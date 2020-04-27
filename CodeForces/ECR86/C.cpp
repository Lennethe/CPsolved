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

ll gcd(ll a, ll b) { return b ? gcd(b, a%b) : a; }	//最大公約数(Greatest Common Divisor)
ll lcm(ll a, ll b) { return a/gcd(a,b)*b; }			//最小公倍数(Least Common Multiple)

ll solve(ll a, ll b, ll v){
    ll l = lcm(a,b);
    ll round = 0;
    ll ans = 0;
    FOR(i,1,l+1){
        if(i%a%b != i%b%a)round++;
    }
    FOR(i,1,v%l+1){
        if(i%a%b != i%b%a)ans++;
    }
    return ans + v/l*round;
}
int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll t; cin>>t;
    while(t--){
        ll a,b,q; cin>>a>>b>>q;

        ll l = lcm(a,b);
        ll round = 0;
        vector<ll> v(l+1);
        FOR(i,1,l+1){
            if(i%a%b != i%b%a){
                round++;
                v[i]++;
            }
            v[i]+=v[i-1];
        }
        vector<ll> ans;
        while(q--){
            ll li,ri; cin>>li>>ri;
            ll la = v[(li-1+l)%l] + (li-1)/l*round;
            ll ra = v[(ri+l)%l] + ri/l*round;            
            ans.push_back(ra-la);
        }
        v1out(ans);
    }
}