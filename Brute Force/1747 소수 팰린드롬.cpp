#include <iostream>
#include <string>
#include <math.h>
using namespace std;

int N;

void input() {
	cin >> N;
}

bool palindrome(int K) {
	string num = to_string(K);
	int len = num.length();
	if (len == 1) return true;
	int half = len / 2;
	

	int left, right;
	if (len % 2 == 1) {
		left = half + 1, right = half - 1;
	}
	else {
		left = half, right = half - 1;
	}

	for (int i = 0; i < half; i++) {
		if (num[left + i] != num[right - i]) return false;
	}
	return true;
}

bool prime(int K) {
	if (K % 2 == 0) return false;
	int root = sqrt(K);
	for (int i = 3; i <= root; i += 2)
		if (K % i == 0) return false;
	return true;
}

bool satisfy(int K) {
	if (palindrome(K) && prime(K)) return true;
	return false;
}

void solution() {
	if (N == 1 || N == 2) {
		cout << 2;
		return;
	}

	for (int i = N;; i++) {
		if (satisfy(i)) {
			cout << i;
			return;
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	input();
	solution();
	return 0;
}