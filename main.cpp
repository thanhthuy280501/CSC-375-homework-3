#include "instagram.h"
#include <iostream>
#include <fstream>
#include <string>

struct President {
    std::string name;
    std::string state;

    friend std::ostream& operator<<(std::ostream& os, const President& p) {
        os << p.name << "\t" << p.state;
        return os;
    }
};

int main() {
    // Create Instagram account for "Presidents"
    Instagram<std::string> instaAccount("Presidents");
    
    // Read presidents from file
    std::ifstream inputFile("presidentsWstates.txt");
    if (!inputFile) {
        std::cerr << "Error opening file." << std::endl;
        return 1;
    }

    std::string name, state;
    while (inputFile >> std::ws && std::getline(inputFile, name, '\t') && std::getline(inputFile, state)) {
        // Combine name and state for simplicity
        std::string presidentEntry = name + "\t" + state;
        instaAccount.addFollower(presidentEntry);
    }
    inputFile.close();

    // Test latestFollower
    std::string latest;
    if (instaAccount.latestFollower(latest)) {
        std::cout << "Most recent follower: " << latest << std::endl;
    }

    // Test removeFollower
    std::string removed;
    if (instaAccount.removeFollower(removed)) {
        std::cout << "Removed follower: " << removed << std::endl;
    }

    // Test printFollowers
    std::cout << "\nCurrent followers:" << std::endl;
    instaAccount.printFollowers();

    // Test resetFollowers
    instaAccount.resetFollowers();
    std::cout << "\nAfter reset:" << std::endl;

    // Test checklist
    if (instaAccount.checklist()) {
        std::cout << "The follower list is empty." << std::endl;
    } else {
        std::cout << "The follower list is not empty." << std::endl;
    }

    return 0;
}
