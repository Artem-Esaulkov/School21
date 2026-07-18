#include "list.h"

#include <stdio.h>
#include <string.h>

const char* test_add_door();
const char* test_remove_door();

int main() {
    const char* result_add = test_add_door();
    const char* result_remove = test_remove_door();

    printf("add_door test: %s\n", result_add);
    printf("remove_door test: %s\n", result_remove);

    if (strcmp(result_add, FAIL) == 0 || strcmp(result_remove, FAIL) == 0) {
        return 1;
    }
    return 0;
}

const char* test_add_door() {
    struct door d1 = {4, 0};
    struct door d2 = {5, 1};

    struct node* root = init(d1);
    if (root == NULL) return FAIL;

    struct node* added = add_door(root, d2);

    const char* status = FAIL;
    if (added != NULL && root->next == added && added->door.id == 2) {
        status = SUCCESS;
    }

    destroy(root);
    return status;
}

const char* test_remove_door() {
    struct door d1 = {1, 0};
    struct door d2 = {2, 1};
    struct door d3 = {3, 0};

    struct node* root = init(d1);
    if (root == NULL) return FAIL;

    struct node* elem2 = add_door(root, d2);
    struct node* elem3 = add_door(elem2, d3);

    if (elem2 == NULL || elem3 == NULL) {
        destroy(root);
        return FAIL;
    }

    root = remove_door(elem2, root);

    const char* status = FAIL;
    if (root != NULL && root->next == elem3 && find_door(2, root) == NULL) {
        status = SUCCESS;
    }

    destroy(root);
    return status;
}
