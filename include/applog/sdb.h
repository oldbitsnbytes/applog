//
// Created by oldbitsnbytes on 2025-11-25.
//

//#ifndef DIAGNOSTIC_SDB_H
//#define DIAGNOSTIC_SDB_H
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
#include <applog/rem.h>

#include <sqlite3.h>

namespace cpp::sql
{


struct field_info
{
    std::string name{};
    enum data_type:u8 {
        integer=1,
        real=2,
        text=3,
        blob=4,
    } type{field_info::integer};

    enum index_type:u8
    {
        primary_key=1,
        unique=2,
        indexed=3,
        not_indexed=4,
        foreign_key=5
    }index{field_info::not_indexed};

    std::vector<std::string> rows{};
    using iterator = std::vector<field_info>::iterator;

    field_info(std::string col_name, field_info::data_type t, index_type field_index_type) : name(std::move(col_name)), type(t), index(field_index_type){}
    field_info() = default;
    ~field_info();


};


struct table_info
{
    std::string             name;
    std::vector<field_info> fields{};

    std::vector<field_info::iterator>    foreign_keys();

    explicit table_info(std::string tbl_name) : name(std::move(tbl_name)){}

    ~table_info();

    u32 prepare_field(std::string field_name, field_info::data_type field_type, field_info::index_type field_index);

    using list = std::vector<table_info>;


    table_info& operator,(field_info&& f);
    field_info& operator[](u32 idx);
    field_info& operator[](std::string_view idx);
};




class sdb
{

    std::string _db_name{};
    sqlite3 *_db{nullptr};
    table_info::list _tables{};

public:
    sdb() = default;

    explicit sdb(std::string db_name);
    ~sdb();

    table_info& create_table(std::string tbl_name);
private:

};

} // namespace cpp::sql
