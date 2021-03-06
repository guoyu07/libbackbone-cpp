#                                               -*- Autoconf -*-
# Process this file with autoconf to produce a configure script.

AC_PREREQ(2.61)
AC_INIT([libbackbone-cpp], [0.0.1], http://wwww.leonmergen.com/libbackbone-cpp/)
AC_CONFIG_SRCDIR([backbone++/model.hpp])
AC_CONFIG_HEADER([config.h])

LT_INIT([shared static])

# Makefile initialization.
AM_INIT_AUTOMAKE([-Wall -Werror subdir-objects])

# Checks for programs.
AC_ARG_ENABLE([debug],
        AS_HELP_STRING([--enable-debug], [Enable debugging output]))

AC_ARG_ENABLE([sqlite],
        AS_HELP_STRING([--enable-sqlite], [Enable sqlite durable backend]))

AC_ARG_WITH([includes],
        [AS_HELP_STRING([--with-includes], [look for additional header files in DIRS])],
        [],
        [])

AC_ARG_WITH([libraries],
        [AS_HELP_STRING([--with-libraries], [look for additional libraries in DIRS])],
        [],
        [])
                       

for dir in $with_libraries
do
        LIBDIRS="$LIBDIRS -L$dir"
done

for dir in $with_includes
do
        INCLUDEDIRS="$INCLUDEDIRS -I$dir"
done

AM_CONDITIONAL(HAVE_DEBUG, test "x$enable_debug" = "xyes")

DEBUG=""
AS_IF([test "x$enable_debug" == "xyes"], [
        DEBUG="-Wall -Werror -g -ggdb -DDEBUG"
])

CXXFLAGS="$CXXFLAGS -std=c++11 $INCLUDEDIRS $DEBUG $BOOST_LOG"
LDFLAGS="$LDFLAGS $LIBDIRS"

AC_PROG_CC
AC_PROG_CXX

# Checks for libraries.

# Checks for header files.

# Checks for typedefs, structures, and compiler characteristics.

# Checks for library functions.
AC_CONFIG_FILES([Makefile test/Makefile])
AC_OUTPUT
