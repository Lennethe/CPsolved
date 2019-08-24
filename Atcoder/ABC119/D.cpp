#include <stdio.h>
#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define ld long double
#define  P pair<ll,ll>
#define FOR(i,n,m) for(ll i=n; i<(ll)m;i++)
#define FORr(i,m,n) for(ll i=n; i>=(ll)m; i--)
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
    ll a,b,q;
    cin>>a>>b>>q;
    vector<ll> shrine(a+2);
    vector<ll> temple(b+2);
    vector<ll> query(q);
    shrine[0] = 0;
    shrine[a+1] = 1e11;
    cinv(shrine,1,a+1);
    temple[0] = 0;
    temple[b+1] = 1e11;
    cinv(temple,1,b+1);
    cinv(query,0,q);
    vector<ll> res_key = query;

    sortAl(query);
    map<ll,ll> mp_res;

    map<ll,ll> mp_tem;
    map<ll,ll> mp_sh;
    ll t=0,s=0;
    while(s!=a+1 || t!=b+1){
      if(s==0) 
    }

    ll sh_r=1,sh_l=0, te_r=1, te_l = 0;
    FOR(i,0,q){
      ll po = query[i];
      while(shrine[sh_r] < po){
        sh_r++;
        sh_l++;
      }
      while(temple[te_r] < po){
        te_r++;
        te_l++;
      }
      ll tmp_sh = min(abs(shrine[sh_r] - po), abs(shrine[sh_l] - po));
      ll tmp_tem = min(abs(temple[te_r] - po), abs(temple[te_l] - po));
      if(sh_l == 0) tmp_sh = shrine[sh_r] - po;
      if(te_l == 0) tmp_tem = temple[te_r] - po;
      if(sh_r == a+1) tmp_sh = po - shrine[sh_l] ;
      if(te_r == b+1) tmp_tem = po - temple[te_l];

      cout<<"i="<<i<<endl;
      cout<<po<<endl;
      cout<<tmp_sh<<" "<<tmp_tem<<endl;
      cout<<endl;
      ll tmp_min = min(tmp_sh, tmp_tem);
      ll tmp_max = max(tmp_sh, tmp_tem);
      mp_res[po] = tmp_min*2 + tmp_max;
    }

    FOR(i,0,q){
      cout<<mp_res[res_key[i]]<<endl;
    }

}
