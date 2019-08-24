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
    if(n == 1){
      cout<<"YES"<<endl;
      cout<<1<<" "<<2<<endl;
    }
    else{
      vector<ll> v(2*n);
      ll tmp = 0;
      FOR(i,1,2*n+1){
        v[tmp]=i;
        tmp = (tmp+3)%(2*n);
        cout<<tmp<<" "<<i<<endl;
      }
      ll c = v[0] + v[1] + v[2*n-1];
      FOR(i,1,2*n-1){
        ll x = v[i-1]+v[i]+v[i+1];
        if(abs(x-c)<=1)c=x;
        else{
          cout<<"NO"<<endl;
          break;
        }

        if(i == n-2){
          FOR(j,0,2*n){
            cout<<v[i];
            if(j != 2*n-1) cout<<" ";
            else cout<<endl;
          }
        }
      }
    }
}
