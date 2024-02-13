// credit.h
#ifndef CREDIT_H
#define CREDIT_H

#include <iostream>
#include <string>

class CreditRecord {
public:
    CreditRecord();        // initialize my score to 0.

    void EconomicActivity();    // simulate a year of credit activity
    void printScore();        // prints the credit score
    static void findAvg();    // finds the average credit score in the
                            // population, assigns to avg_score

    static void printAvg();    // prints the average credit score

    int getScore() const { return score; }    // return the score
    std::string getLname() const { return lname; }    // return the lname
    std::string getFname() const { return fname; }    // return the fname
    int getNaccts() const { return Naccts; }    // return the # of accts

    void setLname(std::string);
    void setFname(std::string);

    // Overloaded operators
    friend bool operator==(const CreditRecord& c1, const CreditRecord& c2);
    friend std::ostream& operator<<(std::ostream& os, const CreditRecord& cr);
    friend std::istream& operator>>(std::istream& is, CreditRecord& cr);

    void output( );        // This prints the person's record
    void input( );        // This reads the person's record

private:
    std::string lname;        // Last name
    std::string fname;        // First name
    int Naccts;            // Number of credit accounts
    int score;            // A number between 300 and 850,
                        // according to the Goog.

    // Static class variables:
    static int avgScore;    // Since the FICO and Vantage scores are
                            // integers, we'll keep this as an int
                            // and just use truncating/rounding maths.

    static int totalOfScores;    // total of scores, used in computing the
                                // average

    static int nScores;        // How many credit records there are
};

#endif // CREDIT_H
