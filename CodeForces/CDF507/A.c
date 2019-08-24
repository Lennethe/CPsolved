#include <stdio.h>
#include <bits/stdc++.h>

using namespace std;
using ll=long long;
using ld=long double;
using P=pair<ll,ll>;
#define FOR(i,n,m) for(ll i=n; i<(ll)m;i++)
#define FORr(i,n,m) for(ll i=n; i>(ll)m; i--)
#define FORm(i,m) for(auto i=m.begin();i!=m.end();i++)
#define VEC2(x,a,b) vector<vector<ll>> x = vector<vector<ll>>(a,vector<ll>(b,0))
#define sortAl(v) sort(v.begin(),v.end())
#define sortAlr(v) sort(v.begin(),v.end()); reverse(v.begin(),v.end())
#define cinv(v,n,m) FOR(i,n,m) cin>>v.at(i)
#define coutv(v,n,m) FOR(i,n,m) cout<<v.at(i) <<" "; cout<<end
#define cout(n) cout<<fixed<<setprecision(n)
int main(){
  ll N,a,b;
  cin>>N>>a>>b;
  vector<ll> v(N);
  cinv(v,0,N);

  ll res=0;
  FOR(i,0,N){
    if(v[i]==v[N-1-i]&&v[i]==2){
      res+=min(a,b);
      if(i==N-i-1){
        res+=min(a,b);
      }
    }
    else if(v[i]!=v[N-i-1]){
      if(max(v[i],v[N-i-1])==1){
        res=-2;
        break;
      }
      else{
        if(min(v[i],v[N-i-1])==0){
          res+=a;
        }
        else res+=b;
      }
    }
  }
  cout<<res/2<<endl;
}
