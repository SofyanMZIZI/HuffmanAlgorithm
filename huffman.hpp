#include <iostream>
#include <string>
#include <queue>


// noeud de notre arbre 
struct Node
{
    char ch;
    int freq;
    Node *left, *right;
};

// ce qu'on va utiliser pour retourner quel noeuds a la plus priorité car il a le minimum de frequence
struct comparer
{
    bool operator()(Node *l, Node *r)
    {
        bool prioriter = l->freq > r->freq;
        return prioriter;
    }
};
