#include <bits/stdc++.h>
using namespace std;
#define FASTIO  ios_base::sync_with_stdio(0);cin.tie(0);

typedef long long ll;
typedef pair<ll, ll> pll;
typedef pair<int,int> pii;
typedef vector<ll> vl;
typedef vector<vl> vll;

const ll mx = 1e9 + 7;
const ll inf = 1e18;

void solve(){
    ll n,c0,c1,h;
    string s;
    cin>>n>>c0>>c1>>h>>s;
    ll n0=0,n1=0;
    for(auto x: s){
        n0+=x=='0';
        n1+=x=='1';
    }

    ll res=inf;
    for(int i=0;i<=n;i++){
        res=min(res,c0*i+c1*(n-i)+(abs(n0-i))*h);
    }
    cout<<res<<endl;
}



int main() {
    FASTIO
    // solve();

   int t;
   cin>>t;
   while(t--)solve();

    return 0;
}
