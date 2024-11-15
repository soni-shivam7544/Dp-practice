#include<bits/stdc++.h>
using namespace std;
int dp[5005][5005];
int f(vector<pair<int,int>>&pilots, int m,int a){
    if(m==0 && a==0)return 0;
    if(dp[m][a]!=-1)return dp[m][a];
    int sum=0;
    if(a==0 || a==m){
        sum+=pilots[a+m-1].first + f(pilots,m-1,a);
    }
    else if(m==0){
        sum+=pilots[a+m-1].second + f(pilots,m,a-1);
    }
    else sum+=min(pilots[a+m-1].first + f(pilots,m-1,a) , pilots[a+m-1].second + f(pilots,m,a-1));
    return dp[m][a]=sum;
}
int main(){
    int n;
    cin>>n;
    vector<pair<int, int>>pilots;
    for(int i=0;i<n;i++){
        int m,a;
        cin>>m>>a;
        pilots.push_back({m,a});
    }
    memset(dp,-1,sizeof(dp));
    cout<<f(pilots,n/2,n/2);
}