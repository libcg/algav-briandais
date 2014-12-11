#include "briandaistrie.h"
#include "test.h"
#include <iostream>
#include <sstream>
#include <algorithm>

using namespace std;

TEST(base)
{
    cout << " base";
    string sentence(
        "A quel genial professeur de dactylographie sommes nous redevables de l"
        "a superbe phrase ci dessous, un modele du genre, que toute dactylo con"
        "nait par coeur puisque elle fait appel a chacune des touches du clavie"
        "r de la machine a ecrire ?"
    );
    string word;
    BriandaisTrie t;

    istringstream iss(sentence, istringstream::in);

    /* Iterate over each word of the sentence */
    while (iss >> word) {
        /* Remove non-letter characters */
        word.erase(remove_if(word.begin(), word.end(),
            [](char c) {
                return !((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'));
            }),
            word.end()
        );

        if (!word.empty()) {
            t.insert(word);
        }
    }

    ASSERT(t.countWords() == 35)

    SUCCESS()
}

TEST(exists)
{
    cout << " exists";
    BriandaisTrie t;

    ASSERT(!t.exists(""))

    t.insert("algav");
    ASSERT(t.exists("algav") && !t.exists("alga") && !t.exists("a"))

    t.insert("alga");
    ASSERT(t.exists("alga"))

    SUCCESS()
}

TEST(countWords)
{
    cout << " countWords";
    BriandaisTrie t;

    t.insert("");
    ASSERT(t.countWords() == 0)

    t.insert("algav");
    ASSERT(t.countWords() == 1)

    t.insert("algav");
    ASSERT(t.countWords() == 1)

    t.insert("a");
    ASSERT(t.countWords() == 2)

    t.insert("al");
    ASSERT(t.countWords() == 3)

    t.insert("test");
    ASSERT(t.countWords() == 4)

    t.insert("akga");
    ASSERT(t.countWords() == 5)

    SUCCESS()
}

TEST(listWords)
{
    cout << " listWords";
    BriandaisTrie t;

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
    ASSERT(t.listWords().size() == 10)
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

    SUCCESS()
}

TEST(countNil)
{
    cout << " countNil";
    BriandaisTrie t;  

    ASSERT(t.countNil() == 2)

    t.insert("m");
    ASSERT(t.countNil() == 2)

    t.insert("ma");
    ASSERT(t.countNil() == 3)
    
    t.insert("a");
    ASSERT(t.countNil() == 4)

    t.insert("z");
    ASSERT(t.countNil() == 5)

    SUCCESS()  
}

TEST(height)
{
    cout << " height";
    BriandaisTrie t;  

    ASSERT(t.height() == 1)

    t.insert("m");
    ASSERT(t.height() == 1)

    t.insert("ma");
    ASSERT(t.height() == 2)
    
    t.insert("a");
    ASSERT(t.height() == 2)

    t.insert("z");
    ASSERT(t.height() == 3)

    t.insert("abcdefghijklmnopqrstuvwxyz");
    ASSERT(t.height() == 27)

    SUCCESS()  
}

TEST(meanDepth)
{
    cout << " meanDepth";
    BriandaisTrie t;

    ASSERT(t.meanDepth() == 1)

    t.insert("bbb");
    ASSERT(t.meanDepth() == 3)

    t.insert("cb");
    ASSERT(t.meanDepth() == 3)

    t.insert("abcde");
    ASSERT(t.meanDepth() == 4)

    SUCCESS()
}

TEST(prefix)
{
    cout << " prefix";
    BriandaisTrie t;

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

TEST(remove)
{
    cout << " remove";
    BriandaisTrie t;

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

TEST(merge)
{
    cout << " merge";
    BriandaisTrie ta;
    BriandaisTrie tb;
    BriandaisTrie tc;

    ta.insert("hello");
    ta.insert("algav");
    ta.insert("set");
    tb.insert("algev");
    tb.insert("ermaged");
    tb.insert("success");
    tb.insert("set");
    tb.insert("alg");
    tc = ta.merge(tb);
    ASSERT(tc.listWords().at(0) == "alg")
    ASSERT(tc.listWords().at(1) == "algav")
    ASSERT(tc.listWords().at(2) == "algev")
    ASSERT(tc.listWords().at(3) == "ermaged")
    ASSERT(tc.listWords().at(4) == "hello")
    ASSERT(tc.listWords().at(5) == "set")
    ASSERT(tc.listWords().at(6) == "success")

    SUCCESS()
}

int main(int argc, char *argv[])
{
    test_t test[] =
    {
        test_base,
        test_exists,
        test_countWords,
        test_listWords,
        test_countNil,
        test_height,
        test_meanDepth,
        test_prefix,
        test_remove,
        test_merge
    };

    return test_run(test, sizeof(test) / sizeof(test_t));
}
