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


char string0[] = "Hello, this is the parent process";
char string1[] = "Hi, this is the child 1";
char string2[] = "Hi, this is the child 2";
int ID ;
int msgSingal;

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
 
 
 CHILDREN FUNCTIONS
 
 
 *************************************************************************/



int main(int argc, const char * argv[]) {
    
    /* reading array */
    //    int array[5];
    int SIZE = 1024;
    long n;
    char buf[SIZE];
    msgSingal = READY;
    write(STDOUT_FILENO, &msgSingal, sizeof(msgSingal));
    exit(0);

}
