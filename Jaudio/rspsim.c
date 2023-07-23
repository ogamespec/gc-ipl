void RspStart2__FPUlll(int param_1,int param_2,int param_3)
{
  if (param_3 == 0) {
    taskp$31 = param_1;
    alltasks$32 = param_2;
  }
  if (0 < alltasks$32) {
    consumes$33 = RspStart__FPUll(taskp$31);
    alltasks$32 = alltasks$32 - consumes$33;
    taskp$31 = taskp$31 + consumes$33 * 8;
  }
  return;
}

int RspStart__FPUll(uint *param_1,int param_2)
{
  short *psVar1;
  byte bVar2;
  short sVar3;
  short sVar4;
  short sVar5;
  short sVar6;
  short sVar7;
  short sVar8;
  short sVar9;
  short sVar10;
  short sVar11;
  short sVar12;
  short sVar13;
  short sVar14;
  short sVar15;
  short sVar16;
  undefined2 uVar17;
  uint uVar18;
  short sVar21;
  short sVar22;
  short sVar23;
  int iVar19;
  int iVar20;
  undefined2 *puVar24;
  int iVar25;
  short *psVar26;
  undefined2 *puVar27;
  int iVar28;
  byte *pbVar29;
  int iVar30;
  uint unaff_r14;
  uint unaff_r15;
  uint unaff_r16;
  uint unaff_r17;
  uint unaff_r18;
  undefined2 *unaff_r19;
  int iVar31;
  uint unaff_r25;
  uint uVar32;
  uint uVar33;
  short *psVar34;
  uint uVar35;
  short *psVar36;
  int iVar37;
  short asStack_ac [8];
  short local_9c;
  int local_68;
  ushort local_64;
  short local_62;
  short local_60;
  short local_5e;
  undefined2 *local_5c;
  pointer __((offset(0x9f0))) *local_58;
  short *local_54;
  undefined1 *local_50;
  
  if (init$44 == '\0') {
    init$43 = 1;
    init$44 = '\x01';
  }
  if (init$43 != 0) {
    init$43 = 0;
  }
  local_50 = FINALR_STATE_BUF;
  local_54 = asStack_ac + 4;
  local_58 = &@286;
  local_68 = param_2;
  for (iVar31 = 0; iVar31 < local_68; iVar31 = iVar31 + 1) {
    uVar18 = *param_1;
    puVar24 = (undefined2 *)param_1[1];
    param_1 = param_1 + 2;
    if (uVar18 >> 0x18 < 0x1a) {
      switch(local_58[uVar18 >> 0x18]) {
      case (pointer __((offset(0x9f0))))0x10124:
        unaff_r14 = uVar18 & 0xffff;
        DCTouchRange(puVar24,uVar18 >> 0xc & 0xff0);
        unaff_r19 = puVar24;
        break;
      case (pointer __((offset(0x9f0))))0x10138:
        if ((uVar18 >> 0x10 & 1) == 0) {
          if ((uVar18 >> 0x10 & 2) == 0) {
            Jac_bcopy__FPvPvl(puVar24,DMEM + (unaff_r25 & 0xffff),0x20);
          }
          else {
            Jac_bcopy__FPvPvl(local_5c,DMEM + (unaff_r25 & 0xffff),0x20);
          }
        }
        else {
          Jac_bzero__FPvl(DMEM + (unaff_r25 & 0xffff),0x20);
        }
        uVar35 = unaff_r17 + 0x1f;
        uVar32 = unaff_r25 + 0x20 & 0xffff;
        psVar26 = (short *)(DMEM + uVar32);
        sVar22 = *(short *)(uVar32 + 0x10f5e);
        iVar19 = (int)*(short *)(uVar32 + 0x10f5c);
        pbVar29 = (byte *)((int)unaff_r19 + (unaff_r18 - unaff_r14));
        for (iVar20 = 0;
            iVar20 < (int)(((int)uVar35 >> 5) + (uint)((int)uVar35 < 0 && (uVar35 & 0x1f) != 0) &
                          0xffff); iVar20 = iVar20 + 1) {
          bVar2 = *pbVar29;
          pbVar29 = pbVar29 + 1;
          iVar30 = (int)(uint)bVar2 >> 4;
          iVar25 = (bVar2 & 0xf) * 0x20;
          iVar28 = (int)*(short *)(ADPCM_BOOKBUF + iVar25);
          iVar25 = (int)*(short *)(ADPCM_BOOKBUF + iVar25 + 0x10);
          if ((uVar18 >> 0x10 & 4) == 0) {
            iVar37 = 8;
            do {
              bVar2 = *pbVar29;
              pbVar29 = pbVar29 + 1;
              sVar21 = *(short *)(AD4 + (bVar2 & 0xf) * 2);
              sVar23 = (short)((int)*(short *)(AD4 + (bVar2 >> 3 & 0x1e)) << iVar30) +
                       (short)(sVar22 * iVar25 + (short)iVar19 * iVar28 >> 0xb);
              iVar19 = (int)sVar23;
              *psVar26 = sVar23;
              sVar22 = (short)((int)sVar21 << iVar30) +
                       (short)(iVar25 * iVar19 + sVar22 * iVar28 >> 0xb);
              psVar26[1] = sVar22;
              psVar26 = psVar26 + 2;
              iVar37 = iVar37 + -1;
            } while (iVar37 != 0);
          }
          else {
            iVar37 = 4;
            do {
              bVar2 = *pbVar29;
              pbVar29 = pbVar29 + 1;
              sVar21 = (short)((int)*(short *)((int)&AD2 + (bVar2 >> 5 & 6)) << iVar30) +
                       (short)(sVar22 * iVar25 + (short)iVar19 * iVar28 >> 0xb);
              *psVar26 = sVar21;
              sVar22 = (short)((int)*(short *)((int)&AD2 + (bVar2 >> 3 & 6)) << iVar30) +
                       (short)(sVar21 * iVar25 + sVar22 * iVar28 >> 0xb);
              psVar26[1] = sVar22;
              sVar21 = (short)((int)*(short *)((int)&AD2 + (bVar2 >> 1 & 6)) << iVar30) +
                       (short)(sVar22 * iVar25 + sVar21 * iVar28 >> 0xb);
              iVar19 = (int)sVar21;
              psVar26[2] = sVar21;
              sVar22 = (short)((int)*(short *)((int)&AD2 + (bVar2 & 3) * 2) << iVar30) +
                       (short)(iVar25 * iVar19 + sVar22 * iVar28 >> 0xb);
              psVar26[3] = sVar22;
              psVar26 = psVar26 + 4;
              iVar37 = iVar37 + -1;
            } while (iVar37 != 0);
          }
        }
        Jac_bcopy__FPvPvl(psVar26 + -0x10,puVar24,0x20);
        break;
      case (pointer __((offset(0x9f0))))0x10354:
        Jac_bzero__FPvl(DMEM + (uVar18 & 0xffff),(uint)puVar24 & 0xffff);
        break;
      case (pointer __((offset(0x9f0))))0x10368:
        if ((uVar18 >> 0x10 & 1) == 0) {
          Jac_bcopy__FPvPvl(puVar24,asStack_ac + 4,0x10);
          uVar32 = (int)local_9c & 0x7fff;
        }
        else {
          Jac_bzero__FPvl(asStack_ac + 4,0x10);
          uVar32 = 0;
        }
        psVar26 = (short *)(DMEM + unaff_r18);
        puVar27 = (undefined2 *)(DMEM + (unaff_r25 & 0xffff));
        iVar19 = 4;
        for (iVar20 = 0;
            iVar20 < (int)(((int)unaff_r17 >> 1) +
                           (uint)((int)unaff_r17 < 0 && (unaff_r17 & 1) != 0) & 0xffff) >> 1;
            iVar20 = iVar20 + 1) {
          uVar35 = uVar32 + (uVar18 & 0xffff);
          iVar25 = (uVar32 >> 9) * 8;
          sVar22 = *(short *)(RES_FILTER + iVar25 + 2);
          sVar21 = asStack_ac[iVar19 + 1];
          uVar32 = uVar35 >> 0xf;
          sVar23 = *(short *)(RES_FILTER + iVar25 + 4);
          sVar3 = asStack_ac[iVar19 + 2];
          sVar4 = *(short *)(RES_FILTER + iVar25);
          sVar5 = asStack_ac[iVar19];
          sVar6 = *(short *)(RES_FILTER + iVar25 + 6);
          sVar7 = asStack_ac[iVar19 + 3];
          iVar25 = iVar19;
          if (0x7fff < uVar35) {
            do {
              sVar8 = *psVar26;
              iVar19 = iVar25 + 1;
              psVar26 = psVar26 + 1;
              asStack_ac[iVar25 + 4] = sVar8;
              uVar35 = uVar35 - 0x8000;
              asStack_ac[iVar25] = asStack_ac[iVar25 + 4];
              if (iVar19 == 8) {
                iVar19 = 4;
              }
              uVar32 = uVar32 - 1;
              iVar25 = iVar19;
            } while (uVar32 != 0);
          }
          uVar32 = uVar35 + (uVar18 & 0xffff);
          iVar25 = (uVar35 >> 9) * 8;
          sVar8 = *(short *)(RES_FILTER + iVar25 + 2);
          sVar9 = asStack_ac[iVar19 + 1];
          uVar35 = uVar32 >> 0xf;
          sVar10 = *(short *)(RES_FILTER + iVar25 + 4);
          sVar11 = asStack_ac[iVar19 + 2];
          sVar12 = *(short *)(RES_FILTER + iVar25);
          sVar13 = asStack_ac[iVar19];
          sVar14 = *(short *)(RES_FILTER + iVar25 + 6);
          sVar15 = asStack_ac[iVar19 + 3];
          iVar25 = iVar19;
          if (0x7fff < uVar32) {
            do {
              sVar16 = *psVar26;
              iVar19 = iVar25 + 1;
              psVar26 = psVar26 + 1;
              asStack_ac[iVar25 + 4] = sVar16;
              uVar32 = uVar32 - 0x8000;
              asStack_ac[iVar25] = asStack_ac[iVar25 + 4];
              if (iVar19 == 8) {
                iVar19 = 4;
              }
              uVar35 = uVar35 - 1;
              iVar25 = iVar19;
            } while (uVar35 != 0);
          }
          iVar25 = (int)sVar6 * (int)sVar7 +
                   (int)sVar23 * (int)sVar3 + (int)sVar22 * (int)sVar21 + (int)sVar4 * (int)sVar5 >>
                   0xf;
          if (0x7fff < iVar25) {
            iVar25 = 0x7fff;
          }
          if (iVar25 < -0x8000) {
            iVar25 = -0x8000;
          }
          iVar28 = (int)sVar14 * (int)sVar15 +
                   (int)sVar10 * (int)sVar11 + (int)sVar8 * (int)sVar9 + (int)sVar12 * (int)sVar13
                   >> 0xf;
          *puVar27 = (short)iVar25;
          if (0x7fff < iVar28) {
            iVar28 = 0x7fff;
          }
          if (iVar28 < -0x8000) {
            iVar28 = -0x8000;
          }
          puVar27[1] = (short)iVar28;
          puVar27 = puVar27 + 2;
        }
        local_54[iVar19] = (ushort)uVar32 & 0x7fff;
        Jac_bcopy__FPvPvl(local_54 + iVar19 + -4,puVar24,0x10);
        break;
      case (pointer __((offset(0x9f0))))0x1059c:
        unaff_r25 = (uint)puVar24 >> 0x10;
        unaff_r18 = uVar18 & 0xffff;
        unaff_r17 = (uint)puVar24 & 0xffff;
        break;
      case (pointer __((offset(0x9f0))))0x105b0:
        uVar32 = (uint)puVar24 >> 0x10;
        uVar35 = uVar18 & 0xffff;
        for (iVar19 = 0; iVar19 < (int)(uVar18 >> 0x10 & 0xff); iVar19 = iVar19 + 1) {
          Jac_bcopy__FPvPvl(DMEM + (uVar35 & 0xffff),DMEM + (uVar32 & 0xffff),0x80);
          uVar35 = uVar35 + 0x80;
          uVar32 = uVar32 + 0x80;
        }
        break;
      case (pointer __((offset(0x9f0))))0x105f4:
        Jac_bcopy__FPvPvl(DMEM + (uVar18 & 0xffff),DMEM + ((uint)puVar24 >> 0x10),
                          (uint)puVar24 & 0xffff);
        break;
      case (pointer __((offset(0x9f0))))0x10610:
        ADPCM_BOOKBUF_SIZE = uVar18 & 0xffff;
        iVar19 = 0;
        uVar18 = ADPCM_BOOKBUF_SIZE + 0xf >> 4;
        uVar32 = ADPCM_BOOKBUF_SIZE;
        while (uVar32 != 0) {
          iVar20 = iVar19 >> 1;
          uVar17 = *puVar24;
          iVar19 = iVar19 + 0x10;
          puVar24 = puVar24 + 8;
          *(undefined2 *)(ADPCM_BOOKBUF + iVar20 * 2) = uVar17;
          uVar18 = uVar18 - 1;
          uVar32 = uVar18;
        }
        break;
      case (pointer __((offset(0x9f0))))0x10658:
        psVar26 = (short *)(DMEM + ((uint)puVar24 >> 0x10));
        psVar34 = (short *)(DMEM + ((uint)puVar24 & 0xffff));
        for (iVar19 = (int)(uVar18 >> 0xc & 0xff0) >> 1; iVar19 != 0; iVar19 = iVar19 + -1) {
          sVar22 = *psVar26;
          psVar26 = psVar26 + 1;
          iVar20 = (int)*psVar34 + ((int)sVar22 * (int)(short)uVar18 >> 0xf);
          if (0x7fff < iVar20) {
            iVar20 = 0x7fff;
          }
          if (iVar20 < -0x8000) {
            iVar20 = -0x8000;
          }
          *psVar34 = (short)iVar20;
          psVar34 = psVar34 + 1;
        }
        break;
      case (pointer __((offset(0x9f0))))0x106cc:
        if (init$138 == '\0') {
          flag$137 = 1;
          init$138 = '\x01';
        }
        if (flag$137 == 1) {
          finalr_state$141 = local_50;
        }
        Jac_Resample16__FPsPsPsllPsPUsl
                  (DMEM + ((uint)puVar24 & 0xffff),DMEM + ((uint)puVar24 >> 0x10),
                   DMEM + (uVar18 & 0xffff),(int)(uVar18 >> 0xc & 0xff0) >> 1,uRam00000000 >> 2,
                   finalr_state$141,&finalr_phase$140,flag$137);
        flag$137 = 0;
        break;
      case (pointer __((offset(0x9f0))))0x10748:
        local_5c = puVar24;
        break;
      case (pointer __((offset(0x9f0))))0x10750:
        uVar32 = (uint)puVar24 >> 0x10;
        uVar35 = (uint)puVar24 & 0xffff;
        uVar33 = uVar18 & 0xffff;
        for (iVar19 = 0; iVar19 < (int)(uVar18 >> 0x10 & 0xff); iVar19 = iVar19 + 1) {
          Jac_bcopy__FPvPvl(DMEM + (uVar33 & 0xffff),DMEM + (uVar32 & 0xffff),uVar35);
          uVar33 = uVar33 + uVar35;
          uVar32 = uVar32 + uVar35;
        }
        break;
      case (pointer __((offset(0x9f0))))0x10798:
        puVar27 = (undefined2 *)(DMEM + ((uint)puVar24 >> 0x10));
        puVar24 = (undefined2 *)(DMEM + ((uint)puVar24 & 0xffff));
        for (uVar18 = uVar18 & 0xffff; uVar18 != 0; uVar18 = uVar18 - 1) {
          uVar17 = *puVar27;
          puVar27 = puVar27 + 2;
          *puVar24 = uVar17;
          puVar24 = puVar24 + 1;
        }
        break;
      case (pointer __((offset(0x9f0))))0x107cc:
        Jac_bcopy__FPvPvl(puVar24,DMEM + (uVar18 & 0xffff),uVar18 >> 0xc & 0xff0);
        break;
      case (pointer __((offset(0x9f0))))0x107e0:
        Jac_bcopy__FPvPvl(DMEM + (uVar18 & 0xffff),puVar24,uVar18 >> 0xc & 0xff0);
        break;
      case (pointer __((offset(0x9f0))))0x107f8:
        local_64 = (ushort)(uVar18 >> 8) & 0xff00;
        local_60 = (short)((uint)puVar24 >> 0x10);
        local_62 = (short)puVar24;
        local_5e = (short)uVar18;
        break;
      case (pointer __((offset(0x9f0))))0x10820:
        unaff_r16 = (uint)puVar24 >> 0x10;
        unaff_r15 = (uint)puVar24 & 0xffff;
        break;
      case (pointer __((offset(0x9f0))))0x10830:
        psVar26 = (short *)(DMEM + ((uint)puVar24 >> 0x14 & 0xff0));
        uVar32 = uVar18 >> 7 & 0x1fe;
        psVar34 = (short *)(DMEM + (uVar18 >> 0xc & 0xff0));
        psVar36 = (short *)(DMEM + ((uint)puVar24 >> 0xc & 0xff0));
        DCTouchRange(psVar26,uVar32);
        DCTouchRange(psVar36,uVar32);
        uVar32 = 0;
        for (iVar19 = (int)(uVar18 >> 8 & 0xff) >> 1; iVar19 != 0; iVar19 = iVar19 + -1) {
          sVar22 = *psVar34;
          psVar1 = psVar34 + 1;
          psVar34 = psVar34 + 2;
          iVar30 = (int)((int)sVar22 * (unaff_r16 & 0xffff)) >> 0x10;
          iVar20 = (int)((int)sVar22 * (unaff_r15 & 0xffff)) >> 0x10;
          iVar25 = (int)((int)*psVar1 * (unaff_r16 & 0xffff)) >> 0x10;
          iVar28 = (int)((int)*psVar1 * (unaff_r15 & 0xffff)) >> 0x10;
          if ((uVar18 & 2) != 0) {
            iVar30 = -iVar30;
            iVar25 = -iVar25;
          }
          if ((uVar18 & 1) != 0) {
            iVar20 = -iVar20;
            iVar28 = -iVar28;
          }
          iVar30 = *psVar26 + iVar30;
          iVar25 = psVar26[1] + iVar25;
          iVar20 = *psVar36 + iVar20;
          iVar28 = psVar36[1] + iVar28;
          if (0x7fff < iVar30) {
            iVar30 = 0x7fff;
          }
          if (iVar30 < -0x8000) {
            iVar30 = -0x8000;
          }
          if (0x7fff < iVar25) {
            iVar25 = 0x7fff;
          }
          if (iVar25 < -0x8000) {
            iVar25 = -0x8000;
          }
          if (0x7fff < iVar20) {
            iVar20 = 0x7fff;
          }
          if (iVar20 < -0x8000) {
            iVar20 = -0x8000;
          }
          if (0x7fff < iVar28) {
            iVar28 = 0x7fff;
          }
          if (iVar28 < -0x8000) {
            iVar28 = -0x8000;
          }
          *psVar26 = (short)iVar30;
          psVar26[1] = (short)iVar25;
          psVar26 = psVar26 + 2;
          *psVar36 = (short)iVar20;
          psVar36[1] = (short)iVar28;
          psVar36 = psVar36 + 2;
          if ((uVar32 & 3) == 3) {
            unaff_r16 = unaff_r16 + (int)local_60;
            unaff_r15 = unaff_r15 + (int)local_62;
            local_64 = local_64 + local_5e;
          }
          uVar32 = uVar32 + 1;
        }
        break;
      case (pointer __((offset(0x9f0))))0x109b8:
        if ((uVar18 >> 0x10 & 1) == 0) {
          if ((uVar18 >> 0x10 & 2) == 0) {
            Jac_bcopy__FPvPvl(puVar24,DMEM + unaff_r25,0x20);
          }
          else {
            Jac_bcopy__FPvPvl(local_5c,DMEM + unaff_r25,0x20);
          }
        }
        else {
          Jac_bzero__FPvl(DMEM + unaff_r25,0x20);
        }
        psVar26 = (short *)(DMEM + (unaff_r25 + 0x20 & 0xffff));
        pbVar29 = (byte *)((int)unaff_r19 + (unaff_r18 - unaff_r14));
        for (uVar18 = ((int)unaff_r17 >> 1) + (uint)((int)unaff_r17 < 0 && (unaff_r17 & 1) != 0) &
                      0xffff; uVar18 != 0; uVar18 = uVar18 - 1) {
          bVar2 = *pbVar29;
          pbVar29 = pbVar29 + 1;
          *psVar26 = (ushort)bVar2 << 8;
          psVar26 = psVar26 + 1;
        }
        Jac_bcopy__FPvPvl((int)&PTR_caseD_10124_00010f40 + (unaff_r25 + 0x20 & 0xffff),puVar24,0x20)
        ;
        break;
      case (pointer __((offset(0x9f0))))0x10a68:
        return iVar31 + 1;
      }
    }
  }
  return local_68;
}

void Jac_Resample16__FPsPsPsllPsPUsl
               (undefined2 *param_1,undefined2 *param_2,undefined2 *param_3,uint param_4,int param_5
               ,int param_6,ushort *param_7,uint param_8)
{
  undefined2 uVar1;
  uint uVar2;
  int iVar3;
  int iVar4;
  undefined2 *puVar5;
  undefined2 *puVar6;
  uint uVar7;
  int iVar8;
  int iVar9;
  int iVar10;
  
  iVar10 = (int)(param_4 << 0x10) / param_5;
  if ((param_8 & 1) == 0) {
    uVar2 = (uint)*param_7;
  }
  else {
    Jac_bzero__FPvl(param_6,0x20);
    uVar2 = 0;
  }
  while( true ) {
    for (; uVar7 = uVar2 + iVar10 * param_5 >> 0x10, uVar7 < param_4; iVar10 = iVar10 + 1) {
    }
    if (uVar7 <= param_4 + 1) break;
    iVar10 = iVar10 + -1;
  }
  iVar3 = 4;
  if (0 < param_5) {
    do {
      uVar7 = uVar2 >> 7 & 0x1fffff8;
      iVar9 = param_6 + iVar3 * 2;
      iVar8 = (int)*(short *)(RES_FILTER + uVar7 + 6) * (int)*(short *)(iVar9 + -2) +
              (int)*(short *)(RES_FILTER + uVar7 + 4) * (int)*(short *)(iVar9 + -4) +
              (int)*(short *)(RES_FILTER + uVar7 + 2) * (int)*(short *)(iVar9 + -6) +
              (int)*(short *)(RES_FILTER + uVar7) * (int)*(short *)(iVar9 + -8) >> 0xf;
      iVar9 = (int)*(short *)(RES_FILTER + uVar7 + 6) * (int)*(short *)(iVar9 + 0xe) +
              (int)*(short *)(RES_FILTER + uVar7 + 4) * (int)*(short *)(iVar9 + 0xc) +
              (int)*(short *)(RES_FILTER + uVar7 + 2) * (int)*(short *)(iVar9 + 10) +
              (int)*(short *)(RES_FILTER + uVar7) * (int)*(short *)(iVar9 + 8) >> 0xf;
      if (0x7fff < iVar8) {
        iVar8 = 0x7fff;
      }
      if (iVar8 < -0x8000) {
        iVar8 = -0x8000;
      }
      if (0x7fff < iVar9) {
        iVar9 = 0x7fff;
      }
      if (iVar9 < -0x8000) {
        iVar9 = -0x8000;
      }
      *param_3 = (short)iVar8;
      uVar2 = uVar2 + iVar10;
      param_3[1] = (short)iVar9;
      param_3 = param_3 + 2;
      while (0xffff < uVar2) {
        puVar5 = (undefined2 *)(param_6 + iVar3 * 2);
        iVar3 = iVar3 + 1;
        *puVar5 = *param_1;
        uVar2 = uVar2 - 0x10000;
        param_1 = param_1 + 1;
        puVar5[-4] = *puVar5;
        uVar1 = *param_2;
        param_2 = param_2 + 1;
        puVar5[8] = uVar1;
        puVar5[4] = puVar5[8];
        if (iVar3 == 8) {
          iVar3 = 4;
        }
      }
      param_5 = param_5 + -1;
    } while (param_5 != 0);
  }
  *param_7 = (ushort)uVar2;
  iVar9 = 0;
  iVar10 = 0;
  iVar8 = 4;
  do {
    iVar4 = iVar3 + iVar9;
    puVar6 = (undefined2 *)(param_6 + iVar10);
    iVar9 = iVar9 + 1;
    iVar10 = iVar10 + 2;
    puVar5 = (undefined2 *)(param_6 + (iVar4 + -4) * 2);
    *puVar6 = *puVar5;
    puVar6[8] = puVar5[8];
    iVar8 = iVar8 + -1;
  } while (iVar8 != 0);
  return;
}

