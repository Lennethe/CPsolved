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
    ll a,b,c;
    cin>>a>>b>>c;
    vector<ll> av(a),bv(b),cv(c);
    FOR(i,0,a)cin>>av[i];
    FOR(i,0,b)cin>>bv[i];
    FOR(i,0,c)cin>>cv[i];
    vector<ll> v(a+b+c+1);
    sortAl(av);
    sortAl(bv);
    sortAl(cv);
    ll p = 1;
    FOR(i,0,a){
        v[av[i]] = p;
        p++;
    }
    FOR(i,0,b){
        v[bv[i]] = p;
        p++;
    }
    FOR(i,0,c){
        v[cv[i]] = p;
        p++;
    }
    vector<ll> ans(a+b+c+1);
    FOR(i,1,v.size()){
        if(v[i-1]<v[i]){
            ans[i] = ans[i-1]+1;
        }
        else{
            FORr(j,0,i){
                if(v[j]<v[i]){
                    ans[i] = ans[j]+1;
                    break;
                }
            }
        }
    }
    ll x = 0;
    FOR(i,1,v.size()){
        x = max(x,ans[i]);
        cout<<ans[i]<<" ";

    }    
    cout<<a+b+c-x-1<<endl;
    
    

    
}