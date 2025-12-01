//
// Created by Serge Lussier on 2025-09-24.
//

//#ifndef CATUI_SYS_H
//#define CATUI_SYS_H
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
#include <applog/tostr.h>
#include <source_location>
#include <sqlite3.h>

using namespace cpp::integers;
using cpp::color;


namespace cpp::sql
{
    class sdb;
}


class sys
{
    static std::vector<std::string> _ram;

public:
    enum  fn: u8
    {
        eol = 0,
        push=1,
       //...
    };

    static int indent,indentsize;
    struct out
    {
///@todo: change header components bits to one u16 bitmap.
        struct header_component
        {
            U8 Type  : 1;
            U8 Stamp : 1;
            U8 Fun   : 1;
            U8 File  : 1;
            U8 Line  : 1;
            U8 Col   : 1;
            U8 HLine : 1;
            U8 VLine : 1;
            U8 BorderFrame : 1; ///< 1 = enable vline|hline|corners and joints.
            //...
        };
        rem::type type{};
        rem::code code{};
        std::source_location location{};
        // ---------------------------------
        cpp::string  text{};
        cpp::string  header{};

        header_component header_data{1,1,1,1,1,1,0,0,0};
        out() = default;
    private:
        out(rem::type message, std::source_location&& src={});
        out(rem::type message, sys::out::header_component hc, std::source_location&& src={});
        static std::string location_tail(const std::string& Fn);
        friend class sys;
    public:
        ~out();

        void init_header();
        out& write();
        out& eol();
        out& operator << (out&);
        out& operator << (const std::string&);
        out& operator << (const char*);
        out& operator << (std::string_view);
        //out& operator << (std::string str);
        out& operator << (char c);
        out& operator << (color::value clr);
        out& operator << (color::pair clr);
        out& operator << (rem::code c);
        out& operator << (rem::type ty);
        out& operator << (rem::fn f);
        out& operator << (glyph::value f);
        out& operator << (cpp::string str);
        out& operator << (cpp::cxy xy);
        out& operator << (sys::fn f);
        out& operator << (cpp::rectangle rect);

        out& render_stamp();
        out& render_file_line();
        out& render_function();
        out& render_day();
        out& render_weekday();
        out& render_month();
        out& render_month_name();
        out& render_year();


        template<typename T> out& operator << (const T& v)
        {
            std::ostringstream o;
            o << v;
            text << o.str();
            return *this;
        }

    };

    sys()=delete;
    sys(std::string db_name);
    ~sys();


    static sys::out error       (std::source_location&& src = std::source_location::current());
    static sys::out status      (std::source_location&& src = std::source_location::current());
    static sys::out warning     (std::source_location&& src = std::source_location::current());
    static sys::out fatal       (std::source_location&& src = std::source_location::current());
    static sys::out except      (std::source_location&& src = std::source_location::current());
    static sys::out message     (std::source_location&& src = std::source_location::current());
    static sys::out write       (std::source_location&& src = std::source_location::current());
    static sys::out debug       (std::source_location&& src = std::source_location::current());
    static sys::out info        (std::source_location&& src = std::source_location::current());
    static sys::out comment     (std::source_location&& src = std::source_location::current());
    static sys::out syntax      (std::source_location&& src = std::source_location::current());
    static sys::out test        (std::source_location&& src = std::source_location::current());
    static sys::out interrupted (std::source_location&& src = std::source_location::current());
    static sys::out aborted     (std::source_location&& src = std::source_location::current());
    static sys::out segfault    (std::source_location&& src = std::source_location::current());
    static sys::out log         (std::source_location&& src = std::source_location::current());
    //...

    static rem::code flush(std::string_view filename, std::ios_base::openmode mode=std::ios_base::trunc);

    class exception :  public std::exception
    {
    public:

        explicit exception():std::exception() { _e_ = true; }
        explicit exception(const char *txt) { _msg_ = txt; _e_ = false; }
        explicit exception(const std::string &txt) { _msg_ = txt; _e_ = false; }

        ~exception() noexcept override {
            _msg_.clear();
        }

        const char* what() const noexcept override;

        sys::exception operator[](const sys::out& el);
    private:
        bool _e_;
        mutable std::string _msg_;
        sys::out _log_;
    };

private:
    std::string _db_name{};
    cpp::sql::sdb* _db{nullptr};

    
};
