#include <stdio.h> 
#include <pthread.h> //creating and managing threads.  
int counter = 0; //shared variable.  
pthread_mutex_t lock; //Creates a mutex lock. 

void *increment(void *arg) //void *function_name(void *arg)  
{    
  int i;      
  for(i = 0; i < 5; i++)     
  {         
  pthread_mutex_lock(&lock);          
  counter++;         
  printf("Thread %ld: Counter = %d\n",(long)arg, counter);          
  pthread_mutex_unlock(&lock);     
  }   

  return NULL; //thread function has finished. 
} 

int main() 
{
  pthread_t thread1, thread2; 
  pthread_mutex_init(&lock, NULL); //initializes the mutex 
  pthread_create(&thread1, NULL, increment, (void *)1); 
  pthread_create(&thread2, NULL, increment, (void *)2); 
  pthread_join(thread1, NULL); //wait until Thread 1 finishes. 
  pthread_join(thread2, NULL); // waits for Thread 2 to finish. 
  pthread_mutex_destroy (&lock); 
  printf ("Final Counter = %d\n", counter); 
    
  return 0; 
} 