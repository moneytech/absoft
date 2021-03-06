C
C
C  Copyright (C) 2000, 2001 Silicon Graphics, Inc.  All Rights Reserved.
C
C  This program is free software; you can redistribute it and/or modify it
C  under the terms of version 2.1 of the GNU Lesser General Public License 
C  as published by the Free Software Foundation.
C
C  This program is distributed in the hope that it would be useful, but
C  WITHOUT ANY WARRANTY; without even the implied warranty of
C  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  
C
C  Further, this software is distributed without any warranty that it is
C  free of the rightful claim of any third person regarding infringement 
C  or the like.  Any license provided herein, whether implied or 
C  otherwise, applies only to this software file.  Patent licenses, if
C  any, provided herein do not apply to combinations of this program with 
C  other software, or any other product whatsoever.  
C
C  You should have received a copy of the GNU Lesser General Public 
C  License along with this program; if not, write the Free Software 
C  Foundation, Inc., 59 Temple Place - Suite 330, Boston MA 02111-1307, 
C  USA.
C
C  Contact information:  Silicon Graphics, Inc., 1600 Amphitheatre Pky,
C  Mountain View, CA 94043, or:
C
C  http://www.sgi.com
C
C  For further information regarding this notice, see:
C
C  http://oss.sgi.com/projects/GenInfo/NoticeExplan
C
C

CDIR$ NAME (S4GEMVX="_S4GEMVX")
      SUBROUTINE S4GEMVX( M, N, ALPHA, A, INCCA, INCRA, X, INCX,
     $                     BETA, Y, INCY )
!DIR$ ID "@(#) libfi/matrix/s4gemvx.f	92.0	"
!DIR$ ID "10/08/98 14:37:14"
*     ENTRY  S4GEMVX_( M, N, ALPHA, A, INCCA, INCRA, X, INCX, BETA,
*    $                 Y, INCY )
*
*  -- X-interface BLAS specification --
*     E. Anderson, Cray Research Inc.
*     February 25, 1993
*
*     .. Scalar Arguments ..
      INTEGER            INCCA, INCRA, INCX, INCY, M, N
      REAL(KIND=4)       ALPHA, BETA
C     REAL*4             ALPHA, BETA
*     ..
*     .. Array Arguments ..
      REAL(KIND=4)       A( * ), X( * ), Y( * )
C     REAL*4             A( * ), X( * ), Y( * )
*     ..
*
*  Purpose
*  =======
*
*  S4GEMVX performs the matrix-vector multiplication
*
*     y := alpha*A*x + beta*y,
*
*  where alpha and beta are scalars, x is an n-vector, y is an m-vector,
*  and A is an m-by-n matrix.
*
*  Arguments
*  =========
*
*  M       (input) INTEGER
*          The length of the vector y, and the number of rows of the
*          matrix A.  M >= 0.
*
*  N       (input) INTEGER
*          The length of the vector x, and the number of columns of the
*          matrix A.  N >= 0.
*
*  ALPHA   (input) REAL
*          The scalar alpha.
*
*  A       (input) REAL array, dimension
*                  (1 + abs(INCCA)*(M-1) + abs(INCRA)*(N-1))
*          The m-by-n matrix A with column and row increments specified
*          by INCCA and INCRA.
*
*  INCCA   (input) INTEGER
*          The increment between elements in a column of A.
*
*  INCRA   (input) INTEGER
*          The increment between elements in a row of A.
*
*  X       (input) REAL array, dimension (1 + (n-1)*abs(INCX))
*          The n-element vector x.
*
*  INCX    (input) INTEGER
*          The increment for the elements of X.  INCX must not be zero.
*
*  BETA    (input) REAL
*          The scalar beta.
*
*  Y       (input/output) REAL array, dimension (1 + (m-1)*abs(INCY))
*          On entry, the m-element vector y.
*          On exit, Y is overwritten by the updated vector y.
*
*  INCY    (input) INTEGER
*          The increment for the elements of Y.  INCY must not be zero.
*
*  =====================================================================
*
*     .. Parameters ..
      REAL(KIND=4)       ONE, ZERO
C     REAL*4             ONE, ZERO
      PARAMETER          ( ONE = 1.0E+0, ZERO = 0.0E+0 )
*     ..
*     .. Local Scalars ..
      INTEGER            I, IA, IAJ, IY, J, JX, JY
      REAL(KIND=4)       TEMP
C     REAL*4             TEMP
*     ..
*     .. Executable Statements ..
*
*     Quick return if possible
*
      IY = 1
      IF( ( M.NE.0 ) .AND. ( N.EQ.0 ) ) THEN
*     Set the result to zeros and exit
         DO, I = 1, M
            Y( IY ) = ZERO
            IY = IY + INCY
         END DO
         RETURN
       END IF

      IF( ( M.EQ.0 ) .OR. ( N.EQ.0 ) .OR.
     $    ( ( ALPHA.EQ.ZERO ) .AND. ( BETA.EQ.ONE ) ) ) RETURN
*
*     First form  y := beta*y.
*
      IF( BETA.EQ.ZERO ) THEN
         DO 10 I = 1, M
            Y( IY ) = ZERO
            IY = IY + INCY
   10    CONTINUE
      ELSE IF( BETA.NE.ONE ) THEN
         DO 20 I = 1, M
            Y( IY ) = BETA*Y( IY )
            IY = IY + INCY
   20    CONTINUE
      END IF
*
      IF( ALPHA.EQ.ZERO )
     $   RETURN
*
*     Form  y := alpha*A*x + y.
*
      IAJ = 1
      JX = 1
      JY = 1
      DO 40 J = 1, N
         IF( X( JX ).NE.ZERO ) THEN
            TEMP = ALPHA*X( JX )
            IA = IAJ
            IY = JY
            DO 30 I = 1, M
               Y( IY ) = Y( IY ) + TEMP*A( IA )
               IA = IA + INCCA
               IY = IY + INCY
   30       CONTINUE
         END IF
         IAJ = IAJ + INCRA
         JX = JX + INCX
   40 CONTINUE
*
      RETURN
*
*     End of S4GEMVX
*
      END
