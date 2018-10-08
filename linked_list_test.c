#include <stdio.h>
#include <assert.h>
#include "sorted_linked_list.h"

void test_insert();
void test_delete();
void test_find();
void test_free();

int main()
{
    printf("Start testing.\n");

    test_insert();
    test_delete();
    test_find();
    test_free();

    printf("All tests passed.\n");
}

void test_insert()
{
    printf("Start test_insert().\n");
    bool status;

    sorted_list *l = new_list();
    assert(l != NULL);
    assert(l->head == NULL);
    
    status = insert_sorted(&(l->head), "a");
    assert(status == true);
    assert(l->head != NULL);
    assert(l->head->value != NULL);

    status = insert_sorted(&(l->head), "b");
    assert(status == true);
    assert(l->head->next != NULL);
    assert(l->head->next->value != NULL);

    status = insert_sorted(&(l->head), "c");
    assert(status == true);
    assert(l->head->next->next != NULL);
    assert(l->head->next->next->value != NULL);

    printf("test_insert() passed.\n");
}

void test_delete()
{
    printf("Start test_delete().\n");
    bool status;

    sorted_list *l = new_list();

    status = delete_element(&(l->head), "x");
    assert(status == false);
    
    insert_sorted(&(l->head), "a");
    insert_sorted(&(l->head), "b");
    insert_sorted(&(l->head), "c");

    status = delete_element(&(l->head), "b");
    assert(status == true);

    status = delete_element(&(l->head), "a");
    assert(status == true);

    status = delete_element(&(l->head), "c");
    assert(status == true);

    assert(l->head == NULL);

    printf("test_delete() passed.\n");
}

void test_find()
{
    printf("Start test_find().\n");

    sorted_list *l = new_list();
    insert_sorted(&(l->head), "b");
    insert_sorted(&(l->head), "c");
    insert_sorted(&(l->head), "d");

    record *node = find(&(l->head), "a");
    assert(node == NULL);

    node = find(&(l->head), "e");
    assert(node == NULL);

    node = find(&(l->head), "b");
    assert(node != NULL);
    
    node = find(&(l->head), "c");
    assert(node != NULL);
    
    printf("test_find() passed.\n");
}

void test_free()
{
    printf("Start test_free().\n");

    sorted_list *l = new_list();
    insert_sorted(&(l->head), "a");
    insert_sorted(&(l->head), "b");
    insert_sorted(&(l->head), "c");

    free_list(&(l->head));

    printf("test_free() passed.\n");
}