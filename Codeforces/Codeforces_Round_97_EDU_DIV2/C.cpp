/*
Shreyash H. Turkar
*/
#include <bits/stdc++.h>
using namespace std;
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
#define PS push
#define IN insert
#define SZ size
#define LEN length
#define FR front

#define LOOP(ITR, S, E) for (ll ITR = S; ITR < E; ITR++)
#define REP(ITR, E) for (ll ITR = 0; ITR < E; ITR++)

typedef vector<ll> vi;
typedef set<ll> si;
typedef unordered_set<ll> u_si;
typedef vector<bool> vb;
typedef queue<ll> qi;
typedef stack<ll> stki;

ll mul(ll a, ll b);
ll add(ll a, ll b);
ll fact(ll n);
ll npr(ll n, ll k);
ll ncr(ll n, ll k);
void sort(vector<ll> &arr);
void sortDesc(vector<ll> &arr);
void read(ll &a);
void read(vi &arr);
void print(vector<ll> arr);

const ll maxN = 1e5 + 1;

//#define SINGLE_TEST_CASE

/*
6
6
4 2 4 4 5 2
7
7 7 7 7 7 7 7
1
1
5
5 1 2 4 3
4
1 4 4 4
21
21 8 1 4 1 5 21 1 8 21 11 21 11 3 12 8 19 15 9 11 13

*/

unordered_map<ll, unordered_map<ll, ll>> dp;

ll takeOut(const vi &arr, ll itr = 0, ll time = 1)
{
	ll n = arr.SZ();
	if (itr == n)
	{
		return 0;
	}
	if (dp.find(itr) != dp.end() && dp[itr].find(time) != dp[itr].end())
	{
		return dp[itr][time];
	}
	if (time > arr[itr])
	{
		return dp[itr][time] = takeOut(arr, itr + 1, time + 1) + time - arr[itr];
	}
	ll best = INF;
	LOOP(i, time, arr[itr] + 1)
	{
		best = min(best, takeOut(arr, itr + 1, i + 1) + arr[itr] - i);
	}
	return dp[itr][time] = best;
}

void solve()
{
	ll n;
	cin >> n;
	vi arr(n);
	read(arr);
	sort(arr);
	dp.clear();
	cout << takeOut(arr);
}

int main(int argc, char *args[])
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
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