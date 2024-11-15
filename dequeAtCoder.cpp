#include<bits/stdc++.h>
#define ll long long int
using namespace std;
ll dp[3005][3005][2];
ll f(vector<int>&input, int i, int j, int chance){
    if(i==j)return (chance==1) ? input[i] : -input[i];
    if(dp[i][j][chance]!=-1)return dp[i][j][chance];
    if(chance==1)return dp[i][j][chance]=(ll)max((ll)input[i]+f(input,i+1,j,0),(ll)input[j]+f(input,i,j-1,0));
    return dp[i][j][chance]=(ll)min(f(input,i+1,j,1)-(ll)input[i],f(input,i,j-1,1)-(ll)input[j]);
}
int main(){
    int n;
    cin>>n;
    vector<int>input(n);
    for(int i=0;i<n;i++){
        cin>>input[i];
    }
    memset(dp,-1,sizeof(dp));
    cout<< f(input,0,n-1,1);
}