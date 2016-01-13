#ifndef BULK_QUOTE_H
#define BULK_QUOTE_H
#include "disc_quote.h"


class Bulk_quote : public Disc_quote
{
public:
    Bulk_quote() { std::cout << "default constructing Bulk_quote\n"; }
    using Disc_quote::Disc_quote;

    Bulk_quote(const Bulk_quote& bq) : Disc_quote(bq)
    { std::cout << "Bulk_quote : copy constructor\n"; }
    
    Bulk_quote(Bulk_quote&& bq) : Disc_quote(std::move(bq))
    {
        std::cout << "Bulk_quote : move constructor\n";
    }

    Bulk_quote& operator =(const Bulk_quote& rhs)
    {
        Disc_quote::operator =(rhs);
        std::cout << "Bulk_quote : copy=()\n";

        return *this;
    }

    Bulk_quote& operator =(Bulk_quote&& rhs)
    {
        Disc_quote::operator =(std::move(rhs));
        std::cout << "Bulk_quote : move=()\n";
        return *this;
    }

    double net_price(std::size_t n) const override;
    void   debug() const override;

    ~Bulk_quot() override
    {
        std::cout << "destructing Bulk_quote\n";
    }
};

#endif

/********************************************************************/

double Bulk_quote::net_price(std::size_t n) const
{
    return n * price * (n >= quantity ? 1 - discount : 1);
}

void Bulk_quote::debug() const
{
    Quote::debug();
    std::cout << "min_qty= " << quantity << " "
        << "discount= " << discount << " ";
}
