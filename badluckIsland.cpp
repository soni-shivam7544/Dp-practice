#include<bits/stdc++.h>
using namespace std;
double dp[105][105][105];
double fr(int r,int s, int p){
    if(r==0 || s==0)return 0;
    if(p==0)return 1;
    if(dp[r][s][p]>-0.9)return dp[r][s][p];
    double total=r*s+r*p+s*p;
    double ans=0;
    ans+=((r*p)/total)*fr(r-1,s,p);
    ans+=((r*s)/total)*fr(r,s-1,p);
    ans+=((s*p)/total)*fr(r,s,p-1);
    return dp[r][s][p]=ans;

}
double fs(int r,int s, int p){
    if(p==0 || s==0)return 0;
    if(r==0)return 1;
    if(dp[r][s][p]>-0.9)return dp[r][s][p];
    double total=r*s+r*p+s*p;
    double ans=0;
    ans+=((r*p)/total)*fs(r-1,s,p);
    ans+=((r*s)/total)*fs(r,s-1,p);
    ans+=((s*p)/total)*fs(r,s,p-1);
    return dp[r][s][p]=ans;

}
double fp(int r,int s, int p){
    if(r==0 || p==0)return 0;
    if(s==0)return 1;
    if(dp[r][s][p]>-0.9)return dp[r][s][p];
    double total=r*s+r*p+s*p;
    double ans=0;
    ans+=((r*p)/total)*fp(r-1,s,p);
    ans+=((r*s)/total)*fp(r,s-1,p);
    ans+=((s*p)/total)*fp(r,s,p-1);
    return dp[r][s][p]=ans;

}
int main(){
    int r,p,s;
    cin>>r>>s>>p;
    memset(dp,-1,sizeof(dp));
    cout<<fixed<<setprecision(9)<<fr(r,s,p)<<" ";
    memset(dp,-1,sizeof(dp));
    cout<<fixed<<setprecision(9)<<fs(r,s,p)<<" ";
    memset(dp,-1,sizeof(dp));
    cout<<fixed<<setprecision(9)<<fp(r,s,p);
}