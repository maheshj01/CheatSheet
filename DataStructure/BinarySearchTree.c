#include<stdio.h>
#include<stdlib.h>

struct Node{
	int data;
	struct Node * left;
	struct Node * right;
};

struct Node * root = NULL;

struct Node * createNode(int x){
	struct Node * newNode = malloc(sizeof(struct Node));
	newNode->data = x;
	newNode->left = NULL;
	newNode->right = NULL;
	return newNode;
} 
	
struct Node * insert(struct Node * startnode,int x){
	if(startnode==NULL){/*if tree is empty*/
		 return createNode(x);
	}
	else{
		if(x <= startnode->data){
			struct Node *newlyAddedNode= insert(startnode->left,x);
			startnode->left = newlyAddedNode;
			return startnode;
		}else{
			struct Node *newlyAddedNode = insert(startnode->right,x);
			startnode->right = newlyAddedNode;
			return startnode;
		}
	}
}

/*LEFT ROOT RIGHT Traversal*/
void inorderTraversal(struct Node * start){
	if(start == NULL)return;
	inorderTraversal(start->left);
	printf("%d ",start->data);
	inorderTraversal(start->right);
}

void preOrderTraversal(struct Node *start){
	if(start == NULL) return;
	printf("%d ",start->data);
	preOrderTraversal(start->left);
	preOrderTraversal(start->right);
}

void postOrderTraversal(struct Node *start){
	if(start == NULL) return;
	preOrderTraversal(start->left);
	preOrderTraversal(start->right);
	printf("%d ",start->data);
}

void deleteNode(struct Node * start,int x){
	if(start->data == x){
		if(start->left == NULL && start->right == NULL)
		return;
	}
	if(x < start->data){
		deleteNode(start->left,x);
		start->left = NULL;
	}else{ /*x > start->data*/
		deleteNode(start->right,x);
		start->right = NULL;
	}
}

int main(){
	int n;
	while(n!=0){
		printf("\nenter operation: \n0. EXIT\n1. Insert\n2. Delete\n3. Traverse Inorder\n4. Traverse PreOrder\n5. Traverse PostOrder");
		scanf("%d",&n);
		if(n==0){
			break;
		}
		else if(n==1){
			printf("\nInsert what? ");
			int x;
			scanf("%d",&x);
			root = insert(root,x);
		}
		else if(n==2){
			printf("what do you want to delete \n");
			int x;
			scanf("%d",&x);
			deleteNode(root,x);
		}
		else if(n==3){
			inorderTraversal(root);
		}
		else if(n==4){
			preOrderTraversal(root);
		}
		else if(n==5){
			postOrderTraversal(root);
		}
		else{
			printf("Invalid operation\n");
		}	
	}
	return 0;
}