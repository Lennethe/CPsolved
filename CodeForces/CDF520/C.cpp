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
    ll q;
    cin>>n>>q;
    string s;
    cin>>s;
    vector<ll> v(s.size()+1);
    vector<ll> fun(100001);
    fun[0]=1;
    FOR(i,1,100001){
      fun[i]=fun[i-1]*2%1000000007;
    }
    FOR(i,1,v.size()){
      if(s[i-1]=='1')v[i]++;
      v[i]+=v[i-1];
    }
    FOR(i,0,q){
      ll l,r;
      cin>>l>>r;
      l--;
      ll one=v[r]-v[l];
      ll zero=r-l-one;

      //cout<<zero<<" "<<one<<endl;
      cout<<(fun[one]-1)*fun[zero]%1000000007<<endl;
    }
}
