#include<bits/stdc++.h>
using namespace std;

struct node{

int data;
struct node * nex;

};

struct queue_{

struct node *front_, *Rear_;

};

class main_queue{

public:
    queue_ *q;
    int size_;
    main_queue(){
    this->size_=0;
    q=new queue_;
    q->front_=q->Rear_=NULL;

    }

    void push (int x){

    this->size_++;
    struct node *now=new node;

    now->data=x;

    if(q->front_==NULL){ q->front_=now;}

    else
        q->Rear_->nex=now;

    q->Rear_=now;
    q->Rear_->nex=q->front_;

    }

int pop(){

    if(q->front_==NULL){ cout<<"queue is empty\n";  return -1;}

    else if(q->front_==q->Rear_){

        int data=q->front_->data;
        free(q->front_);
        q->front_=q->Rear_=NULL;
    this->size_--;
    return data;
    }

    else{

        int date;
        date=q->front_->data;
        q->front_=q->front_->nex;
        q->Rear_->nex=q->front_;
        this->size_--;
    return date;
    }


}

void display(){

    if(q->front_==q->Rear_ && q->front_==NULL){cout<<"Queue is empty\n";}

 else{

    struct queue_ *print= new queue_;
   print=q;  //because don`t change the pointer of orginal front
    while(1){

        cout<<print->front_->data<<' ';
        print->front_=print->front_->nex;

      if(print->Rear_->nex==print->front_)
                                break;
    }

free(print);
 }
}


int len(){return size_;}


};


int main()
{

main_queue q;

//using function


	return 0;
}

