void JV_InitHeader__FPc(undefined4 param_1)
{
  JV_InitHeader_M__FPcPUcPUc(param_1,0,0);
  return;
}

undefined4 JV_InitHeader_M__FPcPUcPUc(char *param_1,int param_2,undefined4 param_3)
{
  int iVar1;
  size_t sVar2;
  char *pcVar3;
  size_t sVar4;
  
  if (param_2 == 0) {
    iVar1 = DVDT_CheckFile__FPc(param_1);
    if (iVar1 == 0) {
      OSReport(...rodata.0,param_1);
      return 0;
    }
    param_2 = OSAlloc2();
    if (param_2 == 0) {
      OSReport(@52);
      return 0;
    }
    iVar1 = DVDT_LoadFile__FPcPUc(param_1,param_2);
    if (iVar1 == 0) {
      OSReport(@53);
      return 0;
    }
  }
  sVar2 = strlen(param_1);
  sVar2 = sVar2 - 1;
  sVar4 = sVar2;
  for (pcVar3 = param_1 + sVar2; (sVar4 != 0 && (*pcVar3 != '/')); pcVar3 = pcVar3 + -1) {
    sVar2 = sVar2 - 1;
    sVar4 = sVar4 - 1;
  }
  if (sVar2 == 0) {
    strcpy(JV_DIR_NAME + JV_CURRENT_ARCS * 0x40,(char *)&@54);
  }
  else {
    strncpy(JV_DIR_NAME + JV_CURRENT_ARCS * 0x40,param_1,sVar2);
  }
  strcpy(JV_ARC_NAME + JV_CURRENT_ARCS * 0x20,param_1 + sVar2 + 1);
  iVar1 = JV_CURRENT_ARCS * 4;
  *(int *)(JV_ARC + iVar1) = param_2;
  iVar1 = *(int *)(JV_ARC + iVar1);
  OSReport(&@55,iVar1,iVar1 + 4,*(undefined4 *)(iVar1 + 0xc));
  *(undefined4 *)(*(int *)(JV_ARC + JV_CURRENT_ARCS * 4) + 8) = param_3;
  JV_CURRENT_ARCS = JV_CURRENT_ARCS + 1;
  return 1;
}

int JV_GetArchiveHandle__FPc(char *param_1)
{
  int iVar1;
  uint uVar2;
  int iVar3;
  
  uVar2 = 0;
  iVar3 = 0;
  while ((uVar2 < JV_CURRENT_ARCS && (iVar1 = strcmp(param_1,JV_ARC_NAME + iVar3), iVar1 != 0))) {
    uVar2 = uVar2 + 1;
    iVar3 = iVar3 + 0x20;
  }
  if (uVar2 == JV_CURRENT_ARCS) {
    iVar3 = -1;
  }
  else {
    iVar3 = uVar2 << 0x10;
  }
  return iVar3;
}

uint JV_GetLogicalHandleS__FPcPc(char *param_1,char *param_2)
{
  uint uVar1;
  int iVar2;
  uint uVar3;
  int iVar4;
  int iVar5;
  
  uVar3 = 0;
  iVar4 = 0;
  while ((uVar3 < JV_CURRENT_ARCS && (iVar5 = strcmp(param_1,JV_ARC_NAME + iVar4), iVar5 != 0))) {
    uVar3 = uVar3 + 1;
    iVar4 = iVar4 + 0x20;
  }
  if (uVar3 == JV_CURRENT_ARCS) {
    uVar1 = 0xffffffff;
  }
  else {
    uVar1 = 0;
    iVar4 = *(int *)(JV_ARC + uVar3 * 4);
    iVar5 = 0;
    while ((uVar1 < *(uint *)(iVar4 + 0xc) &&
           (iVar2 = strcmp((char *)(iVar4 + iVar5 + 0x20),param_2), iVar2 != 0))) {
      uVar1 = uVar1 + 1;
      iVar5 = iVar5 + 0x20;
    }
    if (uVar1 == *(uint *)(iVar4 + 0xc)) {
      uVar1 = 0xffffffff;
    }
    else {
      uVar1 = uVar3 << 0x10 | uVar1;
    }
  }
  return uVar1;
}

uint JV_GetLogicalHandle__FPc(char *param_1)
{
  size_t sVar1;
  char *pcVar2;
  uint uVar3;
  int iVar4;
  uint uVar5;
  int iVar6;
  int iVar7;
  size_t sVar8;
  char acStack_114 [128];
  char acStack_94 [132];
  
  sVar1 = strlen(param_1);
  sVar1 = sVar1 - 1;
  sVar8 = sVar1;
  for (pcVar2 = param_1 + sVar1; (sVar8 != 0 && (*pcVar2 != '/')); pcVar2 = pcVar2 + -1) {
    sVar1 = sVar1 - 1;
    sVar8 = sVar8 - 1;
  }
  if (sVar1 == 0) {
    uVar5 = 0;
    strcpy(acStack_94,param_1);
  }
  else {
    strncpy(acStack_114,param_1,sVar1);
    uVar5 = 0;
    acStack_114[sVar1] = '\0';
    strcpy(acStack_94,param_1 + sVar1 + 1);
    iVar6 = 0;
    while ((uVar5 < JV_CURRENT_ARCS && (iVar7 = strcmp(acStack_114,JV_ARC_NAME + iVar6), iVar7 != 0)
           )) {
      uVar5 = uVar5 + 1;
      iVar6 = iVar6 + 0x20;
    }
  }
  if (uVar5 == JV_CURRENT_ARCS) {
    uVar3 = 0xffffffff;
  }
  else {
    uVar3 = 0;
    iVar6 = *(int *)(JV_ARC + uVar5 * 4);
    iVar7 = 0;
    while ((uVar3 < *(uint *)(iVar6 + 0xc) &&
           (iVar4 = strcmp((char *)(iVar6 + iVar7 + 0x20),acStack_94), iVar4 != 0))) {
      uVar3 = uVar3 + 1;
      iVar7 = iVar7 + 0x20;
    }
    if (uVar3 == *(uint *)(iVar6 + 0xc)) {
      uVar3 = 0xffffffff;
    }
    else {
      uVar3 = uVar5 << 0x10 | uVar3;
    }
  }
  return uVar3;
}

int JV_GetHandle__FUl(uint param_1)
{
  int iVar1;
  
  if (JV_CURRENT_ARCS <= param_1 >> 0x10) {
    return 0;
  }
  iVar1 = *(int *)(JV_ARC + (param_1 >> 0x10) * 4);
  if (iVar1 == 0) {
    return 0;
  }
  if (*(uint *)(iVar1 + 0xc) <= (param_1 & 0xffff)) {
    return 0;
  }
  return iVar1 + (param_1 & 0xffff) * 0x20 + 0x20;
}

int JV_GetRealHandle__FUl(uint param_1)
{
  uint uVar1;
  int iVar2;
  int iVar3;
  
  uVar1 = param_1 & 0xffff;
  if (JV_CURRENT_ARCS <= param_1 >> 0x10) {
    return 0;
  }
  iVar3 = *(int *)(JV_ARC + (param_1 >> 0x10) * 4);
  if (iVar3 != 0) {
    if (uVar1 < *(uint *)(iVar3 + 0xc)) {
      do {
        iVar2 = iVar3 + uVar1 * 0x20 + 0x20;
        uVar1 = (uint)*(ushort *)(iVar2 + 0xe);
      } while (uVar1 != 0xffff);
      return iVar2;
    }
    return 0;
  }
  return 0;
}

void __JV_Callback__FUl(undefined4 param_1)
{
  OSReport("Loaded ID= %d\n",param_1);
  return;
}

int JV_LoadFile__FUlPUcUlUl(uint param_1,undefined4 param_2,int param_3,undefined4 param_4)
{
  int iVar1;
  int local_ac;
  char acStack_a8 [136];
  
  local_ac = 0;
  iVar1 = JV_GetRealHandle__FUl();
  param_3 = *(int *)(iVar1 + 0x18) + param_3;
  strcpy(acStack_a8,JV_DIR_NAME + (param_1 >> 0x10) * 0x40);
  strcat(acStack_a8,(char *)&@54);
  strcat(acStack_a8,(char *)(*(int *)(JV_ARC + (param_1 >> 0x10) * 4) + 0x10));
  OSReport(&@155,param_1,*(undefined4 *)(iVar1 + 0x18));
  OSReport(@156,acStack_a8,param_4,param_3,param_2);
  DVDT_LoadtoDRAM__FUlPcUlUlUlPUlPFUl_v(0,acStack_a8,param_2,param_3,param_4,&local_ac,0);
  do {
  } while (local_ac == 0);
  OSReport(@157);
  return local_ac;
}

undefined4
JV_LoadFile_Async2__FUlPUcUlUlPFUl_vUl
          (uint param_1,undefined4 param_2,int param_3,undefined4 param_4,undefined4 param_5,
          undefined4 param_6)
{
  int iVar1;
  char acStack_b0 [140];
  
  if (init$159 == '\0') {
    first$158 = 1;
    init$159 = '\x01';
  }
  iVar1 = JV_GetRealHandle__FUl(param_1);
  param_3 = *(int *)(iVar1 + 0x18) + param_3;
  strcpy(acStack_b0,JV_DIR_NAME + (param_1 >> 0x10) * 0x40);
  strcat(acStack_b0,(char *)&@54);
  strcat(acStack_b0,(char *)(*(int *)(JV_ARC + (param_1 >> 0x10) * 4) + 0x10));
  OSReport(&@155,param_1,*(undefined4 *)(iVar1 + 0x18));
  OSReport(@162,acStack_b0,param_4,param_3,param_2);
  DVDT_LoadtoDRAM__FUlPcUlUlUlPUlPFUl_v(param_6,acStack_b0,param_2,param_3,param_4,0,param_5);
  return param_4;
}

int JV_GetMemoryFile__FUl(uint param_1)
{
  int iVar1;
  
  iVar1 = JV_GetRealHandle__FUl();
  if (iVar1 == 0) {
    iVar1 = 0;
  }
  else if (*(int *)(*(int *)(JV_ARC + (param_1 >> 0x10) * 4) + 8) == 0) {
    iVar1 = 0;
  }
  else {
    iVar1 = *(int *)(*(int *)(JV_ARC + (param_1 >> 0x10) * 4) + 8) + *(int *)(iVar1 + 0x18);
  }
  return iVar1;
}
