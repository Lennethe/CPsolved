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
    deque<ll> que;
    map<ll,ll> mp;
    ll m = 1;
    FOR(i,0,21){
      mp[m-1] = 1;
      m *= 2;
    }

    ll x = 0;
    FOR(i,0,21){
      if((n & (1<<i)) == 1) x++;
    }

    if(n%2==0){
      que.push_back(0);
      n++;
    }

    if(x <= 8){
      if(mp[n] == 0){
        que.push_back(21);
        n ^= (1<<21) - 1;
        n++;
      }
    }

    FORr(i,0,20){
//      cout<< (1<<i)<<endl;
      if(mp[n] == 1)break;
      if((n & 1<<i) == 0){
        if(i == 0) que.push_back(i);
        else{
          que.push_back(i+1);
          n = n ^ ((1<<(i+1)) - 1);
          n += 1;
        }
      }
    }

    cout<<que.size()*2<<endl;
    while(!que.empty()){
      cout<<que.front();
      que.pop_front();
      if(!que.empty()) cout<<" ";
    }
    cout<<endl;

}
