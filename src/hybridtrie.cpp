#include "hybridtrie.h"
#include <iostream>

HybridTrie::HybridTrie() :
    m_left(NULL),
    m_child(NULL),
    m_right(NULL),
    m_key(false),
    m_char('\0')
{}

HybridTrie::~HybridTrie()
{
    delete m_left;
    delete m_child;
    delete m_right;
}

void HybridTrie::insert(std::string word)
{
    if (word.empty()) {
        return;
    }

    /* If we are inserting the last character, this node is marked as a key */
    m_key = (word.length() == 1);

    if (m_char == '\0') {
        m_char = word.front();
    }

    if (word.front() < m_char) {
        if (m_left == NULL) {
            m_left = new HybridTrie();
        }

        m_left->insert(word);
    }
    else if (word.front() == m_char && !m_key) {
        if (m_child == NULL) {
            m_child = new HybridTrie();
        }

        /* Insert the string minus the first letter */
        m_child->insert(word.erase(0, 1));
    }
    else if (word.front() > m_char) {
        if (m_right == NULL) {
            m_right = new HybridTrie();
        }

        m_right->insert(word);
    }
}

void HybridTrie::print()
{
    if (m_left) {
        m_left->print();
    }

    std::cout << m_char;

    if (m_child) {
        m_child->print();
    }
    else {
        std::cout << std::endl;
    }

    if (m_right) {
        m_right->print();
    }
}

bool HybridTrie::exists(std::string word)
{
    if (word.empty()) {
        return false;
    }

    if (word.length() == 1) {
        return word.front() == m_char && m_key;
    }

    if (word.front() < m_char && m_left) {
        return m_left->exists(word);
    }
    else if (word.front() == m_char && m_child) {
        return m_child->exists(word.erase(0, 1));
    }
    else if (word.front() > m_char && m_right) {
        return m_right->exists(word);
    }

    return false;
}

int HybridTrie::countWords()
{
    /* We count the number of keys (last letter of a word) found in the tree */
    int count = (int)m_key;

    if (m_left) { 
        count += m_left->countWords();
    }
    if (m_child) {
        count += m_child->countWords();
    }
    if (m_right) {
        count += m_right->countWords();
    }

    return count;
}

std::vector<std::string> HybridTrie::listWords()
{
    std::vector<std::string> vs;
    std::string s;

    listWords(vs, s);

    return vs;
}

void HybridTrie::listWords(std::vector<std::string> &vs, std::string &s)
{
    std::string sc(s);

    if (m_left) {
        m_left->listWords(vs, s);
    }

    sc.append(std::string(&m_char, 1));

    /* We have encountered the end of a word. Add it to the vector */
    if (m_key) {
        vs.push_back(sc);
    }

    if (m_child) {
        m_child->listWords(vs, sc);
    }

    if (m_right) {
        m_right->listWords(vs, s);
    }
}

int HybridTrie::countNil()
{
    int count = (m_left == NULL) + (m_child == NULL) + (m_right == NULL);

    if (m_left) { 
        count += m_left->countNil();
    }
    if (m_child) {
        count += m_child->countNil();
    }
    if (m_right) {
        count += m_right->countNil();
    }

    return count;
}

int HybridTrie::height()
{
    int maxh = 0;
    int subh;

    if (m_left && (subh = m_left->height()) > maxh) { 
        maxh = subh;
    }
    if (m_child && (subh = m_child->height()) > maxh) { 
        maxh = subh;
    }
    if (m_right && (subh = m_right->height()) > maxh) { 
        maxh = subh;
    }

    return 1 + maxh;
}

int HybridTrie::meanDepth()
{
    int sum = 0;
    int cnt = 0;

    if (m_left) { 
        sum += m_left->meanDepth();
        cnt ++;
    }
    if (m_child) { 
        sum += m_child->meanDepth();
        cnt ++;
    }
    if (m_right) { 
        sum += m_right->meanDepth();
        cnt ++;
    }

    if (cnt > 0) {
        return 1 + sum / cnt;
    }
    else {
        return 1;
    }
}

int HybridTrie::prefix(std::string word)
{
    if (word.empty()) {
        return 0;
    }

    if (word.length() == 1 && word.front() == m_char) {
        int count = (int)m_key;

        if (m_child) {
            count += m_child->countWords();
        }

        return count;
    }

    if (word.front() < m_char && m_left) {
        return m_left->prefix(word);
    }
    else if (word.front() == m_char && m_child) {
        return m_child->prefix(word.erase(0, 1));
    }
    else if (word.front() > m_char && m_right) {
        return m_right->prefix(word);
    }

    return 0;
}

void HybridTrie::remove(std::string word)
{
    if (word.empty()) {
        return;
    }

    /* Deleting the key deletes the word */
    if (word.length() == 1 && word.front() == m_char) {
        m_key = false;
    }

    if (word.front() < m_char && m_left) {
        m_left->remove(word);
    }
    else if (word.front() == m_char && m_child) {
        m_child->remove(word.erase(0, 1));

        /* If there is no words left in the subtree we can remove it safely */
        if (m_child->countWords() == 0) {
            delete m_child;
            m_child = NULL;
        }
    }
    else if (word.front() > m_char && m_right) {
        m_right->remove(word);
    }
}
