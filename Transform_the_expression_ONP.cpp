#include<bits/stdc++.h>
using namespace std;
typedef long long ll;


void solve() {
	string s;
	cin >> s;

	stack<char> st;

	int i = 0;

	while (i < s.length()) {
		if (s[i] == '*' || s[i] == '/' || s[i] == '+' || s[i] == '-' || s[i] == '^') {

			//since ^ has the highest precedence of the group

			if (s[i] == '^') {
				// pushing if stack is empty or anyways.
				if (st.empty()) {
					st.push(s[i]);
				}
				else
					st.push(s[i]);
			}

			if (s[i] == '*' || s[i] == '/') {
				// if stack is empty just push the operator
				if (st.empty()) {
					st.push(s[i]);
				}
				else if (st.top() == '*' || st.top() == '/' || st.top() == '^') {
					//popping out all the operators till an operator of lower precedence is found
					while (st.top() != '+' && st.top() != '-' && st.top() != '(') {
						cout << s[i];
						st.pop();
						if (st.empty())
							break;
					}
					// then pushing it above the operator of lower precedence or to the empty stack
					st.push(s[i]);
				}
				else if (st.top() == '+' || st.top() == '-')
					st.push(s[i]);
				else
					st.push(s[i]);
			}
			else if (s[i] == '+' || s[i] == '-') {
				// same rule as above
				if (st.empty()) {
					st.push(s[i]);
				}
				else if (st.top() == '+' || st.top() == '-' || st.top() == '*' || st.top() == '/' || st.top() == '^') {
					// same rue as above
					while (!st.empty() && st.top() != '(') {
						cout << s[i];
						st.pop();
						if (st.empty())
							break;
					}
					st.push(s[i]);
				}
				else st.push(s[i]);
			}
		}
		else if (s[i] == '(')
			st.push(s[i]);
		else if (s[i] == ')') {
			//popping out all the operators, till opening paranthesis is found and stopping just before it.
			while (!st.empty() && st.top() != '(') {
				cout << st.top();
				st.pop();
			}
			//popping the opening paranthesis
			if (st.top() == '(')
				st.pop();
		}
		else
			cout << s[i];
		i++;
	}
	if (!st.empty()) {
		// checking if any operators are stll left. If so then print them out as in the stack.
		while (!st.empty()) {
			cout << st.top();
			st.pop();
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