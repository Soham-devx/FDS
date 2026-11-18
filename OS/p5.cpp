#include <stdio.h> 
#include <sys/ipc.h> 
#include <sys/shm.h> 

int main() 
{ 
  int shmid; char *str; // Create shared memory 
  shmid = shmget(1234, 100, 0666 | IPC_CREAT); // Attach shared memory 
  str = (char *)shmat(shmid, NULL, 0); 

  // Write data 
  printf("Enter message: "); 
  scanf("%s", str);  //For long message(“% [^\n]”, str); 
  
  // Read data 
  printf("Message from shared memory: %s\n", str); 
  
  // Detach shared memory 
  shmdt(str); 
  return 0; 
} 