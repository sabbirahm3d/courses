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
static const char *ng0 = "/home/sabbir/Desktop/courses/CMPE415-Programmable-Logic-Devices/hw/hw02/core/part03_tb.v";
static int ng1[] = {0, 0};
static unsigned int ng2[] = {9U, 0U};
static const char *ng3 = " & 4'b1001 = %b";
static const char *ng4 = " & DIS 4'b1001 = %b";
static unsigned int ng5[] = {15U, 8U};
static const char *ng6 = " & 4'bx111 = %b";
static unsigned int ng7[] = {7U, 8U};
static const char *ng8 = " & 4'bz111 = %b";
static int ng9[] = {1, 0};
static const char *ng10 = " | 4'b1001 = %b";
static unsigned int ng11[] = {9U, 8U};
static const char *ng12 = " | 4'bx001 = %b";
static unsigned int ng13[] = {1U, 8U};
static const char *ng14 = " | 4'bz001 = %b";
static int ng15[] = {2, 0};
static const char *ng16 = " ^  4'b1001 = %b";
static const char *ng17 = " ^  4'bx001 = %b";
static const char *ng18 = " ^  4'bz001 = %b";
static const char *ng19 = " ^ 4'b1001 = %b";
static unsigned int ng20[] = {8U, 8U};
static const char *ng21 = " ^ 4'bx000 = %b";
static unsigned int ng22[] = {0U, 8U};
static const char *ng23 = " ^ 4'bz000 = %b";
static int ng24[] = {3, 0};
static const char *ng25 = " ~& 4'b1001 = %b";
static const char *ng26 = " ~& 4'bx001 = %b";
static const char *ng27 = " ~& 4'bz001 = %b";
static int ng28[] = {4, 0};
static const char *ng29 = " ~| 4'b1001 = %b";
static const char *ng30 = " ~| 4'bx001 = %b";
static const char *ng31 = " ~| 4'bz001 = %b";



static void Initial_29_0(char *t0)
{
    char t5[8];
    char *t1;
    char *t2;
    char *t3;
    char *t4;
    char *t6;
    unsigned int t7;
    unsigned int t8;
    unsigned int t9;
    char *t10;
    unsigned int t11;
    unsigned int t12;

LAB0:    t1 = (t0 + 2520U);
    t2 = *((char **)t1);
    if (t2 == 0)
        goto LAB2;

LAB3:    goto *t2;

LAB2:    xsi_set_current_line(29, ng0);

LAB4:    xsi_set_current_line(32, ng0);
    t2 = ((char*)((ng1)));
    t3 = (t0 + 1608);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 1);
    xsi_set_current_line(34, ng0);
    t2 = (t0 + 2328);
    xsi_process_wait(t2, 1000LL);
    *((char **)t1) = &&LAB5;

LAB1:    return;
LAB5:    xsi_set_current_line(35, ng0);
    t3 = ((char*)((ng2)));
    t4 = (t0 + 1448);
    xsi_vlogvar_assign_value(t4, t3, 0, 0, 1);
    xsi_set_current_line(36, ng0);
    t2 = (t0 + 2328);
    xsi_process_wait(t2, 1000LL);
    *((char **)t1) = &&LAB6;
    goto LAB1;

LAB6:    xsi_set_current_line(37, ng0);
    t3 = (t0 + 1048U);
    t4 = *((char **)t3);
    xsi_vlogfile_write(1, 0, 0, ng3, 2, t0, (char)118, t4, 1);
    xsi_set_current_line(38, ng0);
    t2 = ((char*)((ng2)));
    xsi_vlogfile_write(1, 0, 0, ng4, 2, t0, (char)118, t2, 4);
    xsi_set_current_line(39, ng0);
    t2 = (t0 + 1448);
    t3 = (t2 + 56U);
    t4 = *((char **)t3);
    xsi_vlogfile_write(1, 0, 0, ng4, 2, t0, (char)118, t4, 1);
    xsi_set_current_line(40, ng0);
    t2 = (t0 + 1448);
    t3 = (t2 + 56U);
    t4 = *((char **)t3);
    memset(t5, 0, 8);
    t6 = (t4 + 4);
    t7 = *((unsigned int *)t4);
    t8 = *((unsigned int *)t6);
    t9 = (t7 | t8);
    if (t9 != 1U)
        goto LAB8;

LAB7:    if (*((unsigned int *)t6) == 0)
        goto LAB9;

LAB10:    t10 = (t5 + 4);
    *((unsigned int *)t5) = 1;
    *((unsigned int *)t10) = 1;

LAB8:    xsi_vlogfile_write(1, 0, 0, ng4, 2, t0, (char)118, t5, 1);
    xsi_set_current_line(42, ng0);
    t2 = (t0 + 2328);
    xsi_process_wait(t2, 1000LL);
    *((char **)t1) = &&LAB11;
    goto LAB1;

LAB9:    *((unsigned int *)t5) = 1;
    goto LAB8;

LAB11:    xsi_set_current_line(43, ng0);
    t3 = ((char*)((ng5)));
    t4 = (t0 + 1448);
    xsi_vlogvar_assign_value(t4, t3, 0, 0, 1);
    xsi_set_current_line(44, ng0);
    t2 = (t0 + 1048U);
    t3 = *((char **)t2);
    xsi_vlogfile_write(1, 0, 0, ng6, 2, t0, (char)118, t3, 1);
    xsi_set_current_line(46, ng0);
    t2 = (t0 + 2328);
    xsi_process_wait(t2, 1000LL);
    *((char **)t1) = &&LAB12;
    goto LAB1;

LAB12:    xsi_set_current_line(47, ng0);
    t3 = ((char*)((ng7)));
    t4 = (t0 + 1448);
    xsi_vlogvar_assign_value(t4, t3, 0, 0, 1);
    xsi_set_current_line(48, ng0);
    t2 = (t0 + 1048U);
    t3 = *((char **)t2);
    xsi_vlogfile_write(1, 0, 0, ng8, 2, t0, (char)118, t3, 1);
    xsi_set_current_line(52, ng0);
    t2 = ((char*)((ng9)));
    t3 = (t0 + 1608);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 1);
    xsi_set_current_line(54, ng0);
    t2 = (t0 + 2328);
    xsi_process_wait(t2, 1000LL);
    *((char **)t1) = &&LAB13;
    goto LAB1;

LAB13:    xsi_set_current_line(55, ng0);
    t3 = ((char*)((ng2)));
    t4 = (t0 + 1448);
    xsi_vlogvar_assign_value(t4, t3, 0, 0, 1);
    xsi_set_current_line(56, ng0);
    t2 = (t0 + 1048U);
    t3 = *((char **)t2);
    xsi_vlogfile_write(1, 0, 0, ng10, 2, t0, (char)118, t3, 1);
    xsi_set_current_line(58, ng0);
    t2 = (t0 + 2328);
    xsi_process_wait(t2, 1000LL);
    *((char **)t1) = &&LAB14;
    goto LAB1;

LAB14:    xsi_set_current_line(59, ng0);
    t3 = ((char*)((ng11)));
    t4 = (t0 + 1448);
    xsi_vlogvar_assign_value(t4, t3, 0, 0, 1);
    xsi_set_current_line(60, ng0);
    t2 = (t0 + 1048U);
    t3 = *((char **)t2);
    xsi_vlogfile_write(1, 0, 0, ng12, 2, t0, (char)118, t3, 1);
    xsi_set_current_line(62, ng0);
    t2 = (t0 + 2328);
    xsi_process_wait(t2, 1000LL);
    *((char **)t1) = &&LAB15;
    goto LAB1;

LAB15:    xsi_set_current_line(63, ng0);
    t3 = ((char*)((ng13)));
    t4 = (t0 + 1448);
    xsi_vlogvar_assign_value(t4, t3, 0, 0, 1);
    xsi_set_current_line(64, ng0);
    t2 = (t0 + 1048U);
    t3 = *((char **)t2);
    xsi_vlogfile_write(1, 0, 0, ng14, 2, t0, (char)118, t3, 1);
    xsi_set_current_line(67, ng0);
    t2 = ((char*)((ng15)));
    t3 = (t0 + 1608);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 1);
    xsi_set_current_line(69, ng0);
    t2 = ((char*)((ng2)));
    memset(t5, 0, 8);
    t3 = (t2 + 4);
    t7 = *((unsigned int *)t2);
    t8 = *((unsigned int *)t2);
    t8 = (t8 & 1);
    if (*((unsigned int *)t3) != 0)
        goto LAB16;

LAB17:    t9 = 1;

LAB19:    t11 = (t9 <= 3);
    if (t11 == 1)
        goto LAB20;

LAB21:    *((unsigned int *)t5) = t8;

LAB18:    xsi_vlogfile_write(1, 0, 0, ng16, 2, t0, (char)118, t5, 1);
    xsi_set_current_line(70, ng0);
    t2 = ((char*)((ng11)));
    memset(t5, 0, 8);
    t3 = (t2 + 4);
    t7 = *((unsigned int *)t2);
    t8 = *((unsigned int *)t2);
    t8 = (t8 & 1);
    if (*((unsigned int *)t3) != 0)
        goto LAB23;

LAB24:    t9 = 1;

LAB26:    t11 = (t9 <= 3);
    if (t11 == 1)
        goto LAB27;

LAB28:    *((unsigned int *)t5) = t8;

LAB25:    xsi_vlogfile_write(1, 0, 0, ng17, 2, t0, (char)118, t5, 1);
    xsi_set_current_line(71, ng0);
    t2 = ((char*)((ng13)));
    memset(t5, 0, 8);
    t3 = (t2 + 4);
    t7 = *((unsigned int *)t2);
    t8 = *((unsigned int *)t2);
    t8 = (t8 & 1);
    if (*((unsigned int *)t3) != 0)
        goto LAB30;

LAB31:    t9 = 1;

LAB33:    t11 = (t9 <= 3);
    if (t11 == 1)
        goto LAB34;

LAB35:    *((unsigned int *)t5) = t8;

LAB32:    xsi_vlogfile_write(1, 0, 0, ng18, 2, t0, (char)118, t5, 1);
    xsi_set_current_line(73, ng0);
    t2 = (t0 + 2328);
    xsi_process_wait(t2, 1000LL);
    *((char **)t1) = &&LAB37;
    goto LAB1;

LAB16:    t4 = (t5 + 4);
    *((unsigned int *)t5) = 1;
    *((unsigned int *)t4) = 1;
    goto LAB18;

LAB20:    t7 = (t7 >> 1);
    t12 = (t7 & 1);
    t8 = (t8 ^ t12);

LAB22:    t9 = (t9 + 1);
    goto LAB19;

LAB23:    t4 = (t5 + 4);
    *((unsigned int *)t5) = 1;
    *((unsigned int *)t4) = 1;
    goto LAB25;

LAB27:    t7 = (t7 >> 1);
    t12 = (t7 & 1);
    t8 = (t8 ^ t12);

LAB29:    t9 = (t9 + 1);
    goto LAB26;

LAB30:    t4 = (t5 + 4);
    *((unsigned int *)t5) = 1;
    *((unsigned int *)t4) = 1;
    goto LAB32;

LAB34:    t7 = (t7 >> 1);
    t12 = (t7 & 1);
    t8 = (t8 ^ t12);

LAB36:    t9 = (t9 + 1);
    goto LAB33;

LAB37:    xsi_set_current_line(74, ng0);
    t3 = ((char*)((ng2)));
    t4 = (t0 + 1448);
    xsi_vlogvar_assign_value(t4, t3, 0, 0, 1);
    xsi_set_current_line(75, ng0);
    t2 = (t0 + 1048U);
    t3 = *((char **)t2);
    xsi_vlogfile_write(1, 0, 0, ng19, 2, t0, (char)118, t3, 1);
    xsi_set_current_line(77, ng0);
    t2 = (t0 + 2328);
    xsi_process_wait(t2, 1000LL);
    *((char **)t1) = &&LAB38;
    goto LAB1;

LAB38:    xsi_set_current_line(78, ng0);
    t3 = ((char*)((ng20)));
    t4 = (t0 + 1448);
    xsi_vlogvar_assign_value(t4, t3, 0, 0, 1);
    xsi_set_current_line(79, ng0);
    t2 = (t0 + 1048U);
    t3 = *((char **)t2);
    xsi_vlogfile_write(1, 0, 0, ng21, 2, t0, (char)118, t3, 1);
    xsi_set_current_line(81, ng0);
    t2 = (t0 + 2328);
    xsi_process_wait(t2, 1000LL);
    *((char **)t1) = &&LAB39;
    goto LAB1;

LAB39:    xsi_set_current_line(82, ng0);
    t3 = ((char*)((ng22)));
    t4 = (t0 + 1448);
    xsi_vlogvar_assign_value(t4, t3, 0, 0, 1);
    xsi_set_current_line(83, ng0);
    t2 = (t0 + 1048U);
    t3 = *((char **)t2);
    xsi_vlogfile_write(1, 0, 0, ng23, 2, t0, (char)118, t3, 1);
    xsi_set_current_line(86, ng0);
    t2 = ((char*)((ng24)));
    t3 = (t0 + 1608);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 1);
    xsi_set_current_line(88, ng0);
    t2 = (t0 + 2328);
    xsi_process_wait(t2, 1000LL);
    *((char **)t1) = &&LAB40;
    goto LAB1;

LAB40:    xsi_set_current_line(89, ng0);
    t3 = ((char*)((ng2)));
    t4 = (t0 + 1448);
    xsi_vlogvar_assign_value(t4, t3, 0, 0, 1);
    xsi_set_current_line(90, ng0);
    t2 = (t0 + 1048U);
    t3 = *((char **)t2);
    xsi_vlogfile_write(1, 0, 0, ng25, 2, t0, (char)118, t3, 1);
    xsi_set_current_line(92, ng0);
    t2 = (t0 + 2328);
    xsi_process_wait(t2, 1000LL);
    *((char **)t1) = &&LAB41;
    goto LAB1;

LAB41:    xsi_set_current_line(93, ng0);
    t3 = ((char*)((ng11)));
    t4 = (t0 + 1448);
    xsi_vlogvar_assign_value(t4, t3, 0, 0, 1);
    xsi_set_current_line(94, ng0);
    t2 = (t0 + 1048U);
    t3 = *((char **)t2);
    xsi_vlogfile_write(1, 0, 0, ng26, 2, t0, (char)118, t3, 1);
    xsi_set_current_line(96, ng0);
    t2 = (t0 + 2328);
    xsi_process_wait(t2, 1000LL);
    *((char **)t1) = &&LAB42;
    goto LAB1;

LAB42:    xsi_set_current_line(97, ng0);
    t3 = ((char*)((ng13)));
    t4 = (t0 + 1448);
    xsi_vlogvar_assign_value(t4, t3, 0, 0, 1);
    xsi_set_current_line(98, ng0);
    t2 = (t0 + 1048U);
    t3 = *((char **)t2);
    xsi_vlogfile_write(1, 0, 0, ng27, 2, t0, (char)118, t3, 1);
    xsi_set_current_line(101, ng0);
    t2 = ((char*)((ng28)));
    t3 = (t0 + 1608);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 1);
    xsi_set_current_line(103, ng0);
    t2 = (t0 + 2328);
    xsi_process_wait(t2, 1000LL);
    *((char **)t1) = &&LAB43;
    goto LAB1;

LAB43:    xsi_set_current_line(104, ng0);
    t3 = ((char*)((ng2)));
    t4 = (t0 + 1448);
    xsi_vlogvar_assign_value(t4, t3, 0, 0, 1);
    xsi_set_current_line(106, ng0);
    t2 = (t0 + 1048U);
    t3 = *((char **)t2);
    xsi_vlogfile_write(1, 0, 0, ng29, 2, t0, (char)118, t3, 1);
    xsi_set_current_line(108, ng0);
    t2 = (t0 + 2328);
    xsi_process_wait(t2, 1000LL);
    *((char **)t1) = &&LAB44;
    goto LAB1;

LAB44:    xsi_set_current_line(109, ng0);
    t3 = ((char*)((ng11)));
    t4 = (t0 + 1448);
    xsi_vlogvar_assign_value(t4, t3, 0, 0, 1);
    xsi_set_current_line(110, ng0);
    t2 = (t0 + 1048U);
    t3 = *((char **)t2);
    xsi_vlogfile_write(1, 0, 0, ng30, 2, t0, (char)118, t3, 1);
    xsi_set_current_line(112, ng0);
    t2 = (t0 + 2328);
    xsi_process_wait(t2, 1000LL);
    *((char **)t1) = &&LAB45;
    goto LAB1;

LAB45:    xsi_set_current_line(113, ng0);
    t3 = ((char*)((ng13)));
    t4 = (t0 + 1448);
    xsi_vlogvar_assign_value(t4, t3, 0, 0, 1);
    xsi_set_current_line(114, ng0);
    t2 = (t0 + 1048U);
    t3 = *((char **)t2);
    xsi_vlogfile_write(1, 0, 0, ng31, 2, t0, (char)118, t3, 1);
    xsi_set_current_line(116, ng0);
    t2 = (t0 + 2328);
    xsi_process_wait(t2, 18000LL);
    *((char **)t1) = &&LAB46;
    goto LAB1;

LAB46:    xsi_set_current_line(116, ng0);
    xsi_vlog_finish(1);
    goto LAB1;

}


extern void work_m_10364832555965431444_1739940284_init()
{
	static char *pe[] = {(void *)Initial_29_0};
	xsi_register_didat("work_m_10364832555965431444_1739940284", "isim/part03_tb_isim_beh.exe.sim/work/m_10364832555965431444_1739940284.didat");
	xsi_register_executes(pe);
}
