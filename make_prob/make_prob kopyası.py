#!/usr/bin/env python3

from docopt import docopt

import os
import sys
import http.server
import json
from pathlib import Path
import subprocess
import re

args = sys.argv

print(args)

for i in range(1, len(args)):
    os.system("mkdir " + str(args[i]))
    os.system("cp ~/CP/new_template/* " + str(args[i]) + "/.")
    os.system("mkdir " + str(args[i]) + "/bits")
    os.system("cp ~/CP/new_template/bits/* " + str(args[i]) + "/bits/.")
