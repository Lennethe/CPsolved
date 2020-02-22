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

ll f(ll a, ll n){
    return (a+n)%n;
}    
int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    auto compare = [](P a, P b) {
        return a.first < b.first;
    };

    std::priority_queue<
        P,
        std::vector<P>,
        decltype(compare) // 比較関数オブジェクトを指定
    > q {compare};

    ll n;
    cin>>n;
    vector<ll> in(n);
    FOR(i,0,n)cin>>in[i];
    vector<ll> out(n);
    FOR(i,0,n)cin>>out[i];
    FOR(i,0,n)q.push(P(out[i],i));
    
    ll res = 0;
    ll pre = -1;
    while(!q.empty() && pre != q.top().second){
        ll val = q.top().first;
        ll idx = q.top().second;
        pre = idx;
        q.pop();
        if(val == in[idx]) continue;
        if(val <= out[f(idx-1,n)] + out[f(idx+1,n)]) continue;
        ll dif = out[idx] - in[idx];
        ll t_res = dif/(out[f(idx-1,n)] + out[f(idx+1,n)]);
        res += t_res;
        out[idx] -= t_res*(out[f(idx-1,n)] + out[f(idx+1,n)]);

        if(out[idx]>in[idx]) q.push(P(out[idx],idx));
    }
    FOR(i,0,n) if(in[i] != out[i]) res = -1;
    cout<<res<<endl;


    

}