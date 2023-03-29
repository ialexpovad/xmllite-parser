#pragma once

#include "XmlData.h"
#include "XmlParser.h"


class CXmlHandler
    : public XML_DATA,
    public IXmlElementHandler
{
public:
    tstring sDescription;

    /// default constructor
    CXmlHandler(void) noexcept
        : XML_DATA(),
        IXmlElementHandler()
    {};

    virtual ~CXmlHandler()
    {};


    XML_DEFINE_TEMP(DATA* pData)
        XML_DEFINE_TEMP(ITEM* pItem)


    BEGIN_XML_PARSE_MAP()
        BEGIN_XML_ELEMENT(_T("Configuration"))
        END_XML_ELEMENT()
        BEGIN_XML_ELEMENT(_T("Data"))
        XML_ATTRIB_INIT(DATA data; m_rgData.push_back(data); pData = &m_rgData.back(); )
        XML_ATTRIB_STR(_T("strValue"), pData->m_strValue)
        XML_ATTRIB_INT(_T("intValue"), pData->m_intValue)

        XML_ATTRIB_BOOL(_T("boolValue"), pData->m_boolValue)

        END_XML_ELEMENT()
        BEGIN_XML_ELEMENT(_T("Item"))
        XML_ATTRIB_INIT(ITEM item; pData->m_rgItemData.push_back(item); pItem = &pData->m_rgItemData.back(); )
        XML_ATTRIB_INT(_T("a"), pItem->m_a)
        //XML_ATTRIB_CHAR(_T("a"), pItem->m_a)
        END_XML_ELEMENT()

        XML_TEXT_STR(_T("Description"), sDescription)
    END_XML_PARSE_MAP()

    void OnAttribute(const TCHAR* pszName, const TCHAR* pszValue) override;
    void OnElementInit(const TCHAR* pszName) override;
    void OnCharacterData(const TCHAR* pszName, const TCHAR* pszValue, int cchValue) override;
};
