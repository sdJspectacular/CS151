#include <iostream>
#include <cmath>
#include <iomanip>
#include <string>

using namespace std;

// Student class, holds a name(string) and a score(int)
class Student
{
private:
    string name;
    int score;

public:
    // Default constructor (no arguments)
    Student() : name(""), score(0) {}

    // Constructor with arguments
    Student(string studentName, int studentScore)
    {
        name = studentName;
        score = studentScore;
    }

    // Destructor (does nothing)
    ~Student() {}

    // Getter functions
    string getName() const
    {
        return name;
    }

    int getScore() const
    {
        return score;
    }

    // Setter functions
    void setName(string studentName)
    {
        this->name = studentName;
    }

    void setScore(int studentScore)
    {
        this->score = studentScore;
    }

    // Member function to display student information
    void display() const
    {
        cout << setw(15) << left << name << setw(4) << right << score << "\n";
    }
};

// Local prototypes
void insertionSort(Student *students, int size);
void insertionSort(int *arr, int size);
double avgScore(Student *student, int size);
double avgScore(int *arr, int size);

int main()
{
    // Get a different random sequence each time
    srand(time(NULL));

    // Get number of test scores
    string token, name;
    int length, nLetters;

    cout << "Enter number of scores: ";
    getline(cin, token);
    length = stoi(token);

    // dynamically allocated score array
    int *arrPtr = new int[length];

    // dynamically allocated Student array
    Student *studentPtr = new Student[length];

    // assign test scores randomly (it's faster than manual entry)
    cout << "Assigning " << length << " test scores\n";

    int i = 0;
    do {
        arrPtr[i] = rand() % 100;  // random scores 0-99

        // Input Validation: Do not test scores outside of range [0, 100]
        if ((arrPtr[i] < 0) || (arrPtr[i] > 100))
            continue;
        
        // Generate some random name that's between 4 and 12 letters long
        nLetters = 4 + rand() % 8;
        name = "";                 // initialize empty name
        for (int j = 0; j < nLetters; ++j)
        {
            // build name with random letters, one character at a time
            name += 'a' + rand() % 26;  // 26 letters in the English alphabet
        }

        studentPtr[i].setScore(arrPtr[i]);
        studentPtr[i].setName(name);
        i++;

    } while (i < length);

    // Display the unsorted (name, score) data
    cout << "\nUnsorted\n\n";
    cout << setw(15) << left << "Student Name" << setw(4) << "Score" << "\n";
    cout << setw(15) << left << "+----------+" << setw(4) << "+---+" << "\n";
    for (int i = 0; i < length; ++i)
        studentPtr[i].display();
    cout << "\n";

    // Pass test scores to a function that sorts them in ascending order
    insertionSort(studentPtr, length);

    // Display the sorted (name, score) data
    cout << "\nSorted\n\n";
    cout << setw(15) << left << "Student Name" << setw(4) << "Score" << "\n";
    cout << setw(15) << left << "+----------+" << setw(4) << "+---+" << "\n";
    for (int i = 0; i < length; ++i)
        studentPtr[i].display();
    cout << "\n";

    // Calculate the average score
    cout << "Average Score: " << fixed << setprecision(2) << avgScore(studentPtr, length) << "\n\n";

    delete[] arrPtr;
    delete[] studentPtr;

    return 0;
}

// Sort a student list in increasing score order
void insertionSort(Student *students, int size)
{

    // At any i-th element, parse thru subelements [0, ..., i-1] and shift
    // one place to the right IF the subelement is greater than the i-th element.
    for (int i = 1; i < size; ++i)
    {
        int val = students[i].getScore(); // this is the i-th element
        string name = students[i].getName();
        int k;

        // parse thru subelements in order [i-1, i-2, ..., 0]
        for (k = i - 1; k >= 0; --k)
        {
            if (val < students[k].getScore())
            {
                students[k + 1].setScore(students[k].getScore()); // move greater values to the right
                students[k + 1].setName(students[k].getName());
            }
            else
                break; // stop because remaining elements are less than
        }
        students[k + 1].setScore(val); // set the i-th element where it belongs
        students[k + 1].setName(name);
    }
}

// Sort an integer list in increasing order
void insertionSort(int *arr, int size)
{

    // At any i-th element, parse thru subelements [0, ..., i-1] and shift
    // one place to the right IF the subelement is greater than the i-th element.
    for (int i = 1; i < size; ++i)
    {
        int val = arr[i]; // this is the i-th element
        int k;

        // parse thru subelements in order [i-1, i-2, ..., 0]
        for (k = i - 1; k >= 0; --k)
        {
            if (val < arr[k])
                arr[k + 1] = arr[k]; // move greater values to the right
            else
                break; // stop because remaining elements are less than
        }
        arr[k + 1] = val; // set the i-th element where it belongs
    }
}

// Compute the average of a list of scores
double avgScore(Student *student, int size)
{
    double sum = 0.0;
    for (int i = 0; i < size; i++)
    {
        sum += student[i].getScore();
    }
    return sum / size;
}

// Compute the average of a list of scores
double avgScore(int *arr, int size)
{
    double sum = 0.0;
    for (int i = 0; i < size; i++)
    {
        sum += arr[i];
    }
    return sum / size;
}