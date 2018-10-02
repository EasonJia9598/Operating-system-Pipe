# Pipe
Pipe design in Operating system

The newest file will be in the directory : testDemo and child

<img width="1920" alt="screen shot 2018-10-02 at 5 25 34 pm" src="https://user-images.githubusercontent.com/38600346/46376273-f6402780-c66b-11e8-8eeb-a0f44dc4d7de.png">

Every time my program block happened after sending PIVOT value and try to read it.
I have a hypothesis about this situation.
Sending too much buffer to child process std_IN, it maybe has a deadlock. 
Tring to figure out what happened.

One example of error happened.
Child process : 
<img width="1452" alt="image" src="https://user-images.githubusercontent.com/38600346/46380814-2a224980-c67a-11e8-8038-dd93d817e1b1.png">
Parent process:
Sampling process 72841 for 3 seconds with 1 millisecond of run time between samples
Sampling completed, processing symbols...
Analysis of sampling testDemo (pid 72841) every 1 millisecond
Process:         testDemo [72841]
Path:            /Users/WillJia/Library/Developer/Xcode/DerivedData/Pipe-dfzbidcifsljpyaqacfheynbauzg/Build/Products/Debug/testDemo
Load Address:    0x100000000
Identifier:      testDemo
Version:         0
Code Type:       X86-64
Parent Process:  debugserver [72842]

Date/Time:       2018-10-02 19:29:27.390 -0300
Launch Time:     2018-10-02 19:28:28.620 -0300
OS Version:      Mac OS X 10.14 (18A391)
Report Version:  7
Analysis Tool:   /usr/bin/sample

Physical footprint:         5428K
Physical footprint (peak):  5436K
----

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

