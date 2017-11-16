#include<unistd.h>
#include<stdio.h>
#include<stdlib.h>
#include<error.h>
#include<sys/wait.h>
int main()
{int sum=0,a[100],status,sum1,sum2,sum3;

for(int i=0;i<100;i++)
   a[i]=rand();
int cpid;
cpid=fork();
if(cpid<0)
	printf("failed");
else if(cpid==0)
{	for(int i=0;i<25;i++)
		sum+=a[i];
}
else{
wait(&status);
cpid=fork();
if(cpid<0)
	printf("failed");
else if(cpid==0)
{for(int i=25;i<50;i++)
	sum1+=a[i];

}else
{wait(&status);
for(int i=50;i<75;i++)
sum2=a[i];

}
for(int i=75;i<100;i++)
sum3+=a[i];
int sum4=sum+sum1+sum2+sum3;
printf("%d",sum4);
}
return 0;
}
