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

void solve()
{
	ll l, r;
	cin>>l>>r;
	
	vector<ll> cntL(10, 0ll), cntR(10, 0ll);
	ll resL = 0, resR = 0;
	
	//0 -> l-1
	ll n = l-1;
	if(l>1)
	{
		ll muoi = 1;
		ll cuoi = 0;
		while(n>=10)
		{
			ll cs = n%10;
			ll dau = n/10;
			debug(cs, dau);
			for(ll i=0;i<cs;i++) cntL[i] += (dau+1)*muoi;
			cntL[cs] += dau*muoi + (cuoi+1);
			for(ll i=cs+1;i<=9;i++) cntL[i] += dau*muoi;
			n /= 10;
			cuoi += muoi*cs;
			muoi *= 10;
		}
		for(ll i=1;i<n;i++) cntL[i] += muoi;
		cntL[n] += cuoi+1;
		debug(cntL);
		for(ll i=0;i<=9;i++) resL += i*cntL[i];
		debug(resL);
	}
	
	//0 -> r
	n = r;
	ll muoi = 1;
	ll cuoi = 0;
	while(n>=10)
	{
		ll cs = n%10;
		ll dau = n/10;
		debug(cs, dau);
		for(ll i=0;i<cs;i++) cntR[i] += (dau+1)*muoi;
		cntR[cs] += dau*muoi + (cuoi+1);
		for(ll i=cs+1;i<=9;i++) cntR[i] += dau*muoi;
		n /= 10;
		cuoi += muoi*cs;
		muoi *= 10;
		debug(cntR);
	}
	for(int i=1;i<n;i++) cntR[i] += muoi;
	debug(n);
	cntR[n] += cuoi+1;
	debug(cntR);
	for(ll i=0;i<=9;i++) resR += i*cntR[i];
	debug(resR);
	
	// result
	cout<<resR-resL<<endl;
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
