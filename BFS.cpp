#include<bits/stdc++.h>
using namespace std;
bool vis[1000][1000]; //2D array because to discover any node again

int dis[1000][1000]; //2D array store the distance of each node from star s

char arr[1000][1000];   //the main grid

int dx[8]= {1,-1,0,0,1,1,-1,-1}; //increase or decrease dx for every direction

int dy[8]= {0,0,-1,1,1,-1,1,-1}; //increase or decrease dy for every direction

int n,m,x,y;   //the two dimension of array
//function return distance (the shortest path) from star S to end E
//x y the start point in the grid
int BFS(int x,int y)
{
    queue<pair<int,int> >q;
    q.push({x,y});  // push the start point and mark it with true
    vis[x][y]=true;
    dis[x][y]=0; //the first distance from star point
    while(!q.empty())
    {
        pair<int,int>F=q.front();
        q.pop(); //remove from the queue
        //visited the eight direction (N,W,E,S,NE,NW,,SE,SW)
        for(int i=0; i<8; i++)
        {
            int new_x=F.first+dx[i],new_y=F.second+dy[i];
            //not visited yet and the new point in the grid
            if(!vis[new_x][new_y] && ((new_x)>=0 &&(new_x)<n && new_y>=0 && new_y<m ))
            {
                vis[new_x][new_y]=true; //mark it
                
                dis[new_x][new_y]=dis[F.first][F.second]+1; //the distance=Previous+1
                //if i arrive the end point
                
                if(arr[new_x][new_y]=='E')
                {
                    return dis[new_x][new_y];
                }
                q.push({new_x,new_y});  //enqueue in the queue
            }
        }
    }
//if i can`t reach to the end point
    return -1;
}
int main()
{
//using STL because to make the code more readable
//clear the grid with false !
    memset(vis,0,sizeof(vis));
    cin>>n>>m;
//take the grid
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<m; j++)
        {
            cin>>arr[i][j];
            //start point
            if(arr[i][j]=='S')
            {
                x=i,y=j;
            }
        }
    }
    cout<<"the distance from S to E \n";
  
    cout<<BFS(x,y);
  
  
    return 0;
}
