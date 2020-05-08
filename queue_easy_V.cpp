#include<bits/stdc++.h>

using namespace std;

class Queue{
public:
int Front ,Rear,size_,*arr;
    //constractor to init the queue
  Queue(int size_){
        Front=Rear=-1;
        this->size_=size_;
        arr=new int[size_];
    }
    //push the element in queue
    void push(int data){

    if(Rear==size_-1){ cout<<"Queue is Empty"; return; }

    Front==-1?Front=0:Front;
    arr[++Rear]=data;

    }
    //remove the X from star (front)
    int pop(){
        if(Front==-1 || Front>Rear){cout<<"queue is empty"; return -1; }

    return arr[Front++];
    }
//show the queue
void display(){  for(int i=Front;i<=Rear;cout<<arr[i++]<<' ');  /*call fun to print is empty*/  if(Front>Rear){pop();}  }
//size the queue
int len(){ return Front>Rear?Front-Rear-1:Rear-Front+1;}
//chek is empty
bool isempty(){ return Front==-1 || Front>Rear? true:false;}
//check is full
bool isfull(){ return Front==0 && Rear==size_-1?true:false;}
//value of Front
int Front_Value(){ return  Front>Rear?-1:arr[Front];}
//value of Rear
int Rear_Value(){return arr[Rear];}
//clear the queue
void clear_(){ arr=new int [size_];}

};

int main(){
Queue Q(//queue size);
return 0;
}

