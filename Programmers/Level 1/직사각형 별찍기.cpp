#include <iostream>

using namespace std;

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cout << "*";
        }
        cout << "\n";
    }
    return 0;
}