// HUNTER STOUT - 3/29/2022
// LAB 9 - QUEUE CLASS

#ifndef CHORE_H
#define CHORE_H
#include <iostream>
using namespace std;

class Chore{
    public:
        Chore() {task = "N/A"; pnum = 0;}
        void input(istream& ins);
		void output(ostream& outs)const;

        string get_task()const {return task;}
        int get_pnum()const {return pnum;}

        bool operator < (const Chore& c)const {return pnum > c.pnum;}

    private:
        string task;
        int pnum;
};

ostream& operator << (ostream& outs, const Chore& c) {c.output(outs); return outs;}
istream& operator >> (istream& ins, Chore& c) {c.input(ins); return ins;}

void Chore::input(istream& ins) {
    string input;
    cout << "Enter chore description: " << endl;
    while(ins.peek() == '\n' || ins.peek() == '\r') {
        ins.ignore();
	}
    getline(ins, input);
    task = input;
    cout << "Enter this chore priority (1-9): " << endl;
    ins >> pnum;

}

void Chore::output(ostream& outs)const {
    outs << "Chore description: " << task << endl;
    outs << "Priority: " << pnum << endl << endl;
}

#endif