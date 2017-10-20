#include <iostream>
#include <string>

using namespace std;

int main()
{
    string s;
    cin >> s;

    int contiguous = 1;
    for (size_t i = 1; i < s.length(); ++i)
    {
        if (s[i] == s[i - 1])
        {
            contiguous += 1;
            if (contiguous == 7)
            {
                cout << "YES" << endl;
                return 0;
            }
        }
        else
        {
            contiguous = 1;
        }
    }

    cout << "NO" << endl;
    return 0;
}