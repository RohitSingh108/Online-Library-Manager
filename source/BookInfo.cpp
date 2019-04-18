#include <iostream>
#include <fstream>
#include<string.h>
#include<stdlib.h>
#include<conio.h>
#include <stdio.h>
#include<windows.h>

#include "bookClass.h"
#include "BookInfo.h"


using namespace std;


 void bookClass::BookInfo()
    {
        system("color 1F");

        cout<<"Enter bookid             : ";
        cin>>bookid;


        cout<<"Enter title of the book  : ";
        cin.ignore();
        cin.getline(title_of_book,19);


        cout<<"Enter cost of the book   : ";
        cin>>cost;

        cout<<"Enter the department (Mechanical/Computer/Electronics/Electrical/Civil) : ";
        cin>>branch;

        cout<<"Enter Rack No.           : ";
        cin>>rackno;
    }
