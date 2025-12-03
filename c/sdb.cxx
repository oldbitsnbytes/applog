//
// Created by oldbitsnbytes on 2025-11-25.
//

#include <applog/sdb.h>
#include <applog/sys.h>
#include <filesystem>



namespace fs = std::filesystem;

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



namespace cpp::sql
{


field_info::~field_info()
{
    //std::cout << "    ~field_info('" << name << "')" << std::endl;
    rows.clear();
    name.clear();
}


rem::code field_info::set_primary_key()
{
    index = index_type::primary_key;
    return rem::code::ok;
}


rem::code field_info::set_foreign_key(std::string ref_tbl_name, std::string ref_col_name)
{
    fk.referenced_table_name = std::move(ref_tbl_name);
    fk.referenced_column_name = std::move(ref_col_name);
    index = index_type::foreign_key;
    return rem::code::ok;
}


rem::code field_info::set_unique()
{
    index = index_type::unique;
    return rem::code::ok;
}


rem::code field_info::set_indexed()
{
    index = index_type::indexed;
    return rem::code::ok;
}


std::string field_info::schema_info() const
{
    cpp::string out;
    out << name;
    switch (type)
    {
        case data_type::integer:
        {
            out << " INTEGER";
            if(not_null)
            {
                out << " NOT NULL";
                if(default_value.empty())
                    out << " DEFAULT " << default_value;
            }
            // else
            //     if (index == index_type::primary_key)
            //         out << " PRIMARY KEY";
        }
            break;
        case data_type::real: out << " REAL"; break;
        case data_type::text: out << " TEXT"; break;
        case data_type::blob: out << " BLOB"; break;
    }

    //...
    return out();
}


std::vector<field_info::iterator> table_info::keys()
{
    std::vector<field_info::iterator> fkeys{};
    for(auto f = fields.begin(); f != fields.end(); ++f)
        if ((f->index == field_info::index_type::foreign_key) || (f->index == field_info::index_type::primary_key)) fkeys.push_back(f);
    return fkeys;
}


table_info::~table_info()
{
    //std::cout << "~table_info('" << name  << "')" << std::endl;
    //std::cout << "    clearing ("<< fields.size() << ") fields" << std::endl;
    fields.clear();
    name.clear();
}



u32 table_info::prepare_field(std::string field_name, field_info::data_type field_type,
                              field_info::index_type field_index)
{
    fields.emplace_back(std::move(field_name),field_type,field_index);
    return fields.size();
}


table_info& table_info::operator,(field_info&&f)
{
    std::cout << "    adding field '" << f.name << "' ( Destructor called during std::move ):" << std::endl;
    fields.emplace_back(std::move(f));
    return *this;
}


field_info& table_info::operator[](u32 idx)
{
    if(idx >= fields.size())
        throw sys::exception()[sys::error() << "field index " << idx << " out of range [0," << fields.size() << ")"];
    return fields[idx];
}


field_info& table_info::operator[](std::string_view idx)
{
    for(auto& f : fields)
        if(f.name == idx)
            return f;
    throw sys::exception()[sys::error() << "field name '" << idx << "' not found in table '" << name << "'"];
    return fields.back();
}


std::string table_info::generate_create_table_statement()
{
    cpp::string out;
    out << "CREATE TABLE IF NOT EXISTS \"" << name << "\" (";
    auto i = 0;
    for(auto& f : fields)
    {
        if (i>0)
            out << ", ";
        out << f.schema_info();
        ++i;
    }
    auto fk = std::move(keys());
    if (fk.empty())
        return out() + ");";

    for (auto const f: fk)
    {

        switch (f->index)
        {
            case field_info::index_type::primary_key:  out << ", PRIMARY KEY(\"" << f->name << "\")"; break;
            case field_info::index_type::foreign_key:  out << ", FOREIGN KEY(\"" << f->name << "\") REFERENCES \"" << f->fk.referenced_table_name << "\"(\"" << f->fk.referenced_column_name << "\")"; break;

            default:break;
        }

    }

    out << ");";

    return out();
}


/*!
 * RAII
 * @param db_name
 *
 */
sdb::sdb(std::string db_name)
{
    _db_file = std::move(db_name) + ".db";
    
    std::cout << "SQLite database '" << _db_file << "' opening..." << std::endl;
    auto res = sqlite3_open(_db_file.c_str(),&_db);
    if(res != SQLITE_OK)
        throw std::runtime_error(sqlite3_errmsg(_db));

    sqlite3_busy_timeout(_db,1000);
    sqlite3_exec(_db,"PRAGMA foreign_keys=ON;",nullptr,nullptr,nullptr);
    sqlite3_exec(_db,"PRAGMA journal_mode=WAL;",nullptr,nullptr,nullptr);
    sqlite3_exec(_db,"PRAGMA synchronous=OFF;",nullptr,nullptr,nullptr);
    sqlite3_exec(_db,"PRAGMA temp_store=MEMORY;",nullptr,nullptr,nullptr);
    sqlite3_exec(_db,"PRAGMA cache_size=10000;",nullptr,nullptr,nullptr);
    sqlite3_exec(_db,"PRAGMA count_changes=OFF;",nullptr,nullptr,nullptr);

    sys::info() << rem::fn::file << sys::eol << rem::fn::func << sys::eol << "    => SQLite database '" << _db_file << "' opened successfully." << sys::eol;
}



sdb::~sdb()
{
    if (_db)
    {
        sqlite3_close(_db);
        std::cout << "SQLite database '" << _db_file << "' closed successfully." << std::endl;
    }
    _tables.clear();
    _db_file.clear();

}


table_info& sdb::create_table(std::string tbl_name)
{
    _tables.emplace_back(std::move(tbl_name));
    return _tables.back();
}


table_info& sdb::operator[](std::string_view tbl_name)
{
    for(auto& t : _tables) if(t.name == tbl_name) return t;
    throw sys::exception()[sys::error() << "table '" << tbl_name << "' not found in database '" << _db_file << "'"];
}


std::string sdb::generate_create_database_statement()
{
    sys::warning() << "Generating CREATE DATABASE statement for database '" << _db_file << "'" << sys::eol;
    sys::log()     << "    This is not a standard SQL statement and may not work on all databases." << sys::eol;
    sys::log()     << "    Use this statement only if the sqlite database file is not present and a new must be created." << sys::eol;

    if (_tables.empty())
    {
        sys::error() <<"'" << _db_file << "': no tables in database - Declare tables prior to call this method." << sys::eol;
        return "";
    }
    cpp::string out;
    //out << "CREATE DATABASE IF NOT EXISTS \"" << _db_file << "\""; - SQLITE does not have dbname in its own file.
    for(auto& t : _tables) out << t.generate_create_table_statement();
    return out();
}


auto sdb::init_create_db_file() -> rem::code
{
    //auto res = sqlite3_open(db_filename.c_str(),&_db);
    auto res = sqlite3_exec(_db,generate_create_database_statement().c_str(),nullptr,nullptr,nullptr);
    if(res != SQLITE_OK)
    {
        sys::error() << "Failed to create database '" << _db_file << "': " << sqlite3_errmsg(_db) << sys::eol;
        sqlite3_close(_db);
        return rem::code::failed;
    }
    sys::info() << "Database '" << _db_file << "' tables successfully deployed." << sys::eol;
    return rem::code::success;
}


rem::code sdb::check_db_file() const
{
    auto db_filename = _db_file + ".db";
    return fs::exists(db_filename) ?  rem::code::exist : rem::code::notexist;
}


int sdb::call_back(void* tbl_schema, int col_count, char** data, char** column_name)
{
    if (!tbl_schema)
        throw sys::exception()[sys::error() << "table schema is null"];
    if (!data)
        throw sys::exception()[sys::error() << "table data is null"];
    if (!column_name)
        throw sys::exception()[sys::error() << "table column names is null"];
    sys::info()  << "table schema: " << tbl_schema << sys::eol;
    auto& table = *(reinterpret_cast<table_info*>(tbl_schema));
    for (int i = 0; i < col_count; ++i)
    {
        field_info& f = table[column_name[i]];
        if (data[i])
            f.rows.emplace_back(data[i] ? data[i]: "nullptr");

    }

    return 0;
}
}
