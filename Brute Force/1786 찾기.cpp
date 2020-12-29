/* √‚√≥: https://11001.tistory.com/16 */
#include <iostream>
#include <limits.h>
#include <string>
using namespace std;
int N, answer;
string str;

int cal(int left, int right, char op) {
	switch (op)
	{
	case '+':
		left += right; break;
	case '-':
		left -= right; break;
	case '*':
		left *= right; break;
	default:
		break;
	}
	return left;
}

void solution(int idx, int cur) {
	if (idx >= N) {
		if (cur > answer) answer = cur;
		return;
	}
	char op = (idx == 0) ? '+' : str[idx - 1];
	if (idx + 2 < N) {
		int bracket = cal(str[idx]-'0', str[idx+2]-'0',str[idx+1]);
		solution(idx + 4, cal(cur, bracket, op));
	}
	solution(idx + 2, cal(cur, str[idx] - '0', op));
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> N >> str;
	answer = INT_MIN;
	solution(0, 0);
	cout << answer;
	
	return 0;
}