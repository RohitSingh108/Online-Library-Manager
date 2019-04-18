#include <iostream>
#include <fstream>
#include<string.h>
#include<stdlib.h>
#include<conio.h>
#include <stdio.h>
#include<windows.h>


#include "StoredBooks.h"
#include "bookClass.h"



using namespace std;


int bookClass::StoredBooks()
{   if(bookid==0 && cost==0)
        {
            cout<<"Book data not given";
            return(0);
        }

    else{

            ofstream fout;
            fout.open("file1Write.dat", ios::app|ios::binary);
            fout.write((char*)this, sizeof(*this));
            fout.close();
            return(1);
        }
}
