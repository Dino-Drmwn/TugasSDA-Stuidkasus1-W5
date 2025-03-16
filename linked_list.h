#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Struktur node untuk Linked List Mahasiswa
typedef struct Node {
    char nama[50];
    int nilaiUTS;
    struct Node* next;
} Node;

// Deklarasi fungsi ADT
Node* createNode(char* nama, int nilaiUTS);
void insertAscending(Node** head, char* nama, int nilaiUTS);
void printList(Node* head);
void printListDescending(Node* head);
int countElements(Node* head);
void copyAboveThreshold(Node* head, Node** newHead, int threshold);
void removeDuplicates(Node** head);
void deleteList(Node** head);

#endif // LINKED_LIST_H
