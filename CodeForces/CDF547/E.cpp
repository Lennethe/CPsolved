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
    ll hp,n;
    cin>>hp>>n;
    vector<ll> v(n+1);
    ll damage_max = 0;
    ll damage_round = 0;
    FOR(i,1,n+1){
      ll in;
      cin>>in;
      v[i] = v[i-1] + in;
      damage_max = min(v[i], damage_max);
      damage_round = v[i];
    }
    damage_max = -damage_max;
    damage_round = -damage_round;

    if(damage_round<=0){
      if(damage_max<hp) cout<<-1<<endl;
      else{
        FOR(i,0,n+1){
          if(hp + v[i] <= 0){
            cout<<i<<endl;
            break;
          }
        }
      }
    }
    else{
      ll res = 0;
      if(damage_max<hp) res = ((hp - damage_max)/damage_round - 1) * n;
      if(damage_max<hp)hp = ((hp - damage_max) % damage_round) + damage_max + damage_round;
      while(hp>0){
        FOR(i,0,n+1){
          if(hp + v[i] <= 0){
             res += i;
             hp += v[i];
             break;
          }
        }
        if(hp<=0) break;
        res += n;
        hp -= damage_round;
      }
      cout<<res<<endl;
    }
}
