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

int qst(ll c, ll d){
  cout<<"?"<<" "<<c<<" "<<d<<endl;
  ll x;
  cin>>x;
  return x;
}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll a=0,b=0;
    ll f=0;

    ll c=1<<29;d=1<<29;

    while(f!=0){
      ll x=qst(a|c,b|d);
      while(f==x){
        c=c>>1;
        d=d>>1;
        x=qst(a|c,b|d);
      }
      if(f==1){
        a=a|c;
      }
      if(f==-1){
        b=b|d;
      }
      f=qst(a,b);
      c=c>>1;
      d=d>>1;
    }

}
