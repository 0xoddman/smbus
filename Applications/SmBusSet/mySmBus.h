#ifndef _MYSMBUS_H
#define _MYSMBUS_H

#include "Common.h"

UINT8 EFIAPI SmbusReadByte(IN UINT8 SlaveAddress,IN UINT8 RegisterIndex);
VOID EFIAPI SmbusWriteByte(IN UINT8 SlaveAddress,IN UINT8 RegisterIndex,IN UINT8 Byte);
VOID EFIAPI SmbusQuickWrite(IN UINT8 SlaveAddress);
VOID EFIAPI SmbusSendByte(IN UINT8 SlaveAddress,IN UINT8 Buffer);

#endif