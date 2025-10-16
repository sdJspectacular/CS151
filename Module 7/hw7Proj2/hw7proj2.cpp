#include "EncryptableString.h"
#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

int main()
{
    EncryptableString words[] = {EncryptableString("Chic"), EncryptableString("Book"), EncryptableString("kayak!!"),
                       EncryptableString("1x2x3x4x5"), EncryptableString("25  XYZ 9zyx52"), EncryptableString("No lemons, no melon"),
                       EncryptableString("Not even close!"), EncryptableString("Murder for a jar of red rum."),
                       EncryptableString("Al lets Della call Ed  \"Stella\""), EncryptableString("A man, a plan, a canal -- Panama")};

    cout << setw(40) << left << "Phrase" << " " << setw(10) << left << "Is Palindrome?" << "\n";
    cout << setw(40) << left << "~~~~~~" << " " << setw(10) << left << "~~~~~~~~~~~~~~" << "\n";
    for (EncryptableString word : words)
        cout << setw(40) << left << word.getPhrase() << " " << setw(10) << left << std::boolalpha << word.isPalindrome() << "\n";

    cout << "\n";
    
    return 0;
}
