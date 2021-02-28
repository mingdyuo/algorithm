// 참고 블로그 : https://jaimemin.tistory.com/823
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string str;
string bomb;

char answer[1000001];

void input() {
	cin >> str >> bomb;
}

void solution() {
	int index = 0;
	for (int i = 0; i < str.length(); i++) {
		answer[index++] = str[i];
		if (answer[index - 1] == bomb.back()) {
			if (index - bomb.length() < 0) continue;
			bool found = true;
			for (int j = 0; j < bomb.length(); j++) {
				if (answer[index - 1 - j] != bomb[bomb.length() - 1 - j]) {
					found = false;
					break;
				}
			}
			if (found) {
				index -= bomb.length();
			}
		}
	}
	answer[index] = '\0';
	if (index == 0) cout << "FRULA";
	else cout << answer;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	input();
	solution();
	return 0;
}