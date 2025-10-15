#include <bits/stdc++.h>
using namespace std;

vector<int> failure(const string& pattern) {
    int m = pattern.length();
    vector<int> lps(m, 0);
    int len = 0;
    for (int i = 1; i < m; ) {
        if (pattern[i] == pattern[len]) {
            lps[i++] = ++len;
        } else {
            if (len != 0) len = lps[len - 1];
            else lps[i++] = 0;
        }
    }
    return lps;
}

vector<int> kmp(const string& text, const string& pattern) {
    int n = text.length();
    int m = pattern.length();
    vector<int> lps = failure(pattern);
    vector<int> result;

    int i = 0, j = 0;
    while (i < n) {
        if (text[i] == pattern[j]) {
            i++; j++;
            if (j == m) {
                result.push_back(i - j);
                j = lps[j - 1];
            }
        } else {
            if (j != 0) j = lps[j - 1];
            else i++;
        }
    }
    return result;
}