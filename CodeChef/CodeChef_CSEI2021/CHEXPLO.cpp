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
ll max(const vi &arr);

//#define SINGLE_TEST_CASE

/*

1) 1 <= N <= 10^3  O(n^2) 
2) 1 <= N <= 10^5  O(nlogn)
3) 1 <= N <= 10^8  O(n)

*/
ll min(const vi &dist, const vector<bool> &visited)
{
	ll best = INF, bestIndex;
	for (ll i = 0; i < dist.size(); i++)
	{
		if (visited[i] == false && best > dist[i])
		{
			best = dist[i];
			bestIndex = i;
		}
	}
	return bestIndex;
}

ll dijkistra(const vector<vi> &adj, ll src)
{
	ll n = adj.size();
	vi dist(n, n);
	vector<bool> visited(n, false);

	dist[src] = 0;

	for (ll i = 0; i < n; i++)
	{
		ll u = min(dist, visited);
		visited[u] = true;

		for (ll v : adj[u])
		{
			if (!visited[v] && dist[u] < n && dist[u] + 1 < dist[v])
			{
				dist[v] = dist[u] + 1;
			}
		}
	}
	ll best = 0;
	for (ll i : dist)
	{
		best = i < n ? max(best, i) : best;
	}
	return best;
}

void solve()
{
	ll n;
	read(n);
	vector<vi> adj(n);
	unordered_set<ll> terminal, NotTerminal;

	for (ll i = 1; i < n; i++)
	{
		ll u, v;
		read(u);
		read(v);
		u--;
		v--;
		adj[u].PB(v);
		adj[v].PB(u);
		if (terminal.find(u) == terminal.end() && NotTerminal.find(u) == NotTerminal.end())
		{
			terminal.insert(u);
		}
		else if (NotTerminal.find(u) == NotTerminal.end())
		{
			terminal.erase(u);
			NotTerminal.insert(u);
		}
		if (terminal.find(v) == terminal.end() && NotTerminal.find(v) == NotTerminal.end())
		{
			terminal.insert(v);
		}
		else if (NotTerminal.find(v) == NotTerminal.end())
		{
			terminal.erase(v);
			NotTerminal.insert(v);
		}
	}

	vi minDis;

	for (ll i : terminal)
	{
		minDis.PB(dijkistra(adj, i));
	}

	ll best = max(minDis);
	cout << (best + 1) / 2;
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

ll max(const vi &arr)
{
	ll best = 0;
	for (ll i : arr)
	{
		best = max(i, best);
	}
	return best;
}