#include<bits/stdc++.h>
using namespace std;
int rows,cols;
int dp[100005][4];
int f(vector<vector<int>>& days, int row, int idx){
    if(row>=rows)return 0;
    if(dp[row][idx]!=-1)return dp[row][idx];
    int sum=0;
    for(int i=0;i<cols;i++){
        if(i==idx)continue;
        sum=max(sum,days[row][i]+f(days,row+1,i));
    }
    return dp[row][idx]=sum;
}
int main(){
    int n;
    cin>>n;
    vector<vector<int>>days;
    for(int i=0;i<n;i++){
        vector<int>activity;
        for(int i=0;i<3;i++){
            int happiness;
            cin>>happiness;
            activity.push_back(happiness);
        }
        days.push_back(activity);
    }
    rows=n;
    cols=3;
    memset(dp,-1,sizeof(dp));
    cout<<f(days,0,3);
}