#include <stdio.h>
#include <bits/stdc++.h>

using namespace std;
using ll=long long;
using ld=long double;
using P=pair<ll,ll>;
#define FOR(i,n,m) for(ll i=n; i<(ll)m;i++)
#define FORr(i,n,m) for(ll i=n; i>(ll)m; i--)
#define FORm(i,m) for(auto i=m.begin();i!=m.end();i++)
#define VEC2(x,a,b) vector<vector<ll>> x = vector<vector<ll>>(a,vector<ll>(b,0))
#define sortAl(v) sort(v.begin(),v.end())
#define sortAlr(v) sort(v.begin(),v.end()); reverse(v.begin(),v.end())
#define cinv(v,n,m) FOR(i,n,m) cin>>v.at(i)
#define coutv(v,n,m) FOR(i,n,m) cout<<v.at(i) <<" "; cout<<endl
#define cout(n) cout<<fixed<<setprecision(n)

ll di[8]={1,1,0,-1,-1,-1,0,1};
ll dj[8]={0,-1,-1,-1,0,1,1,1};

ll nx(vector<string> v, ll li, ll lj, ll turn){
  char c;
  if(turn%2==0) c='x';
  else c='o';

  ll res=0;
  FOR(d,0,8){
    ll x=1;

    if(li+x*di[d]<0 || 7<li+x*di[d] || lj+x*dj[d]<0 || 7<lj+x*dj[d]  )continue;
    while(v[li+x*di[d]][lj+x*dj[d]]==c){
      x++;

      if(li+x*di[d]<0 || 7<li+x*di[d] || lj+x*dj[d]<0 || 7<lj+x*dj[d]  )break;
    }

    if(li+x*di[d]<0 || 7<li+x*di[d] || lj+x*dj[d]<0 || 7<lj+x*dj[d]  )continue;

    if(v[li+x*di[d]][lj+x*dj[d]]!='.'&&v[li+x*di[d]][lj+x*dj[d]]!=c){
      res+=x-1;
    }
  }
  return res;
}


vector<string> nch(vector<string> v, ll li, ll lj, ll turn){
  char c;
  if(turn%2==0) c='o';
  else c='x';
  v[li][lj]=c;
  FOR(d,0,8){
    ll x=1;
    if(li+x*di[d]<0 || 7<li+x*di[d] || lj+x*dj[d]<0 || 7<lj+x*dj[d]  )continue;

    while(v[li+x*di[d]][lj+x*dj[d]]!=c&&v[li+x*di[d]][lj+x*dj[d]]!='.'){
      x++;
      if(li+x*di[d]<0 || 7<li+x*di[d] || lj+x*dj[d]<0 || 7<lj+x*dj[d]  ){
        x=0;
        break;
      }
      if(v[li+x*di[d]][lj+x*dj[d]]==c){
        break;
      }
      if(v[li+x*di[d]][lj+x*dj[d]]=='.'){
        x=1;
        break;
      }
    }
    FOR(j,0,x){
      v[li+j*di[d]][lj+j*dj[d]]=c;
    }

  }
    return v;

}

P toPut(vector<string> v, ll turn){
  ll li=0,lj=0,mres=0;
  FOR(i,0,8){
    FOR(j,0,8){
      if(v[i][j]=='.'){
        if(mres<nx(v,i,j,turn)&&turn%2==0){
          li=i;lj=j;
          mres=nx(v,i,j,turn);
        }
        if(mres<=nx(v,i,j,turn)&&turn%2==1){
          li=i;lj=j;
          mres=nx(v,i,j,turn);
        }

      }
    }
  }
  return P(li,lj);
}

int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);

  vector<string> v(8);
  cinv(v,0,8);
  FOR(i,0,150){
    P p = toPut(v,i);
    ll li=p.first;
    ll lj=p.second;
    if(nx(v,li,lj,i)!=0 && v[li][lj]=='.')v=nch(v,li,lj,i);
  }

  FOR(i,0,8){
    FOR(j,0,8){
      cout<<v[i][j];
    }
    cout<<endl;
  }

}
