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

*/

void solve(){	
	int n;
	cin>>n;
	vector<vector<vector<int>>> arr(4,vector<vector<int>>(n+1,vector<int>(3)));
	vector<vector<bool>> dp(4,vector<bool>(n+1,false));
	arr[0][0][0] =  arr[0][0][1] = arr[0][0][2] = 0;
	dp[0][0] = true;
	int num;
	for(int i = 1 ; i < 4 ; i++){
		num = 2*i+1;
		for(int j =  0 ; j <= n ; j++){
			if(j-num >= 0 && dp[i-1][j-num]){
				for(int k = 0 ; k < 3 ; k++){
					arr[i][j][k] = arr[i-1][j-num][k];
				}
				arr[i][j][i-1]++;
				//cout<<"i:"<<i<<"\n";
				dp[i][j] = true;
			}else if(j-num >= 0 && dp[i][j-num]){
				for(int k = 0 ; k < 3 ; k++){
					arr[i][j][k] = arr[i][j-num][k];
				}
				arr[i][j][i-1]++;
				dp[i][j] = true;
			}
			else if(dp[i-1][j]){
				for(int k = 0 ; k < 3 ; k++){
					arr[i][j][k] = arr[i-1][j][k];
				}
				dp[i][j] = true;
			}
		}
	}
	/*
	for(int i = 0 ; i <= n ; i++){
		cout<<"\t"<<i<<"\t";	
	}
	cout<<"\n";
	for(int i = 0 ; i < 4 ; i++){
		cout<<2*i+1<<"\t";
		for(int j = 0 ; j <= n ; j++){
			cout<<dp[i][j]<<" [";
			for(int k = 0 ; k < 3 ; k++){
				cout<<arr[i][j][k]<<",";
			}
			cout<<"] ";
		}
		cout<<"\n";
	
	}
	*/
	if(dp[3][n]){
		for(int i = 0 ; i < 3 ; i++){
			cout<<arr[3][n][i]<<" ";
		}
	}else{
		cout<<-1;
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
