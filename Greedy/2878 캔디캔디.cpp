// 소스코드 풀이출처 : https://lyzqm.blogspot.com/2017/08/2878.html
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
typedef long long ll;
int N;
ll M, total;
vector<ll> f;
void input() {
	cin >> M >> N;
	int want;
	for (int i = 0; i < N; i++) {
		cin >> want;
		f.push_back(want);
		total += want;
	}
	sort(f.begin(), f.end());
	total -= M;
}

void solution() {
	ll answer = 0;
	for (int i = 0; i < N; i++) {
		ll temp = min(f[i], total / (N - i));
		answer += temp * temp;
		total -= temp;
	}
	cout << answer;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	input();
	solution();
	return 0;
}