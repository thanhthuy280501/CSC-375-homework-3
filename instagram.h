#ifndef INSTAGRAM_H
#define INSTAGRAM_H

#include "stack.h"
#include <string>

template <class DataType>
class Instagram {
private:
    int numoffollowers;
    DataType user;
    Stack<DataType> followerlist;
public:
    Instagram(const DataType& u) : user(u), numoffollowers(0) {}

    void addFollower(const DataType& follower) {
        followerlist.push(follower);
        numoffollowers++;
    }

    bool removeFollower(DataType& follower) {
        if (followerlist.pop(follower)) {
            numoffollowers--;
            return true;
        }
        return false;
    }

    void printFollowers() const {
        followerlist.print();
    }

    bool latestFollower(DataType& follower) const {
        return followerlist.peek(follower);
    }

    void resetFollowers() {
        followerlist.makeEmpty();
        numoffollowers = 0;
    }

    bool checklist() const {
        return followerlist.isEmpty();
    }

    int getNumFollowers() const {
        return numoffollowers;
    }

    DataType getUser() const {
        return user;
    }
};

#endif // INSTAGRAM_H
