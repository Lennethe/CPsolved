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

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll n,m,k;
    cin>>n>>m>>k;
    vector<ll> a(n);
    vector<ll> a_sort(n);
    FOR(i,0,n){
      ll in;
      cin>>in;
      a[i] = in;
      a_sort[i] = in;
    }
    sortAlr(a_sort);
    ll sum=0;
    FOR(i,0,m*k){
      sum+=a_sort[i];
    }
    cout<<sum<<endl;

    map<ll,ll> mp;
    ll pre = 0;
    FOR(i,0,n){
      if(pre != a_sort[i]){
        pre = a_sort[i];
        mp[pre] = i;
      }
    }
    ll num_m = 0;
    FOR(i,0,n){
      ll x = a[i];
      if(mp[x] < m*k){
        num_m++;
        mp[x]++;
        if(num_m == m+1){
          num_m = 1;
          cout<<i<<" ";
        }
      }
    }
    cout<<endl;
}
