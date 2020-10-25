/*
Shreyash H. Turkar
*/
#include <iostream>
#include <vector>
#include <unordered_map>
#include <map>
#include <unordered_set>
#include <set>
#include <algorithm>
#include <utility>
#include <cmath>
#include <climits>
#include <iterator>
using namespace std;

#define ll long long
#define INF LLONG_MAX
#define NEG_INF LLONG_MIN

//#define SINGLE_TEST_CASE

/*

1) 1 <= N <= 10^3  O(n^2) 
2) 1 <= N <= 10^5  O(nlogn)
3) 1 <= N <= 10^8  O(n)

*/

void sort(vector<ll> &arr)
{
	sort(arr.begin(), arr.end());
}

void sortDesc(vector<ll> &arr)
{
	sort(arr.begin(), arr.end(), greater<int>());
}

void read(ll &a)
{
	cin >> a;
}

void read(vector<ll> &arr)
{
	for (int i = 0; i < arr.size(); i++)
	{
		cin >> arr[i];
	}
}

void print(vector<ll> arr)
{
	for (ll i : arr)
	{
		cout << i << " ";
	}
	cout << "\n";
}

void solve()
{
	ll n;
	cin>>n;
	for(ll i = 0 ; i < n-1 ; i++){
		for(ll j = 0 ; j < i ; j++){
			cout<<0<<" ";
		}
		cout<<1<<" "<<1<<" ";
		for(ll j = i+2 ; j < n ; j++){
			cout<<0<<" ";
		}
		cout<<"\n";
	}
	cout<<1<<" ";
	for(ll i = 1 ; i < n-1 ; i++){
		cout<<0<<" ";
	}
	cout<<1<<" ";
}

int main(int argc, char *args[])
{
#ifdef SINGLE_TEST_CASE
	solve();
#else
	ll t;
	std::cin >> t;
	while (t--)
	{
		solve();
		cout << "\n";
	}
#endif
}
