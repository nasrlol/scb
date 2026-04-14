/* base library internal error checking system */
#ifndef BASE_ERROR_H
#define BASE_ERROR_H

#define error_at(msg) \
    do \
    { \
        os_write(STDERR_FD, Red "[ERROR] ", Len(Red "[ERROR] ")); \
        write_string(STDERR_FD, __FILE__); \
        write_string(STDERR_FD, ":"); \
        write_int(__LINE__); \
        write_string(STDERR_FD, " in "); \
        write_string(STDERR_FD, __func__); \
        write_string(STDERR_FD, ": "); \
        write_string(STDERR_FD, (msg)); \
        os_write(STDERR_FD, Reset "\n", Len(Reset "\n")); \
    } while (0)

#define _fatal(msg) \
    do { \
        error_at(msg); \
        _exit(1); \
    } while (0)

#define assert_msg(expr, msg) \
    do \
    { \
        if (!(expr)) _fatal(msg); \
    } while (0)

#define warn(msg) \
    do \
    { \
        os_write(STDERR_FD, Yellow "[WARN] ", Len(Yellow "[WARN] ")); \
        write_string(STDERR_FD, __FILE__); \
        write_string(STDERR_FD, ":"); \
        write_int(__LINE__); \
        write_string(STDERR_FD, ": "); \
        write_string(STDERR_FD, (msg)); \
        os_write(STDERR_FD, Reset "\n", Len(Reset "\n")); \
    } while (0)

#endif /* BASE_ERROR_H */
