#include "Set.h"

/**
 * Implement the RedBlackTreeSet methods correctly
 */
unsigned int RedBlackTreeSet::size() {
    /* YOUR CODE HERE */
    return rbt.size();
}

void RedBlackTreeSet::insert(string s) {
    /* YOUR CODE HERE */
    if (!find(s)) {
        rbt.insert(s);
    }
}

void RedBlackTreeSet::remove(const string & s) {
    /* YOUR CODE HERE */
    if (find(s)) {
        for (auto itr = rbt.begin(); itr != rbt.end(); itr++) {
            if (*itr == s) {
                rbt.erase(itr);
                break;
            }
        }
    }
}

bool RedBlackTreeSet::find(const string & s) {
    /* YOUR CODE HERE */
    if (rbt.find(s) != rbt.end()) {
        return true;
    } else {
        return false;
    }
}
