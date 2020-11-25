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
    
    vll idx(n+1);
    for(int i=0;i<n;i++){
        int temp;
        cin>>temp;
        idx[temp].push_back(i);
    }

    int res=INT_MAX;
    for(int i=1;i<=n;i++){
        if(idx[i].empty())continue;
        int count=0;

        for(int j=0;j<idx[i].size();j++){
            if(j==0){
                count+=idx[i][j]!=0;
                // if(j!=0)printf("-- %d %d\n",i,idx[i][j]);
            }else{
                count+=idx[i][j-1]+1!=idx[i][j];
                // if(idx[i][j-1]+1!=idx[i][j])printf("-- %d %d\n",i,idx[i][j]);
            }

            if(j==idx[i].size()-1){
                count+=idx[i][j]!=n-1;
                // if(j!=n-1)printf("-- %d %d\n",i,idx[i][j]);
            }
        }

        // printf("\n>> %d %d\n",i,count);
        res=min(res,count);
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
