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
const ll mod = 998244353;
const ll maxN = 1e5;

/*
If you fall behind, run faster. Never give up, never surrender, and rise up against the odds
AND
Mediocrity will never do. You are capable of something better.
*/
ll mul(ll a, ll b){
    return ((a%mod)*(b%mod))%mod;
}

ll power(ll a, ll b){
    ll result = 1;
    while(b){
        if(b&1){
            result = mul(result,a);
        }
        a = mul(a,a);
        b >>= 1;
    }
    return result;
}

ll inv(ll a){
    return power(a,mod-2);
}

/*
b-1 (mod P) will be b^P-2 (mod P)
*/

void solve()
{
    ll n;
    cin>>n;
    ll a = 0, b = 1, c = 1;
    REP(i,1,n){
        c = (b+a)%mod;
        a = b;
        b = c;
    }
    ll inv2 = inv(2);
    // bug(c);
    // line;
    // bug(inv2);
    // line;
    REP(i,0,n){
        c = mul(c,inv2);
    }
    cout<<c;
    line;
}

int main()
{
 ios::sync_with_stdio(0);
    cin.tie(0);
    ll ct = 1;
    //cin>>ct;
    REP(t,0,ct){
        solve();
        line;
    }
}