#include <bits/stdc++.h>
using namespace std;
#define FASTIO  ios_base::sync_with_stdio(0);cin.tie(0);

typedef long long ll;
typedef pair<ll, ll> pll;
typedef pair<int,int> pii;
typedef vector<ll> vl;
typedef vector<string> vs;
typedef vector<vl> vll;

const ll mx = 998244353;
const ll inf = 1e18;

const ll s=2e5+5;
vl fib(s),inv(s);

ll pow(int n){
    if(n==1)return inv[2];
    ll temp=pow(n/2);
    // printf("%lld %lld\n",n,temp);
    if(n%2)return ((temp*temp)%mx)*inv[2]%mx;
    else return(temp*temp)%mx;
}

void solve(){
    ll n;
    cin>>n;

    // printf("%lld %lld\n",fib[n],inv[1<<n]);
    ll res=(fib[n]*pow(n))%mx;
    cout<<res<<endl;
}


int main() {
    FASTIO

    fib[0]=0;
    fib[1]=1;
    for(int i=2;i<s;i++)fib[i]=(fib[i-1]+fib[i-2])%mx;

    inv[0]=inv[1]=1;
    for(int i=2;i<s;i++)inv[i]=(inv[mx%i]*(mx-mx/i))%mx;

    solve();

//    int t;
//    cin>>t;
//    while(t--)solve();

    return 0;
}
