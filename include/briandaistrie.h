#ifndef __BRIANDAISTRIE_H
#define __BRIANDAISTRIE_H

#include "trie.h"
#include <vector>

class BriandaisTrie : public Trie {
public:
    BriandaisTrie();
    BriandaisTrie(const BriandaisTrie &t);
    ~BriandaisTrie();
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
    BriandaisTrie merge(BriandaisTrie &trie);

    BriandaisTrie& operator=(const BriandaisTrie& t);

private:
    void listWords(std::vector<std::string> &vs, std::string &s);

    BriandaisTrie *m_child;
    BriandaisTrie *m_right;
    bool m_key;
    char m_char;
};

#endif /* __BRIANDAISTRIE_H */
