#include<bits/stdc++.h>
using namespace std;
int k,l,m;
int dp[1000005];
int canWin(int n){
    if(n<0)return 1;
    if(n==1 || n==k || n==l)return 1;
    if(dp[n]!=-1)return dp[n];
    return dp[n]=((canWin(n-1)==1 && canWin(n-k)==1 && canWin(n-l)==1))?0:1;
}
char canwin(int n){
     if(canWin(n))return 'A';
     return 'B';
}
int main(){
    memset(dp,-1,sizeof(dp));
    cin>>k>>l>>m;
    vector<int>queries;
    for(int i=0;i<m;i++){
        int query;
        cin>>query;
        queries.push_back(query);
        
    }
    for(int query:queries){
        cout<<canwin(query);
    }
}