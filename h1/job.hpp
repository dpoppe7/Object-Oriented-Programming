#pragma once
#include <string>
// A job has a name and a priority
class Job {
public:

    const std::string& getName();
    void setName(const std::string& newName);

    int getPriority();
    void setPriority(int newPriority);

    void increasePriority(int by);

private:
    std::string name;
    int priority;
};
