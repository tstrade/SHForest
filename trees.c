#include "trees.h"

#include <stdio.h>
#include <stdlib.h>

#define DRAW 0
#define DISCARD 1
#define CHOOSE 2

#define DIS_F 3
#define DIS_L 4

#define F 11
#define L 6


struct Tree {
  node *root;
  int depth;
};

struct node {
  node *parent;
  node *leftChild;
  node *rightChild;

  edge *incoming;
  
  int state;
  int *numPolicies;
  float stateProbability;
};

struct edge {
  node *start;
  node *end;
  
  int choice;choice
};

void checkNULL((void *)ptr) {
  if (ptr == NULL) {
    fprintf(stderr, "Allocation failed!\n");
    exit(EXIT_FAILURE);
  }
  return;
}

// Will need different versions based on what the turn is
// Draw is the probability of getting three cards
// Discard is probability one of three cards is lib/fasc
// Choose is probability, given the recent outcome, one of two cards is lib/fasc
float considerChoice(edge *e) {
  float probability = 0;
  float numLib = e->start->numPolicies[0];
  float numFasc = e->start->numPolicies[1];
  float totalCards = numFasc + numLib;

  if (e->choice == DIS_F) {
    probability = (e->start->stateProbability) * (numLib - 1)/(totalCards - 1);
  }
  return probability;
  
}
  
Tree *initTree(Tree **t) {
  (*t) = malloc(sizeof(Tree));
  checkNULL((void *)(*t));

  (*t)->root = initNode(&(*t)->root);
  (*t)->depth = 1;

  return *t;
}

edge *initEdge(node **start, edge **e, int choice) {
  (*e) = malloc(sizeof(edge));
  checkNULL((void *(*e)));


  (*e)->start = *start;
  
  (*e)->end = initNode((*e)->end);
  checkNULL((void *)(*e)->end);
  
  
  (*e)->end->incoming = *e;
  (*e)->end->parent = *start;

  if (choice == DIS_F) {
    (*start)->rightChild = (*e)->end;
  }
  else if (choice == DIS_L) {
    (*start)->leftChild = (*e)->end;
  }
  else {
    (*e)->choice = -1;
    return *e;
  }

  (*e)->choice = choice;

  return *e;
};

node *initNode(node **n) {
  (*n) = malloc(sizeof(node));
  checkNULL((void *)(*n));

  (*n)->numPolicies = calloc(2, sizeof(int));
  checkNULL((void *)(*n)->numPolicies);

  return *n;
}

void assignWeights(Tree **t) {
  node *n = (*t)->root;

  
  
  
}

  // F 11, L 6
  // p(3F) = 11/17 * 10/16 * 9/15

  // F 8, L 6
  // p(discard fascist) = 1
