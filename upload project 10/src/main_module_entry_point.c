#include <stdio.h>
#include <stdlib.h>

#include "documentation_module.h"
#include "print_module.h"

int validate(char* data);
char print_char(char ch);

int main() {
    print_log(print_char, Module_load_success_message);
    int* compatibility_results = check_available_documentation_module(validate, Documents_count, Documents);

    if (compatibility_results == NULL) {
        return 1;
    }

    char* docs[] = {Documents};
    for (int i = 0; i < Documents_count; i++) {
        if (compatibility_results[i] == 1) {
            printf("[%-15s : available]", docs[i]);
        } else {
            printf("[%-15s : unavailable]", docs[i]);
        }
        if (i != Documents_count - 1) {
            printf("\n");
        }
    }

    free(compatibility_results);
    return 0;
}
