#include <iostream>
#include <fstream>
#include<string.h>
#include<stdlib.h>
#include<conio.h>
#include <stdio.h>
#include<windows.h>


//#include "bookClass.h"

#include "showBookInfo.h"
#include "BookInfo.h"
#include "bookClass.h"
#include "searchBook.h"
#include "deletingBook.h"
#include "update.h"

using namespace std;

void bookClass::searchBook(char *t)
{
    ifstream fin;
    fin.open("file1Write.dat", ios::in|ios::binary);
    if(!fin)
        cout<<"\n File not found";

    else{
        fin.read((char*)this, sizeof(*this));
        while(!fin.eof()){
            if(!strcmp(t,title_of_book))
                    showBookInfo();
            fin.read((char*)this, sizeof(*this));
                        }
        fin.close();

    }
}
