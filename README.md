library-management-system-c
C based Library Management System

Library Management System

Description:
A simple C-based console application to manage a library system including adding, issuing, returning, deleting, and searching books.

## Compilation Instructions:
Use the following command to compile:
gcc main.c -o library-management-system

## Running the Program:
Use the following command to run the executable:
./library-management-system

## Sample Input and Output:

1. Add a Book
   Enter book ID: 101
   Enter book title: The C Programming Language
   Enter book author: Dennis Ritchie
   Enter quantity: 5
   Book added successfully!

2. View All Books
   ID: 101, Title: The C Programming Language, Author: Dennis Ritchie, Quantity: 5, Issued: 0

3. Issue a Book
   Enter student roll number: 23001
   Enter book ID to issue: 101
   Enter student name: Alice
   Book issued successfully!

4. Return a Book
   Enter student roll number: 23001
   Book returned successfully!

Note:
- Do not name the executable a.out.
- Use `library-management-system` as the executable name.
