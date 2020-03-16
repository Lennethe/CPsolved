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
#define sortAl(v) sort(v.begin(),v.end()) //1 2 3
#define sortAlr(v) sort(v.begin(),v.end()); reverse(v.begin(),v.end()) // 3 2 1
#define cout(n) cout<<fixed<<setprecision(n)
#define dout(n) cout<<# n<<" = "<<n<<endl;


ll rec(ll t, vector<ll>& position, vector<vector<ll>>& children){
    ll ans = 1;
    ll tmp = 1;
    FOR(i,0,children[t].size()){
        tmp *= rec(children[t][i],position,children);
    }
    ans+=tmp;
    return ans;
}
int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll n;
    cin>>n;
    vector<P> v(n);
    FOR(i,0,n){
        ll a,b;
        cin>>a>>b;
        v[i].first = a;
        v[i].second = a+b;
    }
    sortAl(v);
    //FOR(i,0,n){
    //    cout<<i<<" "<<v[i].first<<" "<<v[i].second<<endl;
    //}

    vector<ll> position(n);
    vector<ll> destination(n);
    FOR(i,0,n){
        position[i] = v[i].first;
        destination[i] = v[i].second;
    }
    vector<ll> parents(n,-1);
    vector<vector<ll>> children(n);
    map<ll,ll> is_root;
    ll rob = -1;
    map<ll,ll> root;

    FOR(i,0,n){
        //
        if(rob == -1 || (is_root[rob] == 1 && destination[rob]<=position[i])){
            is_root[i] = 1;
            root[i] = 1;
            rob = i;
            continue;
        }
        if(destination[rob]>position[i]){
            parents[i] = rob;
            children[rob].push_back(i);
            rob = i;
        }
        else{
            rob = parents[rob];
            i--;
            continue;
        }
    }
    ll ans = 1;
    FORm(j,root){
        ans *= rec(j->first, position, children);
    }
    cout<<ans<<endl;

}