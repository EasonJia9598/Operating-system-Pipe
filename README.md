# Pipe
Pipe design in Operating system

The newest file will be in the directory : testDemo and child

# Report
# This is a fully report of Assignment 1 -- Pipes' communication.

## Quick brief :

>In assignment 1, your task is to implement distributed median finding algorithm using pipes. The parent process spawns K (5) identical child processes along with 2*K (10) pipes - two for each parent-child pair (one sends messages from parent→child, the other sends messages from child→parent). Each child reads an array of 5 integers. The numbers are read from 5 files (one for each child process). The files are named as "input_1.txt", "input_2.txt", ... , "input_5.txt". Various stages of the algorithm (reproduced from the assignment[1]) is given below: 

In my version of finding median between 5 input files, I used 2 programs by exec family funcitons. 
One is the main program for parent process which invokes 5 children processes,control messages sending and decide when will be the correct ouput by k == m.
The other one is the external program for calculating information and sending calculated messages to parent process.
Message sending includes that array content, array size, pivot , count of numbers that small than pivot and count of numbers that larger than pivot.
Operations on variables includes that delete every number small than pivot, delete every larger number than pivot.

```sequence
Title: Pipe's communication
Parent->Children: fork() 5 times simultaneously
Children->>External Program: redirect pipe write to std_in
Children->>External Program: redirect pipe read to std_out
Children->>External Program: execlp() in diff argv[] - ID
Parent-->External Program: P to C write / C read from P
External Program--> Parent: C to P write / P read from C

```

<div STYLE="page-break-after: always;"></div>

***
# Outline
1. Introduction of functions
	1. main program - initial part - main.cpp
		* Parent process
			* main()
			* pipe
			* create child process
			* assign ID
			* reciving READY message from child
		* Child process
			* getID
			* redirect pipe lines to _STDIN_FILENO/STDOUT_FILENO_
			* use execlp to invoke external program
	3. external program - initial part - child.cpp
		* receiveID
		* read data from input file and store in array
	2. main communication part - IPC
		1. Parent process - main.cpp
			* send communicating signal(REQUEST, READY, PIVOT, SMALL,LARGE...)
			* identify the relationship between k and m, find median
		2. child process - child.cpp
			* calculating data
			* manage data
			* return value
			* terminates
2. Key features found during the procedure of prgramming
3. Remaining Questions   

<div STYLE="page-break-after: always;"></div>

***
# Getting start
This report will discuss all things happened during I wrote this program.  We will begin by explaining the structure and details in functions. In the meantime, I will also talk about what kinds of obstacles I met and how I sovled them.

To be honest, when I first read the insturctions about this assignment, I think it is a single project with mathematics and IPC.
After I finished establishing the Inter process communication part in one C file. I still felt confident about how I could make this work.

However, the next decision I made changed everything. 
I chose to use child process execlp() a external process to do the job.
And it helps me create the best project I ever wrote.
Because I can't see anything from external process. So, I guess what happened and use pstacks to idtentify the collapse line.Tried to debug in the dark without a single light. Thousands of failer made me much more long for the sucess. It helps me think what the most important part is in a project.
I went inside of all details in pipe and process. And try to figure out what makes my programm have bugs and block. I will discuss those parts throughly in next few charpters.
At the end, when I finially had the 100% correct outputs , I felt extremely satisfied.
Learn everything I can, before coding.
Think everything I could avoid before coding.
Okay, let's go to the details in my program.

<div STYLE="page-break-after: always;"></div>

***
# Charpter one: Intruduction of functions <br/>
## Part ONE: Main Program (main.cpp)
> In this part, I will throughly decribe how my program works.
I will divide main program as three parts.
Firstly, it is the fundamental structure to build parent process and child process(before exec). And how to establish their inter process communication.
Secondly, I will briefly talk about the initial part of child process(before exec) and parent process. About how to send ID information between IPC.
Eventually, we will talk about the strategy about invoking external program and its details.

***

### Header files and const variables includes:

```c
#include <iostream>
#include <algorithm>    // std::sort
#include <fstream>
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
#include <ctime>

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
#define BREAK 2000          //BREAK
#define TERMINATE 4000      //TERMINATE

//reading start flag
#define beginning_index 1

//sleep time
#define TIME 0



int ID ;
int msgSingal;
int n = 5;
```

## main():
First of all, let's create 10 pipes as each child has 2 pipes to communicate with parent. 

> By http://www.drkapoorsclinic.com/files/blog/Linux_Kernel_Implementation_of_Pipes_FIFOs.pptx

```c
int main(int argc, const char * argv[]) {
    
    // Generate 25 random numbers into 5 input_file
    //    generateInputFiles();
    
    printf("Process communication program begin.\n");
    
    int fds[10][2]; // pipes
    char buf[1024]; // container of messages
    int times = 0; 
    for (int i = 0; i < 10; i++) {
        pipe(fds[i]);   // create pipes with VFS
    }
    
    pid_t pid;
 
```

And then we create 5 children process at the same time. 
At the moment, I used a strategy from a website. 
>Ref : https://blog.csdn.net/cupidove/article/details/9297335

He set a if - break statement in for loop, every time when pid == 0 then break, which makes child process will not continue to fork sub-child process.

```c
   
    // fork 5 children processes
    printf("Starting fork children process.\n");
    
    for (int i = 0 ; i < 5; i++) {
        pid = fork();
        if (pid != 0 && pid != -1) {
            printf("NO. %d Child has been forked by parent\n" , i + 1);
        }
        sleep(1);
        if(pid == 0 || pid == -1){
            break;
            //Ref : https://blog.csdn.net/cupidove/article/details/9297335
        }
    }
    
```

After we forked 5 children process.
Then we go to if else statment, to distinguish parent process and children process.
By pid == 0 (child process) or pid > 0 (parent process)

```c
 if (pid < 0){/* error occurred*/
        fprintf(stderr, "Fork Failed");
        return 1;
    }else if (pid == 0) { /* child process*/
        childGetID(fds);
        pipeToSTD_IN_OUT(fds);
        //        string filename = "/home/student/z_jia/AS1/child";
        string filename = "/Users/WillJia/Documents/Pipe/child/child";
        
        childExecProgram(filename.c_str());
    }else{ /* parent process*/
        /*
         • It allots ids 1-5 to each of the children and sends the same along the parent→child pipe.
         */
        assignID(fds);
        /*
         • The parent waits on all the child→parent pipes until it receives the code READY from all
         child processes. This ensures that the algorithm initiates only after all child processes
         have read the input completely.
         */
        waitForReady(fds );
```

## ***Now, We discuss the whole communication procedure by swtiching locations from parent to child in main.cpp. For simulating the things happen between P and C by timeline.***

First of all, I create a communication rule between P and C.
As for even number for P2C, odd number for C2P.
By this particular rule, I can make every pipe write and read by child ID without advanced calculating.

```c
/** piping index rules :
 * even number for parent-to-children's write_communication
 * index = id * 2 - 2
 * odd  number for children-to-parent's write_communication
 * index = id * 2 - 1
 */
```

So, I wrote four encapsulation methods by myself to make pipe write / read more easily.

```c

/************************************************************************
 
 Function:        P2C_write
 
 Description:     parent write to child
 
 *************************************************************************/
void P2C_write(int fds[10][2] , int index , const void *__buf , size_t __nbyte){
    
    close(fds[index * 2 - 2][READ_END]);
    write(fds[index * 2 - 2][WRITE_END], __buf, __nbyte);
}

/************************************************************************
 
 Function:        P_from_C_read
 
 Description:     parent read from child
 
 *************************************************************************/
void P_from_C_read(int fds[10][2] , int index , void *__buf , size_t __nbyte){
    
    close(fds[index * 2 - 1][WRITE_END]);                    // close C2P write_end
    read(fds[index * 2 - 1][READ_END] ,__buf, __nbyte);      // start read
    
}


/************************************************************************
 
 Function:        C2P_write
 
 Description:     child write to parent
 
 *************************************************************************/
void C2P_write(int fds[10][2] , int index , const void *__buf , size_t __nbyte){
    
    close(fds[index * 2 - 1][READ_END]);
    write(fds[index * 2 - 1][WRITE_END], __buf, __nbyte);
}

/************************************************************************
 
 Function:        C_from_P_read
 
 Description:     child read from parent
 
 *************************************************************************/
void C_from_P_read(int fds[10][2] , int index , void * __buf , size_t __nbyte){
    
    close(fds[index * 2 - 2][WRITE_END]);                    // close C2P write_end
    read(fds[index * 2 - 2][READ_END] , __buf, __nbyte); // start read
    
}
```

After that, I still think it's not enough. Because sometimes we need sending char[] buf messages, and sometimes we need sending int variable. As we know, although system call write/read has no restrictions on the type of variable, which means we can send int to child process and use another int to contain their values, it still could have mistakes. Because the developer needs to remember when the variable is char[] and when the variable is int. Based on the different between two types, there are a lot of more works that need to be done.
So, I decide to change every types of varaible to char[] variable.
It makes my code more flexiable, because even if we forget what type we sent, we can still use printf("%s",buf); to figure out what happened.

```c
/************************************************************************
 
 Function:        p2c_send_signal
 
 Description:     parent send signal to  all child
 
 *************************************************************************/

void p2c_send_signal(int fds[10][2] , int index , int signal ){
    std::string s = std::to_string(signal);
    char const *pchar = s.c_str();
    P2C_write(fds, index, pchar, sizeof(pchar));
}


```

## ***After those fundamental methods finished, we will fully discuss about the procedure about how does P to C communication establish***

### We start from Parent Process
####   assignID(fds);
In my thought, it is a key feature to assign ID to children process at the beginning. Because in each child they has same PCB from parent. So, their data won't be different.
I observed that all children already inherit 10 pipes. And all the code in child process block are the same.
So, it's hard to distinguish ID by code.
And when I serached the details in pipe system calls.
I know that if P write into pipe, and C read from pipe. Then the buffer will be cleared after reading, which means if Parent send different IDs to pipe, as long as children keep reading from pipe, it will not block.
And use one read() in child process, there will invoke K read() to reach from parent.
SO, how about using only one pipe?

```c
/************************************************************************
 
 Function:        assignID
 
 Description:     assignID to child process
 
 *************************************************************************/
void assignID(int fds[10][2]){
    for(int i = 1; i < 6 ; i++){
        ID = i;
        P2C_write(fds, 1, &ID, sizeof(ID));
        // index = 1 for first 2 pipes.
        // and P2C_write will operate in pipe[0]
    }
}
```

It works.
***
### Then we switch to children process code.
#### childGetID(fds);
The first line of children process code.
Because we talk about the strategy of sending IDs before, then child process read pipe[0] directly.
And at this moment, all 5 children processes are already forked.
Then they are waiting for parent sending message. Someone, called it pipe reading block.
So, as long as the parent send IDs one by one, there always will be a child process read the correct message of ID and then it will go to next execute line.
Then next child read.
After all 5 children read sucessfully from parent.
All ID assgin and ID get work done.

```c

/************************************************************************
 
 Function:        childGetID
 
 Description:     child get ID
 
 *************************************************************************/

void childGetID(int fds[10][2]){
    
    C_from_P_read(fds, 1, &ID, sizeof(ID)); // use 0 pipe for original communicating
    
}
```

***
##Next Step is the most important function in all programs.
### <font color=#DC143C>-- Redirect pipe lines to  STDIN_FILENO and  STDOUT_FILENO</font>

As we know, once we use exec family functions invoke external program. It will execture a complied file, terminate the previously child process and become a new process.
And the data saving in previously PCB will be cleared.
Therefore, new external process (we call it ET process only now) will no longer has value of pipes.
I spent a few hours tring to figure out a solution.
And I find a solution on a website:
>Ref: https://stackoverflow.com/questions/51996946/c-both-input-and-output-pipe-to-the-external-program

So, in order to make ET process still have access to pipes.
We redirect children own 2 pipe lines to ET process's STDIN_FILENO port and STDOUT_FILENO port.

```c
/************************************************************************
 
 Function:        pipeToSTD_IN_OUT
 
 Description:     change pipe to std:in and std:out
 
 *************************************************************************/
void pipeToSTD_IN_OUT(int fds[10][2]){
    
    /* initialize pipe. */
    /** piping index rules :
     * even number for parent-to-children's write_communication
     * index = id * 2 - 2
     * odd  number for children-to-parent's write_communication
     * index = id * 2 - 1
     */
    
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
    
    /*Ref: https://stackoverflow.com/questions/51996946/c-both-input-and-output-pipe-to-the-external-program*/
}

```

After this functions, we can use ```read(STDIN_FILENO , buf, sizeof(buf))``` and ```write(STDOUT_FILENO , buf, sizeof(buf))``` to get information from pipes in ET process.

***
## Then we execlp() a new process.

```c
/************************************************************************
 
 Function:        childExecProgram
 
 Description:     child exec program
 
 *************************************************************************/
void childExecProgram(const char* filename){
    /* change ID to char* */
    std::string s = std::to_string(ID);
    char const *pchar = s.c_str();
    
    /* drop child process, change into a new  running program */
    if (execlp(filename, pchar , NULL)<0){
        printf("Wrong!!");
    }
    
}
```

There are a lot of information and knowledge points in exec family. Please read from online or book source. I will omit those for now.
In my function ```childExecProgram(const char* filename)```, 
we will use execlp() function to execute a new program.
pchar will be the argument to argv[] at```int main(int argc, const char * argv[])```.
And because of argv[], we can send ID to the new process.
***

##***And at this point,inter process communication lines between parent process and ET process (external process) is established.***

<div STYLE="page-break-after: always;"></div>

***
## Part TWO: External programm (child process)

### Now, we go to the new child process source file as the ET process we mentioned before. We will call it child process from now on.
### ***child.cpp***
Same header file and global variables are:

```c

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

```

Once we get into the new child process, and recive the ID from argv[].

```c
/************************************************************************
 
 Function:        getID
 
 Description:     get ID from **argv
 
 *************************************************************************/
void getID(const char * argv[]){
    ID = atoi(argv[0]);
}
```

Then the first thing we do is that obtaining data of ```input_(ID).txt``` into an array.
And if the array is correct with 5 values in it, then send ```READY``` to parent.

### main()

```c
int main(int argc, const char * argv[]) {
    srand((int)time(NULL));
    char buf[2048];
    //Done : change array to vector<int>
    vector<int> array;
    getID(argv);
    array = readingArray();
```

### readingArray()
I used ```vector<int>``` to be the array. Because vector has dynamic items. It is easy to add/delete items and get its size .
Reading data from a file is easy. So, this part will be omitted for now.
After we get the right array from the `vector<int>`, we add array values with delim as `/` between each element and put them into a new string. 
However, in this case, 5 numbers with 4 `/` is larger than the limit of a char[] buf can contain. The parent process will only get half of the string.

After a lot of times failer trying, I use 2 strings to contain those information. Send to parent process twice.
After sending array values to parent process.
Then we send `READY` to parent at the end.

> In this part of code, there is a huge bug which happened in my early version of codes. It caused a lot of times random pipe block between successful runnings. The rate is nearly to 1 failed / 20 success.
And I will talk about this situation in whole Charpter 2.
I spent almost 90% time to fix this problem in the dark.
But right now, we focus on functions stucture.

```c
/************************************************************************
 
 Function:        readingArray
 
 Description:     whole procedure of reading array
 
 *************************************************************************/
vector<int> readingArray(){
    char buf[1024];
    int n = 0;
//    ID = 1;
    /* reading array */
    vector<int> array;
    string info ;
    string info2 ="/";
    
    array = processFile("/Users/WillJia/Documents/Pipe/median/input_" + to_string(ID) +  ".txt");
    
//    array = processFile("input_" + to_string(ID) +  ".txt");
    
    // check capacity of array
    // TODO: why one buf can't send all info
    
    for (int i = 0; i < array.size() ; i++) {
        if (array[i] != 0) {
            n++;
            if (i < 3) {
                info.append(to_string(array[i]));
                info.append("/");
            }else{
                info2.append(to_string(array[i]));
                info2.append("/");
            }
           
        }
    }
    
    if (n == 5) {
//        cout << READY;
        char const *pstar = info.c_str();
        write(STDOUT_FILENO, pstar, sizeof(pstar));
        
        memset(buf, 0, sizeof(buf));    // clear buffer container
        read(STDIN_FILENO, &buf, sizeof(buf));
        
        char const *pstar2 = info2.c_str();
        write(STDOUT_FILENO, pstar2, sizeof(pstar2));
        
        memset(buf, 0, sizeof(buf));    // clear buffer container
        read(STDIN_FILENO, &buf, sizeof(buf));
        
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
```

# To be continued.
# Still writing this report.
# Hopefully I can finish it before Tuesday.

<img width="1920" alt="screen shot 2018-10-02 at 5 25 34 pm" src="https://user-images.githubusercontent.com/38600346/46376273-f6402780-c66b-11e8-8eeb-a0f44dc4d7de.png">

Every time my program block happened after sending PIVOT value and try to read it.
I have a hypothesis about this situation.
Sending too much buffer to child process std_IN, it maybe has a deadlock. 
Tring to figure out what happened.

One example of error happened.
Child process : 
<img width="1452" alt="image" src="https://user-images.githubusercontent.com/38600346/46380814-2a224980-c67a-11e8-8038-dd93d817e1b1.png">

Call graph:
2757 Thread_1166804   DispatchQueue_1: com.apple.main-thread  (serial)  
+ 2757 start  (in libdyld.dylib) + 1  [0x7fff6842a085]  
+   2757 main  (in testDemo) + 910  [0x1000017be]  main.cpp:353  
+     2757 waitForReady(int (*) [2])  (in testDemo) + 162  [0x100000d22]  main.cpp:182  
+       2757 P_from_C_read(int (*) [2], int, void*, unsigned long)  (in testDemo) + 83  [0x100000b53]  main.cpp:115  
+         2757 read  (in libsystem_kernel.dylib) + 10  [0x7fff685648a6]  
2757 Thread_1167037  
2757 start_wqthread  (in libsystem_pthread.dylib) + 13  [0x1003d4e51]  
2757 _pthread_wqthread  (in libsystem_pthread.dylib) + 670  [0x1003d515d]  
2757 __workq_kernreturn  (in libsystem_kernel.dylib) + 10  [0x7fff685645be]  
  
Total number in stack (recursive counted multiple, when >=5):  
  
Sort by top of stack, same collapsed (when >= 5):  
__workq_kernreturn  (in libsystem_kernel.dylib)        2757  
read  (in libsystem_kernel.dylib)        2757  
Full system report : [123.pdf](https://github.com/EasonJia9598/Pipe/files/2439956/123.pdf)
<img width="1920" alt="screen shot 2018-10-02 at 7 44 13 pm" src="https://user-images.githubusercontent.com/38600346/46381241-d6b0fb00-c67b-11e8-89fe-d20e584ef8d0.png">
<img width="1920" alt="screen shot 2018-10-02 at 7 44 18 pm" src="https://user-images.githubusercontent.com/38600346/46381250-dc0e4580-c67b-11e8-81cc-d6726cca3910.png">
<img width="1920" alt="screen shot 2018-10-02 at 7 44 26 pm" src="https://user-images.githubusercontent.com/38600346/46381258-e29cbd00-c67b-11e8-9f0e-406a5651b4d4.png">
<img width="1920" alt="screen shot 2018-10-02 at 7 44 31 pm" src="https://user-images.githubusercontent.com/38600346/46381261-e6304400-c67b-11e8-9a12-890667b37075.png">

<img width="1920" alt="screen shot 2018-10-02 at 7 44 36 pm" src="https://user-images.githubusercontent.com/38600346/46381265-e92b3480-c67b-11e8-8405-eb529a0c34b3.png">

<img width="1920" alt="screen shot 2018-10-02 at 7 44 45 pm" src="https://user-images.githubusercontent.com/38600346/46381269-ecbebb80-c67b-11e8-8d1c-1830d4af8fec.png">

<img width="1920" alt="screen shot 2018-10-02 at 7 45 03 pm" src="https://user-images.githubusercontent.com/38600346/46381271-ee887f00-c67b-11e8-8ef3-244e9cbd82c7.png">

<img width="1920" alt="screen shot 2018-10-02 at 7 45 12 pm" src="https://user-images.githubusercontent.com/38600346/46381273-f0ead900-c67b-11e8-9df7-13d2558b0fc5.png">

<img width="1920" alt="screen shot 2018-10-02 at 7 45 15 pm" src="https://user-images.githubusercontent.com/38600346/46381276-f2b49c80-c67b-11e8-8534-b56b23dfa4b8.png">





# potential bug reason
read pipe close by write function but do not reopen
