//
// Created by oldbitsnbytes on 2025-11-25.
//

#include <applog/sdb.h>
#include <applog/sys.h>
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
    rows.clear();
    name.clear();
}


std::string field_info::schema_info() const
{
    cpp::string out;
    out << name;
    switch (type)
    {
        case data_type::integer: out << " INTEGER"; break;
        case data_type::real: out << " REAL"; break;
        case data_type::text: out << " TEXT"; break;
        case data_type::blob: out << " BLOB"; break;
    }
    //...
    return out();
}


std::vector<field_info::iterator> table_info::foreign_keys()
{
    std::vector<field_info::iterator> fkeys{};
    for(auto f = fields.begin(); f != fields.end(); ++f) if(f->index == field_info::index_type::foreign_key) fkeys.emplace_back(f);
    return fkeys;
}


table_info::~table_info()
{
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


/*!
 * RAII
 * @param db_name
 *
 */
sdb::sdb(std::string db_name):_db_name(std::move(db_name))
{
    auto db_filename = db_name + ".db";
    auto res = sqlite3_open(db_filename.c_str(),&_db);
    if(res != SQLITE_OK)
        throw std::runtime_error(sqlite3_errmsg(_db));

    sqlite3_busy_timeout(_db,1000);
    sqlite3_exec(_db,"PRAGMA foreign_keys=ON;",nullptr,nullptr,nullptr);
    sqlite3_exec(_db,"PRAGMA journal_mode=WAL;",nullptr,nullptr,nullptr);
    sqlite3_exec(_db,"PRAGMA synchronous=OFF;",nullptr,nullptr,nullptr);
    sqlite3_exec(_db,"PRAGMA temp_store=MEMORY;",nullptr,nullptr,nullptr);
    sqlite3_exec(_db,"PRAGMA cache_size=10000;",nullptr,nullptr,nullptr);
    sqlite3_exec(_db,"PRAGMA count_changes=OFF;",nullptr,nullptr,nullptr);

    sys::info() << rem::fn::func << " SQLite database '" << db_filename << "' opened successfully." << sys::eol;
}



sdb::~sdb()
{
    if (_db)
        sqlite3_close(_db);
    _tables.clear();
    _db_name.clear();
}


table_info& sdb::create_table(std::string tbl_name)
{
    _tables.emplace_back(std::move(tbl_name));
    return _tables.back();
}


}
