#include <stdio.h>

#define Max_Vertices 100
#define MAX_length 20

typedef int ElementType;
// Khai báo cấu trúc đồ thị
typedef struct
{

    int A[Max_Vertices][Max_Vertices];
    int n, m;
} Graph;

typedef struct
{
    int data[MAX_length];
    int size;
} List;
void make_null_list(List *L)
{
    L->size = 0;
}
// Thêm phần tử vào cuối danh sách
void push_back(List *L, ElementType x)
{
    L->data[L->size] = x;
    L->size++;
}
// Lấy phần tử tại vị trí i, phần tử bắt đầu ở vị trí 1

ElementType elementAt(List *L, int i)
{
    return L->data[i - 1];
}
// Trả về số phần tử của danh sách

int count_list(List *L)
{
    return L->size;
}

// Phần đồ thị

void init_graph(Graph *G, int n)
{
    G->n = n;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            G->A[i][j] = 0;
}

void addegde(Graph *G, int x, int y)
{
    G->A[x][y] = 1;
}

int adjacent(Graph *G, int x, int y)
{
    return G->A[x][y] != 0;
}
int degree(Graph *G, int x)
{
    int deg = 0;
    for (int i = 1; i <= G->n; i++)
    {
        deg += G->A[x][i];
    }

    return deg;
}

List neighbors(Graph *G, int x)
{
    List list;
    make_null_list(&list);
    for (int i = 1; i <= G->n; i++)
        if (adjacent(G, x, i))
            push_back(&list, i);

    return list;
}

void copy_list(List *s1, List *s2)
{
    int x;
    make_null_list(s1);
    for (int i = 1; i <= s2->size; i++)
    {
        x = elementAt(s2, i);
        push_back(s1, x);
    }
}

List s1, s2;
int k = 0;
ElementType d[Max_Vertices];
ElementType rank[Max_Vertices];
void ranking(Graph *G)
{

    for (int u = 1; u <= G->n; u++)
    {
        d[u] = 0;
    }
    for (int x = 1; x <= G->n; x++)
    {
        for (int u = 1; u <= G->n; u++)
        {
            if (G->A[x][u] != 0)
                d[u]++;
        }
    }
    // List s1, s2
    make_null_list(&s1);
    for (int u = 1; u <= G->n; u++)
    {
        if (d[u] == 0)
            push_back(&s1, u);
    }
    // int k = 1, i

    while (s1.size > 0)
    {
        printf("step %d: ", k);
        for (int i = 1; i <= s1.size; i++)
        {
            printf("%d ", elementAt(&s1, i));
        }
        printf("\n");

        make_null_list(&s2);
        for (int i = 1; i <= s1.size; i++)
        {
            int u = elementAt(&s1, i);
            rank[u] = k;
            for (int v = 1; v <= G->n; v++)
                if (G->A[u][v] != 0)
                {
                    d[v]--;
                    if (d[v] == 0)
                        push_back(&s2, v);
                }
        }
        copy_list(&s1, &s2);
        k++;
    }
}

int main()
{
    freopen("dothixephang.txt", "r", stdin);
    Graph G;
    int n, m, u, v;
    scanf("%d%d", &n, &m);
    init_graph(&G, n);
    for (int e = 0; e < m; e++)
    {
        scanf("%d%d", &u, &v);
        addegde(&G, u, v);
    }
    ranking(&G);
    for (u = 1; u <= n; u++)
    {
        printf("Dinh %d co thu hang rank %d \n",u, rank[u]);
    }
}