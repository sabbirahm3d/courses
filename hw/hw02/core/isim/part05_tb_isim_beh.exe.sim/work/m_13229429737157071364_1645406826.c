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
static const char *ng0 = "/home/sabbir/Desktop/courses/CMPE415-Programmable-Logic-Devices/hw/hw02/core/part05.v";
static int ng1[] = {0, 0};
static int ng2[] = {63, 0};
static int ng3[] = {1, 0};



static void Always_29_0(char *t0)
{
    char t6[8];
    char t15[8];
    char t22[8];
    char t30[8];
    char *t1;
    char *t2;
    char *t3;
    char *t4;
    char *t5;
    char *t7;
    unsigned int t8;
    unsigned int t9;
    unsigned int t10;
    unsigned int t11;
    unsigned int t12;
    char *t13;
    char *t14;
    char *t16;
    char *t17;
    char *t18;
    char *t19;
    char *t20;
    char *t21;
    char *t23;
    char *t24;
    char *t25;
    char *t26;
    char *t27;
    char *t28;
    char *t29;
    char *t31;
    unsigned int t32;
    int t33;

LAB0:    t1 = (t0 + 2680U);
    t2 = *((char **)t1);
    if (t2 == 0)
        goto LAB2;

LAB3:    goto *t2;

LAB2:    xsi_set_current_line(29, ng0);
    t2 = (t0 + 3000);
    *((int *)t2) = 1;
    t3 = (t0 + 2712);
    *((char **)t3) = t2;
    *((char **)t1) = &&LAB4;

LAB1:    return;
LAB4:    xsi_set_current_line(29, ng0);

LAB5:    xsi_set_current_line(31, ng0);
    xsi_set_current_line(31, ng0);
    t4 = ((char*)((ng1)));
    t5 = (t0 + 1768);
    xsi_vlogvar_assign_value(t5, t4, 0, 0, 32);

LAB6:    t2 = (t0 + 1768);
    t3 = (t2 + 56U);
    t4 = *((char **)t3);
    t5 = ((char*)((ng2)));
    memset(t6, 0, 8);
    xsi_vlog_signed_less(t6, 32, t4, 32, t5, 32);
    t7 = (t6 + 4);
    t8 = *((unsigned int *)t7);
    t9 = (~(t8));
    t10 = *((unsigned int *)t6);
    t11 = (t10 & t9);
    t12 = (t11 != 0);
    if (t12 > 0)
        goto LAB7;

LAB8:    goto LAB2;

LAB7:    xsi_set_current_line(31, ng0);

LAB9:    xsi_set_current_line(33, ng0);
    t13 = (t0 + 1048U);
    t14 = *((char **)t13);
    t13 = (t0 + 1008U);
    t16 = (t13 + 72U);
    t17 = *((char **)t16);
    t18 = (t0 + 1768);
    t19 = (t18 + 56U);
    t20 = *((char **)t19);
    xsi_vlog_generic_get_index_select_value(t15, 1, t14, t17, 2, t20, 32, 1);
    t21 = (t0 + 1608);
    t23 = (t0 + 1608);
    t24 = (t23 + 72U);
    t25 = *((char **)t24);
    t26 = (t0 + 1768);
    t27 = (t26 + 56U);
    t28 = *((char **)t27);
    t29 = ((char*)((ng3)));
    memset(t30, 0, 8);
    xsi_vlog_signed_add(t30, 32, t28, 32, t29, 32);
    xsi_vlog_generic_convert_bit_index(t22, t25, 2, t30, 32, 1);
    t31 = (t22 + 4);
    t32 = *((unsigned int *)t31);
    t33 = (!(t32));
    if (t33 == 1)
        goto LAB10;

LAB11:    xsi_set_current_line(34, ng0);
    t2 = (t0 + 1048U);
    t3 = *((char **)t2);
    t2 = (t0 + 1008U);
    t4 = (t2 + 72U);
    t5 = *((char **)t4);
    t7 = (t0 + 1768);
    t13 = (t7 + 56U);
    t14 = *((char **)t13);
    t16 = ((char*)((ng3)));
    memset(t15, 0, 8);
    xsi_vlog_signed_add(t15, 32, t14, 32, t16, 32);
    xsi_vlog_generic_get_index_select_value(t6, 1, t3, t5, 2, t15, 32, 1);
    t17 = (t0 + 1608);
    t18 = (t0 + 1608);
    t19 = (t18 + 72U);
    t20 = *((char **)t19);
    t21 = (t0 + 1768);
    t23 = (t21 + 56U);
    t24 = *((char **)t23);
    xsi_vlog_generic_convert_bit_index(t22, t20, 2, t24, 32, 1);
    t25 = (t22 + 4);
    t8 = *((unsigned int *)t25);
    t33 = (!(t8));
    if (t33 == 1)
        goto LAB12;

LAB13:    xsi_set_current_line(31, ng0);
    t2 = (t0 + 1768);
    t3 = (t2 + 56U);
    t4 = *((char **)t3);
    t5 = ((char*)((ng3)));
    memset(t6, 0, 8);
    xsi_vlog_signed_add(t6, 32, t4, 32, t5, 32);
    t7 = (t0 + 1768);
    xsi_vlogvar_assign_value(t7, t6, 0, 0, 32);
    goto LAB6;

LAB10:    xsi_vlogvar_assign_value(t21, t15, 0, *((unsigned int *)t22), 1);
    goto LAB11;

LAB12:    xsi_vlogvar_assign_value(t17, t6, 0, *((unsigned int *)t22), 1);
    goto LAB13;

}


extern void work_m_13229429737157071364_1645406826_init()
{
	static char *pe[] = {(void *)Always_29_0};
	xsi_register_didat("work_m_13229429737157071364_1645406826", "isim/part05_tb_isim_beh.exe.sim/work/m_13229429737157071364_1645406826.didat");
	xsi_register_executes(pe);
}
