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
#define coutv(v,n,m) FOR(i,n,m) cout<<v.at(i); cout<<endl
#define cout(n) cout<<fixed<<setprecision(n)
int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);

  ll n,t;
  cin>>n>>t;
  string s1,s2;
  cin>>s1>>s2;

  ll same=0;
  FOR(i,0,s1.size()){
    if(s1[i]==s2[i])same++;
  }
  same=same+(s1.size()-same)/2;

  t=s1.size()-t;
  if(same<t) cout<<-1<<endl;
  else{
    vector<char> res(s1.size(),'1');

    ll num=0;
    FOR(i,0,s1.size()){
      if(num!=t&&s1[i]==s2[i]){
        res[i]=s1[i];
        num++;
      }
    }
    ll na=num,nb=num;
    //cout<<num<<endl;
    //coutv(res,0,n);
    FOR(i,0,s1.size()){
      if(res[i]=='1'){
        if(na!=t){
          res[i]=s1[i];
          na++;
        }
        else if(nb!=t){
          res[i]=s2[i];
          nb++;
        }
        else{
          if(s1[i]!='a'&&s2[i]!='a') res[i]='a';
          else if(s1[i]!='b'&&s2[i]!='b') res[i]='b';
          else if(s1[i]!='c'&&s2[i]!='c') res[i]='c';
        }
      }

    }
    coutv(res,0,s1.size());
  }
}
