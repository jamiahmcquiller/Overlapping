// credit.cpp
#include "credit.h"
#include <string>

//*********************************
// This is the credit record file.
//*********************************


int CreditRecord::avgScore = 0;    // this needs to be done once, and only once
int CreditRecord::totalOfScores = 0;
int CreditRecord::nScores = 0;

// This is where the implementation starts

//*********************************************************************
// Construct the credit record.  The baseline score is 300, from which
// the economic activity will modify the score.  The number of accounts
// this person has is always assumed to be 10, for this demo program.
//*********************************************************************
CreditRecord::CreditRecord() : score(300), Naccts(10) {}

//*********************************************************************
// This simulates a 12-month period of economic activity for
// a person who has 10 credit accounts.  Every time they make
// an on-time payment, it adds 4 points to their score.  Every
// time they make a late payment, it subtracts 10 points.  Every
// time they miss a payment (mutually exclusive to the above two),
// it subtracts 30 points from their score.
//*********************************************************************
void CreditRecord::EconomicActivity() {
    int i, j;
    int month;
    int miss;
    int late;

    nScores++;            // I am another person, so increment the
                        // number of scores static class variable

    //******************************************************************
    // Each month:  each payment made on-time represents a +4 to their
    //              credit score.
    //
    //              Each missed payment represents a -30
    //              Each late payment represents a -10
    //******************************************************************
    for (month = 1; month <= 12; month++) {
        for (i = 0; i < Naccts; i++) {

            // Compute two rand values between 1 and 100, to determine a
            // probability.  Probability of missing payment:  2 %
            // Probability of late payment:  4%.  Don't penalize for both.

            miss = 1 + (int) (100.0 * (rand() / (RAND_MAX + 1.0)));
            late = 1 + (int) (100.0 * (rand() / (RAND_MAX + 1.0)));

            if (late <= 4) {        // late pmt
                score = score - 10;
            }
            else if (miss <= 2) {    // missed pmt
                score = score - 30;
            }
            else score = score + 4;    // good pmt
        }
    }
    totalOfScores += score;    // adding my score to the static class
                            // variable totalOfScores
}

//*********************************************************************
// Just prints out the credit score for a credit record
//*********************************************************************
void CreditRecord::printScore() {
    std::cout << "individual credit score is " << score << std::endl;
}

void CreditRecord::findAvg() {
    CreditRecord::avgScore = totalOfScores / nScores;
}

void CreditRecord::printAvg() {
    std::cout << "The average credit score is " << CreditRecord::avgScore << std::endl;
}

void CreditRecord::setLname(std::string inLname) {
    lname = inLname;
}

void CreditRecord::setFname(std::string inFname) {
    fname = inFname;
}

// Overloaded operators

bool operator==(const CreditRecord& c1, const CreditRecord& c2) {
    return (c1.getScore() == c2.getScore());
}

std::ostream& operator<<(std::ostream& os, const CreditRecord& cr) {
    os << cr.lname << ", " << cr.fname << ", no. of accounts " << cr.Naccts << ", and credit score " << cr.score;
    return os;
}

std::istream& operator>>(std::istream& is, CreditRecord& cr) {
    std::cout << "Last name? ";
    is >> cr.lname;
    std::cout << "First name? ";
    is >> cr.fname;
    std::cout << "No. of accounts? ";
    is >> cr.Naccts;
    std::cout << "Initial credit score? ";
    is >> cr.score;

    return is;
}

void CreditRecord::output( ) {
    std::cout << lname << ", " << fname << ", no. of accounts " << Naccts << ", and credit score " << score;
}

void CreditRecord::input( ) {
    std::cout << "Last name? ";
    std::cin >> lname;
    std::cout << "First name? ";
    std::cin >> fname;
    std::cout << "No. of accounts? ";
    std::cin >> Naccts;
    std::cout << "Initial credit score? ";
    std::cin >> score;
}

