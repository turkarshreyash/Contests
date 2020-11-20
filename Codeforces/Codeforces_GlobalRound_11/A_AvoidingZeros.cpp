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
	int n, temp;
	cin>>n;
	vector<int> positive;
	vector<int> zeros;
	vector<int> negative;
	int summ = 0;
	for(int i = 0 ; i < n ; i++){
		cin>>temp;
		if(temp >0){
			positive.push_back(temp);
		}else if(temp < 0){
			negative.push_back(temp);
		}else{
			zeros.push_back(temp);
		}
		summ+=temp;
	}
	sort(negative.begin(),negative.end(),greater<int>());
	if(summ==0){
		cout<<"NO\n";
		return;
	}
	cout<<"YES\n";
	if(summ>0){
		for(const int &i : positive){
			cout<<i<<" ";
		}
		for(const int &i : zeros){
			cout<<i<<" ";
		}
		for(const int &i : negative){
			cout<<i<<" ";
		}
	}else{
		for(const int &i : negative){
			cout<<i<<" ";
		}
		for(const int &i : zeros){
			cout<<i<<" ";
		}
		for(const int &i : positive){
			cout<<i<<" ";
		}
	}

	cout<<"\n";
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
