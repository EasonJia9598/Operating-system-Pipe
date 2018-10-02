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
[123.pdf](https://github.com/EasonJia9598/Pipe/files/2439956/123.pdf)
