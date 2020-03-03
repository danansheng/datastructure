#include<stdio.h>
#include<time.h>
#include<stdlib.h>
#define Maxsize 10
#define ElemType int
int choice;

typedef struct SequentialList{
	ElemType Data[Maxsize];
	int length;
}SList;
typedef struct SequentialList* LinkSList;

typedef struct LinkedList{
	ElemType data;
	LinkedList *next;
}LList;
typedef struct LinkedList* LinkLList;

void PrintMenu();
//Sequential Storage
void Function_SequentialStorage();//main
void InitSList(LinkSList L);//initialize the slist
void PrintSList(SList L);//print the slist
int Getlength(SList L);//get the length of slist
void FindElem(SList L,ElemType e);//find element in slist
void DeletefromSList(LinkSList L,int index);//Delete element in slist
void InsertintoSList(LinkSList L,int index,ElemType e);//Insert element into slist
//Linked Storage
void Function_LinkedStorage();//main
LinkLList InitLList(LinkLList L);//initialize the llist
int GetLListLength(LinkLList L);//return the length
LinkLList FindElembyIndex(LinkLList L,int index);//find element in llist by index
LinkLList FindElembyKey(LinkLList L,ElemType e);//find element in llist by key
void PrintLinkedList(LinkLList L);//print the element
void DeletefromLList(LinkLList *L,ElemType e);//delete one element in llist
void InsertintoLList(LinkLList *L,ElemType e,int index);//insert into llist


int main(){
	PrintMenu();
	while(true){
		scanf("%d",&choice);
		switch(choice){
			case 0:exit(0);
			case 1:Function_SequentialStorage();break;
			case 2:Function_LinkedStorage();break;
			defult:printf("Input error!");
		}
	}

} 

void PrintMenu(){
	printf("0--exit.\n");
	printf("1--Sequential Storage of Linear List.\n");
	printf("2--Linked Storage of Linear List.\n");
	printf("-------------------------------------------------------------\n");
	printf("Please input your choice:");
}
 
/////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////function of Sequential Storage
void Function_SequentialStorage(){
	SList L;
	ElemType e;
	int index;
	int length;
	InitSList(&L);
	PrintSList(L);
	length=Getlength(L);
	printf("The length of Sequential Storage of Linear List is %d.\n",length);
	printf("Please input the element which you want to find:");
	scanf("%d",&e);
	FindElem(L,e);
	printf("Please input the index of element which you want to delete:");
	scanf("%d",&index);
	DeletefromSList(&L,index);
	PrintSList(L);
	length=Getlength(L);
	printf("The length of Sequential Storage of Linear List is %d.\n",length);
	printf("Please input the index of element and the vaulue of element which you want to insert:");
	scanf("%d %d",&index,&e);
	InsertintoSList(&L,index,e);
	PrintSList(L);
	length=Getlength(L);
	printf("The length of Sequential Storage of Linear List is %d.\n",length);
	printf("The function of \"Sequential Storage of List\" have finished.\n");
	printf("-------------------------------------------------------------\n");
	PrintMenu();
}

void InitSList(LinkSList L){
	L->length=Maxsize;
	
	srand((unsigned)time(NULL));
	for(int i=0;i<Maxsize;i++){
		L->Data[i]=rand()%20;
	}
	printf("Sequential Storage of Linear List is successfully initialized.\n");
}

void PrintSList(SList L){
	printf("Now the sequence is:\n");
	for(int i=0;i<L.length;i++){
		printf("%d\t",L.Data[i]);
	}
	putchar('\n');
}

int Getlength(SList L){
	return L.length;
} 

void FindElem(SList L,ElemType e){
	int index;
	int i;
	if(Getlength(L)){
		for(i=0;i<L.length;i++){
			if(L.Data[i]==e){
				index=i;
				break;
			}
		}
		if(i==L.length){
			printf("Cannot find the element %d.\n",e);
		}	
		else {
			printf("The location of %d is number %d.\n",e,index+1);
		}	
	}
	else{
		exit(0);
	}
}

void DeletefromSList(LinkSList L,int index){
	if(L->length<index||index<1){
		printf("Input error!\n");
		exit(0);
	}
	for(int i=index-1;i<L->length;i++){
		L->Data[i]=L->Data[i+1];
	}
	L->length--;
	printf("Delete Successfully!\n");
}

void InsertintoSList(LinkSList L,int index,ElemType e){
	if(L->length==Maxsize){
		printf("The List is full.Can not insert into this list.\n");
		exit(0);
	}
	else{
		for(int i=L->length;i>index-1;i--){
		L->Data[i]=L->Data[i-1];
	}
	L->Data[index-1]=e;
	L->length++;
	printf("Insert Successfully!\n");
	}

}

/////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////function of Linked Storage
void Function_LinkedStorage(){
	LinkLList L;
	LinkLList n;
	int length;
	ElemType e;
	int index;
	L=InitLList(L);
	length=GetLListLength(L);
	printf("The length of Linked Storage of Linear List is %d.\n",length);
	PrintLinkedList(L);
	printf("Please input the value of element which you want to find:\n");
	scanf("%d",&e);
	FindElembyKey(L,e);
	printf("Please input the index of element which you want to find:\n");
	scanf("%d",&index);
	n=FindElembyIndex(L,index);
	printf("The value of this element is %d.\n",n->data);
	PrintLinkedList(L);
	printf("Please input the value of the element which you want to delete:");
	scanf("%d",&e);
	DeletefromLList(&L,e);
	length=GetLListLength(L);
	printf("The length of Linked Storage of Linear List is %d.\n",length);
	PrintLinkedList(L);
	printf("Please input the index of element and the vaulue of element which you want to insert:");
	scanf("%d %d",&e,&index);
	InsertintoLList(&L,e,index);
	length=GetLListLength(L);
	printf("The length of Linked Storage of Linear List is %d.\n",length);
	PrintLinkedList(L);
	printf("The function of \"Sequential Storage of List\" have finished.\n");
	printf("-------------------------------------------------------------\n");
	PrintMenu();
}

LinkLList InitLList(LinkLList L){
	L=(LinkLList)malloc(sizeof(LList));
	L->next=NULL;
	LinkLList r;
	r=L;
	srand((unsigned)time(NULL));
	LinkLList p; 
	for(int i=0;i<Maxsize;i++){
		p=(LinkLList)malloc(sizeof(LList));
		p->next=NULL;
		p->data=rand()%20;
		r->next=p;
		r=p;
	}
	printf("Linked Storage of Linear List is successfully initialized.\n");
	return L;
}

int GetLListLength(LinkLList L){
	LinkLList p;
	p=(LinkLList)malloc(sizeof(LList));
	p=L->next;
	int count=0;
	while(p!=NULL){
		count++;
		p=p->next;
	}
	return count;
}

LinkLList FindElembyKey(LinkLList L,ElemType e){
	if(GetLListLength(L)){
		LinkLList p=L->next;
		while(p!=NULL){
			if(p->data==e){
				printf("Find it!\n");
				return p;
			}
			p=p->next;
		}
		printf("Cannot find the element!\n");
	}
	else{
		printf("error!\n");
		exit(0);
	}
}

LinkLList FindElembyIndex(LinkLList L,int index){
	LinkLList r=L->next;
	int j=1;
	if(!GetLListLength(L)){
		printf("Error!There is no element in this Linked List!\n");
		exit(0);
	}
	if(index>GetLListLength(L)){
		printf("Error!index is bigger than length!\n");
		exit(0);
	}
	while(r!=NULL&&j<index){
		r=r->next;
		j++;
	}
	if(j==index) return r;
	else return NULL;
}

void PrintLinkedList(LinkLList L){
	LinkLList p=L->next;
	printf("Now the sequence is:\n");
	while(p!=NULL){
		printf("%d\t",p->data);
		p=p->next;
	}
	putchar('\n');
}

void DeletefromLList(LinkLList *L,ElemType e){
	LinkLList r=(*L)->next;
	LinkLList p;
	if(r==NULL){
		printf("Error!There is no element in this Linked List!\n");
		exit(0);
	}
	printf("OK!Now we have to find this element!\n");
	if(FindElembyKey((*L),e)==NULL){
		printf("Error!This element is not in the Linked List!\n");
		exit(0);
	}
	while(r!=NULL){
		if(r->data==e){
			p->next=r->next;
			free(r);
			printf("Delete successfully!\n");
			break;
		}
		else{
			p=r;
			r=r->next;
		}
	}
}

void InsertintoLList(LinkLList *L,int index,ElemType e){
	if(index>GetLListLength(*L)){
		printf("Error!index is bigger than length!\n");
		exit(0);
	}
	LinkLList p=FindElembyIndex(*L,index-1);
	LinkLList s=(LinkLList)malloc(sizeof(LList));
	s->data=e;
	s->next=p->next;
	p->next=s;
	printf("Insert successfully!");
}
