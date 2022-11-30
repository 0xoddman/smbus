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
    // SmbusWriteByte(0x80,0x80,0x01);
    // SmbusQuickWrite(0x40,0x01);
    SmbusSendByte(0x40,0x80);
    return Status;
}