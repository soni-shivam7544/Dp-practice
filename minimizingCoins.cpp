#include<bits/stdc++.h>
using namespace std;
int dp[1000005];
int f(vector<int>&coins, int sum){
    if(sum==0)return 0;
    int result=INT_MAX;
    if(dp[sum]!=-1)return dp[sum];
    for(int i=0;i<coins.size();i++){
        if(coins[i]>sum)continue;
        result=min(result,f(coins,sum-coins[i]));
    }
    if(result==INT_MAX)return dp[sum]=INT_MAX;
    else return dp[sum]=1+result;
}
int main(){
    int n,sum;
    cin>>n>>sum;
    vector<int>coins(n);
    for(int i=0;i<n;i++){
        cin>>coins[i];
    }
    memset(dp,-1,sizeof(dp));
   
    int ans=f(coins, sum);
    if(ans>=INT_MAX)cout<<-1;
    else cout<<ans;
}