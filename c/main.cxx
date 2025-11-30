//
// Created by Serge Lussier on 2025-11-27.
//
#include <applog/sys.h>
#include <applog/sdb.h>


using cpp::color;

auto main() -> int
{
    sys::message() << "Hello World!" << color::reset << sys::eol;
    sys logger("applog_test");

    sys::flush("app.log");

    return 0;
}
