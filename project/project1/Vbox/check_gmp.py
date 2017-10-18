#!/usr/bin/python2
# -*- coding: utf-8
import ctypes
from  sage.all import *
import flint_sage as flint
import sys,time,os,ctypes,subprocess

so_name='/usr/lib/libgmp.so'
var_name='__gmp_version'
L=ctypes.cdll.LoadLibrary(so_name)
v=ctypes.c_char_p.in_dll(L,var_name)
print v.value