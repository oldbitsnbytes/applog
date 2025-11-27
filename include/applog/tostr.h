//
// Created by oldlonecoder on 2025-10-05.
//

//#ifndef CATUI_STRING_H
//#define CATUI_STRING_H
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

#include <applog/rem.h>

#include <applog/geometry.h>


#include <iostream>
#include <cstring>
#include <sstream>
#include <iomanip>
#include <vector>
#include <algorithm>
#include <cctype>
#include <cstdlib>
#include <ctime>
#include <cstdint>
#include <cmath>
#include <functional>
#include <string>
#include <chrono>
#include <stack>


namespace cpp
{


class string final
{

    std::string _str{};
public:
    using list = std::vector<std::string>;
    using view_list = std::vector<std::string_view>;

    string() = default;
    string(const std::string& a_str);
    string(std::string_view a_str) { _str  = a_str; }
    string(const char* a_str);
    string(const string& a_str);
    string(char a_ch);
    string(integers::u8 v);
    string(integers::u16 v);
    string(integers::u32 v);
    string(integers::u64 v);
    string(integers::i8 v);
    string(integers::i16 v);
    string(integers::i32 v);
    string(integers::i64 v);

    string(float v);

    ~string();

    string& operator=(const string& a_str);
    string& operator=(const char* a_str);
    string& operator=(char a_ch);
    string& operator=(integers::u8 v);
    string& operator=(integers::u16 v);
    string& operator=(integers::u32 v);
    string& operator=(integers::u64 v);
    string& operator=(integers::i8 v);
    string& operator=(integers::i16 v);
    string& operator=(integers::i32 v);
    string& operator=(integers::i64 v);
    string& operator=(const std::string& a_str);
    string& operator=(float v);
    string& operator=(double v);

    template<typename T> string &operator>>(T &out)
    {
        std::istringstream in(_str); //  When string was derived from std::string ... Oops!  std::istringstream IsIn(*this);

        // if constexpr (std::is_same_v<float,T>           || std::is_same_v<double,  T> ||
        //               std::is_same_v<long double,T>     || std::is_same_v<int,     T> ||
        //               std::is_same_v<unsigned int,T>    || std::is_same_v<int8_t,  T> ||
        //               std::is_same_v<uint8_t, T>        || std::is_same_v<int16_t, T> ||
        //               std::is_same_v<uint16_t, T>       || std::is_same_v<int32_t, T> ||
        //               std::is_same_v<uint32_t, T>       || std::is_same_v<int64_t, T> ||
        //               std::is_same_v<uint64_t, T>)
        // {
        //     in >> write;
        //     return *this;
        // }
        in >> out;
        return *this;
    }

    //-------------- input/concatenation operators. -------------------------------
    string& operator << (color::value color);
    string& operator << (color::pair colors);
    string& operator << (const char* a_str) { _str += a_str; return *this; }
    string& operator << (const std::string& a_str) { _str += a_str; return *this; }
    string& operator << (glyph::value);
    string& operator << (accent_fr::value ac);
    string& operator << (border::Index fri);
    string& operator << (char c) { _str += c; return *this;}
    string& operator << (int  c) { _str += std::to_string(c); return *this;}
    string& operator << (float  c) { _str += std::to_string(c); return *this;}
    string& operator << (std::string_view sv) { _str += sv; return *this; }
    string& operator << (const string& tstr) { _str += tstr(); return *this; }
    //-----------------------------------------------------------------------------

    string& fill(size_t n, char c=0x20);
    static std::string fill(char c, size_t n);
    [[nodiscard]] auto len() const -> size_t { return _str.length(); }
    std::string operator()()const  { return _str; }
    explicit operator std::string() { return _str; }
    explicit operator std::string() const { return _str; }
    operator bool() { return _str.empty(); }
    operator bool() const { return _str.empty(); }
    std::string::iterator begin() { return _str.begin(); }
    std::string::iterator end() { return _str.end(); }
    string& operator *() { return *this; }

    template<typename T> string& operator << (T v)
    {
        std::ostringstream out;
        out << v;
        _str += out.str();
        return *this;
    }
    void clear() { _str.clear(); }

    #pragma region tokenizer

    /*!
     * @brief tokenizer struct object
     */
    template<typename str_type=std::string_view> struct  location final
    {
        rectangle rect{}; ///< smooth transition
        integers::u32 line{1};
        integers::u32 column{1};
        integers::u32 offset{0};
        using iterator = str_type::iterator;
        iterator begin{};
        iterator end{}; ///< not the typename str_type::end() but really the last valid character pointer into the segment.
        size_t   length{0};
        std::string operator *() const;
        using list = std::vector<location>;
    };

    struct  word final
    {
        std::string::iterator begin{};
        std::string::iterator last{}; ///< not the std::string::end() but really the last valid character pointer int the word.
        integers::i64         offset{-1};
        std::string           operator *();
        void                  sync(std::string& ref) { begin=last; offset = begin-ref.begin(); };
        using list = std::vector<word>;
    };


    static constexpr const char* s_default_separators = "\\%(){}[]`$#@!;,~?^&<>=+-*/:.";
    size_t words(string::word::list& a_list,  bool a_keep_as_word=true, const char* a_sep = cpp::string::s_default_separators);


private:
    bool eat(string::word& w);

#pragma endregion tokenizer

public:
    static std::string make_str(const char *B, const char *E) { return {B, E}; }
    static std::string make_str(const cpp::string::list& _list);
    static std::vector<std::string_view> make_view_list(int Count, char **s, int offset=0);

    static std::string now(const std::string &str_fmt);
    bool empty() { return _str.empty(); }

    template<typename T> static std::string to_binary(T _arg, bool padd = false, int f = 128)
    {
        uint8_t seq;
        int nbytes = sizeof(T);

        uint8_t tableau[sizeof(T)];
        memcpy(tableau, (uint8_t *) &_arg, nbytes);
        std::string stream;
        int s = 0;
        //bool Discard = false;
        for (int x = 1; x <= nbytes; x++) {
            seq = tableau[nbytes - x];
            if ((x == 1 && !padd && !seq) || (stream.empty() && !padd && !seq))
                continue;
            for (int y = 7; y >= 0; y--) { // est-ce que le bit #y est à 1 ?
                if (s >= f) {
                    stream += ' ';
                    s = 0;
                }
                ++s;
                uint8_t b = 1 << y;
                if (b & seq)
                    stream += '1';
                else
                    stream += '0';
            }
        }
        /*tableau.Clear();*/
        return stream;
    }

    static std::string bytes(std::string_view a_seq);
    static std::string bytes(std::vector<int> a_seq);
    static std::string bytes(std::vector<integers::u8> a_seq);

    template <typename T>  std::string hex(const T& num)
    {
        std::stringstream ss;
        ss << "0x" << std::hex << num;
        return ss.str();
    }
    static cpp::string::list make_list(int argc, char** argv, int offset=0);





};


template<typename str_type> std::string string::location<str_type>::operator*() const
{
    cpp::string str;
    str << "{ line #" << line << " column #" << column << " offset :" << offset << " length :" << length << "}";
    return str();
}

} // namespace cpp
