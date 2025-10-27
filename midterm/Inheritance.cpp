/* Inheritance.cpp - Create a Person / Teacher hierarchy of classes (Midterm)
 * Author:     <your name>
 * Module:     10
 * Project:    Midterm Problem 4
 * Problem statement: Create a Person class parent to a Teacher class.
 *     The Person class has data members profession (string) and age (int).  The
 *     profession data member is actually a pointer to a string in the heap (free store).
 *
 *   * Data member access is protected in Person
 *     -- getters and setters are provided for data members to allow access by other
 *        classes.
 *   * Base class access for Teacher is public
 *
 *   In this project, complete the constructor, copy constructor, assignment operator,
 *   setters, and destructor in the Person class.
 */

#include <iostream>
using namespace std ;

class Person {

    protected:
        string *profession ;
        int age ;

    public:
        // Constructor
        Person(string profession, int age) {
            // cout << "In constructor for " << profession << endl ;

                    // Complete this function
        }

        // Assignment operator
        Person & operator=(const Person &right) {
            // cout << "In the assignment operator copying: " << *right.profession << endl ;

                    // Complete this function
        }

        // Copy constructor
        Person(Person &copy) {
            // cout << "In copy constructor for " << *copy.profession << endl ;

                    // Complete this function
        }

        // Getters and setters
        string getProfession() const {
            return string(*profession) ;
        }
        int getAge() const {
            return age ;
        }
        void setProfession(string profession) {

                    // Complete this function
        }
        void setAge(int age) {

                    // Complete this function
        }

        // Destructor
        ~Person() {
            cout << "Deleting Person:  " << *profession << endl ;

                    // Complete this function
        }
} ;

// This a child of the Person class
class Teacher : public Person {

    public:
        Teacher(int age) : Person("Teacher", age) { }

        ~Teacher() {
            cout << "Deleting Teacher: " << *profession << endl ;
        }
} ;

// Please make no changes to "main".
int main() {

    // Create a Person object, test the setters, and print the data values
    Person wood_worker("Worker", 25) ;
    cout << "The worker's profession is initially " << wood_worker.getProfession()
         << " and is " << wood_worker.getAge() << " years old" << endl ;

    // Test the setters for the wood worker
    wood_worker.setProfession("Woodworker") ;
    wood_worker.setAge(27) ;
    cout << "The revised worker's profession is " << wood_worker.getProfession()
         << " and is " << wood_worker.getAge() << " years old" << endl << endl ;

    // Test the "Teacher" constructor and the copy constructor
    Teacher first_teacher(42) ;
    Teacher copy_teacher(first_teacher) ;
    cout << "The first teacher's profession is " << first_teacher.getProfession()
         << " and is " << first_teacher.getAge() << " years old" << endl
         << "The copied teacher's profession is " << copy_teacher.getProfession()
         << " and is " << copy_teacher.getAge() << " years old" << endl ;
    copy_teacher.setProfession("Math Teacher") ;
    copy_teacher.setAge(37) ;

    // Test the setters on the copied Teacher object
    copy_teacher.setProfession("Math Teacher") ;
    copy_teacher.setAge(37) ;
    cout << "The updated teacher's profession is " << copy_teacher.getProfession()
         << " and is " << copy_teacher.getAge() << " years old" << endl << endl ;

    // Create a dummy Person object for testing the assignment operator
    cout << "Creating a blank Person object to duplicate" << endl ;
    Person duplicate("N/A", 0) ;

    // Test by re-assigning to the wood worker
    duplicate = wood_worker ;
    cout << "The duplicated person's profession is " << duplicate.getProfession()
         << " and is " << duplicate.getAge() << " years old" << endl << endl ;

    return 0 ;
}
