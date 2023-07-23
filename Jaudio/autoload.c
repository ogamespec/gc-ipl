void __FinishCall__FUl(void)
{
  return;
}

undefined1 * Jac_GetPhysicalBankFileName(int param_1)
{
  return filename_table + param_1 * 0x20;
}

int OpenDirectory__FPc(char *param_1)
{
  int iVar1;
  char *pcVar2;
  size_t sVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  char acStack_1f8 [128];
  char acStack_178 [128];
  char acStack_f8 [128];
  int local_78;
  int local_74;
  undefined auStack_34 [4];
  int local_30;
  char *local_2c;
  int local_28;
  int local_24;
  
  iVar6 = 0;
  iVar5 = 0;
  for (local_78 = 0; local_78 < 0x80; local_78 = local_78 + 1) {
    strcpy(filename_table + local_78 * 0x20,(char *)&@123);
  }
  Bank_Init__Fv();
  Wavegroup_Init__Fv();
  strcpy(acStack_178,param_1);
  iVar1 = DVDOpenDir(acStack_178,&local_28);
  if (iVar1 != 0) {
    local_74 = 1;
    strcpy(acStack_f8,acStack_178);
    local_24 = local_28 + 1;
    while (iVar1 = DVDReadDir(&local_28,auStack_34), iVar1 != 0) {
      if (local_30 != 1) {
        strcpy(acStack_1f8,acStack_178);
        strcat(acStack_1f8,(char *)&@124);
        strcat(acStack_1f8,local_2c);
        pcVar2 = strstr(acStack_1f8,(char *)&@125);
        if (pcVar2 != (char *)0x0) {
          Jac_CheckFile__FPc(acStack_1f8);
          iVar1 = OSAlloc2();
          if (iVar1 == 0) {
            return 0;
          }
          Jac_LoadFile__FPcPUc(acStack_1f8,iVar1);
          Bank_Regist__FPvUl(iVar1,iVar6);
          sVar3 = strlen(acStack_1f8);
          iVar4 = sVar3 - 1;
          iVar1 = iVar4;
          if (0 < iVar4) {
            do {
              if (acStack_1f8[iVar4] == '.') {
                acStack_1f8[iVar4] = '\0';
                break;
              }
              iVar4 = iVar4 + -1;
              iVar1 = iVar1 + -1;
            } while (iVar1 != 0);
          }
          pcVar2 = acStack_1f8 + iVar4;
          iVar1 = iVar4;
          if (0 < iVar4) {
            do {
              if (*pcVar2 == '/') {
                iVar4 = iVar4 + 1;
                break;
              }
              iVar4 = iVar4 + -1;
              pcVar2 = pcVar2 + -1;
              iVar1 = iVar1 + -1;
            } while (iVar1 != 0);
          }
          strcpy(filename_table + iVar5,acStack_1f8 + iVar4);
          strcat(acStack_1f8,(char *)&@126);
          Jac_CheckFile__FPc(acStack_1f8);
          iVar1 = OSAlloc2();
          if (iVar1 == 0) {
            return 0;
          }
          Jac_LoadFile__FPcPUc(acStack_1f8,iVar1);
          Wavegroup_Regist__FPvUl(iVar1,iVar6);
          WaveScene_Set__FUlUl(iVar6,0);
          Jac_BnkConnectTableSet__FUlUl(iVar6,iVar6);
          iVar6 = iVar6 + 1;
          iVar5 = iVar5 + 0x20;
        }
      }
      local_74 = local_74 + 1;
    }
    DVDCloseDir(&local_28);
    DVDChangeDir(acStack_178);
  }
  DVDT_CheckPass__FUlPUlPFUl_v(0x16d,0,0x10000);
  return local_74;
}

void AutoLoad(void)
{
  Jac_WaveDirectorySet__FPc("/AutoLoad/");
  OpenDirectory__FPc("/AutoLoad");
  return;
}

