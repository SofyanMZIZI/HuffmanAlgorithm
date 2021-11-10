#ifndef libs_H_
#define libs_H_


#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define FALSE 0
#define TRUE 1

typedef enum boolean {false, true} boolean;


typedef struct node
{
    char c;
    unsigned c_occ;
} node;


typedef struct stack
{
    node Node;
    struct stack *nextNode;
} stack;


typedef struct tree
{
    node Node;
    boolean codeValue;
    struct tree *leftNode;
    struct tree *rightNode;
}tree;


#endif
