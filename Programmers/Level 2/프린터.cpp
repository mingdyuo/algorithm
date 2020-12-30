#include <string>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

struct docu {
    int priority, location;
    docu(int p, int l) :priority(p), location(l) {};
};


int solution(vector<int> priorities, int location) {
    int answer = 0, priSize = priorities.size();
    int lastPri = location, targetPri = priorities[location];
    int index;
    priority_queue<int> pq(priorities.begin(), priorities.end());
    queue<docu> q;
    for (int i = 0; i < priSize; i++) {
        q.push(docu(priorities[i], i));
    }
    while (true) {
        int pqFirst = pq.top();
        docu qFirst = q.front();
        if (pqFirst > qFirst.priority) {
            q.pop();
            q.push(qFirst);
        }
        else if (pqFirst == qFirst.priority) {
            pq.pop();
            q.pop();
            answer++;
            if (location == qFirst.location) {
                break;
            }
        }
    }

    return answer;
}