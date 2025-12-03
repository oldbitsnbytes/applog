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
/**
 * @brief Represents metadata and configuration for a single field in a database table.
 *
 * Manages attributes such as field name, data type, indexing information, and associated rows.
 * Provides constructors for initialization and a destructor for cleanup.
 */
struct field_info
{
    std::string name{};
    enum data_type:u8 {
        integer=1,
        real=2,
        text=3,
        blob=4,
    } type{field_info::integer};

    bool not_null{false};
    std::string default_value{};

    enum index_type:u8
    {
        primary_key=1,
        unique=2,
        indexed=3,
        not_indexed=4,
        foreign_key=5
    }index{field_info::not_indexed};

    struct foreign_key_info
    {
        std::string column_name{};
        std::string referenced_table_name{};
        std::string referenced_column_name{};
    }fk{};

    std::vector<std::string> rows{};
    using iterator = std::vector<field_info>::iterator;

    field_info(std::string col_name, field_info::data_type t, index_type field_index_type) : name(std::move(col_name)), type(t), index(field_index_type){}
    field_info() = default;
    ~field_info();
    rem::code set_primary_key();
    rem::code set_foreign_key(std::string ref_tbl_name, std::string ref_col_name);
    rem::code set_unique();
    rem::code set_indexed();


    [[nodiscard]] std::string schema_info() const;


};

/**
 * @brief Provides metadata and information about a database table's structure.
 *
 * Manages details such as column names, data types, and other properties for describing
 * the schema of a database table.
 */
struct table_info
{
    std::string             name;
    std::vector<field_info> fields{};

    std::vector<field_info::iterator>    keys();

    explicit table_info(std::string tbl_name) : name(std::move(tbl_name)){}

    ~table_info();

    u32 prepare_field(std::string field_name, field_info::data_type field_type, field_info::index_type field_index);

    using list = std::vector<table_info>;


    table_info& operator,(field_info&& f);
    field_info& operator[](u32 idx);
    field_info& operator[](std::string_view idx);


    [[nodiscard]] std::string generate_create_table_statement();
};


/**
 * @brief Represents a database implementation using SQLite with support for table and field management.
 *
 * Provides functionality to manage a database connection and perform table creation using RAII principles.
 */
class sdb
{

    std::string _db_file{};
    sqlite3 *_db{nullptr};
    table_info::list _tables{};

public:
    sdb() = default;

    explicit sdb(std::string db_name);
    ~sdb();

    table_info& create_table(std::string tbl_name);
    table_info& operator[](std::string_view tbl_name);
    std::string generate_create_database_statement();
    auto init_create_db_file() -> rem::code;
    rem::code check_db_file() const;

private:

    static int call_back(void *NotUsed, int argc, char **argv, char **azColName);

};

} // namespace cpp::sql
