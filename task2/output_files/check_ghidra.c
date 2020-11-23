
/* check(char*, char const*, int (*)(char const*, char const*)) */

void check(char *param_1,char *param_2,FuncDef0 *param_3)

{
  int iVar1;
  
  iVar1 = (*param_3)(param_1,param_2);
  if (iVar1 == 0) {
    puts("Access granted");
  }
  else {
    puts("Access denied");
  }
  return;
}

