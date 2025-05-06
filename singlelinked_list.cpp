#include <iostream>
#include <string>
using namespace std;

struct Node {
    int noMhs;
    string name;
    Node* next;
};

Node* START = NULL;
void addNode() {
    int nim;
    string nama;

    cout << "Masukkan NIM: ";
    cin >> nim;
    cin.ignore(); // Membersihkan newline sebelum getline
    cout << "Masukkan Nama: ";
    getline(cin, nama); // Boleh pakai spasi

    Node* nodeBaru = new Node();
    nodeBaru->noMhs = nim;
    nodeBaru->name = nama;
    nodeBaru->next = NULL;

    // Jika list kosong atau node baru lebih kecil dari START
    if (START == NULL || nim < START->noMhs) {
        // Cek apakah nim sama dengan START
        if (START != NULL && nim == START->noMhs) {
            cout << "NIM sudah ada!" << endl;
            delete nodeBaru;
            return;
        }

        nodeBaru->next = START;
        START = nodeBaru;
        cout << "Data berhasil ditambahkan!" << endl;
        return;
    }

    Node* previous = START;
    Node* current = START->next;

    // Cari posisi penyisipan
    while (current != NULL && nim > current->noMhs) {
        previous = current;
        current = current->next;
    }

    // Cek duplikasi NIM
    if ((current != NULL && current->noMhs == nim) || previous->noMhs == nim) {
        cout << "NIM sudah ada!" << endl;
        delete nodeBaru;
        return;
    }

    // Sisipkan node baru
    nodeBaru->next = current;
    previous->next = nodeBaru;
    cout << "Data berhasil ditambahkan!" << endl;
}


bool searchNode(int nim, Node*& previous, Node*& current) {
    previous = NULL;
    current = START;

    while (current != NULL && nim > current->noMhs) {
        previous = current;
        current = current->next;
    }

    if (current != NULL && current->noMhs == nim) {
        return true;
    }
    return false;
}

bool deleteNode(int nim) {
    Node* current;
    Node* previous;

    if (!searchNode(nim, previous, current)) {
        return false;
    }

    if (current == START) {
        START = START->next;
    } else {
        previous->next = current->next;
    }

    delete current;
    return true;
}

bool listEmpty() {
    return START == NULL;
}

void traverse() {
    if (listEmpty()) {
        cout << "List Kosong" << endl;
        return;
    }

    Node* current = START;
    while (current != NULL) {
        cout << "NIM: " << current->noMhs << ", Nama: " << current->name << endl;
        current = current->next;
    }
}

void searchData() {
    if (listEmpty()) {
        cout << "List Kosong" << endl;
        return;
    }

    int nim;
    cout << "Masukkan NIM: ";
    cin >> nim;

    Node* current = START;
    while (current != NULL) {
        if (current->noMhs == nim) {
            cout << "NIM: " << current->noMhs << ", Nama: " << current->name << endl;
            return;
        }
        current = current->next;
    }

    cout << "Data tidak ditemukan" << endl;
}

int main() {
    int pilihan;

    do {
        cout << "\n====== MENU ======\n";
        cout << "1. Tambah Data\n";
        cout << "2. Hapus Data\n";
        cout << "3. Tampilkan Data\n";
        cout << "4. Cari Data\n";
        cout << "5. Keluar\n";
        cout << "Pilihan: ";
        cin >> pilihan;

        switch (pilihan) {
            case 1:
                addNode();
                break;
            case 2: {
                if (listEmpty()) {
                    cout << "List kosong" << endl;
                    break;
                }

                int nim;
                cout << "Masukkan NIM yang akan dihapus: ";
                cin >> nim;

                if (deleteNode(nim)) {
                    cout << "NIM " << nim << " berhasil dihapus" << endl;
                } else {
                    cout << "Data tidak ditemukan" << endl;
                }
                break;
            }
            case 3:
                traverse();
                break;
            case 4:
                searchData();
                break;
            case 5:
                cout << "Keluar dari program." << endl;
                break;
            default:
                cout << "Pilihan tidak valid!" << endl;
        }

    } while (pilihan != 5);

    return 0;
}
