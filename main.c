#include <stdio.h>
#include <pthread.h>

void *
do_loop(void *data)
{
    int i;
    int j;

    int me = *((int *)data);

    printf("start new thread[%d]...\n", me);

    for (i = 0; i < 10; i ++) {
        for(j = 0; j < 50000000; j++ ) {

        }
        
        printf ("thread:'%d'-Got '%d'\n", me, i);
    }

    // there is no need here to use pthread_exit()
    // since, when returns of function, the thread
    // exit automaticlly anyway.
    pthread_exit(NULL);
}

int
main(int argc, char *argv[])
{
    int thr_id;
    pthread_t p_thread;
    int a = 1;
    int b = 2;

    thr_id = pthread_create(&p_thread, 
    NULL, 
    do_loop, 
    (void *)&a);

    printf("running in main thread...\n");
    do_loop((void *)&b);

    printf("not reached\n");

    return 0;
}