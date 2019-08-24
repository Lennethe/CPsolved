#include <stdio.h>
#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define ld long double
#define  P pair<ll,ll>
#define FOR(i,n,m) for(ll i=n; i<(ll)m;i++)
#define FORr(i,m,n) for(ll i=n; i>=(ll)m; i--)
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

    ll n;
    cin>>n;
    map<ll,ll> mp;
    FOR(i,0,n*n){
      ll in;
      cin>>in;
      mp[in]++;
    }
    vector<ll> four;
    vector<ll> two;
    vector<ll> one;
    map<ll,ll> two_mp;
    ll two_size=0;
    ll one_size=0;
    FORm(i,mp){
      ll x = i-> second;
      ll key = i-> first;
      if(x%4 == 0){
        FOR(i,0,x/4){
          four.push_back(key);
        }
      }
      else if(x%2 == 0){
        two_mp[key] = x;
        two.push_back(key);
      }
      else{
        one_size += 1;
        FOR(i,0,x){
          one.push_back(key);
        }
      }
    }

    FORm(i,two_mp){
      ll x = i->second;
      ll key = i->first;
      FOR(i,0,x/2-1){
        two.push_back(key);
      }
    }

    if(one_size>n%2){
      cout<<"NO"<<endl;
    }
    else{
      FOR(i,0,one.size()/4){
        two.push_back(one[i]);
        two.push_back(one[i]);
      }
      if((one_size-1)%4 == 2){
        two
      }
    }
}
