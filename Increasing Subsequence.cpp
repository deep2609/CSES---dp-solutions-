#include<bits/stdc++.h>
using namespace std;
#define boost ios_base::sync_with_stdio(false);cin.tie(NULL)
const int mod=1e9+7;
const int inf=1e9+7;
int main(){
      boost;
      int n;
      cin>>n;
      vector<int> v(n);
      for(int i=0;i<n;i++)cin>>v[i];
      map<int,int>M;
      set<int>s;
      s.insert(v[0]);
      M[v[0]]=1;
      for(int i=1;i<n;i++){
        auto ip=s.upper_bound(v[i]);
        if(ip==s.end()){
            auto x=ip;
            x--;
           if(*x!=v[i]) M[v[i]]=M[*x]+1;
            s.insert(v[i]);
        }else if(ip==s.begin()){
           // M.erase(*ip);
            s.erase(*ip);
            s.insert(v[i]);
            M[v[i]]=1;
        }else{
            auto x=ip;
            x--;
            if(*x!=v[i]) M[v[i]]=M[*ip],s.erase(ip);
            s.insert(v[i]);
        }
      }
      auto it=s.end();
      it--;
      cout<<M[*it]<<endl;
}
