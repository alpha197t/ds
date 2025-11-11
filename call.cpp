#include<bits/stdc++.h>
using namespace std;

# define size 100

struct call{
    int  ID;
    int calltime;
};

call arr[size];
int front=-1;
int rear=-1;

void add(int ID,int calltime){
    if(rear==size-1){
        cout<<"queue is overload "<<endl;
    }

    if(front==-1){
        front=0;
    }
    rear++;
    arr[rear].ID=ID;
    arr[rear].calltime=calltime;
    
    cout<<"call added-ID "<<ID<<endl;
    cout<<"call time "<<calltime<<endl;

}
void answer(){
    if(front==-1 && front>rear){
        cout<<"no call can add"<<endl;
    }

    cout<<"answer call ID "<<arr[front].ID<<endl;
    cout<<"answer call time"<<arr[front].calltime<<endl;

    front++;
    if(front>rear){
        front=rear=-1;
    }
}
void display(){
    for (int i = front; i <= rear; i++)
    {
     cout<<" pending call ID "<<arr[i].ID<<endl;
    cout<<" pending call time"<<arr[i].calltime<<endl;

    }
    
}
int main(){
    int choice,id, time;

    while(true){
        cout<<"1.add call"<<endl;     
        cout<<"2.answer call"<<endl;       
        cout<<"3.view call"<<endl;
        cout<<"enter a choice"<<endl;
        cin>>choice;

        switch (choice)
        {
        case 1:
            cout<<"enter id"<<endl;
            cin>>id;
            cout<<"enter time"<<endl;
            cin>>time;
            add(id,time);
            break;

        case 2:
            answer();
            break;

        case 3:
            display();
            break;
            
        default:
            break;
        }
    }
}
