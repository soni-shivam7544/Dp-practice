#include<bits/stdc++.h>
using namespace std;
int w,h;
int dp[105][105];
int visited[105][105];
int touristPath(vector<string>&grid, int i, int j){
    if(grid[i][j]=='#')return 0;
    if(i==h-1 && j==w-1) {
        if(grid[i][j]=='*'){
            visited[i][j]=1;
            return 1;
        }
        return 0;
    }
    
    if(dp[i][j]!=-1)return dp[i][j];
    int result=0;
    if(i==h-1) result=touristPath(grid,i,j+1);
    else if(j==w-1) result=touristPath(grid,i+1,j);
    else result=max(touristPath(grid,i+1,j),touristPath(grid,i,j+1));
    
    if(grid[i][j]=='*'){
        visited[i][j]=1;
        return dp[i][j]=1+result;
    }
    return dp[i][j]=result;
}
int reverseTouristPath(vector<string>&grid, int i, int j){
    if(grid[i][j]=='#')return 0;
    if(i==0 && j==0) {
        if(grid[i][j]=='*' && visited[i][j]==0){
            visited[i][j]=1;
            return 1;
        }
        return 0;
    }
    
    if(dp[i][j]!=-1)return dp[i][j];
    int result=0;
    if(i==0) result=reverseTouristPath(grid,i,j-1);
    else if(j==0) result=reverseTouristPath(grid,i-1,j);
    else result=max(reverseTouristPath(grid,i-1,j),reverseTouristPath(grid,i,j-1));
    if(grid[i][j]=='*'&& visited[i][j]==0){
        visited[i][j]=1;
        return dp[i][j]=1+result;
    }
    return dp[i][j]=result;
}
int main(){
    // int n;
    // cin>>n;
    //while(n){
        memset(visited,0,sizeof(visited));
        memset(dp,-1,sizeof(dp));
        cin>>w>>h;
        vector<string>grid;
        for(int i=0;i<h;i++){
            string path="";
            for(int j=0;j<w;j++){
                char ch;
                cin>>ch;
                path.push_back(ch);
            }
            grid.push_back(path);
        }
        int ans=0;
        ans+=touristPath(grid,0,0);
        memset(dp,-1,sizeof(dp));
        // ans+=reverseTouristPath(grid,h-1,w-1);
        cout<<ans;
    //    n--;
    //}
}