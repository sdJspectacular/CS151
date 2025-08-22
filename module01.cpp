#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main()
{
#if 0
    vector<int> scores;
    cout << scores.size() << "\n";
    cout << scores.capacity() << "\n";

    scores.push_back(1);
    cout << scores.size() << "\n";
    cout << scores.capacity() << "\n";

    scores.push_back(2);
    cout << scores.size() << "\n";
    cout << scores.capacity() << "\n";

    scores.push_back(3);
    cout << scores.size() << "\n";
    cout << scores.capacity() << "\n";

    scores.push_back(4);
    cout << scores.size() << "\n";
    cout << scores.capacity() << "\n";

    scores.push_back(5);
    cout << scores.size() << "\n";
    cout << scores.capacity() << "\n";
#else
    vector<int> scores(30);
    cout << scores.size() << "\n";
    cout << scores.capacity() << "\n";

    scores.push_back(1);
    cout << scores.size() << "\n";
    cout << scores.capacity() << "\n";

    string a = "a";
    cout << a.length() << endl;


#endif

  int num = 5 ;
  cout << num++ << "  " 
       << num-- << "  "  
       << --num ; 
    return 0;
}
