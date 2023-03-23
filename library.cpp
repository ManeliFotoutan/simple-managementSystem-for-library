#include <iostream>
#include <vector>
#include <string>
using namespace std;

enum BookType
{
    SCIENTIFIC,
    CRIME,
    FANTASY,
    HORROR,
    CLASSICS
};

class Publisher
{
private:
    static int id;
    string name;
    string location;

    Publisher(string name_, string location_)
    {
        name = name_;
        location = location_;
        id = id + 1;
    }
};

class Book
{
private:
    static int id;
    string name;
    BookType type;
    Publisher publisher;
    bool borrowed;

    Book(string name_, Publisher publisher_, BookType type_)
    {
        name = name_;
        publisher = publisher_;
        type = type_;
        id = id + 1;
    }

public:
    string getName()
    {
        return name;
    }
    BookType getType()
    {
        return type;
    }
    void showInfo()
    {
        cout << id << ". " << name;
    }
};

class Member
{
private:
   static string id;
    string name;
    vector<Book> books;

    Member(string id_, string name_)
    {
        id = id_+1;
        name = name_;
    }

public:
    string getMemberId()
    {
        return id;
    }
    string getMemberName()
    {
        return name;
    }
}; 

class Library
{
private:
   static int id;
    string name;
    vector<Book> books;
    int position;

    Library(string name_, int position_)
    {
        name = name_;
        position = position_;
        id = id + 1;
    }

public:
    
    string printBookInfo()
    {
        for(int i=0;i<books.size() ;i++)
        {
         cout<<books[i].getName;
        }
    }

    int getId()
    {
        return id;
    }
    string getNameLibrary()
    {
        return name;
    }
    int getPositionLibrary()
    {
        return position;
    }
    bool isBookExist(string name)
    {
        for (int i = 0; i < books.size(); i++)
        {
            if (name == books[i].getName())
                return true;
        }
        return false;
    }

    vector<Book> getBookByType(BookType type)
    {
        vector<Book> booktype;
        for (int i = 0; i < books.size(); i++)
        {
            if (type == books[i].getType())
            {
                booktype.push_back(books[i]);
            }
        }
        return booktype;
    }
    void addBook(Book book)
    {
        for (int i = 0; i < books.size(); i++)
            if (name_ == books[i].getName())
            {
                throw " A book with this name already exists";
            }
        books.push_back(book);
    }

    vector<Book> getBooks()
    {
        return books;
    }
};

class LibrariesHandler
{
    vector<Library> libraries;
    vector<Member> members;
    
public:
    void createLibrary(string name_, int position_)
    {
        for (int i = 0; i < libraries.size(); i++)
            if (name_ == libraries[i].getNameLibrary())
            {
                throw " A library with this name already exists";
            }
        if (position_ == libraries[i].getPositionLibrary())
        {
            throw "There is now a library in this place";
        }
        else
        {
            libraries.push_back(Library(name_, position_));
        }
    }

    void addBook(int libId_, string name_, Publisher publisher_, BookType type_)
    {
        for (int i = 0; i < libraries.size(); i++)
        {
            if (libId_ == libraries[i].getId())
            {
                libraries[i].addBook(Book(name_, publisher_, type_));
            }
        }
    }

    void addBook(int libId_, Book book_)
    {
        for (int i = 0; i < libraries.size(); i++)
        {
            if (libId_ == libraries[i].getId())
            {
                libraries[i].addBook(book_);
            }
        }
    }

    void addMember(string name, string id)
    {
        for (int i = 0; i < members.size(); i++)
        {
            if (id == members[i].getMemberId())
            {
                throw "A member whit this id already exist";
            }
        }
        members.push_back(Member(id, name))
    }
};

vector<Book> getAllBooks(int libId_)
{
    for (int i = 0; i < libraries.size(); i++)
    {
        if (libId_ == libraries[i].getId())
        {
            return libraries[i].getBooks();
        }
    }
}

string getAllBooksInfo(int libId_){
    for (int i = 0; i < libraries.size(); i++)
    {
        if (libId_ == libraries[i].getId())
        {  
            return libraries[i].printBookInfo(); 
        }
    }
}
 
int main()
{
}