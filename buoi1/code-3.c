#include <stdio.h>
#define max 100 // Số cung tối đa
// Cấu trúc cảu đồ thị G
typedef struct 
{
    int n, m; // Số đỉnh và số cung của đồ thị
    int A[max][max];
}Graph;
// Hàm khởi tạo đò thị
void init_Graph(Graph *G, int n) {
    G->n = n; // Gán số đỉnh cho đồ thị
    G->m = 0; // Gán số cung của đồ thị = 0
    for(int u=1;u<=n;u++)
        for(int v=1;v<=n;v++)
            G->A[u][v] = 0;
}

// Hàm thêm cung cho đồ thị
void add_Edge(Graph *G, int x, int y) {
    G->A[x][y]=1;
    G->A[y][x]=1;
    G->m++;
}

// Kiểm tra đỉnh kề
int adjacent(Graph *G, int x, int y) {
    return G->A[x][y] > 0;
}

// xác định láng giềng
void neighbours(Graph *G, int x) {
    
    for(int i=0;i<=G->n;i++) {
        if(G->A[x][i]!=0) printf("%d", i);
    }
    printf("\n");
}

int degree(Graph *G, int x) {
    int cnt =0;
    for(int i=1;i<=G->n;i++){
        cnt += G->A[x][i];
    } // duyệt từng cung
    return  cnt += G->A[x][x];
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
        add_Edge(&G, u, v);
    }
    for(int i=1;i<=G.n;i++) 
    printf("Bac(%d): %d\n", i, degree(&G, i));
    printf("-------------------------------\n");
    
    for(int j=1;j<=G.n;j++) 
        for(int k=1;k<=G.n;k++) {
            if(adjacent(&G, j, k) == 1)
                printf("%d ke voi %d\n", j, k);
            else 
                printf("%d khong ke voi %d\n", j, k);
        }
        printf("-------------------------------\n");
    for(int i=1;i<=G.n;i++) {
        printf("Hang xom cua %d la: ", i);
        neighbours(&G, i);
        printf("\n");
    }
}
