#include <stdio.h>
#include <stdlib.h>
int top = -1;
int queue[8];
int visited[8] = {0};

int matrix[8][8] = {{0, 0, 0, 0, 0, 0, 0, 0},
                    {0, 0, 1, 1, 1, 0, 0, 0},
                    {0, 1, 0, 0, 1, 0, 0, 0},
                    {0, 1, 0, 0, 1, 1, 0, 0},
                    {0, 1, 1, 1, 0, 1, 0, 0},
                    {0, 0, 0, 1, 1, 0, 1, 1},
                    {0, 0, 0, 0, 0, 1, 0, 0},
                    {0, 0, 0, 0, 0, 1, 0, 0}};
void enqueue(int x)
{
    top++;
    queue[top] = x;
}

int dequeue()
{
    int w = queue[top];
    top--;
    return w;
}

void bfs(int root)
{
    int i, w, j;
    printf("%d,", root);
    enqueue(root);
    visited[1] = root;
    for (i = 1; i <= 7; i++)
    {
        w = dequeue();
        for (j = 1; j <= 7; j++)
        {
            if (visited[j] != 1)
            {
                if (matrix[i][j] == 1)
                {
                }
            }
        }
    }
}
int main()
{
    int root;
    printf("Enter root element = ");
    scanf("%d", &root);
    bfs(root);
}