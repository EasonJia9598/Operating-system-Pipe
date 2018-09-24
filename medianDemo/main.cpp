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



char string0[] = "Hello, this is the parent process";
char string1[] = "Hi, this is the child 1";
char string2[] = "Hi, this is the child 2";
char number[] = "1";

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
    
    // initialize pipe.
    // even number for parent-to-children's write_communication
    // odd  number for children-to-parent's write_communication
    for (int i = 0; i < 10; i++) {
        pipe(fds[i]);
    }
    
    pid_t pid;
    int p[5];
    // fork 5 children processes
    for (int i = 0 ; i < 5; i++) {
        pid = fork();
        p[i] = pid;
        if(pid == 0 || pid == -1){
            break;
            //https://blog.csdn.net/cupidove/article/details/9297335
        }
    }
    
    if (pid < 0){/* error occurred*/
        fprintf(stderr, "Fork Failed");
        return 1;
    }else if (pid == 0) { /* child process*/
        /* get ID */
        
        //close
        close(fds[0][WRITE_END]);
        //read parent message
        read(fds[0][READ_END], buf, sizeof(number));
        printf("child reads ID = : %c\n", buf[0]);
        
        /* reading array */
        int array[5]; string s(1, buf[0]);
        
        processFile("/Users/WillJia/Desktop/IOS Lecture/Projects/Pipe/median/input_" + s +  ".txt", array);
        
        /* array testing
        for (int n : array) {
            printf("array number = %d\n" , n);
        }
        
         */
        
        
    }else{ /* parent process*/
        
        // assign ID
        for(int i = 1; i < 6 ; i++){
            close(fds[0][READ_END]);
            char str[20] = {0};
            sprintf(str, "%d" , i);
            write(fds[0][WRITE_END], str, sizeof(number));
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
