#include <bits/stdc++.h>
using namespace std;

void insert(int arr[],int size,int data){
    int temp=data ;
    int idx = temp % size;
    if (arr [idx] == -1){
        arr[idx] = data;
    }
    else{
        int cnt = 1;
        
        while(arr[idx] != -1 && cnt < size){
            temp++; 
            idx = temp % size;
            cnt ++;
        }
        if (arr[idx]== -1){
            arr[idx] = data;
        }
        else{
            cout<<"Table is full..";
        }
    }

}
void search(int arr[],int size,int data){
    int temp=data;
    int idx = temp % size;
    if (arr [idx] == data){
       cout<<data <<"  is present.."<<endl;
    }
    else{
        int cnt = 1;
        
        while(arr[idx] != data && cnt < size){
            temp++;
            idx = temp % size;
            cnt ++;
        }
        if (arr[idx] == data){
            cout<<data <<" is present"<<endl;
        }
        else{
            cout<<data<<"  not present.."<<endl;
        }
    }

}
void del(int arr[],int size,int data){
    int temp=data;
    int idx = temp % size;
    if (arr [idx] == data){
       cout<<data <<"  is deleted.."<<endl;
       arr[idx] = -1;
    }
    else{
        int cnt = 1;
        
        while(arr[idx] != data && cnt < size){
            temp++;
            idx = temp % size;
            cnt ++;
        }
        if (arr[idx] == data){
            cout<<data <<" is deleted"<<endl;
            arr[idx] = -1;
        }
        else{
            cout<<data<<"  not present.."<<endl;
        }
    }

}
void display(int arr[],int size){
    for (int i = 0; i < size; i++){
        cout<<arr[i]<<"   ";
    }
}

int main (){
    int arr[10];
    for (int i = 0; i < 10; i++){
        arr[i] = -1;
    }
    int choice;
    do
    {
    cout<<"Enter  : "<<endl;
    cout<<"1. insert a key   2. search a key  "  <<endl;
    cout<<"3.  delete key    4. display table "<<endl;
    cout<<"5. Exit"<<endl;
    cin>>choice;
    int x;
    switch (choice)
    {
    case 1:
        cout<<"Enter element to insert : ";
        cin>>x;
        insert(arr,10,x);
        break;
    case 2:
        cout<<"Enter element to search : ";
        cin>>x;
        search(arr,10,x);
        break;
    case 3:
        cout<<"Enter element to delete : ";
        cin>>x;
        del(arr,10,x);
        break;
    case 4:
        display(arr,10);
        break;
    
    default:
        break;
    }
     } while (choice != 5);
} 
 