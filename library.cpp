#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>
#include <algorithm>

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
    static int libNum;
    int id;
    string name;
    string location;

public:
    Publisher()
    {
    }
    Publisher(string name_, string location_)
    {
        name = name_;
        location = location_;
        id = libNum + 1;
        libNum++;
    }
};
int Publisher::libNum;

class Book
{
private:
    static int libNum;
    int id;
    string name;
    BookType type;
    Publisher publisher;
    bool borrowed;

public:
    Book(string name_, Publisher publisher_, BookType type_)
    {
        name = name_;
        publisher = publisher_;
        type = type_;
        id = libNum + 1;
        libNum++;
    }
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
int Book::libNum;

class Member
{
private:
    string id;
    string name;
    vector<Book> books;

public:
    Member(string id_, string name_)
    {
        id = id_;
        name = name_;
    }
    string getMemberName()
    {
        return name;
    }
    string getId()
    {
        return id;
    }
    void borrowBook(Book book)
    {
        if (books.size() == 5)
            throw "You cannot borrow book! you have already borrowed 5 books";
        else
            books.push_back(book);
    }

    void returnBook(Book book)
    {
        for (auto it = books.begin(); it != books.end(); ++it)
            if ((*it).getName() == book.getName())
            {
                books.erase(it);
                return;
            }
        throw "You did not borrow this book!";
    }
};

class Library
{
private:
    static int libNum;
    int id;
    string name;
    vector<Book> books;
    int position;

public:
    Library()
    {
    }

    Library(string name_, int position_)
    {
        name = name_;
        position = position_;
        id = libNum + 1;
        libNum++;
    }
    string booksInfoString()
    {
        string Info = "";

        for (int i = 0; i < books.size(); i++)
        {
            Info += to_string(i) + ". " + books[i].getName() + "\n";
        }
        return Info;
    }

    int getId()
    {
        return id;
    }
    string getName()
    {
        return name;
    }
    int getPosition()
    {
        return position;
    }
    Book getBookByName(string name)
    {
        for (int i = 0; i < books.size(); i++)
        {
            if (name == books[i].getName())
                return books[i];
        }
        throw "This book dosenot exist";
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

    string bookInfoStringByType(BookType type)
    {
        string bookType = "";
        int j = 1;
        for (int i = 0; i < books.size(); i++)
            if (type == books[i].getType())
            {
                bookType += to_string(j) + ". " + books[i].getName() + "\n";
                j++;
            }
        return bookType;
    }

    void addBook(Book book)
    {
        for (int i = 0; i < books.size(); i++)
        {
            if (book.getName() == books[i].getName())
                throw " A book with this name already exists";
        }
        books.push_back(book);
    }

    vector<Book> getBooks()
    {
        return books;
    }
};
int Library::libNum;

class LibrariesHandler
{
    vector<Library> libraries;
    vector<Member> members;

public:
    LibrariesHandler()
    {
        libraries.push_back(Library("sadaf", 10));
        libraries.push_back(Library("raha", 5));
        libraries.push_back(Library("mona", 1));
        libraries.push_back(Library("deli", 15));
        libraries.push_back(Library("ali", 3));

        members.push_back(Member("10", "Maneli"));
        members.push_back(Member("11", "Narges"));
    }
    void createLibrary(string name_, int position_)
    {
        for (int i = 0; i < libraries.size(); i++)
        {
            if (name_ == libraries[i].getName())
            {
                throw " A library with this name already exists";
            }
            else if (position_ == libraries[i].getPosition())
            {
                throw "There is now a library in this place";
            }
            else
            {
                libraries.push_back(Library(name_, position_));
                return;
            }
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
            if (id == members[i].getId())
            {
                throw "A member whit this id already exist";
            }
        }
        members.push_back(Member(id, name));
    }

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

    string getAllBooksInfo(int libId_)
    {
        for (int i = 0; i < libraries.size(); i++)
            if (libId_ == libraries[i].getId())
                return libraries[i].booksInfoString();
    }

    vector<Book> filterByType(int libId_, BookType type)
    {
        for (int i = 0; i < libraries.size(); i++)
        {
            if (libId_ == libraries[i].getId())
            {
                return libraries[i].getBookByType(type);
            }
        }
    }

    string filterByTypeAndShowInfo(int libId, BookType type)
    {
        {
            for (int i = 0; i < libraries.size(); i++)
            {
                if (libId == libraries[i].getId())
                {
                    return libraries[i].bookInfoStringByType(type);
                }
            }
        }
    }

    bool borrow(string memberId, int libraryId, string name)
    {
        for (int i = 0; i < libraries.size(); i++)
            if (libraryId == libraries[i].getId())
                for (int i = 0; i < members.size(); i++)
                    if (memberId == members[i].getId())
                    {
                        members[i].borrowBook(libraries[i].getBookByName(name));
                        return true;
                    }
    }

    bool returnBook(string memberId, int libraryId, string name)
    {
        for (int i = 0; i < libraries.size(); i++)
            if (libraryId == libraries[i].getId())
                for (int i = 0; i < members.size(); i++)
                    if (memberId == members[i].getId())
                    {
                        members[i].returnBook(libraries[i].getBookByName(name));
                        return true;
                    }
    }

    int size()
    {
        return libraries.size();
    }

    Library findNearestLibraryByPosition(string name, int position)
    {
        int min = 100000;
        vector<Library> bookLibrary;
        Library minDisLib;
        for (int j = 0; j < libraries.size(); j++)
            if (libraries[j].isBookExist(name))
                bookLibrary.push_back(libraries[j]);
        if (bookLibrary.size() == 0)
            throw "-1";

        for (int j = 0; j < bookLibrary.size(); j++)

            if (labs(position - bookLibrary[j].getPosition()) < min)
            {

                min = labs(position - bookLibrary[j].getPosition());
                minDisLib = bookLibrary[j];
            }
        return minDisLib;
    }

    string findLibrariesHaveBook(string name, int position)
    {
        int min = 100000;
        vector<Library> bookLibrary;
        for (int j = 0; j < libraries.size(); j++)
            if (libraries[j].isBookExist(name))
                bookLibrary.push_back(libraries[j]);

        sort(bookLibrary.begin(), bookLibrary.end(), [](Library &lhs, Library &rhs)
             { return lhs.getPosition() < rhs.getPosition(); });

        string bookName = "";
        for (int i = 0; i < bookLibrary.size(); i++)
        {
            bookName += to_string(i + 1) + ". " + bookLibrary[i].getName() + "\n";
        }
        return bookName;
    }
};

int main()
{
    LibrariesHandler handler;
    // string name_, Publisher publisher_, BookType type_
    Publisher publisher("kheili sabz", "Enghelab");
    Book book1("amar", publisher, CLASSICS);
    Book book2("ehtemal", publisher, HORROR);
    Book book3("jabr", publisher, FANTASY);
    try
    {
        handler.addBook(1, book1);
        // handler.addBook(1 , book1); //with err

        handler.addBook(2, "jabr", publisher, FANTASY);
        handler.addBook(2, "ehtemal", publisher, HORROR);

        handler.addMember("fateme", "12");
        // handler.addMember("sara", "10"); //err
        if (handler.borrow("10", 1, "amar"))
            cout << "book borrowed correctly" << endl;

        // handler.createLibrary("deli", 12); //err
        // handler.createLibrary("hale", 5); //err
        handler.createLibrary("rahil", 20);
    }
    catch (const char *error)
    {
        cout << "error: " << error << endl;
    }
    catch (...)
    {
        cout << "error" << endl;
    }
}