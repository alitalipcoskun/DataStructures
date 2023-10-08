#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>


struct nodeFB
{
	int id;
	int age;
	struct nodeFB *next;
};

struct nodeGS
{
	int id;
	struct nodeGS *next;
};

struct newNodeFB
{
	int id;
	int age;
	struct newNodeGS *next;
};

struct newNodeGS
{
	int id;
	struct newNodeFB *next;
};

// You must write all the function definitions to be used in this lab into this file. 
// You may also write other functions that may be called from our functions.
// Do not make any changes to the main.c file.
// Upload function.h file to the system as StudentNumber.h.




void insertFB(struct nodeFB **FBtree, int id, int age){
	struct nodeFB *NewNode = (struct nodeFB*) malloc(sizeof(struct nodeFB*));
	struct nodeFB *tempVar;
	NewNode -> id = id;
	NewNode -> age = age;
	NewNode -> next = NULL;
	if(*FBtree == NULL || (*FBtree) -> id >= NewNode -> id){
		tempVar = (*FBtree);
		(*FBtree) = NewNode;
		NewNode -> next = tempVar;
	}
	else{
		struct nodeFB *iterVar;
		iterVar = *FBtree;
		while(iterVar -> next != NULL && iterVar -> next -> id <= NewNode -> id){
			iterVar = iterVar -> next;
		}
		tempVar = iterVar -> next;
		iterVar -> next = NewNode;
		NewNode -> next = tempVar;

	}	
}

void insertGS(struct nodeGS **GStree, int id){
	struct nodeGS *NewNode = (struct nodeGS*) malloc(sizeof(struct nodeGS));
	NewNode -> id = id;
	NewNode -> next = NULL;
	struct nodeGS *tempVar;

	if((*GStree) == NULL || (*GStree) -> id <= NewNode -> id){
		tempVar = (*GStree);
		(*GStree) = NewNode;
		NewNode -> next = tempVar;
	}else{
		struct nodeGS *iterVar;
		iterVar = *GStree;
		while(iterVar -> next != NULL && iterVar-> next -> id >= NewNode -> id){
			iterVar = iterVar -> next;
		}
		tempVar = iterVar -> next;
		iterVar -> next = NewNode;
		NewNode -> next = tempVar;
	}
}


void printFB(struct nodeFB *FBtree){
	struct nodeFB *iterVar;
	iterVar = FBtree;
	while(iterVar != NULL ){
		printf("%d %d\n", iterVar -> id, iterVar -> age);
		iterVar = iterVar -> next;
	}
	printf("\n");
}

void printGS(struct nodeGS* GStree){
	struct nodeGS *iterVar;
	iterVar = GStree;
	while(iterVar != NULL){
		printf("%d\n", iterVar-> id);
		iterVar = iterVar -> next;
	}
	printf("\n");
}

void createFinalList(struct newNodeFB** list, struct nodeFB *FBlist, struct nodeGS* GSlist){
	struct newNodeFB* FBnode;
	struct newNodeGS* GSnode;
	struct nodeFB* FBIterVar;
	struct nodeGS* GSIterVar;

	struct newNodeFB* FBHolder;
	struct newNodeGS* GSHolder;


	struct newNodeFB* listIterVar;
	
	FBIterVar = FBlist;
	GSIterVar = GSlist;

	if(*list == NULL){
		FBnode = (struct newNodeFB*)malloc(sizeof(struct newNodeFB*));
		GSnode = (struct newNodeGS*)malloc(sizeof(struct newNodeGS*));
		FBnode -> id = FBlist -> id;
		FBnode -> age = FBlist -> age;
		GSnode -> id = GSlist -> id;

		FBnode -> next = GSnode;
		FBIterVar = FBIterVar -> next;
		GSIterVar = GSIterVar -> next;

		FBHolder = FBnode;
		GSHolder = GSnode;
		(*list) = FBnode;
		listIterVar = FBnode;
	}

	while(FBIterVar != NULL){
		FBnode = (struct newNodeFB*)malloc(sizeof(struct newNodeFB*));
		GSnode = (struct newNodeGS*)malloc(sizeof(struct newNodeGS*));
		FBnode -> id = FBIterVar -> id;
		FBnode -> age = FBIterVar -> age;
		GSnode -> id = GSIterVar -> id;
		FBnode -> next = GSnode;
		listIterVar -> next -> next = FBnode;
		FBIterVar = FBIterVar -> next;
		GSIterVar = GSIterVar -> next;
		listIterVar = listIterVar -> next -> next;
	}
}	

void printAll(struct newNodeFB* list){
	struct newNodeFB* iterVar;
	iterVar = list;
	while(iterVar != NULL){
		printf("%d %d\n", iterVar ->id, iterVar -> age);
		printf("%d\n", iterVar -> next -> id);
		iterVar = iterVar -> next -> next;
	}
}