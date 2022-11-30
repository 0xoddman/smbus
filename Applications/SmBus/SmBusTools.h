#ifndef _SMBUSTOOLS_H
#define _SMBUSTOOLS_H

#include "Common.h"
#include "mySmBus.h"


UINT8 EFIAPI SmBusGet(IN UINT8 SlaveAddress,IN UINT8 RegisterIndex);
VOID EFIAPI SmBusSet(IN UINT8 SlaveAddress,IN UINT8 RegisterIndex,UINT8 Byte);
VOID EFIAPI SmBusDump(IN UINT8 SlaveAddress);

#endif