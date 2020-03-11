#include<stdio.h>
#include<time.h>
#include<stdlib.h>
#define Maxsize 10
#define ElemType int
int choice;

//linear list 
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

//stack
typedef struct stack{
	ElemType data[Maxsize];
	int top;
}SqStack;
typedef struct stack* LinkSqStack;

typedef struct stacknode{
	ElemType data;
	struct stacknode *next;
}StackNode;
typedef struct stacknode* LinkStackPtr;

typedef struct linkstack{
	LinkStackPtr top;
	int count;
}LinkStack;

//queue
typedef struct queue{
	ElemType data[Maxsize];
	int front;
	int rear;
}SqQueue;
typedef struct queue* LinkQueue;

typedef struct queuenode{
	ElemType data;
	struct queuenode* next;
}QueueNode;
typedef struct queuenode* QueuePtr;

typedef struct linkedqueue{
	QueuePtr front,rear;
	int count;
}LinkedQueue;

void PrintMenu();
//linear list
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

//Stack
//Sequential Storage
void Function_SequentialStorage_Stack();//main
void Init_SqStack(LinkSqStack S);
bool Push_SqStack(LinkSqStack S,ElemType e);
bool Pop_SqStack(LinkSqStack S,ElemType *e);
bool IsFull_SqStack(SqStack S);
bool IsEmpty_SqStack(SqStack S);
int GetLength_SqStack(SqStack S);
void Print_SqStack(SqStack S);
//Linked Storage
void Funciton_LinkedStorage_Stack();
void Init_LinkStack(LinkStack *S);
void Push_LinkStack(LinkStack *S,ElemType e);
void Pop_LinkStack(LinkStack *S,ElemType *e);
bool IsEmpty_LinkStack(LinkStack S);
int GetLength_LinkStack(LinkStack S);
void Print_LinkStack(LinkStack S);

//Queue
//Sequential Storage(circular-queue)
void Function_SequentialStorage_Queue();
void Init_SqQueue(LinkQueue Q);
int GetLength_SqQueue(SqQueue Q);
void EnQueue(LinkQueue Q,ElemType e);
void DeQueue(LinkQueue Q,ElemType *e);
void Print_SqQueue(SqQueue Q);
//Linked Storage
void Function_LinkedStorage_Queue();
void Init_LinkQueue(LinkedQueue *Q);
int GetLength_SqQueue(LinkedQueue Q);
void EnQueue_LinkedQueue(LinkedQueue *Q,ElemType e);
void DeQueue(LinkedQueue *Q,ElemType *e);
void Print_LinkedQueue(LinkedQueue Q);

int main(){
	PrintMenu();
	while(true){
		scanf("%d",&choice);
		switch(choice){
			case 0:exit(0);
			case 1:Function_SequentialStorage();break;
			case 2:Function_LinkedStorage();break;
			case 3:Function_SequentialStorage_Stack();break;
			case 4:Funciton_LinkedStorage_Stack();break;
			case 5:Function_SequentialStorage_Queue();break;
			case 6:Function_LinkedStorage_Queue();break;
			defult:printf("Input error!");
		}
	}

} 

void PrintMenu(){
	printf("0--exit.\n");
	printf("------------------------Linear List--------------------------\n");
	printf("1--Sequential Storage of Linear List.\n");
	printf("2--Linked Storage of Linear List.\n");
	printf("-----------------------Heap and Stack------------------------\n");
	printf("3--Sequential Storage of Stack\n");
	printf("4--Linked Storage of Stack\n");
	printf("---------------------------Queue-----------------------------\n");
	printf("5--Sequential Storage of Queue\n");
	printf("6--Linked Storage of Queue\n");
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


//////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////function of Sequential Storage of Stack
void Function_SequentialStorage_Stack(){
	SqStack S;
	ElemType e;
	Init_SqStack(&S);
	printf("Please input the vaulue of element which you want to insert:");
	scanf("%d",&e);
	Push_SqStack(&S,e);
	Print_SqStack(S);
	printf("Please input the vaulue of element which you want to insert:");
	scanf("%d",&e);
	Push_SqStack(&S,e);
	Print_SqStack(S);
	printf("Please input the vaulue of element which you want to insert:");
	scanf("%d",&e);
	Push_SqStack(&S,e);
	Print_SqStack(S);
	printf("Now we will pop from stack!\n");
	Pop_SqStack(&S,&e);
	printf("The element is %d.\n",e);
	Print_SqStack(S);
	printf("The function of \"Sequential Storage of Stack\" have finished.\n");
	printf("-------------------------------------------------------------\n");
	PrintMenu();
}

void Init_SqStack(LinkSqStack S){
	//可以有其它初始化操作,这里仅仅建立空栈 
	S->top=-1;
	printf("Initialize successfully!\n");
}

bool Push_SqStack(LinkSqStack S,ElemType e){
	if(S->top==Maxsize-1){
		printf("Error!The stack is full!\n");
		return false;
	}
	S->top++;
	S->data[S->top]=e;
	printf("Push successfully!\n");
	return true;
}

bool Pop_SqStack(LinkSqStack S,ElemType *e){
	if(S->top==-1){
		printf("Error!The stack is empty!\n");
		return false;
	}
	*e=S->data[S->top];
	S->top--;
	printf("Pop successfully!\n");
	return true;
}

bool IsFull_SqStack(SqStack S){
	if(S.top==Maxsize-1){
		return true;
	}
	return false;
}

bool IsEmpty_SqStack(SqStack S){
	if(S.top==-1){
		return true;
	}
	return false;
}

int GetLength_SqStack(SqStack S){
	return S.top+1;
}

void Print_SqStack(SqStack S){
	if(IsEmpty_SqStack(S)){
		printf("The stack is empty!\n");
		return;
	}
	printf("Now the Stack is:\n");
	for(int i=0;i<=S.top;i++){
		printf("%d\t",S.data[i]);
	}
	putchar('\n'); 
}

//////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////function of Linked Storage of Stack
void Funciton_LinkedStorage_Stack(){
	LinkStack S; 
	ElemType e;
	Init_LinkStack(&S);
	printf("Please input the vaulue of element which you want to push:");
	scanf("%d",&e);
	Push_LinkStack(&S,e);
	Print_LinkStack(S);
	printf("Please input the vaulue of element which you want to push:");
	scanf("%d",&e);
	Push_LinkStack(&S,e);
	Print_LinkStack(S);
	printf("Please input the vaulue of element which you want to push:");
	scanf("%d",&e);
	Push_LinkStack(&S,e);
	Print_LinkStack(S);
	printf("Now we will pop from stack!\n");
	Pop_LinkStack(&S,&e);
	printf("The element is %d.\n",e);
	Print_LinkStack(S);
	printf("The function of \"Linked Storage of Stack\" have finished.\n");
	printf("-------------------------------------------------------------\n");
	PrintMenu();
}

void Init_LinkStack(LinkStack *S){
	S->top=NULL;
	S->count=0;
	printf("Initialize successfully!\n");
}

void Push_LinkStack(LinkStack *S,ElemType e){
	LinkStackPtr s=(LinkStackPtr)malloc(sizeof(StackNode));
	s->data=e;
	s->next=S->top;
	S->top=s;
	S->count++;
	printf("Push successfully!\n");
}

void Pop_LinkStack(LinkStack *S,ElemType *e){
	LinkStackPtr p;
	if(IsEmpty_LinkStack(*S)){
		printf("Error!The stack is empty!\n");
		return;
	}
	p=S->top;
	S->top=S->top->next;
	free(p);
	S->count--;
	printf("Pop successfully!\n");
}

bool IsEmpty_LinkStack(LinkStack S){
	if(S.count==0){
		return true;
	}
	return false;
}

int GetLength_LinkStack(LinkStack S){
	return S.count;
}

void Print_LinkStack(LinkStack S){
	LinkStackPtr n=S.top;
	int a[Maxsize],c=0;
	while(n){
		a[c++]=n->data;
		n=n->next;
	}
	printf("Now the Stack is:\n");
	for(int i=c-1;i>=0;i--){
		printf("%d\t",a[i]);
	}
	printf("\n");
}

//////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////function of Sequential Storage of Queue
void Function_SequentialStorage_Queue(){
	SqQueue Q;
	ElemType e;
	Init_SqQueue(&Q);
	printf("Please input the vaulue of element which you want to enqueue:");
	scanf("%d",&e);
	EnQueue(&Q,e);
	Print_SqQueue(Q);
	printf("Please input the vaulue of element which you want to enqueue:");
	scanf("%d",&e);
	EnQueue(&Q,e);
	Print_SqQueue(Q);
	printf("Please input the vaulue of element which you want to enqueue:");
	scanf("%d",&e);
	EnQueue(&Q,e);
	Print_SqQueue(Q);
	printf("Now we will dequeue from queue!\n");
	DeQueue(&Q,&e);
	printf("The element is %d.\n",e);
	Print_SqQueue(Q);
	printf("The function of \"Sequential Storage of Queue\" have finished.\n");
	printf("-------------------------------------------------------------\n");
	PrintMenu();
}

void Init_SqQueue(LinkQueue Q){
	Q->front=0;
	Q->rear=0;
	printf("Initialize successfully!\n");
}

int GetLength_SqQueue(SqQueue Q){
	return (Q.rear-Q.front+Maxsize)%Maxsize;
}

void EnQueue(LinkQueue Q,ElemType e){
	if((Q->rear+1)%Maxsize==Q->front){
		printf("Error!The Queue is full!\n");
		return;
	}
	Q->data[Q->rear]=e;
	Q->rear=(Q->rear+1)%Maxsize;
	printf("Enqueue successfully!\n");
}

void DeQueue(LinkQueue Q,ElemType *e){
	if(Q->rear==Q->front){
		printf("Error!The Queue is empty!\n");
		return;
	}
	*e=Q->data[Q->front];
	Q->front=(Q->front+1)%Maxsize;
}

void Print_SqQueue(SqQueue Q){
	if(GetLength_SqQueue(Q)){
		printf("Now the Queue is:\n");
		if(Q.front<Q.rear){
			for(int i=Q.front;i<Q.rear;i++){
				printf("%d\t",Q.data[i]);
			}
		}
		else{
			int j;
			for(int i=Q.front;i<Q.rear+Maxsize;i++){
				j=(i>=Maxsize?i%Maxsize:i);
				printf("%d\t",Q.data[j]);
			}
		}
		putchar('\n');
	}
}
//////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////function of Linked Storage of 
void Function_LinkedStorage_Queue(){
	LinkedQueue Q;
	ElemType e;
	Init_LinkQueue(&Q);
	printf("Please input the vaulue of element which you want to enqueue:");
	scanf("%d",&e);
	EnQueue_LinkedQueue(&Q,e);
	Print_LinkedQueue(Q);
	printf("Please input the vaulue of element which you want to enqueue:");
	scanf("%d",&e);
	EnQueue_LinkedQueue(&Q,e);
	Print_LinkedQueue(Q);
	printf("Please input the vaulue of element which you want to enqueue:");
	scanf("%d",&e);
	EnQueue_LinkedQueue(&Q,e);
	Print_LinkedQueue(Q);
	printf("Now we will dequeue from queue!\n");
	DeQueue(&Q,&e);
	printf("The element is %d.\n",e);
	Print_LinkedQueue(Q);
	printf("The function of \"Linked Storage of Queue\" have finished.\n");
	printf("-------------------------------------------------------------\n");
	PrintMenu();
}

void Init_LinkQueue(LinkedQueue *Q){
	QueuePtr head=(QueuePtr)malloc(sizeof(QueueNode));
	Q->front=Q->rear=head;
	Q->count=0;
	printf("Initialize successfully!\n");
}

int GetLength_SqQueue(LinkedQueue Q){
	return Q.count;
}

void EnQueue_LinkedQueue(LinkedQueue *Q,ElemType e){
	QueuePtr s=(QueuePtr)malloc(sizeof(QueueNode));
	s->data=e;
	s->next=NULL;
	Q->rear->next=s;
	Q->rear=s;
	Q->count++;
	printf("Enqueue successfully!\n");
}

void DeQueue(LinkedQueue *Q,ElemType *e){
	QueuePtr q;
	if(Q->front==Q->rear){
		printf("Error!The Queue is empty!\n");
		return;
	}
	q=Q->front->next;
	Q->front->next=q->next;
	if(Q->rear==q){//let rear point to the head if q is equal to rear
		Q->rear=Q->front;
	}
	*e=q->data;
	Q->count--; 
	free(q);
}

void Print_LinkedQueue(LinkedQueue Q){
	if(Q.count){
		printf("Now the Queue is:\n");
		QueuePtr q=Q.front->next;
		while(q){
			printf("%d\t",q->data);
			q=q->next;
		}
		putchar('\n');
	}
}
