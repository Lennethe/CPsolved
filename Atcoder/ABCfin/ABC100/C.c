#include <stdio.h>
#include <bits/stdc++.h>

using namespace std;

int main(){
	
	
	int N;
	cin >> N;
	vector<int> vec(N);
	
	
	for(int i=0; i<N; i++){
		cin>>vec.at(i);
	}
	
	int res = 0;
	for(int i=0; i<N; i++){
		
		while(vec.at(i)%2 == 0){
			vec.at(i) = vec.at(i)/2;
			res++;
		}
		
	}
	
	cout << res << endl;
}
