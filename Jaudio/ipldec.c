undefined1 *
WriteTask__FUcUlPvPFPv_v(undefined param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)
{
  int iVar1;
  
  if (TASK_REMAIN == '\x04') {
    return (undefined1 *)0x0;
  }
  iVar1 = (uint)TASK_WRITEPTR * 0x10;
  EX_DSPTASK[iVar1] = param_1;
  *(undefined4 *)(EX_DSPTASK + iVar1 + 4) = param_2;
  *(undefined4 *)(EX_DSPTASK + iVar1 + 8) = param_3;
  *(undefined4 *)(EX_DSPTASK + iVar1 + 0xc) = param_4;
  TASK_WRITEPTR = TASK_WRITEPTR + 1;
  if (TASK_WRITEPTR == '\x04') {
    TASK_WRITEPTR = '\0';
  }
  TASK_REMAIN = TASK_REMAIN + '\x01';
  return EX_DSPTASK;
}

/* WARNING: Removing unreachable block (ram,0x000100d4) */
void DoTask__Fv(void)
{
  int iVar1;
  code *pcVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  
  for (; TASK_REMAIN != '\0'; TASK_REMAIN = TASK_REMAIN + -1) {
    iVar1 = (uint)TASK_READPTR * 0x10;
    uVar4 = *(undefined4 *)(EX_DSPTASK + iVar1 + 8);
    uVar3 = *(undefined4 *)(EX_DSPTASK + iVar1 + 4);
    pcVar2 = *(code **)(EX_DSPTASK + iVar1 + 0xc);
    if (EX_DSPTASK[iVar1] == '\x01') {
      OSReport("Do AGB Task \n");
      DagbSec__FUl(uVar3);
      OSReport("   AGB Task Finish\n");
    }
    else if (EX_DSPTASK[iVar1] == '\0') {
      OSReport("Do CARD Task \n");
      DiplSec__FUl(uVar3);
      OSReport("   CARD Task Finish\n");
    }
    if (pcVar2 == (code *)0x0) {
      OSReport(" Audio Error:: DSP_SECURITY_CALLBACK is NULL\n");
    }
    else {
      (*pcVar2)(uVar4);
    }
    TASK_READPTR = TASK_READPTR + 1;
    if (TASK_READPTR == 4) {
      TASK_READPTR = 0;
    }
  }
  return;
}

undefined4 DspExtraTaskCheck__Fv(void)
{
  DoTask__Fv();
  return 1;
}

undefined4 Jac_IPLDspSec(int param_1)
{
  undefined auStack_c [4];
  
  if (init$49 == '\0') {
    first$48 = '\x01';
    init$49 = '\x01';
  }
  if (first$48 != '\0') {
    OSInitMessageQueue(dspsec_mq,&msgbuf,1);
    first$48 = '\0';
  }
  *(undefined4 *)(param_1 + 8) = uRam00000000;
  DCStoreRange(param_1,0x10);
  OSReceiveMessage(dspsec_mq,auStack_c,0);
  DSP_SECURITY_FLAG = param_1;
  OSReceiveMessage(dspsec_mq,auStack_c,1);
  return 0;
}

void Jac_DSPcardDecodeAsync__FPvPvPFPv_v(undefined4 param_1,undefined4 param_2,undefined4 param_3)
{
  int iVar1;
  
  do {
    iVar1 = WriteTask__FUcUlPvPFPv_v(0,param_2,param_1,param_3);
  } while (iVar1 == 0);
  return;
}

void Jac_DSPagbDecodeAsync__FPvPvPFPv_v(undefined4 param_1,undefined4 param_2,undefined4 param_3)
{
  int iVar1;
  
  do {
    iVar1 = WriteTask__FUcUlPvPFPv_v(1,param_2,param_1,param_3);
  } while (iVar1 == 0);
  return;
}

