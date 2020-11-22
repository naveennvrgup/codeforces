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

bool isPrime(int n){
	if(n==1)return false;
	if(n==2 || n==3)return true;
	
	for(int i=2;i*i<=n;i++){
		if(n%i==0)return false;
	}
	return true;
}

void solve(){
	int n;
	cin>>n;

	int res=0;
	while(n!=1){
		if(isPrime(n) || n%2){
			n--;
		}else{
			for(int i=2;i*i<=n;i++){
				if(n%i==0){
					n=i;
					break;
				}
			}
		}
		res++;
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
