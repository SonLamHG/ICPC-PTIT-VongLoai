#include<bits/stdc++.h>
#define int long long

using namespace std;
char sinh(char a, char b){
    for(char c:{'R', 'G', 'B'}){
        if(c!=a && c!=b){
            return c;
        }
    }
}

main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);

    int n; cin>>n;
    string s; cin>>s;

    int R[4001]={0}, G[4001]={0}, B[4001]={0};
    for(int i=n-1; i>=0; i--){
        G[i]=G[i+1];
        R[i]=R[i+1];
        B[i]=B[i+1];
        if(s[i]=='G') G[i]++;
        if(s[i]=='R') R[i]++;
        if(s[i]=='B') B[i]++;
    }

    int ans=0;
    for(int i=0; i<n; i++){
        for(int j=i+1; j<n; j++){
            if(s[i]!=s[j]) {
                char c=sinh(s[i],s[j]);
                if(c=='R') ans+=R[j+1];
                if(c=='G') ans+=G[j+1];
                if(c=='B') ans+=B[j+1];
                int k=j+(j-i);
                if(k<n && s[k]==c) ans--;
            }
        }
    }

    cout<<ans;


    return 0;
}
