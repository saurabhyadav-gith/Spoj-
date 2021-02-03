#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define gcd(a,b) (__gcd(a,b))
#define lcm(a,b) ((a*b)/gcd(a,b))
vector<ll> soe(ll n) {ll *arr = new ll[n + 1]; vector<ll>ans; for (ll i = 0; i <= n; i++) {arr[i] = 1;} arr[0] = 0; arr[1] = 0; for (ll i = 2; i <= sqrt(n); i++) {if (arr[i] == 1) {for (ll j = 2; i * j <= n; j++) {arr[i * j] = 0;}}} for (ll i = 0; i <= n; i++) {if (arr[i] == 1)ans.push_back(i);} return ans;}

const ll mod = 1e9 + 7;
/* ncr = n-1cr-1+ n-1cr  */

/******************************************************************/

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
#ifndef ONLINE_JUDGE
	freopen("inputf.in", "r", stdin);
	freopen("outputf.in", "w", stdout);
#endif
	while (1) {
		int test;
		cin >> test;
		int n = test;
		if (test == 0)
			break;
		vector<int>vc;
		while (test--) {
			int val;
			cin >> val;
			vc.push_back(val);
		}

		int i = 0;
		stack<int>st;

		// need variable will help us match with the next element that we want
		int need = 1;
		while (i < vc.size()) {
			//if the top of the stack  matches the number we want we pop
			while (!st.empty() && st.top() == need) {
				need++;
				st.pop();
			}
			//if the number does not match we push in the stack
			if (vc[i] != need) {
				st.push(vc[i]);
			}
			//else we increment need
			else if (vc[i] == need) {
				need++;
			}


			i++;
		}

		//it might be that the number are still in stack so checking for possibilities
		while (!st.empty() && st.top() == need) {
			need++;
			st.pop();
		}
		//after the last iteration we will be one ahead of the need that is why checking for the n+1 match.
		if (need == n + 1)
			cout << "yes" << endl;
		else
			cout << "no" << endl;
	}

}