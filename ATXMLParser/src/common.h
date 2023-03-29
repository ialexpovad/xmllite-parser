#pragma once

#if !defined(__COMMON_H__)
#define __COMMON_H__

#ifndef _INC_TCHAR
    #include <tchar.h>
#endif
#ifndef _IOSTREAM_
    #include <iostream>
#endif
#ifndef _STRING_
    #include <string>
#endif

#if !defined(_TSTRING_)
#define _TSTRING_
    #if defined(UNICODE) || defined(_UNICODE)
        #define tstring std::wstring
        #define tcout   std::wcout
        #define tcin    std::wcin
    #else
        #define tstring std::string
        #define tcout   std::cout
        #define tcin    std::cin
    #endif
#endif

#endif