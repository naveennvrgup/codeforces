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
	int n,k;
	cin>>n>>k;

	string a,b;
	cin>>a>>b;

	vl af(27),bf(27);
	for(auto x: a)af[x-'a']++;
	for(auto x: b)bf[x-'a']++;

	for(int i=0;i<26;i++){
		int diff=af[i]-bf[i];
		if(diff<0 || diff%k){
			cout<<"No"<<endl;
			return;
		}
		af[i+1]+=diff;
		af[i]-=diff;
	}
	cout<<"Yes"<<endl;
}

int main() {
    FASTIO

    // solve();

   int t;
   cin>>t;
   while(t--)solve();

    return 0;
}
