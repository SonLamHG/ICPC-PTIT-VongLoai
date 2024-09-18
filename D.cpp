#include<bits/stdc++.h>
#define int long long

using namespace std;

main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);

    int n; cin>>n;
    if(n<=9){
        cout<<n;
        return 0;
    }

    queue<string> q;
    for(string i:{"1","2","3","4","5","6","7","8","9"}) q.push(i);

    int cnt=9;
    while (q.size()){
        string s=q.front(); q.pop();
        char c=s.back();
        for(int i:{-1,0,1}){
            if(c+i>='0' && c+i<='9'){
                string tmp=s;
                tmp.push_back(c+i);
                q.push(tmp);
                cnt++;
                if(cnt==n){
                    cout<<tmp;
                    return 0;
                }
            }
        }
    }

    return 0;
}
