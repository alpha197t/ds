#include<iostream>
using namespace std;

class Stk{
    private:
    int top;
    string arr[100];

    public:
        Stk(){
            top = -1;
        }

        void insert(string x){
            if (top == 99){
                cout<<"Stack is full.."<<endl;
                return;
            }
            arr[++top] = x;
        }
    

        string tp(){
            if (top == -1){
                cout<<"empty.."<<endl;
                return '\0';
            }
            return arr[top];
        }

        void pop(){
            if (top == -1){
                cout<<"empty.."<<endl;
                return;
            }
            -- top;
        }
        void clear(){
            top = -1;
        }
        bool empty(){
            if (top == -1){
                return true;
            }
            return false;
        }
        void dis(){
            if (top == -1){
                cout<<"empty.."<<endl;
                return;
            }
            for(int i = top; i >= 0; i--){
                cout<<arr[i]<<"    ";
            }
            cout<<endl;
        }

};

class Event{
    private:
        Stk undo;
        Stk redo;
        string docu;

    public:
        Event(){
            docu = "";
        }
        void makechange(string s){  
            undo.insert(docu);
            docu = s;
            redo.clear();
            cout<<"change done "<<endl;
          
        }
        void ud(){
            if(!undo.empty()){
                redo.insert(docu);
                docu = undo.tp();
                undo.pop();
                cout<<"Undo done..."<<endl;
            }
        }
        void rd(){
            if(!redo.empty()){
                undo.insert(docu);
                docu = redo.tp();
                redo.pop();
                cout<<"redo done.."<<endl;
            }
        }
        void display(){
            cout << "Document: " << docu << "\n";
            undo.dis();
            redo.dis();
        }

};

int main(){
    Event e;
  
    int choice;
    string y;
    do{
        cout<<"Enter :  1. make change    2.Undo     3.Redo    4.Display   5.Exit ";
        cin>>choice;
        switch(choice){
            case 1: 
                cout<<"Enter change : ";
                cin>>y;
                e.makechange(y);
                break;
            case 2:
                e.ud();
                break;
            case 3:
                e.rd();
                break;
            case 4:
                e.display();
                break;
            default:
                cout<<"Existing..."<<endl;
        }

    }while(choice != 5);

}
