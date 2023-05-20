#include  <stdio.h>
#include  <stdlib.h>

struct node
{
	float data;
	node *pNext;
};

node *khoitaonode(float x)
{
	node *p =(node*)malloc(sizeof(node));
	p->pNext=NULL;
	p->data=x;
	return p;
}

struct list
{
	node *pHead;
	node * pTail;	
};

void khoitaolist(list &l)
{
	l.pHead=NULL;
	l.pTail=NULL;
}
void themvaocuoi(list &l, node *p)
{
	if(l.pHead==NULL){
		l.pHead=p;
	l.pTail=l.pHead;
	}
	

else 
	{
		l.pTail->pNext=p;
		l.pTail=p;
	}
}
void out(list l)
{
	for(node *k=l.pHead; k!=NULL;k=k->pNext)
	{
		printf("%.2f\t",k->data);
	}
}

int main()
{
	list l;
	khoitaolist(l);
	int n;
	printf("nhap so luong danh sach: ");
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		float x;
		printf("\n nhap pt %d : ",i+1);
		scanf("%f",&x);
		themvaocuoi(l,khoitaonode(x));


	}
printf("\n danh sach so thuc vua tao: ");
out(l);
return 0;


}































