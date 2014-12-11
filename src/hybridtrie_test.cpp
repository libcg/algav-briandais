#include "hybridtrie.h"
#include <iostream>

using namespace std;

#define ASSERT(p) \
    if (!(p)) { return true; }
#define SUCCESS() \
    return false;

static bool test_exists()
{
    cout << " exists";
    HybridTrie t;

    ASSERT(!t.exists(""))

    t.insert("algav");
    ASSERT(t.exists("algav") && !t.exists("alga") && !t.exists("a"))

    t.insert("alga");
    ASSERT(t.exists("alga"))

    SUCCESS()
}

static bool test_countWords()
{
    cout << " countWords";
    HybridTrie t;

    t.insert("");
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

static bool test_listWords()
{
    cout << " listWords";
    HybridTrie t;

    ASSERT(t.listWords().empty())

    t.insert("algav");
    t.insert("abc");
    t.insert("helloworld");
    t.insert("z");
    t.insert("because");
    t.insert("caused");
    t.insert("cause");
    t.insert("cauded");
    t.insert("cauzed");
    t.insert("hellozorld");
    t.insert("algav");
    ASSERT(t.listWords().at(0) == "abc")
    ASSERT(t.listWords().at(1) == "algav")
    ASSERT(t.listWords().at(2) == "because")
    ASSERT(t.listWords().at(3) == "cauded")
    ASSERT(t.listWords().at(4) == "cause")
    ASSERT(t.listWords().at(5) == "caused")
    ASSERT(t.listWords().at(6) == "cauzed")
    ASSERT(t.listWords().at(7) == "helloworld")
    ASSERT(t.listWords().at(8) == "hellozorld")
    ASSERT(t.listWords().at(9) == "z")
    ASSERT(t.listWords().size() == 10)

    SUCCESS()
}

static bool test_countNil()
{
    cout << " countNil";
    HybridTrie t;  

    ASSERT(t.countNil() == 3)

    t.insert("m");
    ASSERT(t.countNil() == 3)

    t.insert("ma");
    ASSERT(t.countNil() == 5)
    
    t.insert("a");
    ASSERT(t.countNil() == 7)

    t.insert("z");
    ASSERT(t.countNil() == 9)

    SUCCESS()  
}

static bool test_height()
{
    cout << " height";
    HybridTrie t;  

    ASSERT(t.height() == 1)

    t.insert("m");
    ASSERT(t.height() == 1)

    t.insert("ma");
    ASSERT(t.height() == 2)
    
    t.insert("a");
    ASSERT(t.height() == 2)

    t.insert("z");
    ASSERT(t.height() == 2)

    t.insert("abcdefghijklmnopqrstuvwxyz");
    ASSERT(t.height() == 27)

    SUCCESS()  
}

static bool test_meanDepth()
{
    cout << " meanDepth";
    HybridTrie t;

    ASSERT(t.meanDepth() == 1)

    t.insert("bbb");
    ASSERT(t.meanDepth() == 3)

    t.insert("cb");
    ASSERT(t.meanDepth() == 3)

    t.insert("abcde");
    ASSERT(t.meanDepth() == 4)

    SUCCESS()
}

static bool test_prefix()
{
    cout << " prefix";
    HybridTrie t;

    ASSERT(t.prefix("algav") == 0)

    t.insert("algav");
    ASSERT(t.prefix("a") == 1)
    ASSERT(t.prefix("al") == 1)
    ASSERT(t.prefix("alg") == 1)
    ASSERT(t.prefix("alga") == 1)
    ASSERT(t.prefix("algav") == 1)

    t.insert("alaav");
    t.insert("aagav");
    ASSERT(t.prefix("a") == 3)
    ASSERT(t.prefix("al") == 2)
    ASSERT(t.prefix("aag") == 1)
    ASSERT(t.prefix("d") == 0)

    SUCCESS()
}

static bool test_remove()
{
    cout << " remove";
    HybridTrie t;

    t.insert("algav");
    t.insert("alg");
    t.remove("alga");
    ASSERT(t.height() == 5)
    ASSERT(t.prefix("a") == 2)

    t.remove("algav");
    ASSERT(t.height() == 3)
    ASSERT(t.prefix("a") == 1)

    t.remove("alg");
    ASSERT(t.height() == 1)
    ASSERT(t.prefix("a") == 0)

    SUCCESS()
}

static bool (*test[])() =
{
    test_exists,
    test_countWords,
    test_listWords,
    test_countNil,
    test_height,
    test_meanDepth,
    test_prefix,
    test_remove
};

int main(int argc, char *argv[])
{
    int n = (sizeof(test) / sizeof(bool(*)()));
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
