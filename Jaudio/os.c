void osWritebackDCacheAll__Fv(void)
{
  return;
}

void osInvalDCache2__FPvl(void)
{
  DCInvalidateRange();
  return;
}

void osWritebackDCache2__FPvl(void)
{
  DCStoreRange();
  return;
}

undefined4 osAiSetNextBuffer2__FPvUl(void)
{
  return 0;
}

void Na_SetDiskType__Fl(int param_1)
{
  LBAS_TABLE_TYPE = LBAS_TABLE_TYPE_LIST + param_1 * 0x22;
  ZONE_TABLE_TYPE = ZONE_TABLE_TYPE_LIST + param_1 * 0x10;
  return;
}

int GetLbaSize__Fl(int param_1)
{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  
  iVar2 = 0;
  iVar3 = 1;
  iVar1 = 2;
  iVar4 = 0xf;
  do {
    if (param_1 < *(short *)(LBAS_TABLE_TYPE + iVar1)) break;
    iVar2 = iVar2 + 1;
    iVar3 = iVar3 + 1;
    iVar1 = iVar1 + 2;
    iVar4 = iVar4 + -1;
  } while (iVar4 != 0);
  if (iVar3 == 0x10) {
    return 0;
  }
  return (int)*(short *)(BYTES_TABLE + (char)ZONE_TABLE_TYPE[iVar2] * 2);
}

undefined4 SmzOfsToLBA__FPlPUl(int *param_1,int *param_2)
{
  int iVar1;
  int iVar2;
  int iVar3;
  
  iVar3 = *param_1;
  iVar2 = *param_2;
  while( true ) {
    iVar1 = GetLbaSize__Fl(iVar3);
    if (iVar1 == 0) {
      return 0xffffffff;
    }
    if (iVar2 < iVar1) break;
    iVar2 = iVar2 - iVar1;
    iVar3 = iVar3 + 1;
  }
  *param_1 = iVar3;
  *param_2 = iVar2;
  return 0;
}

void osCreateMesgQueue__FP13OSMesgQueue_sPPvl(int param_1,undefined4 param_2,undefined4 param_3)
{
  *(undefined4 *)(param_1 + 0x14) = param_2;
  *(undefined4 *)(param_1 + 0x10) = param_3;
  *(undefined4 *)(param_1 + 8) = 0;
  *(undefined4 *)(param_1 + 0xc) = 0;
  return;
}

undefined4 osSendMesg__FP13OSMesgQueue_sPvl(int param_1,undefined4 param_2)
{
  int iVar1;
  int iVar2;
  
  iVar2 = *(int *)(param_1 + 0x10);
  if (*(int *)(param_1 + 8) == iVar2) {
    return 0xffffffff;
  }
  iVar1 = *(int *)(param_1 + 0xc) + *(int *)(param_1 + 8);
  if (iVar2 <= iVar1) {
    iVar1 = iVar1 - iVar2;
  }
  *(undefined4 *)(*(int *)(param_1 + 0x14) + iVar1 * 4) = param_2;
  *(int *)(param_1 + 8) = *(int *)(param_1 + 8) + 1;
  return 0;
}

undefined4 osRecvMesg__FP13OSMesgQueue_sPPvl(int param_1,undefined4 *param_2,int param_3)
{
  if (param_3 == 1) {
    do {
    } while (*(int *)(param_1 + 8) == 0);
  }
  if (*(int *)(param_1 + 8) == 0) {
    if (param_2 != (undefined4 *)0x0) {
      *param_2 = 0;
    }
    return 0xffffffff;
  }
  *(int *)(param_1 + 8) = *(int *)(param_1 + 8) + -1;
  if (param_2 != (undefined4 *)0x0) {
    *param_2 = *(undefined4 *)(*(int *)(param_1 + 0x14) + *(int *)(param_1 + 0xc) * 4);
  }
  *(int *)(param_1 + 0xc) = *(int *)(param_1 + 0xc) + 1;
  if (*(int *)(param_1 + 0xc) == *(int *)(param_1 + 0x10)) {
    *(undefined4 *)(param_1 + 0xc) = 0;
  }
  return 0;
}

undefined4 osEPiStartDma__FP10OSPiHandleP8OSIoMesgl(undefined4 param_1,int param_2)
{
  ARAMStartDMAmesg__FUlUlUlUllP13OSMesgQueue_s
            (1,*(undefined4 *)(param_2 + 8),*(undefined4 *)(param_2 + 0xc),
             *(undefined4 *)(param_2 + 0x10),0,*(undefined4 *)(param_2 + 4));
  return 0;
}

void bcopy__FPvPvUl(void)
{
  Jac_bcopy__FPvPvl();
  return;
}

void DumpMemory__FUlUl(undefined4 param_1,uint param_2)
{
  uint uVar1;
  int iVar2;
  
  for (uVar1 = 0; uVar1 < param_2; uVar1 = uVar1 + 1) {
    iVar2 = 0x10;
    do {
      iVar2 = iVar2 + -1;
    } while (iVar2 != 0);
  }
  return;
}

