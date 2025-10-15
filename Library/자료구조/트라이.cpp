#include <bits/stdc++.h>
using namespace std;

struct Trie {
    struct Node {
        Node* child[26] = {nullptr};
        bool isEnd = false;
    };

    Node* root;

    Trie() {
        root = new Node();
    }

    // 문자열 word 삽입
    void insert(const string& word) {
        Node* cur = root;
        for (char ch : word) {
            int idx = ch - 'a';
            if (!cur->child[idx]) cur->child[idx] = new Node();
            cur = cur->child[idx];
        }
        cur->isEnd = true;
    }

    // 정확히 word가 존재하는지 확인
    bool search(const string& word) {
        Node* cur = root;
        for (char ch : word) {
            int idx = ch - 'a';
            if (!cur->child[idx]) return false;
            cur = cur->child[idx];
        }
        return cur->isEnd;
    }

    // 해당 접두사로 시작하는 단어가 있는지 확인
    bool startsWith(const string& prefix) {
        Node* cur = root;
        for (char ch : prefix) {
            int idx = ch - 'a';
            if (!cur->child[idx]) return false;
            cur = cur->child[idx];
        }
        return true;
    }
};