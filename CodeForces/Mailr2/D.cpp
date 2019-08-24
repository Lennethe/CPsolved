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

pair<string,string> ide(string in, string out){
  vector<ll> flag(in.size(),0);
  FOR(i,0,in.size()){
    if(in[i]!=out[i]){
      flag[i]=1;
    }
  }
  ll minp=1e5;
  ll maxp=0;
  FOR(i,0,in.size()){
    if(flag[i]==1){
      minp=min(minp,i);
      maxp=max(maxp,i);
    }
  }
  string subst;
  string subst_in;
  FOR(i,minp,maxp+1){
    subst_in.push_back(in[i]);
    subst.push_back(out[i]);
  }
  ll size = subst.size();
  vector<ll> div;
  FOR(i,1,size){
    if(size%i==0)div.push_back(i);
  }
  string res = subst;
  string res_in = subst_in;
  FOR(i,0,div.size()){
    ll po = div[i];
    ll f = 1;
    FOR(j,po,size){
      if(subst[j%po] != subst[j]){
        f = 0;
        break;
      }
    }
    if(f==1){
      res = "";
      res_in = "";
      FOR(j,0,po){
        res_in.push_back(subst_in[j]);
        res.push_back(subst[j]);
      }
    }
  }

  return make_pair(res_in,res);
}
string change(string in, pair<string,string> ie){
  string subst_in = ie.first;
  string subst_out = ie.second;
  FOR(i,0,in.size()-subst_in.size()+1){
    if(in[i]==subst_in[0]){
      ll f = 1;
      FOR(j,0,subst_in.size()){
        if(in[i+j]!=subst_in[j]){
          f=0;
          break;
        }
      }
      if(f==1){
        FOR(j,0,subst_in.size()){
          in[i]=subst_out[j];
          i++;
        }
      }
    }
  }
  return in;
}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll n;
    cin>>n;
    vector<string> in(n);
    vector<string> out(n);
    cinv(in,0,n);
    cinv(out,0,n);
    pair<string,string> sub;
    FOR(i,0,n){
      if(in[i]!=out[i]){
        sub = ide(in[i],out[i]);
        break;
      }
    }
    ll res = 1;

    FOR(i,0,n){
      in[i] = change(in[i],sub);
      //cout<<in[i]<<endl;
      if(in[i]!=out[i]){
        res=0;
        break;
      }
    }
    if(res==0) cout<<"NO"<<endl;
    else {
      cout<<"YES"<<endl;
      cout<<sub.first<<endl;
      cout<<sub.second<<endl;
    }
}
