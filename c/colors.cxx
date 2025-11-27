//
// Created by oldlonecoder on 2025-09-23.
//

#include <applog/colors.h>
//#include <catui/widgets/object.h>
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

// #include <sstream>
// #include <iomanip>
// #include <vector>
// #include <algorithm>
// #include <ctypes>
// #include <cstdlib>
// #include <ctime>
// #include <cstdint>
// #include <cmath>
// #include <functional>
// #include <string>
// #include <string_view>
// #include <stack>
// #include <unordered_map>
// #include <map>


namespace cpp
{

/*!
 *  https://www.ditig.com/publications/256-colors-cheat-sheet
 */
std::vector<color::data> color::colors_db =
{
    /*0   */ {color::black            , "#000"            , 0x00, 0x00, 0x00},
    /*1   */ {color::maroon           , "maroon"          , 0x80, 0x00, 0x00},
    /*2   */ {color::green            , "green"           , 0x00, 0x80, 0x00},
    /*3   */ {color::olive            , "olive"           , 0x30, 0x50, 0x00},
    /*4   */ {color::navy             , "navy"            , 0x00, 0x00, 0x80},
    /*5   */ {color::purple           , "purple"          , 0x80, 0x00, 0x80},
    /*6   */ {color::cyan             , "cyan"            , 0x00, 0x80, 0x80},
    /*7   */ {color::silver           , "silver"          , 0xc0, 0xc0, 0xc0},
    /*8   */ {color::grey             , "grey"            , 0x80, 0x80, 0x80},
    /*9   */ {color::red              , "red"             , 0xff, 0x00, 0x00},
    /*10  */ {color::lime             , "lime"            , 0x00, 0xff, 0x00},
    /*11  */ {color::yellow           , "yellow"          , 0xff, 0xff, 0x00},
    /*12  */ {color::blue             , "blue"            , 0x00, 0x00, 0xff},
    /*13  */ {color::fuchsia          , "fuchsia"         , 0xff, 0x00, 0xff},
    /*14  */ {color::aqua             , "aqua"            , 0x00, 0xff, 0xff},
    /*15  */ {color::white            , "white"           , 0xff, 0xff, 0xff},
    /*16  */ {color::grey0            , "grey #0"           , 0x00, 0x00, 0x00},
    /*17  */ {color::navyblue         , "navyblue"        , 0x00, 0x00, 0x5f},
    /*18  */ {color::darkblue         , "darkblue"        , 0x00, 0x00, 0x87},
    /*19  */ {color::blue3            , "blue #3"           , 0x00, 0x00, 0xaf},
    /*20  */ {color::blue4            , "blue #4"           , 0x00, 0x00, 0xd7},
    /*21  */ {color::blue1            , "blue #1"           , 0x00, 0x00, 0xff},
    /*22  */ {color::darkgreen        , "darkgreen"       , 0x00, 0x5f, 0x00},
    /*23  */ {color::deepskyblue4     , "deepskyblue #4"    , 0x00, 0x5f, 0x5f},
    /*24  */ {color::deepskyblue5     , "deepskyblue #5"    , 0x00, 0x5f, 0x87},
    /*25  */ {color::deepskyblue6     , "deepskyblue #6"    , 0x00, 0x5f, 0xaf},
    /*26  */ {color::dodgerblue3      , "dodgerblue #3"     , 0x00, 0x5f, 0xd7},
    /*27  */ {color::dodgerblue2      , "dodgerblue #2"     , 0x00, 0x5f, 0xff},
    /*28  */ {color::green4           , "green #4"          , 0x00, 0x87, 0x00},
    /*29  */ {color::springgreen4     , "springgreen #4"    , 0x00, 0x87, 0x5f},
    /*30  */ {color::turquoise4       , "turquoise #4"      , 0x00, 0x87, 0x87},
    /*31  */ {color::deepskyblue3     , "deepskyblue #3"    , 0x00, 0x87, 0xaf},
    /*32  */ {color::deepskyblue7     , "deepskyblue #7"    , 0x00, 0x87, 0xd7},
    /*33  */ {color::dodgerblue1      , "dodgerblue #1"     , 0x00, 0x87, 0xff},
    /*34  */ {color::green3           , "green3"          , 0x00, 0xaf, 0x00},
    /*35  */ {color::springgreen3     , "springgreen3"    , 0x00, 0xaf, 0x5f},
    /*36  */ {color::darkcyan         , "darkcyan"        , 0x00, 0xaf, 0x87},
    /*37  */ {color::lightseagreen    , "lightseagreen"   , 0x00, 0xaf, 0xaf},
    /*38  */ {color::deepskyblue2     , "deepskyblue2"    , 0x00, 0xaf, 0xd7},
    /*39  */ {color::deepskyblue1     , "deepskyblue1"    , 0x00, 0xaf, 0xff},
    /*40  */ {color::green5           , "green5"          , 0x00, 0xd7, 0x00},
    /*41  */ {color::springgreen5     , "springgreen5"    , 0x00, 0xd7, 0x5f},
    /*42  */ {color::springgreen2     , "springgreen2"    , 0x00, 0xd7, 0x87},
    /*43  */ {color::cyan3            , "cyan3"           , 0x00, 0xd7, 0xaf},
    /*44  */ {color::darkturquoise    , "darkturquoise"   , 0x00, 0xd7, 0xd7},
    /*45  */ {color::turquoise2       , "turquoise2"      , 0x00, 0xd7, 0xff},
    /*46  */ {color::green1           , "green1"          , 0x00, 0xff, 0x00},
    /*47  */ {color::springgreen6     , "springgreen6"    , 0x00, 0xff, 0x5f},
    /*48  */ {color::springgreen1     , "springgreen1"    , 0x00, 0xff, 0x87},
    /*49  */ {color::mediumspringgreen, "mediumspringgree", 0x00, 0xff, 0xff},
    /*50  */ {color::cyan2            , "cyan2"           , 0x00, 0xff, 0xd7},
    /*51  */ {color::cyan1            , "cyan1"           , 0x00, 0xff, 0xff},
    /*52  */ {color::darkred          , "darkred"         , 0x5f, 0x00, 0x00},
    /*53  */ {color::deeppink4        , "deeppink4"       , 0x5f, 0x00, 0x5f},
    /*54  */ {color::purple4          , "purple4"         , 0x5f, 0x00, 0x87},
    /*55  */ {color::purple5          , "purple5"         , 0x5f, 0x00, 0xaf},
    /*56  */ {color::purple3          , "purple3"         , 0x5f, 0x00, 0xd7},
    /*57  */ {color::blueviolet       , "blueviolet"      , 0x5f, 0x00, 0xff},
    /*58  */ {color::orange4          , "orange4"         , 0x5f, 0x5f, 0x00},
    /*59  */ {color::grey37           , "grey37"          , 0x5f, 0x5f, 0x5f},
    /*60  */ {color::mediumpurple4    , "mediumpurple4"   , 0x5f, 0x5f, 0x87},
    /*61  */ {color::slateblue3       , "slateblue3"      , 0x5f, 0x5f, 0xaf},
    /*62  */ {color::slateblue4       , "slateblue4"      , 0x5f, 0x5f, 0xd7},
    /*63  */ {color::royalblue1       , "royalblue1"      , 0x5f, 0x5f, 0xff},
    /*64  */ {color::chartreuse4      , "chartreuse4"     , 0x5f, 0x87, 0x00},
    /*65  */ {color::darkseagreen4    , "darkseagreen4"   , 0x5f, 0x87, 0x5f},
    /*66  */ {color::paleturquoise4   , "paleturquoise4"  , 0x5f, 0x87, 0x87},
    /*67  */ {color::steelblue        , "steelblue"       , 0x5f, 0x87, 0xaf},
    /*68  */ {color::steelblue3       , "steelblue3"      , 0x5f, 0x87, 0xd7},
    /*69  */ {color::cornflowerblue   , "cornflowerblue"  , 0x5f, 0x87, 0xff},
    /*70  */ {color::chartreuse3      , "chartreuse3"     , 0x5f, 0xaf, 0x00},
    /*71  */ {color::darkseagreen5    , "darkseagreen5"   , 0x5f, 0xaf, 0x5f},
    /*72  */ {color::cadetblue        , "cadetblue"       , 0x5f, 0xaf, 0x87},
    /*73  */ {color::cadetblue2       , "cadetblue2"      , 0x5f, 0xaf, 0xaf},
    /*74  */ {color::skyblue3         , "skyblue3"        , 0x5f, 0xaf, 0xd7},
    /*75  */ {color::steelblue1       , "steelblue1"      , 0x5f, 0xaf, 0xff},
    /*76  */ {color::chartreuse5      , "chartreuse5"     , 0x5f, 0xd7, 0x00},
    /*77  */ {color::palegreen3       , "palegreen3"      , 0x5f, 0xd7, 0x5f},
    /*78  */ {color::seagreen3        , "seagreen3"       , 0x5f, 0xd7, 0x87},
    /*79  */ {color::aquamarine3      , "aquamarine3"     , 0x5f, 0xd7, 0xaf},
    /*80  */ {color::mediumturquoise  , "mediumturquoise" , 0x5f, 0xd7, 0xd7},
    /*81  */ {color::steelblue4       , "steelblue4"      , 0x5f, 0xd7, 0xff},
    /*82  */ {color::chartreuse2      , "chartreuse2"     , 0x5f, 0xff, 0x00},
    /*83  */ {color::seagreen2        , "seagreen2"       , 0x5f, 0xff, 0x5f},
    /*84  */ {color::seagreen1        , "seagreen1"       , 0x5f, 0xff, 0x87},
    /*85  */ {color::seagreen4        , "seagreen4"       , 0x5f, 0xff, 0xaf},
    /*86  */ {color::aquamarine1      , "aquamarine1"     , 0x5f, 0xff, 0xd7},
    /*87  */ {color::darkslategray2   , "darkslategray2"  , 0x5f, 0xff, 0xff},
    /*88  */ {color::darkred2         , "darkred2"        , 0x87, 0x00, 0x00},
    /*89  */ {color::deeppink5        , "deeppink5"       , 0x87, 0x00, 0x5f},
    /*90  */ {color::darkmagenta      , "darkmagenta"     , 0x87, 0x00, 0x87},
    /*91  */ {color::darkmagenta2     , "darkmagenta2"    , 0x87, 0x00, 0xaf},
    /*92  */ {color::darkviolet       , "darkviolet"      , 0x87, 0x00, 0xd7},
    /*93  */ {color::purple2          , "purple2"         , 0x87, 0x00, 0xff},
    /*94  */ {color::orange5          , "orange5"         , 0x87, 0x5f, 0x00},
    /*95  */ {color::lightpink4       , "lightpink4"      , 0x87, 0x5f, 0x5f},
    /*96  */ {color::plum4            , "plum4"           , 0x87, 0x5f, 0x87},
    /*97  */ {color::mediumpurple3    , "mediumpurple3"   , 0x87, 0x5f, 0xaf},
    /*98  */ {color::mediumpurple5    , "mediumpurple5"   , 0x87, 0x5f, 0xd7},
    /*99  */ {color::slateblue1       , "slateblue1"      , 0x87, 0x5f, 0xff},
    /*100 */ {color::yellow4          , "yellow4"         , 0x87, 0x87, 0x00},
    /*101 */ {color::wheat4           , "wheat4"          , 0x87, 0x87, 0x5f},
    /*102 */ {color::grey53           , "grey53"          , 0x87, 0x87, 0x87},
    /*103 */ {color::lighcoreategrey  , "lighcoreategrey" , 0x87, 0x87, 0xaf},
    /*104 */ {color::mediumpurple     , "mediumpurple"    , 0x87, 0x87, 0xd7},
    /*105 */ {color::lighcoreateblue  , "lighcoreateblue" , 0x87, 0x87, 0xff},
    /*106 */ {color::yellow5          , "yellow5"         , 0x87, 0xaf, 0x00},
    /*107 */ {color::darkolivegreen3  , "darkolivegreen3" , 0x87, 0xaf, 0x5f},
    /*108 */ {color::darkseagreen     , "darkseagreen"    , 0x87, 0xaf, 0x87},
    /*109 */ {color::lightskyblue3    , "lightskyblue3"   , 0x87, 0xaf, 0xaf},
    /*110 */ {color::lightskyblue4    , "lightskyblue4"   , 0x87, 0xaf, 0xd7},
    /*111 */ {color::skyblue2         , "skyblue2"        , 0x87, 0xaf, 0xff},
    /*112 */ {color::chartreuse6      , "chartreuse6"     , 0x87, 0xd7, 0x00},
    /*113 */ {color::darkolivegreen4  , "darkolivegreen4" , 0x87, 0xd7, 0x5f},
    /*114 */ {color::palegreen4       , "palegreen4"      , 0x87, 0xd7, 0x87},
    /*115 */ {color::darkseagreen3    , "darkseagreen3"   , 0x87, 0xd7, 0xaf},
    /*116 */ {color::darkslategray3   , "darkslategray3"  , 0x87, 0xd7, 0xd7},
    /*117 */ {color::skyblue1         , "skyblue1"        , 0x87, 0xd7, 0xff},
    /*118 */ {color::chartreuse1      , "chartreuse1"     , 0x87, 0xff, 0x00},
    /*119 */ {color::lightgreen       , "lightgreen"      , 0x87, 0xff, 0x5f},
    /*120 */ {color::lightgreen2      , "lightgreen2"     , 0x87, 0xff, 0x87},
    /*121 */ {color::palegreen1       , "palegreen1"      , 0x87, 0xff, 0xaf},
    /*122 */ {color::aquamarine2      , "aquamarine2"     , 0x87, 0xff, 0xd7},
    /*123 */ {color::darkslategray1   , "darkslategray1"  , 0x87, 0xff, 0xff},
    /*124 */ {color::red3             , "red3"            , 0xaf, 0x00, 0x00},
    /*125 */ {color::deeppink6        , "deeppink6"       , 0xaf, 0x00, 0x5f},
    /*126 */ {color::mediumvioletred  , "mediumvioletred" , 0xaf, 0x00, 0x87},
    /*127 */ {color::magenta3         , "magenta3"        , 0xaf, 0x00, 0xaf},
    /*128 */ {color::darkviole2       , "darkviole2"      , 0xaf, 0x00, 0xd7},
    /*129 */ {color::purple6          , "purple6"         , 0xaf, 0x00, 0xff},
    /*130 */ {color::darkorange3      , "darkorange3"     , 0xaf, 0x5f, 0x00},
    /*131 */ {color::indianred        , "indianred"       , 0xaf, 0x5f, 0x5f},
    /*132 */ {color::hotpink3         , "hotpink3"        , 0xaf, 0x5f, 0x87},
    /*133 */ {color::mediumorchid3    , "mediumorchid3"   , 0xaf, 0x5f, 0xaf},
    /*134 */ {color::mediumorchid     , "mediumorchid"    , 0xaf, 0x5f, 0xd7},
    /*135 */ {color::mediumpurple2    , "mediumpurple2"   , 0xaf, 0x5f, 0xff},
    /*136 */ {color::darkgoldenrod    , "darkgoldenrod"   , 0xaf, 0x87, 0x00},
    /*137 */ {color::lightsalmon3     , "lightsalmon3"    , 0xaf, 0x87, 0x5f},
    /*138 */ {color::rosybrown        , "rosybrown"       , 0xaf, 0x87, 0x87},
    /*139 */ {color::grey63           , "grey63"          , 0xaf, 0x87, 0xaf},
    /*140 */ {color::mediumpurple6    , "mediumpurple6"   , 0xaf, 0x87, 0xd7},
    /*141 */ {color::mediumpurple1    , "mediumpurple1"   , 0xaf, 0x87, 0xff},
    /*142 */ {color::gold3            , "gold3"           , 0xaf, 0xaf, 0x00},
    /*143 */ {color::darkkhaki        , "darkkhaki"       , 0xaf, 0xaf, 0x5f},
    /*144 */ {color::navajowhite3     , "navajowhite3"    , 0xaf, 0xaf, 0x87},
    /*145 */ {color::grey69           , "grey69"          , 0xaf, 0xaf, 0xaf},
    /*146 */ {color::lightsteelblue3  , "lightsteelblue3" , 0xaf, 0xaf, 0xd7},
    /*147 */ {color::lightsteelblue   , "lightsteelblue"  , 0xaf, 0xaf, 0xff},
    /*148 */ {color::yellow3          , "yellow3"         , 0xaf, 0xd7, 0x00},
    /*149 */ {color::darkolivegreen5  , "darkolivegreen5" , 0xaf, 0xd7, 0x5f},
    /*150 */ {color::darkseagreen6    , "darkseagreen6"   , 0xaf, 0xd7, 0x87},
    /*151 */ {color::darkseagreen2    , "darkseagreen2"   , 0xaf, 0xd7, 0xaf},
    /*152 */ {color::lightcyan3       , "lightcyan3"      , 0xaf, 0xd7, 0xd7},
    /*153 */ {color::lightskyblue1    , "lightskyblue1"   , 0xaf, 0xd7, 0xff},
    /*154 */ {color::greenyellow      , "greenyellow"     , 0xaf, 0xff, 0x00},
    /*155 */ {color::darkolivegreen2  , "darkolivegreen2" , 0xaf, 0xff, 0x5f},
    /*156 */ {color::palegreen2       , "palegreen2"      , 0xaf, 0xff, 0x87},
    /*157 */ {color::darkseagreen7    , "darkseagreen7"   , 0xaf, 0xff, 0xaf},
    /*158 */ {color::darkseagreen1    , "darkseagreen1"   , 0xaf, 0xff, 0xd7},
    /*159 */ {color::paleturquoise    , "paleturquoise1"  , 0xaf, 0xff, 0xff},
    /*160 */ {color::red4             , "red4"            , 0xd7, 0x00, 0x00},
    /*161 */ {color::deeppink3        , "deeppink3"       , 0xd7, 0x00, 0x5f},
    /*162 */ {color::deeppink7        , "deeppink7"       , 0xd7, 0x00, 0x87},
    /*163 */ {color::magenta4         , "magenta4"        , 0xd7, 0x00, 0xaf},
    /*164 */ {color::magenta5         , "magenta5"        , 0xd7, 0x00, 0xd7},
    /*165 */ {color::magenta2         , "magenta2"        , 0xd7, 0x00, 0xff},
    /*166 */ {color::darkorange4      , "darkorange4"     , 0xd7, 0x5f, 0x00},
    /*167 */ {color::indianred2       , "indianred2"      , 0xd7, 0x5f, 0x5f},
    /*168 */ {color::hotpink4         , "hotpink4"        , 0xd7, 0x5f, 0x87},
    /*169 */ {color::hotpink2         , "hotpink2"        , 0xd7, 0x5f, 0xaf},
    /*170 */ {color::orchid           , "orchid"          , 0xd7, 0x5f, 0xd7},
    /*171 */ {color::mediumorchid1    , "mediumorchid1"   , 0xd7, 0x5f, 0xff},
    /*172 */ {color::orange3          , "orange3"         , 0xd7, 0x87, 0x00},
    /*173 */ {color::lightsalmon4     , "lightsalmon4"    , 0xd7, 0x87, 0x5f},
    /*174 */ {color::lightpink3       , "lightpink3"      , 0xd7, 0x87, 0x87},
    /*175 */ {color::pink3            , "pink3"           , 0xd7, 0x87, 0xaf},
    /*176 */ {color::plum3            , "plum3"           , 0xd7, 0x87, 0xd7},
    /*177 */ {color::violet           , "violet"          , 0xd7, 0x87, 0xff},
    /*178 */ {color::gold4            , "gold4"           , 0xd7, 0xaf, 0x00},
    /*179 */ {color::lightgoldenrod3  , "lightgoldenrod3" , 0xd7, 0xaf, 0x5f},
    /*180 */ {color::tan              , "tan"             , 0xd7, 0xaf, 0x87},
    /*181 */ {color::mistyrose3       , "mistyrose3"      , 0xd7, 0xaf, 0xaf},
    /*182 */ {color::thistle3         , "thistle3"        , 0xd7, 0xaf, 0xd7},
    /*183 */ {color::plum2            , "plum2"           , 0xd7, 0xaf, 0xff},
    /*184 */ {color::yellow6          , "yellow6"         , 0xd7, 0xd7, 0x00},
    /*185 */ {color::khaki3           , "khaki3"          , 0xd7, 0xd7, 0x5f},
    /*186 */ {color::lightgoldenrod2  , "lightgoldenrod2" , 0xd7, 0xd7, 0x87},
    /*187 */ {color::lightyellow3     , "lightyellow3"    , 0xd7, 0xd7, 0xaf},
    /*188 */ {color::grey84           , "grey84"          , 0xd7, 0xd7, 0xd7},
    /*189 */ {color::lightsteelblue1  , "lightsteelblue1" , 0xd7, 0xd7, 0xff},
    /*190 */ {color::yellow2          , "yellow2"         , 0xd7, 0xff, 0x00},
    /*191 */ {color::darkolivegreen1  , "darkolivegreen1" , 0xd7, 0xff, 0x5f},
    /*192 */ {color::darkolivegreen6  , "darkolivegreen6" , 0xd7, 0xff, 0x87},
    /*193 */ {color::darkseagreen8    , "darkseagreen8"   , 0xd7, 0xff, 0xaf},
    /*194 */ {color::honeydew2        , "honeydew2"       , 0xd7, 0xff, 0xd7},
    /*195 */ {color::lightcyan1       , "lightcyan1"      , 0xd7, 0xff, 0xff},
    /*196 */ {color::red1             , "red1"            , 0xff, 0x00, 0x00},
    /*197 */ {color::deeppink2        , "deeppink2"       , 0xff, 0x00, 0x5f},
    /*198 */ {color::deeppink1        , "deeppink1"       , 0xff, 0x00, 0x87},
    /*199 */ {color::deeppink8        , "deeppink8"       , 0xff, 0x00, 0xaf},
    /*200 */ {color::magenta6         , "magenta6"        , 0xff, 0x00, 0xd7},
    /*201 */ {color::magenta1         , "magenta1"        , 0xff, 0x00, 0xff},
    /*202 */ {color::orangered1       , "orangered1"      , 0xff, 0x5f, 0x00},
    /*203 */ {color::indianred1       , "indianred1"      , 0xff, 0x5f, 0x5f},
    /*204 */ {color::indianred3       , "indianred3"      , 0xff, 0x5f, 0x87},
    /*205 */ {color::hotpink          , "hotpink"         , 0xff, 0x5f, 0xaf},
    /*206 */ {color::hotpin2          , "hotpin2"         , 0xff, 0x5f, 0xd7},
    /*207 */ {color::mediumorchid2    , "mediumorchid2"   , 0xff, 0x5f, 0xff},
    /*208 */ {color::darkorange       , "darkorange"      , 0xff, 0x87, 0x00},
    /*209 */ {color::salmon1          , "salmon1"         , 0xff, 0x87, 0x5f},
    /*210 */ {color::lightcoral       , "lightcoral"      , 0xff, 0x87, 0x87},
    /*211 */ {color::palevioletred1   , "palevioletred1"  , 0xff, 0x87, 0xaf},
    /*212 */ {color::orchid2          , "orchid2"         , 0xff, 0x87, 0xd7},
    /*213 */ {color::orchid1          , "orchid1"         , 0xff, 0x87, 0xff},
    /*214 */ {color::orange1          , "orange1"         , 0xff, 0xaf, 0x00},
    /*215 */ {color::sandybrown       , "sandybrown"      , 0xff, 0xaf, 0x5f},
    /*216 */ {color::lightsalmon1     , "lightsalmon1"    , 0xff, 0xaf, 0x87},
    /*217 */ {color::lightpink1       , "lightpink1"      , 0xff, 0xaf, 0xaf},
    /*218 */ {color::pink1            , "pink1"           , 0xff, 0xaf, 0xd7},
    /*219 */ {color::plum1            , "plum1"           , 0xff, 0xaf, 0xff},
    /*220 */ {color::gold1            , "gold1"           , 0xff, 0xd7, 0x00},
    /*221 */ {color::lightgoldenrod4  , "lightgoldenrod4" , 0xff, 0xd7, 0x5f},
    /*222 */ {color::lightgoldenrod5  , "lightgoldenrod5" , 0xff, 0xd7, 0x87},
    /*223 */ {color::navajowhite1     , "navajowhite1"    , 0xff, 0xd7, 0xaf},
    /*224 */ {color::mistyrose1       , "mistyrose1"      , 0xff, 0xd7, 0xd7},
    /*225 */ {color::thistle1         , "thistle1"        , 0xff, 0xd7, 0xff},
    /*226 */ {color::yellow1          , "yellow1"         , 0xff, 0xff, 0x00},
    /*227 */ {color::lightgoldenrod1  , "lightgoldenrod1" , 0xff, 0xff, 0x5f},
    /*228 */ {color::khaki1           , "khaki1"          , 0xff, 0xff, 0x87},
    /*229 */ {color::wheat1           , "wheat1"          , 0xff, 0xff, 0xaf},
    /*230 */ {color::cornsilk1        , "cornsilk1"       , 0xff, 0xff, 0xd7},
    /*231 */ {color::grey100          , "grey100"         , 0xff, 0xff, 0xff},
    /*232 */ {color::grey3            , "grey3"           , 0x08, 0x08, 0x08},
    /*233 */ {color::grey7            , "grey7"           , 0x12, 0x12, 0x12},
    /*234 */ {color::grey11           , "grey11"          , 0x1c, 0x1c, 0x1c},
    /*235 */ {color::grey15           , "grey15"          , 0x26, 0x26, 0x26},
    /*236 */ {color::grey19           , "grey19"          , 0x30, 0x30, 0x30},
    /*237 */ {color::grey23           , "grey23"          , 0x3a, 0x3a, 0x3a},
    /*238 */ {color::grey27           , "grey27"          , 0x44, 0x44, 0x44},
    /*239 */ {color::grey30           , "grey30"          , 0x4e, 0x4e, 0x4e},
    /*240 */ {color::grey35           , "grey35"          , 0x58, 0x58, 0x58},
    /*241 */ {color::grey39           , "grey39"          , 0x62, 0x62, 0x62},
    /*242 */ {color::grey42           , "grey42"          , 0x6c, 0x6c, 0x6c},
    /*243 */ {color::grey46           , "grey46"          , 0x76, 0x76, 0x76},
    /*244 */ {color::grey50           , "grey50"          , 0x80, 0x80, 0x80},
    /*245 */ {color::grey54           , "grey54"          , 0x8a, 0x8a, 0x8a},
    /*246 */ {color::grey58           , "grey58"          , 0x94, 0x94, 0x94},
    /*247 */ {color::grey62           , "grey62"          , 0x9e, 0x9e, 0x9e},
    /*248 */ {color::grey66           , "grey66"          , 0xa8, 0xa8, 0xa8},
    /*249 */ {color::grey70           , "grey70"          , 0xb2, 0xb2, 0xb2},
    /*250 */ {color::grey74           , "grey74"          , 0xbc, 0xbc, 0xbc},
    /*251 */ {color::grey78           , "grey78"          , 0xc6, 0xc6, 0xc6},
    /*252 */ {color::grey82           , "grey82"          , 0xd0, 0xd0, 0xd0},
    /*253 */ {color::grey85           , "grey85"          , 0xda, 0xda, 0xda},
    /*254 */ {color::grey89           , "grey89"          , 0xe4, 0xe4, 0xe4},
    /*255 */ {color::reset            , "reset"           , 0   , 0   , 0},
};

/**
 * @brief Renders foreground color code in ansi encoding.
 *
 * @param a_fg
 * @return std::string
 */
std::string color::render(color::value a_fg)
{
    if(a_fg == color::reset)
        return "\x1b[39;49m";

    std::ostringstream txt;
    txt << "\033[38;5;" << static_cast<int>(a_fg) << 'm';
    return txt.str();
}


/**
 * @brief Renders foreground-background colors pair in ansi encoding.
 *
 * @param a_pair
 * @return std::string
 */
std::string color::render(color::pair a_pair)
{

    std::ostringstream txt;
    txt << "\x1b[";
    // ---------------- background ------------------------------------
    if(a_pair.bg == color::reset)
        txt << "49";
    else
        txt << "48;5;" << static_cast<int>(a_pair.bg);
    // ---------------- foreground ------------------------------------
    if(a_pair.fg == color::reset)
        txt << "39";
    else
        txt << "38;5;" << static_cast<int>(a_pair.fg);

    txt << "m";

    return txt.str();
}


/**
 * @brief Render foreground color in ansi-encoded rgb from color::code.
 *
 * @param a_code
 * @return std::string
 */
std::string color::render_rgb(color::value a_code)
{
    std::ostringstream txt;
    if (a_code == color::reset)
        return "\x1b[39;49m";
    else
        txt << "\x1b[38;2;";
    auto rgb_data  = color::colors_db[a_code];
    txt << rgb_data.R << ';' << rgb_data.G << ';' << rgb_data.B << 'm';
    return txt.str();
}


/**
 * @brief Render foreground and background color in ansi-encoded rgb from color::pair data.
 *
 * @param a_pair
 * @return std::string
 */
std::string color::render_rgb(color::pair a_pair)
{
    std::ostringstream txt;
    txt << "\x1b[";

    if (a_pair.fg == 255)
        txt << "39;";
    else
    {
        auto rgb_data  = color::colors_db[a_pair.fg];
        txt << "38;2;" << rgb_data.R << ';' << rgb_data.G << ';' << rgb_data.B << ';';
    }

    if (a_pair.bg == 255)
        txt << "49";
    else
    {
        auto rgb_data  = color::colors_db[a_pair.bg];
        txt << "48;2;" << rgb_data.R << ';' << rgb_data.G << ';' << rgb_data.B;
    }

    txt << 'm';
    return txt.str();
}

std::string color::render_background(color::value a_bg)
{
    if(a_bg == color::reset)
        return "\x1b[49m";
    std::ostringstream txt;
    txt << "\033[48;5;" << static_cast<int>(a_bg) << 'm';
    return txt.str();
}

std::string color::render_background_rgb(color::value a_code)
{
    std::ostringstream txt;
    if (a_code==color::z)
        return "\x1b[49m";
    txt << "\x1b[48;2;";
    auto rgb_data  = color::colors_db[a_code];

    txt << rgb_data.R << ';' << rgb_data.G << ';' << rgb_data.B << 'm';
    return txt.str();
}

color::value color::scan(const std::string &color_name)
{
    for( auto color_data : color::colors_db)
        if(color_data.color_name == color_name) return color_data.Enum;
    return color::reset;
}


std::string color::name(color::value a_code)
{
    for( auto color_data : color::colors_db)
        if(color_data.Enum == a_code) return std::string(color_data.color_name);
    return "color::reset";
}

std::string color::render_html(color::value a_code)
{
    return "not_implemented";
}

std::string color::render_html(color::pair a_pair)
{
    return "not_implemented";
}

color::data color::query_data(color::value a_code)
{
    for(auto color_data : color::colors_db)
        if(color_data.Enum == a_code) return color_data;
    return {};
}




//color::element nul_element{};



std::string color::pair::operator()() const
{
    return color::render_rgb(*this);
}

color::pair &color::pair::operator>>(std::string &out)
{
    out = color::render(*this);
    return  *this;
}


std::string color::pair::name() const
{
    std::ostringstream txt;
    txt << "[fg:" << color::name(fg) << " bg:" << color::name(bg) << ']';
    return txt.str();
}


// color::db::theme  color::db::themes=
// {
//     {
//         "default",
//         {
//             {
//                 "object",
//                 {
//                     {cpp::dom_status_enums::active, {color::grey100, color::grey27}},
//                     {cpp::dom_status_enums::disabled, {color::grey30, color::grey35}}, // keep coherence with widgets base
//                     {cpp::dom_status_enums::normal, {color::grey70, color::grey27}},
//                     {cpp::dom_status_enums::focussed, {color::red4, color::grey27}}
//                     //...
//                 }
//             },
//             {
//                 "frame",
//                 {
//                     {cpp::dom_status_enums::active, {color::lightcyan3, color::darkblue}},
//                     {cpp::dom_status_enums::disabled, {color::grey30, color::darkblue}}, // keep coherence with widgets base
//                     {cpp::dom_status_enums::normal, {color::grey100, color::darkblue}},
//                     {cpp::dom_status_enums::focussed, {color::greenyellow, color::darkblue}}
//                     //...
//                 }
//             },
//             {
//                 "label",
//                 {
//                     {cpp::dom_status_enums::active, {color::indianred, color::blue}},
//                     {cpp::dom_status_enums::disabled, {color::grey19, color::grey35}}, // keep coherence with widgets base
//                     {cpp::dom_status_enums::normal, {color::grey70, color::blue}}, // keep coherence with widgets base
//                     {cpp::dom_status_enums::focussed, {color::yellow, color::blue}}
//                 }
//             },
//             {
//                 "shortkey",
//                 {
//                     {cpp::dom_status_enums::active, {color::hotpink4, color::grey27}},
//                     {cpp::dom_status_enums::disabled, {color::grey19, color::grey35}}, // keep coherence with widgets base
//                     {cpp::dom_status_enums::normal, {color::grey70, color::grey27}},
//                     {cpp::dom_status_enums::focussed, {color::red4, color::grey27}}
//                 }
//             },
//             {
//                 "icon",
//                 {
//                     {cpp::dom_status_enums::active, {color::blue1, color::grey27}}, // keep coherence with widgets base
//                     {cpp::dom_status_enums::disabled, {color::grey19, color::grey35}},
//                     {cpp::dom_status_enums::normal, {color::blue1, color::grey35}},
//                     {cpp::dom_status_enums::focussed, {color::aquamarine3, color::grey27}},
//                     //{cat::widgets::dom_status_enums::success, {color::green5, color::grey27}}
//                 }
//             },
//             {
//                 "input-area", // widgets::text_input
//                 {
//                     {cpp::dom_status_enums::active, {color::white, color::grey30}}, // keep coherence with widgets base
//                     {cpp::dom_status_enums::disabled, {color::grey39, color::grey35}},
//                     {cpp::dom_status_enums::normal, {color::grey37, color::grey30}},
//                     {cpp::dom_status_enums::focussed, {color::white, color::grey30}}
//                 }
//             },
//             {
//                 "input-field",
//                 {
//                     {cpp::dom_status_enums::active, {color::grey70, color::grey27}}, // keep coherence with widgets base
//                     {cpp::dom_status_enums::disabled, {color::grey39, color::grey35}},
//                     {cpp::dom_status_enums::normal, {color::grey70, color::grey27}},
//                     {cpp::dom_status_enums::focussed, {color::white, color::grey27}}
//                 },
//             },
//             {
//                 "input-field:placeholder",
//                 {
//                     {cpp::dom_status_enums::active, {color::darkcyan, color::grey27}}, // keep coherence with widgets base
//                     {cpp::dom_status_enums::disabled, {color::blue, color::grey27}},
//                     {cpp::dom_status_enums::normal, {color::blue, color::grey27}},
//                     {cpp::dom_status_enums::focussed, {color::blue, color::grey27}}
//                 }
//             },
//             {
//                 "statusbar",
//                 {
//                     {cpp::dom_status_enums::active, {color::lime,      color::grey27}},
//                     {cpp::dom_status_enums::disabled, {color::grey30,   color::grey27}}, // keep coherence with widgets base
//                     {cpp::dom_status_enums::normal, {color::grey70,    color::grey27}},
//                     {cpp::dom_status_enums::focussed, {color::red4,       color::grey27}}
//                   //...
//                 }
//             }
//         }
//     },
//     {
//         "C64",
//         {
//             {
//                 "object",
//                 {
//                     {cpp::dom_status_enums::active, {color::darkturquoise, color::darkblue}},
//                     {cpp::dom_status_enums::disabled, {color::grey30, color::darkblue}}, // keep coherence with widgets base
//                     {cpp::dom_status_enums::normal, {color::grey70, color::darkblue}},
//                     {cpp::dom_status_enums::focussed, {color::red4, color::darkblue}}
//                     //...
//                 }
//             },
//             {
//                 "frame",
//                 {
//                     {cpp::dom_status_enums::active, {color::lightcyan3, color::darkblue}},
//                     {cpp::dom_status_enums::disabled, {color::grey30, color::darkblue}}, // keep coherence with widgets base
//                     {cpp::dom_status_enums::normal, {color::grey100, color::darkblue}},
//                     {cpp::dom_status_enums::focussed, {color::greenyellow, color::darkblue}}
//                     //...
//                 }
//             },
//             {
//                 "label",
//                 {
//                     {cpp::dom_status_enums::active, {color::lightcyan3, color::darkblue}},
//                     {cpp::dom_status_enums::disabled, {color::grey19, color::grey35}}, // keep coherence with widgets base
//                     {cpp::dom_status_enums::normal, {color::grey70, color::darkblue}}, // keep coherence with widgets base
//                     {cpp::dom_status_enums::focussed, {color::yellow, color::darkblue}}
//                 }
//             },
//             {
//                 "shortkey",
//                 {
//                     {cpp::dom_status_enums::active, {color::hotpink4, color::darkblue}},
//                     {cpp::dom_status_enums::disabled, {color::grey19, color::darkblue}}, // keep coherence with widgets base
//                     {cpp::dom_status_enums::normal, {color::grey70, color::darkblue}},
//                     {cpp::dom_status_enums::focussed, {color::red4, color::darkblue}}
//                 }
//             },
//             {
//                 "icon",
//                 {
//                     {cpp::dom_status_enums::active, {color::blue1, color::darkblue}}, // keep coherence with widgets base
//                     {cpp::dom_status_enums::disabled, {color::grey19, color::darkblue}},
//                     {cpp::dom_status_enums::normal, {color::blue1, color::darkblue}},
//                     {cpp::dom_status_enums::focussed, {color::aquamarine3, color::darkblue}},
//                     //{cat::widgets::dom_status_enums::success, {color::green5, color::darkblue}}
//                 }
//             },
//             {
//                 "input-area", // widgets::text_input
//                 {
//                     {cpp::dom_status_enums::active, {color::white, color::blue}}, // keep coherence with widgets base
//                     {cpp::dom_status_enums::disabled, {color::grey39, color::blue}},
//                     {cpp::dom_status_enums::normal, {color::grey37, color::blue}},
//                     {cpp::dom_status_enums::focussed, {color::white, color::blue}}
//                 }
//             },
//             {
//                 "input-field",
//                 {
//                     {cpp::dom_status_enums::active, {color::lightcyan3, color::blue4}}, // keep coherence with widgets base
//                     {cpp::dom_status_enums::disabled, {color::blue, color::darkblue}},
//                     {cpp::dom_status_enums::normal, {color::blue, color::darkblue}},
//                     {cpp::dom_status_enums::focussed, {color::blue, color::darkblue}}
//                 },
//
//             },
//             {
//                 "input-field:placeholder",
//                 {
//                     {cpp::dom_status_enums::active, {color::darkcyan, color::blue4}}, // keep coherence with widgets base
//                     {cpp::dom_status_enums::disabled, {color::blue, color::darkblue}},
//                     {cpp::dom_status_enums::normal, {color::blue, color::darkblue}},
//                     {cpp::dom_status_enums::focussed, {color::blue, color::darkblue}}
//                 },
//             },
//             {
//                 "statusbar",
//                 {
//                     {cpp::dom_status_enums::active, {color::lime, color::blue4}},
//                     {cpp::dom_status_enums::disabled, {color::grey30, color::blue4}}, // keep coherence with widgets base
//                     {cpp::dom_status_enums::normal, {color::grey70, color::blue4}},
//                     {cpp::dom_status_enums::focussed, {color::red4, color::blue4}}
//                       //...
//                 }
//             }
//         }
//     },
//     {
//         "C128",
//         {
//             {
//                 "object",
//                 {
//                     {cpp::dom_status_enums::active, {color::darkseagreen, color::grey15}},
//                     {cpp::dom_status_enums::disabled, {color::grey30, color::grey15}}, // keep coherence with widgets base
//                     {cpp::dom_status_enums::normal, {color::grey70, color::grey15}},
//                     {cpp::dom_status_enums::focussed, {color::red4, color::grey15}}
//                     //...
//                 }
//             },
//             {
//                 "frame",
//                 {
//                     {cpp::dom_status_enums::active, {color::darkseagreen, color::grey15}},
//                     {cpp::dom_status_enums::disabled, {color::grey30, color::grey15}}, // keep coherence with widgets base
//                     {cpp::dom_status_enums::normal, {color::lightcyan3, color::grey15}},
//                     {cpp::dom_status_enums::focussed, {color::greenyellow, color::grey15}}
//                     //...
//                 }
//             },
//             {
//                 "label",
//                 {
//                     {cpp::dom_status_enums::active, {color::darkseagreen4, color::grey15}},
//                     {cpp::dom_status_enums::disabled, {color::grey19, color::grey35}}, // keep coherence with widgets base
//                     {cpp::dom_status_enums::normal, {color::grey70, color::darkblue}}, // keep coherence with widgets base
//                     {cpp::dom_status_enums::focussed, {color::yellow, color::darkblue}}
//                 }
//             },
//             {
//                 "shortkey",
//                 {
//                     {cpp::dom_status_enums::active, {color::hotpink4, color::darkblue}},
//                     {cpp::dom_status_enums::disabled, {color::grey19, color::darkblue}}, // keep coherence with widgets base
//                     {cpp::dom_status_enums::normal, {color::grey70, color::darkblue}},
//                     {cpp::dom_status_enums::focussed, {color::red4, color::darkblue}}
//                 }
//             },
//             {
//                 "icon",
//                 {
//                     {cpp::dom_status_enums::active, {color::yellow3, color::darkblue}}, // keep coherence with widgets base
//                     {cpp::dom_status_enums::disabled, {color::grey19, color::darkblue}},
//                     {cpp::dom_status_enums::normal, {color::blue1, color::darkblue}},
//                     {cpp::dom_status_enums::focussed, {color::aquamarine3, color::darkblue}},
//                     //{cat::widgets::dom_status_enums::success, {color::green5, color::darkblue}}
//                 }
//             },
//             {
//                 "input-area", // widgets::text_input
//                 {
//                     {cpp::dom_status_enums::active, {color::darkseagreen, color::grey15}}, // keep coherence with widgets base
//                     {cpp::dom_status_enums::disabled, {color::darkseagreen, color::grey15}},
//                     {cpp::dom_status_enums::normal, {color::darkseagreen, color::grey15}},
//                     {cpp::dom_status_enums::focussed, {color::darkseagreen, color::grey15}}
//                 }
//             },
//             {
//                 "input-field",
//                 {
//                     {cpp::dom_status_enums::active, {color::darkseagreen, color::grey11}}, // keep coherence with widgets base
//                     {cpp::dom_status_enums::disabled, {color::darkseagreen, color::grey15}},
//                     {cpp::dom_status_enums::normal, {color::darkseagreen, color::grey15}},
//                     {cpp::dom_status_enums::focussed, {color::darkseagreen, color::grey15}}
//                 }
//             },
//             {
//                 "input-field:placeholder",
//                 {
//                     {cpp::dom_status_enums::active, {color::grey23, color::grey11}}, // keep coherence with widgets base
//                     {cpp::dom_status_enums::disabled, {color::darkseagreen, color::grey15}},
//                     {cpp::dom_status_enums::normal, {color::darkseagreen, color::grey15}},
//                     {cpp::dom_status_enums::focussed, {color::darkseagreen, color::grey15}}
//                 }
//             },
//             {
//                 "statusbar",
//                 {
//                     {cpp::dom_status_enums::active, {color::lime, color::grey15}},
//                     {cpp::dom_status_enums::disabled, {color::grey30, color::grey15}}, // keep coherence with widgets base
//                     {cpp::dom_status_enums::normal, {color::grey70, color::grey15}},
//                     {cpp::dom_status_enums::focussed, {color::red4, color::grey15}}
//                     //...
//                 }
//             }
//         }
//     },
//     {
//         "cat-latte",
//         {
//             {
//                 "object",
//                 {
//                     {cpp::dom_status_enums::active, {color::darkblue, color::grey85}},
//                     {cpp::dom_status_enums::disabled, {color::grey30, color::grey74}}, // keep coherence with widgets base
//                     {cpp::dom_status_enums::normal, {color::turquoise2, color::grey78}},
//                     {cpp::dom_status_enums::focussed, {color::darkblue, color::white}}
//                     //...
//                 }
//             },
//             {
//                 "frame",
//                 {
//                     {cpp::dom_status_enums::active, {color::lightcyan3, color::darkblue}},
//                     {cpp::dom_status_enums::disabled, {color::grey30, color::darkblue}}, // keep coherence with widgets base
//                     {cpp::dom_status_enums::normal, {color::grey100, color::darkblue}},
//                     {cpp::dom_status_enums::focussed, {color::greenyellow, color::darkblue}}
//                     //...
//                 }
//             },
//             {
//                 "label",
//                 {
//                     {cpp::dom_status_enums::active, {color::lightcyan3, color::darkblue}},
//                     {cpp::dom_status_enums::disabled, {color::grey19, color::grey35}}, // keep coherence with widgets base
//                     {cpp::dom_status_enums::normal, {color::grey70, color::darkblue}}, // keep coherence with widgets base
//                     {cpp::dom_status_enums::focussed, {color::yellow, color::darkblue}}
//                 }
//             },
//             {
//                 "shortkey",
//                 {
//                     {cpp::dom_status_enums::active, {color::hotpink4, color::darkblue}},
//                     {cpp::dom_status_enums::disabled, {color::grey19, color::darkblue}}, // keep coherence with widgets base
//                     {cpp::dom_status_enums::normal, {color::grey70, color::darkblue}},
//                     {cpp::dom_status_enums::focussed, {color::red4, color::darkblue}}
//                 }
//             },
//             {
//                 "icon",
//                 {
//                     {cpp::dom_status_enums::active, {color::blue1, color::darkblue}}, // keep coherence with widgets base
//                     {cpp::dom_status_enums::disabled, {color::grey19, color::darkblue}},
//                     {cpp::dom_status_enums::normal, {color::blue1, color::darkblue}},
//                     {cpp::dom_status_enums::focussed, {color::aquamarine3, color::darkblue}},
//                     //{cat::widgets::dom_status_enums::success, {color::green5, color::darkblue}}
//                 }
//             },
//             {
//                 "input-area", // widgets::text_input
//                 {
//                     {cpp::dom_status_enums::active, {color::white, color::blue}}, // keep coherence with widgets base
//                     {cpp::dom_status_enums::disabled, {color::grey39, color::blue}},
//                     {cpp::dom_status_enums::normal, {color::grey37, color::blue}},
//                     {cpp::dom_status_enums::focussed, {color::white, color::blue}}
//                 }
//             },
//             {
//                 "input-field",
//                 {
//                     {cpp::dom_status_enums::active, {color::lightcyan3, color::blue4}}, // keep coherence with widgets base
//                     {cpp::dom_status_enums::disabled, {color::blue, color::darkblue}},
//                     {cpp::dom_status_enums::normal, {color::blue, color::darkblue}},
//                     {cpp::dom_status_enums::focussed, {color::blue, color::darkblue}}
//                 },
//
//             },
//             {
//                 "input-field:placeholder",
//                 {
//                     {cpp::dom_status_enums::active, {color::darkcyan, color::blue4}}, // keep coherence with widgets base
//                     {cpp::dom_status_enums::disabled, {color::blue, color::darkblue}},
//                     {cpp::dom_status_enums::normal, {color::blue, color::darkblue}},
//                     {cpp::dom_status_enums::focussed, {color::blue, color::darkblue}}
//                 },
//             },
//             {
//                 "statusbar",
//                 {
//                     {cpp::dom_status_enums::active, {color::lime, color::blue4}},
//                     {cpp::dom_status_enums::disabled, {color::grey30, color::blue4}}, // keep coherence with widgets base
//                     {cpp::dom_status_enums::normal, {color::grey70, color::blue4}},
//                     {cpp::dom_status_enums::focussed, {color::red4, color::blue4}}
//                       //...
//                 }
//             }
//         }
//     }
// };
//
//
// /*!
//  *
//  * @param theme_name
//  * @return
//  * @todo check exist.
//  */
// color::db::palette& color::db::theme_palette(const std::string&theme_name)
// {
//     return themes[theme_name];
// }
//
//
// /*!
//  *
//  * @param theme_palette_data
//  * @param object_name
//  * @return reference to items
//  * @todo check exist.
//  */
// color::db::object_palette& color::db::palette_item(palette& theme_palette_data, const std::string&object_name)
// {
//     return theme_palette_data[object_name];
// }

}
