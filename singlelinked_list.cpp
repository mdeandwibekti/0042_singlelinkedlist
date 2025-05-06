#include <iostream>
#include <string.h>
using namespace std;

class Node {
    public:
        int noMhs;
        Node* next;
};

class LinkedList {
    Node* START;
    public:
        LinkedList() {
            START = NULL;
        }

        void addNode()
        {
            int nim;
            cout << "\nMasukkan Nomor Mahasiswa: ";
            cin >> nim;

            Node * newNode = new Node;
            newNode->noMhs = nim;

            if (START == NULL || nim <= START->noMhs) 
            {
                if ((START != NULL) && (nim == START->noMhs)) {
                    cout << "\nDuplikat noMhs tidak diijinkan\n" ;
                    return;
                }
                newNode->next = START;
                START = newNode;
                return;
            }  
            Node *previous = START;
            Node *current = START;

            while ((current != NULL) && (nim >= current->noMhs)) 
            {
                if (nim == current->noMhs)
                {
                    cout << "\nDuplikat noMhs tidak diijinkan\n" ;
                    return;
                }
                previous = current;
                current = current->next;
            } 
            newNode->next = current;
            previous->next = newNode;
        }

        bool listEmpty() 
        {
            return (START == NULL);

        }

        bool search(int nim, Node **previous, Node **current) 
        {
            *previous = START;
            *current = START;

            while ((*current != NULL) && (nim != (*current)->noMhs)) 
            {
                *previous = *current;
                *current = (*current)->next;
            }

            return (*current != NULL);
        }

        bool delNode(int nim) 
        {
            Node *current, *previous;
            if (!search(nim, &previous, &current)) 
                return false;
            
            if (current == START)
                START = START->next;
            else
                previous->next = current->next;

            delete current;
            return true;

        }

        void traverse() 
        {
            if (listEmpty())
            {
                cout << "\nList Kosong\n";
            }
            else
            {
                cout << "\nData didalam list adalah\n:";
                Node *currentNode = START;
                while (currentNode != NULL) 
                {
                    cout << currentNode->noMhs << endl;
                    currentNode = currentNode->next;
                }
                cout << endl;
            }   

        }      
};

int main()
{
    LinkedList mhs;
    int nim;
    char ch;
    while (1)
    {
        cout << endl;
        cout << "Menu";
        cout << endl;
        cout << "1. menambahkan data kedalam list" << endl;
        cout << "2. menghapus data dalam list" << endl;
        cout << "3. menampilkan data didalam list" << endl;
        cout << "4. mencari data dalam list" << endl;
        cout << "5. keluar" << endl;
        cout << endl;
        cout << "masukan pilihan (1-5): ";
        cin >> ch;
        switch (ch) 
        {
            case '1':
            {
                mhs.addNode();
            }
           
        }
    }
    
    
}
