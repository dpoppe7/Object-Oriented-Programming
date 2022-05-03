#include "job.hpp"
using std::string;

const string& Job::getName() {
    return name;
}

void Job::setName(const string& newName) {
    name = newName;
}

int Job::getPriority() {
    return priority;
}

void Job::setPriority(int newPriority) {
    priority = newPriority;
    // priority should never be less than 1
    if (priority < 1) priority = 1;
}

void Job::increasePriority(int by) {
    priority += by;
    // priority should never be less than 1
    if (priority < 1) priority = 1;
}