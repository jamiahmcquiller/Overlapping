// findavg03.cpp
#include <iostream>
#include <iomanip>
#include <cstdlib>
using namespace std;

#include "credit.h"

//*******************************************************************
// This program just does a find average from values generated into
// an array of float.
//*******************************************************************
int main() {

    CreditRecord people[20];        // 20 simulated people's credit records
    CreditRecord newperson;
    int i, j;                        // iterator variables.
    int lidx;                        // last name index
    int fidx;                        // first name index

    string lnames[10] = {"Johnson","Jones","Anderson","Chester","Edwards","Smith","Eaton","Jackson","Sinjinfrinjinson","Doe"};
    string fnames[10] = {"Sia","Michael","Ophelia","Aloysius","Mergatroid","Winona","Tedrick","Harold","Ula","Joe"};

    srand(42);

    for (i = 0; i < 20; i++) {
        cout << "For person " << setw(2) << i << ", ";
        people[i].EconomicActivity();
        people[i].printScore();

        lidx = (int) (10.0 * (rand() / (RAND_MAX + 1.0)));
        fidx = (int) (10.0 * (rand() / (RAND_MAX + 1.0)));

        people[i].setLname(lnames[lidx]);
        people[i].setFname(fnames[fidx]);
    }

    // Find and print the average score.

    cout << endl;
    CreditRecord::findAvg();
    CreditRecord::printAvg();
    cout << endl << endl;

    //*******************************************************************
    // Now, let's find all pairs of scores that are equal.
    // Use the overloaded operator== to check for equality.
    //*******************************************************************
    for (i = 0; i < 20; i++)
        for (j = i + 1; j < 20; j++) {
            if (people[i] == people[j]) {
                cout << "people[" << i << "] and people[" << j << "] are equal:" << endl;

                cout << people[i] << endl;
                cout << endl;
                cout << people[j] << endl;
                cout << endl;
                cout << endl;

            }
        }

    // Replace calls to input( ) and output( ) with overloaded operator>> and operator<<
    cout << "Just for testing purposes, I'm asking for a new person." << endl;
    cin >> newperson;
    cout << "You told me:" << endl;
    cout << newperson << endl;
    cout << endl;
    cout << endl;

    // These can also be used for overloaded input and output operators.
    //
    cout << "Before operator=, people[5] and newperson contain:" << endl;
    cout << people[5] << endl;
    cout << endl;
    cout << newperson << endl;
    cout << endl;
    cout << endl;

    // Here's where you'd overload the assignment operator.
    people[5] = newperson;

    cout << "After operator=, people[5] and newperson contain:" << endl;
    cout << people[5] << endl;
    cout << endl;
    cout << newperson << endl;

    return 0;
}
