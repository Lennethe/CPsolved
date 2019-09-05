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
    ll a1,a2,a3,a4;
    cout<<"? 1 2"<<endl;
    cin>>a1;
    cout<<"? 1 3"<<endl;
    cin>>a2;
    cout<<"? 1 4"<<endl;
    cin>>a3;
    cout<<"? 1 5"<<endl;
    cin>>a4;

    vector<ll> v = {4,8,15,16,23,42};

    vector<ll> ans(6);
    FOR(i,0,6){
      if(a1%v[i]==0 && a2%v[i]==0 && a3%v[i]==0 && a4%v[i]==0){
        ans[0]=v[i];
      }
    }
    ans[1] = a1/ans[0];
    ans[2] = a2/ans[0];
    ans[3] = a3/ans[0];
    ans[4] = a4/ans[0];

    FOR(i,0,5){
      FOR(j,0,6){
        if(v[j] == ans[i])v[j]=0;
      }
    }
    ll x = 0;
    FOR(i,0,6)x = max(x,v[i]);

    cout<<"! "<<ans[0]<<" "<<ans[1]<<" "<<ans[2]<<" "<<ans[3]<<" "<<ans[4]<<" "<<x<<endl;

}
