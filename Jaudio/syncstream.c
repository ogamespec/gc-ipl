void Stop_DirectPCM__FP6dspch_(undefined *param_1)
{
  DSP_PlayStop__FUc(*param_1);
  DSP_FlushChannel__FUc(*param_1);
  return;
}

void Play_DirectPCM__FP6dspch_PsUsUl
               (undefined *param_1,undefined4 param_2,int param_3,undefined4 param_4)
{
  int iVar1;
  uint uVar2;
  
  iVar1 = GetDspHandle__FUc(*param_1);
  *(undefined4 *)(iVar1 + 0x118) = param_2;
  *(undefined2 *)(iVar1 + 0x102) = 0;
  *(undefined2 *)(iVar1 + 0x100) = 0x21;
  *(undefined4 *)(iVar1 + 0x74) = param_4;
  *(undefined4 *)(iVar1 + 0x110) = param_2;
  *(int *)(iVar1 + 0x114) = param_3 << 0x10;
  DSP_SetMixerInitDelayMax__FUcUc(*param_1,0);
  uVar2 = 0;
  do {
    if (uVar2 < 2) {
      DSP_SetMixerInitVolume__FUcUcsUc(*param_1,uVar2 & 0xff,0x7fff,0);
    }
    else {
      DSP_SetMixerInitVolume__FUcUcsUc(*param_1,uVar2 & 0xff,0,0);
    }
    DSP_SetBusConnect__FUcUcUc(*param_1,uVar2 & 0xff,uVar2 + 1);
    uVar2 = uVar2 + 1;
  } while (uVar2 < 6);
  DSP_SetPitch__FUcUs(*param_1,0x800);
  DSP_PlayStart__FUc(*param_1);
  DSP_FlushChannel__FUc(*param_1);
  return;
}

uint Get_DirectPCM_LoopRemain__FP11DSPchannel_(int param_1)
{
  return *(uint *)(param_1 + 0x6c) >> 0x10;
}

uint Get_DirectPCM_Counter__FP11DSPchannel_(int param_1)
{
  return *(uint *)(param_1 + 0x68) >> 0x10;
}

undefined4 Get_DirectPCM_Remain__FP11DSPchannel_(int param_1)
{
  return *(undefined4 *)(param_1 + 0x74);
}

void __LoadFin__FlP11DVDFileInfo(undefined4 param_1,int param_2)
{
  uint uVar1;
  undefined1 *puVar2;
  undefined1 *in_r8;
  int iVar3;
  int iVar4;
  
  iVar3 = 0;
  iVar4 = 2;
  do {
    puVar2 = SC + iVar3 * 0x1518c;
    if (param_2 == iVar3 * 0x1518c + 0x26938) break;
    iVar3 = iVar3 + 1;
    iVar4 = iVar4 + -1;
    puVar2 = in_r8;
  } while (iVar4 != 0);
  uVar1 = (byte)SC[(int)(puVar2 + 0x3882)] + 1;
  puVar2[(uint)(byte)SC[(int)(puVar2 + 0x3882)] * 0x10 + 0x15000] = 2;
  SC[(int)(puVar2 + 0x3882)] =
       (char)uVar1 - (char)(uVar1 / (byte)SC[(int)(puVar2 + 0x3881)]) * SC[(int)(puVar2 + 0x3881)];
  return;
}

/* WARNING: Removing unreachable block (ram,0x000102c0) */
void LoadADPCM__FP11StreamCtrl_i(int param_1,int param_2)
{
  uint uVar1;
  int iVar2;
  uint uVar3;
  char *pcVar4;
  
  pcVar4 = (char *)(param_1 + (uint)(byte)SC[param_1 + 0x3882] * 0x10 + 0x15000);
  if ((*pcVar4 == '\0') && (uVar1 = *(uint *)(SC + param_1 + 0x38b0), uVar1 != 0)) {
    uVar3 = *(uint *)(SC + param_1 + 0x38b8);
    if (uVar1 < *(uint *)(SC + param_1 + 0x38b8)) {
      uVar3 = uVar1;
    }
    if ((SC[param_1 + 0x3968] != '\0') || (iVar2 = Jac_CheckStreamRemain__FUl(uVar3), iVar2 != 0)) {
      *(undefined4 *)(pcVar4 + 4) = 0;
      *(uint *)(pcVar4 + 8) = uVar3;
      *pcVar4 = '\x01';
      if (param_2 != 0) {
        *(uint *)(SC + param_1 + 0x388c) = uVar3;
        *(undefined4 *)(SC + param_1 + 0x3888) = 0;
      }
      if (SC[param_1 + 0x3968] == '\x01') {
        DVDReadAsyncPrio(param_1 + 0x15118,*(undefined4 *)(pcVar4 + 0xc),uVar3,
                         *(undefined4 *)(SC + param_1 + 0x38b4),__LoadFin__FlP11DVDFileInfo,2);
      }
      else if (SC[param_1 + 0x3968] == '\0') {
        Jac_GetStreamData__FPUcUl(*(undefined4 *)(pcVar4 + 0xc),uVar3);
        __LoadFin__FlP11DVDFileInfo(0,param_1 + 0x15118);
      }
      *(uint *)(SC + param_1 + 0x38b4) = *(int *)(SC + param_1 + 0x38b4) + uVar3;
      *(uint *)(SC + param_1 + 0x38b0) = *(int *)(SC + param_1 + 0x38b0) - uVar3;
      *(uint *)(SC + param_1 + 0x38bc) = uVar3;
    }
  }
  return;
}

void BufContInit__FP11BufControl_UcUcUcUcUlUlUl
               (undefined *param_1,undefined param_2,undefined param_3,undefined param_4,
               undefined param_5,undefined4 param_6,undefined4 param_7,undefined4 param_8)
{
  *param_1 = param_2;
  param_1[1] = param_3;
  param_1[2] = param_4;
  param_1[3] = param_5;
  *(undefined4 *)(param_1 + 4) = param_6;
  *(undefined4 *)(param_1 + 8) = param_7;
  *(undefined4 *)(param_1 + 0xc) = param_8;
  return;
}

void Init_StreamAudio(void)
{
  int iVar1;
  int iVar2;
  
  iVar1 = 0;
  iVar2 = 2;
  do {
    *(undefined4 *)(SC + iVar1 * 0x1518c + 0x150e4) = 4;
    *(int *)(SC + iVar1 * 0x1518c + 0x1516c) = iVar1;
    iVar1 = iVar1 + 1;
    iVar2 = iVar2 + -1;
  } while (iVar2 != 0);
  return;
}

int Get_StreamAudio_Handle(void)
{
  int iVar1;
  int iVar2;
  
  iVar1 = 0;
  iVar2 = 2;
  do {
    if (*(int *)(SC + iVar1 * 0x1518c + 0x150e4) == 4) {
      return iVar1;
    }
    iVar1 = iVar1 + 1;
    iVar2 = iVar2 + -1;
  } while (iVar2 != 0);
  return -1;
}

undefined4
StreamAudio_Start(int param_1,undefined4 param_2,int param_3,undefined4 param_4,undefined4 param_5,
                 int param_6)
{
  ushort uVar1;
  undefined4 uVar2;
  undefined1 *puVar3;
  int iVar4;
  undefined4 *puVar5;
  int iVar6;
  uint uVar7;
  undefined4 *puVar8;
  undefined1 *puVar9;
  int iVar10;
  int iVar11;
  
  iVar6 = param_1 * 0x1518c;
  puVar9 = SC + iVar6;
  *(int *)(SC + iVar6 + 0x1516c) = param_1;
  *(undefined4 *)(SC + iVar6 + 0x15170) = param_2;
  *(undefined4 *)(SC + iVar6 + 0x1510c) = 0;
  *(undefined4 *)(SC + iVar6 + 0x15114) = 0;
  *(undefined4 *)(SC + iVar6 + 0x15110) = 0;
  if (param_3 == 0) {
    SC[iVar6 + 0x15188] = 0;
  }
  else {
    Jac_DVDOpen__FPcP11DVDFileInfo(param_3,iVar6 + 0x26938);
    SC[iVar6 + 0x15188] = 1;
  }
  if (param_6 == 0) {
    if (SC[iVar6 + 0x15188] == '\0') {
      return 0;
    }
    DVDReadPrio(iVar6 + 0x26938,puVar9,0x20,0,2);
    iVar10 = 4;
    puVar8 = (undefined4 *)(table4 + iVar6 + 0x18);
    puVar5 = (undefined4 *)(SC + iVar6 + 0x150e0);
    do {
      uVar2 = puVar8[3];
      puVar5[2] = puVar8[2];
      puVar5[3] = uVar2;
      iVar10 = iVar10 + -1;
      puVar8 = puVar8 + 2;
      puVar5 = puVar5 + 2;
    } while (iVar10 != 0);
    *(undefined4 *)(SC + iVar6 + 0x150d4) = 0x20;
  }
  else {
    iVar10 = 4;
    puVar8 = (undefined4 *)(param_6 + -8);
    puVar5 = (undefined4 *)(SC + iVar6 + 0x150e0);
    do {
      uVar2 = puVar8[3];
      puVar5[2] = puVar8[2];
      puVar5[3] = uVar2;
      iVar10 = iVar10 + -1;
      puVar8 = puVar8 + 2;
      puVar5 = puVar5 + 2;
    } while (iVar10 != 0);
    *(undefined4 *)(SC + iVar6 + 0x150d4) = 0;
  }
  *(undefined4 *)(SC + iVar6 + 0x150d0) = *(undefined4 *)(SC + iVar6 + 0x150e8);
  iVar4 = 0;
  *(undefined4 *)(SC + iVar6 + 0x1515c) = *(undefined4 *)(SC + iVar6 + 0x150ec);
  *(undefined4 *)(SC + iVar6 + 0x150e0) = 0;
  *(undefined4 *)(SC + iVar6 + 0x15168) = 0;
  *(undefined4 *)(SC + iVar6 + 0x150e4) = 0;
  iVar11 = 8;
  iVar10 = 0;
  do {
    puVar3 = puVar9 + iVar4;
    iVar4 = iVar4 + 0x1200;
    SC[(int)(puVar9 + iVar10 + 0x37e0)] = 0;
    *(undefined1 **)(SC + (int)(puVar9 + iVar10 + 0x37ec)) = puVar3;
    iVar11 = iVar11 + -1;
    iVar10 = iVar10 + 0x10;
  } while (iVar11 != 0);
  iVar4 = 2;
  iVar10 = 0;
  do {
    puVar9[iVar10 + 0x15080] = 0;
    iVar4 = iVar4 + -1;
    iVar10 = iVar10 + 0x10;
  } while (iVar4 != 0);
  *(undefined4 *)(SC + iVar6 + 0x15160) = 0x1000;
  BufContInit__FP11BufControl_UcUcUcUcUlUlUl(iVar6 + 0x268c0,1,8,0,0,0x1200,0,0);
  BufContInit__FP11BufControl_UcUcUcUcUlUlUl(iVar6 + 0x268d0,2,2,0,0,0x1000,0,0);
  BufContInit__FP11BufControl_UcUcUcUcUlUlUl(iVar6 + 0x268e0,2,4,0,3,0x400,0,0);
  uVar1 = *(ushort *)(SC + iVar6 + 0x150f2);
  if (uVar1 == 3) {
    *(undefined4 *)(SC + iVar6 + 0x150d8) = 0x900;
  }
  else if (uVar1 < 3) {
    if (1 < uVar1) {
      *(undefined4 *)(SC + iVar6 + 0x150d8) = 0x1200;
    }
  }
  else if (uVar1 < 5) {
    *(undefined4 *)(SC + iVar6 + 0x150d8) = 0x1200;
  }
  *(undefined4 *)(SC + iVar6 + 0x15108) = param_4;
  LoadADPCM__FP11StreamCtrl_i(puVar9,1);
  uVar7 = 0;
  iVar10 = 0;
  do {
    puVar8 = (undefined4 *)(puVar9 + iVar10 + 0x15154);
    DeAllocDSPchannel__FP6dspch_Ul(*puVar8,puVar8);
    uVar7 = uVar7 + 1;
    *puVar8 = 0;
    iVar10 = iVar10 + 4;
  } while (uVar7 < 2);
  *(undefined4 *)(SC + iVar6 + 0x15184) = @157;
  *(undefined2 *)(SC + iVar6 + 0x15180) = 0x3fff;
  *(undefined2 *)(SC + iVar6 + 0x15182) = 0x3fff;
  *(undefined4 *)(SC + iVar6 + 0x15174) = default_streamsync_call;
  Jac_RegisterDspPlayerCallback(StreamAudio_Callback__FPv,puVar9);
  return 1;
}

/* WARNING: Removing unreachable block (ram,0x00010998) */
void StreamAudio_Callback__FPv(void)
{
  bool bVar1;
  float fVar2;
  int iVar3;
  int iVar4;
  undefined4 uVar5;
  uint uVar6;
  int iVar7;
  int *piVar8;
  undefined4 *puVar9;
  int iVar10;
  double dVar11;
  double dVar12;
  
  iVar3 = _savefpr_30();
  bVar1 = false;
  if (*(int *)(SC + iVar3 + 0x3934) == 0) {
    uVar6 = 0;
    iVar7 = 0;
    do {
      piVar8 = (int *)(iVar3 + iVar7 + 0x15154);
      iVar4 = AllocDSPchannel__FUlUl(0,piVar8);
      *piVar8 = iVar4;
      uVar6 = uVar6 + 1;
      iVar7 = iVar7 + 4;
      *(undefined *)(*piVar8 + 3) = 0x7f;
    } while (uVar6 < 2);
  }
  if (*(int *)(SC + iVar3 + 0x3948) != 0) {
    iVar7 = GetDspHandle__FUc(**(undefined **)(SC + iVar3 + 0x3934));
    if (*(short *)(iVar7 + 2) != 0) {
      *(undefined4 *)(SC + iVar3 + 0x38f4) = 1;
    }
    if (*(int *)(SC + iVar3 + 0x38f4) != 0) {
      if (SC[iVar3 + (uint)(byte)SC[iVar3 + 0x3882] * 0x10 + 0x37e0] == '\x01') {
        uVar5 = 0;
      }
      else {
        uVar6 = 0;
        iVar7 = 0;
        do {
          puVar9 = (undefined4 *)(iVar3 + iVar7 + 0x15154);
          Stop_DirectPCM__FP6dspch_(*puVar9);
          DeAllocDSPchannel__FP6dspch_Ul(*puVar9,puVar9);
          uVar6 = uVar6 + 1;
          *puVar9 = 0;
          iVar7 = iVar7 + 4;
        } while (uVar6 < 2);
        if (*(code **)(SC + iVar3 + 0x3954) != (code *)0x0) {
          (**(code **)(SC + iVar3 + 0x3954))(*(undefined4 *)(SC + iVar3 + 0x394c),0xffffffff);
        }
        *(undefined4 *)(SC + iVar3 + 0x38c4) = 4;
        *(undefined4 *)(SC + iVar3 + 0x3950) = 0xffffffff;
        if (SC[iVar3 + 0x3968] != '\0') {
          DVDClose(iVar3 + 0x15118);
        }
        uVar5 = 0xffffffff;
      }
      goto LAB_00010e0c;
    }
    if ((*(code **)(SC + iVar3 + 0x3954) != (code *)0x0) &&
       (iVar4 = (**(code **)(SC + iVar3 + 0x3954))
                          (*(undefined4 *)(SC + iVar3 + 0x394c),
                           (*(int *)(SC + iVar3 + 0x38c0) * (uint)*(ushort *)(SC + iVar3 + 0x38d6))
                           / (uint)*(ushort *)(SC + iVar3 + 0x38d0)), iVar4 == -1)) {
      *(undefined4 *)(SC + iVar3 + 0x38ec) = 1;
    }
    *(int *)(SC + iVar3 + 0x3948) = *(int *)(SC + iVar3 + 0x3948) + 1;
    uVar6 = Get_DirectPCM_LoopRemain__FP11DSPchannel_(iVar7);
    uVar6 = *(int *)(SC + iVar3 + 0x3940) - (uVar6 & 0xffff);
    SC[iVar3 + 0x38a3] = (char)(uVar6 >> 10);
    if ((uint)(byte)SC[iVar3 + 0x38a2] == uVar6 >> 10) {
      bVar1 = false;
    }
    else {
      bVar1 = true;
    }
  }
  if (*(int *)(SC + iVar3 + 0x38f0) == 0) {
    if (*(int *)(SC + iVar3 + 0x38c4) == 6) {
      *(undefined4 *)(SC + iVar3 + 0x38c4) = 1;
      DSP_SetPauseFlag__FUcUc(**(undefined **)(SC + iVar3 + 0x3934),0);
      DSP_SetPauseFlag__FUcUc(**(undefined **)(SC + iVar3 + 0x3938),0);
      DSP_FlushChannel__FUc(**(undefined **)(SC + iVar3 + 0x3934));
      DSP_FlushChannel__FUc(**(undefined **)(SC + iVar3 + 0x3938));
    }
    if (((*(int *)(SC + iVar3 + 0x38b0) != 0) && (*(int *)(SC + iVar3 + 0x38c4) != 5)) &&
       (*(uint *)(SC + iVar3 + 0x389c) < *(uint *)(SC + iVar3 + 0x38a4))) {
      DSP_SetPauseFlag__FUcUc(**(undefined **)(SC + iVar3 + 0x3934),1);
      DSP_SetPauseFlag__FUcUc(**(undefined **)(SC + iVar3 + 0x3938),1);
      DSP_FlushChannel__FUc(**(undefined **)(SC + iVar3 + 0x3934));
      DSP_FlushChannel__FUc(**(undefined **)(SC + iVar3 + 0x3938));
      *(undefined4 *)(SC + iVar3 + 0x38c4) = 5;
    }
    if ((*(int *)(SC + iVar3 + 0x38c4) == 5) &&
       (*(uint *)(SC + iVar3 + 0x38a4) < *(uint *)(SC + iVar3 + 0x389c))) {
      DSP_SetPauseFlag__FUcUc(**(undefined **)(SC + iVar3 + 0x3934),0);
      DSP_SetPauseFlag__FUcUc(**(undefined **)(SC + iVar3 + 0x3938),0);
      DSP_FlushChannel__FUc(**(undefined **)(SC + iVar3 + 0x3934));
      DSP_FlushChannel__FUc(**(undefined **)(SC + iVar3 + 0x3938));
      *(undefined4 *)(SC + iVar3 + 0x38c4) = 1;
    }
    iVar7 = iVar3 + 0x10000;
    if ((*(char *)(iVar7 + (uint)(byte)SC[iVar3 + 0x3883] * 0x10 + 0x5000) == '\x02') &&
       (*(char *)(iVar7 + (uint)(byte)SC[iVar3 + 0x3892] * 0x10 + 0x5080) == '\0')) {
      iVar4 = __Decode__FP11StreamCtrl_(iVar3);
      *(undefined *)(iVar7 + (uint)(byte)SC[iVar3 + 0x3883] * 0x10 + 0x5000) = 0;
      *(undefined *)(iVar7 + (uint)(byte)SC[iVar3 + 0x3892] * 0x10 + 0x5080) = 2;
      *(undefined4 *)(iVar7 + (uint)(byte)SC[iVar3 + 0x3892] * 0x10 + 0x5084) = 0;
      *(int *)(iVar7 + (uint)(byte)SC[iVar3 + 0x3892] * 0x10 + 0x5088) = iVar4;
      SC[iVar3 + 0x3883] =
           (char)((byte)SC[iVar3 + 0x3883] + 1) +
           (char)((int)((byte)SC[iVar3 + 0x3883] + 1) >> 3) * -8;
      SC[iVar3 + 0x3892] =
           (char)((byte)SC[iVar3 + 0x3892] + 1) +
           (char)((int)((byte)SC[iVar3 + 0x3892] + 1) >> 1) * -2;
      *(int *)(SC + iVar3 + 0x389c) = *(int *)(SC + iVar3 + 0x389c) + iVar4;
    }
    if ((bVar1) || (*(int *)(SC + iVar3 + 0x3948) == 0)) {
      if (SC[iVar3 + 0x38a2] == SC[iVar3 + 0x38a3]) {
        if (*(int *)(SC + iVar3 + 0x3948) == 0) {
          if (*(int *)(SC + iVar3 + 0x38e8) == 1) {
            if (*(code **)(SC + iVar3 + 0x3954) != (code *)0x0) {
              iVar7 = (**(code **)(SC + iVar3 + 0x3954))(*(undefined4 *)(SC + iVar3 + 0x394c),0);
              if (iVar7 == -1) {
                *(undefined4 *)(SC + iVar3 + 0x38ec) = 1;
              }
              if (iVar7 == 1) {
                *(undefined4 *)(SC + iVar3 + 0x38e8) = 0;
              }
            }
            *(undefined4 *)(SC + iVar3 + 0x38c4) = 2;
            if (*(int *)(SC + iVar3 + 0x38ec) == 0) {
              uVar5 = 0;
              goto LAB_00010e0c;
            }
          }
          else {
            uVar6 = 0;
            *(undefined4 *)(SC + iVar3 + 0x38c4) = 1;
            iVar10 = 0;
            iVar4 = 0;
            iVar7 = 0;
            *(int *)(SC + iVar3 + 0x3948) = *(int *)(SC + iVar3 + 0x3948) + 1;
            dVar11 = (double)@271;
            dVar12 = @273;
            do {
              puVar9 = (undefined4 *)(iVar3 + iVar7 + 0x15154);
              fVar2 = ((float)(dVar11 * (double)(float)((double)CONCAT44(0x43300000,
                                                                         (uint)*(ushort *)
                                                                                (SC + iVar3 + 0x38d0
                                                                                )) - dVar12)) *
                      *(float *)(SC + iVar3 + 0x3964)) / fRam00000000;
              Play_DirectPCM__FP6dspch_PsUsUl
                        (*puVar9,__DecodeADPCM__FP11StreamCtrl_ + iVar3 + iVar4,
                         *(uint *)(SC + iVar3 + 0x3940) & 0xffff,
                         *(undefined4 *)(SC + iVar3 + 0x393c));
              DSP_SetMixerInitVolume__FUcUcsUc
                        (*(undefined *)*puVar9,uVar6 & 0xff,
                         (int)*(short *)(iVar3 + iVar10 + 0x15180),0);
              DSP_SetMixerInitVolume__FUcUcsUc(*(undefined *)*puVar9,1 - uVar6,0,0);
              DSP_SetPitch__FUcUs(*(undefined *)*puVar9,(int)fVar2);
              DSP_FlushChannel__FUc(*(undefined *)*puVar9);
              uVar6 = uVar6 + 1;
              iVar4 = iVar4 + 0x2000;
              iVar7 = iVar7 + 4;
              iVar10 = iVar10 + 2;
            } while (uVar6 < 2);
          }
        }
      }
      else if ((SC[iVar3 + (uint)(byte)SC[iVar3 + 0x3893] * 0x10 + 0x3860] == '\x02') &&
              (*(uint *)(SC + iVar3 + 0x38a4) <= *(uint *)(SC + iVar3 + 0x389c))) {
        __PcmToLoop__FP11StreamCtrl_(iVar3);
        SC[iVar3 + 0x38a2] =
             (char)((byte)SC[iVar3 + 0x38a2] + 1) +
             (char)((int)((byte)SC[iVar3 + 0x38a2] + 1) >> 2) * -4;
        *(int *)(SC + iVar3 + 0x389c) =
             *(int *)(SC + iVar3 + 0x389c) - *(int *)(SC + iVar3 + 0x38a4);
      }
    }
    if (*(int *)(SC + iVar3 + 0x38c4) == 3) {
      uVar5 = 0;
    }
    else {
      if (*(int *)(SC + iVar3 + 0x38ec) == 0) {
        LoadADPCM__FP11StreamCtrl_i(iVar3,0);
      }
      else {
        if (*(int *)(SC + iVar3 + 0x3948) == 0) {
          if (SC[iVar3 + (uint)(byte)SC[iVar3 + 0x3882] * 0x10 + 0x37e0] == '\x01') {
            uVar5 = 0;
          }
          else {
            *(undefined4 *)(SC + iVar3 + 0x38ec) = 0;
            if (*(code **)(SC + iVar3 + 0x3954) != (code *)0x0) {
              (**(code **)(SC + iVar3 + 0x3954))(*(undefined4 *)(SC + iVar3 + 0x394c),0xffffffff);
            }
            *(undefined4 *)(SC + iVar3 + 0x38c4) = 4;
            uVar5 = 0xffffffff;
            *(undefined4 *)(SC + iVar3 + 0x3950) = 0xffffffff;
          }
          goto LAB_00010e0c;
        }
        uVar6 = 0;
        *(undefined4 *)(SC + iVar3 + 0x38ec) = 0;
        iVar7 = 0;
        *(undefined4 *)(SC + iVar3 + 0x38c4) = 3;
        do {
          ForceStopDSPchannel__FP6dspch_(*(undefined4 *)(iVar3 + iVar7 + 0x15154));
          uVar6 = uVar6 + 1;
          iVar7 = iVar7 + 4;
        } while (uVar6 < 2);
      }
      uVar5 = 0;
    }
  }
  else {
    DSP_SetPauseFlag__FUcUc(**(undefined **)(SC + iVar3 + 0x3934),1);
    DSP_SetPauseFlag__FUcUc(**(undefined **)(SC + iVar3 + 0x3938),1);
    DSP_FlushChannel__FUc(**(undefined **)(SC + iVar3 + 0x3934));
    DSP_FlushChannel__FUc(**(undefined **)(SC + iVar3 + 0x3938));
    uVar5 = 0;
    *(undefined4 *)(SC + iVar3 + 0x38c4) = 6;
  }
LAB_00010e0c:
  _restfpr_30(uVar5);
  return;
}

void RegisterStreamCallback(undefined4 param_1)
{
  default_streamsync_call = param_1;
  return;
}

void Jac_Decode_ADPCM(byte *param_1,short *param_2,short *param_3,uint param_4,char param_5,
                     short *param_6)
{
  byte bVar1;
  short sVar2;
  short sVar3;
  byte bVar4;
  byte *pbVar5;
  short sVar6;
  short sVar7;
  short sVar8;
  uint uVar9;
  int iVar10;
  int iVar11;
  int iVar12;
  
  sVar6 = *param_6;
  iVar11 = (int)param_6[1];
  sVar7 = param_6[2];
  iVar10 = (int)param_6[3];
  for (uVar9 = 0; uVar9 < param_4; uVar9 = uVar9 + 1) {
    bVar4 = *param_1 >> 4;
    iVar12 = (*param_1 & 0xf) * 4;
    sVar2 = *(short *)(filter_table + iVar12);
    sVar3 = *(short *)(filter_table + iVar12 + 2);
    iVar12 = 8;
    param_1 = param_1 + 1;
    do {
      pbVar5 = param_1;
      bVar1 = *pbVar5;
      param_1 = pbVar5 + 1;
      sVar8 = (short)((int)*(short *)(table4 + ((int)(uint)bVar1 >> 4) * 2) << bVar4) +
              (short)((int)sVar2 * (int)sVar6 + (int)sVar3 * (int)(short)iVar11 >> 0xb);
      iVar11 = (int)sVar8;
      *param_2 = sVar8;
      sVar6 = (short)((int)*(short *)(table4 + (bVar1 & 0xf) * 2) << bVar4) +
              (short)(sVar2 * iVar11 + (int)sVar3 * (int)sVar6 >> 0xb);
      param_2[1] = sVar6;
      param_2 = param_2 + 2;
      iVar12 = iVar12 + -1;
    } while (iVar12 != 0);
    if (param_5 != '\0') {
      bVar4 = *param_1 >> 4;
      iVar12 = (*param_1 & 0xf) * 4;
      sVar2 = *(short *)(filter_table + iVar12);
      sVar3 = *(short *)(filter_table + iVar12 + 2);
      iVar12 = 8;
      param_1 = pbVar5 + 2;
      do {
        bVar1 = *param_1;
        param_1 = param_1 + 1;
        sVar8 = (short)((int)*(short *)(table4 + ((int)(uint)bVar1 >> 4) * 2) << bVar4) +
                (short)((int)sVar2 * (int)sVar7 + (int)sVar3 * (int)(short)iVar10 >> 0xb);
        iVar10 = (int)sVar8;
        *param_3 = sVar8;
        sVar7 = (short)((int)*(short *)(table4 + (bVar1 & 0xf) * 2) << bVar4) +
                (short)(sVar2 * iVar10 + (int)sVar3 * (int)sVar7 >> 0xb);
        param_3[1] = sVar7;
        param_3 = param_3 + 2;
        iVar12 = iVar12 + -1;
      } while (iVar12 != 0);
    }
  }
  *param_6 = sVar6;
  param_6[1] = (short)iVar11;
  param_6[2] = sVar7;
  param_6[3] = (short)iVar10;
  return;
}

void __DecodeADPCM__FP11StreamCtrl_(int param_1)
{
  byte bVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  uint uVar5;
  int iVar6;
  
  bVar1 = SC[param_1 + 0x3892];
  uVar4 = (uint)(byte)SC[param_1 + 0x3883];
  if ((*(int *)(SC + param_1 + 0x3948) == 0) && (uVar4 == 0)) {
    iVar6 = 4;
    iVar2 = 0;
    do {
      *(undefined2 *)(param_1 + iVar2 + 0x15178) = 0;
      iVar6 = iVar6 + -1;
      iVar2 = iVar2 + 2;
    } while (iVar6 != 0);
  }
  iVar2 = param_1 + 0x10000 + uVar4 * 0x10;
  iVar3 = *(int *)(iVar2 + 0x5004);
  iVar6 = param_1 + (uint)bVar1 * 0x2000;
  uVar5 = (uint)(*(int *)(iVar2 + 0x5008) - iVar3) / 0x12;
  Jac_Decode_ADPCM(param_1 + uVar4 * 0x1200 + iVar3,iVar6 + 0x9000,iVar6 + 0xd000,uVar5,1,
                   param_1 + 0x15178);
  *(uint *)(SC + param_1 + 0x38c0) = *(int *)(SC + param_1 + 0x38c0) + (uVar5 & 0x7ffffff) * 0x10;
  return;
}

undefined4 __Decode__FP11StreamCtrl_(int param_1,undefined4 param_2,undefined4 param_3)
{
  if (*(short *)(SC + param_1 + 0x38d2) == 4) {
    param_3 = __DecodeADPCM__FP11StreamCtrl_();
  }
  return param_3;
}

void __PcmToLoop__FP11StreamCtrl_(int param_1)
{
  byte bVar1;
  int iVar2;
  int iVar3;
  undefined2 *puVar4;
  uint uVar5;
  int iVar6;
  int iVar7;
  uint local_18;
  undefined2 *local_14;
  
  iVar2 = *(int *)(SC + param_1 + 0x38a4);
  iVar3 = param_1 + (uint)(byte)SC[param_1 + 0x38a2] * 0x800;
  puVar4 = (undefined2 *)(__DecodeADPCM__FP11StreamCtrl_ + iVar3);
  local_14 = (undefined2 *)(SC + iVar3 + 0x17e0);
  while (0 < iVar2) {
    bVar1 = SC[param_1 + 0x3893];
    iVar7 = param_1 + (uint)bVar1 * 0x10;
    local_18 = *(int *)(SC + param_1 + 0x3898) + *(int *)(SC + iVar7 + 0x3864);
    uVar5 = *(uint *)(SC + iVar7 + 0x3868);
    for (; (local_18 < uVar5 && (0 < iVar2)); iVar2 = iVar2 + -1) {
      iVar6 = param_1 + (uint)bVar1 * 0x2000 + local_18 * 2;
      *puVar4 = *(undefined2 *)(iVar6 + 0x9000);
      puVar4 = puVar4 + 1;
      *local_14 = *(undefined2 *)(iVar6 + 0xd000);
      local_18 = local_18 + 1;
      local_14 = local_14 + 1;
    }
    if (local_18 == uVar5) {
      SC[iVar7 + 0x3860] = 0;
      SC[param_1 + 0x3893] = bVar1 + 1 & 1;
      *(undefined4 *)(SC + param_1 + 0x3898) = 0;
    }
    else {
      *(uint *)(SC + param_1 + 0x3898) = local_18 - *(int *)(SC + iVar7 + 0x3864);
    }
  }
  DCStoreRange(__DecodeADPCM__FP11StreamCtrl_ + iVar3,*(int *)(SC + param_1 + 0x38a4) << 1);
  DCStoreRange(SC + iVar3 + 0x17e0,*(int *)(SC + param_1 + 0x38a4) << 1);
  return;
}

undefined4 StreamSyncCheckReady(int param_1)
{
  if (*(int *)(SC + param_1 * 0x1518c + 0x150e4) == 2) {
    return 1;
  }
  return 0;
}

undefined4 StreamSyncCheckReadyID(int param_1,int param_2)
{
  int iVar1;
  
  if (*(int *)(SC + param_1 * 0x1518c + 0x15170) == param_2) {
    iVar1 = *(int *)(SC + param_1 * 0x1518c + 0x150e4);
    if (iVar1 != 1) {
      if (iVar1 < 1) {
        if (-1 < iVar1) {
          return 1;
        }
      }
      else if (iVar1 < 3) {
        return 1;
      }
    }
  }
  return 0;
}

undefined4 StreamSyncCheckBusy(int param_1,int param_2)
{
  if (*(int *)(SC + param_1 * 0x1518c + 0x150e4) == 4) {
    return 0;
  }
  if ((*(int *)(SC + param_1 * 0x1518c + 0x15170) == param_2) &&
     (*(int *)(SC + param_1 * 0x1518c + 0x150e4) == 2)) {
    return 0;
  }
  return 1;
}

undefined4 StreamSyncPlayAudio(double param_1,int param_2,undefined2 param_3,undefined2 param_4)
{
  param_2 = param_2 * 0x1518c;
  if (*(int *)(SC + param_2 + 0x150e4) == 2) {
    *(undefined4 *)(SC + param_2 + 0x15108) = 0;
    *(float *)(SC + param_2 + 0x15184) = (float)param_1;
    *(undefined2 *)(SC + param_2 + 0x15180) = param_3;
    *(undefined2 *)(SC + param_2 + 0x15182) = param_4;
    return 1;
  }
  return 0;
}

undefined4 StreamSyncStopAudio(int param_1)
{
  if (*(int *)(SC + param_1 * 0x1518c + 0x150e4) == 4) {
    return 0;
  }
  if (*(int *)(SC + param_1 * 0x1518c + 0x150e4) == 3) {
    return 0;
  }
  *(undefined4 *)(SC + param_1 * 0x1518c + 0x1510c) = 1;
  return 1;
}

void StreamChgPitch(double param_1,int param_2)
{
  float fVar1;
  uint uVar2;
  undefined4 *puVar3;
  int iVar4;
  
  param_2 = param_2 * 0x1518c;
  uVar2 = 0;
  iVar4 = 0;
  *(float *)(SC + param_2 + 0x15184) = (float)param_1;
  fVar1 = (@271 * (float)((double)CONCAT44(0x43300000,(uint)*(ushort *)(SC + param_2 + 0x150f0)) -
                         @273) * *(float *)(SC + param_2 + 0x15184)) / fRam00000000;
  do {
    puVar3 = (undefined4 *)(param_2 + iVar4 + 0x26974);
    DSP_SetPitch__FUcUs(*(undefined *)*puVar3,(int)fVar1);
    DSP_FlushChannel__FUc(*(undefined *)*puVar3);
    uVar2 = uVar2 + 1;
    iVar4 = iVar4 + 4;
  } while (uVar2 < 2);
  return;
}

void StreamChgVolume(int param_1,undefined2 param_2,undefined2 param_3)
{
  uint uVar1;
  undefined4 *puVar2;
  int iVar3;
  int iVar4;
  
  param_1 = param_1 * 0x1518c;
  if (*(int *)(SC + param_1 + 0x15154) != 0) {
    *(undefined2 *)(SC + param_1 + 0x15180) = param_2;
    uVar1 = 0;
    iVar4 = 0;
    iVar3 = 0;
    *(undefined2 *)(SC + param_1 + 0x15182) = param_3;
    do {
      puVar2 = (undefined4 *)(SC + iVar3 + 0x15154 + param_1);
      DSP_SetMixerVolume__FUcUcsUc
                (*(undefined *)*puVar2,uVar1 & 0xff,(int)*(short *)(SC + iVar4 + 0x15180 + param_1),
                 0);
      DSP_FlushChannel__FUc(*(undefined *)*puVar2);
      uVar1 = uVar1 + 1;
      iVar3 = iVar3 + 4;
      iVar4 = iVar4 + 2;
    } while (uVar1 < 2);
  }
  return;
}

uint StreamGetCurrentFrame(uint param_1,int param_2)
{
  int iVar1;
  int iVar2;
  double local_30;
  double local_18;
  
  iVar2 = param_1 * 0x1518c;
  if (*(undefined **)(SC + iVar2 + 0x15154) == (undefined *)0x0) {
    param_1 = 0xffffffff;
  }
  else if (param_2 == 1) {
    local_18 = (double)CONCAT44(0x43300000,(uint)*(ushort *)(SC + iVar2 + 0x150f6));
    param_1 = (uint)((float)((double)CONCAT44(0x43300000,*(undefined4 *)(SC + iVar2 + 0x15168)) -
                            @273) *
                    ((float)(local_18 - @273) /
                    ((fRam00000000 * (float)((double)CONCAT44(0x43300000,fRam00000000) - @273)) /
                    (float)((double)CONCAT44(0x43300000,fRam00000000) - @273))));
  }
  else if (param_2 < 1) {
    if (-1 < param_2) {
      param_1 = (*(int *)(SC + iVar2 + 0x150e0) * (uint)*(ushort *)(SC + iVar2 + 0x150f6)) /
                (uint)*(ushort *)(SC + iVar2 + 0x150f0);
    }
  }
  else if (param_2 < 3) {
    if (*(int *)(SC + iVar2 + 0x15168) == 0) {
      param_1 = 0;
    }
    else {
      GetDspHandle__FUc(**(undefined **)(SC + iVar2 + 0x15154));
      iVar1 = Get_DirectPCM_Remain__FP11DSPchannel_();
      local_30 = (double)CONCAT44(0x43300000,*(int *)(SC + iVar2 + 0x1515c) - iVar1);
      param_1 = (uint)(@423 + ((float)(local_30 - @273) *
                              (float)((double)CONCAT44(0x43300000,
                                                       (uint)*(ushort *)(SC + iVar2 + 0x150f6)) -
                                     @273)) /
                              (float)((double)CONCAT44(0x43300000,
                                                       (uint)*(ushort *)(SC + iVar2 + 0x150f0)) -
                                     @273));
    }
  }
  return param_1;
}

undefined4 StreamSetDVDPause(int param_1,undefined4 param_2)
{
  undefined4 uVar1;
  
  param_1 = param_1 * 0x1518c;
  if (*(int *)(SC + param_1 + 0x15154) == 0) {
    return 0xffffffff;
  }
  uVar1 = *(undefined4 *)(SC + param_1 + 0x15110);
  *(undefined4 *)(SC + param_1 + 0x15110) = param_2;
  return uVar1;
}

