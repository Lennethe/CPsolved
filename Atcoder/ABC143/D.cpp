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
int cal(int a){
    return a*(a-1)/2;
}    
int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n;
    cin>>n;
    vector<int> v(n);
    FOR(i,0,n) cin>>v[i];
    sortAlr(v);
    int ans = 0;
    cout<<endl;
    FOR(i,0,n){
        FOR(j,i+1,n){
            int dif = v[i] - v[j];
            int lb = j;
            int ub = n;
            while(ub-lb>1){
                int md = (ub+lb)/2;
                if(dif>v[md]) ub = md;
                else lb = md;
            }
            ans += lb - j;
        }
    }
    cout<<ans<<endl;
}