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
void read(vector<ll> &arr){
	for(ll i = 0 ; i < arr.size() ; i++){
		cin>>arr[i];
	}
}
void sort(vector<ll> &arr){
	sort(arr.begin(),arr.end());
}

void print(const vector<ll> arr){
	for(ll i = 0 ; i < arr.size() ; i++){
		cout<<arr[i]<<" ";
	}
	cout<<"\n";
}

void solve(){
	ll n,k;
	cin>>n>>k;
	vector<ll> arr(n);
	read(arr);
	sort(arr);
	
	for(int i = n-2 ; i >=0 && k>0; i--){
		if(arr[i] != 0){
			arr[n-1] += arr[i];
			arr[i] = 0;
			k--;
		}
	}
	//print(arr);
	cout<<arr[n-1]<<"\n";

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
