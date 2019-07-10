/*
Note: printing List in reverse a.nd rversing the List is different under the hood
	  when looked at memory level This explained through this program;

# Contents

1. generates a linked list from elements of array
2. add element to List at End 
3. prints reverse list using Recursion :
4. Reversed the linked  by using Iterative method
5. Reverse the Linked list by Recusrion
*/
#include<stdio.h>
#include<stdlib.h>

struct Node{
	int data;
	struct Node *next;
};
struct Node * head = NULL;

struct Node *createNode(){
	struct Node *temp = malloc(sizeof(struct Node));
	return temp; 
}

/*Inserts element x into List at End of List */
void insert(int x){
	if(head==NULL){
		struct Node * newNode = createNode();
		newNode->data = x;
		newNode->next = NULL;
		head = newNode;
	}else{
		struct Node * temp = head; 
		while(temp->next != NULL){
			temp = temp->next;
		}
		struct Node * newNode = createNode();
		newNode->data = x;
		newNode->next = NULL;
		temp->next = newNode;
	}
}

/*To traverse list from the given head Node*/
void showList(struct Node * start){
	struct Node * temp = start;
	while(temp!= NULL){
		printf("%d ",temp->data);
		temp = temp->next;
	}
}

/*prints list in reverse by using Recursion*/
void printreverseListByRecursion(struct Node *nextnode){
	if(nextnode->next!=NULL){
		printreverseListByRecursion(nextnode->next);
	}
	printf("%d ",nextnode->data);
}

struct Node * newhead;
/*This Method reverses the List By using Recursion*/
void reverseListByRecursion(struct Node *currentnode,struct Node *prev){
	if(currentnode->next != NULL){
		reverseListByRecursion(currentnode->next,currentnode);
	}
	/*storing NULL (in the next part) of first Node of this list because it will be last node of our reverse list*/
	if(prev == head){
			prev->next = NULL; /*if first Node put next part to NULL*/
		}
	/*storing the newhead of reverse list */	
	if(currentnode->next == NULL && prev != NULL){ /*this is first Node of new reversed List*/
		newhead = currentnode;
	}
	/* connecting prev pointers to reverse the list */
		currentnode->next = prev;
}
/*reverses the List by Iterative Method*/
void reverseTheListByIteration(){
struct Node *prev = NULL;
struct Node *nexttempaddress;
struct Node *current = head; //store head address in a var for iterating
while(current != NULL){
	if(head == current){ /*if it is first Node*/
		nexttempaddress = current->next;
		current->next = NULL;
		prev = current;
		current = nexttempaddress;
	}else{ /*if not first Node*/
		nexttempaddress = current->next;
		current->next = prev;
		prev = current;
		current = nexttempaddress;
	}
}
head = prev; // after reaching last Node head will point to the last Node;
}


int main(){

	int arr[]={41,3,5,6,5,76,89,456,34,3};
	for(int i=0;i<sizeof(arr)/4;i++){
		insert(arr[i]);
	}
	printf("\nlist from array is: ");
	showList(head);
	printf("\n printing reverse list using Recursion :\n");
	printreverseListByRecursion(head);
	printf("\nReversed the linked  by using Iterative method:");
	reverseTheListByIteration();
	showList(head);
	printf("\nReversed the linked by using Recursion method:");	
	reverseListByRecursion(head,NULL);
	printf("\n new head points to %d \n",newhead->data);
	showList(newhead);
}


/*
# Output

list from array is: 41 3 5 6 5 76 89 456 34 3
 printing reverse list using Recursion :
3 34 456 89 76 5 6 5 3 41
Reversed the linked  by using Iterative method:3 34 456 89 76 5 6 5 3 41
 new head points to 41
41 3 5 6 5 76 89 456 34 3
*/