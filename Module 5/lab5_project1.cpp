// CS151 Fall 2025
// Author:   Jack Marriott
// Module:   5
// Lab:  5
// Project: 1
// Problem Statement: More about Classes
//
// Algorithm:
//   1. Create a membership roster using a vector with pointers to the member data structure
//   2. Declare four members and add to vector
//   3. Drop one member
//   4. Simulate gym visits for the remaining members
//   5. Output membership report
//
#include <iostream>
#include <vector>
#include <random>
#include <iomanip>

using namespace std;

const double BASIC_RATE = 42.75, PREMIUM_RATE = 60.00;

struct Member
{
    static int total_visits;   // all visits from members
    static int active_members; // total members active in gym
    static int last_id;        // id assigned to newest member

    string name; // name of this member
    char type;   // rate (B = basic, P = premium)
    int visits;  // visits by this member
    int id;      // id of this member

    Member(string name, char type) : name(name), type(type), visits(0)
    {
        active_members++;
        id = last_id++;
    }

    ~Member()
    {
        --active_members;
    }

};

int Member::total_visits = 0;
int Member::active_members = 0;
int Member::last_id = 100000;

// 1. Create a function named visit which increments the number of
//    visits for a member and for the gym
void visit(Member &gymBro)
{
    ++gymBro.visits;
    ++Member::total_visits;
}

int main()
{
    // 2. Create a  vector  of pointers to  Member  structures.
    //    Create a  Member  object using the  new  operator; add
    //    pointers to the to the vector in this order
    vector<Member *> gymGoers;

    Member *oprah = new Member("Oprah Winfrey", 'P');
    Member *fluffy = new Member("Fluffy", 'P');
    Member *charlie = new Member("Charlie Sheen", 'B');
    Member *leona = new Member("Leona Helmsley", 'B');

    gymGoers.push_back(oprah);
    gymGoers.push_back(fluffy);
    gymGoers.push_back(charlie);
    gymGoers.push_back(leona);

    // 3. Drop the membership for Charlie Sheen
    int idx = 0;
    // use a loop to determine the index of Charlie Sheet in the vector
    for (Member *goerPtr : gymGoers)
    {
        if (goerPtr->name == "Charlie Sheen")
        {
            // delete the pointer to Charlie's  Member  object from the vector
            gymGoers.erase(gymGoers.begin() + idx);
            // delete Charlie's  Member  object from the heap
            delete charlie;
            break;
        }
        idx++;
    }

    // 4. Generate random visits for each of the remaining members
    random_device seed ;  // A random sequence (“seed”) is created based on system clock
    default_random_engine gen(seed());  //default_random_engine gen(8888);
    uniform_int_distribution<int> randVal(5, 20);

    for (Member *goerPtr : gymGoers)
    {
        int visits = randVal(gen); // generate a random number between 5 and 20
        for (int i = 0; i < visits; ++i)
        {
            visit(*goerPtr); // call the  visit  function for that member that many times
            //cout << goerPtr->name << "\t" << goerPtr->visits << "\t" << Member::total_visits << "\n";
        }
    }

    // 5. Pretty-print a columnar report
    cout << "\n";
    cout << setw(35) << right << "Gym Membership Report" << "\n\n";
    cout << setw(10) << left << "ID No." << setw(18) << left << "Member Name" << setw(8) << "Visits";
    cout << setw(10) << "Type" << setw(6) << "Rate";
    cout << "\n";
    cout << setw(10) << left << "~~~~~~" << setw(18) << left << "~~~~~~~~~~~~~~~" << setw(8) << "~~~~~~";
    cout << setw(10) << "~~~~~~" << setw(6) << "~~~~";
    cout << "\n";

    for (Member *goerPtr : gymGoers)
    {
        cout << setw(10) << left << goerPtr->id << setw(18) << left << goerPtr->name << setw(6) << right << goerPtr->visits << "  ";
        if (goerPtr->type == 'B')
        {
            cout << setw(10) << left << "Basic" << fixed << setprecision(2) << setw(6) << BASIC_RATE;
        }
        else
        {
            cout << setw(10) << left << "Premium" << fixed << setprecision(2) << setw(6) << PREMIUM_RATE;
        }
        cout << "\n";
    }

    // 6. At the bottom of the report, use the static variables to show the
    //    total visit for the gym and the number of active members (should be 3)
    cout << "\nTotal Visits:   " << Member::total_visits << "\n";
    cout << "Active Members: " << Member::active_members << "\n\n";

    // Memory cleanup, because cleanliness is godliness
    for (auto member : gymGoers)
        delete member;

    return 0;
}
