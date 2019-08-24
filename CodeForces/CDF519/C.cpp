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

  string s;
  cin>>s;
  ll N = s.size();
  vector<ll> v(N);


  FOR(i,1,N){
    if(s[i-1]=='a'&&s[i]=='b'){
      v[i-1]=1;
      v[i]=1;
    }
    else if(s[i-1]=='b'&&s[i]=='b'){
      v[i-1]=0;
    }
    else if(s[i-1]=='b'&&s[i]=='a'){
      v[i-1]=1;
    }
  }
  if(s[N-1]=='a')v[N-1]=1;
  else v[N-1]=0;


  FOR(i,0,N){
    cout<<v[i]<<" ";
  }
  cout<<endl;
}
