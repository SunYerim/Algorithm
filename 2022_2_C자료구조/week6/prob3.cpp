//testcase 1, 2, 3 각각 통과하였습니다.
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct node {
    char *data;
    int count;
    struct node *next;
}Node;
Node *head = NULL;
Node *head2 = NULL; // 새로운 노드의 head
int n;
int count1 = 1, count2 = 1;
void freeAll();
void freeAll2();

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

    /*1번 결과 출력*/
    Node *tmp = head;
    while(tmp != NULL){
        printf("%s %d\n", tmp->data, tmp->count);
        tmp = tmp->next;
    }
    printf("%d\n", n);
    printf("----------------------\n");
    tmp = NULL;

    /*count 10이하 노드 삭제*/
    tmp = head; 
    while ((tmp->next) != NULL){
        if (((tmp->next)->count)<=10){
            tmp->next = (tmp->next)->next;
        }
        else{
            tmp = tmp->next;
            count1++;
        }
    }

    /*2번 결과 출력*/
    Node *temp = head;
    while(temp != NULL){
        printf("%s %d\n", temp->data, temp->count);
        temp = temp->next;
    }
    printf("%d\n", count1);
    printf("-----------------------------\n");

    /*새로운 정렬된 연결리스트에 기존 노드 삽입 ==> 새 노드 생성 후 2번 해당 노드 삭제*/
    tmp = head; //2번 연결리스트의 head (쭉 순회하기 위함.)
    while (tmp != NULL){
        Node *goodNode = (Node*)malloc(sizeof(Node));
        goodNode -> data = tmp -> data;
        goodNode -> count = tmp -> count;
        goodNode -> next = NULL;
        //복사 후 다음으로 이동
        tmp = tmp->next;

        /*head2가 NULL인 경우 goodNode*/
        if (head2 == NULL){
            head2 = goodNode;
            continue;
        }

        Node *u = head2; //새로운 LinkedList의 head
        Node *t = NULL; //head2의 앞
        while (u != NULL&& u->count >= goodNode -> count){
            t = u;
            u = u->next;
        }
        if (t == NULL){
            goodNode -> next = head2;
            head2 = goodNode;
            count2++;
        }

        else {
            goodNode -> next = u;
            t->next = goodNode;
            
            count2++;
        }   
    
    }

    /*3번 결과 출력*/
    temp = head2;
    while(temp != NULL){
        printf("%s %d\n", temp->data, temp->count);
        temp = temp->next;
    }
    printf("%d", count2);


    fclose(file);
    freeAll(); //1->2번 LinkedList에 대한 free()
    freeAll2(); //3번 새로 만든 LinkedList에 대한 free()
    return 0;                
}

void freeAll() {
    Node* p = head;
    Node* q = NULL;
    while (p != NULL) {
        q = p;
        p = p->next;

        free(q->data);
        free(q);
    }
}

void freeAll2() {
    Node* p = head2;
    Node* q = NULL;
    while (p != NULL) {
        q = p;
        p = p->next;

        free(q->data);
        free(q);
    }
}