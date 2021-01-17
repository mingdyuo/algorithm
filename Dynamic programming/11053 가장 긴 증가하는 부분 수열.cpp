#include <iostream>
#include <cstring>
using namespace std;

int arr[1001];
int sol[1001];
int N;
void solution() {
	int maxAns = 0;
	for (int i = 1; i < N; i++) {
		int count = 0;
		for (int j = 0; j < i; j++) {
			if (arr[i] > arr[j] && count < sol[j]) {
				count = sol[j];
			}
		}
		sol[i] = count + 1;
		if (sol[i] > maxAns) maxAns = sol[i];
	}
	for (int i = 0; i < N; i++){
		cout << sol[i] << " ";
	}
	cout << endl;

	cout << maxAns;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
		sol[i] = 1;
	}
	solution();
	return 0;
}