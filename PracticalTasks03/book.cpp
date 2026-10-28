#include "book.h"

Book::Book() : Product(), author(""), isbn(""), yearPublished(0), genre(""), pages(0), language("") {}

Book::Book(const string& n, double p, const string& id, const string& d, const string& a, const string& i, int year, const string& gen, int pg, const string& lang)
    : Product(n,p,id,d), author(a), isbn(i), yearPublished(year), genre(gen), pages(pg), language(lang) {}

void Book::setAuthor(const string& a)
{
    author=a;
}

void Book::setIsbn(const string& i)
{
    isbn=i;
}

void Book::setYearPublished(int y)
{
    yearPublished=y;
}

void Book::setGenre(const string& g)
{
    genre=g;
}

void Book::setPages(int p)
{
    pages=p;
}

void Book::setLanguage(const string& l)
{
    language=l;
}

string Book::getAuthor() const
{
    return author;
}

string Book::getIsbn() const
{
    return isbn;
}

int Book::getYearPublished() const
{
    return yearPublished;
}

string Book::getGenre() const
{
    return genre;
}

int Book::getPages() const
{
    return pages;
}

string Book::getLanguage() const
{
    return language;
}

void Book::display() const
{
    Product::display();
    cout<<"Author: "<<author<<"\nISBN: "<<isbn<<"\nYear Published: "<<yearPublished<<"\nGenre: "<<genre<<"\nPages: "<<pages<<"\nLanguage: "<<language<<endl;
}
