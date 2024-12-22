#include "Set.h"

/**
 * Implement the MultiwayTrieSet constructor
 */
MultiwayTrieSet::MultiwayTrieSet() {
    /* YOUR CODE HERE */
    root = new Node();
    numElements = 0;
}

void clear(MultiwayTrieSet::Node* node) {
    while(!node->children.empty()) {
        auto element = *node->children.begin();
        clear(element.second);
        node->children.erase(element.first);
    }
    delete node;
}
/**
 * Implement the MultiwayTrieSet destructor
 */
MultiwayTrieSet::~MultiwayTrieSet() {
    /* YOUR CODE HERE */
    clear(root);
}
/**
 * Implement the MultiwayTrieSet methods correctly
 */
unsigned int MultiwayTrieSet::size() {
    /* YOUR CODE HERE */
    return numElements;
}

void MultiwayTrieSet::insert(string s) {
    /* YOUR CODE HERE */
    if (!find(s)) {
        Node* ptr = root;
        for (unsigned long i = 0; i < s.size(); i++) {
            if (ptr->children.count(s[i]) == 0) {
                ptr->children[s[i]] = new Node();
            }
            ptr = ptr->children[s[i]];
        }
        numElements++;
        ptr->isWord = true;
    }
}

void MultiwayTrieSet::remove(const string & s) {
    /* YOUR CODE HERE */
    if (find(s)) {
        vector <Node*> temp;
        Node* ptr = root;
        char prev_key = '\0';
        for (unsigned long i = 0; i < s.size(); i++) {
            prev_key = s[i];
            temp.push_back(ptr);
            ptr = ptr->children[s[i]];
        }
        numElements--;
        ptr->isWord = false;
        unsigned int index = temp.size(); 

        for (unsigned int i = 0; i < temp.size(); i++) {
            Node* node = temp[index - i - 1];
            if (node->children.empty() && node->isWord == false) {
                if (index - i == 1) {
                    root = nullptr;
                } else {
                    Node* prev = temp[index - i - 2];
                    prev->children.erase(prev_key);
                }
                delete node;
            }
        }
    }
}

bool MultiwayTrieSet::find(const string & s) {
    /* YOUR CODE HERE */
    Node* ptr = root;
    for (unsigned long i = 0; i < s.size(); i++) {
        if (ptr->children.count(s[i]) == 0) {
            return false;
        }
        ptr = ptr->children[s[i]];
    }
    if (ptr->isWord == true) {
        return true;
    }
    return false;
}
