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

ll n,m,rn=0;
map<vll,vll> dp; 
vector<vector<char>> arr;
vll res;

void solve(){
    int n,m;
    cin>>n>>m;

    arr.assign(n+1,vector<char>(m+1));
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++)cin>>arr[i][j];
    }


    for(int i=1;i<=n;i++){
        for(int j=1;j<=m-2;j++){
            if(arr[i][j]=='0')continue;
            if(i==n){
                res.push_back({i,j,i,j+1,i-1,j+1});

                arr[i][j]='0';
                
                if(arr[i][j+1]=='1')arr[i][j+1]='0';
                else arr[i][j+1]='1';

                if(arr[i-1][j+1]=='1')arr[i-1][j+1]='0';
                else arr[i-1][j+1]='1';
            }else{
                res.push_back({i,j,i,j+1,i+1,j+1});

                arr[i][j]='0';
                
                if(arr[i][j+1]=='1')arr[i][j+1]='0';
                else arr[i][j+1]='1';

                if(arr[i+1][j+1]=='1')arr[i+1][j+1]='0';
                else arr[i+1][j+1]='1';
            }
        }
    }

    

    cout<<res.size()<<endl;
    for(auto x: res){
        for(auto y: x)cout<<y<<" ";
        cout<<endl;
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
