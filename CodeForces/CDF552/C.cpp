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
    vector<ll> eat_fish = {-1,0,0,-1,0,0,-1};
    vector<ll> eat_rabbit = {0,-1,0,0,0,-1,0};
    vector<ll> eat_chicken = {0,0,-1,0,-1,0,0};

    ll fish,rabbit,chicken;
    cin>>fish>>rabbit>>chicken;

    ll week = 1e9;
    week = min(fish/3,week);
    week = min(rabbit/2,week);
    week = min(chicken/2,week);
    ll ans = week*7;
    fish -= week*3;
    rabbit -= week*2;
    chicken -= week*2;

    ll res = 0;
    FOR(i,0,7){
      ll day = i;
      ll tmp_fish = fish;
      ll tmp_rabbit = rabbit;
      ll tmp_chicken = chicken;
      ll tmp_res=0;
      while(tmp_fish>=0 && tmp_rabbit>=0 && tmp_chicken>=0){
        tmp_fish += eat_fish[day];
        tmp_rabbit += eat_rabbit[day];
        tmp_chicken += eat_chicken[day];
        day = (day+1)%7;
        tmp_res++;
      }
      tmp_res--;
      res = max(res, tmp_res);
    }
    cout<<ans+res<<endl;
}
