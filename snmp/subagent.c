/******************************************************************************

  LLDP Agent Daemon (LLDPAD) Software
  Copyright(c) 2012 IBM Corp.
  Copyright(c) 2012 Intel Corporation.

  Author(s): John Fastabend <john.r.fastabend at intel.com>
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

  Contact Information:
  open-lldp Mailing List <lldp-devel at open-lldp.org>

  Note: this file originally auto-generated by mib2c using
        version : 5.7.1
******************************************************************************/

/* standard Net-SNMP includes */
#include <net-snmp/net-snmp-config.h>
#include <net-snmp/net-snmp-includes.h>
#include <net-snmp/agent/net-snmp-agent-includes.h>
#include "snmp/net-snmp-features.h"
#include "snmp/snmp_agent.h"

#include <signal.h>

/*
 * If compiling within the net-snmp source code, this will trigger the feature
 * detection mechansim to ensure the agent_check_and_process() function
 * is left available even if --enable-minimialist is turned on.  If you
 * have configured net-snmp using --enable-minimialist and want to compile
 * this code externally to the Net-SNMP code base, then please add
 * --with-features="agent_check_and_process enable_stderrlog" to your
 * configure line.
 */
netsnmp_feature_require(agent_check_and_process)
netsnmp_feature_require(enable_stderrlog)

#include <limits.h>
#include "lldpad.h"
#include "messages.h"

int mib_subagent(void)
{
	int rc = 0;

	netsnmp_enable_subagent();
	snmp_enable_stderrlog();

	rc = init_agent("openlldpMIBs");
	if (rc) {
		LLDPAD_ERR("%s%s: [SNMP-AGENT] ", ">>>", __func__);
		LLDPAD_ERR("init_agent returned with an error - rd: %d\n", rc);
	}

	/* init mibs */
	init_ieee8021BridgeBaseTable();
	init_ieee8021BridgeEvbSys();

	LLDPAD_DBG("%s: init snmp\n", __func__);
	init_snmp("openlldpMIBs");

	return 0;
}
