#include <bits/stdc++.h>

#define sd(x) scanf("%d",&x)
#define sd2(x,y) scanf("%d%d",&x,&y)
#define sd3(x,y,z) scanf("%d%d%d",&x,&y,&z)

#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define foreach(it, v) for(auto it=(v).begin(); it != (v).end(); ++it)

#define _ ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define __ freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);

#define tr(...) cout<<__FUNCTION__<<' '<<__LINE__<<" = ";trace(#__VA_ARGS__, __VA_ARGS__)

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;

template<typename S, typename T> 
ostream& operator<<(ostream& out,pair<S,T> const& p){out<<'('<<p.fi<<", "<<p.se<<')';return out;}

template<typename T>
ostream& operator<<(ostream& out,vector<T> const& v){
int l=v.size();for(int i=0;i<l-1;i++)out<<v[i]<<' ';if(l>0)out<<v[l-1];return out;}

template<typename T>
void trace(const char* name, T&& arg1){cout<<name<<" : "<<arg1<<endl;}

template<typename T, typename... Args>
void trace(const char* names, T&& arg1, Args&&... args){
const char* comma = strchr(names + 1, ',');cout.write(names, comma-names)<<" : "<<arg1<<" | ";trace(comma+1,args...);}

const ld PI = 3.1415926535897932384626433832795;

void d(string &s, vector<pair<char, int> > &v){
	for(int i = 0; i < s.length(); i++){
		char c = s[i];
		int cnt = 1;
		i++;
		while(i < s.length() and s[i] == c){
			i++, cnt++;
		}
		i--;
		v.pb(mp(c,cnt));
	}
}

int main(){ _
	int t;
	cin >> t;
	while(t--){
		string a, b;
		cin >> a >> b;

		int n = a.length();
		int m = b.length();
		
		if(n < m){
			cout << "NO" << endl;
			continue;
		}
		
		vector<pair<char, int> > v1, v2;
		
		d(a, v1);
		d(b, v2);
		
		if(v2.size() != v1.size()){
			cout << "NO" << endl;
			continue;
		}
			
		bool ok = true;
		for(int i = 0; i < v2.size(); i++){
			if(v1[i].fi != v2[i].fi) ok = false;
			else if(v1[i].se < v2[i].se) ok = false;
		}
		
		if(ok){
			cout << "YES" << endl;
		}
		else{
			cout << "NO" << endl;
		}
	}
	return 0;
}
