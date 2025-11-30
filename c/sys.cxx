//
// Created by Serge Lussier on 2025-08-18.
//

#include <applog/sys.h>
//#include <mutex>

#include <fstream>
#include <applog/sdb.h>


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
using namespace cpp::integers;
using cpp::cxy;
using cpp::rectangle;
std::vector<std::string> sys::_ram{};

// #include <obnb/Util/Console/Console.h>


namespace fs = std::filesystem;

//////////////////////////////////////////////
/// \brief COut::Files_S
/// \note The static-global sys files array systematically init default 0'th index (STDOUT_FILE[fd #1]) with std::cout.
// sys::File::List sys::Files_S =
// {
//     {"std::out", &std::cout}
// };


//////////////////////////////////////////////
std::mutex LogMTX;
int sys::indentsize = 4;
int sys::indent = 0;

//
// ////////////////////////////////////////////////
// /// \brief COut::File::close
// ///        closes the opened file by this file struct is the descriptor is not stdout (fd:#1)
// /// \return accepted or rejected
// ///
// rem::code sys::File::Close()
// {
//     if(FilePtr){
//         if(FilePtr != &std::cout){
//             delete FilePtr;
//             FilePtr = nullptr;
//             return rem::code::accepted;
//         }
//     }
//     return rem::code::rejected;
// }

////////////////////////////////////////////////////
/// \brief COut::out constructor
/// \param out_ can be nullptr if it is required to use the default std::cout stream.
/// \param message sys output message type
/// \param src implicit / automatic source location.
///
sys::out::out(rem::type message, std::source_location&& src):
    type(message),
    code(rem::code::ok),
    location(src){
    if (type != rem::type::output)
        init_header();
}


////////////////////////////////////////////////////
/// \brief COut::out constructor specific for the header components
/// \param out_ can be nullptr if it is required to use the default std::cout stream.
/// \param message sys output message type
/// \param src implicit / automatic source location.
///
sys::out::out(rem::type message, header_component hc, std::source_location &&src):
    type(message),
    header_data(hc),
    code(rem::code::ok),
    location(src)
{
    if(!hc.Type) {
        hc.Type = 1; hc.Col  = 1; hc.BorderFrame = 1; hc.File = 1; hc.Stamp = 1; hc.Fun = 0;
        header_data = hc;
    }

    if (type != rem::type::output)
        init_header();
}




sys::out::~out()
{
    // header.clear();
    // text.clear();
}

#pragma region SYSAPPLOG

std::string sys::out::location_tail(const std::string&Fn)
{
    std::string Str = Fn;
    auto Pos = Fn.rfind('/');
    if(Pos != std::string::npos) Str = Fn.substr(Pos+1);
    return Str;
}



//////////////////////////////////////////////////////////////////////////////
/// \brief COut::out::init_header
///        internal call from the constructor.
///
void sys::out::init_header()
{

    cpp::string dash;
    //cpp::string hline;
    //hline << color::r;
    if (type == rem::type::output) return;
    if(header_data.BorderFrame){
        if(header_data.HLine){
            // for(int x=0; x < sys::Files_S[0].PageWidth ; x++)
            // {
            //     hline << Border()[Border::Horizontal];
            //     dash << "-";
            // }

        }
    }

    // if(header_data.Stamp){
    //     auto txt{cpp::string::now("%H:%M:%s")};
    //     auto [ic, a] = rem::function_attributes(rem::fn::stamp);
    //     cpp::string acc;
    //     acc << a.fg << glyph::data[ic]  << txt;
    //     header << acc() << color::r << " ";
    //
    // }
    if(header_data.Type){
        auto [Icon,Colors] = rem::type_attributes(type);
        //header << Colors <<  glyph::data[Icon]  << ' ' << rem::to_string(type) << color::z << ' ';
        header << Colors << rem::to_string(type) << color::z << ": ";
    }

    // if(header_data.File){
    //     auto [Icon, Colors] = rem::function_attributes(rem::fn::file);
    //     header << color::r << " in " << Colors << glyph::data[Icon] << ' ' <<  location_tail(location.file_name()) << color::r << ' ';
    // }

    // if(header_data.Line){
    //     auto [gh, colors] = rem::function_attributes(rem::fn::line);
    //     //header << colors << "line: " << std::format("{}", location.line()) << color::reset << ' ';
    //     header << colors << "line: " << location.line() << color::r << ' ';
    //
    // }

    // sys::_ram.push_back(header());
    //
    // header = "";
    // if(header_data.Fun && type != rem::type::test){
    //     auto [gh, colors] = rem::function_attributes(rem::fn::func);
    //     //header << color::r << "Function:" << colors <<  glyph::data[gh]  << location.function_name()<< color::r;
    //     header << color::r << "Function:" << colors << location.function_name()<< color::r;
    //
    //     sys::_ram.push_back(header());
    // }
    text = header;
    //sys::_ram.push_back(dash());
}


sys::out& sys::out::write()
{
    return *this;
}


sys::~sys()
{
    //...
    delete _db;
    //...
}


/////////////////////////////////////////////////////////////////////////////
/// \brief COut::out::operator <<
/// \param txt
/// \return
///
sys::out &sys::out::operator <<(const std::string &txt)
{
    std::lock_guard<std::mutex> lock(LogMTX);
   //_ram.emplace_back(txt);
    text << txt;
    return *this;
}



sys::out& sys::out::operator << (glyph::value f)
{
    std::lock_guard<std::mutex> lock(LogMTX);
   //_ram.emplace_back(glyph::data[f]);
    text << glyph::data[f];
    return *this;
}

/////////////////////////////////////////////////////////////////////////
/// \brief COut::out::operator <<
/// \param cstr
/// \return
///
sys::out& sys::out::operator << (const char* cstr)
{
    std::lock_guard<std::mutex> lock(LogMTX);
    //_ram.emplace_back(cstr);
    text << cstr;
    return *this;
}


////////////////////////////////////////////////////////////////////
/// \brief COut::out::operator <<
/// \param cstr
/// \return
///
sys::out& sys::out::operator << (std::string_view cstr)
{
    std::lock_guard<std::mutex> lock(LogMTX);
    //_ram.emplace_back(cstr.data());
    text << cstr.data();
    return *this;
}

////////////////////////////////////////////////////////////////////
/// \brief COut::out::operator <<
/// \param obstr
/// \return
///
sys::out& sys::out::operator << (cpp::string obstr)
{
    std::lock_guard<std::mutex> lock(LogMTX);
    //_ram.emplace_back(obstr());
    text << obstr();
    return *this;
}

//////////////////////////////////////////////////////////////////
/// \brief COut::out::operator <<
/// \param c
/// \return
///
sys::out& sys::out::operator << (char c)
{
    std::lock_guard<std::mutex> lock(LogMTX);
    std::string str;
    str += c;
    //_ram.emplace_back(str);
    text << c;
    return *this;
}


////////////////////////////////////////////////////////////////////////
/// \brief COut::out::operator <<
///     Render the given color enum (color::code) in ansi encoded out.
/// \param clr
/// \return
///
sys::out& sys::out::operator << (color::value clr)
{
    std::lock_guard<std::mutex> lock(LogMTX);
    //sys::_ram.push_back(color::render_rgb(clr));
    text << color::render_rgb(clr);
    return *this;
}


/////////////////////////////////////////////////////////////////////////
/// \brief COut::out::operator <<
/// \param clr
/// \return
///
sys::out& sys::out::operator << (color::pair clr)
{
    std::lock_guard<std::mutex> lock(LogMTX);
    //sys::_ram.push_back(color::render_rgb(clr));
    text << color::render_rgb(clr);
    return *this;
}


//////////////////////////////////////////////////////////////////////
/// \brief COut::out::operator <<
///         Translates to ansi encoded string the given rem::code enum value
/// \param c
/// \return self& for chaining call
///
sys::out& sys::out::operator << ( rem::code c)
{
    std::lock_guard<std::mutex> lock(LogMTX);
    auto [ic,col] = rem::return_code_attributes(c);
    cpp::string str;
    //str << col << ic << rem::to_string(c);
    str << col << rem::to_string(c);
    //sys::_ram.push_back(str());
    text << str();
    return *this;
}

////////////////////////////////////////////////////////////////////////
/// \brief COut::out::operator <<
///         Translates to ansi encoded string the given Rem::Type enum value
/// \param ty
/// \return self& for chaining call
///
sys::out& sys::out::operator << ( rem::type ty)
{
    std::lock_guard<std::mutex> lock(LogMTX);
    auto [ic,col] = rem::type_attributes(ty);
    cpp::string str;
    // str << col << ic << rem::to_string(ty);
    str << col << ic << rem::to_string(ty);
    //sys::_ram.push_back(str());
    text << str();
    return *this;
}

sys::out& sys::out::operator << (cxy xy)
{
    std::lock_guard<std::mutex> lock(LogMTX);
    //sys::_ram.push_back((std::string)xy);
    text << (std::string)xy;
    return *this;
}


sys::out& sys::out::operator<<(sys::fn f)
{
    switch (f)
    {
        case fn::eol:
        case fn::push:
            sys::_ram.emplace_back(text());
            text="";
            return *this;
    }
    return *this;
}


sys::out& sys::out::operator << (rectangle r)
{
    std::lock_guard<std::mutex> lock(LogMTX);
    //sys::_ram.push_back ((std::string)r);
    text << (std::string)r;
    return *this;
}

// COut::out& COut::out::operator << (ui::string2d s2d)
// {
//     string str;
//     (*OutFilePtr) << s2d.win;
//     return *this;
// }
//

sys::out& sys::out::operator << (rem::fn f)
{
    std::lock_guard<std::mutex> lock(LogMTX);
    cpp::string str;

    switch (f) {
        case rem::fn::eol:
            ///@todo Limit _ram capacity then auto flush on disk + clear the ram.
            sys::_ram.emplace_back(text());
            if (_ram.size() > 100000)
            {
                sys::flush("temp.sys",std::ios_base::app);
                _ram.clear();
            }
            text="";
            //            switch (appbook::format()) ///@todo create COut::format(); directly instead.
            //            {
            //                case color::format::ansi256:
            //                    input("\n");
            //                    break;
            //                case color::format::html:
            //                    input("<br />");
            //                    break;
            //            }
            return *this;
        case rem::fn::stamp: {
            /*
                     * %d %f ou %d %m %y
                     * %r %t %h %m %s
                     * %a {monday} %a {mon}
                     * %b {june}   %b {jun}
                */


            //std::chrono::zoned_time date{"america/toronto", std::chrono::system_clock::now()};
            //const auto tp{std::chrono::system_clock::now()};
            //auto txt{string::now("{:%h:%m:%s}", tp)};
            auto [ic, a] = rem::function_attributes(rem::fn::stamp);

            str << a.fg << glyph::data[ic] << color::z << cpp::string::now("%H:%M:%s");
            //sys::_ram.push_back(str());
            text << str();
            return *this;
        }

        case rem::fn::file:
            sys::_ram.emplace_back(location.file_name());
            return *this;
        case rem::fn::line:
        {
            auto [ggg, ccolors] = rem::function_attributes(rem::fn::line);
            str << ccolors << location.line() << color::r  << "line #" << str();
            //sys::_ram.emplace_back(str());
            text << str();
            return *this;
        }
        case rem::fn::weekday: {
            auto [ic, a] = rem::function_attributes(rem::fn::weekday);
            //auto today{std::chrono::system_clock::now()};
            str << a.fg << cpp::string::now("%A");
            //sys::_ram.emplace_back(str());
            text << str();
            return *this;
        }

        case rem::fn::day : {
            auto [ic, a] = rem::function_attributes(rem::fn::day);
            //auto today{std::chrono::system_clock::now()};
            str << a.fg << cpp::string::now("%d");
            //sys::_ram.emplace_back(str());
            text << str();
            return *this;
        }

        case rem::fn::month: {
            auto [ic, a] = rem::function_attributes(rem::fn::month);
            //auto today{std::chrono::system_clock::now()};
            str << a.fg << cpp::string::now("%M");
            //sys::_ram.emplace_back(str());
            text << str();
            return *this;
        }
        case rem::fn::monthnum: {
            auto [ic, a] = rem::function_attributes(rem::fn::month);
            //auto today{std::chrono::system_clock::now()};
            str << a.fg <<  cpp::string::now("%b");
            //sys::_ram.emplace_back(str());
            text << str();
            return *this;
        }
        case rem::fn::year: {
            auto [ic, a] = rem::function_attributes(rem::fn::year);
            //auto today{std::chrono::system_clock::now()};
            cpp::string acc;
            acc << /*utf::glyph::data[ic] <<*/ a.fg << cpp::string::now("%Y");
            //sys::_ram.emplace_back(acc());
            text << acc();
            return *this;
        }
        case rem::fn::func:
        {
            auto [gh, colors] = rem::function_attributes(rem::fn::func);
            str << colors << location.function_name() << color::z << "\n";
            //sys::_ram.emplace_back(str());
            text << str();
            return *this;
        }
            break;
        default: break;
    }
    return *this;
}


sys::out& sys::out::eol()
{
    std::lock_guard<std::mutex> lock(LogMTX);
    sys::_ram.emplace_back(text());
    text="";
    return *this;
}




/////////////////////////////////////////////////////////////
/// \brief COut::out::operator <<
///      Cheat Trick that outputs newline in the working file.
/// \return
///
sys::out& sys::out::operator << (sys::out&)
{
    std::lock_guard<std::mutex> lock(LogMTX);
    sys::_ram.emplace_back(text());
    text="";
    return *this;
}



#pragma endregion leaf_out

#pragma region exceptions.

///////////////////////////////////////////////////////////////////
/// \brief COut::exception::operator []
///  std::exception based builder.
/// \param el
/// \return
///
sys::exception sys::exception::operator[](const sys::out& el)
{
    _log_ = el;
    return *this;
}


const char* sys::exception::what() const noexcept
{
    if(!_log_.text().empty()) _msg_ = _log_.text();
    else _msg_ = "Exception message is empty";
    return _msg_.c_str();
}


#pragma endregion exceptions.

sys::sys(std::string db_name)
{
    try
    {
        std::cout << "Initializing the application journal database '" << db_name << '\'' << std::endl;
        _db = new cpp::sql::sdb(std::move(db_name));

        _db->create_table("Section"),
            cpp::sql::field_info{"ID", cpp::sql::field_info::data_type::integer, cpp::sql::field_info::index_type::primary_key},
            cpp::sql::field_info{"Name", cpp::sql::field_info::data_type::text, cpp::sql::field_info::index_type::not_indexed},
            cpp::sql::field_info{"Description", cpp::sql::field_info::data_type::blob, cpp::sql::field_info::index_type::not_indexed};

        _db->create_table("Article"),
            cpp::sql::field_info{"ID", cpp::sql::field_info::data_type::integer, cpp::sql::field_info::index_type::primary_key},
            cpp::sql::field_info{"Title", cpp::sql::field_info::data_type::text, cpp::sql::field_info::index_type::not_indexed},
            cpp::sql::field_info{"Subject", cpp::sql::field_info::data_type::blob, cpp::sql::field_info::index_type::not_indexed},
            cpp::sql::field_info{"Section", cpp::sql::field_info::data_type::integer, cpp::sql::field_info::index_type::foreign_key};

       _db->create_table("Log"),
            cpp::sql::field_info{"ID", cpp::sql::field_info::data_type::integer, cpp::sql::field_info::index_type::primary_key},
            cpp::sql::field_info{"Article", cpp::sql::field_info::data_type::integer, cpp::sql::field_info::index_type::foreign_key},
            cpp::sql::field_info{"Data", cpp::sql::field_info::data_type::blob, cpp::sql::field_info::index_type::not_indexed};

        auto& table = (*_db)["Article"];
        auto& f = table["Section"];
        f.set_foreign_key("Section", "ID");
        std::cout << table.schema_info();

    }catch (std::exception& e)
    {
        std::cerr << e.what() << std::endl;
        return;
    }

}


////////////////////////////////////////////////////////////////////////////////////
/// \brief COut::error
///     Create a COut::out for output to the specified COut::File.
///
/// \param src implicit
/// \return  COut::out instance
///
sys::out sys::error(std::source_location &&src)
{
    return{rem::type::err, std::move(src)};
}


//////////////////////////////////////////////////////////////////////////////////////////////////////
/// \brief COut::status
/// \param src
/// \return
///
sys::out sys::status(std::source_location &&src)
{
    return{rem::type::status, std::move(src)};
}

sys::out sys::warning     (std::source_location&& src){
    return {rem::type::warning, std::move(src)}; // nolint(*-move-const-arg)
}

sys::out sys::fatal       (std::source_location&& src){
    return {rem::type::fatal, std::move(src)};// nolint(*-move-const-arg)
}

sys::out sys::except      (std::source_location&& src){
    return {rem::type::except, std::move(src)};// nolint(*-move-const-arg)
}

sys::out sys::message     (std::source_location&& src){
    return {rem::type::message, std::move(src)};// nolint(*-move-const-arg)
}

sys::out sys::write       (std::source_location&& src){
    return {rem::type::output, std::move(src)};// nolint(*-move-const-arg)
}

sys::out sys::debug       (std::source_location&& src){
    return {rem::type::debug, std::move(src)};// nolint(*-move-const-arg)
}

sys::out sys::info        (std::source_location&& src){
    return {rem::type::info, std::move(src)};// nolint(*-move-const-arg)
}

sys::out sys::comment     (std::source_location&& src){
    return {rem::type::comment, std::move(src)};// nolint(*-move-const-arg)
}

sys::out sys::syntax      (std::source_location&& src){
    return {rem::type::syntax, std::move(src)};// nolint(*-move-const-arg)
}

sys::out sys::test        (std::source_location&& src){
    return {rem::type::test, std::move(src)};// nolint(*-move-const-arg)
}

sys::out sys::interrupted (std::source_location&& src){
    return {rem::type::interrupted, std::move(src)};// nolint(*-move-const-arg)
}

sys::out sys::aborted     (std::source_location&& src){
    return {rem::type::aborted, std::move(src)};// nolint(*-move-const-arg)
}

sys::out sys::segfault    (std::source_location&& src){
    return {rem::type::segfault, std::move(src)};// nolint(*-move-const-arg)
}

sys::out sys::log         (std::source_location&& src){
    return {rem::type::book, std::move(src)};// nolint(*-move-const-arg)
}


rem::code sys::flush(std::string_view filename, std::ios_base::openmode mode)
{
    std::ofstream file;
    file.open(filename.data(),std::ios_base::binary|mode);
    if (!file.is_open())
    {
        std::cout << "Unable to open file: " << filename << std::endl;
        return rem::code::failed;
    }
    file << "--------------------" <<
        color::render_rgb(color::yellow) <<
            "sys" << color::render_rgb(color::lightgreen2)<<
                "::" <<
                    color::render_rgb(color::lightcyan3) <<
                        "log" <<
                            color::render(color::r) << "----------------------------------------" <<
                                color::render(color::r) << std::endl;

    file << " application log file '" << filename << "'" << std::endl;
    file << "--------------------------------------------------------------------" << std::endl;
    for (const auto& txt : sys::_ram) file << txt << std::endl;
    file << "--------------------------eof---------------------------------------" << std::endl;
    // ~file() auto-close?
    //sys::_ram.clear();
    file.close();
    std::cout << "Flushing to " << filename << std::endl;
    return rem::code::done;
}
