
#include "Common.h"

EFI_SMBUS_HC_PROTOCOL *SmbusProtocol;


EFI_STATUS
EFIAPI
LocateSmBusHc(void)
{
    EFI_STATUS Status;
    Status = gBS->LocateProtocol(
        &gEfiSmbusHcProtocolGuid,
        NULL,
        &SmbusProtocol
    );
    if(EFI_ERROR(Status)){
        Print(L"Fail to LocateProtocol.\n");
        return Status;
    }
    return Status;
}