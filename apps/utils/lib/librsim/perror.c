/* This file is part of the RSIM Applications Library and was modified
from the GNU C library as follows:

Separate initialization calls for stdio streams
Testing against the UNIX stdio streams to determine if the user
is using those structures instead. */  
/* Copyright (C) 1991, 1992, 1993 Free Software Foundation, Inc.
This file is part of the GNU C Library.

The GNU C Library is free software; you can redistribute it and/or
modify it under the terms of the GNU Library General Public License as
published by the Free Software Foundation; either version 2 of the
License, or (at your option) any later version.

The GNU C Library is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
Library General Public License for more details.

You should have received a copy of the GNU Library General Public
License along with the GNU C Library; see the file COPYING.LIB.  If
not, write to the Free Software Foundation, Inc., 675 Mass Ave,
Cambridge, MA 02139, USA.  */

#include <ansidecl.h>
#include <stdio.h>
#include <errno.h>

/* extern char *_strerror_internal __P ((int, char buf[1024])); */

/* Print a line on stderr consisting of the text in S, a colon, a space,
   a message describing the meaning of the contents of `errno' and a newline.
   If S is NULL or "", the colon and space are omitted.  */
void
DEFUN(perror, (s), register CONST char *s)
{
  char buf[1024];
  int errnum = errno;
  CONST char *colon;

  if (s == NULL || *s == '\0')
    s = colon = "";
  else
    colon = ": ";

  if (!__stdio_inited) __init_stdio();
  (void) fprintf (stderr, "%s%s\nerrno:%d\n",
		  s, colon, errnum);
  /* _strerror_internal (errnum, buf)); */
}
