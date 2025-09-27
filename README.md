# Hotel-Reservation-system
Hotel Reservation System developed in C language for PF course. This console-based program allows managing hotel bookings with full customer record operations: adding, viewing, editing, deleting, and searching records. Features include secure user authentication, input validation, and file-based storage for organized data management.
1. Introduction
This program is designed to simulate a basic hotel booking system. It provides functionality for managing customer details such as booking rooms, viewing customer information, updating records, and deleting records. The system is developed in C and utilizes file handling for data storage.
2. Features
The system offers the following key features:
Room Booking: Allows users to book rooms by entering various customer details.
View Customer Details: Users can view all customer details stored in the system.
Delete Customer Record: Allows users to delete a customer's record based on the room number.
Search Customer Record: Users can search for a customer's details using the room number.
Edit Customer Record: Users can edit existing customer records, including changing name, address, phone number, nationality, email, period of stay, and arrival date.
User Authentication: A login system ensures that only authorized users can access the system, with a default username and password.
3. System Architecture
The program operates through a series of functions that handle the following:
Login: The login() function prompts the user for a username and password, verifying the credentials before granting access to the system.
Main Menu: After successful login, the program displays a menu where the user can choose different actions such as booking rooms, viewing customer records, or exiting the system.
File Handling: The system uses files (such as cus.txt) to store customer data. The add(), list(), delete1(), edit(), and search() functions manipulate these files.
Input Validation: There is input validation for critical fields, such as room number, phone number, email, and period of stay, ensuring data integrity.
4. Detailed Function Breakdown
Here is a breakdown of the key functions in the program:
add() (Room Booking Function):
This function takes customer information such as room number, name, address, phone number, nationality, email, period, and arrival date.
It validates inputs such as numeric room number, alphabetic name and nationality, correct phone number length, and a valid email format.
The customer details are written to a file cus.txt.
list() (View Customer Details):
This function reads customer records from the file cus.txt and displays them in a tabular format.
It ensures that all customer records are displayed clearly with relevant details.
delete1() (Delete Customer Record):
This function allows the user to delete a customer record by specifying the room number.
It reads all records from cus.txt and writes all but the deleted record to a temporary file. Afterward, the original file is replaced with the updated one.
search() (Search Customer Record):
This function allows the user to search for a customer’s details using the room number.
If the room number is found, the relevant details are displayed. Otherwise, a message indicating that the record was not found is shown.
edit() (Edit Customer Record):
This function allows the user to modify a customer’s details based on the room number.
The system reads all records, finds the matching room number, and prompts the user to enter new details for that record.
The updated record is written to a temporary file, and the original file is replaced with the updated version.
login() (User Authentication):
This function handles user login with a predefined username and password (admin and mksf).
The user is allowed three attempts to enter the correct credentials. If the login is unsuccessful after three attempts, the program exits.
5. Validation and Error Handling
The program includes multiple levels of input validation, such as checking if the room number is numeric, if the name contains only alphabets, and if the phone number is of the correct length.
There are also checks to ensure the email contains "@" and ".", and that the period (number of days) is a positive integer.
Error handling for file operations ensures that if the file cannot be opened, the user is informed.
6. File Operations
The program reads and writes customer records to a file (cus.txt), with each record consisting of customer details.
When editing or deleting records, a temporary file (temp.txt) is used to store modified records. Once the changes are complete, the original file is replaced with the new one.


