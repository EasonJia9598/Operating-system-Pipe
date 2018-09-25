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

void arrayConvert(string content, int array[]){
    
    vector<string> numbers ;
    split(content, ' ', numbers);
    int i = 0;
    for(string n : numbers){
        stringstream geek(n);
        geek >> array[i];
        i++;
    }
    
}
//https://www.geeksforgeeks.org/converting-strings-numbers-cc/

/************************************************************************
 
 Function:        processFile
 
 Description:     read file and store in array
 
 *************************************************************************/

void processFile(string filename, int array[]){
    arrayConvert(readContent(filename), array);
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
void readingArray(int array[]){
    
    int n = 0;
    
    /* reading array */

    processFile("/Users/WillJia/Desktop/IOS Lecture/Projects/Pipe/median/input_" + to_string(ID) +  ".txt", array);
    
    // check capacity of array
    for (int i = 0; i < 5 ; i++) {
        if (array[i] != 0) {
            n++;
        }
    }
    
    if (n == 5) {
        cout << READY;
    }else{
        cout << 2000;
    }
}




int main(int argc, const char * argv[]) {
    
    //TODO: change array to vector<int>
    int array[5];
    getID(argv);
    readingArray(array);
   
    exit(0);

}
