#include<stdio.h> 
#include<stdlib.h> 
#include<sys/ipc.h> 
#include<sys/shm.h> 
#include<sys/types.h> 
#include<string.h> 
#include<unistd.h> 

//sender file

int main() 
{     int i; 
    void *shared_memory; 
    char buff[100]; 
    int shmid; 
 
    shmid=shmget((key_t)2345, 1024, 0666|IPC_CREAT);    
    
    printf("Key of shared memory is %d\n",shmid); 
      
    shared_memory=shmat(shmid,NULL,0);     
    printf("Process attached at %p\n",shared_memory);      
    printf("Enter some data to write to shared memory\n");  
    read(0,buff,100);     
    strcpy(shared_memory,buff); 
    printf("You wrote : %s\n",(char *)shared_memory); 
} 
 

//recevied file

int main() 
{     int i; 
    void *shared_memory;    
    char buff[100]; 
    int shmid; 
 
    shmid=shmget((key_t)2345, 1024, 0666); 
    printf("Key of shared memory is %d\n",shmid); 
 
    shared_memory=shmat(shmid,NULL,0);     
    printf("Process attached at %p\n",shared_memory); 
    printf("Data read from shared memory is : %s\n",(char *)shared_memory); 
 
} 