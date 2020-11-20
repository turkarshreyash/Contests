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
#include<iterator>
using namespace std;

#define ll long long
#define INF      LLONG_MAX	
#define NEG_INF  LLONG_MIN


//#define SINGLE_TEST_CASE

/*

1) 1 <= N <= 10^3  O(n^2) 
2) 1 <= N <= 10^5  O(nlogn)
3) 1 <= N <= 10^8  O(n)

*/




void solve(){
	int n;
	cin>>n;
	vector<int> arr;
	for(int i = 1; i <= n ; i++){
		arr.push_back(i);
	}
	cout<<"2\n";
	if(n <= 2){
		if(n == 2){
			cout<<"1 2\n";
			return;
		}else if(n == 3){
			cout<<"1 3\n2 2\n";
			return;
		}else{
			cout<<"2 4\n3 3\n3 1\n";
			return;
		}
	}
	for(int i = n-1 ; i > 0; i--){
		if((arr[i]%2) == (arr[i-1]%2)){
			cout<<arr[i]<<" "<<arr[i-1]<<"\n";
			arr[i-1] = (arr[i-1]+arr[i])/2;
		}else{
			cout<<arr[i]<<" "<<arr[i-2]<<"\n";
			arr[i-2] = (arr[i]+arr[i-2])/2;
		}
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
