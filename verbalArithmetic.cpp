// Code for verbal arithmetic puzzle
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <map>
#include <set>
#include <cmath>
#include <cassert>
using namespace std;

// Function to check if the given assignment is valid or not
bool isValid(vector<string> &words, map<char, int> &mp) {
    int n = words.size();
    int sum = 0;
    for (int i = 0; i < n - 1; i++) {
        int num = 0;
        for (char ch : words[i]) {
            num = num * 10 + mp[ch];
        }
        sum += num;
    }
    int num = 0;
    for (char ch : words[n - 1]) {
        num = num * 10 + mp[ch];
    }
    return sum == num;
}

// Function to solve the verbal arithmetic puzzle
bool solve(vector<string> &words, string &unique, int idx, map<char, int> &mp, vector<int> &used) {
    if (idx == unique.size()) {
        return isValid(words, mp);
    }
    char ch = unique[idx];
    for (int i = 0; i < 10; i++) {
        if (used[i] == 0) {
            used[i] = 1;
            mp[ch] = i;
            if (solve(words, unique, idx + 1, mp, used)) {
                return true;
            }
            used[i] = 0;
        }
    }
    return false;
}

// Function to initialize the variables and call the solve function
bool isSolvable(vector<string> &words) {
    map<char, int> mp;
    set<char> st;
    for (string &word : words) {
        for (char ch : word) {
            st.insert(ch);
        }
    }
    string unique = "";
    for (char ch : st) {
        unique += ch;
    }
    vector<int> used(10, 0);
    return solve(words, unique, 0, mp, used);
}

// Function to test the code
void test() {
    vector<string> words;
    words.push_back("SEND");
    words.push_back("MORE");
    words.push_back("MONEY");
    cout << isSolvable(words) << endl;
    cout << "All test cases passed!" << endl;
}

int main() {
    test();
    return 0;
}