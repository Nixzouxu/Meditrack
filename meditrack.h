// File header untuk MediTrack

// C library
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

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
