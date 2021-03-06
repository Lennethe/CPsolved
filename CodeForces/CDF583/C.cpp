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
    string s;
    cin>>s;
    vector<ll> v(n+1);
    ll p = 0;
    ll po=0;
    FOR(i,0,n){
      v[i+1] = v[i];
      if(s[i] == '('){
        v[i+1]++; p++;
      }
      else{
        v[i+1]--; p--;
      }
      po = min(po,p);
    }

    if(po>=-1 && p==0) cout<<"Yes"<<endl;
    else cout<<"No"<<endl;
}
