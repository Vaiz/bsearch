#include <stdio.h>

size_t bsearch(int *array, size_t arraySize, int x, char *isFound);
void autoTest();

int main(void)
{
    autoTest();
    return 0;
}

size_t bsearch(int *array, size_t arraySize, int x, char *isFound)
{
    size_t first = 0;
    size_t last = arraySize;

    if(array[arraySize - 1] <= x)
    {
        if(0 != isFound)
            *isFound = 0;
        return -1;
    }

    if(0 != isFound)
        *isFound = 1;

    while (array[first] <= x)
    {
        size_t mid = first + (last - first) / 2;
        if (array[mid] > x)
            last = mid;
        else
            first = mid + 1;
    }

    return first;
}

void autoTest()
{
    int array[] = {1,1,1, 2,2,2, 4,4,5, 5,5,5, 6,6,6, 8,8,10, 11,11,11,11,11};
    int arraySize = sizeof(array) / sizeof(int);
    char isFound = 0;

    for(int i = 0; i < array[arraySize - 1] + 3; ++i)
    {
        size_t index = bsearch(array, arraySize, i, &isFound);
        if(1 == isFound)
        {
            if(0 == index)
            {
                if(array[index] <= i)
                    printf("Wrong result! ");

                printf("X = %d, array[0] = %d, index = 0\r\n", i, array[0]);
            }
            else
            {
                if(!(array[index - 1] <= i && array[index] > i))
                    printf("Wrong result! ");

                printf("X = %d, "
                       "array[%zu] = %d, "
                       "array[%zu] = %d, "
                       "index = %zu\r\n",
                       i,
                       index - 1, array[index - 1],
                       index, array[index],
                       index);
            }
        }
        else
            printf("X = %d, Index not found\r\n", i);
    }
}
