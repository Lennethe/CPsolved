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
	
	std::sort(vec.begin(), vec.end());
	
	cout<< std::abs(vec.at(N-1) - vec.at(0)) << endl;
	
}
