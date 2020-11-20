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

/*

1) 1 <= N <= 10^3  O(n^2) 
2) 1 <= N <= 10^5  O(nlogn)
3) 1 <= N <= 10^8  O(n)

1. Player will only remove the repeating if the other will get at least one repeative

eachplayer 
	if count>1:
		safe to remove the repeating number
   	elif nr-count > 0:
   		remove any other number
	else:
		remove the repeating number 

*/




void solve(){
	int n;
	cin>>n;
	vector<int> arr(n);
	for(int i = 0 ; i < n ; i++){
		cin>>arr[i];
	}
	
	sort(arr.begin(),arr.end());
	int count = 0;
	
	for(int i = 1 ; i < n ; i++){
		if(arr[i] == arr[i-1]){
			count += 1;
		}
	}
	if(count == 0){
		cout<<"First\n";
		return;
	}
	int nr = n-count;
	bool playerFirst = true;

	while(count != 0){
		if(count>1){
			count--;
		}else if(nr>0){
			nr--;
		}else{
			count--;
		}
		playerFirst = !playerFirst;
	}
	if(playerFirst){
		cout<<"Second\n";
	}else{
		cout<<"First\n";
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
	}	
	#endif
}
