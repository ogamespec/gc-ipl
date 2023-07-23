undefined4 Bank_InstChange__FP5Bank_Ul(int param_1,uint param_2)
{
  undefined4 uVar1;
  
  if (0x7f < param_2) {
    OSReport(@46,param_2);
  }
  if (param_1 == 0) {
    uVar1 = 0;
  }
  else {
    uVar1 = *(undefined4 *)(param_1 + param_2 * 4 + 4);
  }
  return uVar1;
}

undefined4 Bank_VoiceChange__FP5Bank_Ul(int param_1,uint param_2)
{
  undefined4 uVar1;
  
  if ((param_2 < 0x80) || (0xe3 < param_2)) {
    OSReport("Bad VOICE Program Change %d \n",param_2);
  }
  if (param_1 == 0) {
    uVar1 = 0;
  }
  else {
    uVar1 = *(undefined4 *)(param_1 + param_2 * 4 + 4);
  }
  return uVar1;
}

undefined4 Bank_PercChange__FP5Bank_Ul(int param_1,uint param_2)
{
  undefined4 uVar1;
  
  if (param_2 < 0xe4) {
    OSReport("Bad PERC Program Change %d \n",param_2);
  }
  if (param_1 == 0) {
    uVar1 = 0;
  }
  else {
    uVar1 = *(undefined4 *)(param_1 + param_2 * 4 + 4);
  }
  return uVar1;
}

int Bank_GetInstKeymap__FP5Inst_Uc(int param_1,byte param_2)
{
  int iVar1;
  int iVar2;
  int iVar3;
  
  if (param_1 == 0) {
    iVar1 = 0;
  }
  else {
    iVar3 = 0;
    iVar2 = 0;
    for (iVar1 = *(int *)(param_1 + 0x28); iVar1 != 0; iVar1 = iVar1 + -1) {
      if (param_2 <= **(byte **)(param_1 + iVar2 + 0x2c)) {
        return iVar3;
      }
      iVar3 = iVar3 + 1;
      iVar2 = iVar2 + 4;
    }
    OSReport(&@71);
    iVar1 = -1;
  }
  return iVar1;
}

byte * Bank_GetInstVmap__FP5Inst_UcUc(int param_1,undefined4 param_2,byte param_3)
{
  int iVar1;
  byte *pbVar2;
  int iVar3;
  int iVar4;
  byte *unaff_r31;
  
  if (param_1 == 0) {
    pbVar2 = (byte *)0x0;
  }
  else {
    pbVar2 = (byte *)Bank_GetInstKeymap__FP5Inst_Uc(param_1);
    if (pbVar2 != (byte *)0xffffffff) {
      iVar4 = *(int *)(param_1 + (int)pbVar2 * 4 + 0x2c);
      iVar3 = 0;
      for (iVar1 = *(int *)(iVar4 + 4); iVar1 != 0; iVar1 = iVar1 + -1) {
        unaff_r31 = *(byte **)(iVar4 + iVar3 + 8);
        if (param_3 <= *unaff_r31) {
          return unaff_r31;
        }
        iVar3 = iVar3 + 4;
      }
      OSReport(&@87,param_3,*unaff_r31);
      pbVar2 = (byte *)0x0;
    }
  }
  return pbVar2;
}

byte * Bank_GetPercVmap__FP5Perc_UcUc(int param_1,uint param_2,byte param_3)
{
  int iVar1;
  byte *pbVar2;
  int iVar3;
  int iVar4;
  
  if ((param_1 != 0) && (iVar4 = *(int *)(param_1 + (param_2 & 0xff) * 4 + 0x88), iVar4 != 0)) {
    iVar3 = 0;
    for (iVar1 = *(int *)(iVar4 + 0x10); iVar1 != 0; iVar1 = iVar1 + -1) {
      pbVar2 = *(byte **)(iVar4 + iVar3 + 0x14);
      if (param_3 <= *pbVar2) {
        return pbVar2;
      }
      iVar3 = iVar3 + 4;
    }
    OSReport("Error: No V-Map Error\n");
  }
  return (byte *)0x0;
}

undefined4 Bank_GetVoiceMap__FP6Voice_Us(int param_1,uint param_2)
{
  return *(undefined4 *)(param_1 + (param_2 & 0xffff) * 4 + 0xc);
}

double Bank_SenseToOfs__FP6Sense_Uc(int param_1,uint param_2)
{
  uint uVar1;
  double dVar2;
  
  if (param_1 == 0) {
    dVar2 = (double)@119;
  }
  else {
    uVar1 = (uint)*(byte *)(param_1 + 2);
    if ((uVar1 == 0x7f) || (uVar1 == 0)) {
      dVar2 = (double)(*(float *)(param_1 + 4) +
                      ((float)((double)CONCAT44(0x43300000,param_2 & 0xff) - @122) *
                      (*(float *)(param_1 + 8) - *(float *)(param_1 + 4))) / @120);
    }
    else {
      param_2 = param_2 & 0xff;
      if (param_2 < uVar1) {
        dVar2 = (double)((@119 - *(float *)(param_1 + 4)) *
                         ((float)((double)CONCAT44(0x43300000,param_2) - @122) /
                         (float)((double)CONCAT44(0x43300000,uVar1) - @122)) +
                        *(float *)(param_1 + 4));
      }
      else {
        dVar2 = (double)((*(float *)(param_1 + 8) - @119) *
                         ((float)((double)CONCAT44(0x43300000,param_2 - uVar1 ^ 0x80000000) - @124)
                         / (float)((double)CONCAT44(0x43300000,0x7f - uVar1 ^ 0x80000000) - @124)) +
                        @119);
      }
    }
  }
  return dVar2;
}

double Bank_RandToOfs__FP5Rand_(int param_1)
{
  float fVar1;
  double dVar2;
  
  fVar1 = @119;
  if (param_1 != 0) {
    dVar2 = (double)GetRandom_sf32();
    fVar1 = (float)(dVar2 * (double)*(float *)(param_1 + 8)) + *(float *)(param_1 + 4);
  }
  return (double)fVar1;
}

double Bank_OscToOfs__FP4Osc_P7Oscbuf_(int param_1,char *param_2)
{
  char cVar1;
  byte bVar2;
  float fVar3;
  short sVar4;
  ushort uVar5;
  short sVar6;
  double dVar7;
  float fVar8;
  float fVar9;
  float fVar10;
  short *psVar11;
  undefined1 *puVar12;
  double dVar13;
  
  if (param_1 == 0) {
    dVar13 = (double)@119;
    *(float *)(param_2 + 8) = @119;
  }
  else {
    if (*param_2 == '\x04') {
      if (*(int *)(param_1 + 8) != *(int *)(param_1 + 0xc)) {
        *(undefined2 *)(param_2 + 2) = 0;
        *(float *)(param_2 + 4) = @193;
        *(undefined4 *)(param_2 + 0xc) = *(undefined4 *)(param_2 + 8);
      }
      if ((*(int *)(param_1 + 0xc) == 0) && (*(short *)(param_2 + 0x14) == 0)) {
        *(undefined2 *)(param_2 + 0x14) = 0x10;
      }
      if (*(short *)(param_2 + 0x14) == 0) {
        *param_2 = '\x05';
      }
      else {
        *param_2 = '\b';
        param_2[1] = (byte)((ushort)*(undefined2 *)(param_2 + 0x14) >> 0xe);
        *(float *)(param_2 + 4) =
             (float)((double)CONCAT44(0x43300000,*(ushort *)(param_2 + 0x14) & 0x3fff ^ 0x80000000)
                    - @124) * ((fRam00000000 / @194) / @195);
        if (*(float *)(param_2 + 4) < @119) {
          *(float *)(param_2 + 4) = @119;
        }
        *(float *)(param_2 + 0xc) = @193;
        *(float *)(param_2 + 0x10) =
             (*(float *)(param_2 + 0xc) - *(float *)(param_2 + 8)) / *(float *)(param_2 + 4);
      }
    }
    if (*param_2 == '\x06') {
      *(undefined2 *)(param_2 + 2) = 0;
      *(float *)(param_2 + 4) = @193;
      *(undefined4 *)(param_2 + 0xc) = *(undefined4 *)(param_2 + 8);
      *param_2 = '\a';
    }
    cVar1 = *param_2;
    if (cVar1 == '\x05') {
      puVar12 = *(undefined1 **)(param_1 + 0xc);
    }
    else if (cVar1 == '\a') {
      puVar12 = FORCE_RELEASE_TABLE;
    }
    else {
      puVar12 = *(undefined1 **)(param_1 + 8);
    }
    if ((puVar12 == (undefined1 *)0x0) && (cVar1 != '\b')) {
      dVar13 = (double)@119;
      *(float *)(param_2 + 8) = @119;
    }
    else if (cVar1 == '\0') {
      dVar13 = (double)@119;
    }
    else if (cVar1 == '\x03') {
      dVar13 = (double)(*(float *)(param_2 + 8) * *(float *)(param_1 + 0x10) +
                       *(float *)(param_1 + 0x14));
    }
    else {
      if (cVar1 == '\x01') {
        *param_2 = '\x02';
        *(undefined2 *)(param_2 + 2) = 0;
        fVar3 = @193;
        *(float *)(param_2 + 4) = @193;
        *(float *)(param_2 + 0xc) = fVar3;
        *(undefined2 *)(param_2 + 0x14) = 0;
        fVar3 = *(float *)(param_1 + 4);
      }
      else {
        fVar3 = *(float *)(param_1 + 4);
      }
      if (*param_2 == '\a') {
        fVar3 = @119;
      }
      *(float *)(param_2 + 4) = *(float *)(param_2 + 4) - fVar3;
      fVar10 = @196;
      fVar9 = @195;
      fVar8 = @194;
      fVar3 = @193;
      dVar7 = @124;
      dVar13 = @122;
      while (*(float *)(param_2 + 4) <= fVar3) {
        *(undefined4 *)(param_2 + 8) = *(undefined4 *)(param_2 + 0xc);
        if (*param_2 == '\b') {
          *param_2 = '\0';
          break;
        }
        psVar11 = (short *)(puVar12 + (uint)*(ushort *)(param_2 + 2) * 6);
        sVar4 = *psVar11;
        uVar5 = psVar11[1];
        sVar6 = psVar11[2];
        if (sVar4 == 0xd) {
          *(short *)(param_2 + 2) = sVar6;
        }
        else {
          if (sVar4 == 0xf) {
            *param_2 = '\0';
            break;
          }
          if (sVar4 == 0xe) {
            *param_2 = '\x03';
            return (double)(*(float *)(param_2 + 8) * *(float *)(param_1 + 0x10) +
                           *(float *)(param_1 + 0x14));
          }
          param_2[1] = (char)sVar4;
          if (uVar5 == 0) {
            *(float *)(param_2 + 0xc) =
                 (float)((double)CONCAT44(0x43300000,(int)sVar6 ^ 0x80000000) - dVar7) / fVar10;
            *(short *)(param_2 + 2) = *(short *)(param_2 + 2) + 1;
          }
          else {
            *(float *)(param_2 + 4) =
                 (float)((double)CONCAT44(0x43300000,(uint)uVar5) - dVar13) *
                 ((fRam00000000 / fVar8) / fVar9);
            *(float *)(param_2 + 0xc) =
                 (float)((double)CONCAT44(0x43300000,(int)sVar6 ^ 0x80000000) - dVar7) / fVar10;
            *(float *)(param_2 + 0x10) =
                 (*(float *)(param_2 + 0xc) - *(float *)(param_2 + 8)) / *(float *)(param_2 + 4);
            *(short *)(param_2 + 2) = *(short *)(param_2 + 2) + 1;
          }
        }
      }
      dVar13 = -(double)(*(float *)(param_2 + 0x10) * *(float *)(param_2 + 4) -
                        *(float *)(param_2 + 0xc));
      *(float *)(param_2 + 8) = (float)dVar13;
      bVar2 = param_2[1];
      if (bVar2 == 1) {
        if (dVar13 <= (double)@193) {
          dVar13 = (double)(float)(-dVar13 * dVar13);
        }
        else {
          dVar13 = (double)(float)(dVar13 * dVar13);
        }
      }
      else if ((bVar2 != 0) && (bVar2 < 3)) {
        if (dVar13 <= (double)@193) {
          dVar13 = (double)sqrtf2__Ff(-dVar13);
          dVar13 = -dVar13;
        }
        else {
          dVar13 = (double)sqrtf2__Ff();
        }
      }
      dVar13 = (double)(float)(dVar13 * (double)*(float *)(param_1 + 0x10) +
                              (double)*(float *)(param_1 + 0x14));
    }
  }
  return dVar13;
}

