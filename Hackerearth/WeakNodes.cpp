/*
Shreyash H. Turkar
*/
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")

#include <algorithm>
#include <climits>
#include <cmath>
#include <iostream>
#include <iterator>
#include <limits>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>

using namespace std;

typedef long long ll;
typedef vector<ll> vi;
typedef priority_queue<ll> hpq;
typedef priority_queue<ll, vi, greater<ll>> lpq;

#define SINGLE_TEST
//#define ONLINE_JUDGE

#ifndef ONLINE_JUDGE
#define bug(x) cout << #x << ":" << x << " ";
#else
#define bug(x)
#endif

#define line cout << "\n";
#define pb push_back
#define mk make_pair
#define F first
#define S second
#define REP(i, s, e) for (ll i = s; i < (e); ++i)
#define RREP(i, s, e) for (ll i = s; i > (e); --i)
#define FOR(i, arr) for (auto i : arr)
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()

const ll inf = numeric_limits<ll>::max();
constexpr ll mod = (1e9) + 7;
constexpr ll maxN = 5 * (1e4);

vi Vi(maxN);
vi visited(maxN, false);
vi ti(maxN);
vi low(maxN);
vector<vi> adj(maxN);
const vi primes{2, 3, 5, 7, 11, 13, 17, 19, 23};
vi bucket(9, 0);
vi ans;

ll timer = 0;

void dfs(ll s, ll p = -1)
{

    visited[s] = true;
    ti[s] = low[s] = ++timer;
    ll childs = 0;
    FOR(i, adj[s])
    {
        if (i == p)
        {
            //nop
        }
        else if (visited[i])
        {
            low[s] = min(low[s], ti[i]);
        }
        else
        {
            dfs(i, s);
            ++childs;
            low[s] = min(low[s], low[i]);
            if (low[i] >= ti[s] && p != -1)
            {
                ans.pb(s);
            }
        }
    }
    if (p == -1 && childs > 1)
    {
        ans.pb(s);
    }
}

ll mpow(ll a, ll p)
{
    ll result = 1;
    while (p--)
    {
        result = (result * a) % mod;
    }
    return result;
}

/*
If you fall behind, run faster. Never give up, never surrender. Rise up against the odds
Mediocrity will never do. You are capable of something better.
*/
void solve()
{
    ll n, m;
    cin >> n >> m;
    REP(i, 0, n)
    {
        cin >> Vi[i];
    }
    REP(i, 0, m)
    {
        ll v, u;
        cin >> v >> u;
        --v;
        --u;
        adj[v].pb(u);
        adj[u].pb(v);
    }
    REP(i, 0, n)
    {
        if (!visited[i])
        {
            dfs(i, -1);
        }
    }
    ll extras = 0;
    FOR(i, ans)
    {
        ll count = 0;
        REP(j, 0, primes.size())
        {
            if (Vi[i] % primes[j] == 0)
            {
                count++;
                bucket[j] = (bucket[j] + 1) % mod;
            }
        }
        if (count == 0)
        {
            extras++;
        }
    }
    /*
    1 2
    2 3
    3

    1 1 1 2 1
    4 3 
*/

    for (i = 0; i < ap.size(); i++)
    {
        ll temp = 0;
        for (j = 0; j < 9; j++)
            if (power[ap[i]] % arr[j] == 0)
                temp |= (1 << j);
        f[temp]++;
    }
    for (i = 0; i < 512; i++)
    {
        f[i] = (POWER(2, f[i], MOD) - 1 + MOD) % MOD;
    }
    ll dp[2][10000] = {0};
    ll c = 1, p = 0;
    for (i = 0; i < 512; i++)
    {
        ll temp = f[i];
        for (j = 0; j < 512; j++)
            dp[c][j] = dp[p][j];
        for (j = 0; j < 512; j++)
        {
            dp[c][j | i] = (dp[c][j | i] + ((dp[p][j] * temp) % MOD)) % MOD;
        }
        dp[c][i] = (dp[c][i] + temp) % MOD;
        c = !c;
        p = !p;
    }
    cout << dp[p][511] << endl;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    ll ct;
#ifndef SINGLE_TEST
    cin >> ct;
#else
    ct = 1;
#endif
    REP(t, 0, ct)
    {
        solve();
        line;
    }
}
/*
turkarshreyash
C++
*/