#include <iostream>
#include <vector>
#include <string>
using namespace std;

// Function to compute hash of a single cell
int hashCell(const string& cell) {
    int hashValue = 0;
    for (char ch : cell) {
        hashValue += int(ch); // Sum of ASCII values of characters
    }
    return hashValue % 13; // Take mod 13
}

// Function to compute hash of a 2x2 grid
int computeGridHash(const vector<vector<string>>& grid, int startRow, int startCol) {
    int hashValue = 0;
    for (int i = startRow; i < startRow + 2; ++i) {
        for (int j = startCol; j < startCol + 2; ++j) {
            hashValue += hashCell(grid[i][j]);
        }
    }
    return hashValue % 13; // Take mod 13
}

// Rolling hash function to check matches
bool rollingHashMatch(const vector<vector<string>>& table1, const vector<vector<string>>& table2) {
    int targetHash = computeGridHash(table2, 0, 0); // Compute hash for the target pattern
    int rows = table1.size();
    int cols = table1[0].size();

    // Slide over all possible 2x2 grids in Table-1
    for (int i = 0; i <= rows - 2; ++i) {
        int currentHash = computeGridHash(table1, i, 0); // Compute hash for the first column of 2x2 grid in row i
        for (int j = 0; j <= cols - 2; ++j) {
            if (j > 0) {
                // Update the hash using the rolling hash formula
                currentHash = (currentHash - hashCell(table1[i][j - 1]) - hashCell(table1[i + 1][j - 1]) + 13) % 13;
                currentHash = (currentHash + hashCell(table1[i][j + 1]) + hashCell(table1[i + 1][j + 1])) % 13;
            }
            if (currentHash == targetHash) {
                return true; // Found a match
            }
        }
    }
    return false; // No match found
}

int main() {
    // Example Table-1
    vector<vector<string>> table1 = {
        {"ABC", "DFD", "LMN", "PQR"},
        {"AAA", "BBB", "TRS", "XZY"},
        {"ZZG", "LMN", "PQR", "GGG"},
        {"UVT", "SRT", "XYZ", "PPP"}
    };

    // Example Table-2 (Pattern to match)
    vector<vector<string>> table2 = {
        {"LMN", "PQR"},
        {"SRT", "XYZ"}
    };

    if (rollingHashMatch(table1, table2)) {
        cout << "Pattern matched!" << endl;
    } else {
        cout << "Pattern not matched!" << endl;
    }

    return 0;
}
