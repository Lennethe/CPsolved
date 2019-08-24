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
  vector<string> laby(n);
  cinv(laby,0,n);

  VEC2(step,n,m);
  step[r-1][c-1]=P(x,y);
  laby[r-1][c-1]='+';
  q.push(P(r-1,c-1));

  cout<<endl;
  FOR(i,0,n){
    FOR(j,0,m){
  //    if(laby[i][j]=='+')res++;
      cout<<laby[i][j];
    }
    cout<<endl;
  }

  while(!q.empty()){
    ll lx,ly;
    ly=q.front().first;
    lx=q.front().second;
    q.pop();
    if(lx!=n-1&&laby[ly][lx+1]=='.' && step[ly][lx].second>0){
      laby[ly][lx+1]='+';
      q.push(P(lx+1,ly));
      step[ly][lx+1]=P(step[ly][lx].first,step[ly][lx].second-1);
      cout<<"w"<<endl;
    }
    if(lx!=0&&laby[ly-1][lx]=='.' && step[ly][lx].first>0){
      laby[ly][lx-1]='+';
      q.push(P(lx-1,ly));
      step[ly][lx-1]=P(step[ly][lx].first-1,step[ly][lx].second);
      cout<<"d"<<endl;
    }

    if(ly!=m-1&&laby[ly+1][lx]=='.' ){
      laby[ly+1][lx]='+';
      q.push(P(lx,ly+1));
      step[ly+1][lx]=step[ly][lx];
      cout<<"f"<<endl;
    }
    if(ly!=0&&laby[ly-1][lx]=='.' ){
      laby[ly-1][lx]='+';
      q.push(P(lx,ly-1));
      step[ly-1][lx]=step[ly][lx];
      cout<<"v"<<endl;
    }
    cout<<endl;
    FOR(i,0,n){
      FOR(j,0,m){
    //    if(laby[i][j]=='+')res++;
        cout<<laby[i][j];
      }
      cout<<endl;
    }
  }

  ll res=0;
  cout<<endl;
  FOR(i,0,n){
    FOR(j,0,m){
      if(laby[i][j]=='+')res++;
      cout<<laby[i][j];
    }
    cout<<endl;
  }
  cout<<res<<endl;



}
