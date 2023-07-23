/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
void Nas_WaveDmaFrameWork__Fv(void)
{
  int iVar1;
  int iVar2;
  uint uVar3;
  
  iVar1 = 0;
  for (uVar3 = 0; uVar3 < _DAT_00017648; uVar3 = uVar3 + 1) {
    iVar2 = _DAT_00017640 + iVar1;
    if ((*(char *)(iVar2 + 0xe) != '\0') &&
       (*(char *)(iVar2 + 0xe) = *(char *)(iVar2 + 0xe) + -1, *(char *)(iVar2 + 0xe) == '\0')) {
      *(byte *)(iVar2 + 0xd) = DAT_00017852;
      *(char *)(DAT_00017852 + 0x17650) = (char)uVar3;
      DAT_00017852 = DAT_00017852 + 1;
    }
    iVar1 = iVar1 + 0x10;
  }
  iVar1 = _DAT_00017648 << 4;
  for (uVar3 = _DAT_00017648; uVar3 < _DAT_00017644; uVar3 = uVar3 + 1) {
    iVar2 = _DAT_00017640 + iVar1;
    if ((*(char *)(iVar2 + 0xe) != '\0') &&
       (*(char *)(iVar2 + 0xe) = *(char *)(iVar2 + 0xe) + -1, *(char *)(iVar2 + 0xe) == '\0')) {
      *(byte *)(iVar2 + 0xd) = DAT_00017853;
      *(char *)(DAT_00017853 + 0x17750) = (char)uVar3;
      DAT_00017853 = DAT_00017853 + 1;
    }
    iVar1 = iVar1 + 0x10;
  }
  _DAT_0001764c = 0;
  return;
}

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
int Nas_WaveDmaCallBack__FUlUllPUcl
              (uint param_1,int param_2,int param_3,byte *param_4,undefined4 param_5)
{
  bool bVar1;
  uint uVar2;
  uint uVar3;
  int iVar4;
  int iVar5;
  byte unaff_r30;
  int *unaff_r31;
  
  bVar1 = false;
  if ((param_3 != 0) || (_DAT_00017648 <= *param_4)) {
    iVar5 = _DAT_00017648 << 4;
    iVar4 = _DAT_00017644 - _DAT_00017648;
    uVar3 = _DAT_00017648;
    if (_DAT_00017648 < _DAT_00017644) {
      do {
        unaff_r31 = (int *)(_DAT_00017640 + iVar5);
        if ((-1 < (int)(param_1 - unaff_r31[1])) &&
           (param_1 - unaff_r31[1] <= (uint)*(ushort *)((int)unaff_r31 + 10) - param_2)) {
          if ((*(char *)((int)unaff_r31 + 0xe) == '\0') &&
             (uVar2 = (uint)DAT_00017851, uVar2 != DAT_00017853)) {
            if (*(byte *)((int)unaff_r31 + 0xd) != uVar2) {
              *(undefined *)(*(byte *)((int)unaff_r31 + 0xd) + 0x17750) =
                   *(undefined *)(uVar2 + 0x17750);
              *(undefined *)(_DAT_00017640 + (uint)*(byte *)(DAT_00017851 + 0x17750) * 0x10 + 0xd) =
                   *(undefined *)((int)unaff_r31 + 0xd);
            }
            DAT_00017851 = DAT_00017851 + 1;
          }
          *(undefined *)((int)unaff_r31 + 0xe) = 0x20;
          *param_4 = (byte)uVar3;
          return *unaff_r31 + (param_1 - unaff_r31[1]);
        }
        uVar3 = uVar3 + 1;
        iVar5 = iVar5 + 0x10;
        iVar4 = iVar4 + -1;
      } while (iVar4 != 0);
    }
    if (param_3 != 0) {
      uVar3 = (uint)DAT_00017851;
      if ((uVar3 != DAT_00017853) && (param_3 != 0)) {
        DAT_00017851 = DAT_00017851 + 1;
        unaff_r30 = *(byte *)(uVar3 + 0x17750);
        bVar1 = true;
        unaff_r31 = (int *)(_DAT_00017640 + (uint)unaff_r30 * 0x10);
      }
      goto LAB_00010344;
    }
  }
  iVar4 = 0;
  iVar5 = _DAT_00017648 + 1;
  unaff_r31 = (int *)(_DAT_00017640 + (uint)*param_4 * 0x10);
  do {
    if ((-1 < (int)(param_1 - unaff_r31[1])) &&
       (param_1 - unaff_r31[1] <= (uint)*(ushort *)((int)unaff_r31 + 10) - param_2)) {
      if (*(char *)((int)unaff_r31 + 0xe) == '\0') {
        if ((uint)*(byte *)((int)unaff_r31 + 0xd) != (uint)DAT_00017850) {
          *(undefined *)(*(byte *)((int)unaff_r31 + 0xd) + 0x17650) =
               *(undefined *)(DAT_00017850 + 0x17650);
          *(undefined *)(_DAT_00017640 + (uint)*(byte *)(DAT_00017850 + 0x17650) * 0x10 + 0xd) =
               *(undefined *)((int)unaff_r31 + 0xd);
        }
        DAT_00017850 = DAT_00017850 + 1;
      }
      *(undefined *)((int)unaff_r31 + 0xe) = 2;
      return *unaff_r31 + (param_1 - unaff_r31[1]);
    }
    unaff_r31 = (int *)(_DAT_00017640 + iVar4);
    iVar4 = iVar4 + 0x10;
    iVar5 = iVar5 + -1;
  } while (iVar5 != 0);
LAB_00010344:
  if (!bVar1) {
    uVar3 = (uint)DAT_00017850;
    if (uVar3 == DAT_00017852) {
      return 0;
    }
    DAT_00017850 = DAT_00017850 + 1;
    unaff_r30 = *(byte *)(uVar3 + 0x17650);
    unaff_r31 = (int *)(_DAT_00017640 + (uint)unaff_r30 * 0x10);
  }
  uVar3 = param_1 & 0xffffffe0;
  *(undefined *)((int)unaff_r31 + 0xe) = 3;
  unaff_r31[1] = uVar3;
  *(undefined2 *)(unaff_r31 + 2) = *(undefined2 *)((int)unaff_r31 + 10);
  iVar5 = _DAT_000178c8 * 0x18;
  _DAT_000178c8 = _DAT_000178c8 + 1;
  Nas_StartDma__FP8OSIoMesgllUlPvUlP13OSMesgQueue_slPSc
            (iVar5 + 0x1700c,0,0,uVar3,*unaff_r31,*(undefined2 *)((int)unaff_r31 + 10),0x16ef4,
             param_5,"SUPERDMA");
  *param_4 = unaff_r30;
  return *unaff_r31 + (param_1 - uVar3);
}

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
void Nas_WaveDmaNew__Fl(void)
{
  int iVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  int *piVar5;
  int iVar6;
  
  _DAT_000178b4 = _DAT_0001789c;
  _DAT_00017640 = Nas_HeapAlloc__FP6ALHeapl(0x17a60,(int)_DAT_00017870 * _DAT_000178bc * 0x40);
  iVar2 = (int)_DAT_00017870;
  iVar1 = _DAT_000178bc * 3;
  for (iVar6 = 0; iVar6 < iVar2 * iVar1; iVar6 = iVar6 + 1) {
    piVar5 = (int *)(_DAT_00017640 + _DAT_00017644 * 0x10);
    iVar3 = Nas_2ndHeapAlloc__FP6ALHeapl(0x17a60,_DAT_000178b4);
    *piVar5 = iVar3;
    if (iVar3 == 0) break;
    Nas_CacheOff__FPUcl(*piVar5,_DAT_000178b4);
    *(short *)((int)piVar5 + 10) = (short)_DAT_000178b4;
    piVar5[1] = 0;
    *(undefined2 *)(piVar5 + 2) = 0;
    *(undefined *)(piVar5 + 3) = 0;
    *(undefined *)((int)piVar5 + 0xe) = 0;
    _DAT_00017644 = _DAT_00017644 + 1;
  }
  iVar1 = 0;
  for (uVar4 = 0; uVar4 < _DAT_00017644; uVar4 = uVar4 + 1) {
    iVar2 = iVar1 + 0xd;
    *(char *)(uVar4 + 0x17650) = (char)uVar4;
    iVar1 = iVar1 + 0x10;
    *(char *)(_DAT_00017640 + iVar2) = (char)uVar4;
  }
  iVar1 = 0x100 - _DAT_00017644;
  uVar4 = _DAT_00017644;
  if ((int)_DAT_00017644 < 0x100) {
    do {
      *(undefined *)(uVar4 + 0x17650) = 0;
      iVar1 = iVar1 + -1;
      uVar4 = uVar4 + 1;
    } while (iVar1 != 0);
  }
  DAT_00017850 = 0;
  DAT_00017852 = (undefined)_DAT_00017644;
  _DAT_00017648 = _DAT_00017644;
  _DAT_000178b4 = _DAT_000178a0;
  for (iVar1 = 0; iVar1 < _DAT_000178bc; iVar1 = iVar1 + 1) {
    piVar5 = (int *)(_DAT_00017640 + _DAT_00017644 * 0x10);
    iVar2 = Nas_2ndHeapAlloc__FP6ALHeapl(0x17a60,_DAT_000178b4);
    *piVar5 = iVar2;
    if (iVar2 == 0) break;
    Nas_CacheOff__FPUcl(*piVar5,_DAT_000178b4);
    *(short *)((int)piVar5 + 10) = (short)_DAT_000178b4;
    piVar5[1] = 0;
    *(undefined2 *)(piVar5 + 2) = 0;
    *(undefined *)(piVar5 + 3) = 0;
    *(undefined *)((int)piVar5 + 0xe) = 0;
    _DAT_00017644 = _DAT_00017644 + 1;
  }
  iVar1 = _DAT_00017648 << 4;
  for (uVar4 = _DAT_00017648; uVar4 < _DAT_00017644; uVar4 = uVar4 + 1) {
    iVar2 = iVar1 + 0xd;
    iVar1 = iVar1 + 0x10;
    *(char *)((uVar4 - _DAT_00017648) + 0x17750) = (char)uVar4;
    *(char *)(_DAT_00017640 + iVar2) = (char)uVar4 - (char)_DAT_00017648;
  }
  iVar1 = 0x100 - _DAT_00017644;
  uVar4 = _DAT_00017644;
  if ((int)_DAT_00017644 < 0x100) {
    do {
      *(char *)(uVar4 + 0x17750) = (char)_DAT_00017648;
      iVar1 = iVar1 + -1;
      uVar4 = uVar4 + 1;
    } while (iVar1 != 0);
  }
  DAT_00017851 = 0;
  DAT_00017853 = (char)_DAT_00017644 - (char)_DAT_00017648;
  return;
}

undefined4 Nas_CheckIDbank__Fl(int param_1)
{
  undefined4 uVar1;
  int iVar2;
  
  if (param_1 == 0xff) {
    uVar1 = 1;
  }
  else if (*(byte *)(param_1 + 0x18540) < 2) {
    iVar2 = __Link_BankNum__Fll(1);
    if (*(byte *)(iVar2 + 0x18540) < 2) {
      uVar1 = 0;
    }
    else {
      uVar1 = 1;
    }
  }
  else {
    uVar1 = 1;
  }
  return uVar1;
}

undefined4 Nas_CheckIDseq__Fl(int param_1)
{
  undefined4 uVar1;
  int iVar2;
  
  if (param_1 == 0xff) {
    uVar1 = 1;
  }
  else if (*(byte *)(param_1 + 0x18560) < 2) {
    iVar2 = __Link_BankNum__Fll(0);
    if (*(byte *)(iVar2 + 0x18560) < 2) {
      uVar1 = 0;
    }
    else {
      uVar1 = 1;
    }
  }
  else {
    uVar1 = 1;
  }
  return uVar1;
}

undefined4 Nas_CheckIDwave__Fl(int param_1)
{
  undefined4 uVar1;
  int iVar2;
  
  if (param_1 == 0xff) {
    uVar1 = 1;
  }
  else if (*(byte *)(param_1 + 0x18520) < 2) {
    iVar2 = __Link_BankNum__Fll(2);
    if (*(byte *)(iVar2 + 0x18520) < 2) {
      uVar1 = 0;
    }
    else {
      uVar1 = 1;
    }
  }
  else {
    uVar1 = 1;
  }
  return uVar1;
}

void Nas_WriteIDbank__Fll(int param_1,char param_2)
{
  if (param_1 == 0xff) {
    return;
  }
  if (*(char *)(param_1 + 0x18540) == '\x05') {
    return;
  }
  *(char *)(param_1 + 0x18540) = param_2;
  return;
}

void Nas_WriteIDseq__Fll(int param_1,char param_2)
{
  if (param_1 == 0xff) {
    return;
  }
  if (*(char *)(param_1 + 0x18560) == '\x05') {
    return;
  }
  *(char *)(param_1 + 0x18560) = param_2;
  return;
}

void Nas_WriteIDwave__Fll(int param_1,char param_2)
{
  char *pcVar1;
  
  if (param_1 != 0xff) {
    pcVar1 = (char *)(param_1 + 0x18520);
    if (*pcVar1 != '\x05') {
      *pcVar1 = param_2;
    }
    if ((*pcVar1 == '\x05') || (*pcVar1 == '\x02')) {
      EntryWave__Fl();
    }
  }
  return;
}

void Nas_WriteIDwaveOnly__Fll(int param_1,char param_2)
{
  if (param_1 == 0xff) {
    return;
  }
  if (*(char *)(param_1 + 0x18520) == '\x05') {
    return;
  }
  *(char *)(param_1 + 0x18520) = param_2;
  return;
}

void Nas_BankHeaderInit__FP10ArcHeader_PUcUs(short *param_1,int param_2,short param_3)
{
  int local_4;
  
  param_1[1] = param_3;
  *(int *)(param_1 + 2) = param_2;
  for (local_4 = 0; local_4 < *param_1; local_4 = local_4 + 1) {
    if ((*(int *)(param_1 + local_4 * 8 + 10) != 0) &&
       (*(char *)(param_1 + local_4 * 8 + 0xc) == '\x02')) {
      *(int *)(param_1 + local_4 * 8 + 8) = *(int *)(param_1 + local_4 * 8 + 8) + param_2;
    }
  }
  return;
}

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
int Nas_PreLoadBank__FlPl(int param_1,uint *param_2)
{
  uint uVar1;
  uint uVar2;
  uint local_14;
  
  if (param_1 < (int)(uint)_DAT_00017868) {
    uVar2 = 0xff;
    uVar1 = (uint)*(ushort *)(_DAT_00017864 + param_1 * 2);
    for (local_14 = (uint)*(byte *)(_DAT_00017864 + uVar1); uVar1 = uVar1 + 1, 0 < (int)local_14;
        local_14 = local_14 - 1) {
      uVar2 = (uint)*(byte *)(_DAT_00017864 + uVar1);
      param_1 = __Load_Ctrl__Fl(uVar2);
    }
    *param_2 = uVar2;
  }
  else {
    param_1 = 0;
  }
  return param_1;
}

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
void Nas_PreLoadSeq__FlllP13OSMesgQueue_s(int param_1,uint param_2,int param_3,undefined4 param_4)
{
  undefined auStack_1c [12];
  
  if (param_1 < (int)(uint)_DAT_00017868) {
    if ((param_2 & 2) != 0) {
      Nas_PreLoadBank__FlPl(param_1,auStack_1c);
    }
    if ((param_2 & 1) != 0) {
      __Load_Seq__Fl(param_1);
    }
    if (param_3 != 0) {
      osSendMesg__FP13OSMesgQueue_sPvl(param_4,param_3 << 0x18,0);
    }
  }
  return;
}

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
undefined4 __Nas_LoadVoice_Inner__FP13smzwavetable_l(uint *param_1,undefined4 param_2)
{
  byte bVar1;
  uint uVar2;
  
  if (((*(byte *)param_1 & 1) == 1) && (bVar1 = *(byte *)param_1 >> 2 & 3, bVar1 != 0)) {
    uVar2 = Nas_Alloc_Single__FllPUcScl(*param_1 & 0xffffff,param_2,param_1[1],bVar1,1);
    if (uVar2 == 0) {
      return 0xffffffff;
    }
    if ((*(byte *)param_1 >> 2 & 3) == 1) {
      Nas_FastDiskCopy__FPUcPUcUll
                (param_1[1],uVar2,*param_1 & 0xffffff,(int)*(short *)(_DAT_0001785c + 2));
    }
    else {
      Nas_FastCopy__FPUcPUcUll(param_1[1],uVar2,*param_1 & 0xffffff);
    }
    *(byte *)param_1 = *(byte *)param_1 & 0xf3;
    param_1[1] = uVar2;
  }
  return 0;
}

undefined4 Nas_LoadVoice__Flll(undefined4 param_1,int param_2,undefined4 param_3)
{
  int iVar1;
  
  if (param_2 < 0x7f) {
    iVar1 = ProgToVp__Fll(param_1);
    if (iVar1 == 0) {
      return 0xffffffff;
    }
    if (*(char *)(iVar1 + 1) != '\0') {
      __Nas_LoadVoice_Inner__FP13smzwavetable_l(*(undefined4 *)(iVar1 + 8),param_1);
    }
    __Nas_LoadVoice_Inner__FP13smzwavetable_l(*(undefined4 *)(iVar1 + 0x10),param_1);
    if (*(char *)(iVar1 + 2) != '\x7f') {
      __Nas_LoadVoice_Inner__FP13smzwavetable_l(*(undefined4 *)(iVar1 + 0x18),param_1);
    }
  }
  else if (param_2 == 0x7f) {
    iVar1 = PercToPp__Fll(param_1,param_3);
    if (iVar1 == 0) {
      return 0xffffffff;
    }
    __Nas_LoadVoice_Inner__FP13smzwavetable_l(*(undefined4 *)(iVar1 + 4),param_1);
    return 0;
  }
  return 0;
}

undefined4
Nas_PreLoad_BG__FllllP13OSMesgQueue_s
          (undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
          undefined4 param_5)
{
  int iVar1;
  
  iVar1 = __Load_Bank_BG__FllllP13OSMesgQueue_s(param_1,param_2,param_3,param_4,param_5);
  if (iVar1 == 0) {
    osSendMesg__FP13OSMesgQueue_sPvl(param_5,0xffffffff,0);
  }
  return 0;
}

undefined4
Nas_PreLoadSeq_BG__FlllP13OSMesgQueue_s
          (undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)
{
  Nas_PreLoad_BG__FllllP13OSMesgQueue_s(0,param_1,0,param_3,param_4);
  return 0;
}

undefined4
Nas_PreLoadWave_BG__FlllP13OSMesgQueue_s
          (undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)
{
  Nas_PreLoad_BG__FllllP13OSMesgQueue_s(2,param_1,0,param_3,param_4);
  return 0;
}

undefined4
Nas_PreLoadBank_BG__FlllP13OSMesgQueue_s
          (undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)
{
  Nas_PreLoad_BG__FllllP13OSMesgQueue_s(1,param_1,0,param_3,param_4);
  return 0;
}

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
int Nas_SeqToBank__FlPl(int param_1,uint *param_2)
{
  uint uVar1;
  
  uVar1 = (uint)*(ushort *)(_DAT_00017864 + param_1 * 2);
  *param_2 = (uint)*(byte *)(_DAT_00017864 + uVar1);
  if (*param_2 == 0) {
    return 0;
  }
  return _DAT_00017864 + uVar1 + 1;
}

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
void Nas_FlushBank__Fl(int param_1)
{
  undefined4 uVar1;
  int iVar2;
  uint uVar3;
  int iVar4;
  int iVar5;
  uint uVar6;
  
  uVar3 = (uint)*(ushort *)(_DAT_00017864 + param_1 * 2);
  uVar6 = (uint)*(byte *)(_DAT_00017864 + uVar3);
  iVar5 = uVar3 + 1;
  while (0 < (int)uVar6) {
    uVar6 = uVar6 - 1;
    iVar4 = iVar5 + 1;
    uVar1 = __Link_BankNum__Fll(1,*(undefined *)(_DAT_00017864 + iVar5));
    iVar2 = EmemOnCheck__Fll(1,uVar1);
    iVar5 = iVar4;
    if (iVar2 == 0) {
      __Kill_Bank__Fl(uVar1);
      Nas_WriteIDbank__Fll(uVar1,0);
    }
  }
  return;
}

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
undefined4 __Kill_Bank__Fl(int param_1)
{
  int iVar1;
  uint uVar2;
  
  if (_DAT_00017cee == param_1) {
    _DAT_00017cee = -1;
  }
  else if (_DAT_00017cfa == param_1) {
    _DAT_00017cfa = -1;
  }
  iVar1 = 0;
  for (uVar2 = 0; uVar2 < _DAT_00017bf4; uVar2 = uVar2 + 1) {
    if (param_1 == *(short *)(iVar1 + 0x17c16)) {
      *(short *)(iVar1 + 0x17c16) = -1;
    }
    iVar1 = iVar1 + 0xc;
  }
  Nas_ForceStopChannel__Fl();
  return 0;
}

void Nas_SetExtPointer__Fllll(undefined4 param_1,int param_2,int param_3,undefined4 param_4)
{
  int iVar1;
  
  iVar1 = __Get_ArcHeader__Fl(param_1);
  iVar1 = iVar1 + param_2 * 0x10;
  if (*(char *)(iVar1 + 0x18) == '\x05') {
    if (param_3 == 1) {
      *(undefined4 *)(iVar1 + 0x14) = param_4;
    }
    else if ((param_3 < 1) && (-1 < param_3)) {
      *(undefined4 *)(iVar1 + 0x10) = param_4;
    }
  }
  return;
}

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
undefined4 Nas_StartMySeq__Flll(int param_1)
{
  undefined4 uVar1;
  
  if (_DAT_00017a04 == 0) {
    *(undefined4 *)(*(int *)(param_1 * 4 + 0x1d4f8) + 0xdc) = 0;
    uVar1 = __Nas_StartSeq__Flll();
  }
  else {
    uVar1 = 0;
  }
  return uVar1;
}

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
undefined4 Nas_StartSeq_Skip__Flll(int param_1,undefined4 param_2,undefined4 param_3)
{
  undefined4 uVar1;
  
  if (_DAT_00017a04 == 0) {
    *(undefined4 *)(*(int *)(param_1 * 4 + 0x1d4f8) + 0xdc) = param_3;
    uVar1 = __Nas_StartSeq__Flll(param_1,param_2,0);
  }
  else {
    uVar1 = 0;
  }
  return uVar1;
}

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
undefined4 __Nas_StartSeq__Flll(int param_1,int param_2)
{
  int iVar1;
  byte bVar2;
  uint uVar3;
  char cVar4;
  byte *pbVar5;
  uint local_28;
  
  if (param_2 < (int)(uint)_DAT_00017868) {
    pbVar5 = *(byte **)(param_1 * 4 + 0x1d4f8);
    Nas_ReleaseGroup__FP6group_(pbVar5);
    cVar4 = -1;
    uVar3 = (uint)*(ushort *)(_DAT_00017864 + param_2 * 2);
    for (local_28 = (uint)*(byte *)(_DAT_00017864 + uVar3); uVar3 = uVar3 + 1, 0 < (int)local_28;
        local_28 = local_28 - 1) {
      cVar4 = *(char *)(_DAT_00017864 + uVar3);
      __Load_Ctrl__Fl(cVar4);
    }
    iVar1 = __Load_Seq__Fl(param_2);
    if (iVar1 != 0) {
      Nas_InitMySeq__FP6group_(pbVar5);
      pbVar5[4] = (byte)param_2;
      if (cVar4 == -1) {
        pbVar5[5] = 0xff;
      }
      else {
        bVar2 = __Link_BankNum__Fll(1,cVar4);
        pbVar5[5] = bVar2;
      }
      *(int *)(pbVar5 + 0x18) = iVar1;
      *(int *)(pbVar5 + 0x78) = iVar1;
      pbVar5[0x90] = 0;
      *(undefined2 *)(pbVar5 + 0x10) = 0;
      *pbVar5 = *pbVar5 & 0x7f | 0x80;
      *pbVar5 = *pbVar5 & 0xbf;
      pbVar5[7] = (byte)param_1;
    }
  }
  return 0;
}

undefined4 __Load_Seq__Fl(undefined4 param_1)
{
  int iVar1;
  undefined4 uVar2;
  undefined auStack_10 [12];
  
  iVar1 = __Link_BankNum__Fll(0,param_1);
  if (*(char *)(iVar1 + 0x18560) == '\x01') {
    uVar2 = 0;
  }
  else {
    uVar2 = __Load_Bank__FllPl(0,param_1,auStack_10);
  }
  return uVar2;
}

void __Load_Wave_Check__FlPUl(undefined4 param_1,undefined4 param_2)
{
  __Load_Wave__FlPUll(param_1,param_2,1);
  return;
}

int __Load_Wave__FlPUll(int param_1,int *param_2,int param_3)
{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int local_28 [2];
  int local_20;
  
  local_28[0] = param_3;
  local_20 = __Link_BankNum__Fll(2,param_1);
  iVar2 = __Get_ArcHeader__Fl(2);
  iVar1 = local_20;
  iVar3 = __Check_Cache__Fll(2,local_20);
  if (iVar3 == 0) {
    iVar4 = iVar2 + param_1 * 0x10;
    if ((*(char *)(iVar4 + 0x19) == '\x04') || (local_28[0] == 1)) {
      *param_2 = (int)*(char *)(iVar2 + param_1 * 0x10 + 0x18);
      iVar3 = *(int *)(iVar2 + iVar1 * 0x10 + 0x10);
    }
    else {
      iVar3 = __Load_Bank__FllPl(2,param_1,local_28);
      if (iVar3 == 0) {
        *param_2 = (int)*(char *)(iVar4 + 0x18);
        iVar3 = *(int *)(iVar2 + iVar1 * 0x10 + 0x10);
      }
      else {
        *param_2 = 0;
      }
    }
  }
  else {
    if (*(char *)(iVar1 + 0x18520) != '\x01') {
      Nas_WriteIDwaveOnly__Fll(iVar1,2);
    }
    *param_2 = 0;
  }
  return iVar3;
}

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
int __Load_Ctrl__Fl(undefined4 param_1)
{
  int iVar1;
  int iVar2;
  uint uVar3;
  uint local_2c;
  uint local_28;
  undefined4 local_24;
  undefined4 local_20;
  undefined auStack_1c [4];
  undefined auStack_18 [4];
  int local_14 [2];
  
  iVar1 = __Link_BankNum__Fll(1,param_1);
  if (*(char *)(iVar1 + 0x18540) == '\x01') {
    iVar2 = 0;
  }
  else {
    iVar2 = _DAT_0001786c + iVar1 * 0x14;
    local_2c = (uint)*(byte *)(iVar2 + 2);
    uVar3 = (uint)*(byte *)(iVar2 + 3);
    local_28 = uVar3;
    if (local_2c == 0xff) {
      local_24 = 0;
    }
    else {
      local_24 = __Load_Wave__FlPUll(local_2c,auStack_1c,0);
    }
    if (uVar3 == 0xff) {
      local_20 = 0;
    }
    else {
      local_20 = __Load_Wave__FlPUll(uVar3,auStack_18,0);
    }
    iVar2 = __Load_Bank__FllPl(1,param_1,local_14);
    if (iVar2 == 0) {
      iVar2 = 0;
    }
    else if (local_14[0] == 1) {
      Nas_BankOfsToAddr__FlPUcP10WaveMedia_l(iVar1,iVar2,&local_2c,0);
    }
  }
  return iVar2;
}

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
int __Load_Bank__FllPl(int param_1,int param_2,undefined4 *param_3)
{
  undefined2 *puVar1;
  char cVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  undefined *puVar7;
  int iVar8;
  undefined2 *puVar9;
  uint uVar10;
  undefined4 local_30;
  
  iVar3 = __Link_BankNum__Fll(param_1,param_2);
  iVar4 = __Check_Cache__Fll(param_1,iVar3);
  if (iVar4 != 0) {
    local_30 = 2;
    *param_3 = 0;
    goto LAB_00011754;
  }
  iVar5 = __Get_ArcHeader__Fl(param_1);
  iVar6 = iVar5 + param_2 * 0x10;
  cVar2 = *(char *)(iVar6 + 0x19);
  iVar8 = iVar5 + iVar3 * 0x10;
  puVar9 = *(undefined2 **)(iVar8 + 0x10);
  uVar10 = *(int *)(iVar8 + 0x14) + 0x1fU & 0xffffffe0;
  iVar6 = (int)*(char *)(iVar6 + 0x18);
  if (cVar2 == '\x02') {
    iVar4 = Nas_SzHeapAlloc__Fllll(param_1,uVar10,0,iVar3);
joined_r0x00011684:
    if (iVar4 == 0) {
      return 0;
    }
  }
  else {
    if (cVar2 < '\x02') {
      if (cVar2 == '\0') {
        iVar4 = EmemAlloc__Flll(param_1,iVar3,uVar10);
      }
      else {
        if (cVar2 < '\0') goto LAB_00011690;
        iVar4 = Nas_SzHeapAlloc__Fllll(param_1,uVar10,1,iVar3);
      }
      goto joined_r0x00011684;
    }
    if (cVar2 < '\x05') {
      iVar4 = Nas_SzHeapAlloc__Fllll(param_1,uVar10,2,iVar3);
      goto joined_r0x00011684;
    }
  }
LAB_00011690:
  *param_3 = 1;
  if (iVar6 == 5) {
    if (puVar9 == (undefined2 *)0x0) {
      return 0;
    }
    if (param_1 == 1) {
      uVar10 = uVar10 - 0x10;
      puVar7 = (undefined *)(_DAT_0001786c + iVar3 * 0x14);
      *puVar7 = (char)*puVar9;
      puVar7[1] = (char)puVar9[1];
      puVar1 = puVar9 + 2;
      puVar9 = puVar9 + 8;
      *(undefined2 *)(puVar7 + 4) = *puVar1;
    }
    bcopy__FPvPvUl(puVar9,iVar4,uVar10);
  }
  else if (iVar6 == 1) {
    Nas_FastDiskCopy__FPUcPUcUll(puVar9,iVar4,uVar10,(int)*(short *)(iVar5 + 2));
  }
  else {
    Nas_FastCopy__FPUcPUcUll(puVar9,iVar4,uVar10,iVar6);
  }
  if (cVar2 == '\0') {
    local_30 = 5;
  }
  else {
    local_30 = 2;
  }
LAB_00011754:
  if (param_1 == 1) {
    Nas_WriteIDbank__Fll(iVar3,local_30);
  }
  else if (param_1 < 1) {
    if (-1 < param_1) {
      Nas_WriteIDseq__Fll(iVar3,local_30);
    }
  }
  else if (param_1 < 3) {
    Nas_WriteIDwave__Fll(iVar3,local_30);
  }
  return iVar4;
}

int __Link_BankNum__Fll(undefined4 param_1,int param_2)
{
  int iVar1;
  
  iVar1 = __Get_ArcHeader__Fl();
  iVar1 = iVar1 + param_2 * 0x10;
  if (*(int *)(iVar1 + 0x14) == 0) {
    param_2 = *(int *)(iVar1 + 0x10);
  }
  return param_2;
}

int __Check_Cache__Fll(undefined4 param_1,undefined4 param_2)
{
  int iVar1;
  
  iVar1 = EmemOnCheck__Fll();
  if ((iVar1 == 0) && (iVar1 = Nas_SzCacheCheck__Flll(param_1,2,param_2), iVar1 == 0)) {
    iVar1 = 0;
  }
  return iVar1;
}

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
undefined4 __Get_ArcHeader__Fl(int param_1)
{
  if (param_1 == 1) {
    return _DAT_00017858;
  }
  if (param_1 < 1) {
    if (-1 < param_1) {
      return _DAT_00017854;
    }
  }
  else if (param_1 < 3) {
    return _DAT_0001785c;
  }
  return 0;
}

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
void Nas_BankOfsToAddr_Inner__FlPUcP10WaveMedia_(int param_1,int *param_2,undefined4 param_3)
{
  uint uVar1;
  int *piVar2;
  char **ppcVar3;
  char *pcVar4;
  int iVar5;
  uint uVar6;
  int iVar7;
  uint local_40;
  int local_38;
  
  param_1 = param_1 * 0x14;
  uVar1 = (uint)*(byte *)(_DAT_0001786c + param_1 + 1);
  local_40 = (uint)*(byte *)(_DAT_0001786c + param_1);
  uVar6 = (uint)*(ushort *)(_DAT_0001786c + param_1 + 4);
  if ((*param_2 != 0) && (uVar1 != 0)) {
    *param_2 = *param_2 + (int)param_2;
    for (local_38 = 0; local_38 < (int)uVar1; local_38 = local_38 + 1) {
      piVar2 = (int *)(*param_2 + local_38 * 4);
      iVar5 = *piVar2;
      if (iVar5 != 0) {
        iVar5 = iVar5 + (int)param_2;
        *piVar2 = iVar5;
        if (*(char *)(iVar5 + 2) == '\0') {
          __WaveTouch__FP6wtstr_UlP10WaveMedia_(iVar5 + 4,param_2,param_3);
          *(int *)(iVar5 + 0xc) = *(int *)(iVar5 + 0xc) + (int)param_2;
          *(undefined *)(iVar5 + 2) = 1;
        }
      }
    }
  }
  if ((param_2[1] != 0) && (uVar6 != 0)) {
    iVar5 = 0;
    iVar7 = 0;
    param_2[1] = param_2[1] + (int)param_2;
    while( true ) {
      if ((int)uVar6 <= iVar5) break;
      piVar2 = (int *)(param_2[1] + iVar7);
      if ((piVar2 != (int *)0x0) && (*piVar2 != 0)) {
        __WaveTouch__FP6wtstr_UlP10WaveMedia_(piVar2,param_2,param_3);
      }
      iVar5 = iVar5 + 1;
      iVar7 = iVar7 + 8;
    }
  }
  if (0x7e < local_40) {
    local_40 = 0x7e;
  }
  iVar5 = 8;
  for (iVar7 = 2; iVar7 <= (int)(local_40 + 1); iVar7 = iVar7 + 1) {
    ppcVar3 = (char **)((int)param_2 + iVar5);
    if (*ppcVar3 != (char *)0x0) {
      *ppcVar3 = *ppcVar3 + (int)param_2;
      pcVar4 = *ppcVar3;
      if (*pcVar4 == '\0') {
        if (pcVar4[1] != '\0') {
          __WaveTouch__FP6wtstr_UlP10WaveMedia_(pcVar4 + 8,param_2,param_3);
        }
        __WaveTouch__FP6wtstr_UlP10WaveMedia_(pcVar4 + 0x10,param_2,param_3);
        if (pcVar4[2] != '\x7f') {
          __WaveTouch__FP6wtstr_UlP10WaveMedia_(pcVar4 + 0x18,param_2,param_3);
        }
        *(int *)(pcVar4 + 4) = *(int *)(pcVar4 + 4) + (int)param_2;
        *pcVar4 = '\x01';
      }
    }
    iVar5 = iVar5 + 4;
  }
  *(int *)(_DAT_0001786c + param_1 + 0xc) = *param_2;
  *(int *)(_DAT_0001786c + param_1 + 0x10) = param_2[1];
  *(int **)(_DAT_0001786c + param_1 + 8) = param_2 + 2;
  return;
}

void Nas_FastCopy__FPUcPUcUll(uint param_1,int param_2,int param_3,undefined4 param_4)
{
  int iVar1;
  int iVar2;
  uint uVar3;
  uint local_40;
  int local_3c;
  uint local_38;
  
  local_38 = param_3 + 0x1fU & 0xffffffe0;
  osInvalDCache2__FPvl(param_2,local_38);
  iVar1 = FASTDMA_BUFFER;
  uVar3 = param_1 & 0x1f;
  local_40 = param_1;
  local_3c = param_2;
  if (uVar3 == 0) {
    for (; 0x3ff < local_38; local_38 = local_38 - 0x400) {
      Nas_StartDma__FP8OSIoMesgllUlPvUlP13OSMesgQueue_slPSc
                (0x17628,1,0,local_40,local_3c,0x400,0x1760c,param_4,"FastCopy");
      osRecvMesg__FP13OSMesgQueue_sPPvl(0x1760c,0,1);
      local_40 = local_40 + 0x400;
      local_3c = local_3c + 0x400;
    }
    if (local_38 != 0) {
      Nas_StartDma__FP8OSIoMesgllUlPvUlP13OSMesgQueue_slPSc
                (0x17628,1,0,local_40,local_3c,local_38,0x1760c,param_4,"FastCopy");
      osRecvMesg__FP13OSMesgQueue_sPPvl(0x1760c,0,1);
    }
  }
  else {
    Nas_StartDma__FP8OSIoMesgllUlPvUlP13OSMesgQueue_slPSc
              (0x17628,1,0,param_1 - uVar3,FASTDMA_BUFFER,0x20,0x1760c,param_4,"FastCopy");
    osRecvMesg__FP13OSMesgQueue_sPPvl(0x1760c,0,1);
    iVar2 = 0x20 - uVar3;
    bcopy__FPvPvUl(iVar1 + uVar3,param_2,iVar2);
    local_40 = param_1 + iVar2;
    local_3c = param_2 + iVar2;
    for (local_38 = local_38 - iVar2; local_38 != 0; local_38 = local_38 - uVar3) {
      Nas_StartDma__FP8OSIoMesgllUlPvUlP13OSMesgQueue_slPSc
                (0x17628,1,0,local_40,iVar1,0x400,0x1760c,param_4,"FastCopy");
      osRecvMesg__FP13OSMesgQueue_sPPvl(0x1760c,0,1);
      uVar3 = local_38;
      if (0x3ff < local_38) {
        uVar3 = 0x400;
      }
      bcopy__FPvPvUl(iVar1,local_3c,uVar3);
      local_40 = local_40 + uVar3;
      local_3c = local_3c + uVar3;
    }
  }
  return;
}

void Nas_FastDiskCopy__FPUcPUcUll(void)
{
  return;
}

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
undefined4
Nas_StartDma__FP8OSIoMesgllUlPvUlP13OSMesgQueue_slPSc
          (int param_1,undefined param_2,undefined4 param_3,undefined4 param_4,undefined4 param_5,
          uint param_6,undefined4 param_7,int param_8)
{
  undefined4 uVar1;
  uint local_3c;
  
  osInvalDCache2__FPvl(param_5,param_6);
  if (_DAT_00017a04 < 0x11) {
    uVar1 = _DAT_00016e40;
    if ((param_8 == 3) || ((param_8 < 3 && (uVar1 = _DAT_00016e3c, 1 < param_8)))) {
      local_3c = param_6;
      if ((param_6 & 0x1f) != 0) {
        local_3c = param_6 + 0x1f & 0xffffffe0;
      }
      *(undefined *)(param_1 + 2) = param_2;
      *(undefined4 *)(param_1 + 4) = param_7;
      *(undefined4 *)(param_1 + 8) = param_5;
      *(undefined4 *)(param_1 + 0xc) = param_4;
      *(uint *)(param_1 + 0x10) = local_3c;
      (*(code *)NA_DMA_PROC)(uVar1,param_1,param_3);
      uVar1 = 0;
    }
    else {
      uVar1 = 0;
    }
  }
  else {
    uVar1 = 0xffffffff;
  }
  return uVar1;
}

undefined4 __OfsToLbaOfs__FlPl(void)
{
  return 0;
}

void EmemLoad__Fll(undefined4 param_1,undefined4 param_2)
{
  undefined auStack_8 [8];
  
  __Load_Bank__FllPl(param_1,param_2,auStack_8);
  return;
}

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
int __Load_Bank_BG__FllllP13OSMesgQueue_s
              (int param_1,int param_2,undefined4 param_3,int param_4,undefined4 param_5)
{
  undefined2 *puVar1;
  char cVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  undefined *puVar6;
  int iVar7;
  undefined4 uVar8;
  uint uVar9;
  undefined2 *puVar10;
  uint uVar11;
  int local_30;
  
  iVar3 = __Link_BankNum__Fll(param_1,param_2);
  if (param_1 == 1) {
    if (*(char *)(iVar3 + 0x18540) == '\x01') {
      return 0;
    }
  }
  else if (param_1 < 1) {
    if ((-1 < param_1) && (*(char *)(iVar3 + 0x18560) == '\x01')) {
      return 0;
    }
  }
  else if ((param_1 < 3) && (*(char *)(iVar3 + 0x18520) == '\x01')) {
    return 0;
  }
  local_30 = __Check_Cache__Fll(param_1,iVar3);
  if (local_30 != 0) {
    uVar8 = 2;
    osSendMesg__FP13OSMesgQueue_sPvl(param_5,param_4 << 0x18,0);
    goto LAB_000121f0;
  }
  iVar4 = __Get_ArcHeader__Fl(param_1);
  iVar5 = iVar4 + param_2 * 0x10;
  cVar2 = *(char *)(iVar5 + 0x19);
  iVar7 = iVar4 + iVar3 * 0x10;
  uVar9 = 2;
  puVar10 = *(undefined2 **)(iVar7 + 0x10);
  uVar11 = *(int *)(iVar7 + 0x14) + 0x1fU & 0xffffffe0;
  iVar5 = (int)*(char *)(iVar5 + 0x18);
  if (cVar2 == '\x02') {
    local_30 = Nas_SzHeapAlloc__Fllll(param_1,uVar11,0,iVar3);
joined_r0x00012114:
    if (local_30 == 0) {
      return 0;
    }
  }
  else if (cVar2 < '\x02') {
    if (cVar2 == '\0') {
      local_30 = EmemAlloc__Flll(param_1,iVar3,uVar11);
      if (local_30 == 0) {
        return 0;
      }
      uVar9 = 5;
    }
    else if (-1 < cVar2) {
      local_30 = Nas_SzHeapAlloc__Fllll(param_1,uVar11,1,iVar3);
      goto joined_r0x00012114;
    }
  }
  else if (cVar2 < '\x05') {
    local_30 = Nas_SzHeapAlloc__Fllll(param_1,uVar11,2,iVar3);
    goto joined_r0x00012114;
  }
  if (iVar5 == 5) {
    if (puVar10 == (undefined2 *)0x0) {
      return 0;
    }
    if (param_1 == 1) {
      uVar11 = uVar11 - 0x10;
      puVar6 = (undefined *)(_DAT_0001786c + iVar3 * 0x14);
      *puVar6 = (char)*puVar10;
      puVar6[1] = (char)puVar10[1];
      puVar1 = puVar10 + 2;
      puVar10 = puVar10 + 8;
      *(undefined2 *)(puVar6 + 4) = *puVar1;
    }
  }
  if (iVar5 == 1) {
    Nas_BgCopyDisk__FlPUcPUcUlllP13OSMesgQueue_sl
              ((int)*(short *)(iVar4 + 2),puVar10,local_30,uVar11,1,param_3,param_5,
               uVar9 | iVar3 << 8 | param_4 << 0x18 | param_1 << 0x10);
  }
  else {
    Nas_BgCopyReq__FPUcPUcUlllP13OSMesgQueue_sl
              (puVar10,local_30,uVar11,iVar5,param_3,param_5,
               uVar9 | iVar3 << 8 | param_4 << 0x18 | param_1 << 0x10);
  }
  uVar8 = 1;
LAB_000121f0:
  if (param_1 == 1) {
    Nas_WriteIDbank__Fll(iVar3,uVar8);
  }
  else if (param_1 < 1) {
    if (-1 < param_1) {
      Nas_WriteIDseq__Fll(iVar3,uVar8);
    }
  }
  else if (param_1 < 3) {
    Nas_WriteIDwave__Fll(iVar3,uVar8);
  }
  return local_30;
}

void Nas_BgDmaFrameWork__Fl(undefined4 param_1)
{
  LpsDma__Fl();
  Nas_CheckBgWave__Fl(param_1);
  Nas_BgCopyMain__Fl(param_1);
  return;
}

void Nas_SetRomHandler__FPFv_l(undefined *param_1)
{
  NA_DMA_PROC = param_1;
  return;
}

void Nas_SetDiskHandler__FPFv_l(undefined4 param_1)
{
  NA_DISK_PROC = param_1;
  return;
}

void Nas_SetSyncHandler__FPFv_PUc(undefined *param_1)
{
  NA_SYNC_PROC = param_1;
  return;
}

undefined4 Nas_GetSyncDummy__FPUcl(void)
{
  return 0;
}

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
void __SetVlute__Fl(int param_1)
{
  undefined *puVar1;
  int iVar2;
  
  iVar2 = _DAT_00017858 + param_1 * 0x10 + 0x10;
  puVar1 = (undefined *)(_DAT_0001786c + param_1 * 0x14);
  puVar1[2] = (char)((ushort)*(undefined2 *)(iVar2 + 10) >> 8);
  puVar1[3] = (char)*(undefined2 *)(iVar2 + 10);
  *puVar1 = (char)((ushort)*(undefined2 *)(iVar2 + 0xc) >> 8);
  puVar1[1] = (char)*(undefined2 *)(iVar2 + 0xc);
  *(undefined2 *)(puVar1 + 4) = *(undefined2 *)(iVar2 + 0xe);
  return;
}

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
void Nas_InitAudio__FPUxl(int param_1,uint param_2)
{
  short sVar1;
  int iVar2;
  undefined4 uVar3;
  undefined4 *puVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  int iVar7;
  int local_24;
  
  uRam00000000 = 0;
  for (local_24 = 0; local_24 < 4; local_24 = local_24 + 1) {
    *(undefined4 *)(local_24 * 4 + 0x17a08) = 0;
  }
  _DAT_00017a04 = 0;
  DAT_00017a18 = 0;
  _DAT_000179dc = @834;
  _DAT_000179e0 = 0x3c;
  Nas_InitGAudio__Fv();
  iVar7 = 4;
  iVar2 = 0;
  do {
    *(undefined2 *)(iVar2 + 0x179f4) = 0xa0;
    iVar7 = iVar7 + -1;
    iVar2 = iVar2 + 2;
  } while (iVar7 != 0);
  _DAT_000178c4 = 0;
  _DAT_000178cc = 0;
  _DAT_000178d0 = 0;
  DAT_000178c2 = 0;
  _DAT_000178e4 = 0;
  _DAT_00017920 = 0;
  _DAT_00017970 = 0;
  osCreateMesgQueue__FP13OSMesgQueue_sPPvl(0x1760c,0x17624,1);
  osCreateMesgQueue__FP13OSMesgQueue_sPPvl(0x16ef4,0x16f0c,0x40);
  osCreateMesgQueue__FP13OSMesgQueue_sPPvl(0x16e44,0x16e5c,0x10);
  osCreateMesgQueue__FP13OSMesgQueue_sPPvl(0x16e9c,0x16eb4,0x10);
  _DAT_000178c8 = 0;
  _DAT_00017644 = 0;
  iVar2 = 0;
  _DAT_0001866c = param_1;
  _DAT_00018670 = param_2;
  for (iVar7 = 0;
      iVar7 < (int)(((int)_DAT_00018670 >> 3) +
                   (uint)((int)_DAT_00018670 < 0 && (_DAT_00018670 & 7) != 0)); iVar7 = iVar7 + 1) {
    puVar4 = (undefined4 *)(_DAT_0001866c + iVar2);
    iVar2 = iVar2 + 8;
    puVar4[1] = 0;
    *puVar4 = 0;
  }
  Nas_SzHeapReset__FUl(_AudiobankHeaderStart + 0x400);
  iVar7 = 0;
  iVar2 = 0;
  do {
    uVar3 = Nas_HeapAlloc_CL__FP6ALHeapl(0x17a4c,0xf80);
    iVar7 = iVar7 + 1;
    *(undefined4 *)(iVar2 + 0x179e4) = uVar3;
    iVar2 = iVar2 + 4;
  } while (iVar7 < 4);
  _DAT_00017854 = &AudioseqHeaderStart;
  _DAT_00017858 = (short *)&AudiobankHeaderStart;
  _DAT_0001785c = &AudiowaveHeaderStart;
  _DAT_00017864 = &AudiomapHeaderStart;
  _DAT_00017868 = _AudioseqHeaderStart;
  DAT_00018661 = 0;
  DAT_00018660 = 1;
  Nas_SpecChange__Fv();
  _DAT_00017860 = &AudiodataHeaderStart;
  uVar3 = 0;
  uVar5 = 0;
  uVar6 = 0;
  if (_AudiodataHeaderStart != 0) {
    uVar3 = _Nas_InitGAudio__Fv;
    uVar5 = MK_QUEUE._4_4_;
    uVar6 = _Nas_SpecChange__Fv;
  }
  Nas_BankHeaderInit__FP10ArcHeader_PUcUs(_DAT_00017854,uVar3,0);
  Nas_BankHeaderInit__FP10ArcHeader_PUcUs(_DAT_00017858,uVar6,0);
  Nas_BankHeaderInit__FP10ArcHeader_PUcUs(_DAT_0001785c,uVar5,0);
  sVar1 = *_DAT_00017858;
  _DAT_0001786c = Nas_HeapAlloc__FP6ALHeapl(0x17a4c,sVar1 * 0x14);
  for (iVar2 = 0; iVar2 < sVar1; iVar2 = iVar2 + 1) {
    __SetVlute__Fl();
  }
  iVar2 = Nas_HeapAlloc__FP6ALHeapl(0x17a4c,_AudiowaveHeaderStart);
  if (iVar2 == 0) {
    _AudiowaveHeaderStart = 0;
  }
  Nas_HeapInit__FP6ALHeapPUcl(0x17e2c,iVar2,_AudiowaveHeaderStart);
  AUDIO_SYSTEM_READY = 1;
  osSendMesg__FP13OSMesgQueue_sPvl(_DAT_0001d7cc,_DAT_000178c4,0);
  return;
}

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
void LpsInit__Fv(void)
{
  _DAT_00016d88 = 0;
  _DAT_00016dec = 0;
  return;
}

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
undefined4 VoiceLoad__FlUlPSc(undefined4 param_1,undefined4 param_2,undefined *param_3)
{
  int iVar1;
  uint uVar2;
  uint *puVar3;
  undefined4 uVar4;
  
  puVar3 = (uint *)__GetWaveTable__Fll(param_1,param_2);
  if (puVar3 == (uint *)0x0) {
    uVar4 = 0xffffffff;
    *param_3 = 0;
  }
  else if ((*(byte *)puVar3 >> 2 & 3) == 0) {
    uVar4 = 0;
    *param_3 = 2;
  }
  else {
    iVar1 = _DAT_00016d70 * 100;
    if (*(int *)(&DAT_00016d88 + iVar1) == 3) {
      *(undefined4 *)(&DAT_00016d88 + iVar1) = 0;
    }
    uVar2 = puVar3[1];
    *(uint *)(iVar1 + 0x16d94) = *puVar3;
    *(uint *)(iVar1 + 0x16d98) = uVar2;
    uVar2 = puVar3[3];
    *(uint *)(iVar1 + 0x16d9c) = puVar3[2];
    *(uint *)(iVar1 + 0x16da0) = uVar2;
    *(undefined **)(iVar1 + 0x16d90) = param_3;
    uVar4 = Nas_Alloc_Single__FllPUcScl
                      (*puVar3 & 0xffffff,param_1,puVar3[1],*(byte *)puVar3 >> 2 & 3,0);
    *(undefined4 *)(iVar1 + 0x16d80) = uVar4;
    if (*(int *)(iVar1 + 0x16d80) == 0) {
      if (((*(byte *)puVar3 >> 2 & 3) == 1) || ((*(byte *)puVar3 >> 4 & 7) == 2)) {
        *param_3 = 0;
      }
      else {
        *param_3 = 3;
      }
      uVar4 = 0xffffffff;
    }
    else {
      *(undefined4 *)(&DAT_00016d88 + iVar1) = 1;
      *(uint *)(iVar1 + 0x16d8c) = (*puVar3 & 0xffffff) + 0x1f & 0xffffffe0;
      *(undefined4 *)(iVar1 + 0x16d84) = *(undefined4 *)(iVar1 + 0x16d80);
      *(uint *)(iVar1 + 0x16d7c) = puVar3[1];
      *(byte *)(iVar1 + 0x16d74) = *(byte *)puVar3 >> 2 & 3;
      *(char *)(iVar1 + 0x16d75) = (char)param_1;
      *(short *)(iVar1 + 0x16d76) = (short)param_2;
      if (*(byte *)(iVar1 + 0x16d74) == 1) {
        *(int *)(iVar1 + 0x16d78) = (int)*(short *)(_DAT_0001785c + 2);
      }
      uVar4 = 0;
      _DAT_00016d70 = _DAT_00016d70 ^ 1;
    }
  }
  return uVar4;
}

undefined4 __GetWaveTable__Fll(undefined4 param_1,int param_2)
{
  int iVar1;
  undefined4 uVar2;
  undefined4 *puVar3;
  
  if (param_2 < 0x80) {
    iVar1 = ProgToVp__Fll();
    if (iVar1 == 0) {
      uVar2 = 0;
    }
    else {
      uVar2 = *(undefined4 *)(iVar1 + 0x10);
    }
  }
  else if (param_2 < 0x100) {
    iVar1 = PercToPp__Fll(param_1,param_2 + -0x80);
    if (iVar1 == 0) {
      uVar2 = 0;
    }
    else {
      uVar2 = *(undefined4 *)(iVar1 + 4);
    }
  }
  else {
    puVar3 = (undefined4 *)VpercToVep__Fll(param_1,param_2 + -0x100);
    if (puVar3 == (undefined4 *)0x0) {
      uVar2 = 0;
    }
    else {
      uVar2 = *puVar3;
    }
  }
  return uVar2;
}

void __WriteBackLps__FP9lpscache_(int param_1)
{
  undefined4 uVar1;
  undefined4 *puVar2;
  
  puVar2 = (undefined4 *)
           __GetWaveTable__Fll(*(undefined *)(param_1 + 1),*(undefined2 *)(param_1 + 2));
  if (puVar2 != (undefined4 *)0x0) {
    uVar1 = *(undefined4 *)(param_1 + 0x24);
    *puVar2 = *(undefined4 *)(param_1 + 0x20);
    puVar2[1] = uVar1;
    uVar1 = *(undefined4 *)(param_1 + 0x2c);
    puVar2[2] = *(undefined4 *)(param_1 + 0x28);
    puVar2[3] = uVar1;
  }
  return;
}

void __SwapLoadLps__FP9lpscache_(int param_1)
{
  undefined4 uVar1;
  undefined4 *puVar2;
  
  if ((*(int *)(param_1 + 0x24) != 0) &&
     (puVar2 = (undefined4 *)
               __GetWaveTable__Fll(*(undefined *)(param_1 + 1),*(undefined2 *)(param_1 + 2)),
     puVar2 != (undefined4 *)0x0)) {
    uVar1 = puVar2[1];
    *(undefined4 *)(param_1 + 0x20) = *puVar2;
    *(undefined4 *)(param_1 + 0x24) = uVar1;
    uVar1 = puVar2[3];
    *(undefined4 *)(param_1 + 0x28) = puVar2[2];
    *(undefined4 *)(param_1 + 0x2c) = uVar1;
    puVar2[1] = *(undefined4 *)(param_1 + 0x10);
    *(byte *)puVar2 = *(byte *)puVar2 & 0xf3;
  }
  return;
}

void LpsDma__Fl(int param_1)
{
  int iVar1;
  int iVar2;
  char *pcVar3;
  int iVar4;
  
  iVar4 = 0;
  iVar2 = 0;
  do {
    iVar1 = *(int *)(&DAT_00016d88 + iVar2);
    pcVar3 = (char *)(iVar2 + 0x16d74);
    if (iVar1 == 2) {
      if (*pcVar3 != '\x01') {
        osRecvMesg__FP13OSMesgQueue_sPPvl(iVar2 + 0x16da4,0,1);
      }
      if (param_1 == 0) goto LAB_00012a78;
      *(undefined4 *)(&DAT_00016d88 + iVar2) = 3;
    }
    else if ((iVar1 < 2) && (0 < iVar1)) {
LAB_00012a78:
      *(undefined4 *)(&DAT_00016d88 + iVar2) = 2;
      iVar1 = *(int *)(iVar2 + 0x16d8c);
      if (iVar1 == 0) {
        __SwapLoadLps__FP9lpscache_(pcVar3);
        *(undefined4 *)(&DAT_00016d88 + iVar2) = 3;
        **(undefined **)(iVar2 + 0x16d90) = 1;
      }
      else if (iVar1 < 0x400) {
        if (*pcVar3 == '\x01') {
          __Nas_SlowDiskCopy__FPUcPUcUll
                    (*(undefined4 *)(iVar2 + 0x16d7c),*(undefined4 *)(iVar2 + 0x16d80),iVar1,
                     *(undefined4 *)(iVar2 + 0x16d78));
        }
        else {
          __Nas_SlowCopy__FP9lpscache_l(pcVar3,iVar1);
        }
        *(undefined4 *)(iVar2 + 0x16d8c) = 0;
      }
      else {
        if (*pcVar3 == '\x01') {
          __Nas_SlowDiskCopy__FPUcPUcUll
                    (*(undefined4 *)(iVar2 + 0x16d7c),*(undefined4 *)(iVar2 + 0x16d80),0x400,
                     *(undefined4 *)(iVar2 + 0x16d78));
        }
        else {
          __Nas_SlowCopy__FP9lpscache_l(pcVar3,0x400);
        }
        *(int *)(iVar2 + 0x16d8c) = *(int *)(iVar2 + 0x16d8c) + -0x400;
        *(int *)(iVar2 + 0x16d80) = *(int *)(iVar2 + 0x16d80) + 0x400;
        *(int *)(iVar2 + 0x16d7c) = *(int *)(iVar2 + 0x16d7c) + 0x400;
      }
    }
    iVar4 = iVar4 + 1;
    iVar2 = iVar2 + 100;
    if (1 < iVar4) {
      return;
    }
  } while( true );
}

void __Nas_SlowCopy__FP9lpscache_l(undefined *param_1,undefined4 param_2)
{
  osInvalDCache2__FPvl(*(undefined4 *)(param_1 + 0xc));
  osCreateMesgQueue__FP13OSMesgQueue_sPPvl(param_1 + 0x30,param_1 + 0x48,1);
  Nas_StartDma__FP8OSIoMesgllUlPvUlP13OSMesgQueue_slPSc
            (param_1 + 0x4c,0,0,*(undefined4 *)(param_1 + 8),*(undefined4 *)(param_1 + 0xc),param_2,
             param_1 + 0x30,*param_1,"SLOWCOPY");
  return;
}

void __Nas_SlowDiskCopy__FPUcPUcUll(void)
{
  return;
}

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
undefined4 SeqLoad__FlPUcPSc(int param_1,undefined4 param_2,undefined *param_3)
{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  
  if (param_1 < (int)(uint)_DAT_00017868) {
    iVar3 = __Link_BankNum__Fll(0);
    iVar4 = __Get_ArcHeader__Fl(0);
    iVar1 = _DAT_00016d70 * 100;
    if (*(int *)(&DAT_00016d88 + iVar1) == 3) {
      *(undefined4 *)(&DAT_00016d88 + iVar1) = 0;
    }
    *(undefined4 *)(iVar1 + 0x16d98) = 0;
    *(undefined **)(iVar1 + 0x16d90) = param_3;
    iVar5 = iVar4 + iVar3 * 0x10;
    iVar6 = *(int *)(iVar5 + 0x14);
    *(undefined4 *)(iVar1 + 0x16d80) = param_2;
    *(undefined4 *)(&DAT_00016d88 + iVar1) = 1;
    *(uint *)(iVar1 + 0x16d8c) = iVar6 + 0x1fU & 0xffffffe0;
    *(undefined4 *)(iVar1 + 0x16d84) = *(undefined4 *)(iVar1 + 0x16d80);
    *(undefined4 *)(iVar1 + 0x16d7c) = *(undefined4 *)(iVar5 + 0x10);
    *(char *)(iVar1 + 0x16d74) = *(char *)(iVar5 + 0x18);
    *(char *)(iVar1 + 0x16d75) = (char)iVar3;
    if (*(char *)(iVar1 + 0x16d74) == '\x01') {
      *(int *)(iVar1 + 0x16d78) = (int)*(short *)(iVar4 + 2);
    }
    uVar2 = 0;
    _DAT_00016d70 = _DAT_00016d70 ^ 1;
  }
  else {
    uVar2 = 0xffffffff;
    *param_3 = 0;
  }
  return uVar2;
}

void Nas_BgCopyInit__Fv(void)
{
  int iVar1;
  int iVar2;
  
  iVar2 = 0x10;
  iVar1 = 0;
  do {
    *(undefined *)(iVar1 + 0x16794) = 0;
    iVar2 = iVar2 + -1;
    iVar1 = iVar1 + 0x58;
  } while (iVar2 != 0);
  return;
}

int Nas_BgCopyDisk__FlPUcPUcUlllP13OSMesgQueue_sl
              (undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
              undefined4 param_5,undefined4 param_6,undefined4 param_7,undefined4 param_8)
{
  int iVar1;
  
  iVar1 = Nas_BgCopyReq__FPUcPUcUlllP13OSMesgQueue_sl
                    (param_2,param_3,param_4,param_5,param_6,param_7,param_8);
  if (iVar1 == 0) {
    iVar1 = 0;
  }
  else {
    osSendMesg__FP13OSMesgQueue_sPvl(0x16d14,iVar1,0);
    *(undefined4 *)(iVar1 + 0x18) = param_1;
  }
  return iVar1;
}

undefined *
Nas_BgCopyReq__FPUcPUcUlllP13OSMesgQueue_sl
          (undefined4 param_1,undefined4 param_2,int param_3,undefined param_4,int param_5,
          undefined4 param_6,undefined4 param_7)
{
  int iVar1;
  int iVar2;
  undefined *unaff_r31;
  int iVar3;
  
  iVar1 = 0;
  iVar2 = 0;
  iVar3 = 0x10;
  do {
    if (*(char *)(iVar1 + 0x16794) == '\0') {
      unaff_r31 = (undefined *)(iVar1 + 0x16794);
      break;
    }
    iVar2 = iVar2 + 1;
    iVar1 = iVar1 + 0x58;
    iVar3 = iVar3 + -1;
  } while (iVar3 != 0);
  if (iVar2 == 0x10) {
    unaff_r31 = (undefined *)0x0;
  }
  else {
    *unaff_r31 = 1;
    *(undefined4 *)(unaff_r31 + 8) = param_1;
    *(undefined4 *)(unaff_r31 + 4) = param_2;
    *(undefined4 *)(unaff_r31 + 0xc) = param_2;
    *(int *)(unaff_r31 + 0x10) = param_3;
    if (param_5 == 0) {
      *(undefined4 *)(unaff_r31 + 0x14) = 0x1000;
    }
    else if (param_5 == 1) {
      *(int *)(unaff_r31 + 0x14) = param_3;
    }
    else {
      *(uint *)(unaff_r31 + 0x14) = param_3 / param_5 + 0xffU & 0xffffff00;
      if (*(uint *)(unaff_r31 + 0x14) < 0x100) {
        *(undefined4 *)(unaff_r31 + 0x14) = 0x100;
      }
    }
    *(undefined4 *)(unaff_r31 + 0x20) = param_6;
    unaff_r31[1] = 3;
    unaff_r31[2] = param_4;
    *(undefined4 *)(unaff_r31 + 0x1c) = param_7;
    osCreateMesgQueue__FP13OSMesgQueue_sPPvl(unaff_r31 + 0x24,unaff_r31 + 0x3c,1);
  }
  return unaff_r31;
}

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
void Nas_BgCopyMain__Fl(int param_1)
{
  int iVar1;
  int iVar2;
  int local_14;
  
  if (_DAT_00017a04 != 1) {
    if (_DAT_00016d6c == 0) {
      if (param_1 == 0) {
        iVar1 = osRecvMesg__FP13OSMesgQueue_sPPvl(0x16d14,&local_14,0);
        if (iVar1 == -1) {
          _DAT_00016d6c = 0;
        }
        else {
          _DAT_00016d6c = local_14;
        }
      }
      else {
        do {
          iVar1 = osRecvMesg__FP13OSMesgQueue_sPPvl(0x16d14,&local_14,0);
        } while (iVar1 != -1);
      }
    }
    if (_DAT_00016d6c != 0) {
      __BgCopyDisk__FP7Bgload_l(_DAT_00016d6c,param_1);
    }
    iVar1 = 0;
    iVar2 = 0;
    do {
      if ((*(char *)(iVar2 + 0x16794) == '\x01') &&
         (local_14 = iVar2 + 0x16794, *(char *)(iVar2 + 0x16796) != '\x01')) {
        __BgCopySub__FP7Bgload_l(local_14,param_1);
      }
      iVar1 = iVar1 + 1;
      iVar2 = iVar2 + 0x58;
    } while (iVar1 < 0x10);
  }
  return;
}

void __BgCopyDisk__FP7Bgload_l(void)
{
  return;
}

/* WARNING: Removing unreachable block (ram,0x00013084) */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
void __BgCopyFinishProcess__FP7Bgload_(undefined *param_1)
{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  int iVar4;
  uint local_34;
  uint local_30;
  undefined4 local_2c;
  undefined4 local_28;
  undefined auStack_24 [4];
  undefined auStack_20 [8];
  uint local_18;
  uint local_14;
  
  local_14 = *(uint *)(param_1 + 0x1c);
  uVar2 = local_14 >> 0x10 & 0xff;
  uVar3 = local_14 >> 8 & 0xff;
  uVar1 = local_14 & 0xff;
  local_18 = uVar3;
  if (uVar2 == 1) {
    iVar4 = _DAT_0001786c + uVar3 * 0x14;
    local_34 = (uint)*(byte *)(iVar4 + 2);
    uVar2 = (uint)*(byte *)(iVar4 + 3);
    local_30 = uVar2;
    if (local_34 == 0xff) {
      local_2c = 0;
    }
    else {
      local_2c = __Load_Wave_Check__FlPUl(local_34,auStack_24);
    }
    if (uVar2 == 0xff) {
      local_28 = 0;
    }
    else {
      local_28 = __Load_Wave_Check__FlPUl(uVar2,auStack_20);
    }
    Nas_WriteIDbank__Fll(uVar3,uVar1);
    Nas_BankOfsToAddr__FlPUcP10WaveMedia_l(uVar3,*(undefined4 *)(param_1 + 4),&local_34,1);
  }
  else if (uVar2 == 0) {
    Nas_WriteIDseq__Fll(uVar3,uVar1);
  }
  else if (uVar2 < 3) {
    Nas_WriteIDwave__Fll(uVar3,uVar1);
  }
  *param_1 = 0;
  osSendMesg__FP13OSMesgQueue_sPvl
            (*(undefined4 *)(param_1 + 0x20),*(undefined4 *)(param_1 + 0x1c),0);
  return;
}

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
void __BgCopySub__FP7Bgload_l(undefined *param_1,int param_2)
{
  char cVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  
  iVar2 = _DAT_0001785c;
  cVar1 = param_1[1];
  if ('\x01' < cVar1) {
    param_1[1] = cVar1 + -1;
    return;
  }
  if (cVar1 == '\x01') {
    param_1[1] = 0;
  }
  else {
    if (param_2 != 0) {
      osRecvMesg__FP13OSMesgQueue_sPPvl(param_1 + 0x24,0,1);
      *param_1 = 0;
      return;
    }
    iVar3 = osRecvMesg__FP13OSMesgQueue_sPPvl(param_1 + 0x24,0,0);
    if (iVar3 == -1) {
      return;
    }
  }
  uVar4 = *(uint *)(param_1 + 0x10);
  if (uVar4 == 0) {
    __BgCopyFinishProcess__FP7Bgload_(param_1);
  }
  else if (uVar4 < *(uint *)(param_1 + 0x14)) {
    if (param_1[2] == '\x01') {
      __Nas_BgDiskCopy__FPUcPUcUll
                (*(undefined4 *)(param_1 + 8),*(undefined4 *)(param_1 + 0xc),uVar4,
                 (int)*(short *)(iVar2 + 2));
    }
    else if (param_1[2] == '\x05') {
      __Nas_ExCopy__FP7Bgload_l(param_1,uVar4);
    }
    else {
      __Nas_BgCopy__FP7Bgload_l(param_1,uVar4);
    }
    *(undefined4 *)(param_1 + 0x10) = 0;
  }
  else {
    if (param_1[2] == '\x01') {
      __Nas_BgDiskCopy__FPUcPUcUll
                (*(undefined4 *)(param_1 + 8),*(undefined4 *)(param_1 + 0xc),
                 *(uint *)(param_1 + 0x14),(int)*(short *)(iVar2 + 2));
    }
    else if (param_1[2] == '\x05') {
      __Nas_ExCopy__FP7Bgload_l(param_1);
    }
    else {
      __Nas_BgCopy__FP7Bgload_l(param_1);
    }
    *(int *)(param_1 + 0x10) = *(int *)(param_1 + 0x10) - *(int *)(param_1 + 0x14);
    *(int *)(param_1 + 8) = *(int *)(param_1 + 8) + *(int *)(param_1 + 0x14);
    *(int *)(param_1 + 0xc) = *(int *)(param_1 + 0xc) + *(int *)(param_1 + 0x14);
  }
  return;
}

void __Nas_BgCopy__FP7Bgload_l(int param_1,int param_2)
{
  uint uVar1;
  
  uVar1 = param_2 + 0x1fU & 0xffffffe0;
  osInvalDCache2__FPvl(*(undefined4 *)(param_1 + 0xc),uVar1);
  osCreateMesgQueue__FP13OSMesgQueue_sPPvl(param_1 + 0x24,param_1 + 0x3c,1);
  Nas_StartDma__FP8OSIoMesgllUlPvUlP13OSMesgQueue_slPSc
            (param_1 + 0x40,0,0,*(undefined4 *)(param_1 + 8),*(undefined4 *)(param_1 + 0xc),uVar1,
             param_1 + 0x24,(int)*(char *)(param_1 + 2),@1044);
  return;
}

void __Nas_ExCopy__FP7Bgload_l(int param_1,int param_2)
{
  uint uVar1;
  
  uVar1 = param_2 + 0x1fU & 0xffffffe0;
  osInvalDCache2__FPvl(*(undefined4 *)(param_1 + 0xc),uVar1);
  osCreateMesgQueue__FP13OSMesgQueue_sPPvl(param_1 + 0x24,param_1 + 0x3c,1);
  bcopy__FPvPvUl(*(undefined4 *)(param_1 + 8),*(undefined4 *)(param_1 + 0xc),uVar1);
  osSendMesg__FP13OSMesgQueue_sPvl(param_1 + 0x24,0,0);
  return;
}

void __Nas_BgDiskCopy__FPUcPUcUll(void)
{
  return;
}

/* WARNING: Removing unreachable block (ram,0x000134b8) */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
void __WaveTouch__FP6wtstr_UlP10WaveMedia_(uint **param_1,int param_2,int param_3)
{
  int iVar1;
  byte bVar2;
  uint *puVar3;
  
  if (*param_1 < (uint *)0x80000001) {
    *param_1 = (uint *)((int)*param_1 + param_2);
    puVar3 = *param_1;
    if (((*puVar3 & 0xffffff) != 0) && ((*(byte *)puVar3 & 1) != 1)) {
      puVar3[2] = puVar3[2] + param_2;
      puVar3[3] = puVar3[3] + param_2;
      bVar2 = *(byte *)puVar3 >> 2 & 3;
      if (bVar2 == 1) {
        puVar3[1] = puVar3[1] + *(int *)(param_3 + 0xc);
        *(byte *)puVar3 = (byte)(*(int *)(param_3 + 0x14) << 2) & 0xc | *(byte *)puVar3 & 0xf3;
      }
      else if (bVar2 == 0) {
        puVar3[1] = puVar3[1] + *(int *)(param_3 + 8);
        *(byte *)puVar3 = (byte)(*(int *)(param_3 + 0x10) << 2) & 0xc | *(byte *)puVar3 & 0xf3;
      }
      *(byte *)puVar3 = *(byte *)puVar3 & 0xfe | 1;
      if ((((*(byte *)puVar3 >> 1 & 1) != 0) && ((*(byte *)puVar3 >> 2 & 3) != 0)) &&
         (_DAT_0001678c < 0x80)) {
        iVar1 = _DAT_0001678c * 4;
        _DAT_0001678c = _DAT_0001678c + 1;
        *(uint **)(iVar1 + 0x15b8c) = puVar3;
      }
    }
  }
  return;
}

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
void Nas_BankOfsToAddr__FlPUcP10WaveMedia_l
               (undefined4 param_1,undefined4 param_2,undefined4 *param_3,int param_4)
{
  bool bVar1;
  uint *puVar2;
  int iVar3;
  uint uVar4;
  uint uVar5;
  int iVar6;
  int iVar7;
  int local_30;
  
  bVar1 = _DAT_00016790 == 0;
  if (bVar1) {
    awheap$1077._0_4_ = 0;
  }
  _DAT_0001678c = 0;
  Nas_BankOfsToAddr_Inner__FlPUcP10WaveMedia_(param_1,param_2,param_3);
  for (local_30 = 0; local_30 < _DAT_0001678c; local_30 = local_30 + 1) {
  }
  iVar7 = 0;
  iVar6 = 0;
  while ((iVar7 < _DAT_0001678c && (_DAT_00016790 != 0x78))) {
    puVar2 = *(uint **)(iVar6 + 0x15b8c);
    uVar5 = 0;
    if (param_4 == 1) {
      uVar4 = *(byte *)puVar2 >> 2 & 3;
      if (uVar4 == param_3[4]) {
        uVar5 = Nas_Alloc_Single__FllPUcScl(*puVar2 & 0xffffff,*param_3,puVar2[1],uVar4,0);
      }
      else if (uVar4 == param_3[5]) {
        uVar5 = Nas_Alloc_Single__FllPUcScl(*puVar2 & 0xffffff,param_3[1],puVar2[1],uVar4,0);
      }
      else if (uVar4 == 3) {
        uVar5 = Nas_Alloc_Single__FllPUcScl(*puVar2 & 0xffffff,0xfe,puVar2[1],3,0);
      }
    }
    else if ((param_4 < 1) && (-1 < param_4)) {
      uVar4 = *(byte *)puVar2 >> 2 & 3;
      if (uVar4 == param_3[4]) {
        uVar5 = Nas_Alloc_Single__FllPUcScl(*puVar2 & 0xffffff,*param_3,puVar2[1],uVar4,1);
      }
      else if (uVar4 == param_3[5]) {
        uVar5 = Nas_Alloc_Single__FllPUcScl(*puVar2 & 0xffffff,param_3[1],puVar2[1],uVar4,1);
      }
      else if (uVar4 == 3) {
        uVar5 = Nas_Alloc_Single__FllPUcScl(*puVar2 & 0xffffff,0xfe,puVar2[1],3,1);
      }
    }
    if (uVar5 != 0) {
      if (param_4 == 1) {
        iVar3 = _DAT_00016790 * 0x14;
        *(uint **)(iVar3 + 0x15d90) = puVar2;
        *(uint *)(iVar3 + 0x15d94) = uVar5;
        *(uint *)(iVar3 + 0x15d98) = _DAT_00016790 << 0x18 | 0xffffff;
        *(undefined4 *)(iVar3 + 0x15d9c) = 0;
        *(uint *)(iVar3 + 0x15d8c) = puVar2[1] + (*puVar2 & 0xffffff) + (*(byte *)puVar2 >> 2 & 3);
        _DAT_00016790 = _DAT_00016790 + 1;
      }
      else if ((param_4 < 1) && (-1 < param_4)) {
        if ((*(byte *)puVar2 >> 2 & 3) == 1) {
          Nas_FastDiskCopy__FPUcPUcUll
                    (puVar2[1],uVar5,*puVar2 & 0xffffff,(int)*(short *)(_DAT_0001785c + 2));
          *(byte *)puVar2 = *(byte *)puVar2 & 0xf3;
          puVar2[1] = uVar5;
        }
        else {
          Nas_FastCopy__FPUcPUcUll(puVar2[1],uVar5,*puVar2 & 0xffffff);
          *(byte *)puVar2 = *(byte *)puVar2 & 0xf3;
          puVar2[1] = uVar5;
        }
      }
    }
    iVar7 = iVar7 + 1;
    iVar6 = iVar6 + 4;
  }
  _DAT_0001678c = 0;
  if ((_DAT_00016790 != 0) && (bVar1)) {
    iVar6 = (_DAT_00016790 + -1) * 0x14;
    puVar2 = *(uint **)(iVar6 + 0x15d90);
    Nas_BgCopyReq__FPUcPUcUlllP13OSMesgQueue_sl
              (puVar2[1],*(undefined4 *)(iVar6 + 0x15d94),*puVar2 & 0xffffff,
               *(byte *)puVar2 >> 2 & 3,((*puVar2 & 0xffffff) >> 0xc) + 1,0x16e9c,
               *(undefined4 *)(iVar6 + 0x15d98));
  }
  return;
}

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
undefined4 Nas_CheckBgWave__Fl(int param_1)
{
  uint uVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  uint *puVar5;
  uint local_18 [3];
  
  if (0 < _DAT_00016790) {
    if (param_1 != 0) {
      osRecvMesg__FP13OSMesgQueue_sPPvl(0x16e9c,local_18,0);
      _DAT_00016790 = 0;
      return 0;
    }
    iVar3 = osRecvMesg__FP13OSMesgQueue_sPPvl(0x16e9c,local_18,0);
    if (iVar3 == -1) {
      return 0;
    }
    local_18[0] = local_18[0] >> 0x18;
    iVar2 = local_18[0] * 0x14;
    iVar3 = _DAT_00016790;
    if (*(int *)(iVar2 + 0x15d9c) == 0) {
      puVar5 = *(uint **)(iVar2 + 0x15d90);
      if (*(int *)(iVar2 + 0x15d8c) == puVar5[1] + (*puVar5 & 0xffffff) + (*(byte *)puVar5 >> 2 & 3)
         ) {
        puVar5[1] = *(uint *)(iVar2 + 0x15d94);
        *(byte *)puVar5 = *(byte *)puVar5 & 0xf3;
      }
      *(undefined4 *)(iVar2 + 0x15d9c) = 1;
      iVar3 = _DAT_00016790;
    }
    while (_DAT_00016790 = iVar3, 0 < _DAT_00016790) {
      iVar2 = (_DAT_00016790 + -1) * 0x14;
      iVar3 = _DAT_00016790 + -1;
      if (*(int *)(iVar2 + 0x15d9c) != 1) {
        puVar5 = *(uint **)(iVar2 + 0x15d90);
        uVar4 = *(byte *)puVar5 >> 2 & 3;
        uVar1 = *puVar5 & 0xffffff;
        if (*(int *)(iVar2 + 0x15d8c) == puVar5[1] + uVar1 + uVar4) {
          Nas_BgCopyReq__FPUcPUcUlllP13OSMesgQueue_sl
                    (puVar5[1],*(undefined4 *)(iVar2 + 0x15d94),uVar1,uVar4,(uVar1 >> 0xc) + 1,
                     0x16e9c,*(undefined4 *)(iVar2 + 0x15d98));
          return 1;
        }
        *(undefined4 *)(iVar2 + 0x15d9c) = 1;
        iVar3 = _DAT_00016790 + -1;
      }
    }
  }
  return 1;
}

int __AddList__FP13smzwavetable_lP9Loadlist_(int param_1,int param_2,int param_3)
{
  int iVar1;
  int iVar2;
  int iVar3;
  
  iVar2 = 0;
  iVar1 = 0;
  iVar3 = param_2;
  if (0 < param_2) {
    do {
      if (*(int *)(*(int *)(param_3 + iVar1) + 4) == *(int *)(param_1 + 4)) break;
      iVar2 = iVar2 + 1;
      iVar1 = iVar1 + 4;
      iVar3 = iVar3 + -1;
    } while (iVar3 != 0);
  }
  if (iVar2 == param_2) {
    iVar3 = param_2 * 4;
    param_2 = param_2 + 1;
    *(int *)(param_3 + iVar3) = param_1;
  }
  return param_2;
}

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
undefined4 MakeWaveList__FlP9Loadlist_(int param_1,undefined4 param_2)
{
  byte bVar1;
  byte bVar2;
  int iVar3;
  undefined4 uVar4;
  int iVar5;
  
  uVar4 = 0;
  bVar2 = *(byte *)(_DAT_0001786c + param_1 * 0x14);
  bVar1 = *(byte *)(_DAT_0001786c + param_1 * 0x14 + 1);
  for (iVar5 = 0; iVar5 < (int)(uint)bVar1; iVar5 = iVar5 + 1) {
    iVar3 = PercToPp__Fll(param_1,iVar5);
    if (iVar3 != 0) {
      uVar4 = __AddList__FP13smzwavetable_lP9Loadlist_(*(undefined4 *)(iVar3 + 4),uVar4,param_2);
    }
  }
  for (iVar5 = 0; iVar5 < (int)(uint)bVar2; iVar5 = iVar5 + 1) {
    iVar3 = ProgToVp__Fll(param_1,iVar5);
    if (iVar3 != 0) {
      if (*(char *)(iVar3 + 1) != '\0') {
        uVar4 = __AddList__FP13smzwavetable_lP9Loadlist_(*(undefined4 *)(iVar3 + 8),uVar4,param_2);
      }
      if (*(char *)(iVar3 + 2) != '\x7f') {
        uVar4 = __AddList__FP13smzwavetable_lP9Loadlist_
                          (*(undefined4 *)(iVar3 + 0x18),uVar4,param_2);
      }
      uVar4 = __AddList__FP13smzwavetable_lP9Loadlist_(*(undefined4 *)(iVar3 + 0x10),uVar4,param_2);
    }
  }
  return uVar4;
}

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
void __Reload__FP6wtstr_(uint **param_1)
{
  int iVar1;
  uint *puVar2;
  
  puVar2 = *param_1;
  if ((*puVar2 & 0xffffff) == 0) {
    return;
  }
  if ((*(byte *)puVar2 >> 1 & 1) == 0) {
    return;
  }
  if ((*(byte *)puVar2 >> 2 & 3) == 0) {
    return;
  }
  iVar1 = _DAT_0001678c * 4;
  _DAT_0001678c = _DAT_0001678c + 1;
  *(uint **)(iVar1 + 0x15b8c) = puVar2;
  return;
}

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
void WaveReload__FllP10WaveMedia_(int param_1,int param_2,undefined4 *param_3)
{
  bool bVar1;
  byte bVar2;
  byte bVar3;
  ushort uVar4;
  int iVar5;
  int iVar6;
  uint *puVar7;
  uint uVar8;
  int iVar9;
  uint unaff_r27;
  int local_38;
  
  bVar1 = _DAT_00016790 == 0;
  _DAT_0001678c = 0;
  iVar5 = _DAT_0001786c + param_1 * 0x14;
  bVar3 = *(byte *)(_DAT_0001786c + param_1 * 0x14);
  bVar2 = *(byte *)(iVar5 + 1);
  uVar4 = *(ushort *)(iVar5 + 4);
  for (local_38 = 0; local_38 < (int)(uint)bVar3; local_38 = local_38 + 1) {
    iVar5 = ProgToVp__Fll(param_1);
    if (iVar5 != 0) {
      if (*(char *)(iVar5 + 1) != '\0') {
        __Reload__FP6wtstr_(iVar5 + 8);
      }
      if (*(char *)(iVar5 + 2) != '\x7f') {
        __Reload__FP6wtstr_(iVar5 + 0x18);
      }
      __Reload__FP6wtstr_(iVar5 + 0x10);
    }
  }
  for (iVar5 = 0; iVar5 < (int)(uint)bVar2; iVar5 = iVar5 + 1) {
    iVar9 = PercToPp__Fll(param_1);
    if (iVar9 != 0) {
      __Reload__FP6wtstr_(iVar9 + 4);
    }
  }
  for (iVar5 = 0; iVar5 < (int)(uint)uVar4; iVar5 = iVar5 + 1) {
    iVar9 = VpercToVep__Fll(param_1);
    if (iVar9 != 0) {
      __Reload__FP6wtstr_();
    }
  }
  if (_DAT_0001678c != 0) {
    iVar5 = _DAT_0001678c;
    if (0 < _DAT_0001678c) {
      do {
        iVar5 = iVar5 + -1;
      } while (iVar5 != 0);
    }
    iVar9 = 0;
    iVar5 = 0;
    while ((iVar9 < _DAT_0001678c && (_DAT_00016790 != 0x78))) {
      puVar7 = *(uint **)(iVar5 + 0x15b8c);
      uVar8 = *(byte *)puVar7 >> 2 & 3;
      if ((*(byte *)puVar7 >> 2 & 3) != 0) {
        if (param_2 == 1) {
          if (uVar8 == param_3[4]) {
            unaff_r27 = Nas_Alloc_Single__FllPUcScl(*puVar7 & 0xffffff,*param_3,puVar7[1],uVar8,0);
          }
          else if (uVar8 == param_3[5]) {
            unaff_r27 = Nas_Alloc_Single__FllPUcScl(*puVar7 & 0xffffff,param_3[1],puVar7[1],uVar8,0)
            ;
          }
        }
        else if ((param_2 < 1) && (-1 < param_2)) {
          if (uVar8 == param_3[4]) {
            unaff_r27 = Nas_Alloc_Single__FllPUcScl(*puVar7 & 0xffffff,*param_3,puVar7[1],uVar8,1);
          }
          else if (uVar8 == param_3[5]) {
            unaff_r27 = Nas_Alloc_Single__FllPUcScl(*puVar7 & 0xffffff,param_3[1],puVar7[1],uVar8,1)
            ;
          }
        }
        if (unaff_r27 != 0) {
          if (param_2 == 1) {
            iVar6 = _DAT_00016790 * 0x14;
            *(uint **)(iVar6 + 0x15d90) = puVar7;
            *(uint *)(iVar6 + 0x15d94) = unaff_r27;
            *(uint *)(iVar6 + 0x15d98) = _DAT_00016790 << 0x18 | 0xffffff;
            *(undefined4 *)(iVar6 + 0x15d9c) = 0;
            *(uint *)(iVar6 + 0x15d8c) =
                 puVar7[1] + (*puVar7 & 0xffffff) + (*(byte *)puVar7 >> 2 & 3);
            _DAT_00016790 = _DAT_00016790 + 1;
          }
          else if ((param_2 < 1) && (-1 < param_2)) {
            if ((*(byte *)puVar7 >> 2 & 3) == 1) {
              Nas_FastDiskCopy__FPUcPUcUll
                        (puVar7[1],unaff_r27,*puVar7 & 0xffffff,(int)*(short *)(_DAT_0001785c + 2));
              *(byte *)puVar7 = *(byte *)puVar7 & 0xf3;
              puVar7[1] = unaff_r27;
            }
            else {
              Nas_FastCopy__FPUcPUcUll(puVar7[1],unaff_r27,*puVar7 & 0xffffff);
              *(byte *)puVar7 = *(byte *)puVar7 & 0xf3;
              puVar7[1] = unaff_r27;
            }
          }
        }
      }
      iVar9 = iVar9 + 1;
      iVar5 = iVar5 + 4;
    }
    _DAT_0001678c = 0;
    if ((_DAT_00016790 != 0) && (bVar1)) {
      iVar5 = (_DAT_00016790 + -1) * 0x14;
      puVar7 = *(uint **)(iVar5 + 0x15d90);
      Nas_BgCopyReq__FPUcPUcUlllP13OSMesgQueue_sl
                (puVar7[1],*(undefined4 *)(iVar5 + 0x15d94),*puVar7 & 0xffffff,
                 *(byte *)puVar7 >> 2 & 3,((*puVar7 & 0xffffff) >> 0xc) + 1,0x16e9c,
                 *(undefined4 *)(iVar5 + 0x15d98));
    }
  }
  return;
}

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
void EmemReload__Fv(void)
{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  uint local_38;
  uint local_34;
  int local_28;
  int local_24;
  
  iVar1 = __Get_ArcHeader__Fl(2);
  iVar4 = 0;
  for (iVar5 = 0; iVar5 < _DAT_00017e38; iVar5 = iVar5 + 1) {
    if (*(short *)(iVar4 + 0x17e48) == 1) {
      iVar2 = __Link_BankNum__Fll(1,(int)*(short *)(iVar4 + 0x17e4a));
      iVar3 = _DAT_0001786c + iVar2 * 0x14;
      local_38 = (uint)*(byte *)(iVar3 + 2);
      local_34 = (uint)*(byte *)(iVar3 + 3);
      if (local_38 != 0xff) {
        local_38 = __Link_BankNum__Fll(2);
        local_28 = (int)*(char *)(iVar1 + local_38 * 0x10 + 0x18);
      }
      if (local_34 != 0xff) {
        local_34 = __Link_BankNum__Fll(2);
        local_24 = (int)*(char *)(iVar1 + local_34 * 0x10 + 0x18);
      }
      WaveReload__FllP10WaveMedia_(iVar2,0,&local_38);
    }
    iVar4 = iVar4 + 0xc;
  }
  return;
}

undefined4 __ExtDiskFinishCheck__FP8Extdisk_(void)
{
  return 0;
}

undefined4 __ExtDiskInit__FP8Extdisk_llPUcl(void)
{
  return 0;
}

undefined4 __ExtDiskLoad__FP8Extdisk_(void)
{
  return 1;
}

void MK_load__FllPUc(undefined4 param_1,undefined4 param_2,undefined4 param_3)
{
  int iVar1;
  
  if (init$1355 == '\0') {
    use$1354 = 0;
    init$1355 = '\x01';
  }
  iVar1 = use$1354;
  *(undefined4 *)(MK_RMES + use$1354 * 4) = param_3;
  Nas_PreLoad_BG__FllllP13OSMesgQueue_s(param_1,param_2,0,iVar1,MK_QUEUE);
  use$1354 = use$1354 + 1;
  if (use$1354 == 0x10) {
    use$1354 = 0;
  }
  return;
}

void MK_FrameWork__Fv(void)
{
  int iVar1;
  uint local_c [3];
  
  iVar1 = osRecvMesg__FP13OSMesgQueue_sPPvl(MK_QUEUE,local_c,0);
  if (iVar1 != -1) {
    if (*(undefined **)(MK_RMES + (local_c[0] >> 0x16 & 0x3fc)) != (undefined *)0x0) {
      **(undefined **)(MK_RMES + (local_c[0] >> 0x16 & 0x3fc)) = 0;
    }
  }
  return;
}

void MK_Init__Fv(void)
{
  osCreateMesgQueue__FP13OSMesgQueue_sPPvl(MK_QUEUE,MK_QBUF,0x10);
  return;
}

