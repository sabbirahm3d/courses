#include "TicTacTree.h"

TicTacTree::TicTacTree()
{
    root = new TicTacNode();
}

TicTacTree::~TicTacTree()
{
    // Free memory
}

void TicTacTree::addWord(string s)
{
    TicTacNode* current = root;

    if ( s.length() == 0 )
    {
        current->setWordMarker(); // an empty word
        return;
    }

    for ( int i = 0; i < s.length(); i++ )
    {        
        TicTacNode* child = current->findChild(s[i]);
        if ( child != NULL )
        {
            current = child;
        }
        else
        {
            TicTacNode* tmp = new TicTacNode();
            tmp->setContent(s[i]);
            current->appendChild(tmp);
            current = tmp;
        }
        if ( i == s.length() - 1 )
            current->setWordMarker();
    }
}


bool TicTacTree::searchWord(string s)
{
    TicTacNode* current = root;

    while ( current != NULL )
    {
        for ( int i = 0; i < s.length(); i++ )
        {
            TicTacNode* tmp = current->findChild(s[i]);
            if ( tmp == NULL )
                return false;
            current = tmp;
        }

        if ( current->wordMarker() )
            return true;
        else
            return false;
    }

    return false;
}