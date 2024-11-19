#include<stdio.h>
#include<stdlib.h>
int *a;
int max,top=-1;
void push(int ele)
{
	if(top==max-1)
	{
		printf("stack overflow\n");
		a=(int*)realloc(a,(++max)*sizeof(int));
	}
	a[++top]=ele;
}
int pop()
{
	if(top==-1)
	{
		printf("Stack underflow");
		return -1;
		
	}
	else
	{
		return(a[top--]);
	}
}
void display()
{
	int i;
	if(top==-1)
	{
		printf("stack is empty");
	}
	else
	{
		printf("elements :");
		for(i=top;i>=0;i--)
		{
			printf("%d\t",a[i]);
		}
	}
}
int main()
{
	int choice,ele,max;
	printf("max :");
	scanf("%d",&max);
	a=(int*)malloc(max*sizeof(int));
	while(1)
	{
		printf("\n Your choice");
		printf("\n 1-push\n 2-pop\n 3-display\n 4-exit");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:printf("element");
			scanf("%d",&ele);
			push(ele);
			break;
			case 2:ele=pop();
			if(ele!=-1)
			{
				printf("deleted element is %d\n",ele);
			}
			break;
			
			case 3:display();
			break;
			case 4: free(a);
			exit(0);
			default:printf("INVAILD INPUT");
		}
	}
}
