#include <stdio.h>

#define MAX_length 20

typedef struct
{
    int u, v; // u = dinh 1, v = dinh 2
} edge;

typedef struct
{
    int n, m;              // n = so dinh, m = so canh
    edge data[MAX_length]; // e = tap hop cac canh

} graph;

typedef struct
{
    int data[MAX_length];
    int size;
} list;

void makeNUll(list *L)
{
    L->size = 0;
}
int elementAt(list *L, int x)
{
    return L->data[x];
}

void pushList(list *L, int x)
{
    L->data[L->size] = x;
    L->size++;
}

void initGraph(graph *G, int n)
{
    G->n = n;
    G->m = 0;
    printf("Do thi G duoc khoi tao voi so dinh n = %d va so canh m = %d\n", G->n, G->m);
}

void addEdge(graph *G, int u, int v)
{
    for (int i = 0; i < G->m; i++)
    {
        if ((G->data[i].u == u && G->data[i].v == v) || (G->data[i].u == v && G->data[i].v == u))
        {
            printf("Canh da co trong do thi!\n");
            return;
        }
    }
    G->data[G->m].u = u;
    G->data[G->m].v = v;
    G->m++;
    printf("Do thi da them vao canh %d %d\n", G->data[G->m - 1].u, G->data[G->m - 1].v);
}

int adjacent(graph *G, int u, int v)
{
    for (int i = 0; i < G->m; i++)
    {
        if ((G->data[i].u == u && G->data[i].v == v) || (G->data[i].u == v && G->data[i].v == u))
        {
            return 1;
        }
    }
    return 0;
}

void degree(graph *G, int x)
{
    int cnt = 0;
    for (int i = 0; i <= G->m; i++)
    {
        if (adjacent(G, x, i))
            cnt++;
    }
    printf("Bac cua canh %d la: %d\n", x, cnt);
}

list neighbor(graph *G, int x)
{
    list listVertex;
    makeNUll(&listVertex);
    for (int i = 1; i <= G->n; i++)
    {
        if (adjacent(G, x, i) == 1)
        {
            pushList(&listVertex, i);
        }
    }
    return listVertex;
}
// Stack

typedef struct
{
    int data[100];
    int size;
} stack;

void make_null_stack(stack *s)
{
    s->size = 0;
}

void push(stack *s, int x)
{
    s->data[s->size] = x;
    s->size++;
}

void pop(stack *s)
{
    s->size--;
}
int top(stack s)
{
    return s.data[s.size - 1];
}
int empty(stack s)
{
    return s.size == 0;
}

// Duyet theo chieu sau

void depth_first_search(graph *G)
{
    printf("\nDuyet theo chieu sau:\n");
    stack L;
    int mark[100];
    make_null_stack(&L);

    for (int i = 1; i <= G->n; i++)
    {
        mark[i] = 0; // biến mark cho biết ai đã được duyệt rồi?
    }

    for (int i = 1; i <= G->n; i++)
    {
        for (int k = 1; k <= G->n; k++)
        {
            printf("%d ", mark[k]);
        }
        printf("\n");
        if (mark[i] == 0)
        {
            push(&L, i);
            while (!empty(L))
            {
                int x = top(L);
                pop(&L);
                if (mark[x] != 0)
                    continue;
                printf("Duyet %d\n", x);
                mark[x] = 1;
                list ls = neighbor(G, x);
                for (int i = 0; i < ls.size; i++)
                {
                    int e = elementAt(&ls, i);
                    push(&L, e);
                }
            }
            for (int k = 1; k <= G->n; k++)
            {
                printf("%d ", mark[k]);
            }
            printf("\n");
        }
    }
}

// Queue
typedef struct
{
    int data[100];
    int front, rear;
} Queue;

void make_null_queue(Queue *q)
{
    q->front = 0;
    q->rear = -1;
}

void pushQ(Queue *q, int x)
{
    q->rear++;
    q->data[q->rear] = x;
}

int topQ(Queue q)
{
    return q.data[q.front];
}
void popQ(Queue *q)
{
    q->front++;
}

int emptyQ(Queue q)
{
    return q.front > q.rear;
}

void breath_firse_search(graph *G)
{
    printf("\nDuyet BFS:\n");
    Queue L;
    int mark[100];
    make_null_queue(&L);

    for (int i = 1; i <= G->n; i++)
        mark[i] = 0;

    for (int j = 1; j <= G->n; j++)
    {
        if (mark[j] == 0)
        {
            pushQ(&L, j);
            printf("Duyet %d\n", j);
            mark[j] = 1;
            while (!emptyQ(L))
            {
                int x = topQ(L);
                popQ(&L);
                list ls = neighbor(G, x);
                for (int i = 0; i < ls.size; i++)
                {
                    int e = elementAt(&ls, i);
                    if (mark[e] == 0)
                    {
                        printf("Duyet %d\n", e);
                        mark[e] = 1;
                        pushQ(&L, e);
                    }
                }
            }
            printf("\n");
        }
    }
}

int main()
{
    freopen("dothi.txt", "r", stdin);
    int n, m, u, v;
    scanf("%d%d", &n, &m);
    graph G;
    initGraph(&G, n);
    for (int i = 1; i <= m; i++)
    {
        scanf("%d%d", &u, &v);
        addEdge(&G, u, v);
    }
    for (int i = 1; i <= n; i++)
    {
        degree(&G, i);
    }

    for (int i = 1; i <= n; i++)
    {
        list l = neighbor(&G, i);
        printf("neighbor(%d): ", i);
        for (int j = 0; j < l.size; j++)
        {
            printf("%d ", elementAt(&l, j));
        }
        printf("\n");
    }
    depth_first_search(&G);
    breath_firse_search(&G);
}
