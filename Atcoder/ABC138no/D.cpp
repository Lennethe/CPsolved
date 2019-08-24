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
    ll n,k;
    cin>>n>>k;
    vector<ll> v(n);
    vector<ll> v_t;
    FOR(i,0,n)cin>>v[i];
    v_t = v;
    reverse(v_t.begin(), v_t.end());

    vector<vector<ll>> l_mat(n+1,vector<ll>(n,0));
    vector<vector<ll>> r_mat(n+1,vector<ll>(n,0));
    vector<vector<ll>> l_v(n+1);
    vector<vector<ll>> r_v(n+1);
    ll tmp=0;
    ll tmp_t = 0;
    FOR(i,0,n){
      l_v[i+1] = l_v[i];
      l_v[i+1].emplace_back(v[i]);
      tmp += v[i];
      l_mat[i+1][0] = tmp;

      r_v[i+1] = r_v[i];
      r_v[i+1].emplace_back(v_t[i]);
      tmp_t += v_t[i];
      r_mat[i+1][0] = tmp_t;
    }
    FOR(i,1,n+1)sortAl(l_v[i]);
    FOR(i,1,n+1)sortAl(r_v[i]);

    FOR(i,1,n+1){
      FOR(j,1,i){
        l_mat[i][j] = l_mat[i][j-1] - l_v[i][j-1];
        r_mat[i][j] = r_mat[i][j-1] - r_v[i][j-1];
      }
    }
    vector<ll> l_ans(2*n+1,0);
    vector<ll> r_ans(2*n+1,0);

    FOR(j,0,n+1){
      FOR(i,0,n+1){
        l_ans[i+j] = max(l_ans[i+j], l_mat[i][j]);
        r_ans[i+j] = max(r_ans[i+j], r_mat[i][j]);
        cout<<r_mat[i][j]<<" ";
      }
      cout<<endl;
    }

    vector<ll> ans(5*n);
    FOR(i,0,2*n+1){
      FOR(j,0,2*n+1){
        ans[i+j] = max(ans[i+j], l_ans[i] + r_ans[j]);
      }
    }

    ll res = 0;
    FOR(i,0,k+1){
      res = max(res, ans[i]);
    }
    cout<<res<<endl;

//    FOR(i,0,2*n+1){
//      cout<<r_ans[i]<<" ";
//    }
//    cout<<endl;


}
