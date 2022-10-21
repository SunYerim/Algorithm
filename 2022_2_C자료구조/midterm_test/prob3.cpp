//추후 마저 해결할 예정
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node {
	char* word;
	struct node* next;
}Node;

Node* head = NULL;

int main(void) {
	char buf[30];
	FILE* fp = fopen("data.txt", "r");

	while (fscanf(fp, "%s", buf) != EOF) {
		Node* newNode = (Node*)malloc(sizeof(Node));
		newNode->word = _strdup(buf);
		newNode->next = NULL;

		if (head == NULL) {
			head = newNode;
			continue;
		}

		Node* p = head;
		Node* q = NULL;

		if (q == NULL) {
			newNode->next = head;
			head = newNode;
		}
		else {
			newNode->next = p;
			q->next = newNode;
		}
	}
	Node* tmp = head;
	while (tmp != NULL) {
		printf("%s\n", tmp->word);
		tmp = tmp->next;
	}
	

	return 0;

}