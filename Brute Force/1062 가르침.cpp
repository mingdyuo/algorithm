#include <iostream>
#include <string>
#include <set>
#include <vector>
#include <algorithm>
using namespace std;

bool alpha[26];
vector<string> v;
int N, K, maxCount = 0;

void input()
{
    cin >> N >> K;
    string str;
    for (int i = 0; i < N; i++)
    {
        cin >> str;
        v.push_back(str.substr(4, str.length() - 8));
    }
    if (K < 5)
    {
        cout << 0;
        exit(0);
    }
    else if (K >= 26)
    {
        cout << N;
        exit(0);
    }
}

int validWord()
{
    bool possible;
    int possibleCount = 0;
    for (auto str : v)
    {
        possible = true;
        for (auto ch : str)
        {
            if (!alpha[ch - 'a'])
            {
                possible = false;
                break;
            }
        }
        if (possible)
            possibleCount++;
    }
    return possibleCount;
}

void dfs(int index, int count)
{
    if (count == K)
    {
        maxCount = max(maxCount, validWord());
        return;
    }

    for (int i = index; i < 26; i++)
    {
        if (alpha[i] == true)
            continue;
        alpha[i] = true;
        dfs(i, count + 1);
        alpha[i] = false;
    }
}

void solution()
{
    alpha['a' - 'a'] = true;
    alpha['n' - 'a'] = true;
    alpha['t' - 'a'] = true;
    alpha['i' - 'a'] = true;
    alpha['c' - 'a'] = true;
    K -= 5;

    dfs(0, 0);
    cout << maxCount << endl;
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