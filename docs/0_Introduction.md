Process :
When a computer runs an application, that instance of the program execution is referred to as a process. A process consists of program's code, its data, and information about its state. Each process is independent and has its own separate address space and memory. A computer can have hundreds of active processes at once, and an operating system's job is to manage all of them. - Now within every process, there are one or more smaller sub-elements called threads.
    1. Includes code, data, and state information
    2. Independent instance of a running process
    3. Separate address space

Threads :
Threads are the basic units that the operating system manages and it allocates time on the processor to actually execute them.


So which is better, using multiple threads or multiple processes? - Well, like most things in programming, it depends. It depends on what you're doing and the environment it's running in, because the implementation of threads and processes differs between operating systems and programming languages. If your application is going to be distributed across multiple computers, you'll most likely need separate processes for that. But as a rule of thumb, if you can structure your program to take advantage of multiple threads, stick with using threads, rather than multiple processes. Threads are considered lightweight compared to processes, which are more resource intensive. A thread requires less overhead to create and terminate than a process, and it's usually faster for an operating system to switch between executing threads from the same process, than to switch between different processes.