#include "Common.h"
#include "mySmBus.h"
#include <Uefi.h>
#include <Library/UefiLib.h>
#include <Library/ShellLib.h>
#include <Library/ShellCommandLib.h>
#include <Library/DebugLib.h>
STATIC CONST SHELL_PARAM_ITEM ParamList[] = {
  {L"-aa", TypeValue},
  {L"-cc", TypeValue},
  {NULL, TypeMax}
  };

EFI_STATUS  
EFIAPI   
UefiMain (
    IN EFI_HANDLE        ImageHandle,
    IN EFI_SYSTEM_TABLE  *SystemTable
)
{
    EFI_STATUS Status;
      LIST_ENTRY          *Package;
  CHAR16              *ProblemParam;
  CONST CHAR16        *ParamAA ;          
  CONST CHAR16        *ParamCC ;  
  UINT8            intParamAA = 0;        
  UINT8            intParamCC = 0;
    ProblemParam        = NULL;
  Status = ShellInitialize();
  if (EFI_ERROR(Status)) {
    DEBUG ((EFI_D_INFO, "[ZK] !!!ShellInitialize Fail!,Status :%r.\n", Status));
  }
  Status = CommandInit();
  if (EFI_ERROR(Status)) {
    DEBUG ((EFI_D_INFO, "[ZK] !!!CommandInit Fail!,Status :%r.\n", Status));
  }
    Status = ShellCommandLineParse (ParamList, &Package, &ProblemParam, TRUE);
  if (EFI_ERROR(Status)) {
    DEBUG ((EFI_D_INFO, "[ZK] !!!ShellCommandLineParse Fail!,Status :%r.\n", Status));
  } else {
    if (ShellCommandLineGetFlag(Package, L"-aa")) { //-a
      ParamAA =  ShellCommandLineGetValue(Package, L"-aa");
      if(ParamAA != NULL){
        DEBUG ((EFI_D_INFO, "ParamAA = %s\n", ParamAA));
        intParamAA = (UINT8)ShellStrToUintn(ParamAA);
      }
    }
    if (ShellCommandLineGetFlag(Package, L"-cc")) { //-b
      ParamCC = ShellCommandLineGetValue(Package, L"-cc");
      if(ParamAA != NULL){
        DEBUG ((EFI_D_INFO, "ParamCC = %s\n", ParamCC));
        intParamCC = (UINT8)ShellStrToUintn(ParamCC);
      }
    }
    ShellCommandLineFreeVarList (Package);
 }



    
    Status = LocateSmBusHc();
    if(EFI_ERROR(Status)){
        Print(L"Fail to LocateProtocol.\n");
        return Status;
    }
    INT8 value;
   // Print(L"Locate Success.\n");
    value = SmbusReadByte(ParamAA,ParamCC);
    Print(L"%02X\n",value);
    return Status;
}