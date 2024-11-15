#include<bits/stdc++.h>
using namespace std;
double dp[3000][3000];
int n;
double f(vector<double>& p, int heads, int idx){
    if(idx==n)return heads>0? 0: 1;
    if(dp[idx][heads]>-0.9)return dp[idx][heads];
    return dp[idx][heads]=f(p,heads-1,idx+1)*p[idx] + f(p,heads,idx+1)*(1-p[idx]);
}
int main(){
    
    cin>>n;
    vector<double>p;
    for(int i=0;i<n;i++){
        double prob;
        cin>>prob;
        p.push_back(prob);
    }
    memset(dp,-1,sizeof(dp));
    cout<<fixed<<setprecision(9)<<f(p,(n+1)/2,0);
}