#include <pthread.h>
#include <stdio.h>

#include <malloc.h>

#include "test_util.h"

OPTNONE static void leak_memory(void) {
    (void)malloc(1024 * 1024 * 1024);
    (void)malloc(16);
    (void)malloc(32);
    (void)malloc(4096);
}

static void *do_work(void *p) {
    leak_memory();
    return NULL;
}

int main(void) {
    pthread_t thread[4];
    for (int i = 0; i < 4; i++) {
        pthread_create(&thread[i], NULL, do_work, NULL);
    }
    for (int i = 0; i < 4; i++) {
        pthread_join(thread[i], NULL);
    }

    malloc_info(0, stdout);
}
