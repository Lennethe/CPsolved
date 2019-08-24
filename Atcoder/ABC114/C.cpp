#include <stdio.h>
#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define ld long double
#define  P pair<ll,ll>
#define FOR(i,n,m) for(ll i=n; i<(ll)m;i++)
#define FORr(i,n,m) for(ll i=n; i>=(ll)m; i--)
#define FORm(i,m) for(auto i=m.begin();i!=m.end();i++)
#define VEC2(x,a,b) vector<vector<ll>> x = vector<vector<ll>>(a,vector<ll>(b,0))
#define sortAl(v) sort(v.begin(),v.end())
#define sortAlr(v) sort(v.begin(),v.end()); reverse(v.begin(),v.end())
#define cinv(v,n,m) FOR(i,n,m) cin>>v.at(i)
#define coutv(v,n,m) FOR(i,n,m) cout<<v.at(i) <<" "; cout<<endl
#define cout(n) cout<<fixed<<setprecision(n)

ll solve(vector<vector<ll>> v, ll three, ll five, ll seven, ll po){
  if(po>=v[0].size() &&(three*five*seven >0)){
    return 1;
  }
  ll ans=0;
  if(v[0][po]==1){
    ans+=solve(v,three+1,five,seven,po+1);
  }
  if(v[1][po]==1){
    ans+=solve(v,three,five+1,seven,po+1);
  }
  if(v[2][po]==1){
    ans+=solve(v,three,five,seven+1,po+1);
  }
  return ans;
}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);

    string s;
    cin>>s;
    VEC2(v,3,s.size());

    FOR(i,0,3){
      FOR(j,0,s.size()){
        v[i][j]=1;
      }
    }
    cout<<v[0].size()<<endl;
    cout<<solve(v,0,0,0,0)<<endl;
}
