#ifndef __TEST_H
#define __TEST_H

#define ASSERT(p) \
    if (!(p)) { return true; }
#define SUCCESS() \
    return false;
#define TEST(name) \
    static bool test_ ##name () 

typedef bool (*test_t)();

bool test_run(test_t test[], int n);

#endif /* __TEST_H */
