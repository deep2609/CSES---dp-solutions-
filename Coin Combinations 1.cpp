#include<bits/stdc++.h>
using namespace std;
#define boost ios_base::sync_with_stdio(false);cin.tie(NULL)
const int mod=1e9+7;
const int inf=1e9+7;
int main(){
       boost;
       int n,x;
       cin>>n>>x;
       vector<int> v(n);
       for(int i=0;i<n;i++)cin>>v[i];
       int dp[x+1];
       dp[0]=1;
       sort(v.begin(),v.end());
       for(int i=1;i<=x;i++){
         dp[i]=0;
         for(int j : v){
           if(j<=i){
                dp[i]+=dp[i-j];
                dp[i]%=mod;
           }else break;
         }  
       }
       cout<<dp[x]<<endl;
}
