#include<bits/stdc++.h>
using namespace std;
typedef long long ll;


void solve() {
	int n;
	cin >> n;
	int arr[n];

	//initializing the array

	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	int flag = 0;
	for (int i = n - 2 ; i >= 0; i--) {
		//traversing to find the element which is smaller from the neighbor
		if (arr[i] < arr[i + 1]) {
			int val = INT_MAX;
			int ans = 0, idx = -1;
			for (int j = n - 1; j > i; j--) {
				// traversing to swap the smallest i-th element found with the element larger than it to the left
				if (arr[j] > arr[i]) {
					swap(arr[i], arr[j]);
					flag = 1;
					// sorting the array after the swap and after the i-th position to find the smallest next permutation
					sort(arr + i + 1, arr + n);
					break;
				}
			}
			if (flag == 1)
				break;
		}

	}
	// -1 if the answer does not exist.
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