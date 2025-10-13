/* PersonAtMCC.h - The parent class of Instructor, Student, and Staff
 * Author:     <your name>
 * Module:     7
 * Project:    Lab, Part 1
 * Description:
 *
 *    Data members:
 *       id (string)
 *       name (string)
 *       address (string)
 *       phone (string)
 *
 *    Functions:
 *       no-argument constructor
 *       partial constructor (id & name)
 *       full constructor
 *       copy constructor
 *       all getters and setters
 *       showinfo
 */

#pragma once

#include <iostream>
using namespace std;

class PersonAtMCC
{

private:
    long long id;
    string name;
    string address;
    string phone;

public:
    PersonAtMCC()
    {
        PersonAtMCC(0, "no name yet", "no address yet", "no phone yet");
    }

    PersonAtMCC(long long id, string name)
    {
        PersonAtMCC(id, name, "no address yet", "no phone yet");
    }

    // **** Complete these constructors using initialization lists **** /

    // full constructor
    PersonAtMCC(long long id, string name, string address, string phone) : id(id), name(name), address(address), phone(phone) 
    {
    }

    // copy constructor
    PersonAtMCC(const PersonAtMCC &copy) : PersonAtMCC(copy.id, "Copy of " + copy.name, copy.address, copy.phone)
    {

    }

    // getters
    long long getId() const
    {
        return id;
    }
    string getName() const
    {
        return name;
    }
    string getAddress() const
    {
        return address;
    }
    string getPhone() const
    {
        return phone;
    }

    // setters
    void setId(long long id)
    {
        this->id = id;
    }
    void setName(string name)
    {
        this->name = name;
    }
    void setAddress(string address)
    {
        this->address = address;
    }
    void setPhone(string phone)
    {
        this->phone = phone;
    }

    // show person's info on the screen
    void showInfo()
    {
        cout << "ID: " << id
             << "  Name: " << name
             << "  Address: " << address << endl
             << "    Phone: " << phone << endl;
    }
};
