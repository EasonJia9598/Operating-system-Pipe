//
//  main.cpp
//  median
//
//  Created by WillJia on 2018-09-23.
//  Copyright © 2018 WillJia. All rights reserved.
//

/************************************************************************************
 
 File:             median
 
 Description:      Using pipe technique to find median in 5 files by 5 child process.
 
 Author:          Zesheng Jia A00416452
 
 *************************************************************************************/



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






/************************************************************************
 
 
                            PARENT FUNCTIONS
 
 
 *************************************************************************/


int main(int argc, const char * argv[]) {
    
    char buf[1024];
    int fds[10][2];
    pid_t pid;
    
    // initialize pipe.
    // even number for parent-to-children's write_communication
    // odd  number for children-to-parent's write_communication
    for (int i = 0; i < 10; i++) {
        pipe(fds[i]);
    }

    // fork 5 children processes
    for (int i = 0 ; i < 5; i++) {
        pid = fork();
    }

    if (pid < 0){/* error occurred*/
        fprintf(stderr, "Fork Failed");
        return 1;
    }else if (pid == 0) { /* child process*/
        //get ID
        
        int array[5];
        

    }else{ /* parent process*/

        // assign ID
        for (int i = parent_to_child_write_beginning; i < 10; i+=2) {
            close(fds[i][READ_END]);
            write(fds[i][WRITE_END], buf, sizeof(to_string(i / 2)));
        }
        

    }
    
    /*  array test
        int array[5];
        processFile("/Users/WillJia/Desktop/IOS Lecture/Projects/Pipe/median/input_1.txt", array);
        for (int i = 0 ; i < 5; i++) {
            cout << array[i] << endl;
        }
     */
}
