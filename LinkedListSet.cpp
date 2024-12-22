#include "Set.h"

/**
 * Implement the LinkedListSet methods correctly
 */
unsigned int LinkedListSet::size() {
    /* YOUR CODE HERE */
    return linked.size();
}

void LinkedListSet::insert(string s) {
    /* YOUR CODE HERE */
    if (!find(s)) {
        linked.push_back(s);
    }
}

void LinkedListSet::remove(const string & s) {
    /* YOUR CODE HERE */
    if (find(s)) {
        for (auto itr = linked.begin(); itr != linked.end(); itr++) {
            if (*itr == s) {
                linked.erase(itr);
                break;
            }
        }
    }

}

bool LinkedListSet::find(const string & s) {
    /* YOUR CODE HERE */
    for (auto itr = linked.begin(); itr != linked.end(); itr++) {
        if (*itr == s) {
            return true;
        }
    }
    return false;
}
