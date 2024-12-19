#ifndef TREES_H
#define TREES_H

typedef struct node node;
typedef struct edge edge;
typedef struct Tree Tree;

Tree *initTree(Tree **t);
edge *initEdge(edge **e);
node *initNode(node **n);

node *getRoot(Tree *t);
void assignWeights(Tree **t, float numLiberals, float numFascists);
float outcomeProbability(Tree *t, char *policySequence);

void destroyTree(Tree **t);
void destroyEdge(edge **e);
void destroyNode(node **n);

#endif
