## What is A Condition Variable?

A `Condition Variable` is a mechanism that allows thread to wait(without wasting CPU cycles) for some event to occur. Several threads may wait on a condition variable, until some other thread signals this condition variable(thus sending a notification). At this time, one of the threads waiting on this condition variable wakes up, and act on the event. It is possible to wake up all threads waiting on this condition variable by using a broadcast method on this variable.

Note that `condition variable` does not provide locking. Thus, a mutex is used along with the condition variable, to provide necessary locking when accessing this condition variable.

```
// init
pthread_cond_t a_cond_variable = PTHREAD_COND_INITIALIZER;
// pthread_cond_t a_cond_variable = pthread_cond_init();

// signal
int rc = pthread_cond_signal(&a_cond_variable);

// broadcast
int rc = pthread_cond_broadcast(&a_cond_variable);

// wait
// first lock the mutex
int rc = pthread_mutex_lock(&a_mutex);
if (rc > 0) {
    // error
    pthread_exit(NULL);
}

rc = pthread_cond_wait(&a_cond_variable);
if (rc == 0) {
    // thread was awakened by signaling
    // do some stuff
}

pthread_mutex_unlock(&a_mutex);

// destroy
int rc = pthread_cond_destroy(&a_cond_variable);
if (rc == EBUSY) {
    // some thread is still waiting on this condition variable
    // handle this case here

    ...
}

```