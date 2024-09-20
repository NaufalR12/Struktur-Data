#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool isPossible(vector<int>& heights, int targetHeight, int currentIndex, vector<int>& currentStack) {
    if (targetHeight == 0) {
        return true;
    }

    if (currentIndex == heights.size() || targetHeight < 0) {
        return false;
    }

    // Include the current book in the current stack
    currentStack.push_back(heights[currentIndex]);
    if (isPossible(heights, targetHeight - heights[currentIndex], currentIndex + 1, currentStack)) {
        return true;
    }
    currentStack.pop_back(); // Backtrack

    // Exclude the current book from the current stack
    if (isPossible(heights, targetHeight, currentIndex + 1, currentStack)) {
        return true;
    }

    return false;
}

int main() {
    int n;
    cout << "Masukkan jumlah tumpukan buku: ";
    cin >> n;

    vector<int> heights(n);

    cout << "Masukkan tinggi buku untuk setiap tumpukan:\n";
    for (int i = 0; i < n; i++) {
        cin >> heights[i];
    }

    sort(heights.begin(), heights.end(), greater<int>()); // Sort in descending order for efficient filtering

    int totalHeight = 0;
    for (int height : heights) {
        totalHeight += height;
    }

    if (totalHeight % 2 != 0) {
        cout << "Tidak mungkin membagi tumpukan buku menjadi dua tumpukan dengan total tinggi yang sama.\n";
        return 0;
    }

    int targetHeight = totalHeight / 2;

    vector<int> stack1;
    if (isPossible(heights, targetHeight, 0, stack1)) {
        // Calculate the other stack
        vector<int> stack2;
        for (int i = 0; i < n; i++) {
            if (find(stack1.begin(), stack1.end(), heights[i]) == stack1.end()) {
                stack2.push_back(heights[i]);
            }
        }

        cout << "Tumpukan buku dengan total tinggi yang sama:\n";
        cout << "Tumpukan 1: ";
        for (int height : stack1) {
            cout << height << " ";
        }
        cout << "\nTumpukan 2: ";
        for (int height : stack2) {
            cout << height << " ";
        }
    } else {
        cout << "Tidak mungkin membagi tumpukan buku menjadi dua tumpukan dengan total tinggi yang sama.\n";
    }

    return 0;
}
