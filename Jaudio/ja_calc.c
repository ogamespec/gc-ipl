void sqrtf2__Ff(void)
{
  sqrtf__3stdFf();
  return;
}

double sqrtf__3stdFf(double param_1)
{
  double dVar1;
  
  if ((double)@109 < param_1) {
    dVar1 = 1.0 / SQRT(param_1);
    dVar1 = @110 * dVar1 * -(param_1 * dVar1 * dVar1 - @111);
    dVar1 = @110 * dVar1 * -(param_1 * dVar1 * dVar1 - @111);
    param_1 = (double)(float)(param_1 * @110 * dVar1 * -(param_1 * dVar1 * dVar1 - @111));
  }
  return param_1;
}

double cosf2__Ff(double param_1)
{
  float fVar1;
  
  fVar1 = cosf((float)param_1);
  return (double)fVar1;
}

double atanf2__Fff(double param_1,double param_2)
{
  double dVar1;
  
  dVar1 = atan2(param_1,param_2);
  return (double)(float)dVar1;
}

double sinf2__Ff(double param_1)
{
  float fVar1;
  
  fVar1 = sinf((float)param_1);
  return (double)fVar1;
}


void Jac_InitSinTable__Fv(void)
{
  uint uVar1;
  int iVar2;
  double dVar3;
  double dVar4;
  double dVar5;
  float fVar6;
  
  _savefpr_29();
  dVar3 = (double)@121;
  dVar5 = (double)@122;
  uVar1 = 0;
  iVar2 = 0;
  dVar4 = @124;
  do {
    fVar6 = sinf((float)((double)(float)(dVar3 * (double)(float)((double)CONCAT44(0x43300000,uVar1)
                                                                - dVar4)) * dVar5));
    uVar1 = uVar1 + 1;
    *(float *)(SINTABLE + iVar2) = fVar6;
    iVar2 = iVar2 + 4;
  } while (uVar1 < 0x101);
  _restfpr_29();
  return;
}

double sinf3__Ff(double param_1)
{
  return (double)*(float *)(SINTABLE + (int)((double)@126 * param_1) * 4);
}

