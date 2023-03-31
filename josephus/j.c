// linked list implementation of the jocephus problem
// input: n = number of prisoners, m = mth person to die

#include <stdlib.h>
#include <stdio.h>


typedef struct node* Node; // you must typedef to the full original. cannot nest

typedef struct node{
    int p;
    Node next;
} node;


int main(int argc, char *argv[])
{
    if (argc != 3) {fprintf(stderr, "Usage %s n m\n", argv[0]); return 1;}

    int n = atoi(argv[1]);
    int m = atoi(argv[2]);

    // create head node
    Node head = malloc(sizeof(head));
    head->p = n;
    head->next = NULL;
    // insert rest of nodes
    for (int i = n - 1; i > 0; i--) {
        Node node = malloc(sizeof(node));
        node->p = i;
        node->next = head;
        head = node;
    }

    // iterate through and set tail->next to head. 
    Node curr = head;
    while (curr->next != NULL) {
        printf("%d -> ", curr->p);
        curr = curr->next;
    }
    Node tail = curr;
    tail->next = head;
    // circular list complete
    
    while (head->next != NULL) {
        // while you have more than one person standing
        Node curr = head;
        // get mth
        for (int i = 0; i + 1 < m; i++) {
            curr = curr->next;
        }
        Node temp = curr->next;
        curr->next = curr->next->next;
        printf("killing %d\n", temp->p);
        free(temp);
    }


}
