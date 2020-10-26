#include<bits/stdc++.h>
using namespace std;
#define boost ios_base::sync_with_stdio(false);cin.tie(NULL)
const int mod=1e9+7;
const int inf=1e9+7;
int main(){
      boost;
      int n;
      cin>>n;
      int sum=n*(n+1)/2;
      if(sum%2!=0){
        cout<<0<<endl;
        return 0;
      }
      sum=sum/2;
      vector<vector<int> >dp(n,vector<int>(sum+1,0));
      dp[0][0]=1;
      for(int i=1;i<n;i++){
        for(int j=0;j<=sum;j++){
          dp[i][j]=dp[i-1][j];
          int left=j-i;
          if(left>=0){
            dp[i][j]=(dp[i][j]%mod + dp[i-1][left]%mod)%mod;
          }
        }
      }
      cout<<dp[n-1][sum]<<endl;
}
