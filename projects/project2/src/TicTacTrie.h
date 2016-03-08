#ifndef TICTACTRIE_H
#define TICTACTRIE_H


#include "TicTacNode.h"
#include "TicTacToe.h"

class TicTacTrie {

public:

    TicTacTrie();
    ~TicTacTrie();
    void AddGame(TicTacToe& game);
    // void addWord(TicTacNode* s);
    // bool searchWord(string s);
    // void deleteWord(string s);

private:

    TicTacNode* root;
    int m_xWins;
    int m_oWins;
    int m_draws;
    int m_size;

};

#endif