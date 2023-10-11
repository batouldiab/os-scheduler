#include "Queue.h"
//Function:to clear system;
void makeEmpty(process r[])
{
int i;
for(i=0;i<Nbr;i++)
{
r[i].at=-1;
while(!isEmptyQueue(r[i].q))
DeQueue(&(r[i].q));
}
}
//Function:copy the queue to maintain the value
void copyQueue(queue q,queue* r)
{
element e;
while(!isEmptyQueue(q))
{
Front(q,&e);
EnQueue(r,e);
DeQueue(&q);
}
}
//Function:To check if any process exits or not;
bool empty(process p[],int N)
{
  int i;
for(i=0;i<N;i++)
  if(p[i].at>-1)
return 0;
return 1;
}
//Function:To find the maximum number of processes available;
int nbrOfProcesses(process p[])
{
int c=0,i;
for(i=0;i<Nbr;i++)
 if(p[i].at>-1)
	c=i+1;
return c;
}
//Function:Copy Available processes to another Temperory array;
void copyArr(process p[],process temp[],int n)
{
int i;
makeEmpty(temp);
for(i=0;i<n;i++)
{
temp[i].at=p[i].at;
copyQueue(p[i].q,&(temp[i].q));
}
}
//Function:Available process
void available(process p[],int n)
{
	int i;
	element e;
	if(empty(p,n))
		printf("no available processes");
	
	for(i=0;i<n;i++)
	{if(p[i].at>-1)
	{
		printf("\np[%d]:\tarrival time=%d",i,p[i].at);
		while(!isEmptyQueue(p[i].q))
		{
			Front(p[i].q,&e);
			printf("\tCPU=%d",e);
			DeQueue(&(p[i].q));
			Front(p[i].q,&e);
			if(e>0)
			{
				printf("\tI/O=%d",e);
			}
			DeQueue(&p[i].q);
		}
	}
	}
}

void addP(process p[])
{
	int i,ar;
	for(i=0;i<Nbr;i++)
	{
		if(p[i].at<0)
		{
			printf("enter the arrival time (negative value to stop):");
			scanf("%d",&ar);
			if(ar<0)
				break;
			p[i].at=ar;
			do{
				printf("\tCPU=");
				scanf("%d",&ar);
					}while(ar<=0);
				EnQueue(&p[i].q,ar);
				printf("\tI/O=");
				scanf("%d",&ar);
				EnQueue(&p[i].q,ar);
				}while(ar>0);
		}
	}


void deleteP(process p[],int n)
{
	int k,i;
	printf("\nenter the index of process you want to delete:");
	scanf("%d",&i);
	for(k=0;k<n;k++)
		if(k==i)
		{
			p[i].at=-1;
			while(!isEmptyQueue(p[i].q))
				DeQueue(&p[i].q);
		}
}


void execute(process p[],int N)
{
	int n=0,min,r,k,t=0;
	element e,e1;

	if(empty(p,N))
	{
		printf("no processes available");
		return;
	}

	for(t=0;p[n].at!=t;t++)
		for(n=0;n<N,p[n].at!=t;n++);

	printf("--t=%d--",t);
	while(!empty(p,N))
	{
		min=-1;
		for(r=0;r<N;r++)
			if(p[r].at<=t && p[r].at>-1)
			{
				min=r;
				break;
			}

		if(min>-1)
		{
			for(k=r;k<N;k++)
			{
				if(p[k].at<p[min].at && p[k].at>-1)
					min=k;
			}
			Front(p[min].q,&e);
			DeQueue(&p[min].q);
			Front(p[min].q,&e1);
			DeQueue(&p[min].q);
			if(e1>0)
				p[min].at=t+e+e1;
			else
				p[min].at=-1;
			printf("--p[%d]--",min);
			t=t+e;
			printf("--t=%d--",t);
		}

		else
		{
			printf("--IDLE--");
			/*for(k=0,t=t+1;p[k].at!=t;t++)
			{
				for(k=0;k<N&&p[k].at!=t;k++);
					printf("|*t=%d*|",t);
			}*/

			for(t=t+1; ;t++)
			{
				for(k=0;k<N;k++)
				{
					if(p[k].at==t)
						break;
				}
				if(p[k].at==t)
						break;
			}
			printf("--t=%d--",t);

		}
	}
}


void find(process p[],int N)
{
	int n=0,min,r,k,t,time,tempt;
	element e,e1;

	if(empty(p,N))
	{
		printf("no processes available");
		return;
	}
	printf("enter the time you want to find the process working at: ");
	scanf("%d",&time);

	for(t=0;p[n].at!=t;t++)
		for(n=0;n<k,p[n].at!=t;n++);

	printf("|*t=%d*|",t);
	while(!empty(p,N))
	{
		min=-1;
		for(r=0;r<N;r++)
			if(p[r].at<=t && p[r].at>-1)
			{
				min=r;
				break;
			}

		if(min>-1)
		{
			for(k=r;k<N;k++)
			{
				if(p[k].at<p[min].at && p[k].at>-1)
					min=k;
			}
			Front(p[min].q,&e);
			DeQueue(&p[min].q);
			Front(p[min].q,&e1);
			DeQueue(&p[min].q);
			if(e1>0)
				p[min].at=t+e+e1;
			else
				p[min].at=-1;
			tempt=t+e;
			if(time>=t && time<=tempt)
			{
				printf("p[%d]",min);
				return;
			}
			t=t+e;
		}

		else
		{
			tempt=t;
			for(k=0,t=t+1;p[k].at!=t;t++)
				for(k=0;k<N,p[k].at!=t;k++);
			if(time>=tempt && time<t)
			{
				printf("IDLE");
				return;
			}
		}
	}
}

void wt(process p[],int N)
{
	int n=0,min,r,k,t=0;
	element e,e1;

	if(empty(p,N))
	{
		printf("no processes available");
		return;
	}

	for(t=0;p[n].at!=t;t++)
		for(n=0;n<N && p[n].at!=t;n++);
	int w[Nbr],i;
	for(i=0;i<N;i++)
		w[i]=-1;
	
	while(!empty(p,N))
	{
		min=-1;
		for(r=0;r<N;r++)
			if(p[r].at<=t && p[r].at>-1)
			{
				min=r;
				break;
			}

		if(min>-1)
		{
			for(k=r;k<N;k++)
			{
				if(p[k].at<p[min].at && p[k].at>-1)
					min=k;
			}
			if(w[min]==-1)
				w[min]=0;
			w[min]=w[min]+(t-p[min].at);
			Front(p[min].q,&e);
			DeQueue(&p[min].q);
			Front(p[min].q,&e1);
			DeQueue(&p[min].q);
			if(e1>0)
				p[min].at=t+e+e1;
			else
				p[min].at=-1;
			
			t=t+e;
			
		}

		else
		{
			
			/*for(k=0,t=t+1;p[k].at!=t;t++)
			{
				for(k=0;k<N&&p[k].at!=t;k++);
				
			}*/

			for(t=t+1; ;t++)
			{
				for(k=0;k<N;k++)
				{
					if(p[k].at==t)
						break;
				}
				if(p[k].at==t)
						break;
			}
			

		}
	}



	for(i=0;i<N;i++)
	{
		if(w[min]!=-1)
			printf("\nwaiting time for process p[%d] is: %d",i,w[i]);
	}
}
