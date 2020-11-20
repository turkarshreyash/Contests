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
typedef unordered_map<ll, ll> umap;

typedef vector<vector<pair<ll, ll>>> vvp;
//#define SINGLE_TEST_CASE

/*

1) 1 <= N <= 10^3  O(n^2) 
2) 1 <= N <= 10^5  O(nlogn)
3) 1 <= N <= 10^8  O(n)

*/
//return distance
typedef struct node
{
	ll u;
	vector<umap> child;
	vector<node *> childRef;
} node;

node *dfs(const vvp &adj, ll u, ll dis = 0)
{
	node *thisNode = new node();
	thisNode->u = u;
	ll cn = 0;
	for (auto v : adj[u])
	{
		node *childref = dfs(adj, v.F, v.S);
		thisNode->child.resize(cn + 1);
		thisNode->child[cn].IN(MP(v.F, v.S));
		for (auto i : childref->child)
		{
			for (auto j : i)
			{
				thisNode->child[cn].IN(MP(j.F, j.S + v.S));
			}
		}
		cn++;
		thisNode->childRef.PB(childref);
	}
	return thisNode;
}

ll search(node *s, ll u, ll v)
{

	ll cn = s->childRef.size();
	ll ud = -1, vd = -1;

	for (ll i = 0; i < cn; i++)
	{
		if (s->child[i].find(u) != s->child[i].end() && s->child[i].find(v) != s->child[i].end())
			return search(s->childRef[i], u, v);
	}

	for (ll i = 0; i < cn; i++)
	{
		if (s->child[i].find(u) != s->child[i].end())
		{
			ud = s->child[i][u];
		}
	}

	for (ll i = 0; i < cn; i++)
	{
		if (s->child[i].find(v) != s->child[i].end())
		{
			vd = s->child[i][v];
		}
	}

	if (s->u == u || s->u == v)
	{
		if (ud != -1)
		{
			ud = 0;
		}
		else
		{
			vd = 0;
		}
	}

	if (vd != -1 && ud != -1)
	{
		return vd + ud;
	}
	return ud == -1 ? vd : ud;
}

void solve()
{
	ll n, q, r;
	read(n);
	read(q);
	read(r);
	r--;

	vector<vector<pair<ll, ll>>> adj(n);
	for (ll i = 1; i < n; i++)
	{
		ll u, v, w;
		read(u);
		read(v);
		read(w);
		u--;
		v--;
		adj[u].PB(MP(v, w));
	}

	node *root = dfs(adj, r);

	for (ll i = 0; i < q; i++)
	{
		ll u, v;
		read(u);
		read(v);
		u--;
		v--;

		cout << search(root, u, v) << "\n";
	}
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

ll max(const vi &arr)
{
	ll best = 0;
	for (ll i : arr)
	{
		best = max(i, best);
	}
	return best;
}