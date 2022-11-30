#include "Common.h"
#include "mySmBus.h"

EFI_STATUS  
EFIAPI   
UefiMain (
    IN EFI_HANDLE        ImageHandle,
    IN EFI_SYSTEM_TABLE  *SystemTable
)
{
    EFI_STATUS Status;
    Status = LocateSmBusHc();
    if(EFI_ERROR(Status)){
        Print(L"Fail to LocateProtocol.\n");
        return Status;
    }
   // Print(L"Locate Success.\n");
    UINT8 SlaveAdd = 0x40;
    //UINT8 RegisterAdd = 0x00;
    UINTN i,j;
    Print(L"   ******Slave Address: 0x%02X***********\n",SlaveAdd);
    Print(L"   | 0  1  2  3  4  5  6  7  8  9  A  B  C  D  E  F\n");
    Print(L"---|-----------------------------------------------\n");
    for(i=0;i<16;i++)
    {
      Print(L"%01x0 |",i);
      for(j=0;j<16;j++)
        Print(L"%02x ",SmbusReadByte(SlaveAdd,(UINT8)(i*16+j)));
      Print(L"\n");
    }
    return Status;
}