#include <stdio.h>
#include <pthread.h>
#include <unistd.h>

void *print_thread_info(void *arg) {
    pid_t pid = getpid();
    pthread_t tid = pthread_self();
    printf("Thread ID: %lu \nProcess ID: %d\n", tid, pid);
    return NULL;
}

int main() {
    pthread_t thread_id;
    int status;

    status = pthread_create(&thread_id, NULL, print_thread_info, NULL);
    if (status != 0) {
        fprintf(stderr, "Error creating thread: %d\n", status);
        return 1;
    }

    pthread_join(thread_id, NULL);
    return 0;
}
