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

    string s;
    cin>>s;
    ll size=s.size();

    ll a=0,b=0;
    ll f=0;
    while(a==0){
      FOR(i,1,5){
        if(size%i==0 && size/i<20){
          a=i;
          b=size/i;
        }
      }
      size++;
      f++;
    }
    FOR(i,0,f){
      s.push_back('*');
    }
    cout<<a<<" "<<b<<endl;
    FOR(i,0,a){
      FOR(j,0,b){
        cout<<s[i*b+j];
      }
      cout<<endl;
    }

}
