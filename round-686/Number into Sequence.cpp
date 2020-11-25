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
    ll n;
    cin>>n;

    map<ll,ll> m;

    while(n%2==0){
        m[2]++;
        n/=2;
    }

    for(ll i=3;i*i<=n;i+=2){
        while(n%i==0){
            m[i]++;
            n/=i;
        }
    }

    if(n>1)m[n]++;

    vector<pll> arr;
    for(auto x:m)arr.push_back({x.second,x.first});

    vl res;
    sort(arr.begin(),arr.end(),[](pll a,pll b){
        return a.first>b.first;
    });

    ll mul=arr[0].second,count=arr[0].first;
    for(int i=1;i<arr.size();i++){
        if(count!=arr[i].first){
            for(int j=0;j<count-arr[i].first;j++)res.push_back(mul);
        }
        mul*=arr[i].second;
        count=arr[i].first;
    }
    for(int j=0;j<count;j++)res.push_back(mul);

    cout<<res.size()<<endl;
    for(auto x:res)cout<<x<<" ";
    cout<<endl;
}

int main() {
    FASTIO

    // solve();

   int t;
   cin>>t;
   while(t--)solve();

    return 0;
}
