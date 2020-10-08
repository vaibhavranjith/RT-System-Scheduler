#include<stdio.h>
#include<stdlib.h>
#include "sched.h"  

job* newJob(float d, int p) 
{ 
    job* temp = (job*)malloc(sizeof(job)); 
    temp->timer= d; 
    temp->period = p; 
    temp->next = NULL; 
    return temp; 
} 
  

int peekp(job** head) 
{ 
    return (*head)->period; 
} 
  
float peekx(job** head) 
{ 
    return (*head)->timer; 
} 

void pop(job** head) 
{ 
    job* temp = *head; 
    (*head)= (*head)->next; 
    free(temp); 
} 
int peeki(job** head){
	return (*head)->id;
}
  

void push(job** head, float d, int p) 
{ 
    job* start = (*head); 
  
    job* temp = newJob(d, p); 
 
    if ((*head)->period > p) { 
        temp->next = *head; 
        (*head) = temp; 
    } 
    else { 
  
     
        while (start->next != NULL && 
            (start->next)->period <p) { 
            start = start->next; 
        } 
  
        temp->next = start->next; 
        start->next = temp; 
    } 
} 
  

int isEmpty(job** head) 
{ 
    return (*head) == NULL; 
}

///////













/*********************************************************************************************************************************************/
// function to create a queue of given capacity.  
// It initializes size of queue as 0 
AQueue* createQueue(unsigned capacity) { 
    AQueue* queue = (AQueue*) malloc(sizeof(AQueue)); 
    queue->capacity = capacity; 
    queue->front = queue->size = 0;  
    queue->rear = capacity - 1;  // This is important, see the enqueue 
    queue->array = (ajob*) malloc(queue->capacity * sizeof(ajob)); 
    return queue; 
} 
  
// Queue is full when size becomes equal to the capacity  
int qisFull(AQueue* queue) 
{  return (queue->size == queue->capacity);  } 
  
// Queue is empty when size is 0 
int qisEmpty(AQueue* queue) 
{  return (queue->size == 0); } 
  
// Function to add an item to the queue.   
// It changes rear and size 
void enqueue(AQueue* queue, ajob item) 
{ 
    if (qisFull(queue)) 
        return; 
    queue->rear = (queue->rear + 1)%queue->capacity; 
    queue->array[queue->rear] = item; 
    queue->size = queue->size + 1; 
    //printf("Task  enqueued to queue\n"); 
} 
  
// Function to remove an item from queue.  
// It changes front and size 
ajob dequeue(AQueue* queue) { 
    if (qisEmpty(queue)){ 
         ajob temp={-1,0}; 
         return temp; 
    }
    ajob item = queue->array[queue->front]; 
    queue->front = (queue->front + 1)%queue->capacity; 
    queue->size = queue->size - 1; 
    return item; 
} 
  
// Function to get front of queue 
ajob front(AQueue* queue) { 
    if (qisEmpty(queue)) {
    	  ajob temp={-1,0}; 
         return temp; 
       }
     
   return queue->array[queue->front]; 
} 
  
// Function to get rear of queue 
ajob rear(AQueue* queue) { 
    if (qisEmpty(queue)) {
         ajob temp={-1,0}; 
         return temp; 
    }
    return queue->array[queue->rear]; 
} 

void print_queue(AQueue* tq){		//used for debugging only 	WARNING! : empties queue
	ajob read_p;
	int n=tq->size;//because each time you dequeue the value of tq->size changes
	for(int i=0;i<n;i++){
		read_p=dequeue(tq);
		printf("Queue items %f %f\n",read_p.timer,read_p.release_time);
		
	}
}

