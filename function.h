#include "Queue.h"

extern void available(process p[],int n);
extern void addP(process p[]);
extern void execute(process p[],int n);
extern void deleteP(process p[],int n);
extern void find(process p[],int n);
extern void makeEmpty(process p[]);
extern void copyQueue(queue q,queue *r);
extern void copyArr(process p[],process temp[],int n);
extern bool empty(process p,int n);
extern int nbrOfProcesses(process p[]);
extern void wt(process p[],int N);