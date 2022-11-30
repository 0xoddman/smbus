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
  //临时debug用
// typedef struct {
//   LIST_ENTRY     Link;
//   CHAR16         *Name;
//   SHELL_PARAM_TYPE      Type;
//   CHAR16         *Value;
//   UINTN          OriginalPosition;
// } SHELL_PARAM_PACKAGE;
  //临时debug用
/**
  The user Entry Point for Application. The user code starts with this function
  as the real entry point for the application.
  @param[in] ImageHandle    The firmware allocated handle for the EFI image.
  @param[in] SystemTable    A pointer to the EFI System Table.
  @retval EFI_SUCCESS       The entry point is executed successfully.
  @retval other             Some error occurs when executing this entry point.
**/
EFI_STATUS
EFIAPI
UefiMain (
  IN EFI_HANDLE        ImageHandle,
  IN EFI_SYSTEM_TABLE  *SystemTable
  )
{
//   Print(L"Hello,this is Entry of UefiMain!\n");
  EFI_STATUS          Status;
  LIST_ENTRY          *Package;
  CHAR16              *ProblemParam;
  // SHELL_STATUS        ShellStatus;
  // UINT8               Level;
  CONST CHAR16        *ParamAA ;  //?????                     
  CONST CHAR16        *ParamCC ;  
  UINT8            intParamAA = 0;        
  UINT8            intParamCC = 0;
  // Level = PcdGet8(PcdShellSupportLevel);
  ProblemParam        = NULL;
  // ShellStatus         = SHELL_SUCCESS;
  //
  // initialize the shell lib (we must be in non-auto-init...)
  //
  Status = ShellInitialize();
  if (EFI_ERROR(Status)) {
    DEBUG ((EFI_D_INFO, "[ZK] !!!ShellInitialize Fail!,Status :%r.\n", Status));
  }
  Status = CommandInit();
  if (EFI_ERROR(Status)) {
    DEBUG ((EFI_D_INFO, "[ZK] !!!CommandInit Fail!,Status :%r.\n", Status));
  }
  //
  // parse the command line
  //
  Status = ShellCommandLineParse (ParamList, &Package, &ProblemParam, TRUE);
//临时debug
  // ParamAA =  ShellCommandLineGetValue(Package, L"-a");
  // LIST_ENTRY     *Node;
  //  for ( Node = GetFirstNode(Package)
  //     ; !IsNull (Package, Node)
  //     ; Node = GetNextNode(Package, Node)
  //     ){
  //       DEBUG ((EFI_D_INFO, "-------------------------------------------------\n"));
  //       DEBUG ((EFI_D_INFO, "((SHELL_PARAM_PACKAGE*)Node)->Name = %s\n",((SHELL_PARAM_PACKAGE*)Node)->Name));
  //       DEBUG ((EFI_D_INFO, "((SHELL_PARAM_PACKAGE*)Node)->Value = %s\n",((SHELL_PARAM_PACKAGE*)Node)->Value));
  //       DEBUG ((EFI_D_INFO, "((SHELL_PARAM_PACKAGE*)Node)->Type = %d\n",((SHELL_PARAM_PACKAGE*)Node)->Type));
  //       // }
  //     }
 
  //   DEBUG ((EFI_D_INFO, "OVER"));
//临时debug

  
  //如果ShellCommandLineParse失败
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
    // free the command line package
    ShellCommandLineFreeVarList (Package);
  }
  Print(L"intParamAA = %02X,intParamCC = %02X\n",  intParamAA, intParamCC);
  Print(L"-----------------------------------\n");
  // DEBUG ((EFI_D_INFO, "ParamAA = %s\n", ParamAA));
  // DEBUG ((EFI_D_INFO, "ParamCC = %s\n", ParamCC));
  return EFI_SUCCESS;
}
