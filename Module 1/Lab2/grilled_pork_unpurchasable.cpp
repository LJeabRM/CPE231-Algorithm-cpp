#include<iostream>
#include<vector>
#include<algorithm>
#include<numeric>

using namespace std;

// Function to find the largest number of grilled pork sticks that cannot be purchased
int findLargestUnpurchasable(int p1, int p2, int p3, int p4, int n) {
    // Create a dynamic programming array to keep track of possible sums
    vector<int> dp(n + 1, 0);
    dp[0] = 1; // Base case: sum of 0 is always possible

    // Loop through all possible combinations of boxes
    for (int i = 0; i <= n / p1; ++i) { // Loop for box 1
        for (int j = 0; j <= n / p2; ++j) { // Loop for box 2
            for (int k = 0; k <= n / p3; ++k) { // Loop for box 3
                for (int m = 0; m <= n / p4; ++m) { // Loop for box 4
                    int sum = i * p1 + j * p2 + k * p3 + m * p4; // Calculate the sum of selected boxes
                    if (sum <= n) { // If the sum does not exceed n, mark it as possible
                        dp[sum] = 1;
                    }
                }
            }
        }
    }

    // Find the largest number that cannot be purchased
    for (int i = n; i >= 0; --i) { // Loop backward to find the largest impossible sum
        if (dp[i] == 0) { // If the sum is not possible, return this sum
            return i;
        }
    }
    return -1; // If all sums are possible, return -1
}

int main() {
    // Input the quantities of grilled pork in each box and the maximum number of sticks
    int p1, p2, p3, p4, n;
    cin >> p1 >> p2 >> p3 >> p4 >> n; 

    // Find and output the largest number of pork sticks that cannot be purchased
    int result = findLargestUnpurchasable(p1, p2, p3, p4, n);
    cout << result << endl;

    return 0;
}
