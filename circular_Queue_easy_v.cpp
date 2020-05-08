#include<bits/stdc++.h>
using namespace std;

class Circular_Queue
{
public:
   int Front,Rear,size_,*arr;    //First-> First Indicator indicates the first elment(remove), Rear-> Indicator indicates the last elment(add)

  Circular_Queue(int size_){   //constrain to initialization class with size


   	this->size_=size_;

   	arr=new int[this->size_];  //init arr with size_

   	Front=Rear=-1;  //no element add

   }

void push(int X){

	if((Front==0 &&Rear==size_-1) || Rear==Front-1 ){    //naive case || circle case

      cout<<"Queue is Full\n";
      return ;

	}


	else if(Front==Rear && Front==-1){   //first case add 1st elemnt

		Front=Rear=0;
		arr[Rear]=X;

	}
	else if(Rear==size_-1 && Front!=0){  //case filled value in Rear and There are places in 1st again
	 arr[Rear=0]=X;
	}

	else{
		arr[++Rear]=X;
	}


}

int pop(){

if(Rear==Front && Front==-1){ cout<<"Queue is Empty\n"; return -1;} //Original case

int ans=arr[Front];

arr[Front]=-1; //flag the value

 if(Front==Rear){ Front=Rear=-1;} // case the Empty arr


else if(Front==size_-1){ Front=0; } //cass fulled Front and Front!=Rear star from 0 again
else
	Front++;


return ans;
}


void display(){
		//show arr with diffrent case

if(Front==-1){ cout<<"Queue is Empty\n"; return ;}

else if( Rear>=Front){ for(int i=Front ;i<=Rear;i++){cout<<arr[i]<<' ';}}
else {


	for (int i = Front; i < size_; i++)
	{
		cout<<arr[i]<<' ';
	}

for(int i=0;i<=Rear;i++){cout<<arr[i]<<' ';}
}

}


int len(){  return (Rear==Front && Front==-1)?0:(size_-Front)+(Rear+1) ;} //len with two case len



};



int main()
{
	Circular_Queue cq(5);
	
	
	return 0;
}
