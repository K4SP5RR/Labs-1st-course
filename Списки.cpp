#include "stdio.h"
#include "stdlib.h"
#include "math.h"

struct Node {
	int d;
	Node* ptr;
};

Node* CreatNewNode(int data) {
	Node* NewNode = (Node*)malloc(sizeof(Node));
	NewNode->d = data;
	NewNode->ptr = NULL;
	return NewNode;
}

void Delete(Node* node) {
	Node* node_next;
	while (node != NULL) {
		node_next = node->ptr;;
		free(node);
		node = node_next;
	}
	return;
}

void PrintQueue(Node* node) {
	while (node != NULL) {
		printf_s("%d ", node->d);
		node = node->ptr;
	}
	printf_s("\n");
	return;
}

int main() {
	int n;
	scanf_s("%d", &n);
	Node* First = CreatNewNode(0);
	Node* P1 = First, *P2 = First;
	for (int i = 1; i < n; i++)
	{
		Node* NewN = CreatNewNode(i);
		P2->ptr = NewN;
		P2 = NewN;
	}
	PrintQueue(P1);

	Node* Second = CreatNewNode(n);
	Node* P3 = Second, * P4 = Second;
	for (int i = 1; i < n; i++)
	{
		Node* NewN = CreatNewNode(n+i);
		P4->ptr = NewN;
		P4 = NewN;
	}
	PrintQueue(P3);
	
	Node* current1 = P1;
	Node* current2 = P3;
	while (current1 != NULL && current2 != NULL)
	{
		Node* node_next1 = current1->ptr;
		Node* node_next2 = current2->ptr;
		
		current1->ptr = current2;
		current2->ptr = node_next1;
		
		current1 = node_next1;
		current2 = node_next2;
	}
	PrintQueue(P1);
	Delete(P1);
	
	return 0;
}