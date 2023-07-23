
void Jac_HeapSetup(int param_1,int param_2)
{
  if (param_1 == 0) {
    OSReport(@148);
    OSReport(@149);
  }
  else {
    OSReport(...rodata.0);
    OSReport(@146);
    Nas_HeapInit__FP6ALHeapPUcl(audio_hp,param_1,param_2);
    OSReport(@147,param_1,param_1 + param_2 + -1);
  }
  audio_hp_exist = (uint)(param_1 != 0);
  return;
}

int GetAudioHeapRemain(void)
{
  if (audio_hp_exist == 0) {
    return 0;
  }
  return audio_hp._8_4_ - (audio_hp._4_4_ - audio_hp._0_4_);
}

undefined4 OSAlloc2(undefined4 param_1)
{
  undefined4 uVar1;
  undefined4 unaff_r31;
  
  Console_printf(&@159,param_1);
  if (audio_hp_exist == 0) {
    OSReport(@160);
  }
  uVar1 = OSDisableInterrupts();
  if (audio_hp_exist == 1) {
    unaff_r31 = Nas_HeapAlloc__FP6ALHeapl(audio_hp,param_1);
  }
  else if ((audio_hp_exist < 1) && (-1 < audio_hp_exist)) {
    unaff_r31 = OSAllocFromHeap(uRam00000000,param_1);
  }
  OSRestoreInterrupts(uVar1);
  return unaff_r31;
}

void OSFree2(undefined4 param_1)
{
  if (audio_hp_exist == 1) {
    Nas_HeapFree__FP6ALHeap(audio_hp,param_1);
  }
  else if ((audio_hp_exist < 1) && (-1 < audio_hp_exist)) {
    OSFreeToHeap(uRam00000000);
  }
  return;
}

void Jac_Init(void)
{
  undefined4 uVar1;
  int iVar2;
  undefined4 *puVar3;
  int iVar4;
  
  OSReport(@172);
  iVar2 = 0;
  iVar4 = 0;
  do {
    uVar1 = OSAlloc2(iRam00000000 << 1);
    puVar3 = (undefined4 *)(dac + iVar4);
    *puVar3 = uVar1;
    OSReport(@173,iVar2,*puVar3);
    Jac_bzero__FPvl(*puVar3,iRam00000000 << 1);
    DCStoreRange(*puVar3,iRam00000000 << 1);
    iVar2 = iVar2 + 1;
    iVar4 = iVar4 + 4;
  } while (iVar2 < 3);
  AIInit(0);
  AIInitDMA(dac._8_4_,iRam00000000 << 1);
  OSReport(@174);
  return;
}

undefined4 Jac_GetCurrentVCounter(void)
{
  return JAC_VFRAME_COUNTER;
}

void HaltDSPSignal(void)
{
  DSP_WAIT = 2;
  return;
}

undefined4 HaltDSP(void)
{
  undefined4 uVar1;
  
  uVar1 = DSP_WAIT;
  DSP_WAIT = 1;
  return uVar1;
}

undefined4 RunDSP(void)
{
  undefined4 uVar1;
  
  uVar1 = DSP_WAIT;
  DSP_WAIT = 0;
  return uVar1;
}

undefined4 CheckHaltDSP(void)
{
  return DSP_WAIT;
}

void MixMonoTrack__FPslPFl_Ps(short *param_1,int param_2,code *param_3)
{
  int iVar1;
  short *psVar2;
  
  Probe_Start(5,"MONO-MIX");
  psVar2 = (short *)(*param_3)(param_2);
  if ((psVar2 != (short *)0x0) && (Probe_Finish(5), 0 < param_2)) {
    do {
      iVar1 = (int)*param_1 + (int)*psVar2;
      if (iVar1 < -0x8000) {
        iVar1 = -0x7fff;
      }
      if (0x7fff < iVar1) {
        iVar1 = 0x7fff;
      }
      *param_1 = (short)iVar1;
      iVar1 = (int)param_1[1] + (int)*psVar2;
      if (iVar1 < -0x8000) {
        iVar1 = -0x7fff;
      }
      if (0x7fff < iVar1) {
        iVar1 = 0x7fff;
      }
      psVar2 = psVar2 + 1;
      param_1[1] = (short)iVar1;
      param_1 = param_1 + 2;
      param_2 = param_2 + -1;
    } while (param_2 != 0);
  }
  return;
}

void MixMonoTrackWide__FPslPFl_Ps(short *param_1,int param_2,code *param_3)
{
  int iVar1;
  short *psVar2;
  
  Probe_Start(5,@213);
  psVar2 = (short *)(*param_3)(param_2);
  if ((psVar2 != (short *)0x0) && (Probe_Finish(5), 0 < param_2)) {
    do {
      iVar1 = (int)*param_1 + (int)*psVar2;
      if (iVar1 < -0x8000) {
        iVar1 = -0x7fff;
      }
      if (0x7fff < iVar1) {
        iVar1 = 0x7fff;
      }
      *param_1 = (short)iVar1;
      iVar1 = (int)param_1[1] - (int)*psVar2;
      if (iVar1 < -0x8000) {
        iVar1 = -0x7fff;
      }
      if (0x7fff < iVar1) {
        iVar1 = 0x7fff;
      }
      psVar2 = psVar2 + 1;
      param_1[1] = (short)iVar1;
      param_1 = param_1 + 2;
      param_2 = param_2 + -1;
    } while (param_2 != 0);
  }
  return;
}

void MixExtraTrack__FPslPFl_Ps(short *param_1,int param_2,code *param_3)
{
  int iVar1;
  short *psVar2;
  short *psVar3;
  
  Probe_Start(5,@230);
  psVar2 = (short *)(*param_3)(param_2);
  if (psVar2 != (short *)0x0) {
    Probe_Finish(5);
    Probe_Start(6,@231);
    psVar3 = psVar2 + iRam00000000;
    if (0 < param_2) {
      do {
        iVar1 = (int)*param_1 + (int)*psVar3;
        if (iVar1 < -0x8000) {
          iVar1 = -0x7fff;
        }
        if (0x7fff < iVar1) {
          iVar1 = 0x7fff;
        }
        *param_1 = (short)iVar1;
        iVar1 = (int)param_1[1] + (int)*psVar2;
        if (iVar1 < -0x8000) {
          iVar1 = -0x7fff;
        }
        if (0x7fff < iVar1) {
          iVar1 = 0x7fff;
        }
        psVar2 = psVar2 + 1;
        param_1[1] = (short)iVar1;
        param_1 = param_1 + 2;
        psVar3 = psVar3 + 1;
        param_2 = param_2 + -1;
      } while (param_2 != 0);
    }
    Probe_Finish(6);
  }
  return;
}

void MixInterleaveTrack__FPslPFl_Ps(short *param_1,int param_2,code *param_3)
{
  int iVar1;
  short *psVar2;
  
  psVar2 = (short *)(*param_3)(param_2);
  if ((psVar2 != (short *)0x0) && (param_2 = param_2 << 1, 0 < param_2)) {
    do {
      iVar1 = (int)*param_1 + (int)*psVar2;
      if (iVar1 < -0x8000) {
        iVar1 = -0x7fff;
      }
      if (0x7fff < iVar1) {
        iVar1 = 0x7fff;
      }
      psVar2 = psVar2 + 1;
      *param_1 = (short)iVar1;
      param_1 = param_1 + 1;
      param_2 = param_2 + -1;
    } while (param_2 != 0);
  }
  return;
}

undefined4 Jac_GetMixcallback(undefined *param_1)
{
  *param_1 = ext_mixmode;
  return ext_mixcallback;
}

void Jac_RegisterMixcallback(undefined4 param_1,undefined param_2)
{
  ext_mixcallback = param_1;
  ext_mixmode = param_2;
  return;
}

/* WARNING: Removing unreachable block (ram,0x000107dc) */
void Jac_VframeWork(void)
{
  int iVar1;
  undefined4 uVar2;
  
  if (init$246 == '\0') {
    dacp$245 = 0;
    init$246 = '\x01';
  }
  JAC_VFRAME_COUNTER = JAC_VFRAME_COUNTER + 1;
  iVar1 = MixDsp__Fl(uRam00000000 >> 1);
  Jac_imixcopy__FPsPsPsl
            (iVar1 + uRam00000000 * 2,iVar1,*(undefined4 *)(dac + dacp$245 * 4),uRam00000000 >> 1);
  if (ext_mixcallback != 0) {
    if (ext_mixmode == 2) {
      MixExtraTrack__FPslPFl_Ps(*(undefined4 *)(dac + dacp$245 * 4),uRam00000000 >> 1);
    }
    else if (ext_mixmode < 2) {
      if (ext_mixmode == 0) {
        MixMonoTrack__FPslPFl_Ps(*(undefined4 *)(dac + dacp$245 * 4),uRam00000000 >> 1);
      }
      else {
        MixMonoTrackWide__FPslPFl_Ps(*(undefined4 *)(dac + dacp$245 * 4),uRam00000000 >> 1);
      }
    }
    else if (ext_mixmode < 4) {
      MixInterleaveTrack__FPslPFl_Ps(*(undefined4 *)(dac + dacp$245 * 4),uRam00000000 >> 1);
    }
  }
  uVar2 = OSDisableInterrupts();
  DCStoreRange(*(undefined4 *)(dac + dacp$245 * 4),uRam00000000 << 1);
  OSRestoreInterrupts(uVar2);
  iVar1 = dacp$245 * 4;
  dacp$245 = dacp$245 + 1;
  last_rsp_madep = *(undefined4 *)(dac + iVar1);
  if (dacp$245 == 3) {
    dacp$245 = 0;
  }
  vframe_work_running = 0;
  return;
}

void Jac_UpdateDAC(void)
{
  if (use_rsp_madep == 0) {
    use_rsp_madep = last_rsp_madep;
    last_rsp_madep = 0;
  }
  if (use_rsp_madep == 0) {
    UNIVERSAL_DACCOUNTER = UNIVERSAL_DACCOUNTER + 1;
  }
  else {
    AIInitDMA(use_rsp_madep,uRam00000000 << 1);
    use_rsp_madep = 0;
  }
  if ((last_rsp_madep == 0) && (vframe_work_running == 0)) {
    Jac_VframeWork();
  }
  StreamMain__Fv();
  if (DAC_CALLBACK_FUNC != (code *)0x0) {
    (*DAC_CALLBACK_FUNC)(last_rsp_madep,uRam00000000 >> 1);
  }
  return;
}

void Jac_RegisterDacCallback(undefined4 param_1)
{
  DAC_CALLBACK_FUNC = param_1;
  return;
}

void Jac_SetOutputMode(undefined4 param_1)
{
  uRam00000000 = param_1;
  return;
}

undefined4 Jac_GetOutputMode(void)
{
  return uRam00000000;
}

void Jac_SetMixerLevel(undefined8 param_1,undefined8 param_2)
{
  Channel_SetMixerLevel__Ff();
  DsetMixerLevel__Ff(param_2);
  return;
}

