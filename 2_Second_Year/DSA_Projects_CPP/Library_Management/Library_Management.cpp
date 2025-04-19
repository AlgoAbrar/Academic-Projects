#include <bits/stdc++.h>
using namespace std;

// Student Info:
// Name: Saiyedul Abrar
// ID: 0812320205101022
// Dept. of Computer Science and Engineering,
// Bangladesh Army University of Engineering & Technology,
// Qadirabad Cantonment, Natore, Bangladesh
// Contact: saiyedul.abrar1430@gmail.com, +8801533713957

class Node {
public:
    int bookID;
    string title;
    string author;
    int pubYear;
    int available;
    Node* next;

    Node(int id, string t, string a, int y) {
        bookID = id;
        title = t;
        author = a;
        pubYear = y;
        available = 1;
        next = NULL;
    }
};

void bookins(Node*& head, Node*& tail, int id, string title, string author, int year) {
    Node* newBook = new Node(id, title, author, year);

    if (head == NULL || id < head->bookID) {
        newBook->next = head;
        head = newBook;
        if (tail == NULL) tail = newBook;
        return;
    }

    Node* temp = head;
    while (temp->next != NULL && temp->next->bookID < id) {
        temp = temp->next;
    }

    newBook->next = temp->next;
    temp->next = newBook;
    if (newBook->next == NULL) tail = newBook;
}

vector<Node*> convertToVector(Node* head) {
    vector<Node*> result;
    while (head != NULL) {
        result.push_back(head);
        head = head->next;
    }
    return result;
}

void searchBook(Node* head, int id) {
    vector<Node*> books = convertToVector(head);
    int left = 0, right = books.size() - 1;

    while (left <= right) {
        int mid = (left + right) / 2;
        if (books[mid]->bookID == id) {
            cout << "\n✅ Book Found:\n";
            cout << "ID: " << books[mid]->bookID << endl;
            cout << "Title: " << books[mid]->title << endl;
            cout << "Author: " << books[mid]->author << endl;
            cout << "Year: " << books[mid]->pubYear << endl;
            cout << "Availability: " << (books[mid]->available ? "Available" : "Checked Out") << endl;
            return;
        }
        if (books[mid]->bookID < id) left = mid + 1;
        else right = mid - 1;
    }

    cout << "\n❌ Book with ID " << id << " not found.\n";
}

Node* mergeByYear(Node* a, Node* b) {
    if (!a) return b;
    if (!b) return a;

    if (a->pubYear <= b->pubYear) {
        a->next = mergeByYear(a->next, b);
        return a;
    } else {
        b->next = mergeByYear(a, b->next);
        return b;
    }
}

void splitList(Node* source, Node** front, Node** back) {
    Node* slow = source;
    Node* fast = source->next;

    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
    }

    *front = source;
    *back = slow->next;
    slow->next = NULL;
}

void mergeSortByYear(Node** headRef) {
    Node* head = *headRef;
    if (!head || !head->next) return;

    Node *a, *b;
    splitList(head, &a, &b);

    mergeSortByYear(&a);
    mergeSortByYear(&b);

    *headRef = mergeByYear(a, b);
}

void checkAvailability(Node* head, int id) {
    while (head != NULL) {
        if (head->bookID == id) {
            cout << "\nBook ID " << id << " is "
                 << (head->available ? "✅ Available" : "❌ Checked Out") << endl;
            return;
        }
        head = head->next;
    }
    cout << "\nBook not found.\n";
}

void displayBooks(Node* head) {
    cout << "\n📚 Book List:\n";
    while (head != NULL) {
        cout << "ID: " << head->bookID
             << " | Title: \"" << head->title
             << "\" | Author: " << head->author
             << " | Year: " << head->pubYear
             << " | " << (head->available ? "Available" : "Checked Out")
             << endl;
        head = head->next;
    }
}

int main() {
    Node* head = NULL;
    Node* tail = NULL;

    int n;
    cout << "📥 Enter number of books to add: ";
    cin >> n;

    for (int i = 0; i < n; i++) {
        int id, year;
        string title, author;

        cout << "\nEnter details for Book " << i + 1 << ":\n";
        cout << "ID: ";
        cin >> id;
        cin.ignore();
        cout << "Title: ";
        getline(cin, title);
        cout << "Author: ";
        getline(cin, author);
        cout << "Publication Year: ";
        cin >> year;

        bookins(head, tail, id, title, author, year);
    }

    displayBooks(head);

    int searchID;
    cout << "\n🔍 Enter Book ID to search: ";
    cin >> searchID;
    searchBook(head, searchID);
    mergeSortByYear(&head);
    cout << "\n📅 Books Sorted by Publication Year:\n";
    displayBooks(head);

    int availID;
    cout << "\n🔎 Enter Book ID to check availability: ";
    cin >> availID;
    checkAvailability(head, availID);

    return 0;
}
