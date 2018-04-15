#include <stdio.h>
#include <stdlib.h>

void request(int need[10][10],int alloc[10][10],int avail[10],int p,int r)
{
int completed[10],request[10],safeSequence[10],pno,count=0,process;
printf("enter request for process ");
scanf("%d",&pno);
for(int i=0;i<r;i++)
{
scanf("%d",&request[i]);
}
for(int j = 0; j < r; j++)
{
if(request[j]<=need[pno][j]&&request[j]<=avail[j])
{
count++;
}
else
{
count=0;
printf("the request can't be processed\n");	
}
if(count==r)
{
for(j=0;j<r;j++)
{
avail[j]-=request[j];
alloc[pno][j]+=request[j];
need[pno][j]-=request[j];
}	
}
}
}
int main()
{
int Max[10][10], need[10][10], alloc[10][10], avail[10], completed[10],c,safeSequence[10];
int p, r, i, j, process, count;
count = 0;
printf("Enter the no of processes : ");
scanf("%d", &p);
for(i = 0; i< p; i++)
completed[i] = 0;
printf("\n\nEnter the no of resources : "); 
scanf("%d", &r);
printf("\n\nEnter the Max Matrix for each process : ");
for(i = 0; i < p; i++)
{
printf("\nFor process %d : ", i + 1);
for(j = 0; j < r; j++)
scanf("%d", &Max[i][j]);
}
printf("\n\nEnter the allocation for each process : ");
for(i = 0; i < p; i++)
{
printf("\nFor process %d : ",i + 1);
for(j = 0; j < r; j++)
scanf("%d", &alloc[i][j]); 
}
printf("\n\nEnter the Available Resources : ");
for(i = 0; i < r; i++)
scanf("%d", &avail[i]);   
for(i = 0; i < p; i++)
for(j = 0; j < r; j++)
need[i][j] = Max[i][j] - alloc[i][j];

do
{

do
{
printf("\n Max matrix:\tAllocation matrix:\n");
for(i = 0; i < p; i++)
{
for( j = 0; j < r; j++)
printf("%d ", Max[i][j]);
printf("\t\t");
for( j = 0; j < r; j++)
printf("%d ", alloc[i][j]);
printf("\n");
}
process = -1;
for(i = 0; i < p; i++)
{
if(completed[i] == 0)//if not completed
{
process = i ;
for(j = 0; j < r; j++)
{
if(avail[j] < need[i][j])
{
process = -1;
break;
}
}
}

}
if(process != -1)
{
printf("\nProcess %d runs to completion!", process + 1); 
safeSequence[count] = process + 1;
count++;
for(j = 0; j < r; j++)
{
avail[j] += alloc[process][j];
completed[process] = 1;
}
}
}while(count != p && process != -1);
if(count == p)
{
printf("\nThe system is in a safe state!!\n");
printf("Safe Sequence : < ");
for( i = 0; i < p; i++)
printf("%d ", safeSequence[i]);
printf(">\n");
}
else 
printf("\nThe system is in an unsafe state!!");
request(need,alloc,avail,p,r);
printf("enter y or Y to repeat requsting");
scanf("%d",&c);
}while(c=='y'||c=='Y');
}

