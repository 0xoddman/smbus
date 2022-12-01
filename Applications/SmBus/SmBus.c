#include "Common.h"
#include "mySmBus.h"
#include "SmBusTools.h"

STATIC CONST SHELL_PARAM_ITEM ParamList[] = {
  {L"set", TypeFlag},
  {L"get", TypeFlag},
  {L"dump", TypeFlag},
  {L"-s", TypeValue},
  {L"-r", TypeValue},
  {L"-v", TypeValue},
  {NULL, TypeMax}
  };

EFI_STATUS  
EFIAPI   
UefiMain (
    IN EFI_HANDLE        ImageHandle,
    IN EFI_SYSTEM_TABLE  *SystemTable
)
{
    EFI_STATUS      Status;
    LIST_ENTRY      *Package;
    CHAR16          *ProblemParam;

    CONST CHAR16    *SlaveAdd ;          
    CONST CHAR16    *RegisterAdd; 
    CONST CHAR16    *Value;

    UINT8            intSA= 0;        
    UINT8            intRA = 0;
    UINT8            intValue = 0;
    ProblemParam     = NULL;
    ShellInitialize();
    CommandInit();
    Status = ShellCommandLineParse (ParamList, &Package, &ProblemParam, TRUE);
    LocateSmBusHc();
    if (ShellCommandLineGetFlag(Package, L"-s")) 
    { 
        SlaveAdd =  ShellCommandLineGetValue(Package, L"-s");
        if(SlaveAdd != NULL)
        {
            intSA = (UINT8)ShellStrToUintn(SlaveAdd);
        }
    }
    if (ShellCommandLineGetFlag(Package, L"-r")) 
    { 
        RegisterAdd = ShellCommandLineGetValue(Package, L"-r");
        if(RegisterAdd != NULL)
        {
            intRA = (UINT8)ShellStrToUintn(RegisterAdd);
        }
    }
    if (ShellCommandLineGetFlag(Package, L"-v")) 
    { 
        Value= ShellCommandLineGetValue(Package, L"-v");
        if(Value != NULL)
        {
            intValue = (UINT8)ShellStrToUintn(Value);
        }
    }
    if(ShellCommandLineGetFlag(Package, L"set")){
        SmBusSet(intSA,intRA,intValue);  
    }
     if(ShellCommandLineGetFlag(Package, L"get")){
        SmBusGet(intSA,intRA);  
    }
     if(ShellCommandLineGetFlag(Package, L"dump")){
        SmBusDump(intSA);  
    }
    ShellCommandLineFreeVarList (Package);
    return EFI_SUCCESS;

}