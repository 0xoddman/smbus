#include "Common.h"
#include "mySmBus.h"
#include "SmBusTools.h"

STATIC CONST SHELL_PARAM_ITEM ParamList[] = {
  {L"-m", TypeValue},
  {L"-s", TypeValue},
  {L"-r", TypeValue},
  {L"-v", TypeValue},
  {NULL, TypeMax}
  };

enum SmbusMode{get=0,set=1,dump=2};

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
    CONST CHAR16    *Mode;
    CONST CHAR16    *SlaveAdd ;          
    CONST CHAR16    *RegisterAdd; 
    CONST CHAR16    *Value;
    enum SmbusMode eMode;
    UINT8            intSA= 0;        
    UINT8            intRA = 0;
    UINT8            intValue = 0;
    ProblemParam     = NULL;
    ShellInitialize();
    CommandInit();
    Status = ShellCommandLineParse (ParamList, &Package, &ProblemParam, TRUE);
    if (ShellCommandLineGetFlag(Package, L"-m")) 
    { 
        Mode =  ShellCommandLineGetValue(Package, L"-m");
        if(Mode != NULL)
        {
            eMode= (UINT8)ShellStrToUintn(Mode);
        }
    }
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
        if(RegisterAdd != NULL)
        {
            intValue = (UINT8)ShellStrToUintn(RegisterAdd);
        }
    }
    ShellCommandLineFreeVarList (Package);
    LocateSmBusHc();
    switch (eMode){
        case set:
            SmBusSet(intSA,intRA,intValue); 
            break;
        case get:
            SmBusGet(intSA,intRA);
            break;
        case dump:
            SmBusDump(intSA);
            break;
    }
    return EFI_SUCCESS;


}