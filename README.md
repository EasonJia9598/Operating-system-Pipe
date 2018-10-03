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
