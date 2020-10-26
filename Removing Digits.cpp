#include<bits/stdc++.h>
using namespace std;
#define boost ios_base::sync_with_stdio(false);cin.tie(NULL)
const int mod=1e9+7;
const int inf=1e9+7;
int main(){
       boost;
       int n;
       cin>>n;
       int dp[n+1];
       dp[0]=0;
       for(int i=1;i<=n;i++){
         int x=i;
         dp[i]=mod;
         while(x>0){
           int r=x%10;
           dp[i]=min(dp[i-r]+1,dp[i]);
           x/=10;
         }
       }
       cout<<dp[n]<<endl;
}
