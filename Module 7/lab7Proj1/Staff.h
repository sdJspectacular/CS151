/* Staff.h - Header for staff members at MCC
 * Author:     Jack Marriott
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

class Staff : public PersonAtMCC
{

private:
    string extension;
    string hire_date;
    double pay_rate;

public:
    /**** Complete these constructors using initialization lists ****/

    // full constructor
    Staff(long long id, string name, string address, string phone,
          string extension, string hire_date, double pay_rate) :
          PersonAtMCC(id, name, address, phone),
          extension(extension), hire_date(hire_date), pay_rate(pay_rate)
          {
          }

    // copy constructor
    Staff(const Staff &copy) : PersonAtMCC(copy),  extension(copy.extension), hire_date(copy.hire_date), pay_rate(copy.pay_rate)
    {
    }

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
        // extension;
        // hire_date;
        // pay_rate;
        PersonAtMCC::showInfo();
        cout << "    Extension: " << getExtension() <<
                "    Hire Date: " << getHireDate() <<
                "     Pay Rate: " << getPayRate() << "\n\n";
    }
};
