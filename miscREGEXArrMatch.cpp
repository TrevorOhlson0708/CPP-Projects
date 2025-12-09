#include <iostream>
#include <regex>
#include <string>
#include <vector>
using namespace std;

int countMatches(const string& pattern, const string& number) {
    int matches = 0;

    if (pattern.length() != 4 || number.length() != 4) {
        throw invalid_argument("Both pattern and number must be 4 characters long.");
    }

    for (size_t i = 0; i < 4; ++i) {
        if (pattern[i] == number[i]) {
            matches++;
        }
    }

    return matches;
}

int main() {
    string pattern = "3901"; 
    vector<string> numbers = {"3122", "0100", "0010", "1100"};  

    cout << "Pattern: " << pattern << endl;

    for (size_t i = 0; i < numbers.size(); ++i) {
        try {
            int matches = countMatches(pattern, numbers[i]);
            cout << "Number " << numbers[i] << " -> Matches: " << matches << endl;
        }
        catch (const invalid_argument& e) {
            cout << "Error with number " << numbers[i] << ": " << e.what() << endl;
        }
    }

    return 0;
}
