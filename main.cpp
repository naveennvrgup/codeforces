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

const ll MAXN=2e5+5;
int n;
vl t(4*MAXN);

void build(vl &a, int v, int tl, int tr) {
    if (tl == tr) {
        t[v] = a[tl];
    } else {
        int tm = (tl + tr) / 2;
        build(a, v*2, tl, tm);
        build(a, v*2+1, tm+1, tr);
        t[v] = min(t[v*2],t[v*2+1]);
    }
}

ll findmin(int v, int tl, int tr, int l, int r) {
    if (l > r) 
        return INT_MAX;
    if (l == tl && r == tr) {
        return t[v];
    }
    int tm = (tl + tr) / 2;
    return min(
        findmin(v*2, tl, tm, l, min(r, tm)),
        findmin(v*2+1, tm+1, tr, max(l, tm+1), r)
    );
}

void solve(){
    ll n;
    cin>>n;

    vl a(n);
    for(int i=0;i<n;i++)cin>>a[i];
    build(a,1,0,n-1);

    ll l=0,r=n-1;
    ll lv=a[l],rv=a[r];

    while(r-l>=2){
        // printf("%lld,%lld\n",l,r);
        if(lv<rv){
            lv=max(lv,a[++l]);
        }else if(lv>rv){
            rv=max(rv,a[--r]);
        }else{
            while(l<r && a[l+1]<lv)l++;
            while(l<r && a[r-1]<rv)r--;
            if(r-l<2)break;
            ll curr=findmin(1,0,n-1,l+1,r-1);
            if(curr==lv)break;
            else lv=max(lv,a[++l]);
        }
    }
    
    if(r-l>=2){
        cout<<"YES"<<endl;
        ll x=l+1,y=r-x,z=n-x-y;
        cout<<x<<" "<<y<<" "<<z<<endl;
    }else cout<<"NO"<<endl;
}

int main() {
    FASTIO

    // solve();

   int t;
   cin>>t;
   while(t--)solve();

    return 0;
}
