#include<bits/stdc++.h>
using namespace std;
#define boost ios_base::sync_with_stdio(false);cin.tie(NULL)
const int mod=1e9+7;
const int inf=1e9+7;
int main(){
      boost;
      int a,b;
      cin>>a>>b;
      int dp[501][501];
      memset(dp,0,sizeof(dp));
      for(int i=1;i<=500;i++){
        for(int j=1;j<=500;j++){
           if(i==j){
            dp[i][j]=0;
            continue;
           }
           if(i==1 || j==1){
             dp[i][j]=max(i,j)-1;
             continue;
           }
            dp[i][j]=mod;
            for(int k=1;k<j;k++){
              dp[i][j]=min(dp[i][j],dp[i][j-k] + dp[i][k] + 1);
            }
            for(int k=1;k<i;k++){
              dp[i][j]=min(dp[i][j],dp[i-k][j] + dp[k][j] + 1);
            }
        }
      }
      cout<<dp[a][b]<<endl;
}
