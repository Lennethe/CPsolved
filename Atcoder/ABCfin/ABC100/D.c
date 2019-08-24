#include <stdio.h>
#include <bits/stdc++.h>

#define ll long long

using namespace std;

int main(){

	int N,M;
	cin >> N >> M;

	vector<vector<ll>> vec = vector<vector<ll>>(N, vector<ll>(3,0)) ;

	for(int i=0; i<N; i++){
		for(int j=0; j<3; j++){
			cin >> vec.at(i).at(j);
		}
	}
	vector<ll> inst(N);

	ll res=0;
	ll S;
	for(int i=0; i<8; i++){
		int a=1,b=1,c=1;
		if(i<4)a=1;
		else a=-1;
		if((i%4)<2) b=1;
		else b=-1;
		if((i%2)<1) c=1;
		else c=-1;

		for(int j=0; j<N; j++){
			inst.at(j)= a*vec.at(j).at(0)+b*vec.at(j).at(1)+c*vec.at(j).at(2);
		}

		std::sort(inst.begin(),inst.end());

		S=0;

		for(int j=N-1; j>N-M-1; j--){
			S=inst.at(j)+S;
		}


		S=std::abs(S);
		if(S>res) res=S;
	}
	cout<< res << endl;



}
