#include <stdio.h>
#include <bits/stdc++.h>

using namespace std;

int main(){
	
	int a,b,c,d;
	
	cin >> a >> b >> c >> d;
	
	if( std::abs(a-c) <= d) cout << "Yes" << endl;
	
	else if( std::abs(a-b) <= d && std::abs(c-b) <= d) cout << "Yes" << endl;
	
	else cout << "No" << endl;
}
