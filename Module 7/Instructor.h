/* Instructor.h - Class describing an Instructor at MiraCosta.
 * Author:     <your name>
 * Module:     7
 * Project:    Lab, Part 1
 * Description:
 *
 *    Data members:
 *       department(string)
 *       is_permanent (bool)
 *       pay_rate (double)
 *       hours (double)
 *
 *    Functions:
 *       full constructor
 *       copy constructor
 *       getters and setters for all data members
 *       showInfo
 */

#pragma once

#include <iostream>
using namespace std;

/*** Make this class a child of PersonAtMCC with public access ***/

class Instructor
{

private:
    string department;
    bool is_permanent;
    double pay_rate;
    double hours;

public:
    /**** Complete these constructors using initialization lists ****/

    // full constructor
    Instructor(long long id, string name, string address, string phone,
               string department, bool is_permanent, double pay_rate, double hours) {}

    // copy constructor
    Instructor(const Instructor &copy) {}

    // getters for this class
    string getDepartment() const
    {
        return department;
    }
    bool getIsPermanent() const
    {
        return is_permanent;
    }
    double getPayRate() const
    {
        return pay_rate;
    }
    double getHours() const
    {
        return hours;
    }

    // setters for this class only
    void setDepartment(string department)
    {
        this->department = department;
    }
    void setIsPermanent(bool is_permanent)
    {
        this->is_permanent = is_permanent;
    }
    void setPayRate(double pay_rate)
    {
        this->pay_rate = pay_rate;
    }
    void setHours(double hours)
    {
        this->hours = hours;
    }

    /**** Complete this function ****/

    // Display the instructor's info on the screen
    void showInfo()
    {
        cout << "ID: " << getId() << endl;
    }
};
