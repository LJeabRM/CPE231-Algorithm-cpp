#include<iostream>
#include<vector>

using namespace std;

// Recursive function to calculate the factorial of a number n
int Factorial(int n)
{
    if (n == 0) { // Base case: if n is 0, return 1
        return 1; 
    }
    else {
        return Factorial(n - 1) * n; // Recursive case: Factorial(n) = n * Factorial(n-1)
    }
}

int main(){
    // Input: Number of students and their position in the line
    int n, v, p;
    cin >> n >> v;

    // Creating a vector to store student IDs
    vector<int> S(n);

    // Input student IDs
    for (int i = 0; i < n; i++) {  // Loop to input student IDs
        cin >> S[i];
    }

    // Input the number of students who don't want to receive from a specific teacher
    cin >> p;

    // Creating a vector to store IDs of students who don't want to receive from the teacher
    vector<int> s(p);
    for (int i = 0; i < p; i++) { // Loop to input these student IDs
        cin >> s[i];
    }

    // Calculate the number of ways students can be arranged while respecting the given restrictions
    int result = (Factorial(n - 1) / Factorial(n - 1 - p)) * Factorial(n - p);  // Using combination formula

    // Output the result
    cout << result << endl;

    return 0;
}
