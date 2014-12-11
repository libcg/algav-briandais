#ifndef __HYBRIDTRIE_H
#define __HYBRIDTRIE_H

#include "trie.h"
#include <vector>

class HybridTrie : public Trie {
public:
    HybridTrie();
    ~HybridTrie();
    void insert(std::string word);
    void print();

    /* Advanced functions */
    bool exists(std::string word);
    int countWords();
    std::vector<std::string> listWords() { return std::vector<std::string>(); }
    int countNil() {return 0;}
    int height() {return 0;}
    int meanDepth() {return 0;}
    int prefix(std::string &word) {return 0;}
    void remove(std::string &word) {}

private:
    HybridTrie *m_left;
    HybridTrie *m_child;
    HybridTrie *m_right;
    bool m_key;
    char m_char;
};

#endif /* __HYBRIDTRIE_H */
