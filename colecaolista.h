#ifndef _COLECAOLISTA_
#define _COLECAOLISTA_

typedef struct _SLNode_{
    struct _SLNode_ *next;
    void *data;
}SLNode;

typedef struct _SLList_{
    SLNode *first;
    SLNode *cur;


}SLList;

int cmp(void *elm1, void *elm2);
SLList *sllCreate();
int sllInsertFirst(SLList *l, void *elm);
int sllDestroy(SLList *l);
void *sllQuery(SLList *l, void *key, int (*cmp)(void*, void*));
void *sllRemoveSpec(SLList *l, void *key, int (*cmp)(void*, void*));

#endif // _COLECAOLISTA_
