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
	int n,q;
	cin>>n>>q;
	
	string s;
	cin>>s;
	
	vl of(n+2),zf(n+2),ob(n+2),zb(n+2);

	for(int i=0;i<n;i++){
		if(s[i]=='0'){
			zf[i+1]=1;
			of[i+1]=of[i];
		}else{
			of[i+1]=1;
			zf[i+1]=zf[i];
		}
	}
	
	for(int i=n-1;i>=0;i--){
		if(s[i]=='0'){
			zb[i+1]=1;
			ob[i+1]=ob[i+2];
		}else{
			ob[i+1]=1;
			zb[i+1]=zb[i+2];
		}
	}

	for(int i=0;i<q;i++){
		int l,r,res=0;
		cin>>l>>r;

		if(s[l-1]=='0'){
			res|=zf[l-1];
		}else{
			res|=of[l-1];
		}

		if(s[r-1]=='0'){
			res|=zb[r+1];
		}else{
			res|=ob[r+1];
		}

		if(res)cout<<"YES"<<endl;
		else cout<<"NO"<<endl;
	}
}

int main() {
    FASTIO

    // solve();

   int t;
   cin>>t;
   while(t--)solve();

    return 0;
}
