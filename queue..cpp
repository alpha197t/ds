#include<bits/stdc++.h>
using namespace std;

int front=-1;
int rear=-1;

void insert(string arr[],int size,string event){
    if(rear==size-1){
        cout<<"queue is overflow"<<endl;
    }

    if(front==-1){
        front=0;
    }

    rear++;
    arr[rear]=event;
    cout<<"add  event "<<event<<endl;
}

void process(string arr[])  {
    if(front==-1  && front>rear){
        cout<<"no event can process"<<endl;
    }
    
    cout<<"process event "<<arr[front]<<endl;
    front++;
    
    if(front>rear){
    front= rear=-1;
    }
    
}
void display(string arr[],int size){
    for(int i=0;i<size;i++){
        cout<<arr[i]<<" "<<endl;
    }
}
int main(){
    int size;
    cout<<"max no of event"<<endl;
    cin>>size;
    string arr[size];
    int choice;
    string event;

    do
    {
       cout << "1. Add event" << endl;
        cout << "2. Process event" << endl;
        cout << "3. Display pending events" << endl;
        cout << "Enter your choice: ";
        cin >> choice; 
        switch(choice){
            
            case 1:
                cout << "Enter event name (single word): ";
                cin >> event;   
                insert(arr, size, event);
                break;

            case 2:
                process(arr);
                break;

            case 3:
                display(arr, size);
                break;

        }


    } while (choice!=3);
    return 0;
}