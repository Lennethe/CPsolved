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

    ll n,m,l;
    cin>>n>>m>>l;
    vector<ll> hair(n);
    cinv(hair,0,n);

    ll res=0;
    if(hair[0]>l)res++;
    FOR(j,1,n){
      if(hair[j]>l){
        res++;
        if(hair[j-1]>l)res--;
      }
    }

    FOR(i,0,m){
      ll in;
      cin>>in;
      if(in == 0){
        cout<<res<<endl;
        }

      else{
        ll in1,in2;
        cin>>in1>>in2;
        if(hair[in1-1]>l)continue;
        //cout<<"here"<<endl;
        hair[in1-1]+=in2;
        if(hair[in1-1]>l){
          res++;
          if(in1!=n && hair[in1]>l){
            res--;
          }
          if(in1!=1 && hair[in1-2]>l){
            res--;
          }
        }
      }
      //coutv(hair,0,n);
    }
}
