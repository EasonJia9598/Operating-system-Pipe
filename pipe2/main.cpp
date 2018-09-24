//
//  main.cpp
//  pipe2
//
//  Created by WillJia on 2018-09-23.
//  Copyright © 2018 WillJia. All rights reserved.
//

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <string.h>
#include <unistd.h>

#define READ_END 0
#define WRITE_END 1

char string0[] = "Hello, this is the parent process";
char string1[] = "Hi, this is the child 1";
char string2[] = "Hi, this is the child 2";
char one[] = "1";
char two[] = "2";
char three[] = "3";

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
    
    //The first child process is created
    if(fork()==0) {
        close(fds0[1]);
        //read from the parent
        read(fds0[0], buf, sizeof(string0));
        printf("child 1 reads: %s\n", buf);
        //write child message to parent via its pipe
        close(fds1[0]);
        write(fds1[1], string1, sizeof(string1));
        exit(0);
    }
    //The second child process
    else if(fork()==0) {
//        sleep(1);
        close(fds0[1]);
        //Get something from the parent process
        read(fds0[0], buf, sizeof(string0));
        printf("child 2 reads: %s\n", buf);
        //write child message into fds2
        close(fds2[0]);
        write(fds2[1], string2, sizeof(string2));
        exit(0);
    }else if (fork() == 0){
        close(fds0[1]);
        //Get something from the parent process
        read(fds0[0], buf, sizeof(string0));
        printf("child 3 reads: %s\n", buf);
        //write child message into fds2
        close(fds3[0]);
        write(fds3[1], string2, sizeof(string2));
        exit(0);
    }
    else {
    //Parent process starts
    //write parent message into fds0
    close(fds0[0]);
    write(fds0[1], one, sizeof(one));
    //read child 1 message from its associated pipe
    close(fds1[1]);
    read(fds1[0],buf,sizeof(string1));
    printf("parent reads from Child 1: %s\n", buf);
        
    //wrong methods
        

    //write something into fds0 again to child 2
    close(fds0[0]);
    write(fds0[1], two, sizeof(two));
        
//    //write something into fds3 to child 2
//    close(fds3[0]);
//    write(fds3[1], string0, sizeof(string0));
    //read child 2 message from its associated pipe
    close(fds2[1]);
    read(fds2[0],buf,sizeof(string2));
    printf("parent reads from Child 2: %s\n", buf);
    
    //Parent process starts
    //write parent message into fds0
    close(fds0[0]);
    write(fds0[1], three, sizeof(one));
    //read child 1 message from its associated pipe
    close(fds1[1]);
    read(fds1[0],buf,sizeof(string1));
    printf("parent reads from Child 3: %s\n", buf);
        
    exit(0);
    }
}
