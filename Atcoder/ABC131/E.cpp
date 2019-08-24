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
    ll n,k;
    cin>>n>>k;
    ll cap = (n-1)*(n-2)/2;
    if(cap<k)cout<<-1<<endl;
    else{
      cout<<n-1 + cap-k <<endl;
      FOR(i,2,n+1){
        cout<<1<<" "<<i<<endl;
      }

      FOR(i,2,n+1){
        if(cap==k)break;
        FOR(j,i+1,n+1){
          if(cap==k)break;
          cout<<i<<" "<<j<<endl;
          cap--;
        }
      }
    }
}
