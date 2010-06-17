/*

  Copyright (C) 2000, 2001 Silicon Graphics, Inc.  All Rights Reserved.

  This program is free software; you can redistribute it and/or modify it
  under the terms of version 2.1 of the GNU Lesser General Public License 
  as published by the Free Software Foundation.

  This program is distributed in the hope that it would be useful, but
  WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  

  Further, this software is distributed without any warranty that it is
  free of the rightful claim of any third person regarding infringement 
  or the like.  Any license provided herein, whether implied or 
  otherwise, applies only to this software file.  Patent licenses, if
  any, provided herein do not apply to combinations of this program with 
  other software, or any other product whatsoever.  

  You should have received a copy of the GNU Lesser General Public 
  License along with this program; if not, write the Free Software 
  Foundation, Inc., 59 Temple Place - Suite 330, Boston MA 02111-1307, 
  USA.

  Contact information:  Silicon Graphics, Inc., 1600 Amphitheatre Pky,
  Mountain View, CA 94043, or:

  http://www.sgi.com

  For further information regarding this notice, see:

  http://oss.sgi.com/projects/GenInfo/NoticeExplan

*/


#ifndef __NIO_H__
#define __NIO_H__


#ident "$Revision: 162 $"

#include <stdio.h>
#include <cmplrs/fio.h>

#if defined(_LANGUAGE_C) || defined(_LANGUAGE_C_PLUS_PLUS)

typedef union {
   char           *pchar;
   signed char    *pbyte;
   short          *pshort;
   int            *pint;
   long long      *plonglong;
   float          *pfloat;
   double         *pdouble;
   long double    *plongdouble;
   char          **pptr;
}               Pointer;	/* pointer to all sorts of things */

/* PROTOTYPES */
extern int s_rsne(cilist *);
extern int s_rsNe(cilist *);
extern int s_rsNe_mp(cilist *, unit **);
extern int s_wsne(cilist *);
extern int s_wsNe(cilist *);
extern int s_wsne_mp (cilist *pnlarg, unit **fu);
extern int s_wsNe_mp(cilist *, unit **);
/*  int c_nle(cilist *, unit **); internal only */
extern int __kai_s_rsne(cilist *);
extern int __kai_s_wsne(cilist *);
extern int __kai_s_rsne_mp(cilist *, unit **);
extern int __kai_s_wsne_mp(cilist *, unit **);

#if 11
extern int s_rsNe64(cilist64 *pnlarg);
extern int s_rsNe64_mp(cilist64 *pnlarg, unit **fu);
extern int s_wsNe64(cilist64 *pnlarg);
extern int s_wsNe64_mp(cilist64 *pnlarg, unit **fu);
extern int __kai_s_rsne64(cilist64 *pnlarg);
extern int __kai_s_rsne64_mp(cilist64 *pnlarg, unit **fu);
extern int __kai_s_wsne64(cilist64 *pnlarg);
extern int __kai_s_wsne64_mp(cilist64 *pnlarg, unit **fu);
#endif

#endif /* C || C++ */

#endif /* !__NIO_H__ */




