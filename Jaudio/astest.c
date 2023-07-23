void CopyStc__FP9commonch_P9commonch_(int param_1,int param_2)
{
  undefined4 uVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  int iVar4;
  
  iVar4 = 4;
  puVar2 = (undefined4 *)(param_2 + -8);
  puVar3 = (undefined4 *)(param_1 + -8);
  do {
    uVar1 = puVar2[3];
    puVar3[2] = puVar2[2];
    puVar3[3] = uVar1;
    iVar4 = iVar4 + -1;
    puVar2 = puVar2 + 2;
    puVar3 = puVar3 + 2;
  } while (iVar4 != 0);
  return;
}

