// Program utama MediTrack
// Mengimpor definisi dan deklarasi dari file header
#include "meditrack.h"

// Fungsi untuk menampilkan header program
void displayHeader() {
    // Menampilkan judul program dengan border
    printf("\n========================================\n");
    printf("  MediTrack: Inventory & Expiry Analyzer  \n");
    printf("========================================\n");
}

// Fungsi untuk menampilkan efek loading
void showLoading() {
    // Menampilkan animasi loading dengan titik
    printf("Memuat sistem ");
    for (int i = 0; i < 4; i++) {
        printf(".");
        fflush(stdout); // Memastikan teks ditampilkan langsung
        #ifdef _WIN32
            Sleep(500); // Jeda 500ms di Windows
        #else
            usleep(500000); // Jeda 500ms di Linux/Mac
        #endif
    }
    printf("\n");
}

// Fungsi untuk membersihkan layar
void clearScreen() {
    // Memilih perintah berdasarkan sistem operasi
    #ifdef _WIN32
        system("cls");
    #else
        system("clear");
    #endif
}

// --- Fungsi Linked List ---
// Menambahkan obat baru ke Linked List dan Min Heap
void addMedicine(MedicineNode** head, Medicine med, MinHeap* heap) {
    // Membuat node baru untuk Linked List
    MedicineNode* newNode = (MedicineNode*)malloc(sizeof(MedicineNode));
    newNode->med = med;
    newNode->next = *head;
    *head = newNode;
    // Menambahkan ke Min Heap
    addToHeap(heap, med.expiry, med.name);
    printf("\nObat %s berhasil ditambahkan.\n", med.name);
    printf("Tekan Enter untuk kembali...");
    getchar(); // Menangkap Enter
    getchar(); // Menunggu input Enter
}
