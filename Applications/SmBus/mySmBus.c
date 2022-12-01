#include "mySmBus.h"

extern EFI_SMBUS_HC_PROTOCOL *SmbusProtocol;

/**
  Smbus Protocol Operation —— ReadByte.(Details in SmBus Spec)

  @param[in]  SlaveAddress      SmBus device address.
  @param[in]  RegisterIndex     Register Address of Smbus device

  @retval Buffer                The value of the register.

**/
UINT8
EFIAPI
SmbusReadByte(IN UINT8 SlaveAddress,IN UINT8 RegisterIndex)
{
    EFI_STATUS Status = EFI_SUCCESS;
    EFI_SMBUS_DEVICE_ADDRESS device;
    UINTN Length = 0x01;
    UINT8 Buffer = 0x00;
    EFI_SMBUS_DEVICE_COMMAND index;
    device.SmbusDeviceAddress = SlaveAddress;
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
/**
  Smbus Protocol Operation —— WriteByte.(Details in SmBus Spec)

  @param[in]  SlaveAddress      SmBus device address.
  @param[in]  RegisterIndex     Register Address of Smbus device
  @param[in]  Byte              The value set into the register

  @retval VOID               

**/
VOID
EFIAPI
SmbusWriteByte(IN UINT8 SlaveAddress,IN UINT8 RegisterIndex,IN UINT8 Byte)
{
    EFI_STATUS Status ;
    EFI_SMBUS_DEVICE_ADDRESS device;
    UINTN Length = 0x01;
    UINT8 Buffer = Byte;
    EFI_SMBUS_DEVICE_COMMAND index;
    device.SmbusDeviceAddress = SlaveAddress;
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
/**
  Smbus Protocol Operation —— QuickCommand.(Details in SmBus Spec)

  @param[in]  SlaveAddress      SmBus device address.
                                First 7th bit is device address,8th bit is the command.

  @retval VOID               

**/
VOID
EFIAPI
SmbusQuickWrite(IN UINT8 SlaveAddress)
{
    EFI_STATUS Status ;
    EFI_SMBUS_DEVICE_ADDRESS device;
    UINTN Length = 0x01;
    UINT8 Buffer = 0;
    device.SmbusDeviceAddress = SlaveAddress;
    Status = SmbusProtocol->Execute(
        SmbusProtocol,
        device,
        0,
        EfiSmbusQuickWrite,
        FALSE,
        &Length,
        &Buffer
    ); 
}
/**
  Smbus Protocol Operation —— SendByte.(Details in SmBus Spec)

  @param[in]  SlaveAddress      SmBus device address.
                                First 7th bit is device address,8th bit is the command.
  @param[in]  Buffer            A byte sent from master to slave.
  @retval VOID               

**/
VOID
EFIAPI
SmbusSendByte(IN UINT8 SlaveAddress,IN UINT8 Buffer)
{
    EFI_STATUS Status ;
    EFI_SMBUS_DEVICE_ADDRESS device;
    UINTN Length = 0x01;
    device.SmbusDeviceAddress = SlaveAddress;
    Status = SmbusProtocol->Execute(
        SmbusProtocol,
        device,
        0,
        EfiSmbusSendByte,
        FALSE,
        &Length,
        &Buffer
    ); 
}


