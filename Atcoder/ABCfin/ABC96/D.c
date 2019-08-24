#include <stdio.h>
#include <bits/stdc++.h>

using namespace std;



vector<int> primVec(int N){
	vector<int> res, vec;
	vec= vector<int>(N+1,1);
	for(int i=2; i<N+1; i++){
		if(vec.at(i)==1){
			for(int j = 0; i*(j+2)<N+1; j++){
				vec.at(i*(j+2))=0;
			}
		}
	}
	for(int i=2; i<N+1; i++){
		if(vec.at(i)==1) res.push_back(i);
	}
	return res;
}



int main(){
	int N;
	cin >> N;
	
	vector<int> vec = primVec(55555);
	vector<int> res;
	
	for(int i=0; i<1000 && (int)res.size()<N; i++){
		if(vec.at(i)%5 == 2) res.push_back(vec.at(i));
	}
	
	for(int i=0; i<N; i++){
		cout << res.at(i) << " " ;
	}
	cout << endl;
	
	
}



