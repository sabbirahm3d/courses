// #include "TicTacToe.h"
#include "TicTacTrie.h"


TicTacTrie::TicTacTrie() {

    root = new TicTacNode();

}


TicTacTrie::~TicTacTrie() {

    delete root;
    root = NULL;

}


void TicTacTrie::AddGame(TicTacToe& game) {

    while ( game.Size() ) {
        TicTacNode* cursor = game.Pop();
        // addWord(cursor);
        delete cursor;
        cursor = NULL;
    }

    switch( game.GetResults() ) {

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

// void TicTacTrie::addWord(TicTacNode* hey) {

//     string word = hey->content();

//     if (word.length()) {
//         ++m_size;
//         string subword = word.substr(1, word.size()-1);
//         if (m_children[word[0]]) {
//             m_children[word[0]]->addWord(hey->setContent(subword));
//         } else {
//             TicTacTrie *tmp = new TicTacTrie();
//             tmp->addWord(hey->setContent(subword));
//             m_children[word[0]] = tmp;
//         }
//     }

// void TicTacTrie::addWord(TicTacNode* hey) {

//     TicTacNode* current = root;

//     // string s = hey->m_data;

//     if ( s.length() == 0 )
//     {
//         current->setWordMarker(); // an empty word
//         return;
//     }

//     for ( int i = 0; i < s.length(); i++ )
//     {        
//         TicTacNode* child = current->findChild(s[i]);
//         if ( child != NULL )
//         {
//             current = child;
//         }
//         else
//         {
//             TicTacNode* tmp = new TicTacNode();
//             tmp->setContent(s[i]);
//             current->appendChild(tmp);
//             current = tmp;
//         }
//         if ( i == s.length() - 1 )
//             current->setWordMarker();
//     }
// }


// bool TicTacTrie::searchWord(string s)
// {
//     TicTacNode* current = root;

//     while ( current != NULL )
//     {
//         for ( int i = 0; i < s.length(); i++ )
//         {
//             TicTacNode* tmp = current->findChild(s[i]);
//             if ( tmp == NULL )
//                 return false;
//             current = tmp;
//         }

//         if ( current->wordMarker() )
//             return true;
//         else
//             return false;
//     }

//     return false;
// }