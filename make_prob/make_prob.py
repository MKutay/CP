#!/usr/bin/env python3

from docopt import docopt
from datetime import date
import os
import sys
import http.server
import json
from pathlib import Path
import subprocess
import re

args = sys.argv

today = date.today()

print(args)

for i in range(1, len(args)):
    os.system("mkdir " + str(args[i]))
    os.system("cp ~/CP/new_template/* " + str(args[i]) + "/.")
    f = open(str(args[i]) + "/a.cpp", 'w')
    date = today.strftime("%B %d, %Y %H:%M:%S")
    file = """/*
    Author: MKutayBozkurt
    Date and Time: """ + date + """
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
}"""
    f.write(file)
