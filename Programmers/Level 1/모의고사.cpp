#include <string>
#include <vector>

using namespace std;

int correctCount(vector<int>& answers, vector<int>& pattern) {
    int patternSize = pattern.size(), answerSize = answers.size();
    int answerCount = 0;
    for (int idx = 0; idx < answerSize; idx++) {
        if (answers[idx] == pattern[idx % patternSize])
            answerCount++;
    }
    return answerCount;
}

vector<int> solution(vector<int> answers) {
    vector<int> answer;
    vector<vector<int>> patterns =
    {
        {1, 2, 3, 4, 5},
        {2, 1, 2, 3, 2, 4, 2, 5},
        {3, 3, 1, 1, 2, 2, 4, 4, 5, 5}
    };

    int counts[3];
    int MAX = 0;
    for (int i = 0; i < 3; i++) {
        counts[i] = correctCount(answers, patterns[i]);
        if (counts[i] > MAX) MAX = counts[i];
    }
    for (int i = 0; i < 3; i++)
        if (counts[i] == MAX)
            answer.push_back(i + 1);

    return answer;
}