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

#define SINGLE_TEST_CASE

/*

1) 1 <= N <= 10^3  O(n^2) 
2) 1 <= N <= 10^5  O(nlogn)
3) 1 <= N <= 10^8  O(n)

*/


/*

10011000

10011000

*/

void solve(){
	string s;
	cin>>s;
	int start = 0, n = s.length();
	if(n==1){
		cout<<s[0]-'0'-1<<"\n";
		return;
	}
	while(s[start] != '1' && start < n){
		start++;
	}
	if(start == n){
		cout<<"-1\n";
		return;
	}
	int end = n-1;
	while(s[end] != '1' && end>start){
		end--;
	}
	int trailling = start + n-1-end;
	end++;
	int i = start, maxx = 0, count;
	while(i<end){
		//skip 1s
		while(s[i] != '0' && i < end){
			i++;
		}
		if(i>=end){
			break;
		}
		count = 0;
		while(s[i] != '1' && i<end){
			count++;
			i++;
		}
		maxx = max(maxx,count);
	}
	maxx = max(trailling,maxx);
	cout<<maxx<<"\n";
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
