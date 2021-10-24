/*
 * SPDX-License-Identifier: Apache-2.0
 */

#include <init.h>
#include <kernel.h>

// XXX: the SOC_FAMILY sets PLATFORM_SOC_INIT
// Should we swap to using `SYS_INIT(xxx, PRE_KERNEL_1, 0)` ?
void z_arm_platform_init(void)
{
	SYS_UnlockReg();

	/* system clock init */
	SystemInit();

    // XXX: Clock setup?
    // UART works w/o anything else here

	SystemCoreClockUpdate();

	SYS_LockReg();
}
