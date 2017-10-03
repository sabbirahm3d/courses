/**********************************************************************/
/*   ____  ____                                                       */
/*  /   /\/   /                                                       */
/* /___/  \  /                                                        */
/* \   \   \/                                                       */
/*  \   \        Copyright (c) 2003-2009 Xilinx, Inc.                */
/*  /   /          All Right Reserved.                                 */
/* /---/   /\                                                         */
/* \   \  /  \                                                      */
/*  \___\/\___\                                                    */
/***********************************************************************/

/* This file is designed for use with ISim build 0xfbc00daa */

#define XSI_HIDE_SYMBOL_SPEC true
#include "xsi.h"
#include <memory.h>
#ifdef __GNUC__
#include <stdlib.h>
#else
#include <malloc.h>
#define alloca _alloca
#endif
static const char *ng0 = "/home/sabbir/Desktop/courses/CMPE415-Programmable-Logic-Devices/hw/hw02/core/part03.v";
static int ng1[] = {0, 0};
static int ng2[] = {1, 0};
static int ng3[] = {2, 0};
static int ng4[] = {3, 0};
static int ng5[] = {4, 0};



static void Always_27_0(char *t0)
{
    char t7[8];
    char t8[8];
    char *t1;
    char *t2;
    char *t3;
    char *t4;
    char *t5;
    int t6;
    char *t9;
    char *t10;
    unsigned int t11;
    unsigned int t12;
    unsigned int t13;
    char *t14;
    char *t15;
    unsigned int t16;
    unsigned int t17;

LAB0:    t1 = (t0 + 2520U);
    t2 = *((char **)t1);
    if (t2 == 0)
        goto LAB2;

LAB3:    goto *t2;

LAB2:    xsi_set_current_line(27, ng0);
    t2 = (t0 + 2840);
    *((int *)t2) = 1;
    t3 = (t0 + 2552);
    *((char **)t3) = t2;
    *((char **)t1) = &&LAB4;

LAB1:    return;
LAB4:    xsi_set_current_line(27, ng0);

LAB5:    xsi_set_current_line(29, ng0);
    t4 = (t0 + 1208U);
    t5 = *((char **)t4);

LAB6:    t4 = ((char*)((ng1)));
    t6 = xsi_vlog_unsigned_case_compare(t5, 1, t4, 32);
    if (t6 == 1)
        goto LAB7;

LAB8:    t2 = ((char*)((ng2)));
    t6 = xsi_vlog_unsigned_case_compare(t5, 1, t2, 32);
    if (t6 == 1)
        goto LAB9;

LAB10:    t2 = ((char*)((ng3)));
    t6 = xsi_vlog_unsigned_case_compare(t5, 1, t2, 32);
    if (t6 == 1)
        goto LAB11;

LAB12:    t2 = ((char*)((ng4)));
    t6 = xsi_vlog_unsigned_case_compare(t5, 1, t2, 32);
    if (t6 == 1)
        goto LAB13;

LAB14:    t2 = ((char*)((ng5)));
    t6 = xsi_vlog_unsigned_case_compare(t5, 1, t2, 32);
    if (t6 == 1)
        goto LAB15;

LAB16:
LAB17:    goto LAB2;

LAB7:    xsi_set_current_line(31, ng0);
    t9 = (t0 + 1048U);
    t10 = *((char **)t9);
    xsi_vlogtype_concat(t8, 1, 1, 1U, t10, 1);
    memset(t7, 0, 8);
    t9 = (t8 + 4);
    t11 = *((unsigned int *)t8);
    t12 = *((unsigned int *)t9);
    t13 = (t11 | t12);
    if (t13 != 1U)
        goto LAB19;

LAB18:    if (*((unsigned int *)t9) == 0)
        goto LAB20;

LAB21:    t14 = (t7 + 4);
    *((unsigned int *)t7) = 1;
    *((unsigned int *)t14) = 1;

LAB19:    t15 = (t0 + 1608);
    xsi_vlogvar_wait_assign_value(t15, t7, 0, 0, 1, 0LL);
    goto LAB17;

LAB9:    xsi_set_current_line(32, ng0);
    t3 = (t0 + 1048U);
    t4 = *((char **)t3);
    memset(t7, 0, 8);
    t3 = (t4 + 4);
    t11 = *((unsigned int *)t3);
    t12 = (~(t11));
    t13 = *((unsigned int *)t4);
    t16 = (t13 & t12);
    t17 = (t16 & 1U);
    if (t17 != 0)
        goto LAB22;

LAB23:    if (*((unsigned int *)t3) != 0)
        goto LAB24;

LAB25:    t10 = (t0 + 1608);
    xsi_vlogvar_wait_assign_value(t10, t7, 0, 0, 1, 0LL);
    goto LAB17;

LAB11:    xsi_set_current_line(33, ng0);
    t3 = (t0 + 1048U);
    t4 = *((char **)t3);
    memset(t7, 0, 8);
    t3 = (t4 + 4);
    t11 = *((unsigned int *)t4);
    t12 = *((unsigned int *)t4);
    t12 = (t12 & 1);
    if (*((unsigned int *)t3) != 0)
        goto LAB26;

LAB27:    t13 = 1;

LAB29:    t16 = (t13 <= 0);
    if (t16 == 1)
        goto LAB30;

LAB31:    *((unsigned int *)t7) = t12;

LAB28:    t10 = (t0 + 1608);
    xsi_vlogvar_wait_assign_value(t10, t7, 0, 0, 1, 0LL);
    goto LAB17;

LAB13:    xsi_set_current_line(34, ng0);
    t3 = (t0 + 1048U);
    t4 = *((char **)t3);
    memset(t7, 0, 8);
    t3 = (t4 + 4);
    t11 = *((unsigned int *)t4);
    t12 = *((unsigned int *)t3);
    t13 = (t11 | t12);
    if (t13 != 1U)
        goto LAB35;

LAB33:    if (*((unsigned int *)t3) == 0)
        goto LAB34;

LAB36:    t9 = (t7 + 4);
    *((unsigned int *)t7) = 1;
    *((unsigned int *)t9) = 1;

LAB34:    t10 = (t0 + 1608);
    xsi_vlogvar_wait_assign_value(t10, t7, 0, 0, 1, 0LL);
    goto LAB17;

LAB15:    xsi_set_current_line(35, ng0);
    t3 = (t0 + 1048U);
    t4 = *((char **)t3);
    memset(t7, 0, 8);
    t3 = (t4 + 4);
    t11 = *((unsigned int *)t3);
    t12 = (~(t11));
    t13 = *((unsigned int *)t4);
    t16 = (t13 & t12);
    t17 = (t16 & 1U);
    if (t17 != 0)
        goto LAB40;

LAB38:    if (*((unsigned int *)t3) == 0)
        goto LAB37;

LAB39:    t9 = (t7 + 4);
    *((unsigned int *)t7) = 1;
    *((unsigned int *)t9) = 1;

LAB40:    t10 = (t0 + 1608);
    xsi_vlogvar_wait_assign_value(t10, t7, 0, 0, 1, 0LL);
    goto LAB17;

LAB20:    *((unsigned int *)t7) = 1;
    goto LAB19;

LAB22:    *((unsigned int *)t7) = 1;
    goto LAB25;

LAB24:    t9 = (t7 + 4);
    *((unsigned int *)t7) = 1;
    *((unsigned int *)t9) = 1;
    goto LAB25;

LAB26:    t9 = (t7 + 4);
    *((unsigned int *)t7) = 1;
    *((unsigned int *)t9) = 1;
    goto LAB28;

LAB30:    t11 = (t11 >> 1);
    t17 = (t11 & 1);
    t12 = (t12 ^ t17);

LAB32:    t13 = (t13 + 1);
    goto LAB29;

LAB35:    *((unsigned int *)t7) = 1;
    goto LAB34;

LAB37:    *((unsigned int *)t7) = 1;
    goto LAB40;

}


extern void work_m_07559884343151481357_2339458911_init()
{
	static char *pe[] = {(void *)Always_27_0};
	xsi_register_didat("work_m_07559884343151481357_2339458911", "isim/part03_tb_isim_beh.exe.sim/work/m_07559884343151481357_2339458911.didat");
	xsi_register_executes(pe);
}
