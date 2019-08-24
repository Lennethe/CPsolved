#include <stdio.h>
#include <bits/stdc++.h>

using namespace std;
using ll=long long;
using ld=long double;
using P=pair<ll,ll>;
#define FOR(i,n,m) for(ll i=n; i<(ll)m;i++)
#define FORr(i,n,m) for(ll i=n; i>(ll)m; i--)
#define FORm(i,m) for(auto i=m.begin();i!=m.end();i++)
#define VEC2(x,a,b) vector<vector<P>> x = vector<vector<P>>(a,vector<P>(b,P(0,0)))
#define sortAl(v) sort(v.begin(),v.end())
#define sortAlr(v) sort(v.begin(),v.end()); reverse(v.begin(),v.end())
#define cinv(v,n,m) FOR(i,n,m) cin>>v.at(i)
#define coutv(v,n,m) FOR(i,n,m) cout<<v.at(i) <<" "; cout<<endl
#define cout(n) cout<<fixed<<setprecision(n)
int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);

  queue<P> q;

  ll n,m,r,c,x,y;
  cin>>n>>m>>r>>c>>x>>y;
  vector<string> v(n);
  cinv(v,0,n);
  vector<vector<char>> laby = vector<vector<char>>(m,vector<char>(n,'.'));

  FOR(i,0,n){
    FOR(j,0,m){
      laby[j][i]=v[i][j];
    }
  }

  VEC2(step,m,n);
  step[c-1][r-1]=P(x,y);
  laby[c-1][r-1]='+';
  q.push(P(c-1,r-1));

  while(!q.empty()){
    ll lx,ly;
    lx=q.front().first;
    ly=q.front().second;
    q.pop();
    if(lx!=m-1&&laby[lx+1][ly]=='.' && step[lx][ly].second>0 ){
      laby[lx+1][ly]='+';
      q.push(P(lx+1,ly));
      step[lx+1][ly]=P(step[lx][ly].first,step[lx][ly].second-1);
    }
    if(lx!=0&&laby[lx-1][ly]=='.'&& step[lx][ly].first>0 ){
      laby[lx-1][ly]='+';
      q.push(P(lx-1,ly));
      step[lx-1][ly]=P(step[lx][ly].first-1,step[lx][ly].second);
    }

    if(ly!=n-1&&laby[lx][ly+1]=='.' ){
      laby[lx][ly+1]='+';
      q.push(P(lx,ly+1));
      step[lx][ly+1]=step[lx][ly];
    }
    if(ly!=0&&laby[lx][ly-1]=='.'){
      laby[lx][ly-1]='+';
      q.push(P(lx,ly-1));
      step[lx][ly-1]=step[lx][ly];
    }
   cout<<endl;
    FOR(j,0,n){
      FOR(i,0,m){
        //cout<<"("<<step[i][j].first<<","<<step[i][j].second<<")";
        cout<<laby[i][j];
      }
      cout<<endl;
    }

  }

  ll res=0;
  //cout<<endl;
  FOR(j,0,n){
    FOR(i,0,m){
      if(laby[i][j]=='+')res++;
    //  cout<<laby[i][j];
    }
  }
  cout<<res<<endl;



}
