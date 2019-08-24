//#define _GLIBCXX_DEBUG
#include <iostream>
#include <vector>
#include <stdio.h>
#include <bits/stdc++.h>


using namespace std;
#define ll long long
#define ld long double
#define  P pair<ll,ll>
#define FOR(i,n,m) for(ll i=n; i<(ll)m;i++)
#define FORa(i,c) for(__typeof((c).begin())i=(c).begin();i!=(c).end();++i)
#define FORr(i,m,n) for(ll i=n; i>=(ll)m; i--)
#define FORm(i,m) for(auto i=m.begin();i!=m.end();i++)
#define FORs(i,st) for(auto i : st)
#define REP(i,n) for(int i=0;i<(int)n;++i)
#define ALL(c) (c).begin(), (c).end()
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
    ll min_v = 0;
    FOR(i,1,n){
      ll in;
      cin>>in;
      v[i] = v[i-1] + in;
      min_v = min(min_v, v[i]);
    }
    map<ll,ll> mp;
    ll flag=0;
    FOR(i,0,n){
      ll x = v[i] - min_v + 1;
      if(x<1 || n<x) flag=1;
      mp[x]++;
      if(mp[x] > 1) flag=1;
    }
    if(flag == 1) cout<<-1<<endl;
    else{
      FOR(i,0,n){
        cout<<v[i] - min_v + 1<<" ";
      }
      cout<<endl;
    }
}
