/*Binary Serach Tree Implementation
*with Serach and Insert method 
*/
#include <iostream>
using namespace std;
struct Node{
int data;
Node* left;
Node* right;
};

Node* generateNode(int data){
    Node* newNode = new Node();
    newNode->data= data;
    newNode->left=newNode->right=NULL;
    return newNode;
}

Node* Insert(Node* root,int data){

    if(root==NULL){
        root = generateNode(data);
    }else if(data<= root->data){
        root->left = Insert(root->left,data);
    }else{
        root->right = Insert(root->right,data);
    }
    return root;
}

bool search(Node* root,int data){
    if(root==NULL) return false;
    else if(data == root->data) return true;
    else if(data <= root->data)return search(root->left,data);
    else return search(root->right,data);
}


int main() {
    Node* root = NULL;
    root = Insert(root, 10);
    root = Insert(root, 9);
    root = Insert(root, 11);
    //cout<<root->left->data; //Print the value of left Node data
    int value;
    cout<<"Search a value:";
    cin>>value;

    cout<<"\nsearch For "<<value<<":"<<search(root,value);
   return 0;
}

