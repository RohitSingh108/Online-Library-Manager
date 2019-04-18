#include <iostream>
#include <fstream>
#include<string.h>
#include<stdlib.h>
#include<conio.h>
#include <stdio.h>
#include<windows.h>


#include "bookClass.h"
#include "deletingBook.h"



using namespace std;

void bookClass::deletingBook(char *t)
{
    ifstream fin;
    ofstream fout;

    fin.open("file1Write.dat", ios::in| ios::binary);
    if(!fin)
        cout<<"File is not available";
    else{
        fout.open("tempfile1.dat",ios::out|ios::binary); //our intention is to write in this file. If this file not available, the file is first made.
        fin.read((char*)this, sizeof(*this)); // data read and kept in the object b1

        while(!fin.eof()){
            if(strcmp(title_of_book,t))// when it doesn't match then only writing in temp file should take place
                fout.write((char*)this, sizeof(*this));
            fin.read((char*)this, sizeof(*this));

                        }

            fin.close();
            fout.close();
            remove("file1Write.dat");
            rename("tempfile1.dat","file1Write.dat");
        }
}
