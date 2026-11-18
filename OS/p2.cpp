#include <stdio.h>  
#include <unistd.h>  
#include <sys/wait.h>  
int main()  
{   
    pid_t pid;             
    pid = fork();    // Calls the fork() system call and Create a child process    
    if (pid < 0)      
    {          
        printf("Process creation failed!\n");      
    }      
    else if (pid == 0)      
    {          // Child process          
        printf("Child Process\n");          
        printf("Child PID = %d\n", getpid());     
    }    
    else      
    {          // Parent process waits for child         
        wait(NULL);        
        printf("Parent Process\n");        
        printf("Parent PID = %d\n", getpid());     
    }        
         
    return 0;  
}  