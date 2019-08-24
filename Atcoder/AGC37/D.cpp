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
    ll n,m;
    cin>>n>>m;
    vector<vector<P>> v(n,vector<P>(m));
    FOR(i,0,n){
      FOR(j,0,m){
        ll in;
        cin>>in;
        in--;
        v[i][j] = P(in/m+1,in%m+1);
      }
    }

    map<P,ll> unrock;
    FOR(i,0,n){
      FOR(j,0,m){
        unrock[P(i,j)] = 1;
      }
    }
    while(unrock.size() != 0){
      queue<ll> q;
      ll x = 0;
      FORm(p,unrock){
        x = p->first.first;
        break;
      }
      FORm(p,unrock){
        if(p->first.first != x)break;
        q.push(p->first.second);
      }
      ll q1 = q.front();
      q.pop();
      ll q2 = 0;
      while(!q.empty()){
        q2 = q1;
        q1 =q.front();
        q.pop();
        P tmp = v[x][q1];
        v[x][q1] = v[x][q2];
        v[x][q2] = tmp;
      }

      FOR(j,0,m){
        vector<ll> tmp(n+1);
        FOR(i,0,n){
          ll a = v[i][j].first;
          tmp[a]++;
        }
        FOR(i,0,n){
          ll a = v[i][j].first;
          if(tmp[a] == 1){
            unrock.erase(P(i,j));
          }
        }
      }
    }


    FOR(i,0,n){
      FOR(j,0,m){
//        cout<<"("<<v[i][j].first<<" , "<<v[i][j].second<<" )"<<" ";
        cout<<(v[i][j].first-1)*m+v[i][j].second<<" ";
      }
      cout<<endl;
    }

    FOR(j,0,m){
      vector<P> tmp_v(n);
      FOR(i,0,n){
        ll it = v[i][j].first-1;
        tmp_v[it] = v[i][j];
      }
      FOR(i,0,n){
        v[i][j] = tmp_v[i];
      }
    }

    FOR(i,0,n){
      FOR(j,0,m){
    //    cout<<"("<<v[i][j].first<<" , "<<v[i][j].second<<" )"<<" ";
        cout<<(v[i][j].first-1)*m+v[i][j].second<<" ";
      }
      if(i != n-1)cout<<endl;
    }




}
