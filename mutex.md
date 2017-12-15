## What is a mutex?

A basic mechanism supplied by the `thread library` to solve this problem, is called **Mutex**. A mutex is lock that guarantees three things:

1. atomicity - Locking a mutex is an atomic operation, meaning that the operating system (or threads library) assures you that if you locked a mutex, no other thread succeeded in locking this mutex at the same time;
2. singularity - If a thread managed to lock a mutex, it is assured that there is no other thread will be able to lock the thread until the original thread releases the lock.
3. Non-Busy Wait - If a thread attempts to lock a thread that was locked by a second thread, the first thread will be suspended(and will not consume any CPU resources) until the lock is freed by the second thread. At the same time, the first thread will wake up and continue execution, having the mutex locked by it.

```
// init mutex variable
pthread_mutex_t a_mutex = PTHREAD_MUTEX_INITIALIZER;
// pthread_mutex_t a_mutex = PTHREAD_RECURSIVE_MUTEX_INITIALIZER_NP;

// lock
int rc = pthread_mutex_lock(&a_mutex);
if (rc > 0) {
    // error
    pthread_exit(NULL);
}

// mutex is locked successfully

// unlock
int rc = pthread_mutex_unlock(&a_mutex);
if (rc > 0) {
    // error
    pthread_exit(NULL);
}

// mutex is unlocked successfully

// destroy mutex

int rc = pthread_mutex_destroy(&a_mutex);


```