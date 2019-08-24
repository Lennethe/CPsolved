#include <stdio.h>
#include <bits/stdc++.h>

using namespace std;
using ll=long long;
using ld=long double;
using P=pair<ll,ll>;
#define FOR(i,n,m) for(ll i=n; i<(ll)m;i++)
#define FORr(i,n,m) for(ll i=n; i>(ll)m; i--)
#define FORm(i,m) for(auto i=m.begin();i!=m.end();i++)
#define cinv(v,n,m) FOR(i,n,m) cin>>v.at(i)
#define coutv(v,n,m) FOR(i,n,m) cout<<v.at(i) <<" "
#define cout(n) cout<<fixed<<setprecision(n)
int main(){
  int N,M;
  cin>>N>>M;
  vector<vector<ll>> key = vector<vector<ll>> (M,vector<ll>(3,0));

  FOR(i,0,M){
    FOR(j,0,3){
      cin>>key[i][j];
    }
  }

  vector<ll> res(N+1,0);
  ll a,b,c;
  sort(key.begin(),key.end());
  FOR(i,0,M){
    a=key[i][0];
    b=key[i][1];
    c=key[i][2];
    res[b]=res[a]+c;
  }
  string s="Yes";

  FOR(i,0,M){
    a=key[i][0];
    b=key[i][1];
    c=key[i][2];
    if(res[b]-res[a]!=c) s="No";
  }
  cout<<s<<endl;
}
