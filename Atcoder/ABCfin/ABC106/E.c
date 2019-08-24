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
  ll N,M,Q;
  cin>>N>>M>>Q;
  vector<vector<ll>> v = vector<vector<ll>> (N+1,vector<ll>(N+1,0));
  ll a,b;
  FOR(i,0,M){
    cin>>a>>b;
    v[a][b]++;
  }

  FOR(i,0,N){
    FOR(j,0,N+1){
      v[i+1][j] += v[i][j];
    }
  }
  FOR(i,0,N+1){
    FOR(j,0,N){
      v[i][j+1] += v[i][j];
    }
  }


  FOR(i,0,Q){
    cin>>a>>b;
    cout<<v[b][b]-v[a-1][b]-v[b][a-1]+v[a-1][a-1]<<endl;
  }


}
