#include<stdio.h>
#include<stdlib.h>

void main() {
	int x, op;
	int N,E,s,d,i,j;
	GNODE p,q;
	printf("Enter the number of vertices : ");
	scanf("%d",&N);
	printf("Enter the number of edges : ");
	scanf("%d",&E);
	for(i=1;i<=E;i++) {
		printf("Enter source : ");
		scanf("%d",&s);
		printf("Enter destination : ");
		scanf("%d",&d);
		q=(GNODE)malloc(sizeof(struct node));
		q->vertex=d;
		q->next=NULL;
		if(graph[s]==NULL)
			graph[s]=q;
		else {
			p=graph[s];
			while(p->next!=NULL)
				p=p->next;
			p->next=q;
		}
	}
	while(1) {
		printf("1.Insert vertex 2.Insert edge 3.Delete vertex 4.Delete edge 5.Print adjacency list 6.Exit\n");
		printf("Enter your option : ");
		scanf("%d", &op);
		switch(op) {
			case 1:	
					insertVertex(&N);
					break;
			case 2:
					insertEdge(&N);
					break;
			case 3: 
					deleteVertex(&N);
					break;
			case 4:
					deleteEdge(&N);
					break;
			case 5:
					print(&N);
					break;
			case 6:
					exit(0);
		}
	}
}

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
