#include<bits/stdc++.h>
using namespace std;

struct Node{
    int key;
    Node*left;
    Node*right;

    Node(int k){
    key =k;
    left=right=NULL;
}
    
};
Node*insert(Node*root,int key){
    if(root==NULL){
        Node* newnode= new Node(key);
        return newnode;
    }
    else if(key<root->key){
        root->left=insert(root->left,key);
    }
    else{
         root->right=insert(root->right,key);
    }
    
}

void search(Node*root,int key){
    if(root==NULL){
        return  ;
    }
    else if(root->key==key){
        cout<<key<< "found "<<endl;
        return ;

    }
    else if(key<root->key){
        search(root->left,key);
        
    }
    else{
        search(root->right,key);

  
    }
}

void display (Node*root){
    if(root==NULL){
        return ;
    }
    display(root->left);
    cout<<root->key<<" ";
    display(root->right);

}
int main(){
      Node*root=NULL;
      root=insert(root,11);
      root=insert(root,22);

      display(root );
    search(root,11);

}