#include <iostream>
#include <string>
#include <cstring>

using namespace std;

void replaceSubstring(char *str1, char *str2, char *str3);

int main()
{
    char orig[250];
    char source[50];
    char target[50];

    while (true)
    {
        // Get the original C-string
        cout << "Enter the original string or \"quit\" to stop:   ";
        cin.getline(orig, 250);

        // Stop if the user enters "quit"
        if (strcmp(orig, "quit") == 0)
        {
            break;
        }

        cout << "Enter the substring to replace: ";
        cin.getline(source, 50);

        cout << "Enter its replacement:          ";
        cin.getline(target, 50);

        // Call the function to replace all occurrences of source with target
        // in the original string, print the updated string and repeat loop
        replaceSubstring(orig, source, target);
        cout << "With all replacements made:  " << orig << endl
             << endl;
    }

    return 0;
}

void replaceSubstring(char *str1, char *str2, char *str3)
{
    // Use C++ strings so that we can use replace()
    string string1(str1);
    string string2(str2);
    string string3(str3);
    size_t n1 = string1.length();
    size_t n2 = string2.length();
    size_t n3 = string3.length();

    // https://cplusplus.com/reference/string/string/find/
    size_t found = string1.find(string2, 0);

    while (found != string::npos)
    {
        //cout << "found at: " << found << "\n";
        // https://cplusplus.com/reference/string/string/replace/
        string1.replace(found, n2, string3);
        found += n3;
        found = string1.find(string2, found);
    }

    size_t sz = strlen(str1);

    if (string1.length() <= sz)
        strcpy(str1, string1.c_str());
    
}