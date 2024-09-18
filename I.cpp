#include<bits/stdc++.h>
#define ll long long
#define onbit(n, i) (n|(1<<i))
#define checkbit(n, i) ((n>>i)%2)
#define fullbit(i) ((1<<i)-1)
#define fi first
#define se second
#define pb push_back
#define ii pair<int,int>
#define all(x) x.begin(),x.end()
#define MOD 1000000007
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <functional>
using namespace std;

#ifndef ONLINE_JUDGE
#include "debug.h"
#else
#define debug(...) 04
#endif

ll cnt[5000001] = {0};

void init()
{
	for(int i=1;i<=5000000;i++)
	{
		int d = i, s = 0;
		while(d!=0)
		{
			s += d%10;
			d /= 10;
		}
		cnt[i] += cnt[i-1] + s;
	}
}

void solve()
{
	int a, b;
	cin>>a>>b;
	cout<<cnt[b]-cnt[a-1]<<endl;
}

int main()
{
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
  #ifndef ONLINE_JUDGE
	freopen("test.inp", "r", stdin);
  #else
	#endif
	int t, test=0;
	bool multitest = 1;
	if(multitest==1) cin>>t; else t = 1;
	init();
	while(t--)
	{
		#ifndef ONLINE_JUDGE
			cout<<"--------------------Testcase "<<++test<<"--------------------\n";
		#else
			#endif
		solve();
	}
	return 0;
}
