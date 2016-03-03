#ifndef TICTACTREE_H
#define TICTACTREE_H


#include "TicTacNode.h"

class TicTacTree {

public:

    TicTacTree();
    TicTacTree(string);
    ~TicTacTree();

    void ReadGame(string);
    // void addWord(string s);
    // bool searchWord(string s);
    // void deleteWord(string s);

private:

    TicTacNode* root;

};

#endif