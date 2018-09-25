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
 
 Author:           Zesheng Jia A00416452
 
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
#define REQUEST 100         //REQUEST
#define PIVOT 200           //PIVOT
#define LARGE 300           //LARGE
#define SMALL 400           //SMALL
#define READY 500           //READY

//reading start flag
#define parent_to_child_write_beginning 0
#define child_to_parent_write_beginning 1



char string0[] = "Hello, this is the parent process";
char string1[] = "Hi, this is the child 1";
char string2[] = "Hi, this is the child 2";
int ID ;
int msgSingal;



/************************************************************************
 
 
                        PARENT FUNCTIONS
 
 
 *************************************************************************/




/************************************************************************
 
 Function:        assignID
 
 Description:     assignID to child process
 
 *************************************************************************/
void assignID(int fds[10][2]){
    // assign ID
    for(int i = 1; i < 6 ; i++){
        close(fds[0][READ_END]);
        ID = i;
        write(fds[0][WRITE_END], &ID, sizeof(ID));
    }
}



/************************************************************************
 
 Function:        waitForReady
 
 Description:     parent wait for all child ready signal
 
 *************************************************************************/
void waitForReady(int fds[10][2]){
    
    int C2P_singal; /* signal container */
    int index[5] = {0}; /* flag for sinal which has been received */
    int flag = 0; /* flag for signal which has not been received */
    char buf[1024];
    /* keep listening until all child process return message. */
    while (true) {
        
        for (int i = child_to_parent_write_beginning ; i < 10; i+=2) {
            
            //                printf("oringal%d = %s\n" ,i ,  buf);
            memset(buf, 0, sizeof(buf));    // clear buf container
            
            close(fds[i][WRITE_END]);       // close C2P write_end
            read(fds[i][READ_END] , &buf , sizeof(buf)); // start read
            
            //                printf("singal%d = %s\n" ,i ,  buf);
            
            C2P_singal = atoi(buf);         // change char[] buf to int
            
            if (C2P_singal == 500) {        // if singal = READY
                index[i/2]++;               // specific child's spot ++
                printf("Child %d sends READY\n" , i/2 + 1);
            }else if(C2P_singal == 2000){   // input has mistake
                cout << "******Input file content has mistake*****" << endl;
                cout << "*************Program failed**************" << endl;
                exit(0);                    // exit
            }
        }
        
        for (int i = 0; i < 5 ; i++) {
            if (index[i] <= 0){
                flag++;
            }
        }
        
        if (flag == 0) {
            printf("Parent READY\n");
            break;
        }else{
            flag = 0;
        }
    }
}


/************************************************************************
 
 
                        CHILDREN FUNCTIONS
 
 
 *************************************************************************/


/************************************************************************
 
 Function:        childGetID
 
 Description:     child get ID
 
 *************************************************************************/

void childGetID(int fds[10][2]){
    
    /* get ID */
    //close
    close(fds[0][WRITE_END]);
    //read parent message
    read(fds[0][READ_END], &ID, sizeof(ID));
    //        printf("Child reads ID = : %d\n", ID);
    
    
}



/************************************************************************
 
 Function:        pipeToSTD_IN_OUT
 
 Description:     change pipe to std:in and std:out
 
 *************************************************************************/
void pipeToSTD_IN_OUT(int fds[10][2]){
    
    /* change pipe into std::in and std::out mode */
    close(fds[ID * 2 - 2][WRITE_END]); // close P2C write end
    close(fds[ID * 2 - 1][READ_END]);  // close C2P read end
    
    dup2(fds[ID * 2 - 2][READ_END], STDIN_FILENO);    //P2C
    dup2(fds[ID * 2 - 1][WRITE_END], STDOUT_FILENO);  //C2P
    // you should be able now to close the two remaining
    // pipe file desciptors as well as you dup'ed them already
    // (confirmed that it is working)
    close(fds[ID * 2 - 2][READ_END]);
    close(fds[ID * 2 - 1][WRITE_END]);
    
    /*https://stackoverflow.com/questions/51996946/c-both-input-and-output-pipe-to-the-external-program*/
}


/************************************************************************
 
 Function:        childExecProgram
 
 Description:     child exec program
 
 *************************************************************************/
void childExecProgram(const char* filename){
    /* change ID to char* */
    std::string s = std::to_string(ID);
    char const *pchar = s.c_str();
    
    /* drop child process, change into a new  running program */
    execlp(filename, pchar , NULL);
    
}


int main(int argc, const char * argv[]) {
    
    int fds[10][2];
    
    /* initialize pipe. */
    
    /** piping index rules :
     * even number for parent-to-children's write_communication
     * index = id * 2 - 2
     * odd  number for children-to-parent's write_communication
     * index = id * 2 - 1
     */
    for (int i = 0; i < 10; i++) {
        pipe(fds[i]);
    }
    
    pid_t pid;
    // fork 5 children processes
    for (int i = 0 ; i < 5; i++) {
        pid = fork();
        if(pid == 0 || pid == -1){
            break;
            //Ref : https://blog.csdn.net/cupidove/article/details/9297335
        }
    }
    
    if (pid < 0){/* error occurred*/
        fprintf(stderr, "Fork Failed");
        return 1;
        
    }else if (pid == 0) { /* child process*/
        
        childGetID(fds);
       
        pipeToSTD_IN_OUT(fds);
        
        string filename = "/Users/WillJia/Desktop/IOS Lecture/Projects/Pipe/child/main";
        childExecProgram(filename.c_str());
        
    }else{ /* parent process*/
        
        assignID(fds);
        
        waitForReady(fds );
        
        
    }
    
}
