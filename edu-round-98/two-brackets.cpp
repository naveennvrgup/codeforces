#include <bits/stdc++.h>
using namespace std;
#define FASTIO  ios_base::sync_with_stdio(0);cin.tie(0);

typedef long long ll;
typedef pair<ll, ll> pll;
typedef pair<int,int> pii;
typedef vector<ll> vl;
typedef vector<string> vs;
typedef vector<vl> vll;

const ll mx = 1e9 + 7;
const ll inf = 1e18;

void solve(){
    string s;
    cin>>s;

    int sq=0,nml=0,res=0;
    for(int i=0;i<s.size();i++){
        if(s[i]=='[')sq++;
        else if(s[i]==']'){
            if(sq>0){
                sq--;
                res++;
            }
        } else if(s[i]=='(')nml++;
        else {
            if(nml>0){
                nml--;
                res++;
            }
        }

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
