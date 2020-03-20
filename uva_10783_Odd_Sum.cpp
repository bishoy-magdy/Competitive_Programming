#include<bits/stdc++.h>
#include<iostream>
#include<string>
#include<vector>
#include<cmath>
#include<list>
#include <algorithm>
#include<vector>
#include<set>
#include <cctype>
#include <cstring>
#include <cstdio>
#include<queue>
#include<stack>
#include<bitset>
#include<time.h>
#include<fstream>
/******************************************************/

using namespace std;


/********************define***************************/
#define ll 				long long
#define ld				long double
#define all(v)				((v).begin()), ((v).end())
#define for_(vec) 		for(int i=0;i<(int)vec.size();i++)
#define lp(j,n)		for(int i=j;i<(int)(n);i++)
#define clr(arr,x)  memset(arr,x,sizeof(arr))
#define fillstl(arr,X)    fill(arr.begin(),arr.end(),X)
#define pb         push_back
#define mp	   		make_pair
#define print_vector(X)  for(int i=0;i<X.size();i++)
/********************************************************/
typedef vector<int> vi;
typedef vector<pair<int, int>> vii;
typedef vector<vector<int>> vvi;
typedef vector<ll> vl;
/***********************function************************/

void fast(){ios_base::sync_with_stdio(NULL);cin.tie(0); cout.tie(0);}
void online_judge(){freopen("input.txt", "r", stdin);freopen("output.txt", "w", stdout);}
const int flag_max=0x3f3f3f3f;
const ll OO=1e9 ;
const double EPS = (1e-7);
int dcmp(double x, double y) {	return fabs(x-y) <= EPS ? 0 : x < y ? -1 : 1;	}

 ll gcd(ll a, ll b) {return !b ? a : gcd(b, a % b);}
 ll lcm(ll a, ll b) { return (a / gcd(a, b)) * b;}

/***********************main_problem****************************/




/**************************Bisho_O*****************************************/
int main() {

fast();
int arr[101]={0};
int last_odd=0;
for(int i=1;i<=100;i++){

    if(i%2){arr[i]+=i; arr[i]+=arr[last_odd]; last_odd=i; }


}


int t,X=1;
cin>>t;
while(t--){

int a,b;
cin>>a>>b;
int last_odd_a,last_odd_b;
last_odd_a=(a-2);
last_odd_b=(b-2);

if(a==0 || b==0 ||a==1 || b==1){int w=max(a,b);w%2==0?w--:w;  cout<<"Case "<<X<<": "<<arr[w]<<'\n';}
else if(b&1 && a&1)
{

if(last_odd_a<0){last_odd_a=0;}
if(last_odd_b<0){last_odd_b=0;}
cout<<"Case "<<X<<": "<<arr[max(a,b)]-arr[min(last_odd_a,last_odd_b)]<<'\n';

}
else if(a%2==0 || b%2==0){

a%2==0?a--,last_odd_a=a:0;
b%2==0?b--,last_odd_b=b:0;


if(last_odd_a<0){last_odd_a=0;}
if(last_odd_b<0){last_odd_b=0;}
cout<<"Case "<<X<<": "<<arr[max(a,b)]-arr[min(last_odd_a,last_odd_b)]<<'\n';


}

X++;
}


return 0;
}
