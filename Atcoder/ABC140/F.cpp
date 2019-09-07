//#define _GLIBCXX_DEBUG
#include <iostream>
#include <bits/stdc++.h>


using namespace std;
#define ll long long
#define ld long double
#define  P pair<ll,ll>
#define FOR(i,n,m) for(ll i=n; i<(ll)m;i++)
#define FORr(i,m,n) for(ll i=n; i>=(ll)m; i--)
#define FORm(i,m) for(auto i=m.begin();i!=m.end();i++)
#define sortAl(v) sort(v.begin(),v.end())
#define sortAlr(v) sort(v.begin(),v.end()); reverse(v.begin(),v.end())
#define cout(n) cout<<fixed<<setprecision(n)

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll n;
    cin>>n;
    vector<ll> a(1<<n);
    FOR(i,0,1<<n) cin>>a[i];
    sortAlr(a);
    string s = "Yes";

    vector<ll> v(1);
    vector<ll> d(1);
    v[0] = a[0];
    ll tmp = (n-1)*2+1;
    d[0] = (n-1)*2+1;
    FOR(i,0,n){
      ll s = v.size();
      if(tmp == 2) tmp=1;
      else tmp = tmp/2 + 1;
      FOR(j,0,s){
        v.push_back(v[j]-1);
        d.push_back(tmp);
      }
    }
    sortAlr(v);
    FOR(i,0,(1<<n)){
      if(a[i]>v[i])s = "No";
      if(a[i]<d[i])s = "No";
      cout<<a[i]<<" "<<d[i]<<endl;
    }
    cout<<s<<endl;


}
