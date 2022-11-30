#include "SmbusTools.h"


UINT8 EFIAPI SmBusGet(IN UINT8 SlaveAddress,IN UINT8 RegisterIndex)
{
    UINT8 value;
    value = SmbusReadByte(SlaveAddress,RegisterIndex);
    Print(L"%02X\n",value);
    return value;
}

VOID EFIAPI SmBusSet(IN UINT8 SlaveAddress,IN UINT8 RegisterIndex,UINT8 Byte)
{
    SmbusWriteByte(SlaveAddress,RegisterIndex,Byte);
}

VOID EFIAPI SmBusDump(IN UINT8 SlaveAddress)
{
    UINTN i,j;
    Print(L"   ******Slave Address: 0x%02X***********\n",SlaveAddress);
    Print(L"   | 0  1  2  3  4  5  6  7  8  9  A  B  C  D  E  F\n");
    Print(L"---|-----------------------------------------------\n");
    for(i=0;i<16;i++)
    {
      Print(L"%01x0 |",i);
      for(j=0;j<16;j++)
        Print(L"%02x ",SmbusReadByte(SlaveAddress,(UINT8)(i*16+j)));
      Print(L"\n");
    }
}