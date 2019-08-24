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
  ll n;
  cin>>n;
  vector<P> v(n);
  ll in;
  string s;
  FOR(i,0,n){
    cin>>in>>s;
    v[i]=P(in,0);
    FOR(j,0,s.size()){
      if(s[j]=='A')v[i].second+=100;
      if(s[j]=='B')v[i].second+=10;
      if(s[j]=='C')v[i].second+=1;
    }
  }

  ll a=1e9,b=1e9,c=1e9,ab=1e9,bc=1e9,ac=1e9,abc=1e9;
  FOR(i,0,n){
    if(v[i].second==100 && a>v[i].first) a=v[i].first;
    if(v[i].second==10 && b>v[i].first) b=v[i].first;
    if(v[i].second==1 && c>v[i].first) c=v[i].first;
    if(v[i].second==110 && ab>v[i].first) ab=v[i].first;
    if(v[i].second==11 && bc>v[i].first) bc=v[i].first;
    if(v[i].second==101 && ac>v[i].first) ac=v[i].first;
    if(v[i].second==111 && abc>v[i].first) abc=v[i].first;
  }
  ab=min(ab,a+b);
  ac=min(ac,a+c);
  bc=min(bc,b+c);
  ll res=0;
  ll in1,in2,in3;
  in1=min(ab+c,ab+ac);
  in1=min(in1,ab+bc);
  in2=min(bc+a,bc+ac);
  in2=min(in2,bc+ab);
  in3=min(ac+b,ac+ab);
  in3=min(in3,ac+bc);

  in1=min(in1,in2);
  in3=min(in3,abc);
  res=min(in1,in3);
  if(res>=1e9) res=-1;
  cout<<res<<endl;

}
