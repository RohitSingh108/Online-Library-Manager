#include <iostream>
#include <fstream>
#include<string.h>
#include<stdlib.h>
#include<conio.h>
#include <stdio.h>
#include<windows.h>



#include "showBookInfo.h"
#include "BookInfo.h"
#include "bookClass.h"
#include "searchBook.h"
#include "deletingBook.h"
#include "update.h"


using namespace std;


COORD coord = {0,0};
char password[10]={"teacher"};


// For changing cursor position on the screen
void gotoxy(int x, int y) // Ggotoxy fn. does not exist in Code::Blocks. So, here gotoxy() fn. is userdefined in this case.
            {coord.X = x; coord.Y = y; // X and Y coordinates
            SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
            }

int menu(){ // this function used for Manager option

int choice;

gotoxy(17,8);
cout<<"        BOOKS MANAGER";
gotoxy(17,12);
cout<<"\xB2\xB2 1. Insert Record of Books";
gotoxy(17,14);
cout<<"\xB2\xB2 2. View All records";
gotoxy(17,16);
cout<<"\xB2\xB2 3. Search for Books";
gotoxy(17,18);
cout<<"\xB2\xB2 4. Delete Book Records";
gotoxy(17,20);
cout<<"\xB2\xB2 5. Update Book Records";
gotoxy(17,22);
cout<<"\xB2\xB2 6. Exit";
gotoxy(17,24);
cout<<"\xB2 Enter the option ->  ";
gotoxy(40,24);
cin>>choice;

return(choice);
}



int menustd(){
int choice2;

gotoxy(17,8);
cout<<"        STUDENT'S CORNER";
gotoxy(17,12);
cout<<"\xB2\xB2 1. View All records";
gotoxy(17,14);
cout<<"\xB2\xB2 2. Search for Books";
gotoxy(17,16);
cout<<"\xB2\xB2 3. Exit";
gotoxy(17,20);

cout<<"\xB2 Enter the option ->  ";
gotoxy(40,20);
cin>>choice2;

return(choice2);
}




int main(){
int mainmenustd();
void Password(void);
int ts;

system("color 2E");
    gotoxy(30,2);

    gotoxy(30,3);
    printf(" \t\t\t\t NEW HORIZON COLLEGE OF ENGINEERING ");
    gotoxy(30,6);
    printf(" \t\t\t\t\t COLLEGE LIBRARY\n\n ");
    gotoxy(32,15);
    printf("\t\t\t You want to access College Library as:");

    gotoxy(32,20);
    printf("\t\t\t \xB2\xB2    1) Teacher");

    gotoxy(32,22);
    printf("\t\t\t \xB2\xB2    2) Student");

    gotoxy(32,27);
    printf("\t\t\t Select 1 or 2 \t: ");
    gotoxy(75,27);
    scanf("%d", &ts);
    if(ts==1)
    {
    Password();
    getch();
    }

    else if (ts==2)
    {
       mainmenustd();
    }

    else
        (printf("Wrong Value"));
    return 0;

}


void Password(void) //for password option
{
    int mainmenu();
    system("color 1F");
    system("cls");
    char d[25]="Password Protected";
    char ch,pass[10];
    int i=0,j;

    gotoxy(10,4);
        for (j=0;j<20;j++)
                {
                    Sleep(50);
                    cout<<"*";
                }
        for(j=0;j<20;j++)
                {
                    Sleep(50);
                    printf("%c",d[j]);
                }
        for(j=0;j<20;j++)
                {
                    Sleep(50);
                    cout<<"*";
                }
        gotoxy(10,10);
        gotoxy(15,7);

        cout<<"Enter Password:";
        while(ch!=13)
                {
                    ch=getch();
                        if(ch!=13 && ch!=8)
                            {
                                putch('*');
                                pass[i] = ch;
                                i++;
                            }
                }

        pass[i] = '\0';
                if(strcmp(pass,password)==0)
                        {
                                gotoxy(15,9);
                                cout<<"Password match";
                                gotoxy(17,10);
                                cout<<"Press any key to continue.....";
                                getch();
                                mainmenu();
                        }
                else
                        {
                                    gotoxy(15,16);
                                    cout<<"\aWarning!! Incorrect Password";
                                    getch();
                                    Password();
                        }
}





int mainmenu(){
system("color 1F");
bookClass b1;
char title[20];
char k;
while(1){

    system("cls");
    switch(menu()){

        case 1:
            system("cls");
            b1.BookInfo();
            cout<<"Records inserted....";
            b1.StoredBooks();

                while(1){
                          cout<<"\n\n Do you want to again insert another Book information(y/n)? : ";
                                cin>>k;
                                    if(k=='n')
                                                {
                                                    cout<<"\n Press any key to return to main menu";
                                                    getch();
                                                    mainmenu();
                                                }
                                    else if(k=='y')
                                                {
                                                    system("cls");
                                                    b1.BookInfo();
                                                    cout<<"\n\n\n Records Inserted...\n\n";
                                                    b1.StoredBooks();
                                                }
                                    else
                                                {

                                                    cout<<"\n Wrong value input";
                                                    cout<<"\n\n Press key to return to Main Menu";
                                                    getch();
                                                    mainmenu();
                                                }
                                }

                        break;


        case 2:
            system("cls");
            b1.ViewStoredBooks();
             cout<<"Press any key to return to Main Menu ";
                        getch();
                        mainmenu();
                        break;

        case 3:
            system("cls");
            cout<<"Enter the title for search: ";
            cin.ignore();
            cin.getline(title,19);
            b1.searchBook(title);
            while(1){
                          cout<<"\n\n Do you want to again search for another Book(y/n)? : ";
                                cin>>k;
                                    if(k=='n')
                                                {
                                                    cout<<"\n Press any key to return to main menu";
                                                    getch();
                                                    mainmenu();
                                                }
                                    else if(k=='y')
                                                {
                                                    system("cls");
                                                    cout<<"\nEnter title of book to search: ";
                                                    cin.ignore();
                                                    cin.getline(title,19);
                                                    b1.searchBook(title);
                                                }
                                    else
                                                {

                                                    cout<<"\n Wrong value input";
                                                    cout<<"\n\n Press key to return to Main Menu";
                                                    getch();
                                                    mainmenu();
                                                }
                                }
                        break;


        case 4:
            system("cls");
            cout<<"\nEnter title to delete : ";
            cin.ignore();
            cin.getline(title,19);
            b1.deletingBook(title);

             while(1){
                          cout<<"\n\n Do you want to delete information about a Book(y/n)? : ";
                                cin>>k;
                                    if(k=='n')
                                                {
                                                    cout<<"\n Press any key to return to main menu";
                                                    getch();
                                                    mainmenu();
                                                }
                                    else if(k=='y')
                                                {
                                                    system("cls");
                                                    cout<<"\nEnter title to delete : ";
                                                    cin.ignore();
                                                    cin.getline(title,19);
                                                    b1.deletingBook(title);

                                                }
                                    else
                                                {

                                                    cout<<"\n Wrong value input";
                                                    cout<<"\n\n Press key to return to Main Menu";
                                                    getch();
                                                    mainmenu();
                                                }
                                }
                        break;




        case 5:
            system("cls");
            cout<<"\nEnter title to update : ";
            cin.ignore();
            cin.getline(title,19);
            b1.update(title);
            while(1){
                          cout<<"\n\n Do you want to update information about another Book(y/n)? : ";
                                cin>>k;
                                    if(k=='n')
                                                {
                                                    cout<<"\n Press any key to return to main menu";
                                                    getch();
                                                    mainmenu();
                                                }
                                    else if(k=='y')
                                                {
                                                    system("cls");
                                                    cout<<"\nEnter title to update : ";
                                                    cin.ignore();
                                                    cin.getline(title,19);
                                                    b1.update(title);
                                                }
                                    else
                                                {

                                                    cout<<"\n Wrong value input";
                                                    cout<<"\n\n Press key to return to Main Menu";
                                                    getch();
                                                    mainmenu();
                                                }
                                }

                        break;




        case 6:
            system("cls");
            cout<<"\n Thank u";
                        cout<<"\n Press any key";
                        getch();
                        system("cls");
                        main();


                    default:
                        cout<<"\n\n Invalid choice";

                }

                getch();

            }

}




int mainmenustd(){
system("color 1F");
bookClass b1;
char title[20];
char k;
while(1){

    system("cls");
    switch(menustd()){


        case 1:
            system("cls");
            b1.ViewStoredBooks();
             cout<<"Press any key to return to Main Menu ";
                        getch();
                        mainmenustd();
                        break;

        case 2:
            system("cls");
            cout<<"Enter the title for search: ";
            cin.ignore();
            cin.getline(title,19);
            b1.searchBook(title);
            while(1){
                          cout<<"\n\n Do you want to again search for another Book(y/n)? : ";
                                cin>>k;
                                    if(k=='n')
                                                {
                                                    cout<<"\n Press any key to return to main menu";
                                                    getch();
                                                    mainmenustd();
                                                }
                                    else if(k=='y')
                                                {
                                                    system("cls");
                                                    cout<<"\nEnter title of book to search: ";
                                                    cin.ignore();
                                                    cin.getline(title,19);
                                                    b1.searchBook(title);
                                                }
                                    else
                                                {

                                                    cout<<"\n Wrong value input";
                                                    cout<<"\n\n Press key to return to Main Menu";
                                                    getch();
                                                    mainmenustd();
                                                }
                                }
                        break;




        case 3:
            system("cls");
            cout<<"\n Thank u";
                        cout<<"\n Press any key";
                        getch();
                        system("cls");
                        main();


                    default:
                        cout<<"\n\n Invalid choice";

                }

                getch();

}

}







