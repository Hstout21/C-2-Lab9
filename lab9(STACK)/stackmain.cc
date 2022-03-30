// HUNTER STOUT - 3/29/2022
// LAB 9 - STACK MAIN

#include <stack>
#include "calc_useful.h"
#include <iostream>
#include <cstdlib>
using namespace std;

int main(){
	char c;
	char tmp;
	int onenum, twonum;
	bool continu = true;
	stack<int> nums;

	while(continu == true){
		cout << "Please enter your expression:\n";
		c = cin.get();
		while(c != '\n'){
			if(isdigit(c)){ //Digit route.
				cin.putback(c);
				cin >> onenum;
				nums.push(onenum);
			}
			else if(isop(c)){ //Operator route.
				if(!nums.empty()){ //Checks if empty.
					//Takes top number.
					twonum = nums.top();
					nums.pop();
					if(!nums.empty()){ //Double checks if empty.
						//Takes new top number.
						onenum = nums.top();
						nums.pop();
						//Evaluates & adds answer to stack.
						onenum = evaluate(onenum, twonum, c);
						nums.push(onenum);
					}
					else {
						cout << "Error: You need at least two numbers to preform this operation." << endl;
						exit(0);
					}
				}
				else{ //Less than two numbers in the stack.
					cout << "Error: You need at least two numbers to preform this operation." << endl;
					exit(0);
				}
			}
			c = cin.get(); // reading at the bottom of the sentinel loop
		}
		
		//Output.
		if (!nums.empty()) {
			onenum = nums.top();
			nums.pop();
			if (nums.empty()) {
				cout << "Answer = " << onenum << endl;
			}
			else {
				cout << "Error: Too many numbers, need more operations for a final answer." << endl;
				exit(0);
			}
		}
		else {
			cout << "Error: Incorrect input." << endl;
			exit(0);
		}

		//New number.
		cout << "Enter another equation?(y or n)";
		cin >> tmp;
		cin.ignore();
		if(tmp == 'y' || tmp == 'Y')
			continu = true;
		else
			continu = false;

	}
	return 0;
}