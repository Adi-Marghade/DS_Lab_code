struct node {
    int data;
    struct node* next;
};

typedef struct node* NODE;

NODE createNode(int x) {
      NODE newNode = (NODE)malloc(sizeof(struct node));
    if (newNode == NULL) {
        printf("Memory allocation failed\n");
        exit(1);
    }
    newNode->data = x;
    newNode->next = NULL;
    return newNode;
    
    
    
    
}

NODE addNode(NODE first, int x) {
    //write your code here..
    
      NODE newNode = createNode(x);

    // If list is empty
    if (first == NULL) {
        return newNode;
    }

    // Traverse to last node
    NODE temp = first;
    while (temp->next != NULL) {
        temp = temp->next;
    }

    // Link new node at end
    temp->next = newNode;

    return first;
    
}

NODE concatenate(NODE t1, NODE t2) {
    //write your code here..
    
    
if (t1 == NULL)
        return t2;
    
    NODE temp = t1;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    
    temp->next = t2;
    return t1;
    
}

void displayList(NODE first) {
    //write your code here..
    
      NODE temp = first;
    
    if (temp == NULL) {
        printf("NULL\n");
        return;
    }
    
    while (temp != NULL) {
        printf("%d --> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
    
    
}
