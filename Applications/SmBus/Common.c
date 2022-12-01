
#include "Common.h"

EFI_SMBUS_HC_PROTOCOL *SmbusProtocol;

/**
  Get the first protocol instance that matches the SmbusHc protocol.

  @param[in]  

  @retval EFI_SUCCESS           A protocol instance matching Protocol was found and returned in
                                Interface.
  @retval EFI_NOT_FOUND         No protocol instances were found that match Protocol and
                                Registration.
  @retval EFI_INVALID_PARAMETER Interface is NULL.
                                Protocol is NULL.

**/
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