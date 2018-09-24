//
//  main.cpp
//  pipe2
//
//  Created by WillJia on 2018-09-23.
//  Copyright © 2018 WillJia. All rights reserved.
//

// fork with loop

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

#define READ_END 0
#define WRITE_END 1

char string0[] = "Hello, this is the parent process";
char string1[] = "Hi, this is the child 1";
char string2[] = "Hi, this is the child 2";
char number[] = "1";


using namespace std;
int main(){
    char buf[1024];
    int i, fds0[2], fds1[2], fds2[2],fds3[2];
    pipe(fds0);
    //pipe used by the parent process
    pipe(fds1);
    //pipe used by the child 1 process
    pipe(fds2);
    //pipe used by the child 2 process
    pipe(fds3);
    //pipe used by the parent process
    
    pid_t pid;
    for(int i = 0; i < 3 ; i++){
        pid = fork();
        if (pid == 0 || pid == -1) {
            break;
        }
    }
    //The first child process is created
    if(pid == 0) {
        
        close(fds0[1]);
        //read from the parent
        read(fds0[0], buf, sizeof(number));
        printf("child reads: %s\n", buf);
        
        //exec (read File)
        
        
    }

    else {
        //Parent process starts
        //write parent message into fds0
        for(int i = 0; i < 5 ; i++){
            close(fds0[0]);
            char str[20] = {0};
            sprintf(str, "%d" , i);
            write(fds0[1], str, sizeof(number));
        }
     
 
        
        
    
       
        
        
    }
}
