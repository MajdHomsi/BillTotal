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
#include "Item.h"
using namespace std;
namespace sdds 
{
    void Item::setName(const char* name)
    {
        strCpy(m_itemName, name);
        m_itemName[20] = '\0'; // Up to 20 chars
    }

    void Item::setEmpty()
    {
        m_itemName[0] = '\0';  // we are setting the first char in the string to NULL
        m_price = 0.0;  // We are setting the price value to a number it can never be technically which is 0.0
        m_taxed = true;
    }

    void Item::set(const char* name, double price, bool taxed)
    {
        if (price < 0.0 || name == nullptr)
        {
            setEmpty();
        }
        else
        {
            strCpy(m_itemName, name);
            m_itemName[20] = '\0';
            m_price = price;
            m_taxed = taxed;
        }
    }

    void Item::display() const
    {
        if (isValid())
        {
            cout << "| ";
            cout.width(20);
            cout << left << setfill('.') << m_itemName;
            cout << " | ";
            cout.width(7);
            cout << left << setfill(' ');
            cout << right << fixed << setprecision(2) << m_price;
            cout << " | ";
            if (m_taxed == true)
            {
                cout << "Yes";
            }
            else
            {
                cout << "No ";
            }

            cout << " |" << endl;
        }

        if (!isValid())
        {
            cout << "| xxxxxxxxxxxxxxxxxxxx | xxxxxxx | xxx |" << endl;
        }
    }

    bool Item::isValid() const
    {
        return m_itemName[0] != '\0';
    }

    double Item::price() const
    {
        return m_price;
    }

    double Item::tax() const
    {
     
        const double c_tax = 0.13;
        if (m_taxed == false)
            return 0.0;
        return c_tax * m_price;
    }

}