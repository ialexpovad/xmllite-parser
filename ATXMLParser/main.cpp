#include <iostream>
#include "src/common.h"
#include "src/filestream.h"
#include "src/XmlParser.h"
#include "src/CXmlParserHeandler.h"

#ifndef FAILED
#define FAILED(hr) (((HRESULT)(hr)) < 0)
#endif

constexpr const TCHAR g_szXmlFile[] = _T("data\\test.xml");
bool LoadXmlFileAndParser(const TCHAR* szXmlFile);

int main(int argc, _TCHAR* argv[])
{

    if (LoadXmlFileAndParser(g_szXmlFile))
    {
        tcout << _T("All right!");
        std::wcin.get();
        return 0;
    }
    else return 1;
}


bool LoadXmlFileAndParser(const TCHAR* szXmlFile)
{
    bool bResult = false;

    if (szXmlFile && szXmlFile[0])
    {
        HRESULT hr;
        IStream* pFileStream = nullptr;

        // open a read only input stream
        if (FAILED(hr = CFileStream::OpenFile(szXmlFile, &pFileStream, false)))
            return false;

        CXmlParser xmlParser;
        if (xmlParser.Create())
        {
            CXmlHandler dataHandler;
            xmlParser.SetHandler(&dataHandler);

            if (bResult = xmlParser.Parse(pFileStream))
            {
                tcout << "Integer Value: " << dataHandler.pData->m_intValue << std::endl;
                tcout << "String Value: " << dataHandler.pData->m_strValue << std::endl;
                tcout << "Bool Value: " << dataHandler.pData->m_boolValue << std::endl;
                tcout << "Description: " << dataHandler.sDescription << std::endl;
            }
        }
    }

    return bResult;
};