#ifndef TICTACTREE_H
#define TICTACTREE_H


#include "TicTacNode.h"

class TicTacTree {

public:

    TicTacTree();
    ~TicTacTree();
    void addWord(string s);
    bool searchWord(string s);
    // void deleteWord(string s);

private:

    TicTacNode* root;

};

#endif