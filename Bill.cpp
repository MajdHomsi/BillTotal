//==============================================
// Name:          Majd Homsi
// Date:          2021-02-03
// Student Number: 113692206
// Email:          mhomsi1@myseneca.ca
// Section:        NAA
//I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
//==============================================
#include <iostream>
#include <iomanip>
#include "cstring.h"
#include "Bill.h"
using namespace std;
namespace sdds {

    double Bill::totalTax() const
    {
        double sumTaxes = 0.0;
        for (int i = 0; i < m_noOfItems; i++) // for loop to add the items taxes needed in the program...
        {
            sumTaxes += m_items[i].tax();
        }
         
        return sumTaxes; //sum
    }

    double Bill::totalPrice() const
    {
       
        double sumPrices = 0.0;
        for (int i = 0; i < m_noOfItems; i++) // adding the prices of the items needed in the program 
        {
            sumPrices += m_items[i].price();
        }

        return sumPrices; //sum
    }

    void Bill::Title() const // the bill outputs for the display
    {
        cout << "+--------------------------------------+" << endl;
        if (isValid())
        {
            cout << "| ";
            cout.width(36);
            cout << left << m_title;
            cout << " |" << endl;
        }
        else
        {
            cout << "| Invalid Bill                         |" << endl;
        }
        cout << "+----------------------+---------+-----+" << endl;
        cout << "| Item Name            | Price   + Tax |" << endl;
        cout << "+----------------------+---------+-----+" << endl;
    }

    void Bill::footer() const
    {
        cout << "+----------------------+---------+-----+" << endl;
        if (isValid())
        {
            cout << "|                Total Tax: ";
            cout.width(10);
            cout << right << fixed << setprecision(2) << totalTax();
            cout << " |" << endl;

            cout << "|              Total Price: ";
            cout.width(10);
            cout << right << fixed << setprecision(2) << totalPrice();
            cout << " |" << endl;

            cout << "|          Total After Tax: ";
            cout.width(10);
            cout << right << fixed << setprecision(2) << totalTax() + totalPrice();
            cout << " |" << endl;

        }
        else
        {
            cout << "| Invalid Bill                         |" << endl;
        }
        cout << "+--------------------------------------+" << endl;
    }

    void Bill::setEmpty()
    {
        m_items = nullptr;
        strCpy(m_title, "");
    }

    bool Bill::isValid() const
    {
        bool valid = true;
        int i;
        valid = m_items != nullptr && m_title[0] != '\0';
        for (i = 0; valid == true && i < m_noOfItems; i++)
        {
            valid = valid && m_items[i].isValid();
        }

        return valid;
    }

    void Bill::init(const char* title, int noOfItems)
    {
        if (title == nullptr || noOfItems < 1)
        {
            m_title[0] = '\0';
            m_noOfItems = 0;
            m_itemsAdded = 0;
        }
        else
        {
            m_noOfItems = noOfItems;
            m_itemsAdded = 0;
            strnCpy(m_title, title, 36);
            m_items = new Item[m_noOfItems];
            for (int i = 0; i < m_noOfItems; i++)
                m_items[i].setEmpty();
        }

    }

    bool Bill::add(const char* item_name, double price, bool taxed)
    {
        if (m_itemsAdded < m_noOfItems)
        {
            m_items[m_itemsAdded].set(item_name, price, taxed);
            m_itemsAdded++;
            return true;
        }
        return false;
    }

    void Bill::display() const
    {
        Title();
        for (int i = 0; i < m_noOfItems; i++)
        {
            m_items[i].display();
        }
        footer();
    }

    void Bill::deallocate()
    {

        delete[] m_items; //clearing the array for m_items
        m_title[0] = '\0'; // set pointers to NULL
    }

}