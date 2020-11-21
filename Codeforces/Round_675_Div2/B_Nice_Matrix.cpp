/*
Shreyash H. Turkar
*/
/*

4 2
2 4
4 2
2 4

x: 2
y: 1
 
n-x: 1
m-y: 0



a1 b2 b3 a4
c5 d6 d7 c8
a9 b10 b11 18



1 4 9
*/

#include<iostream>
#include<vector>
#include<unordered_map>
#include<map>
#include<unordered_set>
#include<set>
#include<algorithm>
#include<utility>

//#define SINGLE_TEST_CASE

#define ll long long

const int maxN = 100;
const ll inf = 1e9+1;

int arr[maxN][maxN];
int equalise[4];

int max(int a, int b, int c){
	return (a>b&&a>c)? a: (c>b)?c:b;
}

void solve(){
	ll n,m;
	std::cin>>n>>m;
	for(int i = 0 ; i < n ; i++){
		for(int j = 0 ; j < m ; j++){
			std::cin>>arr[i][j];
		}
	}
	int tr, tl, br, bl;
	// tr = i, j
	// tl = i, m-j-1
	// br = n-i-1, j
	// bl = n-i-1, m-j-1
	ll count = 0;

	for(int i = 0 ; i < (n+1)/2 ; i++){
		for(int j = 0 ; j < (m+1)/2 ; j++){
			
			equalise[0] = arr[i][j];
			if(i==n-1-i && j==m-j-1){
				continue;
			}
			equalise[1] = arr[n-i-1][m-j-1];
			if(i!=n-1-i && j!=m-j-1){
				equalise[2] = arr[i][m-j-1];
				equalise[3] = arr[n-i-1][j];
				std::sort(equalise,equalise+4);
				count += equalise[3]-equalise[0]+equalise[2]-equalise[1];
			}else{
				count += abs(equalise[0]-equalise[1]);
			}
		}
	}
	
	std::cout<<count<<"\n";
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
