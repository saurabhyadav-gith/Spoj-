#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define gcd(a,b) (__gcd(a,b))
#define lcm(a,b) ((a*b)/gcd(a,b))
vector<ll> soe(ll n) {ll *arr = new ll[n + 1]; vector<ll>ans; for (ll i = 0; i <= n; i++) {arr[i] = 1;} arr[0] = 0; arr[1] = 0; for (ll i = 2; i <= sqrt(n); i++) {if (arr[i] == 1) {for (ll j = 2; i * j <= n; j++) {arr[i * j] = 0;}}} for (ll i = 0; i <= n; i++) {if (arr[i] == 1)ans.push_back(i);} return ans;}

const ll mod = 1e9 + 7;
/* ncr = n-1cr-1+ n-1cr  */

/******************************************************************/

void solve() {
	int n;
	cin >> n;
	int arr[n];
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	int flag = 0;
	for (int i = n - 2 ; i >= 0; i--) {
		if (arr[i] < arr[i + 1]) {
			int val = INT_MAX;
			int ans = 0, idx = -1;
			for (int j = n - 1; j > i; j--) {

				if (arr[j] > arr[i]) {
					swap(arr[i], arr[j]);
					flag = 1;
					sort(arr + i + 1, arr + n);
					break;
				}
			}
			if (flag == 1)
				break;
		}

	}
	if (flag == 0)
		cout << -1 << endl;
	else {
		for (int i = 0; i < n; i++) {
			cout << arr[i];
		}
	}
	cout << endl;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
#ifndef ONLINE_JUDGE
	freopen("inputf.in", "r", stdin);
	freopen("outputf.in", "w", stdout);
#endif
	int test;
	cin >> test;
	while (test--) {
		solve();
	}
}