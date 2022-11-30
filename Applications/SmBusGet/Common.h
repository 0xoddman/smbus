#ifndef _COMMON_H
#define _COMMON_H

#include <Uefi.h>
#include <Protocol/SmbusHc.h>
#include <Library/UefiBootServicesTableLib.h>
#include <Library/UefiLib.h>

EFI_STATUS
EFIAPI
LocateSmBusHc(void);

#endif