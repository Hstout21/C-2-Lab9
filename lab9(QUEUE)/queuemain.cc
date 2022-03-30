// HUNTER STOUT - 3/29/2022
// LAB 9 - QUEUE MAIN

#include "chore.h"
#include <queue>
using namespace std;

int main() {

    //queue<Chore> list;
    priority_queue<Chore> list;
    Chore temp;

    cout << "Welcome! This program will have you enter 5 chores & their priority." << endl;
    for (size_t i = 0; i < 5; i++) {
        cin >> temp;
        list.push(temp);
    }

    for (size_t i = 0; i < 5; i++) {
        //cout << list.front();
        cout << list.top();
        list.pop();
    }

    return 0;
}