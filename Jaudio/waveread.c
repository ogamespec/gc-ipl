
void PTconvert__FPPvUl(uint *param_1,uint param_2)
{
  uint uVar1;
  
  uVar1 = *param_1;
  if (uVar1 == 0) {
    *param_1 = 0;
    return;
  }
  if (param_2 <= uVar1) {
    return;
  }
  if (uVar1 == 0) {
    return;
  }
  *param_1 = uVar1 + param_2;
  return;
}

undefined4 Wave_Test__FPUc(int param_1)
{
  undefined4 uVar1;
  uint uVar2;
  uint uVar3;
  int *piVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  int *piVar8;
  int *piVar9;
  
  PTconvert__FPPvUl(param_1 + 0x10,param_1);
  PTconvert__FPPvUl(param_1 + 0x14,param_1);
  piVar8 = *(int **)(param_1 + 0x10);
  piVar9 = *(int **)(param_1 + 0x14);
  CGRP_ARRAY._0_4_ = piVar9;
  if (*piVar8 == 0x57494e46) {
    if (*piVar9 == 0x57424354) {
      iVar5 = 0;
      for (uVar2 = 0; uVar2 < (uint)piVar8[1]; uVar2 = uVar2 + 1) {
        piVar4 = (int *)((int)piVar8 + iVar5 + 8);
        PTconvert__FPPvUl(piVar4,param_1);
        iVar7 = *piVar4;
        Jac_InitHeap__FP7jaheap_(iVar7 + 0x40);
        iVar6 = 0;
        *(undefined4 *)(iVar7 + 0x48) = 0;
        for (uVar3 = 0; uVar3 < *(uint *)(iVar7 + 0x70); uVar3 = uVar3 + 1) {
          PTconvert__FPPvUl(iVar7 + iVar6 + 0x74,param_1);
          iVar6 = iVar6 + 4;
        }
        iVar5 = iVar5 + 4;
      }
      iVar5 = 0;
      for (uVar2 = 0; uVar1 = CGRP_ARRAY._0_4_, uVar2 < (uint)piVar9[2]; uVar2 = uVar2 + 1) {
        piVar8 = (int *)((int)piVar9 + iVar5 + 0xc);
        PTconvert__FPPvUl(piVar8,param_1);
        iVar7 = *piVar8;
        PTconvert__FPPvUl(iVar7 + 0xc,param_1);
        PTconvert__FPPvUl(iVar7 + 0x10,param_1);
        PTconvert__FPPvUl(iVar7 + 0x14,param_1);
        piVar8 = *(int **)(iVar7 + 0xc);
        if ((piVar8 != (int *)0x0) && (*piVar8 == 0x432d4446)) {
          iVar6 = 0;
          for (uVar3 = 0; uVar3 < (uint)piVar8[1]; uVar3 = uVar3 + 1) {
            piVar4 = (int *)((int)piVar8 + iVar6 + 8);
            PTconvert__FPPvUl(piVar4,param_1);
            Jac_InitHeap__FP7jaheap_(*piVar4 + 4);
            iVar6 = iVar6 + 4;
            *(undefined4 *)(*piVar4 + 0xc) = 0;
          }
        }
        piVar8 = *(int **)(iVar7 + 0x10);
        if ((piVar8 != (int *)0x0) && (*piVar8 == 0x432d4558)) {
          iVar6 = 0;
          for (uVar3 = 0; uVar3 < (uint)piVar8[1]; uVar3 = uVar3 + 1) {
            piVar4 = (int *)((int)piVar8 + iVar6 + 8);
            PTconvert__FPPvUl(piVar4,param_1);
            Jac_InitHeap__FP7jaheap_(*piVar4 + 4);
            iVar6 = iVar6 + 4;
            *(undefined4 *)(*piVar4 + 0xc) = 0;
          }
        }
        piVar8 = *(int **)(iVar7 + 0x14);
        if ((piVar8 != (int *)0x0) && (*piVar8 == 0x432d5354)) {
          iVar7 = 0;
          for (uVar3 = 0; uVar3 < (uint)piVar8[1]; uVar3 = uVar3 + 1) {
            piVar4 = (int *)((int)piVar8 + iVar7 + 8);
            PTconvert__FPPvUl(piVar4,param_1);
            Jac_InitHeap__FP7jaheap_(*piVar4 + 4);
            iVar7 = iVar7 + 4;
            *(undefined4 *)(*piVar4 + 0xc) = 0;
          }
        }
        iVar5 = iVar5 + 4;
      }
    }
    else {
      uVar1 = 0;
    }
  }
  else {
    uVar1 = 0;
  }
  return uVar1;
}

void GetSound_Test__FUl(undefined4 param_1)
{
  GetSoundHandle__FP10CtrlGroup_Ul(CGRP_ARRAY._0_4_,param_1);
  return;
}

bool Wavegroup_Regist__FPvUl(int param_1,int param_2)
{
  int iVar1;
  
  Jac_WsConnectTableSet__FUlUl(*(undefined4 *)(param_1 + 8));
  iVar1 = Wave_Test__FPUc(param_1);
  *(int *)(wavegroup + param_2 * 4) = iVar1;
  *(undefined4 *)(wavearc + param_2 * 4) = *(undefined4 *)(param_1 + 0x10);
  iVar1 = *(int *)(wavegroup + param_2 * 4);
  if (iVar1 != 0) {
    *(undefined4 *)(iVar1 + 4) = 0;
  }
  return iVar1 != 0;
}

void Wavegroup_Init__Fv(void)
{
  int iVar1;
  undefined4 *puVar2;
  int iVar3;
  
  iVar1 = 0;
  iVar3 = 0x100;
  do {
    puVar2 = (undefined4 *)(wavegroup + iVar1);
    iVar1 = iVar1 + 4;
    *puVar2 = 0;
    iVar3 = iVar3 + -1;
  } while (iVar3 != 0);
  return;
}

undefined4 WaveidToWavegroup__FUlUl(undefined4 param_1,uint param_2)
{
  undefined4 uVar1;
  
  if ((short)((uint)param_1 >> 0x10) == -1) {
    param_2 = param_2 & 0xffff;
  }
  else {
    param_2 = Jac_WsVirtualToPhysical__FUs();
  }
  if ((param_2 & 0xffff) < 0x100) {
    uVar1 = *(undefined4 *)(wavegroup + (param_2 & 0xffff) * 4);
  }
  else {
    uVar1 = 0;
  }
  return uVar1;
}

undefined4 __WaveScene_Set__FUlUli(uint param_1,uint param_2,undefined4 param_3)
{
  undefined4 uVar1;
  int iVar2;
  
  if (param_1 < 0x100) {
    iVar2 = *(int *)(wavegroup + param_1 * 4);
    if (iVar2 == 0) {
      uVar1 = 0;
    }
    else if (param_2 < *(uint *)(iVar2 + 8)) {
      uVar1 = Jac_SceneSet__FP16WaveArchiveBank_P10CtrlGroup_Uli
                        (*(undefined4 *)(wavearc + param_1 * 4),iVar2,param_2,param_3);
    }
    else {
      uVar1 = 0;
    }
  }
  else {
    uVar1 = 0;
  }
  return uVar1;
}

void WaveScene_Set__FUlUl(undefined4 param_1,undefined4 param_2)
{
  __WaveScene_Set__FUlUli(param_1,param_2,1);
  return;
}

void WaveScene_Load__FUlUl(undefined4 param_1,undefined4 param_2)
{
  __WaveScene_Set__FUlUli(param_1,param_2,0);
  return;
}

void __WaveScene_Close__FUlUli(uint param_1,uint param_2,undefined4 param_3)
{
  int iVar1;
  
  if (param_1 < 0x100) {
    iVar1 = *(int *)(wavegroup + param_1 * 4);
    if ((iVar1 != 0) && (param_2 < *(uint *)(iVar1 + 8))) {
      Jac_SceneClose__FP16WaveArchiveBank_P10CtrlGroup_Uli
                (*(undefined4 *)(wavearc + param_1 * 4),iVar1,param_2,param_3);
    }
  }
  return;
}

void WaveScene_Close__FUlUl(undefined4 param_1,undefined4 param_2)
{
  __WaveScene_Close__FUlUli(param_1,param_2,1);
  return;
}

void WaveScene_Erase__FUlUl(undefined4 param_1,undefined4 param_2)
{
  __WaveScene_Close__FUlUli(param_1,param_2,0);
  return;
}

