#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int N;
struct lottery {
	int index, w, q;
	lottery(int i, int w, int q) :index(i), w(w), q(q) {};
};
vector<lottery> lot;
bool compare(const lottery& a, const lottery& b) {
	if (a.w * (10000 - b.q) == b.w * (10000 - a.q)) {
		return a.index < b.index;
	}
	return a.w * (10000 - b.q) > b.w * (10000 - a.q);
}
void input() {
	cin >> N;
	int w, q;
	for (int i = 1; i <= N; i++) {
		cin >> w >> q;
		lot.push_back(lottery(i, w, q));
	}
}

void solution() {
	sort(lot.begin(), lot.end(), compare);
	for (auto l : lot) {
		cout << l.index << " ";
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	input();
	solution();
	return 0;
}