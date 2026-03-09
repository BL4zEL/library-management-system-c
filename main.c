
#include <stdio.h>
#include <string.h>  // for string functions like fgets() and strtok()

// Structure to store details of a book
struct Book {
    int id;                // Unique book ID
    char title[100];       // Title of the book
    char author[100];      // Author name
    int quantity;          // Total number of copies
    int issued;            // Number of copies currently issued
};

// Structure to store details of a student who borrowed a book
struct Student {
    int rollNo;            // Student's roll number
    char name[100];        // Student's name
    int borrowedBookId;    // ID of the book borrowed
};

// Arrays to store books and students
struct Book books[100];
struct Student students[100];
int totalBooks = 0;        // Counter for number of books
int totalStudents = 0;     // Counter for number of students

// Function to add a new book
void addBook() {
    printf("Enter book ID: ");
    scanf("%d", &books[totalBooks].id);

    printf("Enter book title: ");
    getchar();  // Consume leftover newline character
    fgets(books[totalBooks].title, 100, stdin);
    strtok(books[totalBooks].title, "\n");  // Remove trailing newline

    printf("Enter book author: ");
    fgets(books[totalBooks].author, 100, stdin);
    strtok(books[totalBooks].author, "\n");

    printf("Enter quantity: ");
    scanf("%d", &books[totalBooks].quantity);

    books[totalBooks].issued = 0;  // Initially no copies are issued
    totalBooks++;                  // Increment total books count

    printf("Book added successfully!\n");
}

// Function to view all available books
void viewBooks() {
    if (totalBooks == 0) {
        printf("No books available.\n");
        return;
    }

    // Display details of each book
    for (int i = 0; i < totalBooks; i++) {
        printf("ID: %d, Title: %s, Author: %s, Quantity: %d, Issued: %d\n", 
            books[i].id, books[i].title, books[i].author, books[i].quantity, books[i].issued);
    }
}

// Function to issue a book to a student
void issueBook() {
    int bookId, rollNo, found = 0;

    printf("Enter student roll number: ");
    scanf("%d", &rollNo);

    printf("Enter book ID to issue: ");
    scanf("%d", &bookId);

    // Search for the book by ID
    for (int i = 0; i < totalBooks; i++) {
        if (books[i].id == bookId) {
            // Check if copies are available
            if (books[i].quantity > books[i].issued) {
                books[i].issued++;  // Issue one copy

                // Store student details
                students[totalStudents].rollNo = rollNo;
                students[totalStudents].borrowedBookId = bookId;

                printf("Enter student name: ");
                getchar();  // Clear newline from input buffer
                fgets(students[totalStudents].name, 100, stdin);
                strtok(students[totalStudents].name, "\n");

                totalStudents++;  // Increase student count

                printf("Book issued successfully!\n");
                found = 1;
            } else {
                printf("No copies left to issue.\n");
            }
            break;
        }
    }

    if (!found) {
        printf("Book not found.\n");
    }
}

// Function to return a borrowed book
void returnBook() {
    int rollNo, found = 0;

    printf("Enter student roll number: ");
    scanf("%d", &rollNo);

    // Find student by roll number
    for (int i = 0; i < totalStudents; i++) {
        if (students[i].rollNo == rollNo) {
            // Match borrowed book ID and update issued count
            for (int j = 0; j < totalBooks; j++) {
                if (books[j].id == students[i].borrowedBookId) {
                    books[j].issued--;  // One copy returned
                    printf("Book returned successfully!\n");
                    found = 1;
                    break;
                }
            }
            break;
        }
    }

    if (!found) {
        printf("No record of borrowing found.\n");
    }
}

// Function to delete a book by ID
void deleteBook() {
    int bookId, found = 0;

    printf("Enter book ID to delete: ");
    scanf("%d", &bookId);

    // Search for the book
    for (int i = 0; i < totalBooks; i++) {
        if (books[i].id == bookId) {
            // Shift all books after the deleted one to fill the gap
            for (int j = i; j < totalBooks - 1; j++) {
                books[j] = books[j + 1];
            }

            totalBooks--;  // Reduce book count
            printf("Book deleted successfully!\n");
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("Book not found.\n");
    }
}

// Function to search for a book by ID
void searchBook() {
    int bookId, found = 0;

    printf("Enter book ID to search: ");
    scanf("%d", &bookId);

    // Search and display book if found
    for (int i = 0; i < totalBooks; i++) {
        if (books[i].id == bookId) {
            printf("Book found! ID: %d, Title: %s, Author: %s, Quantity: %d, Issued: %d\n", 
                books[i].id, books[i].title, books[i].author, books[i].quantity, books[i].issued);
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("Book not found.\n");
    }
}

// Function to display the main menu
void displayMenu() {
    printf("\n1. Add a Book\n2. View All Books\n3. Issue a Book\n4. Return a Book\n5. Delete a Book\n6. Search a Book\n0. Exit\n");
}

// Main function
int main() {
    int choice;

    // Menu-driven program
    do {
        displayMenu();  // Show menu
        printf("Enter your choice: ");
        scanf("%d", &choice);  // Get user choice

        switch (choice) {
            case 1:
                addBook();
                break;
            case 2:
                viewBooks();
                break;
            case 3:
                issueBook();
                break;
            case 4:
                returnBook();
                break;
            case 5:
                deleteBook();
                break;
            case 6:
                searchBook();
                break;
            case 0:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice. Try again.\n");
        }

    } while (choice != 0);  // Repeat until exit

    return 0;
}
