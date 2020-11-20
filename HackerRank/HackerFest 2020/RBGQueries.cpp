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

1 3 5
5 3 1

5 3 5
3 3 3
*/
typedef struct MyClassLessThan
{
	bool operator()(vector<int> &a,  vector<int> &b){
		if(a[0] < b[0]){
			return true;
		}else if(a[0] > b[0]){
			return false;
		}else{
			if(a[1] < b[1]){
				return true;
			}else if(a[1] > b[1]){
				return false;
			}else{
				if(a[2]<b[2]){
					return true;
				}
				return false;
			}
		}
	}	
	
	bool operator()(vector<int> a, int b){
		if(a[0]<b){
			return true;
		}
		return false;
	}
	
	bool operator()(int a, vector<int>b){
		if(a<b[0]){
			return true;
		}
		return false	;
	}
}MyClassLessThan;




void solve(){
	int n,q;
	cin>>n>>q;
	int r,b,g;
	unordered_map<int,set<pair<int,int>>> redBucket, blueBucket, greenBucket;
	for(int i = 0 ; i < n ; i++){
		cin>>r>>b>>g;
		redBucket[r].insert(make_pair(b,g));
		blueBucket[b].insert(make_pair(g,r));
		greenBucket[g].insert(make_pair(r,b));
	}
	
	
	int end;
	bool found;
	for(int i = 0 ; i < q ; i++){
		cin>>r>>b>>g;
		
		if(redBucket.find(r) == redBucket.end()){
			cout<<"NO\n";
			continue;
		}
		found = false;
		for(auto i: redBucket[r]){
			if(i.first > b){
				break;
			}
			if(i.first <= b && i.second <= g){
				found = true;
				break;
			}
		}
		if(!found){
			cout<<"NO\n";
			continue;
		}
		
		
		
		if(blueBucket.find(b) == blueBucket.end()){
			cout<<"NO\n";
			continue;
		}
		found = false;
		for(auto i: blueBucket[b]){
			if(i.first > g){
				break;
			}
			if(i.first <= g && i.second <= r){
				found = true;
				break;
			}
		}
		if(!found){
			cout<<"NO\n";
			continue;
		}
		
		if(greenBucket.find(g) == greenBucket.end()){
			cout<<"NO\n";
			continue;
		}
		found = false;
		for(auto i: greenBucket[g]){
			if(i.first > r){
				break;
			}
			if(i.first <= r && i.second <= b){
				found = true;
				break;
			}
		}
		if(!found){
			cout<<"NO\n";
			continue;
		}
		
		
		cout<<"YES\n";
		
	
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
