#ifndef NODE_H
#define NODE_H

struct Node 
{
    int key;
    Node *left;
    Node *right;

    Node(int k, Node *l, Node *r)
        : key(k), left(l), right(r) { }
};

#endif