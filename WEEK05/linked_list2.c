#include <stdio.h>
#include <stdlib.h>

// 연결 리스트의 노드 구조체 생성
struct NODE {
    // 다음 노드의 주소값을 저장할 포인터
    struct NODE *next;
    // 데이터를 저장할 멤버
    int data;
};

// 기준 노드 뒤에 노드를 추가하는 함수
void addFirst(struct NODE *target, int data) {
    // 새로운 노드 생성
    struct NODE *newNode = malloc(sizeof(struct NODE));
    // 새로운 노드의 다음 노드에 기준 노드의 다음 노드를 지정
    newNode -> next = target -> next;
    // 데이터 저장
    newNode -> data = data;

    // 기준 노드의 다음 노드에 새로운 노드 지정
    target -> next = newNode;
}

int main() {
    // 머리 노드 생성
    // 머리 노드는 데이터를 저장하지 않는다
    struct NODE *head = malloc(sizeof(struct NODE));

    head -> next = NULL;

    // 머리 노드 뒤에 새로운 노드 추가
    addFirst(head, 10);
    // 머리 노드 뒤에 새로운 노드 추가
    addFirst(head, 20);
    // 머리 노드 뒤에 새로운 노드 추가
    addFirst(head, 30);

    // 연결 리스트 순회용 포인터에 첫번째 노드의 주소값 저장
    struct NODE *curr = head -> next;
    // 포인터가 NULL이 아니면 계속 반복
    while (curr != NULL) {
        // 현재 노드의 데이터 출력
        printf("%d \n", curr -> data);
        // 포인터에 다음 노드의 주소값 저장
        curr = curr -> next;
    }

    // 연결 리스트 순회용 포인터에 첫번째 노드의 주소값 저장
    curr = head -> next;
    // 포인터가 NULL이 아니면 계속 반복
    while (curr != NULL) {
        // 현재 노드의 다음 노드 주소값을 임시로 저장
        struct NODE *next = curr -> next;
        // 현재 노드의 메모리 해제
        free(curr);
        // 포인터에 다음 노드의 주소값 저장
        curr = next;
    }
    // 머리 노드의 메모리 해제
    free(head);

    return 0;
}