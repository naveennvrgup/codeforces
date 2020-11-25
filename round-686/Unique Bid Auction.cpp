#include <bits/stdc++.h>
using namespace std;
#define FASTIO  ios_base::sync_with_stdio(0);cin.tie(0);

typedef long long ll;
typedef pair<ll, ll> pll;
typedef pair<int,int> pii;
typedef vector<ll> vl;
typedef vector<vl> vll;

const ll mx = 1e9+7;
const ll inf = 1e18;

void solve(){
    int n;
    cin>>n;
    
    vl num(n+1),idx(n+1);
    for(int i=0;i<n;i++){
        int temp;
        cin>>temp;

        num[temp]++;
        idx[temp]=i+1;
    }

    for(int i=1;i<=n;i++){
        if(num[i]==1){
            cout<<idx[i]<<endl;
            return;
        }
    }

    cout<<-1<<endl;
}

int main() {
    FASTIO

    // solve();

   int t;
   cin>>t;
   while(t--)solve();

    return 0;
}
