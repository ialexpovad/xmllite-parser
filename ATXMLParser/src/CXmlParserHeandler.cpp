#include "CXmlParserHeandler.h"

#define GET_XML_ATTRIB_STR(_Test, _Loc, _attrib, _value) if ( _tcsicmp( _Test, _attrib )==0 ) { _Loc = _value; }
#define GET_XML_ATTRIB_INT(_Test, _Loc, _attrib, _value) if ( _tcsicmp( _Test, _attrib )==0 ) { _Loc = _ttoi( _value ); }
#define GET_XML_ATTRIB_CHAR(_Test, _Loc, _attrib, _value) if ( _tcsicmp( _Test, _attrib )==0 ) { _Loc = _value[0]; }
#define GET_XML_ATTRIB_BOOL(_Test, _Loc, _attrib, _value) if ( _tcsicmp( _Test, _attrib )==0 ) { _Loc = _value[0] == 't' || _value[0] == 'T'; }
//#define XML_ATTRIB_BOOL(_attrib, _value) if ( _tcscmp( _attrib, _it->m_strName.c_str() )==0 ) { _value = _it->m_strValue.c_str()[0] == 't' || **(_it+1)=='T'; };

#define GET_XML_TEXT_STR(_Test, _Loc, _name, _value, _szvalue) if ( _tcsicmp( _Test, _Test ) == 0 ) { _Loc = _value; }


void CXmlHandler::OnElementInit(const TCHAR* pszName)
{
    if (_tcsicmp(_T("Data"), pszName) == 0)
    {
        DATA room;

        m_rgData.push_back(room);
        pData = &m_rgData.back();
        pItem = nullptr;
    }
    else if (_tcsicmp(_T("Item"), pszName) == 0)
    {
        if (pData)
        {
            ITEM item;
            pData->m_rgItemData.push_back(item);
            pItem = &pData->m_rgItemData.back();
        }
    }
};

void CXmlHandler::OnAttribute(const TCHAR* pszName, const TCHAR* pszValue)
{
    if (pData)
    {
            GET_XML_ATTRIB_STR(_T("strValue"), pData->m_strValue, pszName, pszValue)
            GET_XML_ATTRIB_INT(_T("intValue"), pData->m_intValue, pszName, pszValue)
            GET_XML_ATTRIB_BOOL(_T("boolValue"), pData->m_boolValue, pszName, pszValue)
    }

    if (pItem)
    {
        GET_XML_ATTRIB_INT(_T("a"), pItem->m_a, pszName, pszValue)
    }
};


void CXmlHandler::OnCharacterData(const TCHAR* pszName, const TCHAR* pszValue, int cchValue)
{
    //void OnCharacterData(LPCWSTR value, INT cch) { if (_sRef != NULL) (*_sRef) += std::wstring(value, (size_t)cch); };
    GET_XML_TEXT_STR(_T("Description"), sDescription, pszName, pszValue, cchValue)
}