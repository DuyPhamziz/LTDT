#include <stdio.h>

#define Max 100
#define Max_E 100

typedef struct {
    int A[Max_E][Max_E];
    int n, m;
}Graph;

void init_Graph(Graph *G, int n) {
    G->n = n;
    for(int i=0;i<G->n;i++) {
        for(int j=1;j<=G->n;j++)
            G->A[i][j] = 0;
    }
}

void bat_tay(Graph *G, int x, int y) {
    G->A[x][y] = 1;
    G->A[y][x] = 1;
}

int adjacent(Graph *G, int x, int y) {
    return G->A[x][y] == 1;
}

int dem_bat_tay(Graph *G, int x) {
    int cnt =0;
    for(int i=0;i<G->n;i++) {
        if(G->A[x][i]==1) cnt++;
    }
    return cnt;
}

void printGraph(Graph G) {
    for(int i=1;i<=G.n;i++) {

        for(int j=1;j<=G.n;j++) {
            printf("%d ", G.A[i][j]);
        }
        printf("\n");
    }
}

int main() {
    Graph G;
    int x, y;
    FILE *f = fopen("dothi.txt", "r");
    fscanf(f, "%d%d", &x, &y);
    init_Graph(&G, x);
    int u, v;
    for(int i=1;i<=y;i++) {
        fscanf(f, "%d%d", &u,&v);
        bat_tay(&G, u, v);
    }
    printGraph(G);
    int t; 
    printf("Tim so lan bat tay cua: ");
    scanf("%d", &t);
    printf("So lan bat tay cua %d la %d", t, dem_bat_tay(&G, t));
    fclose(f);
}
