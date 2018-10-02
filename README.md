# Pipe
Pipe design in Operating system

The newest file will be in the directory : testDemo and child

<img width="1920" alt="screen shot 2018-10-02 at 5 25 34 pm" src="https://user-images.githubusercontent.com/38600346/46376273-f6402780-c66b-11e8-8eeb-a0f44dc4d7de.png">

Every time my program block happened after sending PIVOT value and try to read it.
I have a hypothesis about this situation.
Sending too much buffer to child process std_IN, it maybe has a deadlock. 
Tring to figure out what happened.
