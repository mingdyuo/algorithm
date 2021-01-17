#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;

long long I;
int N, L;
long long binary[33][33];
string answer = "";

void input() {
	cin >> N >> L >> I;
}

long long dp(int n, int m) {
	if (binary[n][m] != -1) return binary[n][m];
	if (n == 0 || m == 0) {
		return binary[n][m] = 1;
	}
	
	binary[n][m] = dp(n - 1, m);
	if (m > 0) binary[n][m] += dp(n - 1, m - 1);
	return binary[n][m];
}

void printNumber(int n, int l, long long i) {
	if (n == 0) return;
	if (l == 0) {
		while (n--) answer+= "0";
		return;
	}
	long long pivot = dp(n - 1, l);
	if (i <= pivot) {
		answer += "0";
		printNumber(n - 1, l, i);
	}
	else {
		answer += "1";
		printNumber(n - 1, l - 1, i - pivot);
	}
	return;

}

void solution() {
	memset(binary, -1, sizeof(binary));

	printNumber(N, L, I);
	cout << answer;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	input();
	solution();
	return 0;
}
