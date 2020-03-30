#include<stdio.h>
#include<stdlib.h>
#define MaxSize 12
#define ElemType int
#define MaxData 10000

typedef struct node{
	ElemType *data;
	int size;
	int capcity;
}HeapNode; 
typedef struct node *Heap;

typedef Heap MaxHeap;
typedef Heap MinHeap;

MaxHeap Create(){
	MaxHeap H=(MaxHeap)malloc(sizeof(HeapNode));
	H->data=(ElemType *)malloc((MaxSize+1)*sizeof(ElemType));
	H->size=0;
	H->capcity=MaxSize;
	H->data[0]=MaxData; 
	return H; 
}

bool IsFull(MaxHeap H){
	if(H->size==H->capcity){
		return true;
	}
	return false;
}

bool IsEmpty(MaxHeap H){
	if(H->size==0){
		return true;
	}
	return false;
}

bool Insert(MaxHeap H,ElemType X){
	if(IsFull(H)){
		return false;
	}
	int i=++H->size;
	while(H->data[i/2]<X){
		H->data[i]=H->data[i/2];
		i/=2;
	}
	H->data[i]=X;
	return true;
}

ElemType Delete(MaxHeap H){
	if(IsEmpty(H)){
		return -1;
	}
	int MaxItem=H->data[1];
	int temp=H->data[H->size--];
	int parent=1;
	while(parent*2<=H->size){
		int child=parent*2;
		if((child!=H->size)&&(H->data[child]<H->data[child+1])){
			child++;
		}
		if(temp>H->data[child]) break;
		else{
			H->data[parent]=H->data[child];
			parent=child;
		}
	}
	H->data[parent]=temp;
	return MaxItem;
}

void PercDown(MaxHeap H,int index){
	int parent=index;
	int child;
	int temp=H->data[index];
	while(parent*2<=H->size){
		child=parent*2;
		if((child!=H->size)&&(H->data[child]<H->data[child+1])){
			child++;
		}
		if(temp>H->data[child]) break;
		else {
			H->data[parent]=H->data[child];
			parent=child;
		}
	}
	H->data[parent]=temp;
}

void BuildHeap(MaxHeap H){
	for(int i=H->size/2;i>=1;i--){
		PercDown(H,i);
	}
}

void print(MaxHeap H){
	for(int i=1;i<=H->size;i++){
		printf("%d ",H->data[i]);
	}
}

int main(){
	MaxHeap H=Create();
	int a[]={13,27,50,49,76,65,97};
	for(int i=0;i<7;i++){
		H->data[++H->size]=a[i];
	} 
	BuildHeap(H);
	print(H);
	if(Insert(H,83)){
		print(H);
	}
	int t=Delete(H);
	printf("%d\n",t);
	print(H);
}


