#include <stdio.h>

#define MAX_BOOKS 50

typedef struct {
    int id;
    char title[60];
    int issued;
} Book;

int main(void) {
    Book books[MAX_BOOKS];
    int count = 0, choice, id;
    do {
        printf("\n1. Add Book\n2. Issue Book\n3. Return Book\n4. List Books\n5. Exit\nChoice: ");
        if (scanf("%d", &choice) != 1) break;
        if (choice == 1 && count < MAX_BOOKS) {
            Book b; b.issued = 0;
            printf("Book ID: "); scanf("%d", &b.id);
            printf("Title (no spaces): "); scanf("%59s", b.title);
            books[count++] = b;
            printf("Added.\n");
        } else if (choice == 2 || choice == 3) {
            printf("Book ID: "); scanf("%d", &id);
            for (int i = 0; i < count; i++) {
                if (books[i].id == id) {
                    books[i].issued = (choice == 2) ? 1 : 0;
                    printf("Updated status for %s.\n", books[i].title);
                }
            }
        } else if (choice == 4) {
            for (int i = 0; i < count; i++) {
                printf("ID: %d | Title: %s | %s\n", books[i].id, books[i].title, books[i].issued ? "Issued" : "Available");
            }
        }
    } while (choice != 5);
    return 0;
}
