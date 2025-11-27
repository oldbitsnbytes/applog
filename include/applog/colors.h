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

#include <applog/ini.h>
#include <sstream>
#include <iomanip>
#include <vector>
#include <string>
#include <map>

namespace cpp 
{

 /**
  * @struct color
  * @brief Represents a collection of color codes based on an enumerated list of pre-defined named colors.
  *
  * This structure defines a set of color codes with corresponding RGB, HSL, and hex values. The colors are
  * represented as a scoped enumeration for better encapsulation and type safety.
  *
  * The color codes are mapped to commonly known named colors such as black, red, green, etc., and also include
  * variations like grey0, navyblue, deepskyblue, dodgerblue, springgreen, and many others.
  *
  * ### Color Representation:
  * Each color is provided with:
  * - A name (e.g., black, red, green, etc.)
  * - A hexadecimal color code (e.g., #000000 for black)
  * - RGB representation (e.g., rgb(0, 0, 0) for black)
  * - HSL representation (e.g., hsl(0, 0%, 0%) for black)
  *
  * ### Enum Details:
  * The `code` enum inside the `color` structure contains values of type `integers::U16` representing the color codes.
  * The enum values range from well-known primary, secondary, and tertiary colors to more specific shades and variants.
  *
  * ### Use Cases:
  * - Applied to any system requiring color representation by a standard palette.
  * - Useful in environments requiring assignment or comparison of color properties.
  * - Suited for terminal, graphical applications, and styling purposes.
  */
 struct  color {
    enum value : integers::U16 {
        /*0   */ black = 0,         //#000000	rgb(0,0,0)	hsl(0,100%,25%)
        /*1   */ maroon,            //#800000	rgb(128,0,0)	hsl(0,100%,25%)
        /*2   */ green,             //#008000	rgb(0,128,0)	hsl(120,100%,25%)
        /*3   */ olive,             //#808000	rgb(128,128,0)	hsl(60,100%,25%)
        /*4   */ navy,              //#000080	rgb(0,0,128)	hsl(240,100%,25%)
        /*5   */ purple,            //#800080	rgb(128,0,128)	hsl(300,100%,25%)
        /*6   */ cyan,              //#008080	rgb(0,128,128)	hsl(180,100%,25%)
        /*7   */ silver,            //#c0c0c0	rgb(192,192,192)	hsl(0,0%,75%)
        /*8   */ grey,              //#808080	rgb(128,128,128)	hsl(0,0%,50%)
        /*9   */ red,               //#ff0000	rgb(255,0,0)	hsl(0,100%,50%)
        /*10  */ lime,              //#00ff00	rgb(0,255,0)	hsl(120,100%,50%)
        /*11  */ yellow,            //#ffff00	rgb(255,255,0)	hsl(60,100%,50%)
        /*12  */ blue,              //#0000ff	rgb(0,0,255)	hsl(240,100%,50%)
        /*13  */ fuchsia,           //#ff00ff	rgb(255,0,255)	hsl(300,100%,50%)
        /*14  */ aqua,              //#00ffff	rgb(0,255,255)	hsl(180,100%,50%)
        /*15  */ white,             //#ffffff	rgb(255,255,255)	hsl(0,0%,100%)
        /*16  */ grey0,             //#000000	rgb(0,0,0)	hsl(0,0%,0%)
        /*17  */ navyblue,          //#00005f	rgb(0,0,95)	hsl(240,100%,18%)
        /*18  */ darkblue,          //#000087	rgb(0,0,135)	hsl(240,100%,26%)
        /*19  */ blue3,             //#0000af	rgb(0,0,175)	hsl(240,100%,34%)
        /*20  */ blue4,             //#0000d7	rgb(0,0,215)	hsl(240,100%,42%)
        /*21  */ blue1,             //#0000ff	rgb(0,0,255)	hsl(240,100%,50%)
        /*22  */ darkgreen,         //#005f00	rgb(0,95,0)	hsl(120,100%,18%)
        /*23  */ deepskyblue4,      //#005f5f	rgb(0,95,95)	hsl(180,100%,18%)
        /*24  */ deepskyblue5,      //#005f87	rgb(0,95,135)	hsl(97,100%,26%)
        /*25  */ deepskyblue6,      //#005faf	rgb(0,95,175)	hsl(07,100%,34%)
        /*26  */ dodgerblue3,       //#005fd7	rgb(0,95,215)	hsl(13,100%,42%)
        /*27  */ dodgerblue2,       //#005fff	rgb(0,95,255)	hsl(17,100%,50%)
        /*28  */ green4,            //#008700	rgb(0,135,0)	hsl(120,100%,26%)
        /*29  */ springgreen4,      //#00875f	rgb(0,135,95)	hsl(62,100%,26%)
        /*30  */ turquoise4,        //#008787	rgb(0,135,135)	hsl(180,100%,26%)
        /*31  */ deepskyblue3,      //#0087af	rgb(0,135,175)	hsl(93,100%,34%)
        /*32  */ deepskyblue7,      //#0087d7	rgb(0,135,215)	hsl(02,100%,42%)
        /*33  */ dodgerblue1,       //#0087ff	rgb(0,135,255)	hsl(08,100%,50%)
        /*34  */ green3,            //#00af00	rgb(0,175,0)	hsl(120,100%,34%)
        /*35  */ springgreen3,      //#00af5f	rgb(0,175,95)	hsl(52,100%,34%)
        /*36  */ darkcyan,          //#00af87	rgb(0,175,135)	hsl(66,100%,34%)
        /*37  */ lightseagreen,     //#00afaf	rgb(0,175,175)	hsl(180,100%,34%)
        /*38  */ deepskyblue2,      //#00afd7	rgb(0,175,215)	hsl(91,100%,42%)
        /*39  */ deepskyblue1,      //#00afff	rgb(0,175,255)	hsl(98,100%,50%)
        /*40  */ green5,            //#00d700	rgb(0,215,0)	hsl(120,100%,42%)
        /*41  */ springgreen5,      //#00d75f	rgb(0,215,95)	hsl(46,100%,42%)
        /*42  */ springgreen2,      //#00d787	rgb(0,215,135)	hsl(57,100%,42%)
        /*43  */ cyan3,             //#00d7af	rgb(0,215,175)	hsl(68,100%,42%)
        /*44  */ darkturquoise,     //#00d7d7	rgb(0,215,215)	hsl(180,100%,42%)
        /*45  */ turquoise2,        //#00d7ff	rgb(0,215,255)	hsl(89,100%,50%)
        /*46  */ green1,            //#00ff00	rgb(0,255,0)	hsl(120,100%,50%)
        /*47  */ springgreen6,      //#00ff5f	rgb(0,255,95)	hsl(42,100%,50%)
        /*48  */ springgreen1,      //#00ff87	rgb(0,255,135)	hsl(51,100%,50%)
        /*49  */ mediumspringgreen, //#00ffaf	rgb(0,255,175)	hsl(61,100%,50%)
        /*50  */ cyan2,             //#00ffd7	rgb(0,255,215)	hsl(70,100%,50%)
        /*51  */ cyan1,             //#00ffff	rgb(0,255,255)	hsl(180,100%,50%)
        /*52  */ darkred,           //#5f0000	rgb(95,0,0)	hsl(0,100%,18%)
        /*53  */ deeppink4,         //#5f005f	rgb(95,0,95)	hsl(300,100%,18%)
        /*54  */ purple4,           //#5f0087	rgb(95,0,135)	hsl(82,100%,26%)
        /*55  */ purple5,           //#5f00af	rgb(95,0,175)	hsl(72,100%,34%)
        /*56  */ purple3,           //#5f00d7	rgb(95,0,215)	hsl(66,100%,42%)
        /*57  */ blueviolet,        //#5f00ff	rgb(95,0,255)	hsl(62,100%,50%)
        /*58  */ orange4,           //#5f5f00	rgb(95,95,0)	hsl(60,100%,18%)
        /*59  */ grey37,            //#5f5f5f	rgb(95,95,95)	hsl(0,0%,37%)
        /*60  */ mediumpurple4,     //#5f5f87	rgb(95,95,135)	hsl(240,17%,45%)
        /*61  */ slateblue3,        //#5f5faf	rgb(95,95,175)	hsl(240,33%,52%)
        /*62  */ slateblue4,        //#5f5fd7	rgb(95,95,215)	hsl(240,60%,60%)
        /*63  */ royalblue1,        //#5f5fff	rgb(95,95,255)	hsl(240,100%,68%)
        /*64  */ chartreuse4,       //#5f8700	rgb(95,135,0)	hsl(7,100%,26%)
        /*65  */ darkseagreen4,     //#5f875f	rgb(95,135,95)	hsl(120,17%,45%)
        /*66  */ paleturquoise4,    //#5f8787	rgb(95,135,135)	hsl(180,17%,45%)
        /*67  */ steelblue,         //#5f87af	rgb(95,135,175)	hsl(210,33%,52%)
        /*68  */ steelblue3,        //#5f87d7	rgb(95,135,215)	hsl(220,60%,60%)
        /*69  */ cornflowerblue,    //#5f87ff	rgb(95,135,255)	hsl(225,100%,68%)
        /*70  */ chartreuse3,       //#5faf00	rgb(95,175,0)	hsl(7,100%,34%)
        /*71  */ darkseagreen5,     //#5faf5f	rgb(95,175,95)	hsl(120,33%,52%)
        /*72  */ cadetblue,         //#5faf87	rgb(95,175,135)	hsl(150,33%,52%)
        /*73  */ cadetblue2,        //#5fafaf	rgb(95,175,175)	hsl(180,33%,52%)
        /*74  */ skyblue3,          //#5fafd7	rgb(95,175,215)	hsl(200,60%,60%)
        /*75  */ steelblue1,        //#5fafff	rgb(95,175,255)	hsl(210,100%,68%)
        /*76  */ chartreuse5,       //#5fd700	rgb(95,215,0)	hsl(3,100%,42%)
        /*77  */ palegreen3,        //#5fd75f	rgb(95,215,95)	hsl(120,60%,60%)
        /*78  */ seagreen3,         //#5fd787	rgb(95,215,135)	hsl(140,60%,60%)
        /*79  */ aquamarine3,       //#5fd7af	rgb(95,215,175)	hsl(160,60%,60%)
        /*80  */ mediumturquoise,   //#5fd7d7	rgb(95,215,215)	hsl(180,60%,60%)
        /*81  */ steelblue4,        //#5fd7ff	rgb(95,215,255)	hsl(195,100%,68%)
        /*82  */ chartreuse2,       //#5fff00	rgb(95,255,0)	hsl(7,100%,50%)
        /*83  */ seagreen2,         //#5fff5f	rgb(95,255,95)	hsl(120,100%,68%)
        /*84  */ seagreen1,         //#5fff87	rgb(95,255,135)	hsl(135,100%,68%)
        /*85  */ seagreen4,         //#5fffaf	rgb(95,255,175)	hsl(150,100%,68%)
        /*86  */ aquamarine1,       //#5fffd7	rgb(95,255,215)	hsl(165,100%,68%)
        /*87  */ darkslategray2,    //#5fffff	rgb(95,255,255)	hsl(180,100%,68%)
        /*88  */ darkred2,          //#870000	rgb(135,0,0)	hsl(0,100%,26%)
        /*89  */ deeppink5,         //#87005f	rgb(135,0,95)	hsl(17,100%,26%)
        /*90  */ darkmagenta,       //#870087	rgb(135,0,135)	hsl(300,100%,26%)
        /*91  */ darkmagenta2,      //#8700af	rgb(135,0,175)	hsl(86,100%,34%)
        /*92  */ darkviolet,        //#8700d7	rgb(135,0,215)	hsl(77,100%,42%)
        /*93  */ purple2,           //#8700ff	rgb(135,0,255)	hsl(71,100%,50%)
        /*94  */ orange5,           //#875f00	rgb(135,95,0)	hsl(2,100%,26%)
        /*95  */ lightpink4,        //#875f5f	rgb(135,95,95)	hsl(0,17%,45%)
        /*96  */ plum4,             //#875f87	rgb(135,95,135)	hsl(300,17%,45%)
        /*97  */ mediumpurple3,     //#875faf	rgb(135,95,175)	hsl(270,33%,52%)
        /*98  */ mediumpurple5,     //#875fd7	rgb(135,95,215)	hsl(260,60%,60%)
        /*99  */ slateblue1,        //#875fff	rgb(135,95,255)	hsl(255,100%,68%)
        /*100 */ yellow4,           //#878700	rgb(135,135,0)	hsl(60,100%,26%)
        /*101 */ wheat4,            //#87875f	rgb(135,135,95)	hsl(60,17%,45%)
        /*102 */ grey53,            //#878787	rgb(135,135,135)	hsl(0,0%,52%)
        /*103 */ lighcoreategrey,    //#8787af	rgb(135,135,175)	hsl(240,20%,60%)
        /*104 */ mediumpurple,      //#8787d7	rgb(135,135,215)	hsl(240,50%,68%)
        /*105 */ lighcoreateblue,    //#8787ff	rgb(135,135,255)	hsl(240,100%,76%)
        /*106 */ yellow5,           //#87af00	rgb(135,175,0)	hsl(3,100%,34%)
        /*107 */ darkolivegreen3,   //#87af5f	rgb(135,175,95)	hsl(90,33%,52%)
        /*108 */ darkseagreen,      //#87af87	rgb(135,175,135)	hsl(120,20%,60%)
        /*109 */ lightskyblue3,     //#87afaf	rgb(135,175,175)	hsl(180,20%,60%)
        /*110 */ lightskyblue4,     //#87afd7	rgb(135,175,215)	hsl(210,50%,68%)
        /*111 */ skyblue2,          //#87afff	rgb(135,175,255)	hsl(220,100%,76%)
        /*112 */ chartreuse6,       //#87d700	rgb(135,215,0)	hsl(2,100%,42%)
        /*113 */ darkolivegreen4,   //#87d75f	rgb(135,215,95)	hsl(100,60%,60%)
        /*114 */ palegreen4,        //#87d787	rgb(135,215,135)	hsl(120,50%,68%)
        /*115 */ darkseagreen3,     //#87d7af	rgb(135,215,175)	hsl(150,50%,68%)
        /*116 */ darkslategray3,    //#87d7d7	rgb(135,215,215)	hsl(180,50%,68%)
        /*117 */ skyblue1,          //#87d7ff	rgb(135,215,255)	hsl(200,100%,76%)
        /*118 */ chartreuse1,       //#87ff00	rgb(135,255,0)	hsl(8,100%,50%)
        /*119 */ lightgreen,        //#87ff5f	rgb(135,255,95)	hsl(105,100%,68%)
        /*120 */ lightgreen2,       //#87ff87	rgb(135,255,135)	hsl(120,100%,76%)
        /*121 */ palegreen1,        //#87ffaf	rgb(135,255,175)	hsl(140,100%,76%)
        /*122 */ aquamarine2,       //#87ffd7	rgb(135,255,215)	hsl(160,100%,76%)
        /*123 */ darkslategray1,    //#87ffff	rgb(135,255,255)	hsl(180,100%,76%)
        /*124 */ red3,              //#af0000	rgb(175,0,0)	hsl(0,100%,34%)
        /*125 */ deeppink6,         //#af005f	rgb(175,0,95)	hsl(27,100%,34%)
        /*126 */ mediumvioletred,   //#af0087	rgb(175,0,135)	hsl(13,100%,34%)
        /*127 */ magenta3,          //#af00af	rgb(175,0,175)	hsl(300,100%,34%)
        /*128 */ darkviole2,        //#af00d7	rgb(175,0,215)	hsl(88,100%,42%)
        /*129 */ purple6,           //#af00ff	rgb(175,0,255)	hsl(81,100%,50%)
        /*130 */ darkorange3,       //#af5f00	rgb(175,95,0)	hsl(2,100%,34%)
        /*131 */ indianred,         //#af5f5f	rgb(175,95,95)	hsl(0,33%,52%)
        /*132 */ hotpink3,          //#af5f87	rgb(175,95,135)	hsl(330,33%,52%)
        /*133 */ mediumorchid3,     //#af5faf	rgb(175,95,175)	hsl(300,33%,52%)
        /*134 */ mediumorchid,      //#af5fd7	rgb(175,95,215)	hsl(280,60%,60%)
        /*135 */ mediumpurple2,     //#af5fff	rgb(175,95,255)	hsl(270,100%,68%)
        /*136 */ darkgoldenrod,     //#af8700	rgb(175,135,0)	hsl(6,100%,34%)
        /*137 */ lightsalmon3,      //#af875f	rgb(175,135,95)	hsl(30,33%,52%)
        /*138 */ rosybrown,         //#af8787	rgb(175,135,135)	hsl(0,20%,60%)
        /*139 */ grey63,            //#af87af	rgb(175,135,175)	hsl(300,20%,60%)
        /*140 */ mediumpurple6,     //#af87d7	rgb(175,135,215)	hsl(270,50%,68%)
        /*141 */ mediumpurple1,     //#af87ff	rgb(175,135,255)	hsl(260,100%,76%)
        /*142 */ gold3,             //#afaf00	rgb(175,175,0)	hsl(60,100%,34%)
        /*143 */ darkkhaki,         //#afaf5f	rgb(175,175,95)	hsl(60,33%,52%)
        /*144 */ navajowhite3,      //#afaf87	rgb(175,175,135)	hsl(60,20%,60%)
        /*145 */ grey69,            //#afafaf	rgb(175,175,175)	hsl(0,0%,68%)
        /*146 */ lightsteelblue3,   //#afafd7	rgb(175,175,215)	hsl(240,33%,76%)
        /*147 */ lightsteelblue,    //#afafff	rgb(175,175,255)	hsl(240,100%,84%)
        /*148 */ yellow3,           //#afd700	rgb(175,215,0)	hsl(1,100%,42%)
        /*149 */ darkolivegreen5,   //#afd75f	rgb(175,215,95)	hsl(80,60%,60%)
        /*150 */ darkseagreen6,     //#afd787	rgb(175,215,135)	hsl(90,50%,68%)
        /*151 */ darkseagreen2,     //#afd7af	rgb(175,215,175)	hsl(120,33%,76%)
        /*152 */ lightcyan3,        //#afd7d7	rgb(175,215,215)	hsl(180,33%,76%)
        /*153 */ lightskyblue1,     //#afd7ff	rgb(175,215,255)	hsl(210,100%,84%)
        /*154 */ greenyellow,       //#afff00	rgb(175,255,0)	hsl(8,100%,50%)
        /*155 */ darkolivegreen2,   //#afff5f	rgb(175,255,95)	hsl(90,100%,68%)
        /*156 */ palegreen2,        //#afff87	rgb(175,255,135)	hsl(100,100%,76%)
        /*157 */ darkseagreen7,     //#afffaf	rgb(175,255,175)	hsl(120,100%,84%)
        /*158 */ darkseagreen1,     //#afffd7	rgb(175,255,215)	hsl(150,100%,84%)
        /*159 */ paleturquoise,     //#afffff	rgb(175,255,255)	hsl(180,100%,84%)
        /*160 */ red4,              //#d70000	rgb(215,0,0)	hsl(0,100%,42%)
        /*161 */ deeppink3,         //#d7005f	rgb(215,0,95)	hsl(33,100%,42%)
        /*162 */ deeppink7,         //#d70087	rgb(215,0,135)	hsl(22,100%,42%)
        /*163 */ magenta4,          //#d700af	rgb(215,0,175)	hsl(11,100%,42%)
        /*164 */ magenta5,          //#d700d7	rgb(215,0,215)	hsl(300,100%,42%)
        /*165 */ magenta2,          //#d700ff	rgb(215,0,255)	hsl(90,100%,50%)
        /*166 */ darkorange4,       //#d75f00	rgb(215,95,0)	hsl(6,100%,42%)
        /*167 */ indianred2,        //#d75f5f	rgb(215,95,95)	hsl(0,60%,60%)
        /*168 */ hotpink4,          //#d75f87	rgb(215,95,135)	hsl(340,60%,60%)
        /*169 */ hotpink2,          //#d75faf	rgb(215,95,175)	hsl(320,60%,60%)
        /*170 */ orchid,            //#d75fd7	rgb(215,95,215)	hsl(300,60%,60%)
        /*171 */ mediumorchid1,     //#d75fff	rgb(215,95,255)	hsl(285,100%,68%)
        /*172 */ orange3,           //#d78700	rgb(215,135,0)	hsl(7,100%,42%)
        /*173 */ lightsalmon4,      //#d7875f	rgb(215,135,95)	hsl(20,60%,60%)
        /*174 */ lightpink3,        //#d78787	rgb(215,135,135)	hsl(0,50%,68%)
        /*175 */ pink3,             //#d787af	rgb(215,135,175)	hsl(330,50%,68%)
        /*176 */ plum3,             //#d787d7	rgb(215,135,215)	hsl(300,50%,68%)
        /*177 */ violet,            //#d787ff	rgb(215,135,255)	hsl(280,100%,76%)
        /*178 */ gold4,             //#d7af00	rgb(215,175,0)	hsl(8,100%,42%)
        /*179 */ lightgoldenrod3,   //#d7af5f	rgb(215,175,95)	hsl(40,60%,60%)
        /*180 */ tan,               //#d7af87	rgb(215,175,135)	hsl(30,50%,68%)
        /*181 */ mistyrose3,        //#d7afaf	rgb(215,175,175)	hsl(0,33%,76%)
        /*182 */ thistle3,          //#d7afd7	rgb(215,175,215)	hsl(300,33%,76%)
        /*183 */ plum2,             //#d7afff	rgb(215,175,255)	hsl(270,100%,84%)
        /*184 */ yellow6,           //#d7d700	rgb(215,215,0)	hsl(60,100%,42%)
        /*185 */ khaki3,            //#d7d75f	rgb(215,215,95)	hsl(60,60%,60%)
        /*186 */ lightgoldenrod2,   //#d7d787	rgb(215,215,135)	hsl(60,50%,68%)
        /*187 */ lightyellow3,      //#d7d7af	rgb(215,215,175)	hsl(60,33%,76%)
        /*188 */ grey84,            //#d7d7d7	rgb(215,215,215)	hsl(0,0%,84%)
        /*189 */ lightsteelblue1,   //#d7d7ff	rgb(215,215,255)	hsl(240,100%,92%)
        /*190 */ yellow2,           //#d7ff00	rgb(215,255,0)	hsl(9,100%,50%)
        /*191 */ darkolivegreen1,   //#d7ff5f	rgb(215,255,95)	hsl(75,100%,68%)
        /*192 */ darkolivegreen6,   //#d7ff87	rgb(215,255,135)	hsl(80,100%,76%)
        /*193 */ darkseagreen8,     //#d7ffaf	rgb(215,255,175)	hsl(90,100%,84%)
        /*194 */ honeydew2,         //#d7ffd7	rgb(215,255,215)	hsl(120,100%,92%)
        /*195 */ lightcyan1,        //#d7ffff	rgb(215,255,255)	hsl(180,100%,92%)
        /*196 */ red1,              //#ff0000	rgb(255,0,0)	hsl(0,100%,50%)
        /*197 */ deeppink2,         //#ff005f	rgb(255,0,95)	hsl(37,100%,50%)
        /*198 */ deeppink1,         //#ff0087	rgb(255,0,135)	hsl(28,100%,50%)
        /*199 */ deeppink8,         //#ff00af	rgb(255,0,175)	hsl(18,100%,50%)
        /*200 */ magenta6,          //#ff00d7	rgb(255,0,215)	hsl(09,100%,50%)
        /*201 */ magenta1,          //#ff00ff	rgb(255,0,255)	hsl(300,100%,50%)
        /*202 */ orangered1,        //#ff5f00	rgb(255,95,0)	hsl(2,100%,50%)
        /*203 */ indianred1,        //#ff5f5f	rgb(255,95,95)	hsl(0,100%,68%)
        /*204 */ indianred3,        //#ff5f87	rgb(255,95,135)	hsl(345,100%,68%)
        /*205 */ hotpink,           //#ff5faf	rgb(255,95,175)	hsl(330,100%,68%)
        /*206 */ hotpin2,           //#ff5fd7	rgb(255,95,215)	hsl(315,100%,68%)
        /*207 */ mediumorchid2,     //#ff5fff	rgb(255,95,255)	hsl(300,100%,68%)
        /*208 */ darkorange,        //#ff8700	rgb(255,135,0)	hsl(1,100%,50%)
        /*209 */ salmon1,           //#ff875f	rgb(255,135,95)	hsl(15,100%,68%)
        /*210 */ lightcoral,        //#ff8787	rgb(255,135,135)	hsl(0,100%,76%)
        /*211 */ palevioletred1,    //#ff87af	rgb(255,135,175)	hsl(340,100%,76%)
        /*212 */ orchid2,           //#ff87d7	rgb(255,135,215)	hsl(320,100%,76%)
        /*213 */ orchid1,           //#ff87ff	rgb(255,135,255)	hsl(300,100%,76%)
        /*214 */ orange1,           //#ffaf00	rgb(255,175,0)	hsl(1,100%,50%)
        /*215 */ sandybrown,        //#ffaf5f	rgb(255,175,95)	hsl(30,100%,68%)
        /*216 */ lightsalmon1,      //#ffaf87	rgb(255,175,135)	hsl(20,100%,76%)
        /*217 */ lightpink1,        //#ffafaf	rgb(255,175,175)	hsl(0,100%,84%)
        /*218 */ pink1,             //#ffafd7	rgb(255,175,215)	hsl(330,100%,84%)
        /*219 */ plum1,             //#ffafff	rgb(255,175,255)	hsl(300,100%,84%)
        /*220 */ gold1,             //#ffd700	rgb(255,215,0)	hsl(0,100%,50%)
        /*221 */ lightgoldenrod4,   //#ffd75f	rgb(255,215,95)	hsl(45,100%,68%)
        /*222 */ lightgoldenrod5,   //#ffd787	rgb(255,215,135)	hsl(40,100%,76%)
        /*223 */ navajowhite1,      //#ffd7af	rgb(255,215,175)	hsl(30,100%,84%)
        /*224 */ mistyrose1,        //#ffd7d7	rgb(255,215,215)	hsl(0,100%,92%)
        /*225 */ thistle1,          //#ffd7ff	rgb(255,215,255)	hsl(300,100%,92%)
        /*226 */ yellow1,           //#ffff00	rgb(255,255,0)	hsl(60,100%,50%)
        /*227 */ lightgoldenrod1,   //#ffff5f	rgb(255,255,95)	hsl(60,100%,68%)
        /*228 */ khaki1,            //#ffff87	rgb(255,255,135)	hsl(60,100%,76%)
        /*229 */ wheat1,            //#ffffaf	rgb(255,255,175)	hsl(60,100%,84%)
        /*230 */ cornsilk1,         //#ffffd7	rgb(255,255,215)	hsl(60,100%,92%)
        /*231 */ grey100,           //#ffffff	rgb(255,255,255)	hsl(0,0%,100%)
        /*232 */ grey3,             //#080808	rgb(8,8,8)	hsl(0,0%,3%)
        /*233 */ grey7,             //#121212	rgb(18,18,18)	hsl(0,0%,7%)
        /*234 */ grey11,            //#1c1c1c	rgb(28,28,28)	hsl(0,0%,10%)
        /*235 */ grey15,            //#262626	rgb(38,38,38)
        /*236 */ grey19,            //#303030	rgb(48,48,48)	hsl(0,0%,18%)
        /*237 */ grey23,            //#3a3a3a	rgb(58,58,58)	hsl(0,0%,22%)
        /*238 */ grey27,            //#444444	rgb(68,68,68)	hsl(0,0%,26%)
        /*239 */ grey30,            //#4e4e4e	rgb(78,78,78)	hsl(0,0%,30%)
        /*240 */ grey35,            //#585858	rgb(88,88,88)	hsl(0,0%,34%)
        /*241 */ grey39,            //#626262	rgb(98,98,98)	hsl(0,0%,37%)
        /*242 */ grey42,            //#6c6c6c	rgb(108,108,108)	hsl(0,0%,40%)
        /*243 */ grey46,            //#767676	rgb(118,118,118)	hsl(0,0%,46%)
        /*244 */ grey50,            //#808080	rgb(128,128,128)	hsl(0,0%,50%)
        /*245 */ grey54,            //#8a8a8a	rgb(138,138,138)	hsl(0,0%,54%)
        /*246 */ grey58,            //#949494	rgb(148,148,148)	hsl(0,0%,58%)
        /*247 */ grey62,            //#9e9e9e	rgb(158,158,158)	hsl(0,0%,61%)
        /*248 */ grey66,            //#a8a8a8	rgb(168,168,168)	hsl(0,0%,65%)
        /*249 */ grey70,            //#b2b2b2	rgb(178,178,178)	hsl(0,0%,69%)
        /*250 */ grey74,            //#bcbcbc	rgb(188,188,188)	hsl(0,0%,73%)
        /*251 */ grey78,            //#c6c6c6	rgb(198,198,198)	hsl(0,0%,77%)
        /*252 */ grey82,            //#d0d0d0	rgb(208,208,208)	hsl(0,0%,81%)
        /*253 */ grey85,            //#dadada	rgb(218,218,218)	hsl(0,0%,85%)
        /*254 */ grey89,            //#e4e4e4	rgb(235,235,235)	hsl(0,0%,89%)
        /*255 */ reset,
        /*255 */ r = 255,
        /*255 */ z = 255                 // final enum, same as color::reset;
    };

    struct  pair
    {
        color::value fg = color::white;
        color::value bg = color::grey11;

        std::string operator()() const;
        color::pair &operator>>(std::string &out);
        std::string name() const;
    };

    struct  data
    {
        color::value Enum = color::reset;
        std::string_view color_name = " ";
        int R = 0;
        int G = 0;
        int B = 0;
    };
    static std::vector<color::data> colors_db;
    enum class encoding_format_t {
        render256, html
    };

    static std::string render(color::value a_fg);
    static std::string render(color::pair a_pair);
    static std::string render_rgb(color::value a_code);
    static std::string render_rgb(color::pair a_pair);
    static std::string render_background(color::value a_bg);
    static std::string render_background_rgb(color::value a_bg);
    static color::value scan(const std::string &color_name);
    static std::string name(color::value a_code);
    static std::string render_html(color::value a_code);
    static std::string render_html(color::pair a_pair);
    static color::data query_data(color::value a_code);

    struct db
    {
        using object_palette = std::map<int, color::pair>;
        using palette = std::map<std::string, object_palette>;
        using theme = std::map<std::string, palette>;


        static db::palette& theme_palette(const std::string& theme_name);
        static db::object_palette& palette_item(palette& theme_palette_data, const std::string& object_name);


        static theme themes;

    };

}; // struct Color


} // cat
