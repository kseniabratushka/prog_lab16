#include <stdio.h>
#include <stdlib.h>

void sort_array(int *arr, int size) 
{
    int *p, *q, temp;
    
    for (p = arr; p < arr + size - 1; p += 1) 
    {
        for (q = arr; q < arr + size - (p - arr) - 1; q += 1) 
        {
            if (*q > *(q + 1)) 
            {
                temp = *q;
                *q = *(q + 1);
                *(q + 1) = temp;
            }
        }
    }
}

int main() 
{
    system("chcp 65001");
    int *array;
    int n, i;

    printf("Введіть кількість елементів масиву: ");
    scanf("%d", &n);
    
    array = (int*)malloc(n * sizeof(int));
    if (array == NULL) 
    {
        printf("Помилка виділення пам'яті!\n");
        return 1;
    }

    printf("Введіть %d цілих чисел:\n", n);
    for (i = 0; i < n; i += 1) 
    {
        scanf("%d", array + i);
    }

    sort_array(array, n);
    
    printf("Відсортований масив:\n");
    for (i = 0; i < n; i += 1) 
    {
        printf("%d ", *(array + i));
    }
    printf("\n");
    
    free(array);
    
    return 0;
}