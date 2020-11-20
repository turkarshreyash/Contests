#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#include <limits>

using namespace std;

typedef long long ll;
typedef vector<ll> vi;

#define pb push_back
#define mk make_pair
#define REP(i, s, e) for (ll i = s; i < (e); ++i)
#define RREP(i, s, e) for (ll i = s; i > (e); --i)

const ll inf = numeric_limits<ll>::max();
const ll mod = 1e9+7;
const ll maxN = 1e5;

void solve()
{
    int x, y;
    cin>>x>>y;
    x = abs(x); y = abs(y);
    int diff = abs(x-y);
    if(diff < 2){
        cout<<x+y;
    }else{
        int steps = x+y;
        cout<<steps+diff-1;
    }
}
  

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        solve();
        cout<<"\n";
    }
}