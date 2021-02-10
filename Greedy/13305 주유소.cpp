#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

typedef long long ll;

ll answer;
int cityCount;
vector<ll> roads;
vector<ll> city;

void input()
{
    cin >> cityCount;
    roads.resize(cityCount - 1);
    city.resize(cityCount);
    for (int i = 0; i < cityCount - 1; i++)
    {
        cin >> roads[i];
    }
    for (int i = 0; i < cityCount; i++)
    {
        cin >> city[i];
    }
}

void solution()
{
    int prevCost = city[0];
    for (int i = 0; i < cityCount - 1; i++)
    {
        if (prevCost > city[i])
        {
            prevCost = city[i];
        }
        answer += prevCost * roads[i];
    }
    cout << answer;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    input();
    solution();
    return 0;
}