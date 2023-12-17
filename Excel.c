#include<stdio.h> 
#include<stdlib.h> 
#include<unistd.h> 
// #include<sys/wait.h> 
 
int main(){ 
 	 
pid_t child_pid = fork(); 
 	 
 	if(child_pid<0) {  	 	
 	    perror("Failed"); 
	 	exit(EXIT_FAILURE); 
	 	 	} 
 	 	 
	 	if(child_pid==0) { 
	 printf("\nCurrently running process has PID: %d\n", getpid()); 
	 execl("bin/date","date",NULL); 
	 	 	} 
 	else{  	 
 	    wait(NULL); 
	 	 execl("/bin/ls","ls","-l",NULL); 
	 	 	} 
	 	return 0; 
 	 
} 
