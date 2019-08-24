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

    ll n,m;
    cin>>n>>m;

    vector<vector<P>> v(n,vector<P>(2));
    vector<ll> dif;
    FOR(i,0,n){
      P min_x=P(1e10,0);
      P max_x=P(0,0);
      FOR(j,0,m){
        ll in;
        cin>>in;
        if(min_x.first>in){
          min_x = P(in,j);
        }
        if(max_x.first<in){
          max_x = P(in,j);
        }
      }
      if(min_x.first != max_x.first) dif.push_back(i);
      v[i][0] = min_x;
      v[i][1] = max_x;
    }

    ll ans = 0;
    FOR(i,0,n){
      ans = ans ^ v[i][0].first;
    }
    if(ans == 0){
      if(dif.size()==0) cout<<"NIE"<<endl;
      else{
        v[dif[0]][0] = v[dif[0]][1];
        cout<<"TAK"<<endl;
        FOR(i,0,n){
          cout<<v[i][0].second + 1<<" ";
        }
        cout<<endl;
      }
    }
    else{
      cout<<"TAK"<<endl;
      FOR(i,0,n){
        cout<<v[i][0].second + 1<<" ";
      }
      cout<<endl;
    }
}
