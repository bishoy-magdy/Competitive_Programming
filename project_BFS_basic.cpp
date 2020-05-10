#include<bits/stdc++.h>
using namespace std;


int n,m;    //the width and height of grid

char grid[1000][1000]; //the grid 

bool vis[1000][1000]; //make bool arr[][] because the point so that it does not enter again

int dis[1000][1000]; //the number of steps for every point from star

int dx[8]={1,-1,0,0,1,1,-1,-1};  //increase or decrease dx for every direction

int dy[8]={0,0,-1,1,1,-1,1,-1}; //increase or decrease dy for every direction

bool check (int x,int y){ return x>=0 && x<=n-1 && y>=0 && y<=m-1; }  //check the new point valid in grid
  
  ///////////////queue using linked list/////////////////////////////
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
    main_queue(){   //constractor to init queue with Null star point
    q=new queue_;
    q->front_=q->Rear_=NULL;

    }
    void push (int x){

    struct node *now=new node;   //make new block
    now->data=x; //strore the data in new block
    if(q->front_==NULL){ q->front_=now;}   //check it is the first push or not

    else
        q->Rear_->nex=now; //if more element in the queue

    q->Rear_=now;   //update the rear and move the next
    }

int pop(){

    if(q->front_==NULL){ return -1;}  //empty return -1 ->flag !

    else if(q->front_==q->Rear_){   //one element in the queue

        int data=q->front_->data;   //take data
        free(q->front_); //remove 
        q->front_=q->Rear_=NULL;   //finish wuth null

    return data;
    }

    else{   //more than element
    int data=q->front_->data; //take data
     q->front_=q->front_->nex; //move the front

   return data;
    }


}
//check the queue empty or not
bool empty_(){  if(q->front_==NULL){ return true;}  return false; }

};


//return short step to end point E

int BFS(int s_x,int s_y){


main_queue q_x,q_y;  //two class one to x-axs for point in grid and anther y-axs 

q_x.push(s_x);

q_y.push(s_y);

dis[s_x][s_y]=0;   //first step =0

vis[s_x][s_y]=1;  //mark visted
while(!q_x.empty_())
{
	//remove the first point in grid (start point) -> S
    int X=q_x.pop(),Y=q_y.pop();

    for(int k=0;k<8;k++){   //visted 8 directions

        if(grid[X+dx[k]][Y+dy[k]]=='E'){ return dis[X][Y]+1;  }    //i arrived
        
        //check the new point i not visited and new point in the grid

        else if(!vis[X+dx[k]][Y+dy[k]] && check(X+dx[k],Y+dy[k])){  

            vis[X+dx[k]][Y+dy[k]]=1;  //mark visited
            dis[X+dx[k]][Y+dy[k]]=dis[X][Y]+1; //increase step +1
            
            //push new axis
            q_x.push(X+dx[k]);
            q_y.push(Y+dy[k]);
        }


    }

}


}


int main()
{


//take with and height
cin>>n>>m;

int s_x,s_y;

for(int i=0;i<n;i++){

    for(int j=0;j<m;j++){

        cin>>grid[i][j];
        
        //find star point
        if(grid[i][j]=='S'){s_x=i,s_y=j;}
    }


}

cout<<BFS(s_x,s_y);
	return 0;
}

