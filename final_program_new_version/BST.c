#include "basic.h"
#include "base_operator.h"
#include "BST.h"

struct Ntree *root0 = NULL;
struct Mtree *root1 = NULL;
struct Dtree *root2 = NULL;

struct Ntree *insert0(struct Ntree *curnode, char *data)
{
    // insert
    if (curnode == NULL)
    {
        // create new node
        struct Ntree *newData = (struct Ntree *)malloc(sizeof(struct Ntree));
        strcpy(newData->data, data);
        newData->Lchild = NULL;
        newData->Rchild = NULL;
        return newData;
    }
    else
    {
        // name
        if (strcmp(curnode->data, data) > 0)
            curnode->Lchild = insert0(curnode->Lchild, data);
        else
            curnode->Rchild = insert0(curnode->Rchild, data);
    }
    return curnode;
}

struct Mtree *insert1(struct Mtree *curnode, int data, char *name)
{
    // insert
    if (curnode == NULL)
    {
        // create new node
        struct Mtree *newData = (struct Mtree *)malloc(sizeof(struct Mtree));
        newData->data = data;
        strcpy(newData->N, name);
        newData->Lchild = NULL;
        newData->Rchild = NULL;
        return newData;
    }
    else // money
    {
        if (curnode->data > data)
            curnode->Lchild = insert1(curnode->Lchild, data, name);
        else
            curnode->Rchild = insert1(curnode->Rchild, data, name);
    }
    return curnode;
}

struct Dtree *insert2(struct Dtree *curnode, char *data, char *name)
{
    // insert
    if (curnode == NULL)
    {
        // create new node
        struct Dtree *newData = (struct Dtree *)malloc(sizeof(struct Dtree));
        strcpy(newData->data, data);
        strcpy(newData->N, name);

        newData->Lchild = NULL;
        newData->Rchild = NULL;
        return newData;
    }
    else
    {
        // date //TODO
        if (strcmp(curnode->data, data) < 0)
            curnode->Lchild = insert2(curnode->Lchild, data, name);
        else
            curnode->Rchild = insert2(curnode->Rchild, data, name);
    }
    return curnode;
}

void traverse0(struct Ntree *curnode)
{
    if (curnode)
    {
        traverse0(curnode->Lchild);
        printf("%s\n", curnode->data);
        traverse0(curnode->Rchild);
    }
}
void traverse1(struct Mtree *curnode)
{
    if (curnode)
    {
        traverse1(curnode->Lchild);
        printf("%s\t%d\n", curnode->N, curnode->data);
        traverse1(curnode->Rchild);
    }
}
void traverse2(struct Dtree *curnode)
{
    if (curnode)
    {
        traverse2(curnode->Lchild);
        printf("%s\t%s\n", curnode->N, curnode->data);
        traverse2(curnode->Rchild);
    }
}
void delete_tree0(struct Ntree *curnode)
{
    if (curnode == NULL)
        return;
    delete_tree0(curnode->Lchild);
    delete_tree0(curnode->Rchild);
    free(curnode);
}
void delete_tree1(struct Mtree *curnode)
{
    if (curnode == NULL)
        return;
    delete_tree1(curnode->Lchild);
    delete_tree1(curnode->Rchild);
    free(curnode);
}
void delete_tree2(struct Dtree *curnode)
{
    if (curnode == NULL)
        return;
    delete_tree2(curnode->Lchild);
    delete_tree2(curnode->Rchild);
    free(curnode);
}

void my_sort_BST(struct basic_account * HEAD)
{
    struct basic_account *list = HEAD;
    printf("1.NAME\t2.TOTAL MONEY\t3.DATE\n");
    printf("SORTING BY:");
    char status;
    scanf(" %c", &status);
    switch (status)
    {
    case '1':
        for (; list != NULL; list = list->next)
            root0 = insert0(root0, list->name);
        traverse0(root0), delete_tree0(root0);
        root0 = NULL;
        break;
    case '2':
        for (; list != NULL; list = list->next)
            root1 = insert1(root1, list->money, list->name);
        traverse1(root1), delete_tree1(root1);
        root1 = NULL;
        break;
    case '3':
        for (; list != NULL; list = list->next)
            root2 = insert2(root2, list->trade->date, list->name);
        traverse2(root2), delete_tree2(root2);
        root2 = NULL;
        break;
    default:
        printf("Please enter the correct information.\n");
        break;
    }
    wait_screen();
}