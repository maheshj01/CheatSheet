#include<stdio.h>
#include<stdlib.h>
struct node
{
	int data;
	struct node *link; /*node *link in c++*/
};
struct node *start=NULL;

void InsertNodeAtEnd(int x){
 struct node *temp = (struct node *)malloc(sizeof(struct node)); /*dynamically created node that is to be added to list*/
 temp->data = x;
 temp->link = NULL;
/* Now to connect above node to linked list there may be two cases*/
 if(start == NULL){ 	/*there may not be any node in the list i.e list is empty*/
 	start = temp; /* directly store new nodes address in start/head of list*/
 }
 else{ /*if start points to some other node i.e linked list already contains some nodes*/
 	struct node *temp1 = start; /*save the start headress in a temporary variable*/
 	while(temp1->link != NULL){ /*traverse the list until last node using the temporary variable*/
 		temp1 = temp1->link;
 	}
 	/*when temporary variable points to last node*/
 	temp1->link =temp; /*store new nodes address in this last node*/ 	
 }
}

/*struct node * createNode(){
 struct node *newnode = (struct node *)malloc(sizeof(struct node));
 return newnode;
}*/

void InsertNodeAtFront(int x){
	if(start != NULL){
	struct node * tempAddress = start; /*store start address in temporary variable*/
	struct node * newnode = malloc(sizeof(struct node)); /*create a node*/
	newnode->data = x; /*add data in new node*/
	start = newnode; /* store new nodes address in start*/
	newnode->link = tempAddress; /*add old start address in new nodes link*/
	}else{
		InsertNodeAtEnd(x);
	}
}

void displayList(){
	struct node *temp2 = start; /*store starting address in a temporary variable*/
	printf("\nList: ");
	while(temp2!=NULL){		/*traverse while end of list using temporary variable*/
		printf("%d ",temp2->data); 
		temp2 = temp2->link;
	} 
}

/* Needs a Fix */
void InsertAfter(int index , int x){
	int counter = 0;
	struct node *newnodeAddress  = malloc(sizeof(struct node));
	struct node *tempaddress = start;
	newnodeAddress->data = x;
	while(counter < index){
		/*if(tempaddress->link==NULL){
			InsertNodeAtEnd(x);
			goto c;
		}*/
		tempaddress = tempaddress->link;
	}
	struct node * ZplusindexAddress = tempaddress;
	tempaddress->link = newnodeAddress;
	newnodeAddress->link = ZplusindexAddress;
	displayList();
	/*c:;*/
}

void deleteFront(){
	struct node * startAddress = start;
	if(startAddress!=NULL){
		start = startAddress->link;
	}
	else{
		printf("\nLIST IS EMPTY NOTHING TO DELETE\n");
	}
}

void deleteEnd(){
	struct node *startAddress = start;
	struct node * temp;
	while(startAddress->link!=NULL){
		temp = startAddress;
		startAddress = startAddress->link;
	}
	temp->link=NULL;
}

int main(/*int argc, char const *argv[]*/)
{

	int n=100;
	while(n!=0){
	printf("\n1. Insert into List");
	printf("\n2. Insert at front");
	printf("\n3.Insert after node");
	printf("\n4. Delete Front");
	printf("\n5. Delete End");
	printf("\n0. EXIT");
	printf("\nenter your Operation on Linked List:");
	scanf("%d",&n);
	if(n==1){
		int x;
		printf("\nInsert What? \n");
		scanf("%d",&x);
		InsertNodeAtEnd(x);
		displayList();
	}
	else if(n==2){
		int x;
		printf("\nInsert What at front? \n");
		scanf("%d",&x);
		InsertNodeAtFront(x);
		displayList();
	}
	else if(n==3){ /*needs a fix*/
		int x;
		printf("insert after node position e.g 2\n");
		int z;
		scanf("%d",&z);
		printf("insert what? ");
		scanf("%d \n",&x);
		InsertAfter(z,x); /* insert x after zth node*/ 
	}
	else if(n==4){
		deleteFront();
		displayList();
	}
	else if(n==5){
		deleteEnd();
		displayList();
	}
	else{
		printf("Invalid Operation entered\n");
	}
	}
	return 0;
}