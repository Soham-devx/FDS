#include <stdio.h> 
#include <pthread.h> 
#include <semaphore.h> 

sem_t semaphore; 
int shared_data = 0; 

void *process(void *arg) 
{ 
  int id = *(int *)arg; 

  printf("Thread %d is waiting for semaphore...\n", id); 
  sem_wait(&semaphore); 

  printf("Thread %d entered Critical Section.\n", id); 
  shared_data++; printf("Thread %d changed shared data to %d\n", id, shared_data); 

  printf("Thread %d leaving Critical Section.\n", id); 
  sem_post(&semaphore); return NULL; 

}

int main () 
{ 
  pthread_t t1, t2; 
  int id1 = 1, id2 = 2; 

  sem_init(&semaphore, 0, 1); 

  pthread_create(&t1, NULL, process, &id1); 
  pthread_create(&t2, NULL, process, &id2); 

  pthread_join(t1, NULL); 
  pthread_join(t2, NULL); 
  
  printf("\nFinal value of shared data = %d\n", shared_data); 
  sem_destroy(&semaphore); 
  
  return 0; 
} 