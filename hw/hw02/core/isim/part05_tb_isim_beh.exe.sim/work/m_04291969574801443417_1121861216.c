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
static const char *ng0 = "/home/sabbir/Desktop/courses/CMPE415-Programmable-Logic-Devices/hw/hw02/core/part05_tb.v";
static int ng1[] = {1, 0};
static unsigned int ng2[] = {2863311530U, 0U, 2863311530U, 0U};
static const char *ng3 = "";
static const char *ng4 = " x = %b";
static const char *ng5 = " u = %b";
static int ng6[] = {0, 0};
static unsigned int ng7[] = {1840700269U, 0U, 1533916891U, 0U};



static void Initial_29_0(char *t0)
{
    char t4[16];
    char *t1;
    char *t2;
    char *t3;
    char *t5;
    char *t6;

LAB0:    t1 = (t0 + 2520U);
    t2 = *((char **)t1);
    if (t2 == 0)
        goto LAB2;

LAB3:    goto *t2;

LAB2:    xsi_set_current_line(29, ng0);

LAB4:    xsi_set_current_line(31, ng0);
    t2 = ((char*)((ng1)));
    t3 = (t0 + 1608);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 1);
    xsi_set_current_line(32, ng0);
    t2 = ((char*)((ng2)));
    t3 = (t0 + 1448);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 64);
    xsi_set_current_line(33, ng0);
    t2 = (t0 + 2328);
    xsi_process_wait(t2, 5000LL);
    *((char **)t1) = &&LAB5;

LAB1:    return;
LAB5:    xsi_set_current_line(34, ng0);
    t2 = xsi_vlog_time(t4, 1000.0000000000000, 1000.0000000000000);
    xsi_vlogfile_write(0, 0, 0, ng3, 2, t0, (char)118, t4, 64);
    t3 = (t0 + 1448);
    t5 = (t3 + 56U);
    t6 = *((char **)t5);
    xsi_vlogfile_write(1, 0, 0, ng4, 2, t0, (char)118, t6, 64);
    xsi_set_current_line(35, ng0);
    t2 = (t0 + 2328);
    xsi_process_wait(t2, 5000LL);
    *((char **)t1) = &&LAB6;
    goto LAB1;

LAB6:    xsi_set_current_line(36, ng0);
    t2 = xsi_vlog_time(t4, 1000.0000000000000, 1000.0000000000000);
    xsi_vlogfile_write(0, 0, 0, ng3, 2, t0, (char)118, t4, 64);
    t3 = (t0 + 1048U);
    t5 = *((char **)t3);
    xsi_vlogfile_write(1, 0, 0, ng5, 2, t0, (char)118, t5, 64);
    xsi_set_current_line(38, ng0);
    t2 = ((char*)((ng6)));
    t3 = (t0 + 1608);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 1);
    xsi_set_current_line(39, ng0);
    t2 = ((char*)((ng7)));
    t3 = (t0 + 1448);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 64);
    xsi_set_current_line(40, ng0);
    t2 = (t0 + 2328);
    xsi_process_wait(t2, 5000LL);
    *((char **)t1) = &&LAB7;
    goto LAB1;

LAB7:    xsi_set_current_line(41, ng0);
    t2 = xsi_vlog_time(t4, 1000.0000000000000, 1000.0000000000000);
    xsi_vlogfile_write(0, 0, 0, ng3, 2, t0, (char)118, t4, 64);
    t3 = (t0 + 1448);
    t5 = (t3 + 56U);
    t6 = *((char **)t5);
    xsi_vlogfile_write(1, 0, 0, ng4, 2, t0, (char)118, t6, 64);
    xsi_set_current_line(42, ng0);
    t2 = (t0 + 2328);
    xsi_process_wait(t2, 5000LL);
    *((char **)t1) = &&LAB8;
    goto LAB1;

LAB8:    xsi_set_current_line(43, ng0);
    t2 = xsi_vlog_time(t4, 1000.0000000000000, 1000.0000000000000);
    xsi_vlogfile_write(0, 0, 0, ng3, 2, t0, (char)118, t4, 64);
    t3 = (t0 + 1048U);
    t5 = *((char **)t3);
    xsi_vlogfile_write(1, 0, 0, ng5, 2, t0, (char)118, t5, 64);
    xsi_set_current_line(45, ng0);
    t2 = ((char*)((ng1)));
    t3 = (t0 + 1608);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 1);
    xsi_set_current_line(46, ng0);
    t2 = ((char*)((ng7)));
    t3 = (t0 + 1448);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 64);
    xsi_set_current_line(47, ng0);
    t2 = (t0 + 2328);
    xsi_process_wait(t2, 5000LL);
    *((char **)t1) = &&LAB9;
    goto LAB1;

LAB9:    xsi_set_current_line(48, ng0);
    t2 = xsi_vlog_time(t4, 1000.0000000000000, 1000.0000000000000);
    xsi_vlogfile_write(0, 0, 0, ng3, 2, t0, (char)118, t4, 64);
    t3 = (t0 + 1448);
    t5 = (t3 + 56U);
    t6 = *((char **)t5);
    xsi_vlogfile_write(1, 0, 0, ng4, 2, t0, (char)118, t6, 64);
    xsi_set_current_line(49, ng0);
    t2 = (t0 + 2328);
    xsi_process_wait(t2, 5000LL);
    *((char **)t1) = &&LAB10;
    goto LAB1;

LAB10:    xsi_set_current_line(50, ng0);
    t2 = xsi_vlog_time(t4, 1000.0000000000000, 1000.0000000000000);
    xsi_vlogfile_write(0, 0, 0, ng3, 2, t0, (char)118, t4, 64);
    t3 = (t0 + 1048U);
    t5 = *((char **)t3);
    xsi_vlogfile_write(1, 0, 0, ng5, 2, t0, (char)118, t5, 64);
    xsi_set_current_line(52, ng0);
    t2 = ((char*)((ng6)));
    t3 = (t0 + 1608);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 1);
    goto LAB1;

}

static void Initial_57_1(char *t0)
{
    char *t1;
    char *t2;

LAB0:    t1 = (t0 + 2768U);
    t2 = *((char **)t1);
    if (t2 == 0)
        goto LAB2;

LAB3:    goto *t2;

LAB2:    xsi_set_current_line(57, ng0);
    t2 = (t0 + 2576);
    xsi_process_wait(t2, 40000LL);
    *((char **)t1) = &&LAB4;

LAB1:    return;
LAB4:    xsi_set_current_line(57, ng0);
    xsi_vlog_finish(1);
    goto LAB1;

}


extern void work_m_04291969574801443417_1121861216_init()
{
	static char *pe[] = {(void *)Initial_29_0,(void *)Initial_57_1};
	xsi_register_didat("work_m_04291969574801443417_1121861216", "isim/part05_tb_isim_beh.exe.sim/work/m_04291969574801443417_1121861216.didat");
	xsi_register_executes(pe);
}
