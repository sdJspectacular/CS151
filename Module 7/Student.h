/* Student.h - Describes students at MiraCosta (child of PersonAtMCC)
 * Author:     <your name>
 * Module:     7
 * Project:    Lab, Part 1
 * Description:
 *
 *    Child of PersonAtMCC
 *
 *    Data members:
 *       major (string)
 *       credits_received (int)
 *       applied_to_4_year (bool)
 *       is_veteran (bool)
 *
 *    Functions:
 *       full constructor
 *       copy constructor
 *       getters and setters for all data members
 *       showInfo
 */

#pragma once

#include <iostream>
using namespace std ;

         /*** Make this class a child of PersonAtMCC with public access ***/

class Student {

    private :
        string major ;
        int credits_received ;
        bool applied_to_4_year ;
        bool is_veteran ;

    public :

        /**** Complete these constructors using initialization lists. ****/

        // full constructor
        Student(long long id, string name, string address, string phone,
                    string major, int credits_received,
                    bool applied_to_4_year, bool is_veteran) { }

        // copy constructor
        Student(const Student &copy) { }

        // getters
        string getMajor() const
            { return major ; }
        int getCreditsReceived() const
            { return credits_received ; }
        bool getAppliedTo4Year() const
            { return applied_to_4_year ; }
        bool getIsVeteran() const
            { return is_veteran ; }

        // setters
        void setMajor(string major)
            { this->major = major ; }
        void setCreditsReceived(int credits)
            { credits_received = credits ; }
        void setAppliedTo4Year(bool applied)
            { applied_to_4_year = applied ; }
        void setIsVeteran(bool is_veteran)
            { this->is_veteran = is_veteran ; }

        /**** Complete this function ****/

        // display the student's info on the screen
        void showInfo() {
            cout << "ID: " << getId() << endl ;
        }
} ;
