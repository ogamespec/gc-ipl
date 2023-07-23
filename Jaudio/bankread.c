void PTconvert__FPPvUl(uint *param_1,uint param_2)
{
  uint uVar1;
  
  uVar1 = *param_1;
  if (param_2 <= uVar1) {
    return;
  }
  if (uVar1 == 0) {
    return;
  }
  *param_1 = uVar1 + param_2;
  return;
}

int Bank_Test__FPUc(int param_1)
{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int *piVar7;
  int iVar8;
  int iVar9;
  int iVar10;
  
  iVar10 = param_1 + 0x20;
  if (*(int *)(param_1 + 0x20) == 0x42414e4b) {
    uVar1 = 0;
    iVar5 = 0;
    do {
      piVar7 = (int *)(iVar10 + iVar5 + 4);
      PTconvert__FPPvUl(piVar7,param_1);
      iVar4 = *piVar7;
      if (iVar4 != 0) {
        uVar3 = 0;
        iVar8 = 0;
        do {
          iVar9 = iVar4 + iVar8;
          piVar7 = (int *)(iVar9 + 0x10);
          PTconvert__FPPvUl(piVar7,param_1);
          PTconvert__FPPvUl(iVar9 + 0x18,param_1);
          PTconvert__FPPvUl(iVar9 + 0x20,param_1);
          if (*piVar7 != 0) {
            PTconvert__FPPvUl(*piVar7 + 8,param_1);
            PTconvert__FPPvUl(*piVar7 + 0xc,param_1);
          }
          uVar3 = uVar3 + 1;
          iVar8 = iVar8 + 4;
        } while (uVar3 < 2);
        iVar8 = 0;
        for (uVar3 = 0; uVar3 < *(uint *)(iVar4 + 0x28); uVar3 = uVar3 + 1) {
          PTconvert__FPPvUl(iVar4 + iVar8 + 0x2c,param_1);
          iVar9 = 0;
          for (uVar2 = 0; iVar6 = *(int *)(iVar4 + iVar8 + 0x2c), uVar2 < *(uint *)(iVar6 + 4);
              uVar2 = uVar2 + 1) {
            PTconvert__FPPvUl(iVar6 + iVar9 + 8,param_1);
            iVar9 = iVar9 + 4;
          }
          iVar8 = iVar8 + 4;
        }
      }
      uVar1 = uVar1 + 1;
      iVar5 = iVar5 + 4;
    } while (uVar1 < 0x80);
    uVar1 = 0;
    iVar5 = 0;
    do {
      piVar7 = (int *)(iVar10 + iVar5 + 0x204);
      PTconvert__FPPvUl(piVar7,param_1);
      iVar4 = *piVar7;
      if (iVar4 != 0) {
        iVar8 = 0;
        for (uVar3 = 0; uVar3 < *(uint *)(iVar4 + 8); uVar3 = uVar3 + 1) {
          PTconvert__FPPvUl(iVar4 + iVar8 + 0xc,param_1);
          iVar8 = iVar8 + 4;
        }
      }
      uVar1 = uVar1 + 1;
      iVar5 = iVar5 + 4;
    } while (uVar1 < 100);
    uVar1 = 0;
    iVar5 = 0;
    do {
      piVar7 = (int *)(iVar10 + iVar5 + 0x394);
      PTconvert__FPPvUl(piVar7,param_1);
      iVar4 = *piVar7;
      if (iVar4 != 0) {
        uVar3 = 0;
        iVar8 = 0;
        do {
          piVar7 = (int *)(iVar4 + iVar8 + 0x88);
          PTconvert__FPPvUl(piVar7,param_1);
          iVar9 = *piVar7;
          if (iVar9 != 0) {
            PTconvert__FPPvUl(iVar9 + 8,param_1);
            PTconvert__FPPvUl(iVar9 + 0xc,param_1);
            iVar6 = 0;
            for (uVar2 = 0; uVar2 < *(uint *)(iVar9 + 0x10); uVar2 = uVar2 + 1) {
              PTconvert__FPPvUl(iVar9 + iVar6 + 0x14,param_1);
              iVar6 = iVar6 + 4;
            }
          }
          uVar3 = uVar3 + 1;
          iVar8 = iVar8 + 4;
        } while (uVar3 < 0x80);
      }
      uVar1 = uVar1 + 1;
      iVar5 = iVar5 + 4;
    } while (uVar1 < 0xc);
  }
  else {
    iVar10 = 0;
  }
  return iVar10;
}

bool __Bank_Regist_Inner__FPUcUlUl(undefined4 param_1,int param_2,undefined4 param_3)
{
  int iVar1;
  
  Jac_BnkConnectTableSet__FUlUl(param_3);
  iVar1 = Bank_Test__FPUc(param_1);
  *(int *)(bankp + param_2 * 4) = iVar1;
  return *(int *)(bankp + param_2 * 4) != 0;
}

void Bank_Regist__FPvUl(int param_1,undefined4 param_2)
{
  __Bank_Regist_Inner__FPUcUlUl(param_1,param_2,*(undefined4 *)(param_1 + 8));
  return;
}

void Bank_Regist_Direct__FPvUlUl(void)
{
  __Bank_Regist_Inner__FPUcUlUl();
  return;
}


void Bank_Init__Fv(void)
{
  int iVar1;
  undefined4 *puVar2;
  int iVar3;
  
  iVar1 = 0;
  iVar3 = 0x100;
  do {
    puVar2 = (undefined4 *)(bankp + iVar1);
    iVar1 = iVar1 + 4;
    *puVar2 = 0;
    iVar3 = iVar3 + -1;
  } while (iVar3 != 0);
  return;
}

undefined4 Bank_Get__FUl(uint param_1)
{
  if (0xff < param_1) {
    return 0;
  }
  return *(undefined4 *)(bankp + param_1 * 4);
}

