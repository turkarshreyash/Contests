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

/*
2


*/


void solve(){
	int n, k;
	cin>>n>>k;
	string s;
	cin>>s;
	int start = 0, end = n-1, trailling;
	
	while(start < n && s[start] != 'W'){
		start++;
	}
	if(start == n && k >0){
		cout<<min(k,start)*2-1<<"\n";
		return;
	}
	
	
	while(s[end] != 'W'){
		end--;
	}
	
	trailling = start+(n-1-end);
	end++;
	int i = start, count;
	vector<int> trapped;
	int score = 0;
	while(i<end){
		count = 0;
		while(i<end && s[i] != 'L'){
			i++;
			count++;
		}
		
		score += max(count*2-1,0);
		if(i>=end){
			break;
		}
		count = 0;
		while(i<end && s[i] != 'W'){
			count++;
			i++;
		}
		trapped.push_back(count);
	}
	
	sort(trapped.begin(),trapped.end());
	for(int t: trapped){
		if(k<=0){
			break;
		}
		
		if(k>=t){
			score += 2*t+1;
			k-=t;
		}else{
			score += 2*k;
			k = 0;
		}
	}
	
	if(k>0){
		score += 2*min(trailling,k);
	}
	cout<<score<<"\n";	
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
