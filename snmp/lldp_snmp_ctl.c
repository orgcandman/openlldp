/*******************************************************************************

  Implementation of SNMP support
  (c) Copyright IBM Corp. 2012

  Author(s): Mijo Safradin <mijo at linux.vnet.ibm.com>

  This program is free software; you can redistribute it and/or modify it
  under the terms and conditions of the GNU General Public License,
  version 2, as published by the Free Software Foundation.

  This program is distributed in the hope it will be useful, but WITHOUT
  ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
  FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for
  more details.

  You should have received a copy of the GNU General Public License along with
  this program; if not, write to the Free Software Foundation, Inc.,
  51 Franklin St - Fifth Floor, Boston, MA 02110-1301 USA.

  The full GNU General Public License is included in this distribution in
  the file called "COPYING".

*******************************************************************************/
#include <sys/select.h>

#include "include/lldpad_snmp.h"

#if HAVE_SNMP
int snmpfds(fd_set *fds)
{
	int rc = 0;
	rc = snmp_fd(fds);
	if (rc == -1)
		snmp_clean_data();
	return rc;
}
#endif
