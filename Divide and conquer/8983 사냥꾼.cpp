#include <iostream>
#include <math.h>
#include <vector>
#include <algorithm>
using namespace std;
int sadae, animal, range;
vector<pair<int, int>> location;
vector<int> gun;

bool check(vector<int>& gun, int xVal, int yVal) {
	int upper = range + xVal - yVal, lower = xVal + yVal - range;
	int left = 0, right = gun.size() - 1, mid;
	while (left <= right) {
		mid = (left + right) / 2;
		if (lower <= gun[mid] && gun[mid] <= upper) 
			return true;
		else if (gun[mid] < lower) left = mid+1;
		else right = mid - 1;
	}
	return false;
}

void input() {
	cin >> sadae >> animal >> range;
	int xValue, yValue;
	
	for (int i = 0; i < sadae; i++) {
		cin >> xValue;
		gun.push_back(xValue);
	}
	sort(gun.begin(), gun.end());
	int answer = 0;
	for (int i = 0; i < animal; i++) {
		cin >> xValue >> yValue;
		if (yValue > range) continue;
		if (check(gun, xValue, yValue))
			answer++;
	}
	cout << answer;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	input();
	return 0;
}