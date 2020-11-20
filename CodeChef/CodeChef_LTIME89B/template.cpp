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
const ll mod = 1e9 + 7;

#define REP(i,a,b) for(ll i = a; i < b; i++)

#define F first
#define S second
#define MP make_pair
#define PB push_back
#define SZ size

typedef vector<ll> vi;
typedef pair<ll,ll> pi;
typedef stack<ll> stki;
typedef queue<ll> qi;
typedef set<ll> si;

ll mul(ll a, ll b);
ll add(ll a, ll b);
ll fact(ll n);
ll npr(ll n, ll k);
ll ncr(ll n, ll k);
void sort(vi &arr);
void sortDesc(vi &arr);
void read(ll &a);
void read(vi &aarr);
void print(const vi arr);

//#define SINGLE_TEST_CASE

/*

input size required time complexity
n ≤ 10 O(n!)
n ≤ 20 O(2^n)
n ≤ 500 O(n^3)
n ≤ 5000 O(n^2)
n ≤ 10^6 O(nlogn) or O(n)
n is large O(1) or O(logn)
*/

void solve()
{
	
}

int main(int argc, char *args[])
{
	ios::sync_with_stdio(0);
	cin.tie(0);
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

ll mul(ll a, ll b)
{
	return (a * b) % mod;
}

ll add(ll a, ll b)
{
	return (a + b) % mod;
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
	return f % mod;
}

ll npr(ll n, ll k)
{
	ll res = 1;
	for (int i = n - k + 1; i <= n; ++i)
	{
		res = mul(res, (i));
	}
	return res;
}

ll ncr(ll n, ll k)
{
	ll res = 1;
	k = n - k > k ? n - k : k;
	for (int i = k + 1; i <= n; ++i)
	{
		res = mul(res, (i));
		res /= (i - k);
	}
	return res;
}

void sort(vi &arr)
{
	sort(arr.begin(), arr.end());
}

void sortDesc(vi &arr)
{
	sort(arr.begin(), arr.end(), greater<int>());
}

void read(ll &a)
{
	cin >> a;
}

void read(vi &arr)
{
	for (int i = 0; i < arr.size(); i++)
	{
		cin >> arr[i];
	}
}

void print(const vi arr)
{
	for (ll i : arr)
	{
		cout << i << " ";
	}
	cout << "\n";
}