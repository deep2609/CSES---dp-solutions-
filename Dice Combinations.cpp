#include<bits/stdc++.h>
using namespace std;
#define boost ios_base::sync_with_stdio(false);cin.tie(NULL)
const int mod=1e9+7;
int main(){
      boost;
      int n;
      cin>>n;
      int dp[n+1];
      dp[0]=1;
      for(int i=1;i<=n;i++){
         dp[i]=0;
         for(int j=1;j<=min(i,6);j++){
           dp[i]+=dp[i-j];
           dp[i]%=mod;
         }
       }
      cout<<dp[n]<<endl;
}
 
