#ifndef BST_H
#define BST_H
#define maxsize 50
#define maxloan 1000000


struct Ntree
{
    char data[maxsize];
    struct Ntree *Lchild;
    struct Ntree *Rchild;
};
struct Mtree
{
    char N[maxsize];
    int data;
    struct Mtree *Lchild;
    struct Mtree *Rchild;
};
struct Dtree
{
    char N[maxsize], data[maxsize];
    int day[3];
    struct Dtree *Lchild;
    struct Dtree *Rchild;
};

struct Ntree *insert0(struct Ntree *, char *);
struct Mtree *insert1(struct Mtree *, int, char *);
struct Dtree *insert2(struct Dtree *, char *, char *);
void traverse0(struct Ntree *);
void traverse1(struct Mtree *);
void traverse2(struct Dtree *);
void delete_tree0(struct Ntree *);
void delete_tree1(struct Mtree *);
void delete_tree2(struct Dtree *);
void my_sort_BST(struct basic_account *);

#endif