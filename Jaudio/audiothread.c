
void DspSyncCountClear(undefined4 param_1)
{
  intcount = param_1;
  return;
}

undefined4 DspSyncCountCheck(void)
{
  return intcount;
}

double Jac_GetDacRate(void)
{
  return (double)fRam00000000;
}

void DspSync__Fv(void)
{
  int iVar1;
  
  if (audioproc_mq_init == 0) {
    DSPReleaseHalt__Fv();
  }
  else {
    iVar1 = OSSendMessage(audioproc_mq,1,0);
    if (iVar1 == 0) {
      OSReport(...rodata.0);
    }
  }
  return;
}

void StopAudioThread(void)
{
  int iVar1;
  
  if ((audioproc_mq_init != 0) && (iVar1 = OSSendMessage(audioproc_mq,3,0), iVar1 == 0)) {
    OSCancelThread(jac_audioThread);
  }
  return;
}

void AudioSync__Fv(void)
{
  int iVar1;
  
  if (init$71 == '\0') {
    first$70 = 1;
    init$71 = '\x01';
  }
  if (first$70 == 0) {
    Probe_Finish(4);
  }
  first$70 = 0;
  Probe_Start(4,"UPDATE-DAC");
  if ((audioproc_mq_init != 0) && (iVar1 = OSSendMessage(audioproc_mq,0,0), iVar1 == 0)) {
    OSReport("Miss Send AudioSync\n");
  }
  return;
}

void NeosSync__Fv(void)
{
  if (audioproc_mq_init != 0) {
    OSSendMessage(audioproc_mq,2,1);
  }
  return;
}

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
void __DspSync__FsP9OSContext(undefined4 param_1,undefined4 param_2)
{
  undefined auStack_2d0 [716];
  
  _DAT_cc00500a = _DAT_cc00500a & 0xffd7 | 0x80;
  OSClearContext(auStack_2d0);
  OSSetCurrentContext(auStack_2d0);
  DspSync__Fv();
  OSClearContext(auStack_2d0);
  OSSetCurrentContext(param_2);
  return;
}

void __DspReg__Fv(void)
{
  undefined4 uVar1;
  
  uVar1 = OSDisableInterrupts();
  __OSSetInterruptHandler(7,__DspSync__FsP9OSContext);
  OSRestoreInterrupts(uVar1);
  return;
}

void audioproc__FPv(void)
{
  int local_10 [2];
  
  OSReport(@104);
  OSInitFastCast();
  OSInitMessageQueue(audioproc_mq,msgbuf,0x10);
  audioproc_mq_init = 1;
  Jac_Init();
  Jac_InitSinTable__Fv();
  ResetPlayerCallback();
  DspbufProcess__F13DSPBUF_EVENTS(0);
  CpubufProcess__F13DSPBUF_EVENTS(0);
  DspBoot__Fv();
  DSP_InitBuffer__Fv();
  __DspReg__Fv();
  AISetDSPSampleRate(uRam00000000);
  AIRegisterDMACallback(AudioSync__Fv);
  AIStartDMA();
  OSReport(@105);
  OSReport(@106);
  while( true ) {
    do {
      while( true ) {
        while( true ) {
          while( true ) {
            OSReceiveMessage(audioproc_mq,local_10,1);
            if (local_10[0] != 2) break;
            CpuFrameEnd__Fv();
          }
          if (local_10[0] < 2) break;
          if (local_10[0] < 4) {
            OSReport(@109);
            OSExitThread(0);
            OSReport(@110);
          }
        }
        if (local_10[0] != 0) break;
        Jac_UpdateDAC();
      }
    } while (local_10[0] < 0);
    if (intcount == 0) break;
    intcount = intcount + -1;
    if (intcount == 0) {
      Probe_Finish(7);
      DspFrameEnd__Fv();
    }
    else {
      Probe_Start(2,@108);
      UpdateDSP__Fv();
      Probe_Finish(2);
    }
  }
  OSReport(@107);
  return;
}

undefined4 OSInitFastCast(void)
{
  return 0x70007;
}

void SetAudioThreadPriority(uint param_1,uint param_2,uint param_3)
{
  priority_set = 1;
  pri = param_1 & 0xff;
  pri2 = param_2 & 0xff;
  pri3 = param_3 & 0xff;
  return;
}

void StartAudioThread(undefined4 param_1,undefined4 param_2,undefined4 param_3,uint param_4)
{
  int iVar1;
  
  if (priority_set == 0) {
    OSGetCurrentThread();
    iVar1 = OSGetThreadPriority();
    pri = iVar1 + -3;
    pri3 = iVar1 + -2;
    pri2 = iVar1 + -1;
    OSReport(@126);
  }
  else {
    OSReport(@127);
  }
  OSReport(@128);
  Jac_HeapSetup(param_1,param_2);
  Jac_SetAudioARAMSize__FUl(param_3);
  Jac_InitARAM__FUl(param_4 & 4);
  OSReport(@129,pri);
  if ((param_4 & 2) != 0) {
    OSCreateThread(jac_audioThread,audioproc__FPv,0,neosStack,0x1000,pri,0);
    OSResumeThread(jac_audioThread);
    OSReport(@130);
  }
  if ((param_4 & 1) == 0) {
    OSReport(@132);
  }
  else {
    jac_dvdproc_init__Fv();
    OSCreateThread(jac_dvdThread,&jac_dvdproc__FPv,0,audioproc_mq,0x1000,pri3,0);
    OSResumeThread(jac_dvdThread);
    OSReport(@131);
  }
  if ((param_4 & 4) != 0) {
    OSCreateThread(jac_neosThread,&neosproc__FPv,0,dvdStack,0x1000,pri2,0);
    OSResumeThread(jac_neosThread);
    OSReport(@133);
  }
  return;
}

