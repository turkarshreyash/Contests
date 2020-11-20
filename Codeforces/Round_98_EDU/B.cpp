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
typedef long double ld;
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
If you fall behind, run faster. Never give up, never surrender, and rise up against the odds
AND
Mediocrity will never do. You are capable of something better.
*/
void solve()
{
    ll n;
    ll sum = 0;
    ll maxx = 0;
    cin>>n;
    REP(i,0,n){
        ll temp;
        cin>>temp;
        sum += temp;
        maxx = max(maxx,temp);
    }
    ll dis = ceil((ld)sum/(n-1));
    dis = max(dis,maxx);
    cout<<dis*(n-1)-sum;
}

int main()
{
 ios::sync_with_stdio(0);
    cin.tie(0);
    ll ct;
    cin>>ct;
    REP(t,0,ct){
        solve();
        line;
    }
}