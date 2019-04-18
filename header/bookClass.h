#ifndef BOOKCLASS_H_INCLUDED
#define BOOKCLASS_H_INCLUDED



#endif // BOOKCLASS_H_INCLUDED


class bookClass
{
public:
    int bookid;
    char title_of_book[100];
    float cost;
    char branch[15];
    int rackno;


public:

        bookClass()                                 // Constructor
    {
        bookid=0;
        strcpy(title_of_book,"No title given");
        cost=0;
        strcpy(branch,"No branch given");
    }

void BookInfo();
void deletingBook(char*);
void searchBook(char*);
void showBookInfo();
int StoredBooks();
void update(char*);
void ViewStoredBooks();




};
