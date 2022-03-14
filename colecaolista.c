#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <C:\Users\Caio\Desktop\Ed1\TrabalhoLista\colecaolista.h>




SLList *sllCreate(){

SLList *l;
l = (SLList *)malloc(sizeof(SLList));
    if(l!=NULL){
        l->first = NULL;
        return l;
    }
    return NULL;
}

int sllInsertFirst(SLList *l, void *elm){
SLNode *newnode;
    if(l!=NULL){
        newnode = (SLNode*)malloc(sizeof(SLNode));
        if(newnode!=NULL){
            newnode->data = elm;
            if(l->first == NULL){
                newnode->next = NULL;
            }else{
                newnode->next = l->first;
            }
            l->first = newnode;
            return 1;
        }
    }
    return 0;
}

int sllDestroy(SLList *l){

    if(l!=NULL){
        if(l->first==NULL){
            free(l);
            return 1;
        }
    }
    return 0;
}

void *sllQuery(SLList *l, void *key, int (*cmp)(void*, void*)){

SLNode *cur;
    if(l!=NULL){
        if(l->first!=NULL){
            cur = l->first;
            while(cur->next!=NULL && cmp(key,cur->data)!=1){
                cur = cur->next;
            }
            if(cmp(key,cur->data)==1){
                return cur->data;
            }
        }
    }
    return NULL;
}

void *sllRemoveSpec(SLList *l, void *key, int (*cmp)(void*, void*)){

SLNode *prev,*spec;
void *data;
    if(l!=NULL){
        if(l->first!=NULL){
            spec = l->first;
            prev = NULL;
            while(spec->next!=NULL && cmp(key,spec->data)!=1){
                prev = spec;
                spec = spec->next;
            }
            if(cmp(key,spec->data)==1){
                data = spec->data;
                if(spec==l->first){
                    l->first = spec->next;
                }else{
                    prev->next = spec->next;
                }
                free(spec);
                return data;
            }
        }
        return NULL;

    }
}
