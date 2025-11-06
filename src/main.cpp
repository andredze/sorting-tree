#include "tree.h"
#include "treeGraph.h"
#include <stdlib.h>

int IsSorted(int* array, size_t size);

int main()
{
    Tree_t tree2 = {};

    do
    {
        if (TreeCtor(&tree2))
            break;

        if (TreeInsert(&tree2, 25))
            break;

        if (TreeInsert(&tree2, 20))
            break;

        if (TreeInsert(&tree2, 35))
            break;

        if (TreeInsert(&tree2, 40))
            break;

        if (TreeInsert(&tree2, 22))
            break;

        if (TreeInsert(&tree2, 21))
            break;

        if (TreeInsert(&tree2, 15))
            break;

        if (TreeInsert(&tree2, 30))
            break;

    }
    while (0);

    if (TreeDtor(&tree2))
    {
        return EXIT_FAILURE;
    }

    const int NUMS_SIZE          = 10;
    int       numbers[NUMS_SIZE] = {};

    for (int j = 0; j < 10; j++)
    {
        Tree_t tree3 = {};

        if (TreeCtor(&tree3))
        {
            TreeDtor(&tree3);
            return 1;
        }

        for (size_t i = 0; i < NUMS_SIZE; i++)
        {
            numbers[i] = rand();
        }

        for (size_t i = 0; i < NUMS_SIZE; i++)
        {
            if (TreeInsert(&tree3, numbers[i]))
            {
                TreeDtor(&tree3);
                return 1;
            }
        }

        int sorted[NUMS_SIZE] = {};

        TreeGetValue(tree3.dummy->right, sorted, NUMS_SIZE);
        IsSorted(sorted, NUMS_SIZE);

        TreeDtor(&tree3);
    }

    return EXIT_SUCCESS;
}

int IsSorted(int* array, size_t size)
{
    assert(array);

    DPRINTF("[");

    for (size_t i = 0; i < size - 1; i++)
    {
        DPRINTF("%d, ", array[i]);

        if (array[i] > array[i + 1])
        {
            DPRINTF("%d, ", array[i + 1]);
            printf(RED "\nArray is not sorted!\n" RESET_CLR);
            return 1;
        }
    }

    DPRINTF("%d]\n", array[size - 1]);

    printf(GREEN "Array is sorted!\n" RESET_CLR);

    return 0;
}
