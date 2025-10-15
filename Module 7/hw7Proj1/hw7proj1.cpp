#include "PString.h"
#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

int main()
{
    PString words[] = {PString("Chic"), PString("Book"), PString("kayak!!"),
                       PString("1x2x3x4x5"), PString("25  XYZ 9zyx52"), PString("No lemons, no melon"),
                       PString("Not even close!"), PString("Murder for a jar of red rum."),
                       PString("Al lets Della call Ed  \"Stella\""), PString("A man, a plan, a canal -- Panama")};

    cout << setw(40) << left << "Phrase" << " " << setw(10) << left << "Is Palindrome?" << "\n";
    cout << setw(40) << left << "~~~~~~" << " " << setw(10) << left << "~~~~~~~~~~~~~~" << "\n";
    for (PString word : words)
        cout << setw(40) << left << word.getPhrase() << " " << setw(10) << left << std::boolalpha << word.isPalindrome() << "\n";

    cout << "\n";
    
    return 0;
}
