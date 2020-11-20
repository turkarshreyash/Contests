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
    string s;
    cin>>s;
    ll count = 0;
    ll open = 0;
    for(char i : s){
        if(i == ')' && open > 0){
            open--;
            count++;
        }else if(i == '('){
            open++;
        }
    }
    open = 0;
    for(char i : s){
        if(i == ']' && open > 0){
            open--;
            count++;
        }else if(i == '['){
            open++;
        }
    }
    cout<<count<<'\n';
}
  

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
}