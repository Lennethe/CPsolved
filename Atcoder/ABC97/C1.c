#include <stdio.h>
#include <bits/stdc++.h>

using namespace std;

int main(){
	
	
	string s,sum;
	int K;
	
	cin >> s >> K;
	
	vector<string> vec;
	
	for(int i=0; std::abs(i)<s.size(); i++){
		
		sum = "";
		for(int j=0; j<5 && std::abs(j+i)<s.size(); j++){
			sum = sum + s.at(i+j);
			vec.push_back(sum);
		}
	}
	std::sort(vec.begin(), vec.end());
		
	for(int j=1; j<K; j++){
		
		if(vec.at(j-1) == vec.at(j)) K++;
		
		}
		
	
	
	cout << vec.at(K-1) << endl;
	
	
	
}
