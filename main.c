#include "linked_list.h"

int main() {
    Node* L1 = NULL;
    Node* L2 = NULL;
    
    // Menambahkan data mahasiswa ke L1
    insertAscending(&L1, "miaw", 80);
    insertAscending(&L1, "rawr", 75);
    insertAscending(&L1, "woof", 85);
    insertAscending(&L1, "citcit", 65);
    insertAscending(&L1, "moo", 90);
    
    printf("List L1 terurut berdasarkan nama:\n");
    printList(L1);
    
    printf("\nList L1 terurut berdasarkan nilai UTS (descending):\n");
    printListDescending(L1);
    
    printf("\nJumlah mahasiswa dalam list: %d\n", countElements(L1));
    
    copyAboveThreshold(L1, &L2, 70);
    printf("\nList L2 setelah menyalin elemen dengan nilai > 70:\n");
    printList(L2);
    
    removeDuplicates(&L2);
    printf("\nList L2 setelah menghapus duplikasi:\n");
    printList(L2);
    
    deleteList(&L1);
    deleteList(&L2);
    
    return 0;
}

