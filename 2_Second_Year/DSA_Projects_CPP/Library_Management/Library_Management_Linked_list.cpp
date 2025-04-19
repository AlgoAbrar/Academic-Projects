#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int bookID;
    string title;
    string author;
    int pubYear;
    int availability;
    Node *next;

    Node(int id, string t, string a, int y)
    {
        bookID = id;
        title = t;
        author = a;
        pubYear = y;
        availability = 1;
        next = NULL;
    }
};

void bookinss(Node *&head, Node *&tail, int id, string title, string author, int year)
{
    Node *newBook = new Node(id, title, author, year);

    if (!head || id < head->bookID)
    {
        newBook->next = head;
        head = newBook;
        if (!tail)
            tail = newBook;
        return;
    }

    Node *temp = head;
    while (temp->next && temp->next->bookID < id)
    {
        temp = temp->next;
    }
    newBook->next = temp->next;
    temp->next = newBook;
    if (!newBook->next)
        tail = newBook;
}

Node *midget(Node *start, Node *end)
{
    if (!start)
        return NULL;
    Node *slow = start;
    Node *fast = start->next;

    while (fast != end && fast->next != end)
    {
        fast = fast->next->next;
        slow = slow->next;
    }
    return slow;
}

void findingbook(Node *head, int id)
{
    Node *start = head;
    Node *end = NULL;

    while (start != end)
    {
        Node *mid = midget(start, end);

        if (!mid)
            break;

        if (mid->bookID == id)
        {
            cout << "\nFound it!\n";
            cout << "ID: " << mid->bookID << "\n";
            cout << "Title: " << mid->title << "\n";
            cout << "Author: " << mid->author << "\n";
            cout << "Year: " << mid->pubYear << "\n";
            cout << "Status: " << (mid->availability ? "Available" : "Checked") << "\n";
            return;
        }
        else if (mid->bookID < id)
        {
            start = mid->next;
        }
        else
        {
            end = mid;
        }
    }

    cout << "\nNo book with ID " << id << "\n";
}

Node *middlee(Node *head)
{
    if (!head || !head->next)
        return head;
    Node *slow = head, *fast = head->next;
    while (fast && fast->next)
    {
        fast = fast->next->next;
        slow = slow->next;
    }
    return slow;
}

Node *merge(Node *left, Node *right)
{
    if (!left)
        return right;
    if (!right)
        return left;

    Node *result = NULL;
    if (left->pubYear <= right->pubYear)
    {
        result = left;
        result->next = merge(left->next, right);
    }
    else
    {
        result = right;
        result->next = merge(left, right->next);
    }
    return result;
}

Node *mergeSort(Node *head)
{
    if (!head || !head->next)
        return head;

    Node *mid = middlee(head);
    Node *right = mid->next;
    mid->next = NULL;

    Node *leftSorted = mergeSort(head);
    Node *rightSorted = mergeSort(right);

    return merge(leftSorted, rightSorted);
}

void yearsrt(Node *&head, Node *&tail)
{
    head = mergeSort(head);
    tail = head;
    while (tail && tail->next)
        tail = tail->next;
}

void availablee(Node *head, int id)
{
    Node *curr = head;
    while (curr)
    {
        if (curr->bookID == id)
        {
            cout << "\nBook ID " << id << " is "
                 << (curr->availability ? "Available" : "Checked") << "\n";
            return;
        }
        curr = curr->next;
    }
    cout << "\nBook not found.\n";
}

void displayy(Node *head)
{
    cout << "\nFull book list:\n";
    Node *curr = head;
    while (curr)
    {
        cout << "ID: " << curr->bookID << "  Title: \"" << curr->title
             << "\"  Author: " << curr->author << "  Year: " << curr->pubYear
             << "  " << (curr->availability ? "Available" : "Checked Out") << "\n";
        curr = curr->next;
    }
}

int main()
{
    Node *head = NULL;
    Node *tail = NULL;

    int numBooks;
    cout << "Enter the number of books: ";
    cin >> numBooks;

    for (int i = 0; i < numBooks; i++)
    {
        int id, year;
        string title, author;
        cout << "\nBook no. " << i + 1 << " details:\n";
        cout << "ID: ";
        cin >> id;
        cin.ignore();
        cout << "Title: ";
        getline(cin, title);
        cout << "Author: ";
        getline(cin, author);
        cout << "Year: ";
        cin >> year;

        bookinss(head, tail, id, title, author, year);
    }

    displayy(head);

    int searchID;
    cout << "\nBook ID to search: ";
    cin >> searchID;
    findingbook(head, searchID);

    yearsrt(head, tail);
    cout << "\nSorted by publication year:\n";
    displayy(head);

    int availID;
    cout << "\nCheck availability for Book ID: ";
    cin >> availID;
    availablee(head, availID);

    return 0;
    // alhamdulillah
}
