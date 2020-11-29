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
#include <array>

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
const ll mod = 1e9 + 7;
const ll maxN = 5001;

vector<vector<ll>> dp(maxN, vector<ll>(maxN, 0));

ll lcs(string s1, string s2)
{
    ll n = s1.length();
    ll m = s2.length();
    ll best = 0;
    REP(i, 1, n + 1)
    {
        REP(j, 1, m + 1)
        {
            if (s1[i - 1] == s2[j - 1])
            {
                dp[i][j] = dp[i - 1][j - 1] + 2;
            }else{
                dp[i][j] =  max(0ll,max(dp[i - 1][j], dp[i][j - 1])- 1);
            }
            best = max(best, dp[i][j]);
        }
    }
    return best;
}

/*
If you fall behind, run faster. Never give up, never surrender. Rise up against the odds
Mediocrity will never do. You are capable of something better.
*/
void solve()
{
    ll n, m;
    string a, b;
    cin >> n >> m;
    cin >> a >> b;
    cout << lcs(a, b)<< "\n";
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