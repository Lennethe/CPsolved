#include <stdio.h>
#include <bits/stdc++.h>

using namespace std;
using ll=long long;
using ld=long double;
using P=pair<ll,ll>;
#define FOR(i,n,m) for(ll i=n; i<(ll)m;i++)
#define FORr(i,n,m) for(ll i=n; i>(ll)m; i--)
#define cinv(v,n,m) FOR(i,n,m) cin>>v.at(i)
#define coutv(v,n,m) FOR(i,n,m) cout<<v.at(i) <<" "
#define cout(n) cout<<fixed<<setprecision(n)
int main(){
  int n,m;
  cin>>n;
  vector<string> v(n);
  cinv(v,0,n);
  cin>>m;
  vector<string> s(m);
  cinv(s,0,m);

  sort(v.begin(),v.end());
  sort(s.begin(),s.end());
  vector<pair<int,string>> key;
  key.push_back(make_pair(1,v[0]));
  FOR(i,1,n){
    if(key[key.size()-1].second==v[i]){
      key[key.size()-1].first++;
    }
    else{
      key.push_back(make_pair(1,v[i]));

    }
  }
  vector<pair<int,string>> key2;
  key2.push_back(make_pair(1,s[0]));
  FOR(i,1,m){
    if(key2[key2.size()-1].second==s[i]){
      key2[key2.size()-1].first++;
    }
    else{
      key2.push_back(make_pair(1,s[i]));

    }
  }
  FOR(i,0,key.size()){
    FOR(j,0,key2.size()){
      if(key[i].second==key2[j].second){
        key[i].first-=key2[j].first;
        break;
      }
    }
  }
  sort(key.begin(),key.end());

  if(key[key.size()-1].first>0) cout<<key[key.size()-1].first<<endl;
  else cout<<0<<endl;

}
