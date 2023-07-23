
void Jac_RegisterARAMCallback__FPFPcUlUlPUlP7jaheap__Ul(undefined *param_1)
{
  ARCALL = param_1;
  return;
}

undefined4 LoadAram__FPcPUlUl(undefined4 param_1,undefined4 param_2,undefined4 param_3)
{
  int iVar1;
  
  iVar1 = DVDT_LoadtoARAM__FUlPcUlUlUlPUlPFUl_v(0,param_1,param_3,0,0,param_2,0);
  if (iVar1 == -1) {
    param_3 = 0;
  }
  return param_3;
}

undefined4
LoadAramSingle__FPcUlUlPUlUl
          (undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
          undefined4 param_5)
{
  int iVar1;
  
  iVar1 = DVDT_LoadtoARAM__FUlPcUlUlUlPUlPFUl_v(0,param_1,param_5,param_2,param_3,param_4,0);
  if (iVar1 == -1) {
    param_5 = 0;
  }
  return param_5;
}

void Jac_WaveDirectorySet__FPc(char *param_1)
{
  strcpy(extdir,param_1);
  return;
}

undefined1 * Get_AramMotherHeap__Fv(void)
{
  return aram_mother;
}

void Show_AramMotherHeap__Fv(void)
{
  Jac_ShowHeap__FP7jaheap_Ul(aram_mother,0);
  return;
}

void Collect_AramMotherHeap__Fv(void)
{
  Jac_GarbageCollection_St__FP7jaheap_(aram_mother);
  Show_AramMotherHeap__Fv();
  return;
}

void Init_AramMotherHeap__Fv(void)
{
  undefined4 uVar1;
  undefined4 local_8 [2];
  
  if (init$64 == '\0') {
    inited$63 = 0;
    init$64 = '\x01';
  }
  if (inited$63 == 0) {
    inited$63 = 1;
    uVar1 = ARAllocFull__FPUl(local_8);
    Jac_InitMotherHeap__FP7jaheap_UlUlUc(aram_mother,uVar1,local_8[0],0);
  }
  return;
}

undefined4
LoadAram_Default__FPcUlUlPUlP7jaheap_
          (char *param_1,int param_2,int param_3,undefined4 param_4,int param_5)
{
  undefined4 uVar1;
  int iVar2;
  char acStack_a4 [144];
  
  if (first != 0) {
    Init_AramMotherHeap__Fv();
    first = 0;
  }
  strcpy(acStack_a4,extdir);
  strcat(acStack_a4,param_1);
  if ((param_2 == 0) && (param_3 == 0)) {
    uVar1 = DVDT_CheckFile__FPc(acStack_a4);
    iVar2 = Jac_AllocHeap__FP7jaheap_P7jaheap_Ul(param_5,aram_mother,uVar1);
    if (iVar2 == 0) {
      uVar1 = 0;
    }
    else {
      uVar1 = LoadAram__FPcPUlUl(acStack_a4,param_4,*(undefined4 *)(param_5 + 8));
    }
  }
  else {
    iVar2 = Jac_AllocHeap__FP7jaheap_P7jaheap_Ul(param_5,aram_mother,param_3);
    if (iVar2 == 0) {
      uVar1 = 0;
    }
    else {
      uVar1 = LoadAramSingle__FPcUlUlPUlUl
                        (acStack_a4,param_2,param_3,param_4,*(undefined4 *)(param_5 + 8));
    }
  }
  return uVar1;
}

void LoadAram_All__FPcPUlP7jaheap_(undefined4 param_1,undefined4 param_2,undefined4 param_3)
{
  (*(code *)ARCALL)(param_1,0,0,param_2,param_3);
  return;
}

void LoadAram_One__FPcUlUlPUlP7jaheap_(void)
{
  (*(code *)ARCALL)();
  return;
}

