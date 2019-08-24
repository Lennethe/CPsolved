#include<bits/stdc++.h>
using namespace std;

#define MAX 100002

int n;

vector<pair<int,int> > v;
priority_queue<pair<int,int> ,vector<pair<int,int> > , greater<pair<int,int> > > mint;
priority_queue<pair<int,int> > maxt;
bool used[MAX];


int main(){
	cin>>n;
	for(int i=0;i<n;i++){
		int l,r;
		scanf("%d%d",&l,&r);
		v.push_back(make_pair(l,r));
	}
	long long int ans=0;
	for(int k=0;k<2;k++){
		memset(used,false,sizeof(used));
	for(int i=0;i<n;i++){
		int l=v[i].first;
		int r=v[i].second;
		v.push_back(make_pair(l,r));
		mint.push(make_pair(l,i));
		maxt.push(make_pair(l,i));
		mint.push(make_pair(r,i));
		maxt.push(make_pair(r,i));
	}
	bool dir=k;
	long long int cur=0;
	int pos=0;
	while(true){
		if(dir==false){
			bool ok=false;
			while(!maxt.empty()){
				auto it=maxt.top();
				maxt.pop();
				if(it.first<pos)continue;
				if(v[it.second].first<=pos&&pos<v[it.second].second)continue;
				int dist=min(abs(v[it.second].first-pos),abs(v[it.second].second-pos));
				if(dist!=abs(it.first-pos))continue;
				if(used[it.second])continue;
				used[it.second]=true;
				cur+=2*it.first;
				pos=it.first;
				ok=true;
				break;
			}
			if(ok==false)break;
		}
		else{
			bool ok=false;
			while(!mint.empty()){
				auto it=mint.top();
				mint.pop();
				if(it.first>pos)continue;
				if(v[it.second].first<=pos&&pos<=v[it.second].second)continue;
				int dist=min(abs(v[it.second].first-pos),abs(v[it.second].second-pos));
				if(dist!=abs(it.first-pos))continue;
				if(used[it.second])continue;
				used[it.second]=true;
				cur-=2*it.first;
				pos=it.first;
				ok=true;
				break;
			}
			if(ok==false)break;
		}
		ans=max(ans,cur);
		dir^=true;
	}
}
	printf("%lld\n",ans);
	return 0;
}
