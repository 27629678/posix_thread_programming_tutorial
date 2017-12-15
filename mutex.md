## What is a mutex?

A basic mechanism supplied by the `thread library` to solve this problem, is called **Mutex**. A mutex is lock that guarantees three things:

1. atomicity - Locking a mutex is an atomic operation, meaning that the operating system (or threads library) assures you that if you locked a mutex, no other thread succeeded in locking this mutex at the same time;
2. singularity - If a thread managed to lock a mutex, it is assured that there is no other thread will be able to lock the thread until the original thread releases the lock.
3. Non-Busy Wait - If a thread attempts to lock a thread that was locked by a second thread, the first thread will be suspended(and will not consume any CPU resources) until the lock is freed by the second thread. At the same time, the first thread will wake up and continue execution, having the mutex locked by it.