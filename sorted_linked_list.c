#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "sorted_linked_list.h"

sorted_list* new_list()
{
    sorted_list *l = malloc(sizeof(sorted_list));
    if (l)
        l->head = NULL;
    return l;
}

bool insert_sorted(record **r, const char *value)
{
    record *newrec = NULL;
    while (*r && strcmp(value, (*r)->value) > 0)
        r = &((*r)->next);

    newrec = malloc(sizeof(record));
    if (!newrec)
        return false;
    newrec->value = strdup(value);
    if (!(newrec->value))
        return false;
    
    if (*r)
        newrec->next = *r;
    else
        newrec->next = NULL;
    
    *r = newrec;

    return true;
}

bool delete_element(record **r, char *value)
{
    while (*r && strcmp(value, (*r)->value) > 0)
        r = &((*r)->next);
    
    if (*r && strcmp(value, (*r)->value) == 0)
    {
        *r = (*r)->next;
        return true;
    }

    return false;
}

record* find(record **r, char *value)
{
    record *tar = malloc(sizeof(record));
    tar = NULL;
    while (*r && strcmp(value, (*r)->value) > 0)
        r = &((*r)->next);
    
    if (*r && strcmp(value, (*r)->value) == 0)
        tar = *r;
    
    return tar;
}

void free_list(record **r)
{
    record *cur = *r;
    while (cur)
    {
        record *temp = cur->next;
        free(cur->value);
        free(cur);
        cur = temp;
    }
    *r = NULL;
}

void traverse(record **head)
{
    record *cur = *head;
    while (cur)
    {
        printf("%s->", cur->value);
        cur = cur->next;
    }
    printf("NULL\n");
}
