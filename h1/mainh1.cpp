#include <iostream>
#include <vector>
#include <string>
#include "job.hpp"
#include "joblist.hpp"

using namespace std;

int main() {
  string name;
  int priority;
  cin >> name;
  while (name != "done") {
    cin >> priority;
    Job job;
    job.setName(name);
    job.setPriority(priority);
    addJob(job);
    cin >> name;
  }

  cin >> threshold;

  while (hasJob()) {
    Job job = getJob();
    cout << "Running job " << job.getName() << "...\n";
  }
}
