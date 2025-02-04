#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct Task {
    string taskname;
    string taskdescription;
    string dateadded;
};

void menu() {
    cout << "\033[2J\033[1;1H";  // CLEARS SCREEN
    cout << "\n---- TODO MENU ----\n";
    cout << " (x) Exit Program\n";
    cout << " (a) Add Task\n";
    cout << " (c) Check Tasks\n";
    cout << " (r) Remove Task\n";
}

void add_task(vector<Task> &tasks) {
    Task t;
    cout << "\nTaskname: ";
    cin >> t.taskname;
    cout << "\nTaskdescription: ";
    cin >> t.taskdescription;
    t.dateadded = "";
    tasks.push_back(t);
}

void remove_task(vector<Task> &tasks) {
    string taskname;
    cout << "\nTaskname to remove: ";
    cin >> taskname;

    for (size_t i=0; i < tasks.size(); i++) {
        if (tasks[i].taskname == taskname) {
            tasks.erase(tasks.begin() + i);
        }
    }
}

int main()
{
    vector<Task> tasks;
    while (true) {
        char choice;
        menu();
        cout << "\nChoice: ";
        cin >> choice;

        switch (choice) {
        case 'x':
            return 0;
        case 'a':
            add_task(tasks);
            break;
        case 'c':
            for (auto& task : tasks) {

                cout << "Name: " << task.taskname << " Description: " << task.taskdescription << "\n";

            }
            char waitforenter;
            cout << "Type anything to go back to menu: ";
            cin >> waitforenter;
            break;
        case 'r':
            remove_task(tasks);
            break;
        }
    }
    return 0;
}
