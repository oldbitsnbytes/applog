//
// Created by oldlonecoder on 2025-10-05.
//

#include <applog/tostr.h>


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

#define out std::cout
#define lend std::endl;

namespace cpp
{


#define num_constructor(v) { std::ostringstream os; os << (v); _str = os.str(); }
#define num_assign(v) { std::ostringstream os; os << (v); _str += os.str(); return *this; }


string::string(const std::string& a_str)
{
    _str = a_str;
}


string::string(const char* a_str): _str(a_str){}


string::string(const string& a_str):_str(a_str._str){}
string::string(char a_ch)num_constructor(a_ch)


string::string(integers::u8 v)  num_constructor(v)
string::string(integers::u16 v) num_constructor(v)
string::string(integers::u32 v) num_constructor(v)
string::string(integers::u64 v) num_constructor(v)
string::string(integers::i8 v)  num_constructor(v)
string::string(integers::i16 v) num_constructor(v)
string::string(integers::i32 v) num_constructor(v)
string::string(integers::i64 v) num_constructor(v)
string::string(float v)         num_constructor(v)


string::~string()
{
    _str.clear();
}


string& string::operator=(const string& a_str) { _str = a_str._str; return *this; }


/////////////////////////////////////////////////////////////////////
/// \brief string::fill
///     Fills with \arg c n times at the end of _str ( begin or end-1 ).
/// \param n
/// \param c
/// \return ref-to-self
///
string &string::fill(size_t n, char c)
{
    if(!_str.empty())
        std::fill_n(_str.end()-1, n, c);
    else
        std::fill_n(_str.begin(),n,c);
    return *this;
}

///////////////////////////////////////////////////////////////
/// \brief string::fill
///     static version that creates and return pre-filled std::string with \arg c
///     usage: Mostly for indentation with spaces
/// \param c
/// \param n
/// \return
///
std::string string::fill(char c, size_t n)
{
    return std::string(n,c);
}


string& string::operator=(const char* a_str)   { _str = a_str; return *this; }
string& string::operator=(char a_ch)           { _str = a_ch; return *this; }
string& string::operator=(integers::u8 v)      num_assign(v)
string& string::operator=(integers::u16 v)     num_assign(v)
string& string::operator=(integers::u32 v)     num_assign(v)
string& string::operator=(integers::u64 v)     num_assign(v)
string& string::operator=(integers::i8 v)      num_assign(v)
string& string::operator=(integers::i16 v)     num_assign(v)
string& string::operator=(integers::i32 v)     num_assign(v)
string& string::operator=(integers::i64 v)     num_assign(v)
string& string::operator=(const std::string& a_str) { _str = a_str; return *this; }
string& string::operator=(float v)             num_assign(v)
string& string::operator=(double v)            num_assign(v)


string& string::operator << (color::value color)
{
    _str += color::render_rgb(color);
    return *this;
}


string& string::operator << (color::pair colors)
{
    _str += color::render_rgb(colors);
    return *this;
}


string& string::operator << (glyph::value ig)
{
    if(ig > glyph::book) return *this;
    _str += glyph::data[ig];
    return *this;
}


string& string::operator << (accent_fr::value ac)
{
    _str += accent_fr::data[ac];
    return *this;
}


string& string::operator << (border::Index fri)
{
    _str += border()[fri];
    return *this;
}


std::string string::word::operator*()
{
    return {begin, last+1};
}



/*!
 * \brief string::words
 * \param a_list
 * \param a_keep_as_word
 * \param a_sep
 * \return
 * \note The code below is very hard to read, I know, even from myself being the author... I had to choose between speed + efficiency + weight - and readability. I have chosen speed...
 */
size_t string::words(string::word::list& a_list, bool a_keep_as_word, const char* a_sep)
{
    if(_str.empty()) return 0;
    //out << __PRETTY_FUNCTION__ << std::endl << " text: '" << _str << "'" << std::endl;
    string::word w{_str.begin(),_str.begin(), 0};
    if(!a_sep) a_sep = cpp::string::s_default_separators;
    //out << "separators : '" << color::render(color::yellow) << a_sep << color::render(color::reset) << "'" << std::endl;
    //out << "init the first word with: '" << *w << '\'' << lend;
    if(_str.size() < 2) return 1;
    //...
    do
    {
        // out << "start iteration, w :'" << *w << '\'' << lend;
        // out << "w.last '" << *w.last << '\'' << lend;
        // out << " check separators: at '" << *w.last << '\''  << std::endl;
        if(std::string(a_sep).find(*w.last, 0/* DUH!!!!!!!!!!!!!!!!!!!*/) != std::string::npos)
        {
            if(w.last > w.begin)
            {
                a_list.push_back({w.begin, w.last-1, w.begin-_str.begin()});
                // out << "push verify word before separator: '" << *a_list.back() << "'" << std::endl;
                w.sync(_str);
            }
            if(a_keep_as_word)
            {
                a_list.push_back({w.begin, w.last, w.begin-_str.begin()});
                // out << "push separator as word: '" << *a_list.back() << '\'' << lend;
                w.sync(_str); //!!
                // out << "> push separator as word: sync'ed w:'" << *w << '\'' << lend;
            }
            if(!eat(w))
            {
                // out << "in separator bookic: eat reached end of string. - break;" << std::endl;
                break;
            }
            w.sync(_str);
            continue;
        }
        // out << "check white spaces :" << std::endl;
        if(std::isspace(*w.last))
        {
            // out << " in white spaces ..." << std::endl;
            if(w.last > w.begin)
            {
                a_list.push_back({w.begin,w.last-1, w.begin-_str.begin()});
                // out << "push before whitespace: '" << *a_list.back() << '\'' << lend;
                if(!eat(w)) break;
            }
            while(std::isspace(*w.last) && w.last != _str.end()) ++w.last;
            if(w.last == _str.end()) break;

            w.sync(_str);
            continue;
        }
        // out << "check quotes : " << std::endl;
        if(*w.last == '"' || *w.last == '\'')
        {
            auto c = *w.last;
            if(!eat(w)) break; // advance w.last ...
            if(auto off = _str.find(c, w.last-_str.begin()) != std::string::npos)
            {
                if(a_keep_as_word)
                {
                    a_list.push_back({w.begin,w.begin,w.offset});

                    ++w.begin;
                    ++w.offset;
                }
                w.last = _str.begin()+off;
                // w.last now on the second quote, closing the string.
                // Push "string" content.
                a_list.push_back({w.begin,w.last-1,w.begin-_str.begin()});
                // out << "push : '" << *a_list.back() << '\'' << lend;
                w.sync(_str);
                if(a_keep_as_word)
                {
                    a_list.push_back({w.begin,w.begin,w.offset});
                    // out << "push : '" << *a_list.back() << '\'' << lend;
                    ++w.begin;
                    ++w.offset;
                }

                if(!eat(w)) break;
                w.sync(_str);
                continue;
            }
            // else
            // {
            //     // unterminated enclosed string : " blah <=> 'halb ...";
            //     a_list.push_back({w.begin,w.last,w.begin-_str.begin()});
            //     out << "push : '" << *a_list.back() << '\'' << lend;
            //     break;
            // }
        }
        if(!eat(w)) break;

    }while(w.last != _str.end());
    if(w.last > w.begin)
    {
        a_list.push_back({w.begin,w.last, w.begin-_str.begin()});
        // out << "push last word ( w.last > w.begin ) :' " << *a_list.back() << '\'' << lend;
    }

    return a_list.size();
}


bool string::eat(string::word& w)
{
    if(w.last == _str.end()) return false;
    ++w.last;
    if(w.last == _str.end())
    {
        --w.last;
        return false;
    }
    return true;
}


std::string string::make_str(const cpp::string::list& _list)
{
    std::string str="{";
    int col=0;
    for (auto const& c:_list)
    {
        if (col++)
            str += ',';
        str += c;
    }
    str += '}';
    return str;
}



//////////////////////////////////////////////////////////////
/// \brief string::now
///
///     \b time/date format, given by \a str_fmt.
///
///     [https://cpluxplux.com/reference/ctime/strftime]
///
///   \li %a	Abbreviated weekday name
///   \li %a	Full weekday name
///   \li %b	Abbreviated month name
///   \li %b	Full month name
///   \li %c	Date and time representation (ex.:)	Thu Aug 23 14:55:02 2001
///   \li %C	Year divided by 100 and truncated to integer (00-99)
///   \li %d	Day of the month, zero-padded (01-31)
///   \li %D	Short MM/DD/YY date, equivalent to %m/%d/%y
///   \li %e	Day of the month, space-padded ( 1-31)
///   \li %F	Short YYYY-MM-DD date, equivalent to %y-%m-%d
///   \li %g	Week-based year, last two digits (00-99)
///   \li %G	Week-based year
///   \li %h	Abbreviated month name * (same as %b)
///   \li %H	Hour in 24h format (00-23)
///   \li %I	Hour in 12h format (01-12)
///   \li %j	Day of the year (001-366)
///   \li %m	Month as a decimal number (01-12)
///   \li %M	Minute (00-59)
///   \li %n	New-line character ('\n')
///   \li %p	AM or PM designation
///   \li %r	12-hour clock time
///   \li %R	24-hour HH:MM time, equivalent to %H:%M
///   \li %s	Second (00-61)
///   \li %t	Horizontal-tab character ('\t')
///   \li %T	ISO 8601 time format (HH:MM:SS), equivalent to %H:%M:%s
///   \li %u	ISO 8601 weekday as number with Monday as 1 (1-7)
///   \li %U	Week number with the first Sunday as the first day of week one (00-53)
///   \li %V	ISO 8601 week number (01-53)
///   \li %w	Weekday as a decimal number with Sunday as 0 (0-6)
///   \li %W	Week number with the first Monday as the first day of week one (00-53)
///   \li %x	Date representation
///   \li %x	Time representation
///   \li %y	Year, last two digits (00-99)
///   \li %y	Year
///   \li %z	ISO 8601 offset from UTC in timezone (1 minute=1, 1 hour=100)
///   \li %Z	Timezone name or abbreviation
///

/// \param str_fmt
/// \return
///
///
///
std::string string::now(const std::string& str_fmt)
{
    // Old archaic Code...
    // time_t rawtime;
    // struct tm* timeinfo;
    // char tmb[180];
    // std::time(&rawtime);
    // timeinfo = std::localtime(&rawtime);
    // std::strftime(tmb, 60, str_fmt.c_str(), timeinfo);
    // std::string _s = tmb;
    // //return tmb;


    auto current = std::chrono::system_clock::now();
    auto now = std::chrono::system_clock::to_time_t(current);
    auto local = localtime(&now);
    std::ostringstream ostr;
    ostr << std::put_time(local, str_fmt.c_str());
    return ostr.str();
}

std::string string::bytes(std::string_view a_seq)
{
    std::string outstr{};

    int c = 0;
    for(auto ch  : a_seq)
    {
        outstr += std::format("0x{:02x}", static_cast<int>(ch));
        if(c++ < (a_seq.size()-1)) outstr += ',';
    }

    return outstr;
}

std::string string::bytes(std::vector<int> a_seq)
{
    std::string outstr{};
    int c = 0;
    for(auto n  : a_seq)
    {
        if(std::isprint(n))
            outstr += std::format("x{:02x}|u{:d}'{}'", n,n, char(n) );
        else
            outstr += std::format("x{:02x}|u{:d}", n,n);
        if(c++ < (a_seq.size()-1)) outstr += ',';
    }

    return outstr;
}


std::string string::bytes(std::vector<integers::u8> a_seq)
{
    std::string outstr{};
    int c = 0;
    for(auto n  : a_seq)
    {
        if(std::isprint(n))
            outstr += std::format("x{:02x}|u{:d}'{}'", n,n, char(n) );
        else
            outstr += std::format("x{:02x}|u{:d}", n,n);
        if(c++ < (a_seq.size()-1)) outstr += ',';
    }

    return outstr;
}


std::vector<std::string_view> string::make_view_list(int Count, char** s, int offset)
{
    std::vector<std::string_view> result;
    if (offset == Count) return {};
    for(int i = offset; i < Count; ++i) result.emplace_back(s[i]);
    return result;
}


cpp::string::list string::make_list(int argc, char** argv, int offset)
{
    std::vector<std::string> result;
    for(int i = offset; i < argc; ++i) result.emplace_back(argv[i]);
    return result;
}
} // namespace cat

namespace cat
{




} // cat
