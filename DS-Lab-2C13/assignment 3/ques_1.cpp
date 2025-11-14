#include<iostream>
using namespace std;
int main(){
    int n, choice;
    cout<<"Enter size of stack ";
    cin>> n;
    int STACK[n];
    int top = -1;
    do{
    cout<<"MENU: ENTER - 1. PUSH()\n 2. POP()\n 3.isEMPTY() \n 4.ISFULL()\n 5.DISPLAY() \n 6.PEEK() \n";
    cin>> choice;
    if(choice==1){
        if(top == n-1){
            cout<<"OVERFRLOW!";
        }
        else{
            int value;
            cout<<"enter value ";
            cin>>value;
            top++;
            STACK[top] = value;
            
        }
    }
    if(choice==2){
        if(top == -1){
            cout<<"UNDERFLOW!";
        }
        else{
           top--;
            
        }
    }
    if(choice==3){
        if(top == -1){
            cout<<"stack is empty!";
        }
        else{
           
            cout<<"stack not empty ";
            
        }
    }
    if(choice==4){
        if(top == n-1){
            cout<<"stack is full!";
        }
        else{
            
            cout<<"stack not full  ";
            
        }
    }
    if(choice==5){
      for(int i=top;i>=0;i--){
        cout<<STACK[i]<<endl;
      }
    }
    if(choice==6){
        if(top != -1){
     cout<<STACK[top];
    }
    else{
     cout<<"stack is empty";
    }
    }
    if(choice == 7) {
            cout << "Exiting program.\n";
        }
} while (choice!=7);
   return 0;
}