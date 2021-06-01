#include <iostream>
#include <queue>
#include <functional>
#include <algorithm>
using namespace std;


void solution() {
	int operationCount, operand;
	char operation;
	cin >> operationCount;

	priority_queue<pair<int, int>> pq_dsc;
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>> > pq_asc;
	
	vector<bool> deleted(operationCount, false);

	for (int i = 0; i < operationCount; i++)
	{
		cin >> operation >> operand;
		if (operation == 'I')
		{
			pq_asc.push({ operand, i });
			pq_dsc.push({ operand, i });
			continue;
		}

		while (!pq_asc.empty() && deleted[pq_asc.top().second])
		{
			pq_asc.pop();
		}
		while (!pq_dsc.empty() && deleted[pq_dsc.top().second])
		{
			pq_dsc.pop();
		}

		
		if (!pq_dsc.empty() && operand == 1) // ÃÖ´ñ°ª »èÁ¦
		{
			deleted[pq_dsc.top().second] = true;
			pq_dsc.pop();
		}
		else if (!pq_asc.empty() && operand == -1) // ÃÖ¼Ú°ª »èÁ¦
		{
			deleted[pq_asc.top().second] = true;
			pq_asc.pop();
		}
	}

	while (!pq_asc.empty() && deleted[pq_asc.top().second])
	{
		pq_asc.pop();
	}
	while (!pq_dsc.empty() && deleted[pq_dsc.top().second])
	{
		pq_dsc.pop();
	}

	if (pq_asc.empty() || pq_dsc.empty())
	{
		cout << "EMPTY\n";
	}
	else
	{
		cout << pq_dsc.top().first << " " << pq_asc.top().first << "\n";
	}
	
}

void input() {
	int testcase;
	cin >> testcase;
	for (int i = 0; i < testcase; i++)
	{
		solution();
	}
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	input();

	return 0;
}