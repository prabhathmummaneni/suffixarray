#include <bits/stdc++.h>
#include <fstream>
using namespace std;
#define ll long long
#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define bs binary_search
#define vl vector<ll>
#define pll pair<ll,ll>
#define vpl vector<pair<ll,ll> >
#define mll map<ll,ll>
#define mcl map<char,ll>
#define pqll priority_queue<ll>
#define mpl map<pair<ll,ll>,ll >
#define msl map<string,ll>
#define mset(a,k) memset(a,k,sizeof(a));
#define len length()
#define fr(a,b,c) for(ll a=b;a<c;a++)
void in(ll *a,ll n){fr(i,0,n){cin>>a[i];}}
void out(ll *a,ll n){fr(i,0,n){cout<<a[i]<<" ";}}
void out(vl v){fr(i,0,(ll)v.size())cout<<v[i]<<"\n";}
void out(ll a){cout<<a;}
void out(string s){cout<<s;}
void fast(){
ios_base::sync_with_stdio(false);
cin.tie(NULL);
cout.tie(NULL);
}
     
     
int main(){
	string s;
	cin>>s;
	ll n=s.len;
	pair<pll,ll> p[n];
	fr(i,0,n){
		if(i<n-1)
			p[i]=mp(mp(s[i]-'a',s[i+1]-'a'),i);
		else
			p[i]=mp(mp(s[i]-'a',-1),i);
	}
	ll a[n];
	sort(p,p+n);
	ll rank=0;
	pll prev;
	fr(i,0,n){
		if(i==0){
			a[p[i].ss]=i;
			prev=p[i].ff;
			p[i].ff.ff=i;
		}
		else{
			if(prev!=p[i].ff){
				rank++;
				a[p[i].ss]=rank;
				prev=p[i].ff;
				p[i].ff.ff=rank;
			}
			else{
				a[p[i].ss]=rank;
				p[i].ff.ff=rank;
			}
		}
	}
	ll k=2;
	
	while(k<=n){
		fr(i,0,n){
			ll d=p[i].ss+k;
			if(d<n){
				p[i].ff.ss=a[d];
			}
			else{
				p[i].ff.ss=-1;		
			}
		}
		sort(p,p+n);
		ll rank=0;
		pll prev;
		fr(i,0,n){
			if(i==0){
				a[p[i].ss]=i;
				prev=p[i].ff;
				p[i].ff.ff=i;
			}
			else{
				if(prev!=p[i].ff){
					rank++;
					a[p[i].ss]=rank;
					prev=p[i].ff;
					p[i].ff.ff=rank;
				}
				else{
					a[p[i].ss]=rank;
					
					p[i].ff.ff=rank;
				}
				
			}
		}
		/*fr(i,0,n){
			cout<<p[i].ss<<"\n";
		}
		cout<<"------------------\n";*/
		k=k*2;
	}
	fr(i,0,n){
		cout<<p[i].ss<<"\n";
	}
}
