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
    // XXX:
    // SystemInit uses a symbol `__Vectors` when working with the VTOR setup
    // https://github.com/OpenNuvoton/M2351BSP/blob/5e272d7a5980344c5e24de8a598d47f5e5a14e55/Library/Device/Nuvoton/M2351/Source/system_M2351.c#L393-L409
    // This errors because __Vectors is some startup code in Assembly that we did not include
    // And considering Zephyr has code for VTOR already, it's probably(?) handled elsewhere
    // SystemInit();

    // XXX: Clock setup?
    // UART works w/o anything else here

    SystemCoreClockUpdate();

    SYS_LockReg();
}
