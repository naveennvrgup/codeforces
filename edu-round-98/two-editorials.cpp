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

struct seg{
	ll l,r;
};

void solve(){
	ll n,m,k;
	cin>>n>>m>>k;

	vector<seg> segs(m);
	for(int i=0;i<m;i++){
		cin>>segs[i].l>>segs[i].r;
		segs[i].l--;
	}

	sort(segs.begin(),segs.end(),[](seg a,seg b){
		return a.r+a.l<b.r+b.l;
	});

	vl suf(m+1);
	for(ll i=0;i<n-k+1;i++){
		ll curr=0;
		for(ll j=m-1;j>=0;j--){
			curr+=max((ll)0,min(segs[j].r,i+k)-max(segs[j].l,i));	
			suf[j]=max(suf[j],curr);
		}
	}

	ll ans=suf[0];
	for(ll i=0;i<n-k+1;i++){
		ll curr=0;
		for(ll j=0;j<m;j++){
			curr+=max((ll)0,min(segs[j].r,i+k)-max(segs[j].l,i));
			ans=max(ans,curr+suf[j+1]);
		}
	}

	cout<<ans<<endl;
}

int main() {
    FASTIO

    solve();

//    int t;
//    cin>>t;
//    while(t--)solve();

    return 0;
}
