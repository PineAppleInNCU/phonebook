#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "phonebook_opt.h"

bst_return LinkedlistToBST(int n, entry *phead)
{
    bst_return re;
    re.head=phead;
    re.root=NULL;
    if (n <= 0) {
        return re;
    }
    re = LinkedlistToBST(n/2, phead);
    treeEntry *left = re.root;
    phead = re.head;
    treeEntry *root=(treeEntry *)malloc(sizeof(treeEntry));
    root->left = left;
    strcpy(root->lastName,phead->lastName);
    phead=phead->pNext;
    re = LinkedlistToBST(n-n/2-1, phead);
    root->right = re.root;
    re.root = root;

    return re;
}


/* TODO: FILL YOUR OWN IMPLEMENTATION HERE! */
treeEntry *findName(char lastName[], treeEntry *pHead)
{
    while (pHead != NULL) {
        int result = strcmp(lastName, pHead->lastName);
        //printf("%s\n",pHead->lastName);
        if (result == 0) {
            return pHead;
        } else if (result > 0) {
            pHead = pHead->right;
        } else {
            pHead = pHead->left;
        }
    }
    return NULL;
    /* TODO: implement */
    //return NULL;
}

entry *append(char lastName[], entry *e)
{
    /* allocate memory for the new entry and put lastName */
    e->pNext = (entry *) malloc(sizeof(entry));
    e = e->pNext;
    strcpy(e->lastName, lastName);
    e->pNext = NULL;

    return e;
    /* TODO: implement */
    //return NULL;
}
