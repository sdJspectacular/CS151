/* Staff.h - Header for staff members at MCC
 * Author:     <your name>
 * Module:     7
 * Project:    Lab
 * Description:
 *
 *    Child of PersonAtMCC
 *
 *    Data members:
 *       extension (string)
 *       hire_date (string)
 *       pay_rate (double)
 *
 *    Functions:
 *       full constructor
 *       copy constructor
 *       getters and setters for extension, hire_date, and pay_rate
 *       showInfo
 */

#pragma once

#include <iostream>
using namespace std;

/**** Make this class a child of PersonAtMCC with public access ****/

class Staff
{

private:
    string extension;
    string hire_date;
    double pay_rate;

public:
    /**** Complete these constructors using initialization lists ****/

    // full constructor
    Staff(long long id, string address, string name, string phone,
          string extension, string hire_date, double pay_rate) {}

    // copy constructor
    Staff(const Staff &copy) {}

    // getters
    string getExtension() const
    {
        return extension;
    }
    string getHireDate() const
    {
        return hire_date;
    }
    double getPayRate() const
    {
        return pay_rate;
    }

    // setters
    void setExtension(string extension)
    {
        this->extension = extension;
    }
    void setHireDate(string hire_date)
    {
        this->hire_date = hire_date;
    }
    void setPayRate(double pay_rate)
    {
        this->pay_rate = pay_rate;
    }

    /**** Complete this function ****/

    // Display the staff member's info on the screen
    void showInfo()
    {
        cout << "ID: " << getId() << endl;
    }
};
