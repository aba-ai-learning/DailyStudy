#include <iostream>

int main()
{
    using namespace std;
    int a = 42;
    int b = 0x42;
    int c = 042;
    cout << "demical a 42 is : " << a << endl;
    cout << "demical b 0x42 is : " << b << endl;
    cout << "demical c 042 is : " << c << endl;
    cout << hex;
    cout << "hexademical b 0x42 is: " << b << endl;
    cout << oct;
    cout << "octal c 042 is: " << c << endl;

    return 0;

}