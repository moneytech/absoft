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


/*

  xlate_get_reg.c

  $Revision: 162 $


*/

#include "xlateincl.h"

#ifdef _LIBELF_XTND_EXPANDED_DATA
#pragma weak xlate_get_reg_rule_xtnd = _xlate_get_reg_rule_xtnd
#else
#pragma weak xlate_get_reg_rule = _xlate_get_reg_rule
#endif


int
xlate_get_reg_rule(xlate_table_con tab,
	Elf64_Addr pc,
	Elf32_Word reg,
	Elf32_Word  *rule_register,
	Elf64_Xword *rule_offset,
        Elf32_Word  *rule_is_offset)
{
	int retstatus;
	Dwarf_Regtable regtab;
   	if(tab->xc_valid_table != VALID_TABLE_MAGIC) {
        	return XLATE_TB_STATUS_INVALID_TABLE;
   	}


	

	retstatus = _xlate_expand_reg_info_internal(tab,
		REG_RULE_AT_PC,
                pc,
        	&regtab,
		/* num_instrsp=*/ 0,
		/*xlate_reg_instr2** = */  0);

	if(retstatus == XLATE_TB_STATUS_NO_ERROR) {
		*rule_register = regtab.rules[reg].dw_regnum;
		*rule_offset = regtab.rules[reg].dw_offset;
		*rule_is_offset = regtab.rules[reg].dw_offset_relevant;
	}
	return retstatus;
}
