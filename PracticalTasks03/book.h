#ifndef BOOK_H_
#define BOOK_H_
#include "product.h"

class Book : public Product
{
private:
    string author;
    string isbn;
    int yearPublished;
    string genre;
    int pages;
    string language;

public:
    Book();
    Book(const string& n, double p, const string& id, const string& d,
         const string& a, const string& i, int year, const string& gen, int pg, const string& lang);

    void setAuthor(const string& a);
    void setIsbn(const string& i);
    void setYearPublished(int y);
    void setGenre(const string& g);
    void setPages(int p);
    void setLanguage(const string& l);

    string getAuthor() const;
    string getIsbn() const;
    int getYearPublished() const;
    string getGenre() const;
    int getPages() const;
    string getLanguage() const;

    void display() const override;
};

#endif