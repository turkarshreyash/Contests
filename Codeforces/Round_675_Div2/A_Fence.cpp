/*
Shreyash H. Turkar
*/
#include<iostream>
#include<vector>
#include<unordered_map>
#include<map>
#include<unordered_set>
#include<set>
#include<algorithm>
#include<utility>

#include <cmath> 

//#define SINGLE_TEST_CASE

#define ll long long


void solve(){
	ll a,b,c, temp;
	std::cin>>a>>b>>c;
	if(c==a){
		std::cout<<b;
		return;
	}
	if(a>c){
		temp = a;
		a = c;
		c = temp;
	}
	double th = acos(a/c);
	std::cout<<b+int(c*sin(th));
}

int main(int argc, char *args[]){
	#ifdef SINGLE_TEST_CASE
	solve();
	#else
	ll t;
	std::cin>>t;
	while(t--){
		solve();
		std::cout<<"\n";
	}	
	#endif
}
