#include<bits/stdc++.h>
using namespace std;
#define boost ios_base::sync_with_stdio(false);cin.tie(NULL)
const int mod=1e9+7;
const int inf=1e9+7;
int main(){
        boost;
        int n,x;
        cin>>n>>x;
        vector<int> coins(n);
        for(int i=0;i<n;i++)cin>>coins[i];
        vector<vector<int> >dp(n+1,vector<int>(x+1,0));
        dp[0][0]=1;
        for(int i=1;i<=n;i++){
          for(int j=0;j<=x;j++){
            dp[i][j]=dp[i-1][j];
            int left=j - coins[i-1];
            if(left>=0){
              dp[i][j]+=dp[i][left];
              dp[i][j]%=mod;
            }
          }
        }
        cout<<dp[n][x]<<endl;
}
