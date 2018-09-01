#include <pthread.h>

int i=0;
void thread(void *arg) {
    for(i =0 ;i<1000;i++) {
      printf("thread id: %d i=%d\n",pthread_self(),i);
    }
}

main() {
    pthread_t tid1,tid2;

    pthread_create(&tid1,NULL,thread,NULL);
    pthread_create(&tid2,NULL,thread,NULL);

    pthread_join(tid1,NULL);
    pthread_join(tid2,NULL);

    //pthread_detach(tid1);
}
