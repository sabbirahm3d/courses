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
static unsigned int ng4[] = {15U, 8U};
static const char *ng5 = " & 4'bx111 = %b";
static unsigned int ng6[] = {7U, 8U};
static const char *ng7 = " & 4'bz111 = %b";
static int ng8[] = {1, 0};
static const char *ng9 = " | 4'b1001 = %b";
static unsigned int ng10[] = {9U, 8U};
static const char *ng11 = " | 4'bx001 = %b";
static unsigned int ng12[] = {1U, 8U};
static const char *ng13 = " | 4'bz001 = %b";
static int ng14[] = {2, 0};
static const char *ng15 = " ^ 4'b1001 = %b";
static unsigned int ng16[] = {8U, 8U};
static const char *ng17 = " ^ 4'bx000 = %b";
static unsigned int ng18[] = {0U, 8U};
static const char *ng19 = " ^ 4'bz000 = %b";
static int ng20[] = {3, 0};
static const char *ng21 = " ~& 4'b1001 = %b";
static const char *ng22 = " ~& 4'bx001 = %b";
static const char *ng23 = " ~& 4'bz001 = %b";
static int ng24[] = {4, 0};
static const char *ng25 = " ~| 4'b1001 = %b";
static const char *ng26 = " ~| 4'bx001 = %b";
static const char *ng27 = " ~| 4'bz001 = %b";



static void Initial_29_0(char *t0)
{
    char *t1;
    char *t2;
    char *t3;
    char *t4;

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
    t2 = ((char*)((ng2)));
    t3 = (t0 + 1448);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 4);
    xsi_set_current_line(35, ng0);
    t2 = (t0 + 2328);
    xsi_process_wait(t2, 1000LL);
    *((char **)t1) = &&LAB5;

LAB1:    return;
LAB5:    xsi_set_current_line(36, ng0);
    t3 = (t0 + 1048U);
    t4 = *((char **)t3);
    xsi_vlogfile_write(1, 0, 0, ng3, 2, t0, (char)118, t4, 1);
    xsi_set_current_line(38, ng0);
    t2 = ((char*)((ng4)));
    t3 = (t0 + 1448);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 4);
    xsi_set_current_line(39, ng0);
    t2 = (t0 + 2328);
    xsi_process_wait(t2, 1000LL);
    *((char **)t1) = &&LAB6;
    goto LAB1;

LAB6:    xsi_set_current_line(40, ng0);
    t3 = (t0 + 1048U);
    t4 = *((char **)t3);
    xsi_vlogfile_write(1, 0, 0, ng5, 2, t0, (char)118, t4, 1);
    xsi_set_current_line(42, ng0);
    t2 = ((char*)((ng6)));
    t3 = (t0 + 1448);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 4);
    xsi_set_current_line(43, ng0);
    t2 = (t0 + 2328);
    xsi_process_wait(t2, 1000LL);
    *((char **)t1) = &&LAB7;
    goto LAB1;

LAB7:    xsi_set_current_line(44, ng0);
    t3 = (t0 + 1048U);
    t4 = *((char **)t3);
    xsi_vlogfile_write(1, 0, 0, ng7, 2, t0, (char)118, t4, 1);
    xsi_set_current_line(48, ng0);
    t2 = ((char*)((ng8)));
    t3 = (t0 + 1608);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 1);
    xsi_set_current_line(50, ng0);
    t2 = ((char*)((ng2)));
    t3 = (t0 + 1448);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 4);
    xsi_set_current_line(51, ng0);
    t2 = (t0 + 2328);
    xsi_process_wait(t2, 1000LL);
    *((char **)t1) = &&LAB8;
    goto LAB1;

LAB8:    xsi_set_current_line(52, ng0);
    t3 = (t0 + 1048U);
    t4 = *((char **)t3);
    xsi_vlogfile_write(1, 0, 0, ng9, 2, t0, (char)118, t4, 1);
    xsi_set_current_line(54, ng0);
    t2 = ((char*)((ng10)));
    t3 = (t0 + 1448);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 4);
    xsi_set_current_line(55, ng0);
    t2 = (t0 + 2328);
    xsi_process_wait(t2, 1000LL);
    *((char **)t1) = &&LAB9;
    goto LAB1;

LAB9:    xsi_set_current_line(56, ng0);
    t3 = (t0 + 1048U);
    t4 = *((char **)t3);
    xsi_vlogfile_write(1, 0, 0, ng11, 2, t0, (char)118, t4, 1);
    xsi_set_current_line(58, ng0);
    t2 = ((char*)((ng12)));
    t3 = (t0 + 1448);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 4);
    xsi_set_current_line(59, ng0);
    t2 = (t0 + 2328);
    xsi_process_wait(t2, 1000LL);
    *((char **)t1) = &&LAB10;
    goto LAB1;

LAB10:    xsi_set_current_line(60, ng0);
    t3 = (t0 + 1048U);
    t4 = *((char **)t3);
    xsi_vlogfile_write(1, 0, 0, ng13, 2, t0, (char)118, t4, 1);
    xsi_set_current_line(63, ng0);
    t2 = ((char*)((ng14)));
    t3 = (t0 + 1608);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 1);
    xsi_set_current_line(65, ng0);
    t2 = ((char*)((ng2)));
    t3 = (t0 + 1448);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 4);
    xsi_set_current_line(66, ng0);
    t2 = (t0 + 2328);
    xsi_process_wait(t2, 1000LL);
    *((char **)t1) = &&LAB11;
    goto LAB1;

LAB11:    xsi_set_current_line(67, ng0);
    t3 = (t0 + 1048U);
    t4 = *((char **)t3);
    xsi_vlogfile_write(1, 0, 0, ng15, 2, t0, (char)118, t4, 1);
    xsi_set_current_line(69, ng0);
    t2 = ((char*)((ng16)));
    t3 = (t0 + 1448);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 4);
    xsi_set_current_line(70, ng0);
    t2 = (t0 + 2328);
    xsi_process_wait(t2, 1000LL);
    *((char **)t1) = &&LAB12;
    goto LAB1;

LAB12:    xsi_set_current_line(71, ng0);
    t3 = (t0 + 1048U);
    t4 = *((char **)t3);
    xsi_vlogfile_write(1, 0, 0, ng17, 2, t0, (char)118, t4, 1);
    xsi_set_current_line(73, ng0);
    t2 = ((char*)((ng18)));
    t3 = (t0 + 1448);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 4);
    xsi_set_current_line(74, ng0);
    t2 = (t0 + 2328);
    xsi_process_wait(t2, 1000LL);
    *((char **)t1) = &&LAB13;
    goto LAB1;

LAB13:    xsi_set_current_line(75, ng0);
    t3 = (t0 + 1048U);
    t4 = *((char **)t3);
    xsi_vlogfile_write(1, 0, 0, ng19, 2, t0, (char)118, t4, 1);
    xsi_set_current_line(78, ng0);
    t2 = ((char*)((ng20)));
    t3 = (t0 + 1608);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 1);
    xsi_set_current_line(80, ng0);
    t2 = ((char*)((ng2)));
    t3 = (t0 + 1448);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 4);
    xsi_set_current_line(81, ng0);
    t2 = (t0 + 2328);
    xsi_process_wait(t2, 1000LL);
    *((char **)t1) = &&LAB14;
    goto LAB1;

LAB14:    xsi_set_current_line(82, ng0);
    t3 = (t0 + 1048U);
    t4 = *((char **)t3);
    xsi_vlogfile_write(1, 0, 0, ng21, 2, t0, (char)118, t4, 1);
    xsi_set_current_line(84, ng0);
    t2 = ((char*)((ng10)));
    t3 = (t0 + 1448);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 4);
    xsi_set_current_line(85, ng0);
    t2 = (t0 + 2328);
    xsi_process_wait(t2, 1000LL);
    *((char **)t1) = &&LAB15;
    goto LAB1;

LAB15:    xsi_set_current_line(86, ng0);
    t3 = (t0 + 1048U);
    t4 = *((char **)t3);
    xsi_vlogfile_write(1, 0, 0, ng22, 2, t0, (char)118, t4, 1);
    xsi_set_current_line(88, ng0);
    t2 = ((char*)((ng12)));
    t3 = (t0 + 1448);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 4);
    xsi_set_current_line(89, ng0);
    t2 = (t0 + 2328);
    xsi_process_wait(t2, 1000LL);
    *((char **)t1) = &&LAB16;
    goto LAB1;

LAB16:    xsi_set_current_line(90, ng0);
    t3 = (t0 + 1048U);
    t4 = *((char **)t3);
    xsi_vlogfile_write(1, 0, 0, ng23, 2, t0, (char)118, t4, 1);
    xsi_set_current_line(93, ng0);
    t2 = ((char*)((ng24)));
    t3 = (t0 + 1608);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 1);
    xsi_set_current_line(95, ng0);
    t2 = ((char*)((ng2)));
    t3 = (t0 + 1448);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 4);
    xsi_set_current_line(96, ng0);
    t2 = (t0 + 2328);
    xsi_process_wait(t2, 1000LL);
    *((char **)t1) = &&LAB17;
    goto LAB1;

LAB17:    xsi_set_current_line(98, ng0);
    t3 = (t0 + 1048U);
    t4 = *((char **)t3);
    xsi_vlogfile_write(1, 0, 0, ng25, 2, t0, (char)118, t4, 1);
    xsi_set_current_line(100, ng0);
    t2 = ((char*)((ng10)));
    t3 = (t0 + 1448);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 4);
    xsi_set_current_line(101, ng0);
    t2 = (t0 + 2328);
    xsi_process_wait(t2, 1000LL);
    *((char **)t1) = &&LAB18;
    goto LAB1;

LAB18:    xsi_set_current_line(102, ng0);
    t3 = (t0 + 1048U);
    t4 = *((char **)t3);
    xsi_vlogfile_write(1, 0, 0, ng26, 2, t0, (char)118, t4, 1);
    xsi_set_current_line(104, ng0);
    t2 = ((char*)((ng12)));
    t3 = (t0 + 1448);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 4);
    xsi_set_current_line(105, ng0);
    t2 = (t0 + 2328);
    xsi_process_wait(t2, 1000LL);
    *((char **)t1) = &&LAB19;
    goto LAB1;

LAB19:    xsi_set_current_line(106, ng0);
    t3 = (t0 + 1048U);
    t4 = *((char **)t3);
    xsi_vlogfile_write(1, 0, 0, ng27, 2, t0, (char)118, t4, 1);
    xsi_set_current_line(108, ng0);
    t2 = (t0 + 2328);
    xsi_process_wait(t2, 2000LL);
    *((char **)t1) = &&LAB20;
    goto LAB1;

LAB20:    xsi_set_current_line(108, ng0);
    xsi_vlog_finish(1);
    goto LAB1;

}


extern void work_m_10415374662479158261_1739940284_init()
{
	static char *pe[] = {(void *)Initial_29_0};
	xsi_register_didat("work_m_10415374662479158261_1739940284", "isim/part03_tb_isim_beh.exe.sim/work/m_10415374662479158261_1739940284.didat");
	xsi_register_executes(pe);
}
