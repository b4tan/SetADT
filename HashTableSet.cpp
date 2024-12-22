#include "Set.h"

/**
 * Implement the HashTableSet methods correctly
 */
unsigned int HashTableSet::size() {
    /* YOUR CODE HERE */
    return ht.size();
}

void HashTableSet::insert(string s) {
    /* YOUR CODE HERE */
    if (!find(s)) {
        ht.insert(s);
    }
}

void HashTableSet::remove(const string & s) {
    /* YOUR CODE HERE */
    if (find(s)) {
        for (auto itr = ht.begin(); itr != ht.end(); itr++) {
            if (*itr == s) {
                ht.erase(itr);
                break;
            }
        }
    }
}

bool HashTableSet::find(const string & s) {
    /* YOUR CODE HERE */
    if (ht.find(s) != ht.end()) {
        return true;
    } else {
        return false;
    }
}
