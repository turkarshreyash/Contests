/*
Shreyash H. Turkar
*/
#include<iostream>
#include<vector>
#include<unordered_map>
#include<map>
#include<unordered_set>
#include<set>
#include<string.h>
#include<algorithm>
#include<utility>
#include<cmath>
#include<climits>
#include<stdint.h>

using namespace std;

#define USE_LL 

#ifdef USE_LL
#define ll       long long 
#define INF      LLONG_MAX	
#define NEG_INF  LLONG_MIN
#else
#define ll       int
#define INF      INT_MAX
#define NEG_INT  INT_MIN
#endif

#define MOD      (ll)(10e9+7)


#define SINGLE_TEST_CASE


/*
12345

00001
00010
00011
00100
00101
00110
00111
01000
01001
01010
01011
01100
01101
01110
01111

10000
10001
10010
10011
10100
10101
10110
10111
11000
11001
11010
11011
11100
11101
11110

-----
11111



*/


#define MUL(A,B) (((A%MOD)*(B%MOD))%MOD)
#define ADD(A,B) (((A%MOD)+(B%MOD))%MOD)
#define SUB(A,B) (((A%MOD)-(B%MOD))%MOD)

void solve(){
	string s;
	cin>>s;
	ll n = s.length();
	ll subtract = 0;
	ll sum = 0, temp;
	
	vector<ll> pow_2(n);
	vector<ll> pow_11(n);
	
	pow_11[n-1] = 1;
	pow_2[0] = 1;
	for(ll i = 1 ; i < n ; i++){
		pow_11[n-1-i] = MUL(pow_11[n-i],11);
		pow_2[i] = MUL(pow_2[i-1],2);
	}
	for(ll i = 0; i <n ; i++){
		cout<<"i:"<<i<<" pow_2:"<<pow_2[i]<<" pow_11:"<<pow_11[i]<<"\n";
		temp = MUL(pow_2[i],pow_11[i]);
		temp = MUL(temp,s[i]-'0');
		sum = ADD(sum,temp);
		
		subtract = MUL(10,subtract);
		subtract = ADD(subtract,s[i]-'0');
	}
	cout<<"sum:"<<sum<<" subtract:"<<subtract<<"\n";
	cout<<sum-subtract<<"\n";
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
