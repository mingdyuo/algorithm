#include <string>
#include <vector>
#include <map>
#include <set>
using namespace std;

int solution(string skill, vector<string> skill_trees) {
    int answer = 0;
    map<char, char> prevSkill;
    for (int i = 0; i < skill.length() - 1; i++) {
        prevSkill[skill[i + 1]] = skill[i];
    }
    for (auto& tree : skill_trees) {
        set<char> learned;
        bool possible = true;
        for (auto skill : tree) {
            map<char, char>::iterator prevIt = prevSkill.find(skill);
            if (prevIt == prevSkill.end()) {
                learned.insert(skill);
            }
            else {
                if (learned.find(prevIt->second) == learned.end()) {
                    possible = false;
                    break;
                }
                else {
                    learned.insert(skill);
                }
            }
        }
        if (possible) answer++;
    }
    return answer;
}

