/* File:    TicTacTrie.h
 * Project: CMSC 341: Project 2, Spring 2016
 * Author:  Sabbir Ahmed
 * Date:    3/14/16
 * Section: 02
 * E-mail:  sabbir1@umbc.edu
 *
 * Description:
 * This class holds the trie data structure using TicTacNode objects
 * This class contains the trie data structure, which will hold all paths for
 * the TicTacToe games
 */

#include "TicTacTrie.h"

TicTacTrie::TicTacTrie() {

    root = new TicTacNode();

}


TicTacTrie::~TicTacTrie() {

    delete root;
    root = NULL;

    for ( unsigned int i = 0; i < m_leaves.size(); i++ ) {
        delete m_leaves[i];
        m_leaves[i] = NULL;
    }

}


int TicTacTrie::GetXWins() const { return m_xWins; }

int TicTacTrie::GetOWins() const { return m_oWins; }

int TicTacTrie::GetDraws() const { return m_draws; }

int TicTacTrie::Size() const { return m_size; }


void TicTacTrie::AddGame(TicTacToe &game) {

    while (game.Size()) {
        TicTacNode *cursor = game.Pop();
        AddTicTacNode(cursor->GetData());
        delete cursor;
        cursor = NULL;
    }

    switch (game.GetResults()) {

        case 1:
            m_xWins++;
            break;

        case 2:
            m_oWins++;
            break;

        case 3:
            m_draws++;
            break;

        default:
            break;

    }

}


void TicTacTrie::AddTicTacNode(string s) {


    TicTacNode* current = root;
    bool newChild = false;

    if ( !s.length() ) {
        return;
    }

    for ( unsigned int i = 0; i < s.length(); i++ ) {   

        TicTacNode* child = current->FindChild(s[i]);
        if ( child != NULL ) {
            current = child;
        }

        else {

            TicTacNode* tmp = new TicTacNode();
            tmp->SetChildContent(s[i]);
            current->AddChild(tmp);
            current = tmp;
            m_leaves.push_back(current);
            newChild = true;
        }

    }

    if ( newChild ) {
        m_size++;
    }

}