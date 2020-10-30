/*
Shreyash H. Turkar
*/
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define INF LLONG_MAX
#define NEG_INF LLONG_MIN
const ll mod = 1e9 + 7;

#define F first
#define S second
#define MP make_pair
#define PB push_back
#define IN insert

typedef vector<ll> vi;
typedef set<ll> si;

ll mul(ll a, ll b);
ll add(ll a, ll b);
ll fact(ll n);
ll npr(ll n, ll k);
ll ncr(ll n, ll k);
void sort(vector<ll> &arr);
void sortDesc(vector<ll> &arr);
void read(ll &a);
void read(vi &a);
void print(vector<ll> arr);

//#define SINGLE_TEST_CASE

/*

1) 1 <= N <= 10^3  O(n^2) 
2) 1 <= N <= 10^5  O(nlogn)
3) 1 <= N <= 10^8  O(n)

*/

void solve()
{
	ll n, k;
	read(n);
	read(k);
	vi arr(n);
	read(arr);
	sort(arr);
	ll l = 0, r = k - 1;
	ll best = INF;
	while (r < n)
	{
		best = min(arr[r] - arr[l], best);
		r++;
		l++;
	}
	cout << best;
}

int main(int argc, char *args[])
{
#ifdef SINGLE_TEST_CASE
	solve();
	cout << "\n";
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