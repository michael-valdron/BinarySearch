/*
    Title: Binary Search
    Program Author: Michael Valdron
    Date: April 16, 2016
    ** Note: All rights to Binary Search algorithm is in no way bound to the program author. **
    ** This program is for personal perposes only.                                           **
*/

#include "stdio.h"
#include "stdlib.h"


// Binary Search Algorithm Procedure
int binary_search(char *collection[], char *targetItem)
{
    int i_mid;
    int i_low = 0;
    int i_high = sizeof(collection);
    int match_index;

    while (i_low <= i_high) {
        i_mid = i_low + (i_high - i_low) / 2;

        if (collection[i_mid] == targetItem) {
            match_index = i_mid;
        } else if (collection[i_mid] < targetItem) {
            i_low = i_mid + 1;
        } else {
            i_high = i_mid - 1;
        }
    }

    return i_mid;
}

int main(int argc, char *argv[])
{
    char **collection;
    char *target;
    int i = 2;

    if (argc > 0) {
        target = argv[1];

        collection = calloc((argc - i), sizeof(char*));

        while (i < argc) {
            collection[i] = argv[i];
            i++;
        }

        printf("Selected item's index: %d\n", binary_search(collection, target));
    }

    return 0;
}
