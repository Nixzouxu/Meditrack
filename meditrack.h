// File header untuk MediTrack

// C library
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#ifdef _WIN32
#include <windows.h> // Untuk Sleep di Windows
#else
#include <unistd.h> // Untuk usleep di Linux/Mac
#endif

// Struct untuk menyimpan data Obat
typedef struct {
    char name[50];     // nama obat
    int stock;         // jumlah stok
    char expiry[11];   // Tanggal Kadaluwarsa (format: YYYY-MM-DD)
} Medicine;

// Node untuk Linked List penyimpanan Obat
typedef struct MedicineNode {
    Medicine med;               // Data Obat
    struct MedicineNode* Next;  // Pointer ke node berikutnya
} MedicineNode;

// Node untuk Min Heap berdasarkan tanggal kadaluwarsa
typedef struct {
    char expiry[11];   // Tanggal Kadaluwarsa
    char name[50];     // nama obat
} HeapNode;

typedef struct{
    HeapNode* nodes;   // Array untuk menyimpan node heap
    int size;          // jumlah elemen saat ini
    int capacity;      // kapasitas maksimum dari heap
} MinHeap;

// Node untuk Queue permintaan obat
typedef struct RequestObat {
    char medName[50];           // nama obat yang diminta
    int quantity;               // jumlah elemen saat ini
    struct RequestObat* next;   // pointer ke node berikutnya
} RequestObat;

typedef struct{
    RequestObat* front;   // Depan antrian
    RequestObat* rear;    // Belakang antrian
} Queue;

// Deklarasi fungsi
void displayHeader();
void showLoading();
void clearScreen();
void addMedicine(MedicineNode** head, Medicine med, MinHeap* heap);
void showMedicines(MedicineNode* head);
void updateStock(MedicineNode* head, char* name, int quantity);
MinHeap* createHeap(int capacity);
void addToHeap(MinHeap* heap, char* expiry, char* name);
HeapNode getNearestExpiry(MinHeap* heap);
Queue* createQueue();
void addRequest(Queue* queue, char* medName, int quantity);
void processRequest(Queue* queue, MedicineNode* head);
void addMedicine(MedicineNode** head, Medicine med, MinHeap* heap);
void showMedicines(MedicineNode* head);
void updateStock(MedicineNode* head, char* name, int quantity);
MinHeap* createHeap(int capacity);
void addToHeap(MinHeap* heap, char* expiry, char* name);
HeapNode getNearestExpiry(MinHeap* heap);
Queue* createQueue();
void addRequest(Queue* queue, char* medName, int quantity);
void processRequest(Queue* queue, MedicineNode* head);
