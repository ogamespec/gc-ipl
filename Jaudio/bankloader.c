void Bank_Setup__FPc(undefined4 param_1)
{
  int iVar1;
  int *piVar2;
  int *piVar3;
  uint uVar4;
  uint uVar5;
  int iVar6;
  
  OSReport(...rodata.0);
  Bank_Init__Fv();
  DVDT_CheckFile__FPc(param_1);
  piVar2 = (int *)OSAlloc2();
  if (piVar2 == (int *)0x0) {
    Console_printf(@100);
  }
  DVDT_LoadFile__FPcPUc(param_1,piVar2);
  Console_printf(@101);
  Wavegroup_Init__Fv();
  iVar1 = *piVar2;
  uVar5 = piVar2[1];
  iVar6 = 0;
  for (uVar4 = 0; uVar4 < uVar5; uVar4 = uVar4 + 1) {
    piVar3 = (int *)((int)piVar2 + iVar6 + iVar1);
    if (piVar3[1] != 0) {
      Wavegroup_Regist__FPvUl((int)piVar2 + *piVar3,uVar4);
    }
    iVar6 = iVar6 + 8;
  }
  OSReport(@102);
  iVar1 = piVar2[2];
  uVar5 = piVar2[3];
  iVar6 = 0;
  for (uVar4 = 0; uVar4 < uVar5; uVar4 = uVar4 + 1) {
    piVar3 = (int *)((int)piVar2 + iVar6 + iVar1);
    if (piVar3[1] != 0) {
      Bank_Regist__FPvUl((int)piVar2 + *piVar3,uVar4);
    }
    iVar6 = iVar6 + 8;
  }
  OSReport(@103);
  return;
}
