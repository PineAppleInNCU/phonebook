#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "phonebook_opt.h"

/* TODO: FILL YOUR OWN IMPLEMENTATION HERE! */
entry *findName(char lastName[], entry *pHead)
{
    while (pHead != NULL) {
        if (strcasecmp(lastName, pHead->lastName) == 0)
            return pHead;
        pHead = pHead->pNext;
    }
    return NULL;

    /* TODO: implement */
    //return NULL;
}

entry *append(char lastName[], entry *e, POOL *p)
{
    /* allocate memory for the new entry and put lastName */
    e->pNext = (entry *) pool_alloc(p, sizeof(entry));
    e = e->pNext;
    strcpy(e->lastName, lastName);
    e->pNext = NULL;

    return e;
    /* TODO: implement */
    //return NULL;
}
/* memory pool */
POOL * pool_create( size_t size )
{
    POOL * p = (POOL*)malloc( size + sizeof(POOL) );
    p->next = (char*)&p[1];//不懂這行的意義
    p->end = p->next + size;
    //printf("%p %p %p %p\n",&(p->next),&(p->end),p->next,p[1]);
    return p;
}

void pool_destroy( POOL *p )
{
    free(p);
}

size_t pool_available( POOL *p )
{
    return p->end - p->next;
}

void * pool_alloc( POOL *p, size_t size )
{
    if( pool_available(p) < size ) return NULL;
    void *mem = (void*)p->next;
    p->next += size;
    return mem;
}
