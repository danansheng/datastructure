#include<stdio.h>
#include<stdlib.h>
#define ElemType char


typedef struct node{
	ElemType data;
	struct node *lchild;
	struct node *rchild;
}BiTNode,*BiTree;

typedef struct stacknode{
	BiTree T;
	struct stacknode *next;
}Stack,*StackPtr;

typedef struct stack{
	StackPtr top;
	int count;
}LinkStack;



void CreateBiTree(BiTree *T);
void Init_Stack(LinkStack *S);
bool IsEmpty(LinkStack S);
void Push(LinkStack *S,BiTree t);
BiTree Pop(LinkStack *S);
void PreorderTraverse(BiTree T);
void InOrderTraverse(BiTree T);
void PostOrderTraverse(BiTree T);
void PreorderTraverse_non_recursion(BiTree T);
void InorderTraverse_non_recursion(BiTree T);
void PostorderTraverse_non_recursion(BiTree T);


LinkStack S;

int main(){
	BiTree T;
	CreateBiTree(&T);
	
	printf("Preorder recursive traversal:\n");
	PreorderTraverse(T);
	putchar('\n');
	printf("Preorder non-recursive traversal:\n");
	PreorderTraverse_non_recursion(T);

	printf("Inorder recursive traversal:\n");
	InOrderTraverse(T);
	putchar('\n');
	printf("Inorder non-recursive traversal:\n");
	InorderTraverse_non_recursion(T);
	
	printf("Postorder recursive traversal:\n");
	PostOrderTraverse(T);
	putchar('\n');
	printf("Postorder non-recursive traversal:\n");
	PostorderTraverse_non_recursion(T);
	return 0;
}

void CreateBiTree(BiTree *T){
	ElemType ch;
	scanf("%c",&ch);
	if(ch=='#'){
		*T=NULL;
	}else{
		*T=(BiTree)malloc(sizeof(BiTNode));
		(*T)->data=ch;
		CreateBiTree(&(*T)->lchild);
		CreateBiTree(&(*T)->rchild);
	}
}

void Init_Stack(LinkStack *S){
	S->top=NULL;
	S->count=0; 
}

bool IsEmpty(LinkStack S){
	if(S.count){
		return false;
	}
	return true;
}

void Push(LinkStack *S,BiTree t){
	StackPtr s=(StackPtr)malloc(sizeof(Stack));
	s->next=S->top;
	s->T=t;
	S->top=s;
	S->count++;
}

BiTree Pop(LinkStack *S){
	StackPtr s;
	s=S->top;
	S->top=S->top->next;
	S->count--;
	return s->T;
}

//recursion
void PreorderTraverse(BiTree T){
	if(T==NULL){
		return;
	}
	printf("%c",T->data);
	PreorderTraverse(T->lchild);
	PreorderTraverse(T->rchild);
}

void InOrderTraverse(BiTree T){
	if(T==NULL){
		return;
	}
	InOrderTraverse(T->lchild);
	printf("%c",T->data);
	InOrderTraverse(T->rchild);
} 

void PostOrderTraverse(BiTree T){
	if(T==NULL){
		return;
	}
	PostOrderTraverse(T->lchild);
	PostOrderTraverse(T->rchild);
	printf("%c",T->data);
}

//non-recursion
void PreorderTraverse_non_recursion(BiTree T){
	Init_Stack(&S);
	BiTree t=T;
	while(t||!IsEmpty(S)){
		while(t){
			Push(&S,t);
			printf("%c",t->data);
			t=t->lchild;
		}
		if(!IsEmpty(S)){
			t=Pop(&S);
			t=t->rchild;
		}
	}
	putchar('\n');
}

void InorderTraverse_non_recursion(BiTree T){
	Init_Stack(&S);
	BiTree t=T;
	while(t||!IsEmpty(S)){
		while(t){
			Push(&S,t);
			t=t->lchild;
		}
		if(!IsEmpty(S)){
			t=Pop(&S);
			printf("%c",t->data);
			t=t->rchild;
		}
	}
	putchar('\n');
}

void PostorderTraverse_non_recursion(BiTree T){
	Init_Stack(&S);
	LinkStack S2;
	Init_Stack(&S2);
	BiTree t=T;
	while(t||!IsEmpty(S)){
		while(t){
			Push(&S,t);
			Push(&S2,t);
			t=t->rchild;
		}
		if(!IsEmpty(S)){
			t=Pop(&S);
			t=t->lchild;
		}
	}
	while(!IsEmpty(S2)){
		t=Pop(&S2);
		printf("%c",t->data);
	}
	putchar('\n');
}
