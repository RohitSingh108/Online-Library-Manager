#include <iostream>
#include <fstream>
#include<string.h>
#include<stdlib.h>
#include<conio.h>
#include <stdio.h>
#include<windows.h>


#include "showBookInfo.h"
#include "bookClass.h"


using namespace std;

  void bookClass::showBookInfo() //Get the info about the book from user
    {
        system("color 1F");

        cout<<"\n The book id is: "<<bookid;
        cout<<"\n The book title is: "<<title_of_book;
        cout<<"\n Price of the book is: "<<cost;
        cout<<"\n Department: "<<branch;
        cout<<"\n Rack No.  : "<<rackno;



    }
