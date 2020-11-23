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
If you fall behind, run faster. Never give up, never surrender, and rise up against the odds
AND
Mediocrity will never do. You are capable of something better.
*/

void solve()
{
    ll x, y, r, c;
    cin>>x>>y>>r>>c;
    r-=x;   
    c-=y;
    r = abs(r);
    c = abs(c);
    // bug(r);
    // line;
    // bug(c);
    // line;
    //already in pos
    if(c == 0 && r == 0){
        cout<<0;
        return;
    }

    //diagonal
    if(r == c){
        cout<<1;
        return;
    }

    //in block
    if(r + c <= 3){
        cout<<1;
        return;
    }

    // on axis
    if(r == 0 || c==0){
        ll steps = r?r:c;
        if(steps%2==0 || steps/3+1 < 3){
            cout<<2;
        }else{
            cout<<3;
        }
        return;
    }

    //on diagonal shifted
    if(abs(r-c) <= 3){
        cout<<2;
        return;
    }


    if((r+c)%2 == 0){
        cout<<2;
    }else{
        cout<<3;
    }
}

int main()
{
 ios::sync_with_stdio(0);
    cin.tie(0);
    ll ct = 1;
    // cin>>ct;
    REP(t,0,ct){
        solve();
        line;
    }
}