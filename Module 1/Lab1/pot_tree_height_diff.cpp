#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>

using namespace std;

int main(){

    // Step 0: Input the number of pots and trees 
    int n;
    cin >> n; // Number of pots and trees

    vector<int> t(n);  // Tree heights
    vector<int> p(n);  // Pot heights
    vector<int> sum(n); // Sum of pot and tree heights
    
    // Input the heights of the pots
    for (int i = 0; i < n; i++) {
        cin >> p[i];
    }
    
    // Input the heights of the trees
    for (int i = 0; i < n; i++) {
        cin >> t[i];
    }

    // Step 1: Sort the pot heights in descending order
    sort(p.begin(), p.end(), greater<int>());
    
    // Step 2: Sort the tree heights in ascending order
    sort(t.begin(), t.end());

    // Step 3: Combine the sorted heights of pots and trees
    for (int i = 0; i < n; i++) {
        sum[i] = p[i] + t[i];  // Combine the respective pot and tree height
    }

    // Step 4: Sort the combined heights in descending order
    sort(sum.begin(), sum.end(), greater<int>());
    
    // Step 5: Calculate the sum of absolute differences between consecutive heights
    int sumdiff = 0;
    for (int i = 0; i < n - 1; i++) {
        sumdiff += abs(sum[i] - sum[i + 1]);  // Calculate the absolute difference
    }

    // Step 6: Output the result
    cout << sumdiff << endl;

    return 0;
}
