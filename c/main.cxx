//
// Created by Serge Lussier on 2025-11-27.
//
#include <applog/sys.h>



using cpp::color;

auto main() -> int
{
    sys::message() << "Hello World!" << color::reset << sys::eol;
    sys::flush("app.log");

    return 0;
}
