#include <iostream>
#include <stack>
#include <vector>
#include <climits> // for INT_MIN

using namespace std;

vector<int> nextSmallerElement(int* arr, int n) {
    stack<int> s;
    s.push(-1);
    vector<int> ans(n);
    
    for (int i = n - 1; i >= 0; i--) {
        int curr = arr[i];
        while (s.top() != -1 && arr[s.top()] >= curr) {
            s.pop();
        }
        
        ans[i] = s.top();
        s.push(i);
    }
    return ans;
}

vector<int> prevSmallerElement(int* arr, int n) {
    stack<int> s;
    s.push(-1);
    vector<int> ans(n);
    
    for (int i = 0; i < n; i++) {
        int curr = arr[i];
        while (s.top() != -1 && arr[s.top()] >= curr) {
            s.pop();
        }
        
        ans[i] = s.top();
        s.push(i);
    }
    return ans;
}

int largestRectangleArea(int* heights, int n) {
    vector<int> next = nextSmallerElement(heights, n);
    vector<int> prev = prevSmallerElement(heights, n);
    
    int area = INT_MIN;
    for (int i = 0; i < n; i++) {
        int l = heights[i];
        
        if (next[i] == -1) {
            next[i] = n;
        }
        
        int b = next[i] - prev[i] - 1;
        int newArea = l * b;
        area = max(area, newArea);
    }
    return area;
}

int maxArea(int M[][100], int n, int m) {
    int area = largestRectangleArea(M[0], m);
    
    for (int i = 1; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (M[i][j] != 0) {
                M[i][j] += M[i - 1][j];
            } else {
                M[i][j] = 0;
            }
        }
        int newArea = largestRectangleArea(M[i], m);
        area = max(area, newArea);
    }
    return area;
}

int main() {
    // Example usage
    int M[4][100] = {
        {1, 0, 1, 0, 0},
        {1, 0, 1, 1, 1},
        {1, 1, 1, 1, 1},
        {1, 0, 0, 1, 0}
    };
    int n = 4; // number of rows
    int m = 5; // number of columns
    cout << "Maximum rectangle area: " << maxArea(M, n, m) << endl;
    return 0;
}

