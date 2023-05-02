#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<ctype.h>
#define STACK_INIT_SIZE 20
#define STACKINCREMENT 10
typedef char ElemType;
typedef struct 
{
	ElemType *base;
	ElemType *top;
	int stackSize;
}sqStack;

void InitStack(sqStack *s)
{
	s->base=(ElemType*)malloc(STACK_INIT_SIZE*sizeof(ElemType));
	if(!s->base)
	{
		printf("�ڴ����ʧ��");
		exit(0);
	}
	s->top=s->base;
	s->stackSize=STACK_INIT_SIZE;
}
void push(sqStack*s,ElemType e)
{
	if(s->top-s->base>=s->stackSize)
	{
		s->base=(ElemType*)realloc(s->base,(STACK_INIT_SIZE+STACKINCREMENT)*sizeof(ElemType));
		if(!s->base)
		{
			printf("�ڴ����ʧ��");
			exit(0) ;
		}
		s->stackSize=STACKINCREMENT+STACK_INIT_SIZE;
	}
	*(s->top)=e;
	s->top++;
}
void pop(sqStack*s,ElemType *e)
{
	if(s->base==s->top)
	{
		return ;
	}
	*e=*--(s->top);
}
int stackLen(sqStack s)
{
	return s.top-s.base;
}
int main()
{
	int len,sum=0,i;
	sqStack s;
	InitStack(&s);
	char c;
	printf("�����������������#����\n"); 
	scanf("%c",&c);
	while(c!='#')
	{
		push(&s,c);
		scanf("%c",&c);
	}
	getchar();
	len=stackLen(s);
	for(i=0;i<len;i++)
	{
		pop(&s,&c);
		sum+=(c-48)*pow(2,i);
	}
	printf("\n�ö�����ת��Ϊʮ����Ϊ%d",sum);
	return 0;
}

