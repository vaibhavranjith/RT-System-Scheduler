#include<unistd.h>
#include<stdlib.h>
#include<stdio.h>

#define TIME_GRAN 0.1
#define READY_QUEUE_SIZE 20 	//maximum nummber of tasks possible to resife on main memory
#define RUNNING_TIME 4

typedef struct{
	float next_exec;
	int period;		//if period is -1 then it is an aperiodic process
	float exec;				
	float release_time;	//if it is -1 then this task  instance does not exist(error  checking in queue
	float deadline;		//if deadline is -1 then it is an aperiodic task
	int id;
}task;


  
typedef struct{
	float budget;
	int period;
	float next_exec;
	float timer;
}server;

typedef struct Job{
	int id;
	float timer;
	int period;
	struct Job* next;
}job;
typedef struct{
	float timer;
	float release_time;
}ajob;

typedef struct 
{ 
    	int front, rear, size; 
   	unsigned capacity; 
    	ajob* array; 
}AQueue; 



job* newJob(float d, int p) ;
int peekp(job** head);
float peekx(job** head);
void pop(job** head) ;
void push(job** head, float d, int p) ;
int isEmpty(job** head) ;

//queue functions

AQueue* createQueue(unsigned capacity) ;
int qisFull(AQueue* queue);
int qisEmpty(AQueue* queue);
void enqueue(AQueue* queue, ajob item);
ajob dequeue(AQueue* queue) ;
ajob front(AQueue* queue);
ajob rear(AQueue* queue);
void print_queue(AQueue* queue);

//scheduling functions
int create_queue(FILE* fp,AQueue* tq);	
void rms_schedule(task* ptasks,task* atasks,int no_of_ptasks,int no_of_atasks);  
void initialise_server(task* ptasks,int no_of_ptasks,server* serv);
