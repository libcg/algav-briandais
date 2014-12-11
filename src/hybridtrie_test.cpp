#include "hybridtrie.h"
#include <iostream>

#define ASSERT(p) \
    if (!(p)) { return 1; }
#define SUCCESS() \
    return 0;

int test_exists()
{
    HybridTrie t;

    ASSERT(!t.exists(""))

    t.insert("algav");
    ASSERT(t.exists("algav") && !t.exists("alga") && !t.exists("a"))

    t.insert("alga");
    ASSERT(t.exists("alga"))

    SUCCESS()
}

int test_countWords()
{
    HybridTrie t;

    ASSERT(t.countWords() == 0)

    t.insert("algav");
    ASSERT(t.countWords() == 1)

    t.insert("algav");
    ASSERT(t.countWords() == 1)

    t.insert("alga");
    ASSERT(t.countWords() == 2)

    t.insert("test");
    ASSERT(t.countWords() == 3)

    t.insert("akga");
    ASSERT(t.countWords() == 4)

    SUCCESS()
}

int (*test[])() =
{
    test_exists,
    test_countWords,
};

int main(int argc, char *argv[])
{
    int n = (sizeof(test) / sizeof(int(*)()));
    int count = 0;

    for (int i = 0; i < n; i++) {
        std::cout << "running test " << i << "... ";
        if (test[i]()) {
            std::cout << "failed" << std::endl;
        }
        else {
            std::cout << "passed" << std::endl;
            count++;
        }
    }

    std::cout << count << '/' << n << " tests passed." << std::endl;

    return (count != n);
}
