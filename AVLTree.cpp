#include<stdio.h>
#include<stdlib.h>
#define LeftHigher 1
#define RightHigher -1
#define equal 0
#define ElemType int

typedef struct node {
	ElemType data;
	struct node *lchild;
	struct node *rchild;
	int height;
} AVLNode;
typedef struct node *AVLTree;

AVLTree Insert(AVLTree T,ElemType X);
AVLTree R_Rotate(AVLTree T);
AVLTree L_Rotate(AVLTree T);
AVLTree LR_Rotate(AVLTree T);
AVLTree RL_Rotate(AVLTree T);
int GetHeight(AVLTree T);
void Preorder(AVLTree T);
int Max(int a,int b);

int main() {
	int a[10]= {3,2,1,4,5,6,7,10,9,8};
	AVLTree T=NULL;
	for(int i=0; i<10; i++) {
		T=Insert(T,a[i]);
	}
	Preorder(T);
	return 0;
}

AVLTree Insert(AVLTree T,ElemType X) {
	if(T==NULL) {
		T=(AVLTree)malloc(sizeof(AVLNode));
		T->height=0;
		T->data=X;
		T->lchild=T->rchild=NULL;
	} else {
		if(X==T->data) {
			return T;
		} else if(X>T->data) {
			T->rchild=Insert(T->rchild,X);
			if(GetHeight(T->rchild)-GetHeight(T->lchild)==2) {
				if(X>T->rchild->data) {
					T=L_Rotate(T);
				} else {
					T=RL_Rotate(T);
				}
			}
		} else {
			T->lchild=Insert(T->lchild,X);
			if(GetHeight(T->lchild)-GetHeight(T->rchild)==2) {
				if(X<T->lchild->data) {
					T=R_Rotate(T);
				} else {
					T=LR_Rotate(T);
				}
			}
		}
	}
	T->height=Max(GetHeight(T->lchild),GetHeight(T->rchild))+1;
	return T;
}

AVLTree R_Rotate(AVLTree T) {
	AVLTree L=T->lchild;
	T->lchild=L->rchild;
	L->rchild=T;
	T->height=Max(GetHeight(T->lchild),GetHeight(T->rchild))+1;
	L->height=Max(GetHeight(L->lchild),GetHeight(L->rchild))+1;
	return L;
}

AVLTree L_Rotate(AVLTree T) {
	AVLTree R=T->rchild;
	T->rchild=R->lchild;
	R->lchild=T;
	T->height=Max(GetHeight(T->lchild),GetHeight(T->rchild))+1;
	R->height=Max(GetHeight(R->lchild),GetHeight(R->rchild))+1;
	return R;
}

AVLTree LR_Rotate(AVLTree T) {
	T->lchild=L_Rotate(T->lchild);
	return R_Rotate(T);
}

AVLTree RL_Rotate(AVLTree T) {
	T->rchild=R_Rotate(T->rchild);
	return L_Rotate(T);
}

int GetHeight(AVLTree T) {
	if(T==NULL){
		return 0;
	}
	return T->height;
}

void Preorder(AVLTree T) {
	if(T==NULL) {
		return;
	}
	printf("%d",T->data);
	Preorder(T->lchild);
	Preorder(T->rchild);
}

int Max(int a,int b){
	return a>b?a:b;
}
