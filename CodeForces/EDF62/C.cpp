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
    ll n,k;
    cin>>n>>k;
    vector<P> v(n);
    FOR(i,0,n){
      ll in1,in2;
      cin>>in1>>in2;
      v[i] = P(in2,in1);
    }
    sortAlr(v);
    set<ll> ans;
    ll time=0;
    ll beauty=0;
    ll res=0;

    FOR(i,0,n){
      beauty = v[i].first;
      if(i<k){
        time += v[i].second;
        ans.insert(v[i].second);
      }
      else{
        time += v[i].second;
        ans.insert(v[i].second);
        ll x = *ans.begin();
        ans.erase(ans.begin());
        time-=x;

      }
//      cout<<"i = "<<i<<endl;
//      cout<<time<<" "<<beauty<<endl;
      res = max(res,time*beauty);

    }
    cout<<res<<endl;

}
