//
//  main.cpp
//  Pipe
//
//  Created by WillJia on 2018-09-23.
//  Copyright © 2018 WillJia. All rights reserved.
//


#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <string.h>
#include <unistd.h>

#define READ_END 0
#define WRITE_END 1

char string1[] = "Hello from parent";
char string2[] = "Hi from child";

int main()
{
    char buf[1024];
    int i, fds1[2], fds2[2];
    pipe(fds1);
    pipe(fds2);
    
    if (fork()>0){
        //Parent process starts
        for (i=0; i<3; i++) {
            //write parent message into fds1
            close(fds1[0]);
            write(fds1[1], string1,sizeof(string1));
            //read child message from fds2
            close(fds2[1]);
            read(fds2[0],buf,sizeof(string2));
            printf("parent read %s\n", buf);
        }
        exit(0);
    
    }
    else {
        for (i=0; i<3; i++) {
            //write child message into fds2
            close(fds2[0]);
            write(fds2[1], string2, sizeof(string2));
            //read parent message from fds1
            close(fds1[1]);
            read(fds1[0], buf, sizeof(string1));
            printf("child read %s\n", buf);
        }
    }
}

