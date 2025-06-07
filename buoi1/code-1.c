#include <stdio.h>

#define max 100 // Số cung tối đa

// Cấu trúc của 1 cung
typedef struct 
{
    int x, y; // Đỉnh đầu và đỉnh cuối của một cung
}Egde;

// Cấu trúc của đồ thị G
typedef struct 
{
    int n, m; // Số đỉnh và số cung của đồ thị
    Egde edges[max];
}Graph;

// Hàm khởi tạo đồ thị
void init_Graph(Graph *G, int n) {
    G->n = n; // Gán số đỉnh cho đồ thị
    G->m = 0; // Gán số cung của đồ thị = 0
}

// Hàm thêm cung cho đồ thị
void add_Edge(Graph *G, int x, int y) {
    G->edges[G->m].x = x; // Gán giá trị đỉnh đầu = x
    G->edges[G->m].y = y; // Gán giá trị đỉnh cuối = y
    G->m++;
}

// Kiểm tra đỉnh kề
int adjacent(Graph *G, int x, int y) {
    for(int i=0;i<G->m;i++) { // Duyệt qua từng cung
        // ĐỈnh đầu = x và đỉnh cuối = y hoặc ngược lại
        if((G->edges[i].x == x && G->edges[i].y ==y) || (G->edges[i].y == x && G->edges[i].x == y)) 
            return 1; // Trả về 1 nếu là 
    }
    return 0; //ngược lại = 0
}

// Xác định bậc của một đỉnh
int degree(Graph *G, int x) {
    int count = 0;
    for(int i=0;i<G->m;i++) { // Duyệt qua từng cung
        if(G->edges[i].x == x) count++; // Nếu x = đầu tăng bậc
        if(G->edges[i].y == x) count++; // Nếu x = cuối tăng bậc
    }
    return count;
}

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
