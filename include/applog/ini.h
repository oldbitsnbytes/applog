//
// Created by oldlonecoder on 2025-09-23.
//

////////////////////////////////////////////////////////////////////////////////////////////
//   Copyright (C) ...,2025,... by Serge Lussier
//   serge.lussier@oldbitsnbytes.club / lussier.serge@gmail.com
//   ----------------------------------------------------------------------------------
//   Unless otherwise specified, all Codes and files in this project is written
//   by the author and owned by the author (Serge Lussier), unless otherwise specified.
//   ----------------------------------------------------------------------------------
//   Copyrights from authors other than Serge Lussier also apply here.
//   Open source FREE licences also apply to the code from the author (Serge Lussier)
//   ----------------------------------------------------------------------------------
//   Usual GNU FREE GPL-1,2, MIT... or whatever -  apply to this project.
//   ----------------------------------------------------------------------------------
//   NOTE : All source code that I am the only author, I reserve for myself, the rights to
//   make it to restricted private license.
////////////////////////////////////////////////////////////////////////////////////////////
//------------------------------------------------------------------------------------------


#pragma once

//#warning "This project uses 'cpp::' as its main/root namespace. Please adjust your includes and usings accordingly."

#if defined(_MSC_VER) || defined(WIN64) || defined(_WIN64) || defined(__WIN64__) || defined(WIN32) || defined(_WIN32) || defined(__WIN32__) || defined(__NT__)
#warning "Windows detected - msvc env and Windows console terminal not yet fully supported..."
pragma warning(disable : 4996)
//#   pragma warning(disable : 4005)
//#   pragma warning(disable : 4267)
#   pragma warning(disable : 4251)
//class __declspec(dllimport) std::thread;
#   define _CRT_SECURE_NO_WARNINGS
#   define _SCL_SECURE_NO_WARNINGS
#   define NOMINMAX
#   if defined(APPLOG_LIB_EXPORT)
#       define APPLOG_LIB  __declspec(dllexport)
#   else
#       define APPLOG_LIB __declspec(dllimport)
#   endif

#else
#   define APPLOG_LIB //__visibility__("default")
#endif

// ------------ Mandatory includes ------------
#include <cstdint>
#include <thread>
#include <mutex>
#include <condition_variable>
#include <vector>

// ------------ PRSEUDO NAME ------------
#ifndef CLASSNAME_START
#define CLASSNAME_START(CLASS) \
    public:\
        virtual const char*  class_name() const noexcept\
        {\
            return #CLASS;\
        }\
    private:
#endif

#ifndef CLASSNAME_DERIVED
# define CLASSNAME_DERIVED(CLASS) \
    public:\
        const char*  class_name() const noexcept override\
        {\
            return #CLASS;\
        }\
    private:
#endif


//--  Stand alone non-virtual class names macros : --

#ifndef CLASSNAME
# define CLASSNAME(CLASS) \
public:\
const char*  class_name() const noexcept { return #CLASS; }\
private:

#endif



//----------------------------------------------------------------------------

namespace cpp::integers
{
using Byte  = uint8_t;
using I8    = int8_t;
using U8    = uint8_t;
using I16   = int16_t;
using U16   = uint16_t;
using I32   = int32_t;
using U32   = uint32_t;
using I64   = int64_t;
using U64   = uint64_t;
using UReg  = uint64_t;
using byte  = uint8_t;
using i8    = int8_t;
using u8    = uint8_t;
using i16   = int16_t;
using u16   = uint16_t;
using i32   = int32_t;
using u32   = uint32_t;
using i64   = int64_t;
using u64   = uint64_t;
using u_reg = uint64_t;
}
