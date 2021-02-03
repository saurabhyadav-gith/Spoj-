#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define gcd(a,b) (__gcd(a,b))
#define lcm(a,b) ((a*b)/gcd(a,b))
vector<ll> soe(ll n) {ll *arr = new ll[n + 1]; vector<ll>ans; for (ll i = 0; i <= n; i++) {arr[i] = 1;} arr[0] = 0; arr[1] = 0; for (ll i = 2; i <= sqrt(n); i++) {if (arr[i] == 1) {for (ll j = 2; i * j <= n; j++) {arr[i * j] = 0;}}} for (ll i = 0; i <= n; i++) {if (arr[i] == 1)ans.push_back(i);} return ans;}

const ll mod = 1e9 + 7;
/* ncr = n-1cr-1+ n-1cr  */

/******************************************************************/

void solve(string s, int n) {
	// int i = 0;
	stack<char>st;

	int i = 0;
	int ans = 0;
	while (i < s.length()) {
		if (s[i] == '{') {
			st.push(s[i]);
		}
		else if (s[i] == '}' and !st.empty() and st.top() == '{')
			st.pop();
		else {
			ans++;
		}
		i++;
	}

	// if (ans == 1 && st.size () == 1) {
	// 	cout << n << "." << " " << ans + st.size() << endl;
	// 	return;
	// }
	// else if (ans == 1 && st.size() > 1) {
	// 	int val =  st.size() / 2;
	// 	int clea = st.size() - 2 * val;
	// 	cout << n << "." << " " << clea + ans + val << endl;
	// 	return;
	// }
	// else if (ans > 1 && st.size() == 1) {
	// 	int val =  ans / 2;
	// 	int clea = ans - 2 * val;
	// 	cout << n << "." << " " << clea + st.size() + val << endl;
	// 	return;
	// }
	int val = ans / 2;
	int cel = st.size() / 2;
	cout << n << "." << " " << (ans - (2 * val)) + (st.size() - (2 * cel)) + val + cel << endl;

}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
#ifndef ONLINE_JUDGE
	freopen("inputf.in", "r", stdin);
	freopen("outputf.in", "w", stdout);
#endif

	int n = 1;
	while (1) {
		string s;
		cin >> s;
		if (s[0] == '-')
			break;
		solve(s, n);
		n++;
	}
}