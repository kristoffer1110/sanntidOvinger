// Compile with `gcc foo.c -Wall -std=gnu99 -lpthread`, or use the makefile
// The executable will be named `foo` if you use the makefile, or `a.out` if you use gcc directly

#include <pthread.h>
#include <stdio.h>
#include <semaphore.h>

//pthread_mutex_t mtx;
sem_t sem;

int i = 0;

// Note the return type: void*
void* incrementingThreadFunction(){
    
    // TODO: increment i 1_000_000 times
    for (int n = 0; n < 1000000; n++){
        //pthread_mutex_lock(&mtx);
        sem_wait(&sem);
        i++;
        sem_post(&sem);
        //pthread_mutex_unlock(&mtx);
    }
    return NULL;
}

void* decrementingThreadFunction(){
    // TODO: decrement i 1_000_000 times
    for (int m  = 0; m < 1000000; m++){
    
        //pthread_mutex_lock(&mtx);
        sem_wait(&sem);
        i--;
        sem_post(&sem);
        //pthread_mutex_unlock(&mtx);
    }
    return NULL;
}


int main(){
    // TODO: 
    // start the two functions as their own threads using `pthread_create`
    // Hint: search the web! Maybe try "pthread_create example"?
    
    pthread_t thread1;
    pthread_t thread2;
    //pthread_mutex_init(&mtx, NULL);
    sem_init(&sem, 0, 1);

    pthread_create(&thread1, NULL, incrementingThreadFunction, NULL);
    pthread_create(&thread2, NULL, decrementingThreadFunction, NULL);

    // TODO:
    // wait for the two threads to be done before printing the final result
    // Hint: Use `pthread_join`
    pthread_join(thread1, NULL);
    pthread_join(thread2, NULL);

    //pthread_mutex_destroy(&mtx);
    sem_destroy(&sem);
    
    printf("The magic number is: %d\n", i);
    return 0;
}
