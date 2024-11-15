#include<bits/stdc++.h>
using namespace std;
// vector<int>getDigits(int n){
//     vector<int>result;
//     while(n>0){
//         if(n%10!=0)result.push_back(n%10);
//         n/=10;
//     }
//     return result;
// }
int dp[1000005];
// vector<int>dp;
// int f(int num){
//     if(num<=9)return 1;
//     if(num==0)return 0;
    
//     if(dp[num]!=-1)return dp[num];
//     vector<int>d=getDigits(num);
//     int mn=INT_MAX;
//     for(int i=0;i<d.size();i++){
//         mn=min(mn,f(num-d[i]));
//     }
//     return dp[num]=1+mn;
// }
int f(int num){
    if(num<0)return INT_MAX;
    if(num==0)return 0;
    
    if(dp[num]!=-1)return dp[num];
    int mn=INT_MAX;
    int n=num;
    while(n>0){
        if(n%10!=0){
            mn=min(mn,f(num-n%10));
        }
        n/=10;
    }
    return dp[num]=1+mn;
}
int main(){
    int n;
    cin>>n;
    memset(dp,-1,sizeof(dp));
    // dp.resize(1000005,-1);
    cout<<f(n);
}