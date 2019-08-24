#include <stdio.h>
#include <bits/stdc++.h>

using namespace std;

int main(){

	int a, output,inst, flag;
	string b,result;
	output = 0;
	inst = 0;
	
	cin >> a >> b;
	for (int i=0; i<a; i++){
		int inter = i+1;
		for(int k=0; k<=i; k++){
		
			flag = 0;
			for(int j=inter; j<a; j++){
				if(b.at(k) == b.at(j)){
					flag = 1;
				}
			}
			if(flag == 1)result = result + b.at(k);
			
		}
		
		for(int k=0; std::abs(k)<result.size(); k++){
			
			flag = 0;
			for(int l=k-1; l >= 0; l--){
				if(result.at(k) == result.at(l)) flag = 1;
				
			}
			if(flag == 0) output++;
		}
		
		if(inst <= output) inst = output;
		output = 0;
	
		
		result = "";
	}
		cout << inst << endl;

}

