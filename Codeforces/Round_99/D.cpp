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

//#define SINGLE_TEST
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


bool sorted(const vi &arr, ll s){
    REP(i,s,arr.size()-1){
        if(arr[i] > arr[i+1]){
            return false;
        }
    }
    return true;
}

/*
If you fall behind, run faster. Never give up, never surrender. Rise up against the odds
Mediocrity will never do. You are capable of something better.
*/
void solve()
{
    ll n, x;
    cin>>n>>x;
    vi arr(n);
    FOR(&i,arr){
        cin>>i;
    }
    ll count = 0;
    ll maxx = 0;
    REP(i,0,n){
        if(sorted(arr,i) == true && arr[i] >= maxx){
            cout<<count;
            return;
        }
        if(arr[i] < maxx && x > arr[i]){
            cout<<-1;
            return;
        }
        if(arr[i] > x){
            swap(arr[i],x);
            ++count;
        }
        maxx = max(maxx,arr[i]);
    }
    cout<<count;
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