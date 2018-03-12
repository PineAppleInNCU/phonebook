#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>


#include "phonebook_opt.h"

int StringToInteger(char lastName[])
{

    char *key=lastName;
    int all=0;

    while(*key) {
        all+=*key++;
    }
    // printf("all:%d\n",all);

    return all;
}
unsigned int BKDRHash(char *str)
{
    unsigned int seed = 131;
    unsigned int hash = 0;
    while (*str) {
        hash = hash * seed + (*str++);
    }
    return hash;
}
/* TODO: FILL YOUR OWN IMPLEMENTATION HERE! */
entry *findName(char lastName[], entry *hashtable[])
{
    //printf("BKDRHash: %u\n",BKDRHash(lastName));
    //int index = StringToInteger(lastName);
    unsigned int index = BKDRHash(lastName);
    index%=HASH_TABLE_SIZE;
    //printf("index:%d\n",index);
    entry *query=hashtable[index];
    while (query != NULL) {
        if (strcasecmp(lastName, query->lastName) == 0)
            return query;
        else
            query = query->pNext;
    }
    return NULL;
    /* while (pHead != NULL) {
        if (strcasecmp(lastName, pHead->lastName) == 0)
            return pHead;
        pHead = pHead->pNext;
    }
    return NULL; */

    /* TODO: implement */
    //return NULL;
}

void append(char lastName[], entry *hashtable[])
{
    /* TODO: implement */
    entry *newentry;
    newentry = (entry*) malloc(sizeof(entry));
    strcpy(newentry->lastName,lastName);
    newentry->pNext=NULL;

    //int index = StringToInteger(lastName);
    //index%=HASH_TABLE_SIZE;
    unsigned int index = BKDRHash(lastName);
    index%= HASH_TABLE_SIZE;
    //printf("index:%u\n",index);
    if (hashtable[index]==NULL) {
        hashtable[index]=newentry;
    } else {
        entry *pre=hashtable[index];
        while(pre->pNext!=NULL) {
            pre=pre->pNext;
        }
        pre->pNext=newentry;
    }
}

/*
 * first try hash function. buckets=503
 * overflow handling use chaining
 * hash function use simple division
 *
 *
 *
 */
