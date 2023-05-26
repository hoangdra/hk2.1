#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct sinhvien
{
	char hoten[50];
	int maso;
	float diem;
	
}SV;

typedef struct node
{
	SV data;
	node* next;
}Node;

typedef struct list
{
node *pHead;
node *pTail;
};

void khoitao(list &ds)
{
		ds.pHead = NULL;
		ds.pTail = NULL;
}
int kiemtrarong(list ds)
{
	if(ds.pHead == NULL)
	{
		return 1;
	}
return 0;
}
node *taonode(char Name[20], int maso, float diem)
{
	node *p=(node*)malloc(sizeof(node));
	if(p == NULL )
	{
		printf("khong du bo nho");
		return NULL;

	}
	p->data.maso = maso;
	strcpy(p->data.hoten,Name);
	p->data.diem=diem;
	return p;
	
}
void themdauds(list &ds, node *p)
{
	if(ds.pHead==NULL)
	{
		ds.pHead=p;
		ds.pTail=p;
	}else{
		p->next=ds.pHead;
		ds.pHead=p;
	}
}
void nhap(list &ds,int n)
{
	SV data;
	for(int i=0 ; i<n ; i++){
	  printf("\n\nNHAP THONG TIN SV %d:   ",i+1);
	//fflush(stdin);
	printf("\nNhap ma so sinh vien: ");
	scanf("%d",&data.maso);
	printf("nhap ho va ten:  ");
	fflush(stdin);
	gets(data.hoten);
	printf("nhap so diem  :  ");
	//fflush(stdin);
	scanf("%f",&data.diem);
	printf("\n");
	themdauds(ds,taonode(data.hoten,data.maso,data.diem));
	}
	
}
void xuat(list ds)
{
	printf("\nThong tin vua nhap: ");
	for(node *p=ds.pHead;p!=NULL;p=p->next)
	{
	
		printf("\n    %d,  %s,  %2.f",p->data.maso,p->data.hoten,p->data.diem);
	}
}

void xoadau(list &ds)

{
	for(node *p =ds.pTail; p!= NULL; p = p->next)
	{
		if(p->next == ds.pHead)
		{
			delete ds.pHead;
			p->next =NULL;
			ds.pHead=p;
		}
	}

xuat(ds);

}

int main()
{
	list ds;
	int n;
    printf("NHAP SO LUONG SINH VIEN: ");
    scanf("%d",&n);
    khoitao(ds);
    nhap(ds,n);
    printf("\nDANH SACH SINH VIEN\n");
    xuat(ds);
    printf("\nDANH SACH SINH VIEN DA XOA PHAN TU DAU\n");
    xoadau(ds);
}










