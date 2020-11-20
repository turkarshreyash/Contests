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

*/

/*
add of adjacent numbers should not be 0

we have n numbers
1........n

0001 -> 1
0010 -> 2
0011 -> 3

0100 -> 4
0101 -> 5

0110 -> 6
0111 -> 7

1000 -> 8
1001 -> 9
1010 -> 10
1011 -> 11
1100 -> 12



2 3 1 
*/


void solve(){
	int n;
	cin>>n;
	if(n == 1){
		cout<<1;
		return;
	}
	//cout<<"n:"<<n<<" n-1:"<<n-1<<" n&(n-1):"<<(n&(n-1))<<"\n";
	if((n&(n-1)) == 0){
		cout<<-1;
		return;
	}
	
	vector<int> arr(n);
	int j = 3;
	
	arr[0] = 2;
	arr[1] = 3;
	arr[2] = 1;

	int e = 4;
	
	while(j<n){
		arr[j] =  e+1;
		j++;
		arr[j] = e;
		j++;
		e+=2;
		for(;e&(e-1) && j<n;e++,j++){
			arr[j] = e;
		}	
	}
	for(int i = 0 ; i < n ; i++){
		cout<<arr[i]<<" ";
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
		cout<<endl;
	}	
	#endif
}
