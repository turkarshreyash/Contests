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

	 ll n, k, carryForwardQ = 0, q;
	 cin>>n>>k;
	 for(ll i = 0LL ; i < n ; i++){
		cin>>q;
		if(q+carryForwardQ < k){
			cout<<i+1LL;
			return;
		}
		carryForwardQ+=q-k;
	}
	cout<<(carryForwardQ/k)+(n+1LL);
}


int main(int argc, char *args[]){
	#ifdef SINGLE_TEST_CASE
	solve();
	#else
	ll t;
	std::cin>>t;
	while(t--){
		solve();
		cout<<endl;
	}	
	#endif
}
