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

            this->profession = new string(profession);
            this->age = age;
        }

        // Assignment operator
        Person & operator=(const Person &right) {
            // cout << "In the assignment operator copying: " << *right.profession << endl ;

            if (this != &right)
            {
                delete this->profession;
                this->profession = new string(*right.profession);
                this->age = right.age;
            }
            return *this;
        }

        // Copy constructor
        Person(Person &copy) {
            // cout << "In copy constructor for " << *copy.profession << endl ;

            this->age = copy.age;
            this->profession = new string(*copy.profession);
        }

        // Getters and setters
        string getProfession() const {
            return *profession;
        }
        int getAge() const {
            return age ;
        }
        void setProfession(string profession) {
            delete this->profession;
            this->profession = new string(profession);
        }
        void setAge(int age) {
            this->age = age;
        }

        // Destructor
        ~Person() {
            // cout << "Deleting Person:  " << *profession << endl ;

            delete profession;
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
