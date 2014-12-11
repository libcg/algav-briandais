#include "test.h"
#include <iostream>

using namespace std;

bool test_run(test_t test[], int n)
{
    int count = 0;

    for (int i = 0; i < n; i++) {
        cout << "test " << i;

        if (test[i]()) {
            cout << " failed" << endl;
        }
        else {
            cout << " passed" << endl;
            count++;
        }
    }

    cout << count << '/' << n << " tests passed." << endl;

    return (count != n);
}
