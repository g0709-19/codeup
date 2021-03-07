#include <iostream>
#include <string>
#include <stack>

using namespace std;

int main() {
	string str;
	cin >> str;
	
	int len = str.length();
	stack<int> stack;

	for (int i = 0; i < len; ++i) {
		int c = str.at(i);
		
		// opening
		if (c == '(' || c == '[') {
			stack.push(c);
		}
		// closing
		else if (c == ')' || c == ']') {
			int sum = 0;
			while (!stack.empty()) {
				int temp = stack.top();
				stack.pop();
				if (c == ')' && temp == '(') {
					stack.push(sum == 0 ? 2 : 2 * sum);
					break;
				}
				else if (c == ']' && temp == '[') {
					stack.push(sum == 0 ? 3 : 3 * sum);
					break;
				}
				// Add all if numbers
				sum += temp;
			}

		}
	}
	
	// Add all remains
	int answer = 0;
	while (!stack.empty()) {
		int c = stack.top();
		stack.pop();
		// return 0 unless right expressions
		if (c == '(' || c == ')' || c == '[' || c == ']') {
			answer = 0;
			break;
		}
		answer += c;
	}

	cout << answer << '\n';

	return 0;
}