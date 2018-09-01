#include <pthread.h>

void thread(void *arg) {
    for(int i =0 ;i<10000;i++) {
        printf("thread id: %d i=%d\n",pthread_self(),i);
    }
}

main() {
    int tid1,tid2;

    pthread_create(&tid1,NULL,thread,NULL);
    pthread_create(&tid2,NULL,thread,NULL);
    while(1);
}
