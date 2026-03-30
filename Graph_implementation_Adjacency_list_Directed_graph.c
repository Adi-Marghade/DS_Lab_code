#include <stdio.h>
#include <stdlib.h>

struct node {
    struct node *next;
    int vertex;
};
typedef struct node *GNODE;

GNODE graph[20];


void print(int *N) {
    for(int i = 1; i <= *N; i++) {
        if(graph[i] != NULL) {
            printf("%d=>", i);
            GNODE p = graph[i];
            while(p != NULL) {
                printf("%d", p->vertex);
                if(p->next != NULL)
                    printf("\t");
                p = p->next;
            }
            printf("\t\n");
        }
    }
}


void insertVertex(int *N) {
    if(*N >= 20) {
        printf("Maximum vertices reached.\n");
        return;
    }
    (*N)++;
    int newV = *N;
    graph[newV] = NULL;

    int m, src, dest;
    printf("Enter the number of edges from existing vertices to new vertex: ");
    scanf("%d", &m);
    for(int i = 0; i < m; i++) {
        printf("Enter source vertex : ");
        scanf("%d", &src);
        if(src < 1 || src > *N - 1) {
            printf("Invalid vertex.\n");
            continue;
        }
        GNODE q = (GNODE)malloc(sizeof(struct node));
        q->vertex = newV;
        q->next = NULL;
        if(graph[src] == NULL)
            graph[src] = q;
        else {
            GNODE p = graph[src];
            while(p->next != NULL)
                p = p->next;
            p->next = q;
        }
    }

    printf("Enter the number of edges from new vertex to existing vertices: ");
    scanf("%d", &m);
    for(int i = 0; i < m; i++) {
        printf("Enter destination vertex : ");
        scanf("%d", &dest);
        if(dest < 1 || dest > *N - 1) {
            printf("Invalid vertex.\n");
            continue;
        }
        GNODE q = (GNODE)malloc(sizeof(struct node));
        q->vertex = dest;
        q->next = NULL;
        if(graph[newV] == NULL)
            graph[newV] = q;
        else {
            GNODE p = graph[newV];
            while(p->next != NULL)
                p = p->next;
            p->next = q;
        }
    }

    printf("After inserting vertex the adjacency list is : \n");
    print(N);
}


void insertEdge(int *N) {
    int src, dest;
    printf("Enter the source vertex of the edge : ");
    scanf("%d", &src);
    printf("Enter the destination vertex of the edge : ");
    scanf("%d", &dest); 

    if(src < 1 || src > *N || dest < 1 || dest > *N) {
        printf("Invalid vertex.\n");
        return;
    }

    GNODE q = (GNODE)malloc(sizeof(struct node));
    q->vertex = dest;
    q->next = NULL;

    if(graph[src] == NULL)
        graph[src] = q;
    else {
        GNODE p = graph[src];
        while(p->next != NULL)
            p = p->next;
        p->next = q;
    }

    printf("After inserting edge the adjacency list is : \n");
    print(N);
}


void deleteVertex(int *N) {
    if(*N == 0) {
        printf("Graph is empty.\n");
        return;
    }
    int v;
    printf("Enter the vertex to be deleted : ");
    scanf("%d", &v);
    if(v < 1 || v > *N) {
        printf("Invalid vertex.\n");
        return;
    }

    GNODE p = graph[v];
    while(p != NULL) {
        GNODE temp = p;
        p = p->next;
        free(temp);
    }
    graph[v] = NULL;

    for(int i = 1; i <= *N; i++) {
        if(i == v || graph[i] == NULL) continue;
        GNODE prev = NULL, curr = graph[i];
        while(curr != NULL) {
            if(curr->vertex == v) {
                if(prev == NULL)
                    graph[i] = curr->next;
                else
                    prev->next = curr->next;
                free(curr);
                break;
            } else {
                prev = curr;
                curr = curr->next;
            }
        }
    }

    for(int i = v; i < *N; i++) {
        graph[i] = graph[i + 1];
    }
    graph[*N] = NULL;
    (*N)--;

    printf("After deleting vertex the adjacency list is : \n");
    print(N);
}


void deleteEdge(int *N) {
    int src, dest;
    printf("Enter the source vertex of the edge : ");
    scanf("%d", &src);
    printf("Enter the destination vertex of the edge : ");
    scanf("%d", &dest);

    if(src < 1 || src > *N || dest < 1 || dest > *N) {
        printf("Invalid vertex.\n");
        return;
    }

    GNODE prev = NULL, curr = graph[src];
    while(curr != NULL) {
        if(curr->vertex == dest) {
            if(prev == NULL)
                graph[src] = curr->next;
            else
                prev->next = curr->next;
            free(curr);
            break;
        } else {
            prev = curr;
            curr = curr->next;
        }
    }

    printf("After deleting edge the adjacency list is : \n");
    print(N);
}
