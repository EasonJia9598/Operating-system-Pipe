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

/************************************************************************
 
 
                        CHILDREN FUNCTIONS
 
 
 *************************************************************************/

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
    array = processFile("/Users/WillJia/Documents/Pipe/median/input_" + to_string(ID) +  ".txt");
    
    // check capacity of array
    for (int i = 0; i < array.size() ; i++) {
        if (array[i] != 0) {
            n++;
//            cout << array[i];
        }
    }
    
    if (n == 5) {
//        cout << READY;
        
        int ready = READY;
        
        std::string s = std::to_string(READY);
        char const *pchar = s.c_str();
        write(STDOUT_FILENO, pchar, sizeof(pchar));
        
//        write(STDOUT_FILENO, &ready, sizeof(ready));

        
    }else{
//        cout << 2000;

        int error = 2000;
        
        std::string s = std::to_string(error);
        char const *pchar = s.c_str();
        write(STDOUT_FILENO, pchar, sizeof(pchar));
        
//        write(STDOUT_FILENO, &error, sizeof(error));
    }
    
    return array;
}




int main(int argc, const char * argv[]) {
    
    char buf[1024];
    //Done : change array to vector<int>
    vector<int> array;
    getID(argv);
    array = readingArray();
   
    //TODO:
    /* It then enters a while loop (broken by a user defined signal -
     * which is sent by the parent to terminate the child process).
     */
    while (true) {
        read(STDIN_FILENO, &buf, sizeof(buf));
        write(STDOUT_FILENO, buf, sizeof(buf));
        exit(0);
    }

    /*
     * • In each iteration it waits on the parent→child pipe to respond according the codes
     *   it gets.
     */
    
    
    /* • If it receives the command REQUEST from parent:
     *   ■ If its array is empty, write -1 on the child->parent pipe
     *   ■ Else chose a random element from its array and write it to the child→parent pipe
     */
    
    /* • If it receives the command PIVOT from parent:
     *   ■ It waits to read another integer (and store it as pivot).
     *   ■ It then writes the number of integers greater than pivot on the child→parent pipe.
     *     If it has an empty array, the number would be 0.
     */
    
    
    /* • If it receives the command SMALL from parent:
     *   ■ It deletes the elements smaller than the pivot and updates the array.
     */
    
    
    /* • If it receives the command LARGE from parent:
     *   ■ It deletes the elements larger than the pivot and updates the array
     */

        
    exit(0);

}
