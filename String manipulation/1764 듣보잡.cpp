#include <iostream>
#include <map>
#include <string>
#include <vector>
using namespace std;

int heard, seen;

void input() {
	cin >> heard >> seen;
}

void solution() {
	string name;
	map<string, int> count;
	for (int i = 0; i < heard; i++)
	{
		cin >> name;
		count[name]++;
	}

	for (int j = 0; j < seen; j++)
	{
		cin >> name;
		count[name] ++;
	}

	vector<string> answer;
	for (auto& n : count)
	{
		if (n.second == 2)
		{
			answer.push_back(n.first);
		}
	}

	cout << answer.size() << '\n';
	for (auto& n : answer)
	{
		cout << n << '\n';
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	input();
	solution();
	return 0;
}