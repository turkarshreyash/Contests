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
const ll maxN = 2001;

ll n, m;
vector<vector<char>> arr(maxN,vector<char>(maxN));
vector<vector<pair<ll,ll>>> adj(26);
vector<vector<bool>> visited(maxN,vector<bool>(maxN,false));
vector<vector<int>> moves{{-1,0,1,0},{0,1,0,-1}};

inline bool isbtw(ll i, ll s, ll e){
    if(i < s || i > e){
        return false;
    }
    return true;
}
/*
If you fall behind, run faster. Never give up, never surrender. Rise up against the odds
Mediocrity will never do. You are capable of something better.
*/
void solve()
{
    cin>>n>>m;
    ll si, sj;
    REP(i,0,n){
        REP(j,0,m){
            cin>>arr[i][j];
            if(isbtw(arr[i][j],'a','z')){
                adj[arr[i][j]-'a'].pb(mk(i,j));
            }
            if(arr[i][j] == 'S'){
                tie(si,sj) = mk(i,j);
            } 
        }
    }

    queue<pair<ll,ll>> q;

    visited[si][sj] = true;
    q.push(mk(si,sj));
    ll level = 1;
    ll nodeCount = 1;
    while(!q.empty()){
        ll childs = 0;
        REP(i,0,nodeCount){
            ll x, y;
            tie(x,y) = q.front();
            q.pop();
            REP(move,0,4){
                ll x2 = x+moves[0][move];
                ll y2 = y+moves[1][move];
                if(isbtw(x2,0,n-1) && isbtw(y2,0,m-1) && !visited[x2][y2] && arr[x2][y2] != '#') {
                    if(arr[x2][y2] == 'G'){
                        cout<<level;
                        return;
                    }
                    visited[x2][y2] = true;
                    ++childs;
                    q.push(mk(x2,y2));
                }
            }
            if(isbtw(arr[x][y],'a','z')){
                FOR(i,adj[arr[x][y] - 'a']){
                    if(!visited[i.F][i.S]){
                        if(arr[i.F][i.S] == 'G'){
                            cout<<level;
                            return;
                        }
                        visited[i.F][i.S] = true;
                        ++childs;
                        q.push(mk(i.F,i.S));
                    }
                }
            }

        }
        nodeCount = childs;
        ++level;
    }
    cout<<-1;
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