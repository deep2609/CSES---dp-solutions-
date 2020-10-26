#include<bits/stdc++.h>
using namespace std;
#define boost ios_base::sync_with_stdio(false);cin.tie(NULL)
const int mod=1e9+7;
const int inf=1e9+7;
int main(){
       boost;
       int n;
       cin>>n;
       char arr[n][n];
       for(int i=0;i<n;i++){
        for(int j=0;j<n;j++)cin>>arr[i][j];
       }
       if(arr[0][0]=='*' || arr[n-1][n-1]=='*'){
         cout<<0<<endl;
         return 0;
       }
       int dp[n][n];
       memset(dp,0,sizeof(dp));
       for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
           if(i==0 && j==0){
            dp[i][j]=1;
            continue;
           }
           if(i==0 && arr[i][j]=='.'){
            dp[i][j]=dp[i][j-1];
            continue;
           }
           if(j==0 && arr[i][j]=='.'){
            dp[i][j]=dp[i-1][j];
            continue;
           }
           if(arr[i][j]=='.'){
             dp[i][j]=(dp[i-1][j]%mod + dp[i][j-1]%mod)%mod;
           }
        }
       }
       cout<<dp[n-1][n-1]<<endl;
}
