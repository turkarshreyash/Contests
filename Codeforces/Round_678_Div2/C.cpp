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

#define ll uint64_t
#define INF LLONG_MAX
#define NEG_INF LLONG_MIN

#define SINGLE_TEST_CASE

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

const ll mod = 1e9+7;	
ll posSmaller = 0;
ll posLarger = 0;

void binarySearch(ll n, ll pos)
{
	ll l = 0;
	ll r = n;
	while (l < r)
	{
		ll middle = (l + r) / 2;
		if(middle == pos){
			l = middle + 1;
		}
		else if (middle < pos)
		{
			posSmaller++;
			l = middle + 1;
		}
		else
		{
			posLarger++;
			r = middle;
		}
	}
}

ll mul(ll a, ll b)
{
	return (a * b) % mod;
}

ll fact(ll n)
{
	if (n == 1 || n == 0)
	{
		return 1;
	}
	ll f = 1;
	for (ll i = 2; i <= n; i++)
	{
		f = mul(f, i);
	}
	return f%mod;
}

ll ncr(ll n, ll k)
{
	ll res = 1;
	for (int i = n-k+1; i <= n; ++i)
	{
		res = mul(res, (i));
	}

	return res%mod;
}	

void solve()
{
	ll n, x, pos;
	cin >> n >> x >> pos;
	binarySearch(n, pos);
	if(posSmaller > x-1 || posLarger > n-x){
		cout<<"0";
		return;
	}
	ll arragementOfSmaller = ncr(x-1, posSmaller);
	ll arragementOfLarger = ncr(n - x , posLarger);
	ll remaining = fact(n - posSmaller - posLarger - 1);
	cout << mul(mul(arragementOfSmaller, remaining), arragementOfLarger) << "\n";
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
