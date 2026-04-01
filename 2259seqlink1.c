#include<stdio.h>
#include<stdlib.h>
typedef int ElemType;
typedef struct node
{
	ElemType data;
	struct node *next;
}slink;
slink *CreLink(int n)//建表 
{
	slink *head,*p,*s;//注意区分指针变量、指针、指针所指向结点和结点的域 
	int i;
	p=head=(slink *)malloc(sizeof(slink));
	for(i=1;i<=n;i++)
	{
		s=(slink *)malloc(sizeof(slink));
		scanf("%d",&s->data);
		p->next=s;
		p=s;
	}
	p->next=NULL;
	return head;
}
int GetLen(slink *head)//求表长 
{
	slink *p;
	int n;
	p=head->next;
	n=0;
	while(p!=NULL)
	{
		n++;
		p=p->next;
	}
	return n;
}
int GetElem(slink *head,int i,ElemType *e)//取元素 
{
	slink *p;
	int j;
	if(i<1)
	{
		printf("参数不合理，请重新输入！\n\n");
		return 0;
	}
	p=head->next;
	j=1;
	while(p!=NULL&&j<i)
	{
		p=p->next;
		j++;
	}
	if(p==NULL)
	{
		printf("参数超出表长，请重新输入！\n\n");
		return 0;
	}
	*e=p->data;
	return 1;
}
int Locate(slink *head,ElemType x,int *t)//定位
{
	int i=1;
	slink *p=head->next;
	while(p!=NULL&&p->data!=x)
	{
		p=p->next;
		i++;
	}
	if(p)
	{
		*t=i;
		return 1;
	}
	else return 0;
}
int Delete(slink *head,int i,ElemType *e)//删除 
{
	slink *p,*q;
	int j;
	if(i<1)
	{
		printf("参数不合理，请重新输入！\n\n");
		return 0;
	}
	p=head;
	j=0;
	while(p->next!=NULL&&j<i-1)
	{
		p=p->next;
		j++;
	}
	if(p->next==NULL)
	{
		printf("参数超出表长，请重新输入！\n\n");
		return 0;
	}
	q=p->next;
	*e=q->data;
	p->next=q->next;
	free(q);
	return 1;
}
int Insert(slink *head,int i,ElemType x)//插入 
{
	slink *p,*q;
	int j;
	if(i<1)
	{
		printf("参数不合理，请重新输入！\n\n");
		return 0;
	}
	p=head;
	j=0;
	while(p!=NULL&&j<i-1)
	{
		p=p->next;
		j++;
	}
	if(p==NULL)
	{
		printf("参数超出表长，请重新输入！\n\n");
		return 0;
	}
	q=(slink *)malloc(sizeof(slink));
	q->data=x;
	q->next=p->next;
	p->next=q;
	return 1;
}
void List(slink *head)//输出 
{
	slink *p;
	p=head->next;
	while(p!=NULL)
	{
		printf("%d ",p->data);
		p=p->next;
	}
	printf("\n");
}
void SwapMin(slink *head)//将最小值移动到链表最前面
{
	slink *p,*q,*pre;
	p=head->next;
	pre=head;
	q=p;
	while(p->next!=NULL)
	{
		if(q->data>p->next->data)
		{
			q=p->next;
			pre=p;
		}
		p=p->next;
	}
	if(q==head->next)
	{
		printf("最小值已在最前面\n");
		return ;
	}
	else
	{
		pre->next=q->next;
		q->next=head->next;
		head->next=q;
	}
}
int main()
{
	slink *H;
	int n,i,op,x;
	printf("输入结点个数\n");
	scanf("%d",&n);
	printf("输入%d个结点数据\n",n);
	H=CreLink(n);
	printf("您建立的单链表如下\n");
	List(H);
	printf("\n");
	while(1)
	{
		printf("-------------------请选择操作-------------------\n");
		printf("输出当前表长，请按1\n");
		printf("取第i个元素的值，请按2\n");
		printf("定位第1个值为x的元素，请按3\n");
		printf("删除第i个元素，请按4\n");
		printf("在第i个元素前插入一个值为x的元素，请按5\n");
		printf("输出当前单链表，请按6\n");
		printf("将最小值移动到链表最前面，请按7\n");
		printf("结束程序，请按8\n\n");
		scanf("%d",&op);
		switch(op)
		{
			case 1:
			{
				printf("当前表长为%d\n\n",GetLen(H));
			}break;
			case 2:
			{
				printf("请输入参数i\n");
				scanf("%d",&i);
				if(GetElem(H,i,&x))
				{
					printf("第%d个元素的值为%d\n\n",i,x);
				}
			}break;
			case 3:
			{
				printf("请输入参数x\n");
				scanf("%d",&x);
				int t;
				if(Locate(H,x,&t))
				{
					printf("它第一次出现在位序%d\n\n",t);
				}
				else
				{
					printf("无法定位到该元素\n\n");
				}
			}break;
			case 4:
			{
				printf("请输入参数i\n");
				scanf("%d",&i);
				if(Delete(H,i,&x))
				{
					printf("您删除了%d\n",x);
					printf("更新后的单链表如下\n");
					List(H);
					printf("\n");		
				}
			}break;
			case 5:
			{
				printf("请输入参数i和x\n");
				scanf("%d%d",&i,&x);
				if(Insert(H,i,x))
				{
					printf("更新后的单链表如下\n");
					List(H);
					printf("\n");					
				}
			}break;
			case 6:
			{
				printf("当前单链表如下\n");
				List(H);
				printf("\n");
			}break;
			case 7:
			{
				SwapMin(H);
				printf("更新后的单链表如下\n");
				List(H);
				printf("\n");
			}break;
			default:exit(0);break;
		}
	}
	return 0;
}
