//
// Created by oldlonecoder on 10/29/23.
//


#include <applog/geometry.h>
#include <applog/tostr.h>
#include <applog/sys.h>

namespace cpp
{


#pragma region cxy

/**
 * @brief Subtract x,y by dxy
 *
 * @param dxy
 * @return cxy&
 */
cxy &cxy::operator-=(const cxy &dxy)
{
    x -= dxy.x;
    y -= dxy.y;
    return *this;
}

/**
 * @brief add dxy to this
 *
 * @param dxy
 * @return cxy&
 */
cxy &cxy::operator+=(const cxy &dxy)
{
    x += dxy.x;
    y += dxy.y;
    return *this;
}




/**
 * @brief comparison
 *
 * @param rhs
 * @return true
 * @return false
 */
bool cxy::operator==(cxy rhs) const
{
    return (x == rhs.x) && (y == rhs.y);
}


/**
 * @brief add x,y with dxy then return the result
 *
 * @param dxy
 * @return cxy
 */
cxy cxy::operator+(const cxy &dxy) const
{
    return {dxy.x+x, dxy.y+y};
}

/**
 * @brief subtract x,y with dxy then return the result
 *
 * @param rhs
 * @return cxy
 */
cxy cxy::operator-(const cxy &rhs) const
{
    return {x-rhs.x, y-rhs.y};
}


/**
 * @brief ? alias to get_min...
 *
 * @param rhs
 * @return cxy
 */
cxy cxy::lesser(cxy rhs) const
{
    return get_min(rhs);
}

/**
 * @brief alias to get_max
 *
 * @param rhs
 * @return cxy
 */
cxy cxy::greater(cxy rhs) const
{
    return get_max(rhs);
}


/**
 * @brief Incoldloneluxent x immediately, cancelling natural behaviour
 *
 * @return ref to self
 */
cxy &cxy::operator++()
{
    ++x;
    return *this;
}


/**
 * @brief greater comparison operator
 *
 * @param rhs
 * @return true
 * @return false
 */
bool cxy::operator>(cxy rhs) const
{
    return (x>rhs.x) || (y>rhs.y);
}

/**
 * @brief lesser comparison operator
 *
 * @param rhs
 * @return true
 * @return false
 */
bool cxy::operator<(cxy rhs) const
{
    return (x<rhs.x) || (y<rhs.y);
}


/**
 * @brief Incoldloneluxent y immediately, cancelling natural behaviour
 *
 * @return ref to self
 */
cxy &cxy::operator++(int)
{
    ++y;
    return *this;
}

cxy &cxy::operator--()
{
    return *this;
}

cxy &cxy::operator--(int)
{
    return *this;
}

cxy &cxy::operator()(int x_, int y_)
{
    return *this;
}

cxy::operator std::string() const
{
    return std::format("{},{}", x,y);
}



/**
 * @brief get the max values of x,y between this and rhs
 *
 * @param rhs
 * @return cxy
 */
cxy cxy::get_max(const cxy &rhs) const
{
    return {x >= rhs.x ? x:rhs.x, y >= rhs.y ? y : rhs.y};
}


/**
 * @brief get the min values of x,y between this and rhs
 *
 * @param rhs
 * @return cxy
 */
cxy cxy::get_min(const cxy &rhs) const
{
    return {x < rhs.x ? x:rhs.x, y < rhs.y ? y : rhs.y};
}

#pragma endregion cxy

#pragma region size

csz::operator std::string() const
{
    return std::format("{}x{}:{}", w, h , w*h);
}


/**
 * @brief dimensions comparison...
 *
 * @param dwh
 * @return true
 * @return false
 */
bool csz::operator<(const csz &dwh) const
{
    return (w < dwh.w) || (h < dwh.h);
}


bool csz::operator==(const csz &dwh) const
{
    return (w==dwh.w) && (h==dwh.h);
}

bool csz::operator>(const csz &dwh) const
{
    return (w > dwh.w) || (h > dwh.h);
}

bool csz::operator!=(const csz &dwh) const
{
    return (w!=dwh.w) || (h!=dwh.h);
}


void csz::set_min_max(cxy mi, cxy ax)
{
    min_size = mi;
    max_size = ax;
}


void csz::set_min_size(int _w, int _h)
{
    min_size = { _w, _h };
}


void csz::set_max_size(int _w, int _h)
{
    max_size = { _w, _h };
}


bool csz::has_minmax() const { return min_size.x && min_size.y && max_size.x && max_size.y; }
bool csz::has_min_size() const { return min_size.x && min_size.y; }
bool csz::has_max_size() const { return max_size.x && max_size.y; }


#pragma endregion size

#pragma region rectangle


rectangle::operator std::string() const
{
    return std::format("{},{} [{},{}:{},{}; {}x{}]", cursor.x, cursor.y, a.x, a.y, b.x,b.y, size.w, size.h);
}

std::string rectangle::tostring() const
{
    return this->operator std::string();
}

void rectangle::home()
{
    cursor = {0, 0};
}

/*!
 * @brief advance the internal cursor by one unit.
 * @return true if accepted or false otherwise.
 */
bool rectangle::operator++()
{
    scroll_dir = 0;
    ++cursor.x;
    if (cursor.x >= size.w) {
        if (nowrap) {
            --cursor.x;
            return false;
        }
        cursor.x = 0;
        ++cursor.y;
        if (cursor.y >= size.h) {
            --cursor.y;
            scroll_dir = direction::down;
            ////sys::status() << " cursor wraps to home.";
            return false;
        }
    }
    return true;
}

/*!
 * @brief  ++cursor.y
 * @return true or false if there was or not movement.
 */
bool rectangle::operator++(int)
{
    scroll_dir = 0;
    ++cursor.y;
    if (cursor.y >= size.h)
    {
        cursor.y=size.h-1;
        scroll_dir = direction::down;
        return false;
    }
    return true;
}

bool rectangle::operator--()
{
    scroll_dir = 0;
    return true;
}


/**
 * @brief Decrements the y-coordinate of the cursor and updates scroll direction
 *
 * @param int Unused integer parameter to differentiate post-decrement
 * @return bool Returns true if the cursor remains within bounds; otherwise returns false
 */
bool rectangle::operator--(int)
{
    scroll_dir = 0;
    --cursor.y;
    if (cursor.y < 0) {
        if (nowrap) {
            cursor.y = 0;
            scroll_dir = direction::up;
            return false;
        }
        cursor.y = size.h - 1;
    }
    return true;
}


/**
 * @brief Moves the rectangle's cursor to the specified coordinates if valid.
 *
 * @param xy The target coordinates to move the cursor to.
 * @return bool True if the cursor was successfully moved, false if the coordinates were invalid.
 */
bool rectangle::goto_xy(cxy xy)
{
    if (!in(xy + a)) {
        auto l = sys::error(); l  << "rejected at" << xy << l;
        return false;
    }
    cursor = xy;
    return true;
}

rectangle::rectangle(int x, int y, int w, int h)
{
    a = {x,y};
    size= { w, h };
    b = {a.x + size.w - 1, a.y + size.h - 1};
}


rectangle::rectangle(const cxy &a_, const cxy &b_)
{
    a = a_;
    b = b_;
    size.w = b.x - a.x + 1;
    size.h = b.y - a.y + 1;
}


/*!
 * \brief construct a rectangle from the size values.
 * \param wh
 */
rectangle::rectangle(const csz &dxy)
{
    a = {0, 0};
    size = dxy;
    b = {a.x + size.w - 1, a.y + size.h - 1};
}


/*!
 * \brief construct a rectangle from the size values, at cxy a_.
 * \param a_
 * \param d
 */
rectangle::rectangle(const cxy &a_, const csz &d)
{
    a = a_;
    size = d;
    b = {a.x + d.w - 1, a.y + d.h - 1};
}

void rectangle::assign(int x, int y, int w, int h)
{
    a = {x, y};
    b = {x + w - 1, y + h - 1};
    size = {w, h};
}

void rectangle::assign(const cxy &a_, const cxy &b_)
{
    a = a_;
    b = b_;
    size.w = b.x - a.x + 1;
    size.h = b.y - a.y + 1;
}

void rectangle::assign(const cxy &a_, const csz &dxy)
{
    a = a_;
    size = dxy;
    b = {a.x + dxy.w - 1, a.y + dxy.h - 1};
}

rectangle &rectangle::operator+=(const cxy &dx)
{
    a += dx;
    b += dx;
    return *this;
}


/**
 * @brief rectangle::operator -=
 * @param dx
 * @return
 */
rectangle &rectangle::operator-=(const cxy &dx)
{
    a -= dx;
    b.x -= dx.x;
    b.y -= dx.y;
    return *this;
}


/**
 * @brief Combines the current rectangle with another rectangle using the union operator.
 *
 * @param rhs The rectangle to be combined with the current rectangle.
 * @return rectangle& A reference to the current rectangle after combining.
 */
rectangle &rectangle::operator|=(const rectangle &rhs)
{
    if(!rhs) return *this;
    *this = this->operator |(rhs);
    return *this;
}


/**
 * @brief rectangle::resize
 *      Assign new dimensions to this recangle.
 * @param new_sz
 */
void rectangle::resize(const csz &new_sz)
{
    assign({a.x, a.y}, new_sz);
}



/**
 * @brief rectangle::moveat
 *      Move this reclangle to the new position \arg p
 * @param p
 */
void rectangle::move_at(const cxy &p)
{
    a.x = p.x;
    a.y = p.y;
    b.x = a.x + size.w - 1;
    b.y = a.y + size.h - 1;
}


void rectangle::set_x(int _x){ move_at({_x, a.y}); }
void rectangle::set_y(int _y){ move_at({a.x, _y}); }

/**
 * @brief rectangle::in
 *      Check if \arg pt is within this rectangle's boundaries.
 * @param pt
 * @return
 */
bool rectangle::in(const cxy &pt) const
{
    return ((pt.x >= a.x) && (pt.x <= b.x) && (pt.y >= a.y) && (pt.y <= b.y));
}


/**
 * @brief rectangle::move
 *      Moves this rectangle to new position by \arg deltapt.
 * @param deltapt
 */
void rectangle::move(const cxy &deltapt)
{
    a += deltapt;
    b += deltapt;

}

/**
 * @brief rectangle::operator ==
 *      Check if the dimensions are the saame as rhs
 * @param rhs
 * @return
 */
bool rectangle::operator == (const rectangle& rhs) const
{
    return rhs.size.w == size.w && rhs.size.h == size.h;
}



/*!
 * \brief rectangle::operator []
 * Test if the xy coord is within the boundaries. Offset origin of pt is the same as this
 * \param pt
 * \return true if within, false otherwise.

 * \author oldlonecoder (serge.lussier@oldbitsnbytes.club; lussier.serge@gmail.com)
 *
 * \note to test the internal cursor, pt must be set explicitely to cursor + a.
 */
bool rectangle::operator[](const cxy &pt) const
{
    return ((pt.x >= 0) && (pt.x < size.w) && (pt.y >= 0) && (pt.y < size.h));
}

cxy rectangle::top_left() const
{
    return a;
}

cxy rectangle::top_right() const
{
    return {b.x, a.y};
}

cxy rectangle::bottom_left() const
{
    return {a.x, b.y};
}

cxy rectangle::bottom_right() const
{
    return b;
}

/*!
    @brief intersection between this (a) and r (b).

    @note a & b must be of the same offset's origin. Undefined behaviour otherwise.
    @author &copy; 1996, 2023, Serge luxsier, (oldlonecoder'@'gmail.com)
    @code
   a+==============================+
    |                              |
    |  b+==========================|===========+
    |   |                          |           |
    |   |                        +-|--+        |
    +============================|=+  |        |
        |                        |    |        |
        |                        +----+        |
        +======================================+
    @endcode

    @note to get target's inner coords after intersection, subtract from intersection the r.a of the target rectangle.
    ex: r1 & r2 := inter; inter <- r1 := inter.a - r1.a;
*/
rectangle rectangle::operator&(const rectangle &r) const
{
    if(!r) return {};
    // auto topl = r.a - a;
    // auto botr = r.b - b;
    rectangle tmp;

    tmp.assign(cxy{
        r.a.x > a.x ? r.a.x : a.x,
        r.a.y > a.y ? r.a.y : a.y
    },cxy{
        r.b.x > b.x ? b.x : r.b.x,
        r.b.y > b.y ? b.y : r.b.y
    });
    if((!in(tmp.a)) || (!in(tmp.b))) return {};

    return tmp;
}


/**
 * @brief Divides the current rectangle by another rectangle.
 *
 * Performs a bitwise AND operation between the current rectangle
 * and the given rectangle, followed by subtraction of an internal value.
 *
 * @param rhs The rectangle to divide the current rectangle by.
 * @return rectangle A new rectangle resulting from the operation.
 */
rectangle rectangle::operator/(const rectangle &rhs) const
{
    //rectangle tmp = *this & rhs;
    //tmp -= a;
    return (*this & rhs) - a;
}


/**
 * @brief rectangle::operator |
 *      Union of the two rectangles between this ans \arg r.
 * @param r
 * @return
 */
rectangle rectangle::operator|(const rectangle &r) const
{
    rectangle tmp;
    // cxy a_ = {r.a.x <= a.x ? r.a.x : a.x, r.a.y <= a.y ? r.a.y : a.y};
    // cxy b_ = {r.b.x <= b.x ? r.b.x : b.x, r.b.y <= b.y ? r.b.y : b.y};
    cxy a_ = {std::min(r.a.x,a.x), std::min(r.a.y,a.y)};
    cxy b_ = {std::max(r.b.x,b.x), std::max(r.b.y,b.y)};

    tmp.assign(a_, b_);
    return tmp;
}


/**
 * @brief rectangle::operator +
 * moves this rectangle toplevel by \arg pt {x,y} units.
 * @param pt
 * @return resulting rectangle ( new topleft position )
 */
rectangle rectangle::operator+(const cxy &pt) const
{
    rectangle tmp = *this;
    tmp.a.x += pt.x;
    tmp.a.y += pt.y;
    tmp.b.x += pt.x;
    tmp.b.y += pt.y;
    tmp.size = size;
    return tmp;
}

/**
 * @brief rectangle::operator -
 *      * moves this rectangle toplevel by \arg pt {-x,-y} units.
 * @param pt
 * @return
 */
rectangle rectangle::operator-(const cxy& pt) const
{
    rectangle r = *this;
    r.a.x-=pt.x;
    r.a.y-=pt.y;
    r.b.x-=pt.x;
    r.b.y-=pt.y;
    return r;
}

/**
 * @brief rectangle::grow
 *      Grows this recangle from its center, by dxy {a: -x,-y; b: +x, +y} units.
 * @param dxy
 * @return resulting rectangle.
 */
rectangle rectangle::grow(cxy dxy)
{
    rectangle r = *this;

    r.a.x -= dxy.x;
    r.b.x += dxy.x;
    r.a.y -= dxy.y;
    r.b.y += dxy.y;
    r.size.w = b.x - a.x + 1;
    r.size.h = b.y - a.y + 1;
    return r;
}

/*!
 * @brief return a local representation of the cursor position.
 * @return  local relative coords of the cursor.
 */
cxy rectangle::local() const
{
    return {cursor.x - a.x, cursor.y - a.y};
}


/**
 * @brief rectangle::relative
 * @return the cursor xy values.
 */
cxy rectangle::relative() const
{
    return cursor;
}


void rectangle::set_top_left(cxy pt)
{
    a = pt;
    b = {a.x + size.w - 1, a.y + size.h - 1};
}


/**
 * @brief rectangle::tolocal
 *      remove toplevel offset from this rectangle.
 * @return resulting rectangle.
 */
rectangle rectangle::to_local() const
{
    return {{0,0}, size};
}


#pragma endregion rectangle


//- -------------------------------- string2d ------------------------------------------------------------
// #pragma region string2d
//
// string2d::string2d(const ui::size &wh)
// {
//     set_geometry(wh.w, wh.h);
//     for (int y = 0; y < wh.h; y++) data.push_back({});
//     clear();
// }
//
//
// /**
//  * @brief Destructor for the string2d class
//  *
//  * Frees all allocated resources by iterating through the internal data structure,
//  * clearing each attribute and attribute container, and finally clearing the data.
//  */
// string2d::~string2d()
// {
//     for (auto& d: data)
//     {
//         d.attributes.clear();
//     }
//     data.clear();
// }
//
//
// /**
//  * @brief Move to a specific position (x, y) in a 2D coordinate system.
//  *
//  * @param x The x-coordinate of the position to move to.
//  * @param y The y-coordinate of the position to move to.
//  * @return string2d& Reference to the current string2d instance.
//  */
// string2d &string2d::gotoxy(int x, int y)
// {
//     geometry.goto_xy({x,y});
//     return *this;
// }
//
//
// /**
//  * @brief Set the geometry of the string2d object.
//  *
//  * @param w The width of the geometry.
//  * @param h The height of the geometry.
//  */
// void string2d::set_geometry(int w, int h)
// {
//     geometry = rectangle({0,0}, size{w, h});
//     clear();
// }
//
//
// /**
//  * @brief Increment r.a.x by 1
//  *
//  * @return string2d& Reference to the updated string2d object
//  */
// string2d &string2d::operator++()
// {
//     ++geometry;
//     return *this;
// }
//
//
// /**
//  * @brief Increment r.a.y by 1
//  *
//  * @return string2d& Reference to the updated string2d object
//  */
// void string2d::operator++(int)
// {
//     geometry++;
// }
//
//
// /**
//  * @brief Decrement r.a.x by 1
//  *
//  * @return string2d& Reference to the updated string2d object
//  */
// string2d &string2d::operator--()
// {
//     --geometry;
//     return *this;
// }
//
//
//
// /**
//  * @brief Decrement r.a.y by 1
//  *
//  * @return string2d& Reference to the updated string2d object
//  */
//
// void string2d::operator--(int)
// {
//    geometry--;
// }
//
//
//
// /**
//  * @brief Inserts the given text (txt) into the 2D string at the current cursor position
//  *
//  * @param txt The text to insert into the 2D string
//  * @return string2d& A reference to the updated string2d object
//  */
// string2d &string2d::put(const std::string &txt)
// {
//     auto w = geometry.width();
//     if(!w) return *this;
//     auto line_width = w - geometry.cursor.x;
//     auto ln = txt.length();
//
//     auto dx = line_width <= ln ? line_width : ln;
//
//     std::string::iterator crs = win.begin() + (geometry.cursor.y * w + geometry.cursor.x);
//     auto p = txt.begin();
//     for (size_t x = 0; x < dx; x++)
//         *crs++ = *p++;
//
//     geometry.cursor.x += line_width;
//
//     return *this;
// }
//
//
// /**
//  * @brief Compiles the 2D string representation by applying color renders based on attributes.
//  *
//  * Processes the `data` structure to insert rendered color codes into the string based on
//  * foreground and background attributes. If no geometry is defined, an error leaf
//  * is generated and the method returns immediately.
//  *
//  * @return string2d& A reference to the current instance after compilation.
//  */
// string2d & string2d::compile()
// {
//     //...
//     auto l = sys::debug(1);
//     if (!geometry)
//     {
//         l <<  rem::type::err  << color::hotpink4 << " - no geometry defined!" << l;
//         return *this;
//     }
//
//     ///////////////////////////
//     ///
//     for (auto& d: data)
//     {
//         for (auto&a : d.attributes)
//         {
//             if (a.fg && !a.bg) d.line.insert(a.col_offset, color::render(a.colors.fg));
//             else if (a.bg && !a.fg) d.line.insert(a.col_offset, color::render(a.colors.bg));
//             else if (a.fg && a.bg) d.line.insert(a.col_offset, color::render(a.colors));
//         }
//     }
//
//     return *this;
// }
//
//
// /**
//  * @brief Clears the 2D string representation by filling it with blank spaces.
//  *
//  * Resets the internal string representation to contain only blank spaces,
//  * based on the current width and height of the rectangular dimensions.
//  */
// void string2d::clear()
// {
//     win = std::string(geometry.size.w * geometry.size.h, ' ');
//     for (auto l : data)
//     {
//         // Clear the attributes
//         l.attributes.clear();
//         l.line = std::string(geometry.size.w, ' ');
//     }
//
// }
//
//
// void string2d::home()
// {
//     gotoxy(0,0);
// }
//
//
// /*!
//  * @brief Draws surrounding frame.
//  *
//  * @note This method is destructive at the line #0 and at the bottom of the rectangle. It is using the frame glyphes (UTF-8)-like multibytes char.
//  *       So be sure to sync with the rest of the contents. It is also important to invoke this method at the very end of this string2d building.
//  */
// void string2d::frame()
// {
//     std::fill(data[0].line.begin(), data[0].line.end(), cadre()[cadre::Horizontal]);
//
//     data[0].line = cadre()[cadre::TopLeft];
//     // Horizontal line
//     for (int i=1; i < geometry.size.w-1; i++)
//         data[0].line.append(cadre()[cadre::Horizontal]);
//
//     data[0].line.append = cadre()[cadre::TopRight];
//     for (int i = 1; i < geometry.size.h-1; i++)
//     {
//         data[i].line.erase(0, 1);
//         data[i].line.insert = cadre()[cadre::Vertical];
//         data[i].line[geometry.size.w-1] = cadre()[cadre::Vertical];
//     }
//     data[geometry.size.h-1].line[0] = cadre()[cadre::Bottom];
//     data[geometry.size.h-1].line[geometry.size.w-1] = cadre()[cadre::Bottom];
// }
//
//
// /**
//  * @brief Provides access to internal details.
//  *
//  * @return Reference to the internal details object.
//  */
// std::string string2d::details() const
// {
//     string str = "string2d details:\n";
//     str << geometry.tostring() << " cursor: " << (std::string)geometry.cursor;
//     return str();
// }
//
//
// /**
//  * @brief Converts the 2D string representation to a std::string.
//  *
//  * @return A std::string representing the 2D data. If the area is uninitialized or undefined,
//  *         a default error message is returned. Otherwise, the content is formatted as rows with
//  *         elements from the area separated by line breaks.
//  */
// string2d::operator std::string()
// {
//     std::string str;
//     if (win.empty())
//         return "oops! there is no such defined and initialised area!";
//     str += '\n';
//     auto w = geometry.width();
//     auto h = geometry.height();
//
//     if(!w||h) return str;
//
//     for (int l = 0; l < h; l++) {
//         for (int c = 0; c < w; c++)
//             str += *(win.begin() + (l * w + c));
//         str += '\n';
//     }
//     return str;
// }
//
//
// string2d& string2d::operator<<(cxy xy)
// {
//     if(!geometry[xy])
//     {
//         ////sys::error() << //sys::code::oob << r << "; <-" << xy;
//         return *this;
//     }
//     geometry.goto_xy(xy);
//     return *this;
// }
//
//
// /**
//  * @brief Overloads the operator
//  *
//  * Provides a custom implementation for this operator to define its behavior.
//  *
//  * @return Result of the operator application
//  */
// string2d & string2d::operator<<(color::code fg)
// {
//     //win += color::render(fg);
//     data[geometry.cursor.y].attributes.push_back({.fg=1,.bg=0,.col_offset=geometry.cursor.x,.colors={fg,color::r}});
//     return *this;
// }
//
//
// string2d & string2d::operator<<(color::pair cp)
// {
//     //win += color::render(cp);
//     data[geometry.cursor.y].attributes.push_back({.fg=1,.bg=1,.col_offset=geometry.cursor.x,.colors=cp});
//     return *this;
// }
//
//
// #pragma endregion string2d
//

}
