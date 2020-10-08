#include "sched.h"
#include<stdio.h>
#include<stdlib.h>
#include<strings.h>
#include<math.h>

void initialise_server(task* ptasks,int no_of_ptasks,server* serv){
	int lst;
	for(int i=0;i<no_of_ptasks;i++)
		if(ptasks[i].period<lst)
			lst=ptasks[i].period;
	
	float ui,us,limit;
	ui=0;
	for(int i=0;i<no_of_ptasks;i++)
		ui=ui+(ptasks[i].exec/ptasks[i].period);
	printf("ui= %f\n",ui);
	limit=(no_of_ptasks+1)*(pow(2,1/((float)no_of_ptasks+1))-1)-ui;
	printf("%f\n",limit);
	serv->period=lst-1;
	float b=0;
	while(1){
		b=b+0.1;
		if((b/serv->period)>=limit)
			break;
	}
	serv->budget=b-0.1;
	printf("Server budget:: %f Server Period:: %d\n",serv->budget,serv->period);
	serv->next_exec=0;
	serv->timer=serv->budget;
}

int lcm(int a, int b)
{
    int m = 1;
 
    while(m%a || m%b) m++;
 
    return m;
}



void rms_schedule(task* ptasks,task* atasks,int no_of_ptasks,int no_of_atasks){
	float t=0;		//time set to zero
	job* job_q;
	server* serv=(server*)malloc(sizeof(server)*1);
	initialise_server(ptasks,no_of_ptasks,serv);
	int hyperperiod=ptasks[0].period;
	for(int i=0;i<no_of_ptasks;i++)
		hyperperiod=lcm(hyperperiod,ptasks[i].period);
	hyperperiod=lcm(hyperperiod,serv->period);
	printf("Hyperperiod :: %d\n",hyperperiod);
	for(int i=0;i<no_of_ptasks;i++)
		ptasks[i].next_exec=ptasks[i].release_time;
	int flag=0;
	job now_executing;
	AQueue* aq=createQueue(5);
	/*for(int i=0;i<no_of_atasks;i++){
		ajob temp;
		temp.timer=atasks[i].exec;
		temp.release_time=atasks[i].release_time;
		enqueue(aq,temp);		//aperiodic task queue has been created
	}*/
	//print_queue(aq);
	for(int i=0;i<no_of_ptasks;i++){
		float dif=ptasks[i].next_exec-t;
		if(dif<TIME_GRAN && flag==0){
			job_q=newJob(ptasks[i].exec,ptasks[i].period);
			ptasks[i].next_exec+=ptasks[i].period;
			now_executing.period=peekp(&job_q);
			now_executing.timer=peekx(&job_q);
			flag=1;
		}
		else if(dif<TIME_GRAN && flag==1){
			push(&job_q,ptasks[i].exec,ptasks[i].period);
			ptasks[i].next_exec+=ptasks[i].period;
			if(peekp(&job_q)<now_executing.period){
			  	now_executing.period=peekp(&job_q);
			
			 	now_executing.timer=peekx(&job_q);

			 }
		}
	}
	now_executing.next=NULL;
	pop(&job_q);
	int hijack=0,intra=0,ap_f=0,server_f=0;//these falgs are required to shift the processor from old rma to the one with servers
	int idle=0,intr=0;
	int print_f=0;
	printf("Job of Task %d ---->{ %f ",now_executing.period,t);
	while(t<=hyperperiod){	
		for(int i=0;i<no_of_ptasks;i++){
			float dif=ptasks[i].next_exec-t;
			if(dif<0.1){
				if(!isEmpty(&job_q))
					push(&job_q,ptasks[i].exec,ptasks[i].period);
				else
					job_q=newJob(ptasks[i].exec,ptasks[i].period);
			  	ptasks[i].next_exec+=ptasks[i].period;
			  	intr=1;
			 }
		}
		for(int i=0;i<no_of_atasks;i++){
			if(atasks[i].release_time-t<0.1){
				ajob temp;
				temp.timer=atasks[i].exec;
				temp.release_time=atasks[i].release_time;
				enqueue(aq,temp);		//aperiodic task queue has been created
				intra=1;
			}
					
		}			
					
		if( serv->next_exec-t<0.1){
			serv->next_exec+=serv->period;
			serv->timer=serv->budget;
			if(!qisEmpty(aq))
				server_f=1;
		}
		else if(intra==1 && serv->timer>0)
			server_f=1;
			
		if(server_f==1){
			printf("%f}\n",t);		
			hijack=1;
			printf("Aperiodic job {%f %f}\n",t,t+serv->budget);
			ap_f=1;
			server_f=0;
		}		
				
		else if(intr==1  && peekp(&job_q)<now_executing.period){ //decision point at the arrival of a job
			if(hijack==0)
				printf(" %f}\n",t);  //hijack flag
			else
				hijack=0;
			if(now_executing.timer>=TIME_GRAN){
				push(&job_q,now_executing.timer,now_executing.period);
				
			}
			now_executing.timer=peekx(&job_q);
			now_executing.period=peekp(&job_q);
			pop(&job_q);
			
			printf("Job of Task %d ---->{%f ",now_executing.period,t);
			idle=0;
			intr=0;			
		}
		else if(!isEmpty(&job_q) && idle==1){	//decision point at which a job leaves at t-0.1
			if(hijack==0)
				printf(" %f}\n",t);  //hijack flag
			else
				hijack=0;
			now_executing.timer=peekx(&job_q);
			now_executing.period=peekp(&job_q);
			pop(&job_q);
			intr=0;
			idle=0;
			printf("Job of Task %d ---->{%f ",now_executing.period,t);
		}
	        if(ap_f==0){
			now_executing.timer-=0.1;
		}
		else if(ap_f==1){
			serv->timer-=0.1;
			aq->array[aq->front].timer-=0.1;
			if(aq->array[aq->front].timer <=0){
				dequeue(aq);
				ap_f=0;
			}
			if(serv->timer<=0){
				ap_f=0;
			}
		}
		
		if(now_executing.timer<TIME_GRAN && ap_f==0){
			idle=1;		
			now_executing.period=100000;
		}
		t=t+TIME_GRAN;
	
	}
	printf("...\n");
		
}	
	

		
		
		
		
