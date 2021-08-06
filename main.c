q#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <string.h>

#define REPEAT_COUNT 10

void *child_thread_body(void *args) {
    for (int i = 0; i < REPEAT_COUNT; i++) {
        printf("Message №%d from CHILD Thread\n", i);
    }
    return NULL;
}

int main() {
    pthread_t thread;

    int creation_code = pthread_create(&thread, NULL, child_thread_body, NULL);
    if (creation_code != 0) {
        fprintf(stderr, "Cannot create thread: %s\n", strerror(creation_code));
        return EXIT_FAILURE;
    }

/*    int join_code = pthread_join(thread, NULL);
    if (join_code != 0) {
        fprintf(stderr, "Cannot join child thread: %s\n", strerror(join_code));
        return EXIT_FAILURE;
    }*/

    for (int i = 0; i < REPEAT_COUNT; i++) {
        printf("Message №%d from PARENT Thread\n", i);
    }

    pthread_exit(EXIT_SUCCESS);
//  return EXIT_SUCCESS;
}
