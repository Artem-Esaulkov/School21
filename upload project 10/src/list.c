#include "list.h"

#include <stdlib.h>

struct node* init(struct door door) {
    struct node* root = (struct node*)malloc(sizeof(struct node));
    if (root != NULL) {
        root->door = door;
        root->next = NULL;
    }
    return root;
}

struct node* add_door(struct node* elem, struct door door) {
    if (elem == NULL) return NULL;

    struct node* new_node = (struct node*)malloc(sizeof(struct node));
    if (new_node != NULL) {
        new_node->door = door;
        new_node->next = elem->next;
        elem->next = new_node;
    }
    return new_node;
}

struct node* find_door(int door_id, struct node* root) {
    struct node* current = root;
    while (current != NULL) {
        if (current->door.id == door_id) {
            return current;
        }
        current = current->next;
    }
    return NULL;
}

struct node* remove_door(struct node* elem, struct node* root) {
    if (root == NULL || elem == NULL) return root;

    if (root == elem) {
        struct node* new_root = root->next;
        free(root);
        return new_root;
    }

    struct node* current = root;
    while (current != NULL && current->next != elem) {
        current = current->next;
    }

    if (current != NULL && current->next == elem) {
        current->next = elem->next;
        free(elem);
    }

    return root;
}

void destroy(struct node* root) {
    struct node* current = root;
    while (current != NULL) {
        struct node* next = current->next;
        free(current);
        current = next;
    }
}
