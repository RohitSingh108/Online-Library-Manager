#include <iostream>
#include <fstream>
#include<string.h>
#include<stdlib.h>
#include<conio.h>
#include <stdio.h>
#include<windows.h>


#include "ViewStoredBooks.h"
#include "bookClass.h"
#include "showBookInfo.h"




using namespace std;


void bookClass::ViewStoredBooks()
{
        ifstream fin;
        fin.open("file1Write.dat",ios::in|ios::binary);

        if(!fin)
                {
                    cout<<"\n The file you are looking for is not available";
                }

        else{
                fin.read((char*)this,sizeof(*this));

                while(!fin.eof())
                    {
                        showBookInfo();
                        cout<<"\n";
                        cout<<"\n";
                        fin.read((char*)this,sizeof(*this));

                    }
            }

fin.close();

}
