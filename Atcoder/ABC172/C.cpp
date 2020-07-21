#define _GLIBCXX_DEBUG
#include <iostream>
#include <bits/stdc++.h>
    
    
using namespace std;
#define ll long long
#define ld long double
#define  P pair<ll,ll>
#define FOR(i,n,m) for(ll i=n; i<(ll)m;i++)
#define FORr(i,m,n) for(ll i=n; i>=(ll)m; i--)
#define FORm(i,m) for(auto i=m.begin();i!=m.end();i++)
#define REV(v) reverse(v.begin(),v.end())
#define sortAl(v) sort(v.begin(),v.end())
#define sortAlr(v) sort(v.begin(),v.end()); reverse(v.begin(),v.end())
#define cout(n) cout<<fixed<<setprecision(n)
#define dout(n) cout<<# n<<" = "<<n<<endl;
#define v1out(v) FOR(j,0,v.size()){cout<<v[j]; if(j!=(ll)v.size()-1)cout<<" ";else cout<<endl; }
#define v2out(v) FOR(i,0,v.size())v1out(v[i]);

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll n,m,k;
    cin>>n>>m>>k;
    vector<ll> A(n+1);
    vector<ll> B(m+1);
    FOR(i,1,n+1){
        cin>>A[i];
        A[i] += A[i-1];
    }
    FOR(i,1,m+1){
        cin>>B[i];
        B[i] += B[i-1];
    }


    ll b = m;
    ll res = 0;
    FOR(i,0,n+1){
        while(A[i] + B[b] > k && b>0) b--;
        if(A[i] + B[b] <= k) res = max(res, i+b);
    }
    cout<<res<<endl;
}