#include <stdio.h>

#define Max 100
#define Max_E 100
// Duyệt đồ thị theo dạng đỉnh
typedef struct {
    int A[Max_E][Max_E];
    int n, m;
}Graph;
// Tạo số đồ đỉnh đỉnh
void init_Graph(Graph *G, int n) {
    G->n = n;
    for(int i=1;i<=G->n;i++) {
        for(int j=1;j<=G->n;j++)
            G->A[i][j] = 0;
    }
}

// // Khởi tạo đồ thị đỉnh cung
// void init_Graph_1(Graph *G, int n, int m) {
//     for(int i=1;i<=G->n;i++) {
//         for(int j=1;j<=G->m;j++) 
//             G->A[i][j] = 0;
//     }
// }

// Theo cung vào đồ thị đỉnh = đỉnh
void add_edge(Graph *G, int x, int y) {
    G->A[x][y] = 1;
    G->A[y][x] = 1;
}

// // Thêm cung vào đồ thị đỉnh cung
// void add_Edge_1(Graph *G, int x, int y, int e) {
//     G->A[x][e] = 1;
//     G->m++;
// }

// Kiểm tra có phải láng giềng
int adjacent(Graph *G, int x, int y) {
    return G->A[x][y] == 1;
}
// Tính Số bậc của một đỉnh
int degree(Graph *G, int x) {
    int cnt =0;
    for(int i=1;i<=G->n;i++) {
        if(G->A[x][i]==1) cnt++;
    }
    return cnt;
}

// In đồ thị đỉnh-đỉnh
void printGraph(Graph G) {
    for(int i=1;i<=G.n;i++) {

        for(int j=1;j<=G.n;j++) {
            printf("%d ", G.A[i][j]);
        }
        printf("\n");
    }
}
// In đồ thị đỉnh-cung
// void printGraph_1(Graph G) {
//     for(int i=1;i<=G.n;i++) {
//         for(int j=1;j<=G.n;j++) 
//             printf("%d ", G.A[i][j]);
//         printf("\n");
//     }
// }
// Xác định hàng xóm
void neighbours(Graph *G, int u) {
    for(int i=1;i<=G->n;i++) {
        if(adjacent(G,u,i) !=0) 
            printf("%d", i);
    }
    printf("\n");
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
        add_edge(&G, u, v);
    }
    printGraph(G);
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