#include<bits/stdc++.h>
using namespace std;
#define boost ios_base::sync_with_stdio(false);cin.tie(NULL)
const int mod=1e9+7;
const int inf=1e9+7;
int main(){
       boost;
       int n,x;
       cin>>n>>x;
       vector<int> price(n);
       for(int i=0;i<n;i++)cin>>price[i];
       vector<int> pages(n);
       for(int i=0;i<n;i++)cin>>pages[i];
       long long sum=0;
       for(int i=0;i<n;i++)sum+=pages[i];
       vector<long long> dp(sum+1,mod);
       dp[0]=0;
       for(int i=0;i<n;i++){
        for(int value_already=sum - pages[i];value_already>=0;value_already--){
          dp[value_already+pages[i]]=min(dp[value_already+pages[i]],dp[value_already]+price[i]);
        }
       }
       long long ans=0;
       for(long long i=0;i<=sum;i++){
         if(dp[i]<=x){
          ans=max(ans,i);
         }
       }
       cout<<ans<<endl;
}
