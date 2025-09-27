#include <stdio.h>
#include <conio.h>
#include <ctype.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

void add();
void list();
void edit();
void delete1();
void search();
void login();

// Structure to hold customer details
struct CustomerDetails {
    char roomnumber[10];
    char name[20];
    char address[25];
    char phonenumber[15];
    char nationality[15];
    char email[20];
    char period[10];
    char arrivaldate[10];
}s;

int main() {
    int i = 0;
    time_t t;
    time(&t);
    char choice;

    system("cls");
    printf("\t\t=============================================\n");
    printf("\t\t|                                           |\n");
    printf("\t\t|       ----------------------------        |\n");
    printf("\t\t|           HOTEL BOOKING SYSTEM            |\n");
    printf("\t\t|       ----------------------------        |\n");
    printf("\t\t|                                           |\n");
    printf("\t\t|                                           |\n");
    printf("\t\t|                                           |\n");
    printf("\t\t=============================================\n\n\n");
    
    for(i = 0; i < 80; i++)
        printf("-");

    printf("\nDate and Time : %s", ctime(&t));

    for(i = 0; i < 80; i++)
        printf("-");

    printf(" \n Press any key to continue:");
    getch();
    
    system("cls");
    login();  // Login Function
    system("cls");

    // Main loop for user options after login
    while (1) {
        system("cls");
        for(i = 0; i < 80; i++) printf("-");
        printf("\n\t\t\t|MAIN MENU|  \n");
        for(i = 0; i < 80; i++) printf("-");
        printf("\n\t\t Select an option:");
        printf("\n\n");
        printf(" \n 1 Book a room");
        printf(" \n 2 View Customer Detail");
        printf(" \n 3 Delete Customer Detail");
        printf(" \n 4 Search Record");
        printf(" \n 5 Update Record");
        printf(" \n 6 Exit");
        printf("\n");

        for(i = 0; i < 80; i++) printf("-");
        printf("\nDate and Time : %s", ctime(&t));
        for(i = 0; i < 80; i++) printf("-");

        choice = getche();
        choice = toupper(choice);

        switch(choice) {
            case '1':
                add(); break;
            case '2':
                list(); break;
            case '3':
                delete1(); break;
            case '4':
                search(); break;
            case '5':
                edit(); break;
            case '6':
                system("cls");
                printf("\n\n\t **THANK YOU**");
                printf("\n\t FOR TRUSTING OUR SERVICE");
                exit(0);
                break;
            default:
                system("cls");
                printf("Incorrect Input");
                printf("\n Press any key to continue");
                getch();
        }
    }
}

// Function to handle string input with backspace support
void input_with_backspace(char *input, int size) {
    int index = 0;
    char ch;

    while (1) {
        ch = getch();
        if (ch == 13) { // Enter key
            input[index] = '\0';
            break;
        } else if (ch == 8) { // Backspace key
            if (index > 0) {
                index--;
                printf("\b \b");
            }
        } else if (index < size - 1) { // Regular character
            input[index++] = ch;
            printf("%c", ch);
        }
    }
}
// Login function to validate user credentials
void login() {
    int a = 0, i = 0;
    char uname[10], c = ' ';
    char pword[10], code[10];
    char user[10] = "admin";
    char pass[10] = "mksf";

    do {
        system("cls");

        printf("\n  =============  LOGIN FORM  =============  ");
        printf(" \n        ENTER USERNAME:-");
        scanf("%s", uname);
        printf(" \n        ENTER PASSWORD:-");

        i = 0;
        while (1) {
            c = getch();  // Read a character
            if (c == 13) {  // Enter key pressed
                break;
            } else if (c == 8) {  // Backspace key pressed
                if (i > 0) {
                    printf("\b \b");  // Move cursor back, overwrite with space, move back again
                    i--;
                }
            } else if (i < 9) {  // Limit input to 9 characters
                pword[i] = c;
                printf("*");  // Print asterisk for each character
                i++;
            }
        }
        pword[i] = '\0';  // Null-terminate the password string

        if (strcmp(uname, user) == 0 && strcmp(pword, pass) == 0) {
            printf("  \n\n\n       WELCOME !!!! LOGIN IS SUCCESSFUL");
            break;
        } else {
            printf("\n        SORRY !!!!  LOGIN IS UNSUCCESSFUL");
            a++;
            getch();
        }
    } while (a <= 2);

    if (a > 2) {
        printf("\nSorry you have entered the wrong username and password three times!!!");
        getch();
        exit(0);
    }
    system("cls");
}


// Add customer details function
void add() {
    FILE *f;
    char test;
    f = fopen("cus.txt", "a+");

    if(f == NULL) {
        f = fopen("cus.txt", "w+");
    }
    system("cls");
    printf("\nEnter Customer Details:");
    printf("\n**********");

    // Room number validation (Only digits)
    while (1) {
        printf("\n Enter Room number:\n");
        scanf("%s", s.roomnumber);
        if (isdigit(s.roomnumber[0])) break;
        else {
            printf("Invalid input. Please enter a numeric room number:\n");
        }
    }

    // Name validation (Only alphabetic characters)
    printf("Enter Name (Only alphabetic characters):\n");
    while(1) {
        int valid = 1;
        scanf("%s", s.name);
        for (int i = 0; i < strlen(s.name); i++) {
            if (!isalpha(s.name[i])) {
                valid = 0;
                break;
            }
        }
        if (valid) break;
        else {
            printf("Invalid name. Only alphabetic characters allowed.\n");
        }
    }

    // Address input (No specific validation)
    printf("Enter Address:\n");
    scanf(" %[^\n]", s.address);

    // Phone number validation (Exactly 10 digits)
    while(1) {
        printf("Enter Phone Number (Exactly 10 digits):\n");
        scanf("%s", s.phonenumber);
        if (strlen(s.phonenumber) == 12 && strspn(s.phonenumber, "012345678923") == 12)break;
        else {
            printf("Invalid phone number. It should be 12 digits.\n");
        }
    }

    // Nationality validation (Only alphabetic characters)
    printf("Enter Nationality (Only alphabetic characters):\n");
    while(1) {
        int valid = 1;
        scanf("%s", s.nationality);
        for (int i = 0; i < strlen(s.nationality); i++) {
            if (!isalpha(s.nationality[i])) {
                valid = 0;
                break;
            }
        }
        if (valid) break;
        else {
            printf("Invalid nationality. Only alphabetic characters allowed.\n");
        }
    }

    // Email validation (simple check for @ and .)
    printf("Enter Email (e.g., example@example.com):\n");
    while(1) {
        scanf("%s", s.email);
        if (strchr(s.email, '@') != NULL && strchr(s.email, '.') != NULL) break;
        else {
            printf("Invalid email format. Please try again.\n");
        }
    }

    // Period validation (Positive integer)
    while(1) {
        printf("Enter Period (Number of days):\n");
        scanf("%s", s.period);
        if (strspn(s.period, "0123456789") == strlen(s.period)) break;
        else {
            printf("Invalid input. Please enter a positive number.\n");
        }
    }

    // Arrival date validation (Format dd/mm/yyyy)
    printf("Enter Arrival date (dd/mm/yyyy):\n");
    scanf("%s", s.arrivaldate);

    fwrite(&s, sizeof(s), 1, f);
    fflush(stdin);
    printf("\n\n1 Room is successfully booked!!");
    printf("\n Press esc key to exit, any other key to add another customer detail:");
    test = getche();
    if(test == 27) {
        fclose(f);
        return;
    }
    fclose(f);
}

// List all customer details function
void list() {
    FILE *f;
    if((f = fopen("cus.txt", "r")) == NULL) {
        printf("File not found!\n");
        return;
    }
    system("cls");
    printf("ROOM    NAME\tADDRESS\tPHONENUMBER\tNATIONALITY\tEMAIL\tPERIOD\tARRIVALDATE\n");

    while(fread(&s, sizeof(s), 1, f) == 1) {
        printf("\n%s \t%s \t%s \t%s \t%s \t%s \t%s \t%s", s.roomnumber, s.name, s.address, s.phonenumber, s.nationality, s.email, s.period, s.arrivaldate);
    }
    fclose(f);
    getch();
}

// Delete customer detail function
void delete1() {
    FILE *f, *t;
    int i = 1;
    char roomnumber[20];
    if((t = fopen("temp.txt", "w")) == NULL || (f = fopen("cus.txt", "r")) == NULL) {
        printf("Error opening files!\n");
        return;
    }

    system("cls");
    printf("Enter the Room Number of the hotel to be deleted from the database: \n");
    fflush(stdin);
    scanf("%s", roomnumber);

    while(fread(&s, sizeof(s), 1, f) == 1) {
        if(strcmp(s.roomnumber, roomnumber) == 0) {
            i = 0;
            continue;  // Skip this record for deletion
        }
        fwrite(&s, sizeof(s), 1, t);
    }
    
    if(i == 1) {
        printf("\n\nRecords of Customer in this Room number not found!!");
    } else {
        printf("\n\nThe Customer is successfully removed....");
    }

    fclose(f);
    fclose(t);
    remove("cus.txt");
    rename("temp.txt", "cus.txt");

    getch();
}

// Search customer detail function
void search() {
    system("cls");
    FILE *f;
    char roomnumber[20];
    int flag = 1;

    if((f = fopen("cus.txt", "r+")) == NULL) {
        printf("File not found!\n");
        return;
    }
    
    fflush(stdin);
    printf("Enter Room number of the customer to search its details: \n");
    scanf("%s", roomnumber);

    while(fread(&s, sizeof(s), 1, f) == 1) {
        if(strcmp(s.roomnumber, roomnumber) == 0) {
            printf("\n\tRecord Found\n ");
            printf("\nRoom Number:\t%s", s.roomnumber);
            printf("\nName:\t%s", s.name);
            printf("\nAddress:\t%s", s.address);
            printf("\nPhone number:\t%s", s.phonenumber);
            printf("\nNationality:\t%s", s.nationality);
            printf("\nEmail:\t%s", s.email);
            printf("\nPeriod:\t%s", s.period);
            printf("\nArrival date:\t%s", s.arrivaldate);
            flag = 0;
            break;
        }
    }

    if(flag == 1) {
        printf("\nSorry no record found\n");
    }
    fclose(f);
    getch();
}

// Edit customer details function
void edit() {
    FILE *f, *t;
    char roomnumber[20];
    int found = 0;

    if((f = fopen("cus.txt", "r")) == NULL || (t = fopen("temp.txt", "w")) == NULL) {
        printf("File not found!\n");
        return;
    }

    system("cls");
    printf("Enter Room number to edit details:\n");
    scanf("%s", roomnumber);

    while(fread(&s, sizeof(s), 1, f) == 1) {
        if(strcmp(s.roomnumber, roomnumber) == 0) {
            found = 1;
            printf("Enter New Details for Room Number %s:\n", s.roomnumber);
            
            // Get new details for the room
            printf("Enter Name:\n");
            scanf("%s", s.name);

            printf("Enter Address:\n");
            scanf(" %[^\n]", s.address);

            printf("Enter Phone Number:\n");
            scanf("%s", s.phonenumber);

            printf("Enter Nationality:\n");
            scanf("%s", s.nationality);

            printf("Enter Email:\n");
            scanf("%s", s.email);

            printf("Enter Period:\n");
            scanf("%s", s.period);

            printf("Enter Arrival date:\n");
            scanf("%s", s.arrivaldate);
        }

        fwrite(&s, sizeof(s), 1, t);
    }

    if(found == 0) {
        printf("\nRoom number not found\n");
    } else {
        printf("\nRecord Updated Successfully!\n");
    }

    fclose(f);
    fclose(t);

    remove("cus.txt");
    rename("temp.txt", "cus.txt");

    getch();
}

