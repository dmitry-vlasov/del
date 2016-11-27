#                                               -*- Autoconf -*-
# Process this file with autoconf to produce a configure script.

AC_PREREQ(2.64)
AC_INIT(del, 0.8, vlasov at academ dot org)
AC_CONFIG_SRCDIR([config.h.in])
AC_CONFIG_HEADER([config.h])
AM_INIT_AUTOMAKE

# Checks for programs.
AC_PROG_CXX
AC_PROG_CC
AC_PROG_INSTALL

AM_LDFLAGS='-static'
AX_PTHREAD
CXXFLAGS='-pthread'

# Checks for library functions.
AC_FUNC_ERROR_AT_LINE

# Checks for header files.
AC_CHECK_HEADERS #([limits.h stdlib.h string.h sys/time.h unistd.h])

# Checks for typedefs, structures, and compiler characteristics.
AC_CHECK_HEADER_STDBOOL
AC_C_INLINE

# Checks for library functions.
AC_FUNC_ERROR_AT_LINE
AC_FUNC_MALLOC
AC_FUNC_REALLOC
AC_CHECK_FUNCS([gettimeofday mkdir pow strchr strcspn strstr])

AC_CONFIG_FILES([
Makefile
	
math/Makefile
scripts/Makefile

src/Makefile

src/nstd/Makefile
	src/nstd/config/Makefile
		src/nstd/config/option/Makefile
	src/nstd/container/Makefile
		src/nstd/container/continual/Makefile
		src/nstd/container/discrete/Makefile
		src/nstd/container/storage/Makefile
	src/nstd/equation/Makefile
	src/nstd/interpolation/Makefile
	src/nstd/lexer/Makefile
	src/nstd/map/Makefile
	src/nstd/memory/Makefile
		src/nstd/memory/allocator/Makefile
		src/nstd/memory/exception/Makefile
		src/nstd/memory/storage/Makefile
		src/nstd/memory/unit/Makefile
	src/nstd/misc/Makefile
	src/nstd/sampler/Makefile
	src/nstd/type/Makefile
		src/nstd/type/constant/Makefile
		src/nstd/type/list/Makefile
		src/nstd/type/traits/Makefile
			src/nstd/type/traits/indicator/Makefile
		src/nstd/type/undefined/Makefile
	src/nstd/system/Makefile

src/del/Makefile
	src/del/auxiliary/Makefile
	src/del/interface/Makefile
		src/del/interface/model/Makefile
			src/del/interface/model/queue/Makefile
	src/del/lexer/Makefile
	src/del/math/Makefile
	src/del/model/Makefile
		src/del/model/interpretation/Makefile
		src/del/model/node/Makefile
			src/del/model/node/negative/Makefile
			src/del/model/node/positive/Makefile
		src/del/model/queue/Makefile
			src/del/model/queue/domain/Makefile
			src/del/model/queue/impl/Makefile
			src/del/model/queue/range/Makefile
	src/del/owl/Makefile
		src/del/owl/func/Makefile
			src/del/owl/func/lexer/Makefile
			src/del/owl/func/parser/Makefile
			src/del/owl/func/source/Makefile
		src/del/owl/man/Makefile
			src/del/owl/man/lexer/Makefile
			src/del/owl/man/parser/Makefile
			src/del/owl/man/source/Makefile
	src/del/parser/Makefile
	src/del/source/Makefile
		src/del/source/formula/Makefile
			src/del/source/formula/equiv/Makefile
			src/del/source/formula/subset/Makefile
				src/del/source/formula/subset/normal/Makefile
		src/del/source/term/Makefile
	src/del/types/Makefile
])
AC_OUTPUT
