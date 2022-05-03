#include "joblist.hpp"
#include <vector>
using std::vector;

int threshold = 0;
vector<Job> jobs;

int firstJobMeetingThreshold() {
    for (int i = 0; i < jobs.size(); ++i) {
        if (jobs[i].getPriority() >= threshold) {
            return i;
        }
    }
    return -1;
}

void removeJob(int i) {
    for (int j = i; j < jobs.size() - 1; ++j) {
        jobs[j] = jobs[j + 1];
    }
    jobs.pop_back();
}

void addJob(Job job) {
    jobs.push_back(job);
}

bool hasJob() {
    int i = firstJobMeetingThreshold();
    return i >= 0;
}

Job getJob() {
    int i = firstJobMeetingThreshold();
    Job job = jobs[i];
    removeJob(i);
    return job;
}

