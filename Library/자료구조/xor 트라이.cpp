#include <bits/stdc++.h>
using namespace std;

struct Node {
    Node *child[2] = {nullptr, nullptr};
    int cnt = 0;
    
    void insert(const vector<int> &s){
        Node *cur = this;
        for (auto x : s) {
            if (!cur->child[x]) cur->child[x] = new Node;
            cur = cur->child[x];
            cur->cnt++;
        }
    }
    
    void remove(const vector<int> &s) {
        Node *cur = this;
        for (auto x : s) {
            cur = cur->child[x];
            cur->cnt--;
        }
    }
    
    // s와 xor해서 최대인 값 탐색
    int search(const vector<int> &s) {
        Node* cur = this;
        int res = 0;
        for (auto x : s) {
            int y = x ^ 1;
            res <<= 1;
            if (cur->child[y] && cur->child[y]->cnt > 0) {
                res |= 1;
                cur = cur->child[y];
            } else cur = cur->child[x];
        }
        return res;
    }
};