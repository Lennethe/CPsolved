#include <stdio.h>
#include <bits/stdc++.h>

using namespace std;

int main(){
	
	int a, result;
	cin >> a ;
	vector<long long> vec1(a+1);
	vector<long long> vec2(a+1);
	result = 0;
	//xo=0;
	//x=0;
	//sum=0;
	
	vec1.at(0) = 0;
	vec2.at(0) = 0;
	for(int i=1; i<a+1; i++){
		cin >> vec1.at(i);
	}
	for(int i=1; i<a+1; i++){
		vec2.at(i) = std::bit_xor<>()(vec1.at(i), vec2.at(i-1));
		vec1.at(i) = vec1.at(i) + vec1.at(i-1);
	}
	
	
	for(int i=1; i<a+1; i++){
		
		for(int j=0; j<i; j++){
			
			if( std::bit_xor<>()(vec2.at(j), vec2.at(i)  ) == vec1.at(i) - vec1.at(j) ){
				result++;
			}
			
		}
		
	}
	
	
	cout << result << endl;
	
	
}
