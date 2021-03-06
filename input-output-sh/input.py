#!/usr/bin/env python3
import os
import sys
import subprocess

a = sys.argv # i = int, l = long long, d = double, c = char, s = string

def f():
    c = ""
    if a[1] == '-i':
        c += "int"
    if a[1] == '-l':
        c += "long long"
    if a[1] == '-d':
        c += "double"
    if a[1] == '-c':
        c += "char"
    if a[1] == '-s':
        c += "string"

    c += " "

    for i in range(2, len(a)):
        if (i == len(a) - 1):
            c += a[i] + "; "
            break
        c += a[i] + ", "
    c += "cin >> "
    for i in range(2, len(a)):
        if (i == len(a) - 1):
            c += a[i] + ";"
            break
        c += a[i] + " >> "
    return c

def f2():
    c = ""
    ty = ""
    c += "vector<"
    if a[1] == '-vi':
        ty = "int"
    if a[1] == '-vl':
        ty = "long long"
    if a[1] == '-vd':
        ty = "double"
    if a[1] == '-vc':
        ty = "char"
    if a[1] == '-vs':
        ty = "string"
    c += ty + "> "
    c += a[2] + "; "
    c += "for (" + ty + " &x : " + a[2] + ") cin >> x;"
    return c

def f3():
    c = ""
    ty = ""
    c += "vector<vector<"
    if a[1] == '-vvi':
        ty = "int"
    if a[1] == '-vvl':
        ty = "long long"
    if a[1] == '-vvd':
        ty = "double"
    if a[1] == '-vvc':
        ty = "char"
    if a[1] == '-vvs':
        ty = "string"
    c += ty + ">> "
    c += a[2] + "; "
    c += "for (auto &x : " + a[2] + ") for (" + ty + " &y : x) cin >> y;"
    return c

c = ""

if a[1][1] == 'v' and a[1][2] == 'v':
    c = f3()
elif 'v' in a[1]:
    c = f2()
else:
    c = f()

print(c)

subprocess.run("pbcopy", universal_newlines=True, input=c)
