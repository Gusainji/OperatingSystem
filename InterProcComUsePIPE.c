#include <stdio.h> 
#include <stdlib.h> 
#include <unistd.h> 
#include <string.h> 
 
int main() {     
    int pipe_fd[2]; 
    pid_t child_pid; 
 
    child_pid = fork(); 
 
    if (child_pid < 0) {         
        perror("Fork failed"); 
        exit(EXIT_FAILURE); 
    } 
 
    if (child_pid == 0) { 
//child         
close(pipe_fd[1]); // Close the write end of the pipe      
char message[100];        
 read(pipe_fd[0], message, sizeof(message));         
 printf("Child Process received: %s\n", message);     
 close(pipe_fd[0]);     } 
else { //parent 
        close(pipe_fd[0]); // Close the read end of the pipe      
        char message[] = "Hello from Parent!";         
        write(pipe_fd[1], message, strlen(message) + 1);         
        close(pipe_fd[1]); 
    } 
    return 0; 
} 
