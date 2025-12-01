/******************************************************************************************
*   Copyright (C) ...,2025,... by Serge luxsier                                          *
 *   serge.luxsier@oldbitsnbytes.club / luxsier.serge@gmail.com                            *
 *   ----------------------------------------------------------------------------------   *
 *   Unless otherwise specified, all Codes ands files in this project is written          *
 *   by the author and owned by the auther (Serge luxsier), unless otherwise specified.   *
 *   ----------------------------------------------------------------------------------   *
 *   Copyrights from authors other than Serge luxsier also apply here.                    *
 *   Open source FREE licences also apply To the Code from the author (Serge luxsier)     *
 *   ----------------------------------------------------------------------------------   *
 *   Usual GNU FREE GPL-1,2, MIT... or whatever -  apply to this project.                 *
 *   ----------------------------------------------------------------------------------   *
 *   NOTE : All code source that I am the only author, I reserve for myself, the rights to*
 *   make it to restricted private license.                                               *
 ******************************************************************************************/



#pragma once

#include <applog/colors.h>
#include <applog/border.h>


using cpp::color;
using cpp::glyph;
using cpp::border;
/*!
 * @brief  [ a coherent (decorated with glyphes and colors ] Return Enumeration Mnemonics [ system ]
 *         Also a rem system as "REMarks";
 */
namespace rem
{

/**
 * @enum rem::type
 * @brief Enumerates various message and status types used in the application.
 *
 * This enumeration defines a set of message and status identifiers, each
 * assigned a unique value of type `tux::integers::U8`. It is used to
 * represent and classify events or states within the system.
 *
 * ### Enumerators:
 * - `none`: Represents no type or an unspecified message/state.
 * - `err`: Indicates an error condition.
 * - `warning`: Represents a warning message.
 * - `fatal`: Denotes a fatal message or condition.
 * - `except`: Represents an exception type message.
 * - `message`: Generic message type.
 * - `output`: Designates output-related messages.
 * - `debug`: Indicates messages meant for debugging purposes.
 * - `info`: Represents informational messages.
 * - `comment`: Denotes comment messages or notes.
 * - `syntax`: Relates to syntax-specific messages.
 * - `status`: Represents status-related information.
 * - `test`: Denotes test-related output or messages.
 * - `interrupted`: Indicates an interrupted operation.
 * - `aborted`: Represents an aborted process or operation.
 * - `segfault`: Signifies a segmentation fault condition.
 * - `book`: Used for book-related status or operations.
 * - `normal`: Represents a normal or default state.
 */
enum class type : cpp::integers::U8{
    none, err, warning, fatal, except, message, output, debug, info, comment, syntax, status, test, interrupted, aborted, segfault, book, normal, grace
};

/**
 * @enum code
 * @brief Enumerates various common result and status codes used in the system.
 *
 * This enumeration defines a broad range of identifiers for conveying the result
 * or state of operations, errors, conditions, and other system-defined statuses.
 * Each enumerator is of type `tux::integers::U8` and represents a specific meaning
 * or category to describe different conditions in the system.
 *
 * ### Enumerators:
 * - `ok`: Represents a successful or positive outcome.
 * - `accepted`: Indicates an action or request was accepted.
 * - `success`: Denotes that an operation completed successfully.
 * - `rejected`: Indicates that an action or request was rejected.
 * - `failed`: Represents a failure condition.
 * - `empty`: Denotes an empty state or data structure.
 * - `full`: Represents a full state or capacity reached.
 * - `notempty`: Indicates that an entity is not empty.
 * - `implemented`: Represents a feature or functionality that has been implemented.
 * - `notimplemented`: Indicates a feature or functionality is yet to be implemented.
 * - `untested`: Denotes a feature or condition that has not yet been tested.
 * - `eof`: Signifies the end of a file (EOF).
 * - `eos`: Represents the end of a stream, string, statement, or status.
 * - `null_ptr`: Indicates a null or invalid pointer reference.
 * - `notexist`: Indicates that an entity does not exist.
 * - `exist`: Represents that an entity already exists.
 * - `unexpected`: Denotes an unexpected condition.
 * - `expected`: Represents an expected condition.
 * - `blocked`: Indicates that a thread was blocked due to a locked mutex or resource.
 * - `locked`: Represents that a thread has successfully locked a mutex or resource.
 * - `overflow`: Indicates a buffer overflow condition.
 * - `oob`: Represents a buffer overflow, often due to out-of-bounds access.
 * - `reimplement`: Suggests reimplementation of a feature or functionality.
 * - `done`: Indicates the completion of an operation.
 * - `complete`: Represents that a task or process has been fully completed.
 * - `finish`: Marks the concluxion of an operation or process.
 * - `undefined`: Denotes an undefined state or value.
 * - `ready`: Indicates readiness for action or operation.
 * - `terminate`: Represents a termination condition or request.
 * - `timeout`: Denotes that an operation timed out.
 * - `divbyzero`: Represents a division by zero condition.
 * - `notvisible`: Indicates that an entity is not visible.
 * - `cancel`: Denotes a cancellation event or state.
 * - `object_ptr`: Refers to an object pointer.
 * - `object_id`: Refers to an object identifier.
 * - `unhandled`: Represents an unhandled condition or exception.
 * - `zero`: Represents a zero state or value.
 * - `hup`: Indicates a hang-up (HUP) signal or similar condition.
 * - `notready`: Denotes an entity is not yet ready.
 * - `notfound`: Represents that a requested entity or resource was not found.
 * - `found`: Indicates that a requested entity or resource was found.
 * - `dismissed`: Denotes that a condition or state was dismissed.
 * - `syntax_error`: Represents a syntax error condition.
 */
enum class code :cpp::integers::U8
{
    ok  =0           , ///< Obviously;
    accepted         ,
    success          ,
    rejected         ,
    failed           ,
    empty            ,
    full             ,
    notempty         ,
    implemented      , ///< Like notimplemented or already implemented
    notimplemented   , ///< "Please, implement"
    untested         ,
    eof              , ///< End of file
    eos              , ///< End of stream or string or statement or Status ( machine state )
    null_ptr         , ///< It will happen. Trust me :)
    notexist         , ///< does not exist
    exist            , ///< does already exist
    unexpected       , ///< unexpected
    expected         , ///< expected
    blocked          , ///< thread trying To lock a mutex has failed because the mutex is already locked into another thread...
    locked           , ///< thread trying To lock a mutex has become the owner of the lock.
    overflow         , ///< buffer overflow
    oob              , ///< buffer overflow
    reimplement      ,
    done             ,
    complete         ,
    finish           ,
    undefined        ,
    ready            ,
    terminate        ,
    timeout          ,
    divbyzero        ,
    notvisible       ,
    cancel           ,
    object_ptr       ,
    object_id        ,
    unhandled        ,
    zero             ,
    hup              ,
    notready         ,
    notfound         ,
    found            ,
    dismissed        ,
    syntax_error     ,
    applied          ,
    notapplicable    ,
    valid            ,
    invalid
    //...to be continued

};


/**
 * @enum rem::fn
 * @brief Represents function-related identifiers and time components.
 *
 * This enumeration provides various function identifiers and time-related
 * components, each assigned a unique value of type `tux::integers::U8`.
 * It is used for identifying functions, timestamps, and other contextual
 * information within the application.
 *
 * ### Enumerators:
 * - `func`: Represents a general function identifier.
 * - `endl`: Indicates the end of a line in the input format.
 * - `file`: Denotes a file identifier or reference.
 * - `line`: Represents a line reference or number.
 * - `stamp`: Indicates a fully detailed timestamp.
 * - `hour`: Refers to the hour component of a timestamp.
 * - `minute`: Represents the minute component of a timestamp.
 * - `seconds`: Denotes the seconds component of a timestamp.
 * - `weekday`: Represents the weekday of a date.
 * - `dayname`: Denotes the name of the day in a week.
 * - `month`: Represents the name of the month by default.
 * - `day`: Indicates the day of the month.
 * - `monthnum`: Represents the numeric representation of the month.
 * - `year`: Refers to the year component of a date.
 */
enum class fn :cpp::integers::U8
{
    func             ,
    eol              , ///< End of line Code, input format
    file             ,
    line             ,
    stamp            , ///< fully detailed timestamp
    hour             ,
    minute           ,
    seconds          ,
    weekday          ,
    dayname          ,
    month            , ///< Par defaut month name
    day              ,
    monthnum         , ///< Maintenant explicite
    year             ,
    location           ///< full text source location ( dedicated entry line containing stamp, file, line, fully-qualified function name )
};


/**
 * @enum rem::action
 * @brief Represents a set of predefined actions or control signals for system processes.
 *
 * This enumeration defines various actions that control or manage
 * iterations, sections, loops, and commit operations within the system.
 * Each enumerator provides specific behavior or signals for processing
 * workflow and structure handling.
 *
 * ### Enumerators:
 * - `enter`: Enter a new block or increase indent level.
 * - `leave`: End accumulators and commit changes; terminate a section, reset attributes, or decrease indentation.
 * - `commit`: Signal to commit the current state or data.
 * - `begin`: Mark the start of a section or increase indent level.
 * - `end`: End a loop, action, or section; decrease indentation or finalize inputs.
 * - `cont`: Continue a loop or signal iteration.
 * - `dismiss`: Dismiss the current action or iteration; break the process or ignore the action.
 */
enum class action :cpp::integers::U8
{
    enter            , ///< enter pad or indent
    leave            , ///< End (bookger: End of entry accumulators, so do commit); End of (sel)Section, Attribute ( auto-color::reset ) and unindent
    commit           , ///< Commit...
    begin            , ///< Begin (sel)Section or augment indent level
    end              , ///< End   Loop/Action or End selection or Unindent one level; or end inputs on the current bookentry then fluxh to file.
    cont             , ///< Continue Loop and/or continue Signals::Action iteration.
    dismiss          , ///< The current action or iteration has been dismissed : break run or actual action.
};

std::string to_string(rem::type ty);
std::string to_string(rem::code value);
std::string to_string(rem::fn fn);
std::string to_string(rem::action a);
std::pair<cpp::glyph::value,color::pair> type_attributes(rem::type ty);
std::pair<cpp::glyph::value,color::pair> return_code_attributes(rem::code cod);
std::pair<cpp::glyph::value,color::pair> function_attributes(rem::fn fn);
std::pair<cpp::glyph::value,color::pair> action_attributes(rem::action a);

std::string render(rem::code c);
std::string render(rem::type c);

}



bool operator !(rem::code);
