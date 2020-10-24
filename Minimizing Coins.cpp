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
    int dp[x+1];
    dp[0]=0;
    sort(coins.begin(),coins.end());
    for(int i=1;i<=x;i++){
      dp[i]=inf;
      for(int j : coins){
         if(j<=i){
             if(dp[i-j]!=-1){
                dp[i]=min(dp[i],dp[i-j]+1);
              }
            }else break;
          }
          if(dp[i]==inf)dp[i]=-1;
     }
       cout<<dp[x]<<endl;
}
