typedef struct{
	float budget;
	int period;
	float next_exec;
	float timer;
}server;			//this is the server structure





void initialise_server(task* ptasks,int no_of_ptasks,server* serv){
	
	int lst=ptasks[0].period;	
	for(int i=0;i<no_of_ptasks;i++)
		if(ptasks[i].period<lst)
			lst=ptasks[i].period;
	
	float ui,us,limit;
	ui=0;
	for(int i=0;i<no_of_ptasks;i++)
		ui=ui+(ptasks[i].exec/ptasks[i].period);
	limit=(no_of_ptasks+1)*(pow(2,1/(no_of_ptasks+1))-1)-ui;
	serv->period=lst-1;
	float b=0;
	while(1){
		b=b+0.1;
		if((b/serv->period)>=limit)
			break;
	}
	serv->budget=b-0.1;
	printf("Server budget:: %f\n Server Period:: %d\n",serv->budget,serv->period);
	serv->next_exec=0;
	serv->timer=serv->budget;
}
