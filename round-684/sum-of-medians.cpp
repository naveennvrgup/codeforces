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
    ll n,k;
    cin>>n>>k;
    vl arr(n*k);
    for(int i=0;i<n*k;i++)cin>>arr[i];
    
    ll res=0,j=n*k;
    for(int i=0;i<k;i++){
        j-=n/2+1;
        // cout<<j<<" ";
        res+=arr[j];
        
    }
    // cout<<endl;
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