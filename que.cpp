#include<stdio.h>
#include<stdlib.h>
int *a,rear=-1,front=0,count=0,n,max;
void enqueue()
{ int ele;
	if(count==n)
	{
		printf("queue underflow");
	}
	else
	{
	printf("enter the element");
		scanf("%d",ele);
		rear=(rear+1)%max;
		a[rear]=ele;
		count++;
	}
}
void dequeue()
{
	if(count==0)
	printf("queue under flow");
	else{
		printf("the enter element is %d",a[front]);
		front=(front+1)%max;
		count--;
		}
}
void display()
{ int k;
k==front;
	if(count==0)
	{
		printf("it is emoty");
		
	}
	else
	{
	 for(int i=0;i<count;i++)
	 {
	 	printf("%d\t", a[k]);
	 	k=(k+1)%max;
	 }
	}
}
int main()
{   int choice;
	printf("enter the n");
	scanf("%d",&n);
	a=(int*)malloc(n*sizeof(int));
while(1)
{	
	printf("enter the choice");
	scanf("%d",&choice);
	switch(choice)
	{
		case 1:
		 enqueue();
		      
		break;
		case 2: dequeue();
		break;
		case 3: display();
		break;
		case 4 : free(a);
		exit(0);
		default :
			printf("INVAILD INPUT");
	}
return  0 ;	
}
}

