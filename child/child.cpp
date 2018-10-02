//
//  main.cpp
//  child
//
//  Created by WillJia on 2018-09-24.
//  Copyright © 2018 WillJia. All rights reserved.
//


#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <string.h>
#include <unistd.h>
#include <string.h>
#include <fstream>
#include <vector>
#include <sstream>
#include <cstdlib>
#include <array>
#include <ctime>


using namespace std;

//pipe
#define READ_END 0
#define WRITE_END 1

//signal
#define REQUEST 100 //REQUEST
#define PIVOT 200   //PIVOT
#define LARGE 300   //LARGE
#define SMALL 400   //SMALL
#define READY 500   //READY
#define SUM 600     //SUM

#define BREAK 2000  //BREAK
#define TERMINATE 4000  //TERMINATE

//reading start flag
#define parent_to_child_write_beginning 0
#define child_to_parent_write_beginning 1

/* initialize pipe. */

/** piping index rules :
 * even number for parent-to-children's write_communication
 * index = id * 2 - 2
 * odd  number for children-to-parent's write_communication
 * index = id * 2 - 1
 */


int ID ; // child ID
int pivot_num;

/************************************************************************
 
 
                        CHILDREN FUNCTIONS
 
 
 *************************************************************************/


/************************************************************************
 
 Function:        num_2_char
 
 Description:     change number to char for passing value in pipe
 
 *************************************************************************/


char const* num_2_char(int n ){
    std::string s = std::to_string(n);
    char const *pchar = s.c_str();
    return pchar;
}

/************************************************************************
 
 Function:        split
 
 Description:     spilt line into elements
 
 *************************************************************************/


std::vector<std::string> &split(const std::string &s, char delim, std::vector<std::string> &elems) {
    std::stringstream ss(s);
    std::string item;
    while(std::getline(ss, item, delim)) {
        elems.push_back(item);
    }
    return elems;
}
// https://stackoverflow.com/questions/275404/splitting-strings-in-c

/************************************************************************
 
 Function:        readContent
 
 Description:     read content from file
 
 *************************************************************************/

string readContent(string filename){
    string content;
    string line;
    ifstream myfile (filename);
    if (myfile.is_open()) {
        while (getline(myfile,line)) {
            content.append(line);
        }
    }
    myfile.close();
    return content;
}

/************************************************************************
 
 Function:        arrayConvert
 
 Description:     convert string to array
 
 *************************************************************************/

vector<int> arrayConvert(string content){
    
    vector<int> array;
    vector<string> numbers ;
    split(content, ' ', numbers);
    int i = 0;
    for(string n : numbers){
        stringstream geek(n);
        geek >> i;
        array.push_back(i);
    }
    return array;
}
//https://www.geeksforgeeks.org/converting-strings-numbers-cc/

/************************************************************************
 
 Function:        processFile
 
 Description:     read file and store in array
 
 *************************************************************************/

vector<int> processFile(string filename){
   return arrayConvert(readContent(filename));
}


/************************************************************************
 
 Function:        getID
 
 Description:     get ID from **argv
 
 *************************************************************************/
void getID(const char * argv[]){
    ID = atoi(argv[0]);
}

/************************************************************************
 
 Function:        readingArray
 
 Description:     whole procedure of reading array
 
 *************************************************************************/
vector<int> readingArray(){
    
    int n = 0;
//    ID = 1;
    /* reading array */
    vector<int> array;
    string info ;
    array = processFile("/Users/WillJia/Documents/Pipe/median/input_" + to_string(ID) +  ".txt");
//    array = processFile("input_" + to_string(ID) +  ".txt");
    
    // check capacity of array
    for (int i = 0; i < array.size() ; i++) {
        if (array[i] != 0) {
            n++;
            info.append(to_string(array[i]));
            info.append("   ");
//            cout << array[i];
        }
    }
    
    if (n == 5) {
//        cout << READY;
        char const *pstar = info.c_str();
        write(STDOUT_FILENO, pstar, sizeof(pstar));
        
//        sleep(1);
        char const *pchar = num_2_char(READY);
        write(STDOUT_FILENO, pchar, sizeof(pchar));
        
//        write(STDOUT_FILENO, &ready, sizeof(ready));

        
    }else{
//        cout << 2000;

        char const *pchar = num_2_char(BREAK);
        write(STDOUT_FILENO, pchar, sizeof(pchar));
        
//        write(STDOUT_FILENO, &error, sizeof(error));
    }
    
    return array;
}

/************************************************************************
 
 Function:        request_func
 
 Description:     return random value in array,return -1 if array is empty.
 
 *************************************************************************/

void request_func(vector<int> &array){

    
    if (array.empty()) {
        int n = -1;
        char const *pchar = num_2_char(n);
        write(STDOUT_FILENO, pchar, sizeof(pchar));
    }else{
        char const *pchar = num_2_char(array[(rand() % array.size())]);
        write(STDOUT_FILENO, pchar, sizeof(pchar));
    }
}

/************************************************************************
 
 Function:        pivot_func
 
 Description:     return Large number than pivot
 
 *************************************************************************/

void pivot_func(vector<int> &array){
    char buf[1024];

    char const *pstar = num_2_char(1000);
    write(STDOUT_FILENO, pstar, sizeof(pstar));

    
    memset(buf, 0, sizeof(buf));    // clear buf container
    read(STDIN_FILENO, &buf, sizeof(buf));
    pivot_num = atoi(buf);

    int index = 0;

    for (int n : array) {
        if (n > pivot_num) {
            index++;
        }
    }
    char const *pchar = num_2_char(index);
    write(STDOUT_FILENO, pchar, sizeof(pchar));
    
  
   
}

/************************************************************************
 
 Function:        small_func
 
 Description:     delete Large number than pivot
 
 *************************************************************************/
void small_func(vector<int> &array){
    
    for (int i = 0; i < (int)array.size(); i++) {
        if (array[i] < pivot_num) {
            array.erase(array.begin()+i);
            i--;
        }
    }
    int size = (int)array.size();
    char const *pchar = num_2_char(size);
    write(STDOUT_FILENO, pchar, sizeof(pchar));

}

/************************************************************************
 
 Function:        large_func
 
 Description:     delete Large number than pivot
 
 *************************************************************************/
void large_func(vector<int> &array){
    
    for (int i = 0; i < (int)array.size(); i++) {
        if (array[i] > pivot_num) {
            array.erase(array.begin()+i);
            i--;
        }
    }
    
    int size;

    if (array.empty()) {
        size = 0;
    }else{
        size = array.size();
    }

    char const *pchar = num_2_char(size);
    write(STDOUT_FILENO, pchar, sizeof(pchar));

}



int main(int argc, const char * argv[]) {
    srand((int)time(NULL));
    char buf[2048];
    //Done : change array to vector<int>
    vector<int> array;
    getID(argv);
    array = readingArray();
        
    //TODO:
    /* It then enters a while loop (broken by a user defined signal -
     * which is sent by the parent to terminate the child process).
     */
    while (true) {
        
    /*
     * • In each iteration it waits on the parent→child pipe to respond according the codes
     *   it gets.
     */
        
        memset(buf, 0, sizeof(buf));    // clear buf container
        // read signal from parent
        read(STDIN_FILENO, &buf, sizeof(buf));
        int signal = atoi(buf);
        

        switch (signal) {
                
    /* • If it receives the command REQUEST from parent:
     *   ■ If its array is empty, write -1 on the child->parent pipe
     *   ■ Else chose a random element from its array and write it to the child→parent pipe
     */
            case REQUEST:
                request_func(array);
                break;
                
    /* • If it receives the command PIVOT from parent:
     *   ■ It waits to read another integer (and store it as pivot).
     *   ■ It then writes the number of integers greater than pivot on the child→parent pipe.
     *     If it has an empty array, the number would be 0.
     */
            case PIVOT:
                pivot_func(array);
                break;
                
    /* • If it receives the command SMALL from parent:
     *   ■ It deletes the elements smaller than the pivot and updates the array.
     */
            case SMALL:
                small_func(array);
                break;
                
    /* • If it receives the command LARGE from parent:
     *   ■ It deletes the elements larger than the pivot and updates the array
     */

            case LARGE:
                large_func(array);
                break;
            case BREAK:
                char const* tchar = num_2_char(TERMINATE);
                write(STDOUT_FILENO, tchar, sizeof(tchar));
                exit(0);
                break;
        }
        
        
    }

}
