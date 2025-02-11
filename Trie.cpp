#include <bits/stdc++.h>
using namespace std;

struct Node {
    Node *next_edge[26];
    bool flag;

    Node() {
        flag = 0;
        for (int i = 0; i < 26; i++) {  
            next_edge[i] = NULL;
        }
    }
};

void insert_into_trie(const string &word, Node *root) {
    Node *current = root;
    for (char ch : word) {
        int index = ch - 'a';
        if (current->next_edge[index] == NULL) {
            current->next_edge[index] = new Node;
        }
        current = current->next_edge[index];
    }
    current->flag = 1;
}


void traverse(string word, Node *current) {
    if (current == NULL) {
        return;
    }

    if (current->flag == 1) {
        cout << word << endl;
    }

    
    for (int i = 0; i < 26; i++) {
        if (current->next_edge[i] != NULL) {
            word+=(char)(i+97);
            traverse(word, current->next_edge[i]);
        }
    }
}



int main() {
    int n;
    cin >> n;
    Node *root = new Node;

   
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        insert_into_trie(s, root);
    }

    int k;
    cin >> k;

    
    for (int i = 0; i < k; i++) {
        string s;
        cin >> s;
        Node *current = root;
    for (int i=0;i<s.length();i++) {
        
        current = current->next_edge[i];
    }
         traverse(s, current);
    }

    return 0;
}
