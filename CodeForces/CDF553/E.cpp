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

ll mod = 1e9+7;
// rightは含まない
ll odd_sum(ll left, ll right){
  return ((2*left - 1)%mod + (2*right - 1)%mod) * (right - left)/2%mod;
}

ll even_sum(ll left, ll right){
  return (left%mod + (right-1)%mod)*(right-left)%mod;
}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);

    ll a,b;
    cin>>a>>b;
    ll odd=0;
    ll even=0;
    ll siz=1;
    ll flag = 0;

    while(!(odd+even<=a && a<=odd+even + siz ) ){
      if(flag == 0){
        flag = 1;
        odd+=siz;
      }
      else{
        flag = 0;
        even+=siz;
      }
      siz*=2;
    }
    ans =

}
