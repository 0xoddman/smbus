#include "mySmBus.h"

extern EFI_SMBUS_HC_PROTOCOL *SmbusProtocol;

UINT8
EFIAPI
SmbusReadByte(IN UINT8 SlaveAddress,IN UINT8 RegisterIndex)
{
    EFI_STATUS Status = EFI_SUCCESS;
    EFI_SMBUS_DEVICE_ADDRESS device;
    UINTN Length = 0x01;
    UINT8 Buffer = 0x00;
    EFI_SMBUS_DEVICE_COMMAND index;
    device.SmbusDeviceAddress = (SlaveAddress>>1);
    index = RegisterIndex;
    Status = SmbusProtocol->Execute(
        SmbusProtocol,
        device,
        index,
        EfiSmbusReadByte,
        FALSE,
        &Length,
        &Buffer
    );
    return Buffer;
};

VOID
EFIAPI
SmbusWriteByte(IN UINT8 SlaveAddress,IN UINT8 RegisterIndex,IN UINT8 Byte)
{
    EFI_STATUS Status ;
    EFI_SMBUS_DEVICE_ADDRESS device;
    UINTN Length = 0x01;
    UINT8 Buffer = Byte;
    EFI_SMBUS_DEVICE_COMMAND index;
    device.SmbusDeviceAddress = (SlaveAddress>>1);
    index = RegisterIndex;
    Status = SmbusProtocol->Execute(
        SmbusProtocol,
        device,
        index,
        EfiSmbusWriteByte,
        FALSE,
        &Length,
        &Buffer
    );
}