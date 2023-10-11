#include "function.h"

int main()
{
	int c,n;
	process p[Nbr],temp[Nbr];

	makeEmpty(p);

	do{
	printf("\n\nEnter \t\n  1\tto show available processes\n  2\tadd a process\n  3\tdelete the process\n  4\tto show the execution schedual \n  5\tto find the process working at given time\n  6\tto clear the system\n 7\ttofind the waiting time of processes\n 0\tquit\n\n:");
	n=nbrOfProcesses(p);
		scanf("%d",&c);
		
		switch(c)
		{
			case 1:
		
				copyArr(p,temp,n);
				available(temp,n);
				break;

			case 2:
				
				addP(p);			
				break;

			case 3:
				deleteP(p,n);
				break;

			case 4:
				copyArr(p,temp,n);
				execute(temp,n);
				break;

			case 5:
				copyArr(p,temp,n);
				find(temp,n);
				break;		

			case 6:
				makeEmpty(p);
				break;	

			case 7:
				copyArr(p,temp,n);
				wt(temp,n);
				break;

			case 0:
				break;

			default:
				break;

		}
	}while(c!=0);

	return 0;
}