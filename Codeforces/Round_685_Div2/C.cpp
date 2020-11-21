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

#define bug(x) cout << #x << ":" << x;
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
const ll maxN = 1e5;

/*
If you fall behind, run faster. Never give up, never surrender, and rise up
against the odds AND Mediocrity will never do. You are capable of something
better.
*/
void solve()
{
    ll n, k;
    cin >> n >> k;
    string a, b;
    cin >> a >> b;
    vi ah(26, 0);

    REP(i, 0, n)
    {
        ah[a[i] - 'a']++;
        ah[b[i] - 'a']--;
    }
    // REP(i,0,26){
    //     cout<<ah[i]<<" ";
    // }
    // line;
    if (ah[25] > 0)
    {
        cout << "No";
        return;
    }
    ll pos = 0;
    ll neg = 0;
    REP(i, 0, 26)
    {
        // cout<<ah[i]<<" ";
        if (ah[i])
        {
            if (ah[i] > 0)
            {
                if (ah[i] + pos >= k)
                {
                    pos += k*(ah[i]/k);
                }
            }
            else
            {
                neg -= ah[i];
                if(abs(ah[i])%k){
                    cout<<"No";
                    return;
                }
            }
        }
        if(pos < neg){
            cout<<"No";
            return;
        }
    }
    // line;
    // bug(pos);
    // line;
    // bug(neg);
    // line;
    if (pos == neg)
    {
        cout << "Yes";
    }
    else
    {
        cout << "No";
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    ll ct;
    cin >> ct;
    REP(t, 0, ct)
    {
        solve();
        line;
    }
}