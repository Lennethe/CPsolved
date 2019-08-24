#include <stdio.h>
#include <bits/stdc++.h>
#define cout(n) cout<<fixed<<setprecision(n)
using namespace std;


int main(){
  int n,m;
  cin>>n>>m;

  vector<int> alice(n,0);
  vector<vector<int>> vec = vector<vector<int>>(m,vector<int>(2,0));

  for(int i=0; i<m; i++){
    cin>>vec[i][0]>>vec[i][1];
  }

  int x=0;
  int y=0;
  for(int i=0; i<m; i++){
    x=x+vec[i][0];
    y=y+vec[i][1];

  }
  //cout<<"x="<<x<<" y="<<y<<endl;
  double res=0;
  int pos=0;
  if(y<0)pos=(m/2);

  for(int i=0; i<n; i++){
    res=res+y*(std::abs(pos-i));
  }

  //cout<<res<<endl;
  res=res+(x*n);

  //cout<<res<<endl;
  res=res/n;
  cout(13)<<res<<endl;
}
