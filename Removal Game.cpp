#include<bits/stdc++.h>
using namespace std;
#define boost ios_base::sync_with_stdio(false);cin.tie(NULL)
const int mod=1e9+7;
const int inf=1e9+7;
int main(){
        boost;
        int n;
        cin>>n;
        vector<long long> v(n);
        long long sum=0;
        for(int i=0;i<n;i++){
            cin>>v[i];
            sum+=v[i];
        }
        vector<vector<long long> >dp(5005,vector<long long>(5005));
        for(int L=n-1;L>=0;L--){
          for(int R=L;R<n;R++){
            if(L==R)dp[L][R]=v[L];
            else{
              dp[L][R]=max(v[L] - dp[L+1][R],v[R] - dp[L][R-1]);
            }
          }
        }
        cout<<(dp[0][n-1]+sum)/2<<endl;
}
