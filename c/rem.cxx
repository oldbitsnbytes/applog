#include <map>
#include <applog/rem.h>





/**
 * Checks whether a given `rem::code` status code represents a state that is neither successful nor completed.
 *
 * This operator negates a `rem::code` value and evaluates to `true` if the value is not one of the following:
 * - `rem::code::accepted`
 * - `rem::code::ok`
 * - `rem::code::success`
 * - `rem::code::done`
 * - `rem::code::ready`
 * - `rem::code::finish`
 * - `rem::code::complete`
 * - `rem::code::found`
 * Otherwise, it returns `false`.
 *
 * @param c The status code of type `rem::code` to be evaluated.
 * @return `true` if the status code is not one of the successful or completed states, `false` otherwise.
 */
bool operator !(rem::code c)
{
    return (c != rem::code::accepted)&&
           (c != rem::code::ok)      &&
           (c != rem::code::success) &&
           (c != rem::code::done)    &&
           (c != rem::code::ready)   &&
           (c != rem::code::finish)  &&
           (c != rem::code::complete)&&
           (c != rem::code::found)   &&
           (c != rem::code::applied) &&
           (c != rem::code::notapplicable) &&
           (c != rem::code::exist)   &&
           (c != rem::code::applied) &&
           (c != rem::code::valid);
}







namespace rem
{


/**
 * A dictionary mapping `rem::type` enumerations to their corresponding string representations.
 *
 * This `std::map` provides a convenient way to associate human-readable descriptions with
 * the enumeration values defined in `rem::type`. It can be used for logging, debugging,
 * or displaying user-friendly status messages.
 *
 * Each key in the dictionary is an enumeration value from `rem::type`, and the associated value
 * is a constant character pointer containing the string representation of that enumeration.
 *
 * Example mappings include:
 * - `rem::type::none` -> "none"
 * - `rem::type::err` -> "err"
 * - `rem::type::fatal` -> "fatal"
 * - `rem::type::syntax` -> "syntax error"
 * - `rem::type::segfault` -> "segmentation fault"
 *
 * Enumerations in `rem::type`, which do not have an explicit description, are mapped to an
 * empty string (e.g., `rem::type::output`).
 */
std::map<rem::type, const char*> enums_type_dictionary = {
    {rem::type::none,        "none"},
    {rem::type::err  ,       "error"},
    {rem::type::warning,     "warning"},
    {rem::type::fatal,       "fatal"},
    {rem::type::except,      "exception"},
    {rem::type::message,     "message"},
    {rem::type::output,      ""},
    {rem::type::debug,       "debug"},
    {rem::type::info,        "info"},
    {rem::type::comment,     "comment"},
    {rem::type::syntax,      "syntax error"},
    {rem::type::status,      "status"},
    {rem::type::test,        "test"},
    {rem::type::interrupted, "interrupted"},
    {rem::type::aborted,     "aborted"},
    {rem::type::segfault,    "segmentation fault"},
    {rem::type::book,         "log"},
    {rem::type::normal,       "normal"},
    {rem::type::grace,        "gracefully terminated/done/clean."}
};

/**
 * A dictionary that maps `rem::code` status codes to their corresponding string representations.
 *
 * This `std::map` serves as a look-up table where each key is a `rem::code` enumeration value
 * and the associated value is a constant character pointer providing a human-readable description
 * of the respective status code. It can be used for debugging, logging, or displaying error or
 * status messages to the user.
 *
 * The keys represent various status codes defined in the `rem::code` namespace, such as:
 * - `rem::code::ok`: Represents a successful operation.
 * - `rem::code::accepted`: Indicates that an operation was accepted.
 * - `rem::code::timeout`: Signifies that an operation exceeded the allowed time limit.
 * - `rem::code::syntax_error`: Represents a syntax error.
 *
 * The corresponding string values are concise descriptions of these status codes, for example:
 * - `"ok"`
 * - `"accepted"`
 * - `"timeout"`
 * - `"syntax error"`
 *
 * This dictionary provides an efficient way to obtain descriptive strings for `rem::code` values
 * for purposes such as error reporting, message generation, or status monitoring.
 */
std::map<rem::code, const char*> return_codes_dictionary = {
    {rem::code::ok,               "ok"},
    {rem::code::accepted,         "accepted"},
    {rem::code::success,          "success "},
    {rem::code::rejected,         "rejected"},
    {rem::code::failed,           "failed"},
    {rem::code::empty,            "empty"},
    {rem::code::full,             "full"},
    {rem::code::notempty,         "not empty"},
    {rem::code::implemented,      "implemented"},
    {rem::code::notimplemented,   "not implemented"},
    {rem::code::untested,         "untested"},
    {rem::code::eof,              "end of file"},
    {rem::code::eos,              "end of stream or string"},
    {rem::code::null_ptr,         "null pointer"},
    {rem::code::notexist,         "does not exist"},
    {rem::code::exist,            "exist"},
    {rem::code::unexpected,       "unexpected"},
    {rem::code::expected,         "expected"},
    {rem::code::blocked,          "blocked"},
    {rem::code::locked,           "locked"},
    {rem::code::overflow,         "buffer overflow"},
    {rem::code::oob,              "out of boundaries"},
    {rem::code::reimplement,      "need to be re-implemented in derived instances"},
    {rem::code::done,             "done"},
    {rem::code::complete,         "completed"},
    {rem::code::finish,           "finished"},
    {rem::code::undefined,        "undefined"},
    {rem::code::ready,            "ready"},
    {rem::code::terminate,        "terminate"},
    {rem::code::timeout,          "timeout"},
    {rem::code::divbyzero,        "division by zero"},
    {rem::code::notvisible,       "not visible"},
    {rem::code::cancel,           "cancel"},
    {rem::code::object_ptr,       "pointer to object"},
    {rem::code::object_id,        "object id"},
    {rem::code::unhandled,        "unhandled"},
    {rem::code::notready,         "not ready"},
    {rem::code::notfound,         "not found"},
    {rem::code::found,            "found"},
    {rem::code::dismissed,        "dismissed"},
    {rem::code::syntax_error,     "syntax error"},
    {rem::code::applied,          "applied"},
    {rem::code::notapplicable,    "not applicable"},
    {rem::code::valid,            "valid"},
    {rem::code::invalid,          "invalid"}
};

/**
 * A dictionary that maps `rem::action` enumeration values to their respective string representations.
 *
 * This `std::map` provides a convenient mapping between the values defined in the
 * `rem::action` enum and their human-readable representations as constant character strings.
 * It is useful for debugging, logging, or displaying descriptive labels for actions.
 *
 * Each key in the dictionary corresponds to an `rem::action` enumeration value, and the associated
 * value is a string that describes the action. The mappings provided include:
 * - `rem::action::enter`: "enter"
 * - `rem::action::leave`: "leave"
 * - `rem::action::begin`: "begin"
 * - `rem::action::end`: "end"
 * - `rem::action::commit`: "commit"
 * - `rem::action::cont`: "continue"
 * - `rem::action::dismiss`: "dismissed"
 *
 * This mapping can be leveraged to convert `rem::action` values into readable strings
 * for message generation, output descriptions, or status reporting.
 */
std::map<rem::action, const char*> actions_dictionary= {
    {rem::action::enter,   "enter"},
    {rem::action::leave,   "leave"},
    {rem::action::begin,   "begin"},
    {rem::action::end,     "end"},
    {rem::action::commit,  "commit"},
    {rem::action::cont,    "continue"},
    {rem::action::dismiss, "dismissed"},
};

/**
 * A dictionary that maps `rem::fn` enumeration values to their corresponding string representations.
 *
 * This `std::map` provides a convenient way to associate enumeration values from `rem::fn` with
 * human-readable descriptions, which can be used for debugging, logging, or displaying descriptive outputs.
 *
 * The keys in this dictionary are `rem::fn` enumeration values representing time, date, or code-related
 * elements, while the associated values are constant character pointers describing the respective enumeration.
 *
 * Example mappings include:
 * - `rem::fn::eol` -> "end line"
 * - `rem::fn::file` -> "file"
 * - `rem::fn::hour` -> "hour"
 * - `rem::fn::dayname` -> "day name"
 * - `rem::fn::year` -> "year"
 *
 * This dictionary facilitates efficient conversion of `rem::fn` enumeration values to concise,
 * readable string descriptions useful for various textual outputs or representations.
 */
std::map<rem::fn, const char*> functions_dictionary= {

    {rem::fn::eol,           "end line"},
    {rem::fn::func,            "function"},
    {rem::fn::file,           "file"},
    {rem::fn::line,           "line"},
    {rem::fn::stamp,          "stamp"},
    {rem::fn::hour,           "hour"},
    {rem::fn::minute,         "minute"},
    {rem::fn::seconds,        "seconds"},
    {rem::fn::weekday,        "weekday"},
    {rem::fn::month,          "month name"},
    {rem::fn::dayname,        "day name"},
    {rem::fn::day,            "day"},
    {rem::fn::monthnum,       "month number"},
    {rem::fn::year,           "year"}
};





/**
 * A database mapping specific types of `rem::type` to their corresponding glyph representation
 * and associated color pair.
 *
 * Each entry in the map represents a `rem::type` that is paired with a `glyph::type`
 * and a `color::pair` to define the visual rendering for that type in terms of both glyph
 * iconography and color styling.
 *
 * This database serves as the primary lookup table for determining how a given `rem::type`
 * should be visually represented and color-coded. The design allows for standardized
 * appearance of messages, states, or objects across the application, ensuring intuitive
 * and consistent user interaction.
 *
 * Key components:
 * - `rem::type`: The enumeration of types that define different application states or messages.
 * - `glyph::type`: The glyph or icon associated with the respective `rem::type`.
 * - `color::pair`: A pair of colors defining the foreground and background for visual styling.
 *
 * The entries include, but are not limited to:
 * - `rem::type::none`: Represents no specific type, associated with a computer glyph and aquamarine1 color.
 * - `rem::type::err`: Indicates an error state, rendered with an error glyph and red coloring.
 * - `rem::type::fatal`: Represents a fatal error state, using a dead_head glyph with hotpink4 color.
 * - `rem::type::message`: Corresponds to a standard message, displayed with a comment glyph and green4 color.
 *
 * This map can be expanded or modified to support additional `rem::type` values and their
 * corresponding glyphs and colors as needed.
 */
std::map<rem::type, std::pair<cpp::glyph::value, color::pair>> types_database={

    {rem::type::none,        {glyph::computer,  {color::aquamarine1         , color::reset }}},
    {rem::type::err,         {glyph::err1,      {color::red4                , color::reset }}},
    {rem::type::warning,     {glyph::warning,   {color::yellow              , color::reset }}},
    {rem::type::fatal,       {glyph::dead_head, {color::hotpink4            , color::reset }}},
    {rem::type::except,      {glyph::bolt,      {color::skyblue3            , color::reset }}},
    {rem::type::message,     {glyph::comment,   {color::green4              , color::reset }}},
    {rem::type::output,      {glyph::notepad,   {color::grey39              , color::reset }}},
    {rem::type::debug,       {glyph::bug,       {color::pink3               , color::reset }}},
    {rem::type::info,        {glyph::info,      {color::lightskyblue4       , color::reset }}},
    {rem::type::comment,     {glyph::comment,   {color::grey42              , color::reset }}},
    {rem::type::syntax,      {glyph::handwrite, {color::lighcoreateblue     , color::reset }}},
    {rem::type::status,      {glyph::admin,     {color::lightcyan3          , color::reset }}},
    {rem::type::test,        {glyph::file,      {color::aquamarine3         , color::reset }}},
    {rem::type::interrupted, {glyph::circle_x,  {color::khaki3              , color::reset }}},
    {rem::type::aborted,     {glyph::stop,      {color::red4                , color::reset }}},
    {rem::type::segfault,    {glyph::bomb,      {color::sandybrown          , color::reset }}},
    {rem::type::book,        {glyph::book,      {color::orangered1          , color::reset }}},
    {rem::type::normal,      {glyph::school,    {color::orangered1          , color::reset }}},
    {rem::type::grace,       {glyph::school,    {color::lime                , color::reset }}}
    //...
};

/**
 * A mapping between `rem::action` types and their corresponding visual representations,
 * including graphical glyphs and associated color pairs.
 *
 * This database provides a visualization framework for `rem::action` codes, specifying:
 * - A glyph (`glyph::type`) symbolizing the action.
 * - A color pair (`color::pair`) that defines the foreground and background colors.
 *
 * Entries in the map pair a specific action type with its designated glyph and color. The
 * visual representation aids in the interpretation of actions for user interface or logging systems.
 *
 * Keys:
 * - `rem::action`: Represents the type of action (e.g., `enter`, `leave`, `begin`, etc.).
 *
 * Values:
 * - A pair consisting of:
 *   - A `glyph::type` representing a visual symbol for the action.
 *   - A `color::pair` specifying the display colors, with the foreground color followed by
 *     the background reset color.
 *
 * Example mappings:
 * - `rem::action::enter` maps to `{glyph::enter, {color::white, color::reset}}`.
 * - `rem::action::dismiss` maps to `{glyph::arrow_dhead_right, {color::yellow, color::reset}}`.
 */
std::map<rem::action      , std::pair<glyph::value, color::pair>> actions_color_db = {
    {rem::action::enter   , {glyph::enter        , {color::white               , color::reset}}},
    {rem::action::leave   , {glyph::file         , {color::white               , color::reset}}},
    {rem::action::begin   , {glyph::chronos      , {color::white               , color::reset}}},
    {rem::action::end     , {glyph::dead_head    , {color::white               , color::reset}}},
    {rem::action::commit  , {glyph::pencil_dr    , {color::white               , color::reset}}},
    {rem::action::cont    , {glyph::success      , {color::white               , color::reset}}},
    {rem::action::dismiss , {glyph::arrow_dhead_right , {color::yellow         , color::reset}}},
};


/**
 * A database mapping status codes (`rem::code`) to their corresponding visual representations.
 *
 * This variable, `codes_database`, associates each `rem::code` status code with a pair comprising:
 * - A glyph (`glyph::type`) representing the status visually.
 * - A pair of colors (`color::pair`) that define the foreground and background context for the glyph.
 *
 * Each entry in the map represents a unique status code with its corresponding glyph and color association,
 * providing a consistent way to visually interpret status codes in user interfaces or log outputs.
 */
std::map<rem::code, std::pair<glyph::value, color::pair>> codes_database={
    {rem::code::ok,              {glyph::thumb_up,        {color::lime              ,color::reset }}},
    {rem::code::accepted,        {glyph::thumb_up,        {color::lime              ,color::reset }}},
    {rem::code::success,         {glyph::success,         {color::darkgreen         ,color::reset }}},
    {rem::code::rejected,        {glyph::thumb_down,      {color::hotpink4          ,color::reset }}},
    {rem::code::failed,          {glyph::poop,            {color::darkgoldenrod     ,color::reset }}},
    {rem::code::empty,           {glyph::arrowright,      {color::lighcoreategrey   ,color::reset }}},
    {rem::code::full,            {glyph::small_dot,       {color::white             ,color::reset }}},
    {rem::code::notempty,        {glyph::big_dot,         {color::white             ,color::reset }}},
    {rem::code::implemented,     {glyph::arrow_head_right,{color::lime              ,color::reset }}},
    {rem::code::notimplemented,  {glyph::err1,            {color::orange3           ,color::reset }}},
    {rem::code::untested,        {glyph::flag,            {color::yellow            ,color::reset }}},
    {rem::code::eof,             {glyph::baseline,        {color::white             ,color::reset }}},
    {rem::code::eos,             {glyph::baseline,        {color::white             ,color::reset }}},
    {rem::code::null_ptr,        {glyph::circle_x,        {color::hotpink4          ,color::reset }}},
    {rem::code::notexist  ,      {glyph::circle_x ,       {color::white             ,color::reset }}},
    {rem::code::exist     ,      {glyph::star5 ,          {color::white             ,color::reset }}},
    {rem::code::unexpected,      {glyph::flag ,           {color::yellow            ,color::reset }}},
    {rem::code::expected  ,      {glyph::cat ,            {color::white             ,color::reset }}},
    {rem::code::blocked   ,      {glyph::unauth ,         {color::indianred3        ,color::reset }}},
    {rem::code::locked    ,      {glyph::err3 ,           {color::white             ,color::reset }}},
    {rem::code::overflow  ,      {glyph::dead_head,       {color::red4              ,color::reset }}},
    {rem::code::oob       ,      {glyph::alien,           {color::lightcoral        ,color::reset }}},
    {rem::code::reimplement,     {glyph::book,            {color::yellow            ,color::reset }}},
    {rem::code::done       ,     {glyph::ok,              {color::yellow            ,color::reset }}},
    {rem::code::complete   ,     {glyph::ok,              {color::yellow            ,color::reset }}},
    {rem::code::finish     ,     {glyph::ok,              {color::lime              ,color::reset }}},
    {rem::code::undefined  ,     {glyph::err3,            {color::red               ,color::reset }}},
    {rem::code::ready      ,     {glyph::ok,              {color::aqua              ,color::reset }}},
    {rem::code::terminate  ,     {glyph::flag,            {color::hotpink4          ,color::reset }}},
    {rem::code::timeout    ,     {glyph::chronos,         {color::lime              ,color::reset }}},
    {rem::code::divbyzero  ,     {glyph::circle_x,        {color::red4              ,color::reset }}},
    {rem::code::notvisible ,     {glyph::circle_x,        {color::yellow            ,color::reset }}},
    {rem::code::cancel     ,     {glyph::circle_x,        {color::red4              ,color::reset }}},
    {rem::code::object_ptr ,     {glyph::edit_pencil_br,  {color::lightsteelblue3   ,color::reset }}},
    {rem::code::object_id ,      {glyph::arrowright,      {color::yellow            ,color::reset }}},
    {rem::code::unhandled ,      {glyph::alien,           {color::yellow            ,color::reset }}},
    {rem::code::notready ,       {glyph::circle_x,        {color::orange5           ,color::reset }}},
    {rem::code::notfound,        {glyph::circle_x,        {color::red               ,color::reset }}},
    {rem::code::found,           {glyph::success,         {color::fuchsia           ,color::reset }}},
    {rem::code::dismissed,       {glyph::circle_x,        {color::yellow            ,color::reset }}},
    {rem::code::syntax_error,    {glyph::circle_x,        {color::hotpink4          ,color::reset }}},
    {rem::code::applied,         {glyph::success,         {color::green             ,color::reset }}},
    {rem::code::notapplicable,   {glyph::circle_x,        {color::hotpink4          ,color::reset }}},
    {rem::code::valid,           {glyph::success,         {color::green             ,color::reset }}},
    {rem::code::invalid,         {glyph::circle_x,        {color::hotpink4          ,color::reset }}}

};

/**
 * A database mapping function identifiers (`rem::fn`) to their associated glyph representations and color pairs.
 *
 * This map serves as a lookup table that associates specific functions (identified by `rem::fn` enumeration values)
 * with their corresponding glyph type (from `glyph::type`) and a pair of colors (`color::pair`) used for visual representation.
 * These mappings are useful for rendering or displaying information in a visually meaningful way, such as in logs,
 * debugging output, or graphical user interfaces.
 *
 * Each entry in the database consists of:
 * - A `rem::fn` function identifier (e.g., `stamp`, `func`, `file`, etc.).
 * - A pair containing:
 *   - A glyph type from `glyph::type` (e.g., `chronos`, `function`, `file`, etc.).
 *   - A color pair consisting of foreground and background colors (e.g., `color::skyblue3`, `color::reset`, etc.).
 *
 * Duplicate keys may override earlier entries based on implementation of the std::map container.
 *
 * The database encapsulates mappings for functionalities related to timestamps, files, lines, time components, weekdays,
 * months, day names, and numeric representations of dates.
 *
 */
std::map<rem::fn, std::pair<glyph::value, color::pair>> functions_database={
    {rem::fn::func      ,      {glyph::function ,   {color::skyblue3          ,color::reset }}},
    {rem::fn::file      ,      {glyph::file     ,   {color::lightcyan3        ,color::reset }}},
    {rem::fn::line      ,      {glyph::baseline ,   {color::lime              ,color::reset }}},
    {rem::fn::stamp     ,      {glyph::chronos  ,   {color::yellow            ,color::reset }}},
    {rem::fn::hour      ,      {glyph::chronos  ,   {color::white             ,color::reset }}},
    {rem::fn::minute    ,      {glyph::chronos  ,   {color::white             ,color::reset }}},
    {rem::fn::seconds   ,      {glyph::chronos  ,   {color::white             ,color::reset }}},
    {rem::fn::weekday   ,      {glyph::fabric   ,   {color::yellow            ,color::reset }}},
    {rem::fn::month     ,      {glyph::chronos  ,   {color::white             ,color::reset }}},
    {rem::fn::dayname   ,      {glyph::star5    ,   {color::white             ,color::reset }}},
    {rem::fn::day       ,      {glyph::star5    ,   {color::white             ,color::reset }}},
    {rem::fn::monthnum  ,      {glyph::star5    ,   {color::white             ,color::reset }}},
    {rem::fn::year      ,      {glyph::star5    ,   {color::white             ,color::reset }}}

};


/**
 * Retrieves the attributes associated with a specified type.
 *
 * This function accesses a database to retrieve a pair consisting of the glyph type
 * and color pair associated with the provided `rem::type`.
 *
 * @param ty The type of `rem::type` for which attributes are to be fetched.
 * @return A `std::pair` containing the glyph type and color pair associated with the specified type.
 */
std::pair<glyph::value, color::pair> type_attributes(rem::type ty)
{
    return rem::types_database[ty];
}


/**
 * Retrieves the associated attributes for a given `rem::code` status code.
 *
 * This function looks up the provided status code in the `rem::codes_database`
 * and returns a pair containing the corresponding glyph type and color pair.
 *
 * @param cod The status code of type `rem::code` for which the attributes are to be retrieved.
 * @return A std::pair containing a `glyph::type` representing the glyph type
 *         and a `color::pair` representing the associated color attributes.
 */
std::pair<glyph::value, color::pair> return_code_attributes(rem::code cod)
{
    return rem::codes_database[cod];
}


/**
 * Retrieves the attributes of a specified function from the functions database.
 *
 * This function fetches a pair of attributes for the given function identifier,
 * including its glyph type and color pair, from the `rem::functions_database`.
 *
 * @param fn The function identifier of type `rem::fn` whose attributes are to be retrieved.
 * @return A pair containing the glyph type (`glyph::type`) and color pair (`color::pair`) associated with the given function identifier.
 */
std::pair<glyph::value, color::pair> function_attributes(rem::fn fn)
{
    return rem::functions_database[fn];
}


/**
 * Retrieves the attributes associated with a given action, including its glyph type
 * and color pair information.
 *
 * The attributes for the specified action are fetched from a predefined action-to-attribute
 * mapping database.
 *
 * @param a The action of type `rem::action` for which attributes are to be retrieved.
 * @return A pair containing the glyph type (`glyph::type`) and the color pair
 * (`color::pair`) associated with the specified action.
 */
std::pair<glyph::value, color::pair> action_attributes(rem::action a)
{
    return rem::actions_color_db[a];
}


std::string render(rem::code c)
{

    auto [g,col] = return_code_attributes(c);
    std::string text = color::render_rgb(col);
    text += glyph::data[g];
    text += ' ';
    text += rem::to_string(c);
    text += "\x1b[39m";
    return text;
}


std::string render(rem::type c)
{
    auto [g,col] = type_attributes(c);
    std::string text = color::render_rgb(col);
    text += glyph::data[g];
    text += ' ';
    text += rem::to_string(c);
    text += "\x1b[39m";
    return text;
}


std::string to_string(rem::type ty)
{
    return enums_type_dictionary[ty];
}

std::string to_string(rem::code value)
{

    return return_codes_dictionary[value];
}



std::string to_string(rem::fn fn)
{
    return functions_dictionary[fn];
}

std::string to_string(rem::action ac)
{
    return actions_dictionary[ac];
}




}
//
// Created by oldlonecoder on 2025-09-23.
//
