#include<bits/stdc++.h>
#define int long long

using namespace std;

main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);

    int m; cin>>m;
    int ans=0;
    for(int n=1; n<=1e7; n++){
        if(2*m-n*n>=1 && (2*m-n*n)%n==0){
            int t=(2*m-n*n)/n;
            t--;
            if(t%2==0) ans+=2;
        }
    }

    cout<<ans;

    return 0;
}
