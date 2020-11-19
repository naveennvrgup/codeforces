#include <bits/stdc++.h>
using namespace std;
#define FASTIO  ios_base::sync_with_stdio(0);cin.tie(0);
 
typedef long long ll;
typedef pair<ll, ll> pll;
typedef pair<int,int> pii;
typedef vector<ll> vl;
typedef vector<string> vs;
typedef vector<vl> vll;
 
const ll mx = 1e9 + 7;
const ll inf = 1e18;
 
void solve(){
    int a,b;
    cin>>a>>b;
 
    if(a==b){
        cout<<a+b<<endl;
        return;
    }
    int res=min(a,b)*2+(max(a,b)-min(a,b)-1)*2+1;
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