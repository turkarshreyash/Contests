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
void print(vector<ll> arr);

//#define SINGLE_TEST_CASE
/*
The first line contains T− Number of test cases in a file.
The first line of each test case has 3 integers, N, M and K, denoting number of nodes, number of edges, and number of special nodes respectively.
Next M lines have 2 integers each - u v - denoting that there is an (undirected) edge between u and v.
Next line has K space separated integers denoting the special nodes.
Next line has a single integer Q - the number of queries.
Next Q lines contain 1 integer each - u - the starting node for Commander Tresdin.
*/

const ll maxN = 1e5 + 1;

vi djikistra(const vector<vi> &adj, ll u)
{
	ll n = adj.size();
	vi dist(n, n);
	vector<u_si> bucket(n + 1);
	dist[u] = 0;
	bucket[0].IN(u);
	REP(i, n)
	{
		if (i != u)
		{
			bucket[n].IN(i);
		}
	}
	while (true)
	{
		u = -1;
		REP(i, n)
		{
			if (bucket[i].SZ() > 0)
			{
				u = *bucket[i].begin();
				bucket[i].erase(bucket[i].begin());
			}
		}
		if (u == -1)
		{
			break;
		}
		for (auto i : adj[u])
		{
			if (dist[i] > dist[u] + 1)
			{
				bucket[dist[i]].erase(i);
				bucket[dist[u] + 1].IN(i);
				dist[i] = dist[u] + 1;
			}
		}
	}

	return dist;
}

void solve()
{
	ll n, m, k;
	cin >> n >> m >> k;
	vector<vi> adj(n);
	REP(i, m)
	{
		ll u, v;
		cin >> u >> v;
		u--, v--;
		adj[u].PB(v);
		adj[v].PB(u);
	}
	vector<vi> dsn;
	REP(i, k)
	{
		ll sn;
		cin >> sn;
		sn--;
		dsn.PB(djikistra(adj, sn));
		print(dsn[i]);
	}
	vi best(n, n);
	REP(i, k)
	{
		REP(j, n)
		{
			best[j] = min(best[j], dsn[i][j]);
		}
	}

	REP(j, n)
	{
		best[j] = best[j] == n ? -1 : best[j];
	}

	ll q;
	cin >> q;
	REP(i, q)
	{
		ll u;
		cin >> u;
		u--;
		cout << best[u] << "\n";
	}
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
	cin >> t;
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