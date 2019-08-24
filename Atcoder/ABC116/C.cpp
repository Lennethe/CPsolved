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

    ll n;
    cin>>n;
    vector<ll> v(n);
    cinv(v,0,n);
    vector<ll> f(n,0);
    if(v[0]>v[1]){
      f[0]=1;
    }
    FOR(i,1,n-1){
      if(v[i-1]<=v[i] && v[i]>v[i+1]){
        f[i]=1;
      }
      if(v[i-1]>=v[i] && v[i]<v[i+1]){
        f[i]=-1;
      }
    }

    if(v[n-2]<=v[n-1]){
      f[n-1]=1;
    }
    ll down = 0;
    ll res=0;

    ll flag = 1;
    FOR(i,0,n){
      if(f[i]==1 && flag == 1){
        res += v[i] - down;
        flag = 0;
      }
      if(f[i] == -1 && flag == 0){
        down = v[i];
        flag = 1;
      }
    }
    if(n==1){
      res=v[0];
    }
    cout<<res<<endl;
}
