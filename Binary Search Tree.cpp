#include<stdio.h>
#include<stdlib.h>
#define ElemType int

typedef struct node{
	ElemType data;
	struct node *lchild;
	struct node *rchild;
}BSTNode,*BSTree; 

BSTree NewNode(ElemType e);
void print(BSTree T);
BSTree Find_Successor(BSTree T);
BSTree Find_Precursor(BSTree T);
bool Search(BSTree T,ElemType e,BSTree P,BSTree *c);
void Insert(BSTree *T,ElemType e);
BSTree create(int data[],int n);
void Delete(BSTree *T,ElemType e);
void Insert1(BSTree *T,ElemType e);
BSTree create1(int data[],int n);
BSTree Delete1(BSTree T,ElemType e);

int main(){
	int data[]={62,88,58,47,35,73,51,99,37,93};
	int n=10;
	BSTree T=create1(data,n);
	print(T);
//	Delete(&T,37);
	Delete1(T,37);
	putchar('\n');
	print(T);
	return 0;
}

BSTree NewNode(ElemType e){
	BSTree s=(BSTree)malloc(sizeof(BSTNode));
	s->data=e;
	s->lchild=NULL;
	s->rchild=NULL;
	return s;
}

//insert
void Insert(BSTree *T,ElemType e){
	BSTree c;
	if(!Search(*T,e,NULL,&c)){
		BSTree s=NewNode(e);
		if(!c){
			*T=s;
		}else if(e>c->data){
			c->rchild=s;
		}else{
			c->lchild=s;
		}
	}
}

void Insert1(BSTree *T,ElemType e){
	if(*T==NULL){
		*T=NewNode(e);
		return ;
	}
	if(e==(*T)->data){
		return;
	}else if(e>(*T)->data){
		Insert1(&(*T)->rchild,e);
	}else{
		Insert1(&(*T)->lchild,e);
	}
}

BSTree create(int data[],int n){
	BSTree T=NULL;
	for(int i=0;i<n;i++){
		Insert(&T,data[i]);
	}
	return T;
}

BSTree create1(int data[],int n){
	BSTree T=NULL;
	for(int i=0;i<n;i++){
		Insert1(&T,data[i]);
	}
	return T;
}

//delete
void Delete(BSTree *T,ElemType e){
	if(!*T){
		return;
	}
	BSTree s;
	if((*T)->data==e){
		if((*T)->lchild==NULL&&(*T)->rchild==NULL){
			(*T)=NULL;
		}else if((*T)->lchild!=NULL){
			s=Find_Precursor((*T)->lchild);
			(*T)->lchild->data=s->data;
			Delete(&(*T)->lchild,s->data);
		}else{
			s=Find_Successor((*T)->rchild);
			(*T)->rchild->data=s->data;
			Delete(&(*T)->rchild,s->data);
		}
	}else if((*T)->data>e){
		Delete(&(*T)->lchild,e);
	}else{
		Delete(&(*T)->rchild,e);
	}
}

BSTree Delete1(BSTree T,ElemType e){
	if(!T){
		return NULL;
	}
	BSTree s;
	if(T->data==e){
		if(T->lchild==NULL&&T->rchild==NULL){
			T=NULL;
		}else if(T->lchild!=NULL){
			s=Find_Precursor(T->lchild);
			T->lchild->data=s->data;
			T->lchild=Delete1(T->lchild,s->data);
		}else{
			s=Find_Successor(T->rchild);
			T->rchild->data=s->data;
			T->rchild=Delete1(T->rchild,s->data);
		}
	}else if(T->data>e){
		T->lchild=Delete1(T->lchild,e);
	}else{
		T->rchild=Delete1(T->rchild,e);
	}
}

//find
bool Search(BSTree T,ElemType e,BSTree P,BSTree *c){
	if(T==NULL){
		*c=P;
		return false;
	}
	if(e>T->data){
		Search(T->rchild,e,T,c);
	}
	else if(e<T->data){
		Search(T->lchild,e,T,c);
	}else{
		*c=T;
		return true;
	}
}

//findprecursor
BSTree Find_Precursor(BSTree T){
	while(T->rchild!=NULL){
		T=T->rchild;
	}
	return T;
}

//findsuccessor

BSTree Find_Successor(BSTree T){
	while(T->lchild!=NULL){
		T=T->lchild;
	}
	return T;
}

void print(BSTree T){
	if(T==NULL){
		return;
	}
	print(T->lchild);
	printf("%d\t",T->data);
	print(T->rchild);
}

