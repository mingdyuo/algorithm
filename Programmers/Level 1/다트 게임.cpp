#include <string>
using namespace std;

int bonusScore(int score, char bonus) {
    switch (bonus) {
    case 'S':
        return score;
    case 'D':
        return score * score;
    case 'T':
        return score * score * score;
    default:
        break;
    }
}

int solution(string dartResult) {
    int totalScore = 0, prevScore = 0;
    int strLen = dartResult.length();
    for (int i = 0; i < strLen; ) {
        int score, bScore;
        char bonus, option;
        if (isdigit(dartResult[i + 1])) {
            score = 10;
            bonus = dartResult[i + 2];
            i = i + 3;
        }
        else {
            score = dartResult[i] - '0';
            bonus = dartResult[i + 1];
            i = i + 2;
        }
        bScore = bonusScore(score, bonus);

        if (dartResult[i] == '*') {
            totalScore += bScore * 2 + prevScore;
            prevScore = bScore * 2;
            i++;
        }
        else if (dartResult[i] == '#') {
            totalScore -= bScore;
            prevScore = -bScore;
            i++;
        }
        else {
            totalScore += bScore;
            prevScore = bScore;
        }
    }

    return totalScore;
}