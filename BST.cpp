#include<iostream>
using namespace std;

struct Node{
    int key;
    Node* left;
    Node* right;
    Node(int k){
        key = k;
        left = NULL;
        right = NULL;
    }
};

Node* insert(Node* root,int key){
    if (root == NULL){
        Node* newNode = new Node(key);
        return newNode;
    }
    else if(key < root->key){
        root->left = insert(root->left,key);
    }
    else{
        root->right = insert(root->right,key);
    }
    return root;
}
void display(Node* root){
    if (root == NULL){
        return;
    }
    display(root->left);
    cout<<root->key<<"    ";
    display(root->right);
}
void search(Node* root,int key){
    if(root == NULL){
        return;
    }
    if(root->key == key){
        cout<<key<<"  found..."<<endl;
        return;
    }
    else if(key < root->key){
        search(root->left,key);
    }
    else{   
        search(root->right,key);
    }
}
Node* del(Node* root,int key){
    if (root == NULL){
        cout<<"element not found...";
        return root;
    }
    else if (key < root->key){
        root->left = del(root->left,key);
    }
    else if (key > root->key){
        root->right = del(root->right,key);
    }
    else{
        if(root->left == NULL && root->right == NULL){
            delete root;
            root = NULL;
        }
        else if(root->right == NULL){
            Node* temp = root;
            root = root->left;
            delete temp;
        }
        else if(root->left == NULL){
            Node* temp = root;
            root = root->right;
            delete temp;
        }
        cout<<key<<" is deletedd..."<<endl;
    }
    return root;
}


int main(){
    Node* root = NULL;
    int x;
    int choice;
    do{
        cout<<"enter : 1.insert  2.delete  3.search  4.display  5.Exit : ";
        cin>>choice;

        switch(choice){
            case 1:
                cout<<"Enter element : ";
                cin>>x;
                root = insert(root,x);
                break;
            case 2:
                cout<<"Enter element : ";
                cin>>x;
                root = del(root,x);
                break;
            case 3:
                cout<<"Enter element : ";
                cin>>x;
                search(root,x);
                break;
            case 4:
                display(root);
                cout<<endl;
                break;
            default:
                cout<<"existing...";
                break;
        }

    }while(choice!=5);
}
