//testcase 모두 통과했습니다.
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct node {
    char *data;
    int count;
    struct node *next;
}Node;
Node *head = NULL;
int n;
int count1 = 1;
//strtok로 token한 후 node_insert
//전에 나온 단어면(검사) count++, 새로 나온 단어면 자리 찾아서 insert
//strdup로 주소 저장 (*word자리)

int main(void){
    char buff[50];
    FILE *file = fopen("harry.txt", "r");
    while (fscanf(file, "%s", buff) != EOF) {
        //malloc으로 노드를 새로 만들고, 거기에 단어를 저장하고, count는 1로
        Node *newNode = (Node*)malloc(sizeof(Node));
        newNode -> data = strdup(buff);
        newNode -> count = 1;
        newNode -> next = NULL;

        if(head == NULL)
        {
            head = newNode;
            n++;
            continue;
        }

        //먼저 buff에 읽힌 단어가 이미 head가 가리키는 연결리스트에 있는지 검사한다.
        //p node head로 잡고 null 될 때 까지 순회
        Node *p = head;
        Node *q = NULL;
        bool duplicate = false;
        while (p!=NULL && strcmp(p->data, buff) <= 0) {
            if(strcmp(p->data, buff) == 0)
            {
                p->count++;
                duplicate = true;
                break;
            }

            q = p;
            p = p->next;
        }

        if(duplicate)
            continue;

        //만든 노드를 head가 가리키는 연결리스트에 insert
        //(empty list, 삽입위치 앞쪽, 뒷쪽인가 따라서)
        if(q == NULL){ //head앞쪽 삽입
            newNode -> next = head;
            head = newNode;
            n++;
        }
        else { //사이에 insert
            newNode -> next = p;
            q -> next = newNode;
            n++;
        }
    }

    /*count 10이하 노드 삭제*/
    Node *tmp = head;
    while ((tmp->next) != NULL){
        if (((tmp->next)->count)<=10){
            tmp->next = (tmp->next)->next;
        }
        else{
            tmp = tmp->next;
            count1++;
        }
    }

    /*LinkedList 출력*/
    Node *temp = head;
    while(temp != NULL){
        printf("%s %d\n", temp->data, temp->count);
        temp = temp->next;
    }
    printf("%d", count1);
        
    return 0;                
}