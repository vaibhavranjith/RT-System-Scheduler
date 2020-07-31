#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
#include"sched.h"

int main(int argc,char* argv[]){
	float t=0;
	FILE* fp;
	fp=fopen("periodic.txt","rw");
	int no_of_ptasks;
	fscanf(fp,"%d",&no_of_ptasks);
	task* ptasks=(task*)malloc(sizeof(task)*no_of_ptasks);
	for(int i=0;i<no_of_ptasks;i++){
		fscanf(fp,"%f %d %f %f %d",&ptasks[i].release_time,&ptasks[i].period,&ptasks[i].exec,&ptasks[i].deadline,&ptasks[i].id);
		printf("%f %d %f %f\n",ptasks[i].release_time,ptasks[i].period,ptasks[i].exec,ptasks[i].deadline);
	}
	FILE* fpa=fopen("aperiodic.txt","rw");
	int no_of_atasks;
	fscanf(fpa,"%d",&no_of_atasks);
	task* atasks=(task*)malloc(sizeof(task)*no_of_atasks);
	printf("The aperiodic tasks:: \n");
	for(int i=0;i<no_of_atasks;i++){
		fscanf(fpa,"%f %f",&atasks[i].release_time,&atasks[i].exec);
		
		printf("%f %f\n",atasks[i].release_time,atasks[i].exec);
	}
	
	rms_schedule(ptasks,atasks,no_of_ptasks,no_of_atasks);
	return 0;
}
	
	
