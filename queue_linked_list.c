#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Queue {
    struct Node* front;
    struct Node* rear;
};

struct Queue* createQueue() {
    struct Queue* q = (struct Queue*)malloc(sizeof(struct Queue));
    q->front = q->rear = NULL;
    return q;
}

void enqueue(struct Queue* q) {
    int item;
    char ch;

    do {
        printf("Enter the data to enqueue: ");
        scanf("%d", &item);

        struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
        newNode->data = item;
        newNode->next = NULL;

        if (q->rear == NULL) {
            q->front = q->rear = newNode; // Queue was empty
        } else {
            q->rear->next = newNode; // Link new node at the end
            q->rear = newNode; // Update rear
        }

        printf("Inserted %d into the queue.\n", item);
        printf("Press y to continue:");
        getchar();
        scanf(" %c", &ch); // Space before %c to ignore newline
    } while (ch == 'y' || ch == 'Y');
}

void dequeue(struct Queue* q) {
    if (q->front == NULL) {
        printf("Queue underflow\n");
        return;
    }

    struct Node* temp = q->front;
    printf("Removed %d from the queue.\n", temp->data);
    q->front = q->front->next;

    if (q->front == NULL) {
        q->rear = NULL; // Queue is empty now
    }

    free(temp);
}

void display(struct Queue* q) {
    if (q->front == NULL) {
        printf("Queue is empty.\n");
        return;
    }

    struct Node* temp = q->front;
    printf("Queue elements: ");
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    struct Queue* q = createQueue();
    int choice;

    do {
        
        printf("\nQueue Operations Menu:\n");
        printf("1. Add (Enqueue)\n");
        printf("2. Delete (Dequeue)\n");
        printf("3. Print (Display)\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                enqueue(q);
                break;
            case 2:
                dequeue(q);
                break;
            case 3:
                display(q);
                break;
            case 4:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    } while (choice != 4);

    
    return 0;
}
