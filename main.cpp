#include <stdio.h> 
#include <pthread.h> 
#include <semaphore.h> 
#include <unistd.h> 
  
sem_t s1; 
  
void* fun1(void* arg) 
{ 
    printf("\nEntered in 1..\n"); 
    sleep(1); 
    printf("\nJust Exiting 1...\n");
} 
void* fun2(void* arg) 
{ 
    sem_wait(&s1);
    printf("\nEntered in 2..\n"); 
    sleep(1); 
    printf("\nJust Exiting 2...\n");
    sem_post(&s1); 
} 
  
  
int main() 
{ 
    sem_init(&s1, 0, 1); 
    pthread_t t1,t2; 
    printf("\nfun1 , fun1\n");
    pthread_create(&t1,NULL,fun1,NULL);
    pthread_create(&t2,NULL,fun1,NULL); 
    pthread_join(t1,NULL); 
    pthread_join(t2,NULL); 
    printf("\nfun1 , fun2\n");
    pthread_create(&t1,NULL,fun1,NULL);
    pthread_create(&t2,NULL,fun2,NULL); 
    pthread_join(t1,NULL); 
    pthread_join(t2,NULL);
    printf("\nfun2 , fun2\n");
    pthread_create(&t1,NULL,fun2,NULL);
    pthread_create(&t2,NULL,fun2,NULL); 
    pthread_join(t1,NULL); 
    pthread_join(t2,NULL);  
    sem_destroy(&s1); 
    Return 0
}
