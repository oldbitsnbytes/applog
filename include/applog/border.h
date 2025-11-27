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

#include <applog/colors.h>
#include <stack>
#include <applog/glyphes.h>

namespace cpp
{

using namespace integers;

struct  border
{
    color::pair colors;     ///< colors of the box::frame


/*!
 * @brief 1v x 4h matrix for addressing Frame components
 * @note  : Source : https://github.com/ArthurSonzogni/FTXUI/blob/main/src/ftxui/screen/string.cpp
 */
    struct  FrameMatrix
    {
        u8 Left : 2;
        u8 Top  : 2;
        u8 Right: 2;
        u8 Down : 2;
        u8 Round: 1;

        bool operator < (border::FrameMatrix RHS) const;
    };

    struct  FrameData
    {
        glyph::value_type TL; ///< Top Left
        glyph::value_type TR; ///< Top Right
        glyph::value_type BL; ///< Bottom Left
        glyph::value_type BR; ///< Bottom Right
        glyph::value_type HL; ///< Horizontal Line
        glyph::value_type VL; ///< Vertical Line
        glyph::value_type CVH;///< Cross Vertical-Horizontal
        glyph::value_type CRL;///< Cross Right-towards-Left
        glyph::value_type CLR;///< Cross Left-towards-Right
        glyph::value_type CTD;///< Cross Top-towards-Down
        glyph::value_type CDT;///< Cross Down-towards-Top
        border::FrameData& operator = (const border::FrameMatrix& FrameModel);
    }Frame{ "╭", "╮", "╰", "╯", "─", "│", "┼", "┤", "├", "┬", "┴" }; ///< By ...default, hardcode the ...default model.
/*           ┃    ┃    ┃    ┃    ┃    ┃    ┃    ┃    ┃    ┃    ┃
             ┃    ┃    ┃    ┃    ┃    ┃    ┃    ┃    ┃    ┃    ┗━━{x,x,x,0,0}
             ┃    ┃    ┃    ┃    ┃    ┃    ┃    ┃    ┃    ┗━━━━━━━{x,0,x,x,0}
             ┃    ┃    ┃    ┃    ┃    ┃    ┃    ┃    ┗━━━━━━━━━━━━{0,x,x,x,0}
             ┃    ┃    ┃    ┃    ┃    ┃    ┃    ┗━━━━━━━━━━━━━━━━━{x,x,0,x,0}
             ┃    ┃    ┃    ┃    ┃    ┃    ┗━━━━━━━━━━━━━━━━━━━━━━{x,x,x,x,0}
             ┃    ┃    ┃    ┃    ┃    ┗━━━━━━━━━━━━━━━━━━━━━━━━━━━{0,x,0,x,0}
             ┃    ┃    ┃    ┃    ┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━{x,0,x,0,0}
             ┃    ┃    ┃    ┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━{x,x,0,0,1}
             ┃    ┃    ┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━{0,x,x,0,1}
             ┃    ┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━{x,0,0,x,1}
             ┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━{0,0,x,x,1}

*/
    border();
    border::FrameMatrix _Model_{2,2,2,2,0}; ///< (default) Frame model to apply to frame_data.
    static std::map<std::string_view, border::FrameMatrix> MatrixData_S;
    const char** Data[11] = {&Frame.TL, &Frame.TR,&Frame.BL,&Frame.BR,&Frame.HL,&Frame.VL,&Frame.CVH,&Frame.CRL,&Frame.CLR,&Frame.CTD,&Frame.CDT};
    enum Index : int
    {
        TopLeft=0, TopRight, BottomLeft, BottomRight, Horizontal, Vertical, Cross, VerticalTowardsLeft, VerticalTowardsRight, TopTowardsDown, DownTowardsUp
    };

    static std::stack<border::FrameMatrix> FMatrix_S;
    static void Push(border::FrameMatrix FrameModel);
    static void Pop();

    border& operator=(border::FrameMatrix Model);
    // .Frame[Mem & CharMask]; Enum: Cadre::TopLeft

    /**
     * @brief Retrieves the string representation of a frame component at the given index.
     *
     * This operator allows access to specific components of the frame by their index,
     * returning their respective string representation.
     *
     * @param Ix The index of the frame component to retrieve. It must be a valid value
     *           of the `cadre::index` enumeration.
     * @return std::string The string representation of the frame component at the given index.
     */
    std::string operator [](border::Index Ix)
    {
        //const char* -> std::string(const char*); // Creates a deep copy and that is what we want.
        // if(Ix > DownTowardsUp)
        //     throw rem::exception() [rem::fatal() << "cadres::index oob (" << Ix << ")!"];
        return *Data[Ix];
    }
};
} // obnb

//#endif //UTIL_BORDER_H
