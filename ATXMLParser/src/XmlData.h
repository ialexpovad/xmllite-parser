
#pragma once
#include "common.h"
#include <vector>

struct Desc
{
    tstring sDescription;
    Desc(void) noexcept
        : sDescription()
    { };

};


struct ITEM
{
    int          m_a;

    /// default constructor
    ITEM(void) noexcept
        : m_a()
    { };

    /// Copy constructor
    ITEM(const ITEM& othr)
        : m_a(othr.m_a)
    { };

    ITEM(int ia)
        : m_a(ia)
    { };

    /// Assignment operator
    ITEM& operator=(const ITEM& rhs)
    {
        if (this != &rhs)
        {
            m_a = rhs.m_a;
        }
        return *this;
    };
};

struct DATA
{
    int                         m_intValue;
    tstring                     m_strValue;
    bool                        m_boolValue;

    std::vector<ITEM>           m_rgItemData;


    /// default constructor
    DATA(void) noexcept
        : m_intValue(),
        m_strValue(),
        m_boolValue(),

        m_rgItemData()
    { };

    /// copy constructor
    DATA(const DATA& othr)
        : m_intValue(othr.m_intValue),
        m_strValue(othr.m_strValue),
        m_boolValue(othr.m_boolValue),

        m_rgItemData(othr.m_rgItemData)
    { };

    /// assignment operator
    DATA& operator=(const DATA& rhs)
    {
        if (this != &rhs)
        {
            m_intValue = rhs.m_intValue;
            m_strValue = rhs.m_strValue;
            m_boolValue = rhs.m_boolValue;

            m_rgItemData = rhs.m_rgItemData;
        }
        return *this;
    };
};


struct XML_DATA
{
    std::vector<DATA>    m_rgData;

    /// default constructor
    XML_DATA(void) noexcept
        : m_rgData()
    { };
};
