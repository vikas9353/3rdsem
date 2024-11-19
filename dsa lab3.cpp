#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<string.h>
#include<math.h>
char istack[20];
int tos =-1;
float stack[20];
int top=-1;
void ipush(char s)
{
	istack[++tos]=s;
}
char ipop()
{
	return istack[tos--];
}
int preced(char s)
{
	switch(s)
	{
		case '^':return 4;
		case '*':
		case '%':
		case '/':return 3;
		case '+':
		case '-':return 2;
		case '(':
		case ')':return 1;	
	}
	return 0;
}
void convertip(char infix[20],char postfix[20])
{
	int i,j=0;
	char symbol;
	ipush('(');
	int n =strlen(infix);
	infix[n]=')';
	n=n+1;
	for(i=0;i<n;i++)
	{
		symbol=infix[i];
		switch(symbol)
		{
			case '(':ipush(symbol);
			break;
			case ')':while(istack[tos]!='(')
			postfix[j++]=ipop();
			ipop();
			break;
			case '^':
			case '*':
	    	case '/':
		    case '%':
		    case '+':
	     	case '-':while(preced(symbol)<=preced(istack[tos]))
	     	             postfix[j++]=ipop();
	     	             ipush(symbol);
	     	             break ;
	     	default:postfix[j++]=symbol;
	    	
		}
	}
	postfix[j]='\0';
}
void push(float ele)
{
	stack[++top]=ele;
	
}
float pop()
{
	return stack[top--];
}
void evalute(char postfix[50])
{
	int i;
	char sym;
	float op1,op2,result,x;
	for(i=0;i<strlen(postfix);i++)
	{
		sym=postfix[i];
		if(isalpha(sym))
		{
			printf("\n enter value for %c\t",sym);
			scanf("%f",&x);
			push(x);
		}
		else
		{
			op2=pop();
			op1=pop();
			switch(sym)
			{
			  case '+':push(op1+op2);
			  break;
			  case '-':push(op1-op2);
			  break;
			  case '%':push((int)op1%(int)op2);
			  break;
			  case '/':push((int)op1/(int)op2);
			  break;
			  case '*':push((int)op1*(int)op2);
			  break;
			  case '^':push(pow(op1,op2));
			  break;
			  default :printf("INVAILD");
			  exit(0);	
			}
		}
	}
	result=pop();
	printf("result is %f\n",result);
}
int main()
{
	char infix[20],postfix[20];
	printf("enter the infix exp");
	gets(infix);
	convertip(infix,postfix);
	printf("postfix exp is %s",postfix);
	evalute(postfix);
	return 0;
}
