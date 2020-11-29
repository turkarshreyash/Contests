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
const ll mod = 1e9 + 7;
const ll maxN = 1e5;

/*
If you fall behind, run faster. Never give up, never surrender. Rise up against the odds
Mediocrity will never do. You are capable of something better.
*/

/*
i A -> i B      Corridor x
i+1 A -> i B    Corridor x
staircase i -> i+1  y
 
b-th floor of B from the a-th floor of A.
*/
void solve()
{
    ll a, b, x ,y;
    cin>>a>>b>>x>>y;
    if(a==b){
        cout<<x;
    }else if(a > b){
        ll cost1 = (a-b)*x + (a-b-1)*x;
        ll cost2 = min((a-b)*y + x,x + (a-b-1)*y);
        if(cost2>cost1){
            cout<<cost1;
        }else{
            cout<<cost2;
        }
    }else{
        ll cost1 = (b-a)*x + (b-a+1)*x;
        ll cost2 = (b-a)*y + x;
        if(cost2>cost1){
            cout<<cost1;
        }else{
            cout<<cost2;
        }
    }
    //going up by corridors = 2*x
    //going up by stairs = y
    //x
    //2 1 1 5
    //1 2 100 1
    //1 100 1 100


    
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