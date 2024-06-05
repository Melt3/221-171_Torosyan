#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Box {
    int weight;
    int capacity;
};

bool compareBoxes(const Box& a, const Box& b) {
    return a.capacity < b.capacity;
}

int main() {
    int n;
    cin >> n;
    
    vector<Box> boxes(n);
    for (int i = 0; i < n; ++i) {
        cin >> boxes[i].weight >> boxes[i].capacity;
    }
    
    sort(boxes.begin(), boxes.end(), compareBoxes); // Исправлено: передача функции сортировки
    
    vector<int> dp(n, 1);
    
    int maxBoxes = 1;
    
    for (int i = 1; i < n; ++i) {
        for (int j = 0; j < i; ++j) {
            if (boxes[j].weight + boxes[i].weight <= boxes[i].capacity) {
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }
        maxBoxes = max(maxBoxes, dp[i]);
    }
    
    cout << maxBoxes << endl;
    
    return 0;
}
