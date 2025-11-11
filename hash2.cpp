#include<bits/stdc++.h>
using namespace std;

struct Node{
    int key;
    Node* next;

    Node(int k){
        key = k;
        next = NULL;
    }
};

class Hash{
    private:
        Node* arr[10];
    public:
        Hash(){
            for(int i = 0; i < 10; i++){
                arr[i] = new Node(i+1);
            }
        }

        void insert(int k){
            int idx = k % 10;
            Node* temp = arr[idx];
            Node* newNode = new Node(k);
            while(temp->next != NULL){
                temp = temp->next;
            }
            temp->next = newNode;
            cout<<k<<" Inserted..."<<endl;
        }
        void display(){
            for(int i = 0; i < 10; i++){
                Node* temp = arr[i];
                while(temp!= NULL){
                    cout<<temp->key<<" -> ";
                    temp = temp->next;
                }
                cout<<endl;
            }
        }
        void search(int el){
            int idx = el % 10;
            Node* temp = arr[idx];
            temp = temp->next;
            while(temp!= NULL){
                if(temp->key == el){
                    cout<<el<<" Found..."<<endl;
                    return;
                }
                temp = temp->next;
            }
            cout<<el<<" Not found..."<<endl;
        }
        void del(int el){
            int idx = el%10;
            Node* temp = arr[idx];
            Node* prev = NULL;
            while(temp != NULL && temp->key != el){
                prev = temp;
                temp = temp->next;
            }
            if(temp == NULL){
                cout<<el<<" not found..."<<endl;
                return;
            }
            if (temp->key == el){
                prev->next = temp->next;
                delete temp;
                cout<<el<<" deleted.."<<endl;
            }
        }
};

int main(){
    Hash h;
    h.insert(55);
    h.insert(95);
    h.insert(25);
    h.insert(11);
    h.insert(28);
    h.insert(10);
    cout<<endl;

    h.display();
    cout<<endl;

    h.search(25);
    h.search(28);
    h.search(42);
    h.search(3);
    cout<<endl;

    h.del(25);
    h.del(28);
    cout<<endl;

    h.display();
}
