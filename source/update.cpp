#include <iostream>
#include <fstream>
#include<string.h>
#include<stdlib.h>
#include<conio.h>
#include <stdio.h>
#include<windows.h>


#include "bookClass.h"
#include "BookInfo.h"
#include "update.h"


using namespace std;

void bookClass::update(char *t)
{
    fstream file; // Object of fstream class made which has both capability to read and write. So with the same object we can read and write.
    file.open("file1Write.dat",ios::in|ios::out|ios::ate|ios::binary); // read, write and update
    // in update mode, the pointer points to the last byte/ last record
    file.seekg(0); // 28 bytes makes 1 record. If seekg(28) given, it means 28 byte from the beginning.
    // seekg(0) is the first byte of the first record.

    file.read((char*)this, sizeof(*this));
    while(!file.eof()){

            if(!strcmp(t,title_of_book)){
                cout<<"\nEnter the updated values for a book ->\n";
                BookInfo();
                file.seekp(file.tellp()-sizeof(*this)); // seekp() is a function which changes pointer value. tellp() tells the current position of the pointer.
                file.write((char*)this, sizeof(*this));
                                        }
    file.read((char*)this, sizeof(*this));
                        }
        file.close();
}

