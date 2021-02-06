#include <string>
#include <vector>
#include <algorithm>
using namespace std;

bool isRight(int dist, char op, int range) {
	switch (op) {
	case '=':
		return dist == range ? true : false;
	case '<':
		return dist < range ? true : false;
	case '>':
		return dist > range ? true : false;
	}
	return false;
}

int solution(int n, vector<string> data) {
	int answer = 0;
	string line = "ACFJMNRT";
	sort(line.begin(), line.end());

	do {
		bool isValid = true;
		for (auto elem : data) {
			int dist = line.find(elem[0]) - line.find(elem[2]);
			dist = abs(dist) - 1;
			if (!isRight(dist, elem[3], elem[4] - '0')) {
				isValid = false;
				break;
			}
		}
		if (isValid) answer++;
	} while (next_permutation(line.begin(), line.end()));

	return answer;
}