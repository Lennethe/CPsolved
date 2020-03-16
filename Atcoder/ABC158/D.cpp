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
#define dout(n) cout<<# n<<" = "<<n<<endl;
    
int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    string s;
    cin>>s;
    ll q;
    cin>>q;
    string h,t;
    ll is_even = 0;
    FOR(i,0,q){
        ll in;
        cin>>in;
        if(in == 1) is_even = (is_even+1)%2;
        else{
            ll f;
            char c;
            cin>>f>>c;
            if((is_even+f)%2==0)t.push_back(c);
            else h.push_back(c);
        }
    }
    string ans;
    reverse(h.begin(),h.end());
    ans = h + s + t;
    if(is_even==1){
        reverse(ans.begin(),ans.end());
    }
    cout<<ans<<endl;
}