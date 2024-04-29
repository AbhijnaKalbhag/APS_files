#include <stdio.h>
#include <stdlib.h>
struct node
{
    int u;
    int v;
    int w;
};
typedef struct node NODE;
NODE a[14] = {{0, 1, 8}, {1, 2, 16}, {2, 3, 14}, {3, 4, 18}, {4, 5, 20}, {5, 6, 4}, {6, 7, 2}, {7, 8, 14}, {7, 0, 16}, {1, 7, 22}, {2, 8, 4}, {2, 5, 8}, {6, 8, 12}, {3, 5, 28}};
int b[9], size = 14, n = 9;

void selection_sort(NODE a[], int size)
{
    int i, j, min;
    NODE temp;
    for (i = 0; i < size - 1; i++)
    {
        min = i;
        for (j = i + 1; j < size; j++)
        {
            if (a[j].w < a[min].w)
            {
                min = j;
            }
        }
        temp = a[min];
        a[min] = a[i];
        a[i] = temp;
    }
}
int check(int b[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        if (b[i] != b[i + 1])
        {

            return 1;
        }
    }

    return 0;
}
int find(int u, int v, int b[])
{

    if (b[u] == b[v])
    {
        return 0;
    }
    else
    {
        return 1;
    }
}
void union_k(int u, int v, int b[])
{
    int i, temp;
    temp = b[u];
    for (i = 0; i < n; i++)
    {
        if (b[i] == temp)
        {
            b[i] = b[v];
        }
    }
}
int kruskal(NODE a[], int size, int b[], int n)
{
    int sum = 0, i = 0;
    while (i < size)
    {
        if (find(a[i].u, a[i].v, b))
        {
            printf("(%d,%d)\n", a[i].u, a[i].v);
            sum = sum + a[i].w;
            union_k(a[i].u, a[i].v, b);
            printf("b array after union:\n");
            for (int j = 0; j < n; j++) {
                printf("%d ", b[j]);
            }
            printf("\n");
        }
        i++;
    }
    return sum;
}

int main()
{
    for (int i = 0; i < n; i++)
    {
        b[i] = i;
    }
    selection_sort(a, size);
    printf("cost=%d", kruskal(a, size, b, n));
}
