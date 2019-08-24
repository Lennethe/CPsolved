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


  ll n;
  cin>>n;
  vector<ll> v(n);
  cinv(v,0,n);

  vector<ll> key(101,0);

  FOR(i,0,n){
    key[v[i]]++;
  }

  ll x1=0;
  ll x3=0;
  FOR(i,0,101){
    if(key[i]==1)x1++;
    if(key[i]>=3)x3++;
  }

  string res="A";
  if(x1%2==1&&x3==0){
    cout<<"NO"<<endl;
  }
  else{
    if(x1%2==1)x3=1;
    else x3=0;
    cout<<"YES"<<endl;
    FOR(i,0,n){
      if(key[v[i]]==1){
        cout<<res;
        if(res=="A")res="B";
        else res="A";
      }
      else if(key[v[i]]==2){
        cout<<"A";
      }
      else if(key[v[i]]>=3 && x3==1){
        x3=0;
        cout<<"B";
      }
      else cout<<'A';
    }
  }
  cout<<endl;
}
