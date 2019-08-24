#include <stdio.h>
#include <bits/stdc++.h>

using namespace std;

int main(){
	
	int a,b;
	
	cin >> a >> b ;
	
	if( b < 15){
		cout << "C 0" << endl;
	}
	else{
		if(112.5 <= a && a < 337.5) cout << "NNE ";
		else if(337.5 <= a && a < 562.5) cout << "NE ";
		else if(562.5 <= a && a < 787.5) cout << "ENE ";
		else if(787.5 <= a && a < 1012.5) cout << "E ";
		else if(1012.5 <= a && a < 1237.5) cout << "ESE ";
		else if(1237.5 <= a && a < 1462.5) cout << "SE ";
		else if(1462.5 <= a && a < 1687.5) cout << "SSE ";
		else if(1687.5 <= a && a < 1912.5) cout << "S ";
		else if(1912.5 <= a && a < 2137.5) cout << "SSW ";
		else if(2137.5 <= a && a < 2362.5) cout << "SW ";
		else if(2362.5 <= a && a < 2587.5) cout << "WSW ";
		else if(2587.5 <= a && a < 2812.5) cout << "W ";
		else if(2812.5 <= a && a < 3037.5) cout << "WNW ";
		else if(3037.5 <= a && a < 3262.5) cout << "NW ";
		else if(3262.5 <= a && a < 3487.5) cout << "NNW ";
		else cout << "N " ;
		
		if ( b < 93) cout << "1" << endl;
		else if ( b < 201) cout << "2" << endl;
		else if ( b < 327) cout << "3" << endl;
		else if ( b < 477) cout << "4" << endl;
		else if ( b < 645) cout << "5" << endl;
		else if ( b < 831) cout << "6" << endl;
		else if ( b < 1029) cout << "7" << endl;
		else if ( b < 1245) cout << "8" << endl;
		else if ( b < 1467) cout << "9" << endl;
		else if ( b < 1707) cout << "10" << endl;
		else if ( b < 1959) cout << "11" << endl;
		else  cout << "12" << endl;
		
		
	}
}