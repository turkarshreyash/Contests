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

#define F first
#define S second
#define MP make_pair
#define PB push_back
#define IN insert

typedef vector<ll> vi;

ll mul(ll a, ll b);
ll add(ll a, ll b);
ll fact(ll n);
ll npr(ll n, ll k);
ll ncr(ll n, ll k);
void sort(vector<ll> &arr);
void sortDesc(vector<ll> &arr);
void read(ll &a);
void read(vector<ll> &a);
void print(vector<ll> arr);
ll max(const vector<ll> &arr);
ll min(const vector<ll> &arr);

#define SINGLE_TEST_CASE

/*

1) 1 <= N <= 10^3  O(n^2) 
2) 1 <= N <= 10^5  O(nlogn)
3) 1 <= N <= 10^8  O(n)

*/

void solve()
{
	vi tones(6);
	read(tones);
	ll n;
	read(n);
	vi notes(n);
	read(notes);

	vector<pair<ll, ll>> fret;
	for (ll i = 0; i < n; i++)
	{
		for (ll j = 0; j < 6; j++)
		{
			if (notes[i] > tones[j])
			{
				fret.PB(MP(notes[i] - tones[j], i));
			}
		}
	}

	sort(fret.begin(), fret.end());
	vi countN(n, 0);
	ll nn = fret.size();
	ll best = INF;
	ll l = 0, r = -1;
	ll count = 0;
	while (r < nn)
	{
		if (count < n)
		{	
			r++;
			if (countN[fret[r].S] == 0)
			{
				count++;
			}
			countN[fret[r].S]++;
		}
		else
		{	
			// cout<<"r.F:"<<fret[r].F<<" l.F:"<<fret[l].F<<"\n";
			best = min(best, fret[r].F - fret[l].F);
			countN[fret[l].S]--;
			if (countN[fret[l].S] == 0)
			{
				count--;
			}
			l++;
		}
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

ll max(const vector<ll> &arr)
{
	ll maxx = 0;
	for (ll i : arr)
	{
		maxx = max(i, maxx);
	}
	return maxx;
}

ll min(const vector<ll> &arr)
{
	ll minn = INF;
	for (ll i : arr)
	{
		minn = min(i, minn);
	}
	return minn;
}