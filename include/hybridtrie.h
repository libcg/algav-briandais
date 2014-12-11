#ifndef __HYBRIDTRIE_H
#define __HYBRIDTRIE_H

#include "trie.h"
#include <vector>

class HybridTrie : public Trie {
public:
    HybridTrie();
    HybridTrie(const HybridTrie &t);
    ~HybridTrie();
    void insert(std::string word);
    void print();

    /* Advanced functions */
    bool exists(std::string word);
    int countWords();
    std::vector<std::string> listWords();
    int countNil();
    int height();
    int meanDepth();
    int prefix(std::string word);
    void remove(std::string word);

    /* Complex functions */
    HybridTrie merge(HybridTrie &trie);

    HybridTrie& operator=(const HybridTrie& t);

private:
    void listWords(std::vector<std::string> &vs, std::string &s);
    void insertSorted(std::vector<std::string> &vs, int begin, int end);

    HybridTrie *m_left;
    HybridTrie *m_child;
    HybridTrie *m_right;
    bool m_key;
    char m_char;
};

#endif /* __HYBRIDTRIE_H */
