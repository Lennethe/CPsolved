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
    ll n,a,b;
    cin>>n>>a>>b;
    ll dif = pow(2,n) - 1;
    ll bit = 1;
    ll tmp = 2;
    while(true){
      if(tmp-1 >= max(a,b)) break;
       tmp*=2;
       bit++;
    }
    ll bit_dif = 0;
    FOR(i,0,bit){
      if((a & 1<<i) ^ (b & 1<<i) ) bit_dif++;
    }

    if((dif>=bit_dif) && ((dif-bit_dif)%2 == 0)){
      cout<<"YES"<<endl;
      ll res = a;
      ll tmp_bit = 0;
      cout<<res<<" ";
      FOR(i,0,bit_dif){
        while((res & 1<<tmp_bit) == (b & 1<<tmp_bit)){
          tmp_bit++;
        }
        if((res & 1<<tmp_bit) == 1) res &= !(1<<tmp_bit);
        else res |= (1<<tmp_bit);
        cout<<res;
        if(i != bit_dif-1) cout<<" ";
      }
      FOR(i,bit_dif,dif){
        if(i == bit_dif) cout<<" ";
        if(res & (1<<0)) res--;
        else res++;
        cout<<res;
        if(i != dif-1) cout<<" ";
      }
      cout<<endl;
    }
    else cout<<"NO"<<endl;
}
