#include <stdio.h>
#include <stdlib.h>

#define MAX 47

//Structure
struct Contact {
    char name[MAX];
    char phone[MAX];
    char email[MAX];
};

//Function contact
void addContact() {
    FILE *file = fopen("Contact List.txt", "a");

    if (file == NULL) {
        printf("\nError: 404 mannn!\n\n");
        return;
    }

    struct Contact contact;

    fflush(stdin);

    //Input contact details
    printf("\n--- Add New Contact ---\n");
    printf("Enter Name  : ");
    fgets(contact.name, sizeof(contact.name), stdin);

    printf("Enter Phone : ");
    fgets(contact.phone, sizeof(contact.phone), stdin);

    printf("Enter Email : ");
    fgets(contact.email, sizeof(contact.email), stdin);

    //contact details to file
    fprintf(file, "%s%s%s\n", contact.name, contact.phone, contact.email);
    fclose(file);

    printf("\nContact added successfully!\n\n");
}

//show contacts
void showContacts() {
    FILE *file = fopen("Contact List.txt", "r");

    if (file == NULL) {
        printf("\nError: 404 bruhh\n\n");
        return;
    }

    struct Contact contact;
    printf("\n--- Contact List ---\n");

    //Reading file
    while (fscanf(file, " %[^\n] %[^\n] %[^\n]", contact.name, contact.phone, contact.email) != EOF) {
        printf("Name  : %s |", contact.name);
        printf("Phone : %s |", contact.phone);
        printf("Email : %s |\n\n", contact.email);
    }

    fclose(file);
}

//Contact Management System
int main() {
    int choice;

    do {
        //menu
        //printf("\n=========================\n");
        printf("Contact Management by Abrar\n");
        printf("=========================\n");
        printf("1. Add Contact\n");
        printf("2. Show Contacts\n");
        printf("3. Exit\n");
        //printf("=========================\n");

        printf("\nEnter your choice: ");
        scanf("%d", &choice);
        fflush(stdin); //clear trailing space

        switch (choice) {
            case 1:
                addContact();
                break;
            case 2:
                showContacts();
                break;
            case 3:
                printf("\nAdios, Amigos!\n");
                break;
            default:
                printf("\nAre you sure about the choice? Please try again.\n");
                break;
        }

    } while (choice != 3);

    return 0;
}

