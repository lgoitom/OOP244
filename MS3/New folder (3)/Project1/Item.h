#ifndef SDDS_ITEM_H
#define SDDS_ITEM_H
#include "iProduct.h"
#include "Status.h"
namespace sdds
{
    class Item : public iProduct
    {
        char* m_description;
        bool m_flag;
        double m_price;
        int m_quantityOnHand;
        int m_quantityNeeded;
    protected:
        Status m_state;
        int m_skuNum;
    public:
        void linear(bool flag);
        Item();
        int readSku(std::istream& is);
        int qtyNeeded() const;
        int qty() const;
        operator double() const;
        operator bool() const;
        int operator-=(int quantity);
        int operator+=(int quantity);
        bool operator==(int sku) const;
        bool operator==(const char* description) const;
        std::ofstream& save(std::ofstream& os) const;
        std::ifstream& load(std::ifstream& is);
        std::ostream& display(std::ostream& os) const;
        std::istream& read(std::istream& is);
        void clear();
        virtual ~Item();
    };

}
#endif // !SDDS_ITEM_H