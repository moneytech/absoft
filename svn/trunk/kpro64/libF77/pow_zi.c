/*
 * Copyright 2004, 2005 PathScale, Inc.  All Rights Reserved.
 */

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

#include <math.h>
#include "cmplrs/host.h"
#include "cmplx.h"
#include "defalias.h"

extern dcomplex __powzi(double adreal, double adimag, int32 n);
extern dcomplex __powzl(double adreal, double adimag, int64 n);

void pow_zi__(dcomplex *p, dcomplex *a, int32 *b)   /* p = a**b  */
{
  *p = __powzi(a->dreal, a->dimag,*b);
}

defalias(pow_zi__, pow_zi_);
defalias(pow_zi__, pow_zif_);

#if defined(ABSOFT_EXTENSIONS) && defined(__APPLE__) // || !defined(HAVE_ALIAS_SUPPORT)
void pow_zi_(dcomplex *p, dcomplex *a, int32 *b)
{
  *p = __powzi(a->dreal, a->dimag, *b);
}

void pow_zif_(dcomplex *p, dcomplex *a, int32 *b)
{
  *p = __powzi(a->dreal, a->dimag, *b);
}
#endif

void pow_zl__(dcomplex *p, dcomplex *a, int64 *b)   /* p = a**b  */
{
  *p = __powzl(a->dreal, a->dimag,*b);
}

defalias(pow_zl__, pow_zl_);
defalias(pow_zl__, pow_zlf_);

#if defined(ABSOFT_EXTENSIONS) && defined(__APPLE__) // || !defined(HAVE_ALIAS_SUPPORT)
void pow_zl_(dcomplex *p, dcomplex *a, int64 *b)
{
  *p = __powzl(a->dreal, a->dimag, *b);
}

void pow_zlf_(dcomplex *p, dcomplex *a, int64 *b)
{
  *p = __powzl(a->dreal, a->dimag, *b);
}
#endif

