#include <stdio.h>
#include <stdlib.h>

struct NODE {
    struct NODE *next;
    int data;
};

void addFirst(struct NODE *target, int data) {
    struct NODE *newNode = malloc(sizeof(struct NODE));
    newNode -> next = target -> next;
    newNode -> data = data;

    target -> next = newNode;
}

// 단일 연결 리스트는 특정 노드를 찾으려면 첫번째 노드부터 마지막 노드까지 차례대로 검색해야 한다.
struct NODE *findNode(struct NODE *node, int data) {
    if (node == NULL)
        return NULL;
    
    struct NODE *curr = node -> next;
    while (curr != NULL) {
        // 현재 노드의 데이터와 매개변수로 받은 데이터를 비교하여 같으면 현재 노드를 반환
        if (curr -> data == data)
            return curr;

        // 다르면 다음 노드로 넘어간다.
        curr = curr -> next;
    }

    // 값을 찾지 못했거나 처음부터 node가 NULL이라면 NULL을 반환
    return NULL;
}

int main() {
    struct NODE *head = malloc(sizeof(struct NODE));
    head -> next = NULL;

    addFirst(head, 10);
    addFirst(head, 20);
    addFirst(head, 30);

    struct NODE *found = findNode(head, 20);
    printf("%d \n", found -> data);

    struct NODE *curr = head -> next;
    while (curr != NULL) {
        struct NODE *next = curr -> next;
        free(curr);
        curr = next;
    }

    free(head);

    return 0;
}