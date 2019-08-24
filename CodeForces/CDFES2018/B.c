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
#define coutv(v,n,m) FOR(i,n,m) cout<<v.at(i) <<" "; cout<<endl
#define cout(n) cout<<fixed<<setprecision(n)
int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);

  ll N,M,A,B;
  cin>>N>>M>>A>>B;

  vector<ll> v(N,0);
  ll ina,inb;
  FOR(i,0,M){
    cin>>ina>>inb;

    FOR(j,ina-1,inb){
      v[j]=1;
    }
  }
  ll res=0;
  ll x=0;
  FOR(i,0,N){
    if(v[i]==1)x++;
  }

  if(A>B) res=A*N;
  else res=A*x+B*(N-x);
  cout<<res<<endl;
}
