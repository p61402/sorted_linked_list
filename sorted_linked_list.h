#include <stdbool.h>

typedef struct rec {
    char *value;
    struct rec *next;
} record;

typedef struct {
    record *head; 
} sorted_list;

sorted_list* new_list();

bool insert_sorted(record **r, const char *value);

bool delete_element(record **r, char *value);

record* find(record **r, char *value);

void free_list(record **r);

void traverse(record **head);