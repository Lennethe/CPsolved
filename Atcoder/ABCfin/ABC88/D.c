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
  ll H,W;
  cin>>H>>W;
  vector<vector<pair<char,int>>> v = vector<vector<pair<char,int>>> (H+2,vector<pair<char,int>>(W+2,make_pair('#',0)));

  ll x=0;
  string s;
  FOR(i,1,H+1){
    cin>>s;
    FOR(j,1,W+1){
      if(s[j-1]=='.') x++;
      v[i][j].first=s[j-1];
    }
  }

  queue<P> q;
  q.push(P(1,1));
  v[1][1].second = 1;
  ll a,b;
  while(!q.empty()){
    a = q.front().first;
    b = q.front().second;
    q.pop();
    if(v[a+1][b] == make_pair('.',0) ) {
      q.push(P(a+1,b));
      v[a+1][b].second=v[a][b].second+1;
    }
    if(v[a-1][b] == make_pair('.',0) ) {
      q.push(P(a-1,b));
      v[a-1][b].second=v[a][b].second+1;
    }
    if(v[a][b+1] == make_pair('.',0) ) {
      q.push(P(a,b+1));
      v[a][b+1].second=v[a][b].second+1;
    }
    if(v[a][b-1] == make_pair('.',0) ) {
      q.push(P(a,b-1));
      v[a][b-1].second=v[a][b].second+1;
    }
    //cout<<a<<" "<<b<<endl;
  }
  ll res=v[H][W].second;
  if(res==0) res=-1;
  else res=x-res;
  /*
  FOR(i,0,H+2){
    FOR(j,0,W+2){
      cout<<v[i][j].first;
    }
    cout<<endl;
  }
  FOR(i,0,H+2){
    FOR(j,0,W+2){
      cout<<v[i][j].second;
    }
    cout<<endl;
  }*/


  cout<<res<<endl;




}
