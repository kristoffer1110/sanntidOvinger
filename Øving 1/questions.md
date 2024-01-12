Exercise 1 - Theory questions
-----------------------------

### Concepts

What is the difference between *concurrency* and *parallelism*?
<<<<<<< HEAD
> Concurrency is when a program runs several threads in the same time period, while parallelism is when the computer actually runs several threads simultaneusly on different computer cores

What is the difference between a *race condition* and a *data race*? 
> A race condition is when the outcome of a program depends on timing intervals, making it unpredictable. A data race is a type of race condition when several threads tries to access the same shared variable at the same time, and at least one of them is a write-operation. The write-operation gets re-written as another thread modifies it.
 
*Very* roughly - what does a *scheduler* do, and how does it do it?
> A scheduler schedules what processes or computations should be done in the future. It does so by arranging or rearranging the stack.
=======
> *Your answer here*

What is the difference between a *race condition* and a *data race*? 
> *Your answer here* 
 
*Very* roughly - what does a *scheduler* do, and how does it do it?
> *Your answer here* 
>>>>>>> 49ad03f3d5c97371c386e59cafd26a50a8a2d396


### Engineering

Why would we use multiple threads? What kinds of problems do threads solve?
<<<<<<< HEAD
> Threads make a program more efficient. without threads, the programming is streamlined, meaning one operation is computed at a time, even though they might not use the same resources. By introducing threads, we can compute several operations at a time, and with locks with locks we can prevent them from using the same resource simultaneously.

Some languages support "fibers" (sometimes called "green threads") or "coroutines"? What are they, and why would we rather use them over threads?
> When backend programming, an assembly code, actively swaps between tasks within a thread, we have created a fiber. Each task do their own work, which means that we have a concurrency within the thread as well.

Does creating concurrent programs make the programmer's life easier? Harder? Maybe both?
> Harder in a sense, because the programmer needs to introduce locks to prevent threads trying to use the same resource.

What do you think is best - *shared variables* or *message passing*?
> Shared variables, creating and dealing with channel networks was pain
=======
> *Your answer here*

Some languages support "fibers" (sometimes called "green threads") or "coroutines"? What are they, and why would we rather use them over threads?
> *Your answer here*

Does creating concurrent programs make the programmer's life easier? Harder? Maybe both?
> *Your answer here*

What do you think is best - *shared variables* or *message passing*?
> *Your answer here*
>>>>>>> 49ad03f3d5c97371c386e59cafd26a50a8a2d396


