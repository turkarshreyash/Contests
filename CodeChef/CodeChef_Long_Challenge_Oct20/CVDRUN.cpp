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
#include<cmath>
#include<climits>

using namespace std;

#define ll long long
#define INF      LLONG_MAX	
#define NEG_INF  LLONG_MIN


//#define SINGLE_TEST_CASE










void solve(){
	ll n, k, x, y;
	cin>>n>>k>>x>>y;
	unordered_set<ll> visited;
	ll currentLocation = x;
	
	// when visiting 
	while(currentLocation != y && visited.find(currentLocation) == visited.end()){
		visited.insert(currentLocation);
		currentLocation += k;
		currentLocation %= n;
	}
	if(currentLocation == y){
		cout<<"YES";
	}else{
		cout<<"NO";
	}
}


int main(int argc, char *args[]){
	#ifdef SINGLE_TEST_CASE
	solve();
	#else
	ll t;
	std::cin>>t;
	while(t--){
		solve();
		cout<<"\n";
	}	
	#endif
}
