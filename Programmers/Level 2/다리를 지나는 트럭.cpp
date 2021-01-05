#include <string>
#include <vector>

using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights) {
    int ticks = 1, size = truck_weights.size();
    vector<int> locations(size, 0);
    int first = 0, last = 0;
    int totalWeight = truck_weights[0];
    locations[0] = 0;
    while (first <= last) {
        for (int ptr = first; ptr <= last; ptr++) {
            if (++locations[ptr] >= bridge_length) {
                totalWeight -= truck_weights[ptr];
                first++;
            }
        }
        if (last != size - 1 && truck_weights[last + 1] + totalWeight <= weight) {
            totalWeight += truck_weights[last + 1];
            last++;
        }
        ticks++;
    }
    return ticks;
}
