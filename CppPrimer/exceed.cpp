#include <iostream>
#include <limits.h>


int main()
{
    using namespace std;
    short shortmax = SHRT_MAX;
    short exceedshort = shortmax + 1;
    int exceedshort2 = shortmax + 1;
    cout << "sort max is :" << shortmax << endl;
    cout << "short res for short max + 1 is :" << exceedshort << endl;
    cout << "int res for short max + 1 is :" << exceedshort2 << endl;

    return 0;
}