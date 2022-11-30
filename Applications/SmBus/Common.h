#ifndef _COMMON_H
#define _COMMON_H

#include <Uefi.h>
#include <Protocol/SmbusHc.h>
#include <Library/UefiBootServicesTableLib.h>
#include <Library/UefiLib.h>
#include <Library/ShellLib.h>
#include <Library/ShellCommandLib.h>
#include <Library/DebugLib.h>

EFI_STATUS
EFIAPI
LocateSmBusHc(void);

#endif