#include <bits/stdc++.h>
using namespace std;

string reverseParentheses(string str, int len){
	stack<int> st;
	for (int i = 0; i < len; i++) {
		if (str[i] == '(') {
			st.push(i);
		}
		else if (str[i] == ')') {
			reverse(str.begin() + st.top() + 1,
					str.begin() + i);
			st.pop();
		}
	}
	string res = "";
	for (int i = 0; i < len; i++) {
		if (str[i] != ')' && str[i] != '(')
			res += (str[i]);
	}
	return res;
}

int main()
{
	string str = "(skeeg(for)skeerg)";
	int len = str.length();

	cout << reverseParentheses(str, len);

	return 0;
}
