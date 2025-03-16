#include "linked_list.h"

// Fungsi untuk membuat node baru
Node* createNode(char* nama, int nilaiUTS) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    strcpy(newNode->nama, nama);
    newNode->nilaiUTS = nilaiUTS;
    newNode->next = NULL;
    return newNode;
}

// Fungsi untuk menambahkan node ke dalam list secara ascending berdasarkan nama
void insertAscending(Node** head, char* nama, int nilaiUTS) {
    Node* newNode = createNode(nama, nilaiUTS);
    if (*head == NULL || strcmp((*head)->nama, nama) > 0) {
        newNode->next = *head;
        *head = newNode;
        return;
    }
    
    Node* temp = *head;
    while (temp->next != NULL && strcmp(temp->next->nama, nama) < 0) {
        temp = temp->next;
    }
    newNode->next = temp->next;
    temp->next = newNode;
}

// Fungsi untuk menampilkan list dalam urutan ascending
void printList(Node* head) {
    Node* temp = head;
    while (temp != NULL) {
        printf("Nama: %s, Nilai UTS: %d\n", temp->nama, temp->nilaiUTS);
        temp = temp->next;
    }
}

// Fungsi untuk menampilkan list dalam urutan descending berdasarkan nilai UTS
void printListDescending(Node* head) {
    if (head == NULL) return;
    
    // Menggunakan rekursi untuk mencetak secara descending
    printListDescending(head->next);
    printf("Nama: %s, Nilai UTS: %d\n", head->nama, head->nilaiUTS);
}

// Fungsi untuk menghitung jumlah elemen dalam list
int countElements(Node* head) {
    int count = 0;
    while (head != NULL) {
        count++;
        head = head->next;
    }
    return count;
}

// Fungsi untuk menyalin elemen dengan nilai > threshold ke list baru
void copyAboveThreshold(Node* head, Node** newHead, int threshold) {
    while (head != NULL) {
        if (head->nilaiUTS > threshold) {
            insertAscending(newHead, head->nama, head->nilaiUTS);
        }
        head = head->next;
    }
}

// Fungsi untuk menghapus duplikasi nama pada list
void removeDuplicates(Node** head) {
    Node *current = *head, *prev = NULL, *temp;
    while (current != NULL && current->next != NULL) {
        if (prev != NULL && strcmp(prev->nama, current->nama) == 0) {
            prev->next = current->next;
            free(current);
            current = prev->next;
        } else {
            prev = current;
            current = current->next;
        }
    }
}

// Fungsi untuk menghapus seluruh list
void deleteList(Node** head) {
    Node* temp;
    while (*head != NULL) {
        temp = *head;
        *head = (*head)->next;
        free(temp);
    }
}
