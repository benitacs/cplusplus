//
//  main.cpp
//  BinaryTree
//
//  Created by Benita Alexander on 2/8/23.
//

#include <iostream>
using namespace std;

struct Node{
    int data;
    Node* left;
    Node* right;
};

Node* createNode(int data){
    Node* newNode = new Node();
    newNode->data = data;
    newNode->left= newNode->right=nullptr;
    return newNode;
}

// Pre-Order Traversal
void printPreOrderTree(Node* root){
    if(root == nullptr) return;
    cout<<root->data<<endl;
    printPreOrderTree(root->left);
    printPreOrderTree(root->right);
}//Output -> 1,2,4,5,9,3,6,7,15

//In-Order Traversal
void printInOrderTree(Node* root){
    if(root == nullptr) return;
    
    printInOrderTree(root->left);
    cout<<root->data<<endl;
    printInOrderTree(root->right);
}//Output -> 4,2,9,5,1,6,3,15,7

//In-Order Traversal
void printPostOrderTree(Node* root){
    if(root == nullptr) return;
    
    printPostOrderTree(root->left);
    printPostOrderTree(root->right);
    cout<<root->data<<endl;
}

int main(int argc, const char * argv[]) {
    // insert code here...
    
    Node* root=createNode(1);
    
    root->left=createNode(2);
    root->right=createNode(3);
    
    root->left->left=createNode(4);
    root->left->right=createNode(5);
    root->right->left=createNode(6);
    root->right->right=createNode(7);
    
    root->left->right->left=createNode(9);
    root->right->right->left=createNode(15);
    
    printPreOrderTree(root);
    cout<<endl<<"----------------\n";
    printInOrderTree(root);
    cout<<endl<<"----------------\n";
    printPostOrderTree(root);
    cout<<endl<<"----------------\n";
    return 0;
}
