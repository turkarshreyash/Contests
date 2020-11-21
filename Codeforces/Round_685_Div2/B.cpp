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
    int l, q;
    cin>>l>>q;
    vi b_1count(l+1);
    vi f_1count(l+1);
    vi b_0count(l+1);
    vi f_0count(l+1);
    string s;
    cin>>s;
    f_1count[0] = f_0count[0] = 0;
    REP(i,0,l){
        f_0count[i+1] = f_0count[i];
        f_1count[i+1] = f_1count[i];
        if(s[i] == '0'){
            f_0count[i+1]++;
        }else{
            f_1count[i+1]++;
        }
    }
    b_1count[l] = b_0count[l] = 0;
    RREP(i,(l-1),-1){
        b_0count[i] = b_0count[i+1];
        b_1count[i] = b_1count[i+1];
        if(s[i] == '0'){
            b_0count[i]++;
        }else{
            b_1count[i]++;
        }
    }
    // cout<<"f_0count:";
    // REP(i,0,l+1){
    //     cout<<f_0count[i]<<" ";
    // }
    // cout<<"\nf_1count:";

    // REP(i,0,l+1){
    //     cout<<f_1count[i]<<" ";
    // }
    // cout<<"\nb_0count:";

    // REP(i,0,l+1){
    //     cout<<b_0count[i]<<" ";
    // }
    // cout<<"\nb_1count:";

    // REP(i,0,l+1){
    //     cout<<f_0count[i]<<" ";
    // }

    REP(i,0,q){
        ll l,r;
        cin>>l>>r;
        bool exits = false;
        l--;
        r--;
        if(s[l] == '0' && f_0count[l] > 0){
            exits = true;
        }
        if(s[l] == '1' && f_1count[l] > 0){
            exits = true;
        }

        if(s[r] == '0' && b_0count[r+1] > 0){
            exits = true;
        }
        if(s[r] == '1' && b_1count[r+1] > 0){
            exits = true;
        }
        if(exits == true){
            cout<<"YES";
        }else{
            cout<<"NO";
        }
        line;
    }
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