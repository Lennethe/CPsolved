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

    vector<P> v(3);
    FOR(i,0,3){
      ll x,y;
      cin>>x>>y;
      v[i]=make_pair(x,y);
    }
    sortAl(v);

    ll res=0;
    res+=v[2].first-v[0].first;
    res+=max(max(v[0].second,v[1].second),v[2].second)
        -min(min(v[0].second,v[1].second),v[2].second);
    cout<<res+1<<endl;

    ll po_x=v[0].first;
    ll po_y=v[0].second;
    while(po_x!=v[1].first){
      cout<<po_x<<" "<<po_y<<endl;
      po_x++;
    }
    ll dir=1;
    if(v[0].second > v[1].second) dir=-1;
    while(po_y!=v[1].second){
      cout<<po_x<<" "<<po_y<<endl;
      po_y += dir;
    }
    cout<<po_x<<" "<<po_y<<endl;
    ll max_y=max(v[0].second, v[1].second);
    ll min_y=min(v[0].second, v[1].second);

    if(v[2].second>max_y){
      po_y=max_y;
      dir = 1;
    }
    else if(v[2].second<min_y){
      po_y=min_y;
      dir = -1;
    }
    else po_y=v[2].second;

    while(po_x!=v[2].first){
      po_x++;
      cout<<po_x<<" "<<po_y<<endl;
    }
    while(po_y!=v[2].second){
      po_y+=dir;
      cout<<po_x<<" "<<po_y<<endl;
    }


}
