#include<bits/stdc++.h>
using namespace std;
long long dp[1000005];
long long combinations(int n){
    if(n==0)return 1;
    if(dp[n]!=-1)return dp[n];
    long long sum=0;
    for(int i=1;i<=n && i<=6;i++){
        sum+=combinations(n-i);
    }
    return dp[n]=(long long)sum%1000000007;
}
int main(){
    int n;
    cin>>n;
    memset(dp,-1,sizeof(dp));
    cout<<combinations(n);
}