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
	vl arr(n);
	ll sum=0,mele=0;
	for(int i=0;i<n;i++){
		cin>>arr[i];
		sum+=arr[i];
		mele=max(mele,arr[i]);
	}

	ll temp=ceil((double)sum/(n-1));
	temp=max(mele,temp);
	temp=temp*(n-1);
	cout<<temp-sum<<endl;

}

int main() {
    FASTIO

    // solve();

   int t;
   cin>>t;
   while(t--)solve();

    return 0;
}
