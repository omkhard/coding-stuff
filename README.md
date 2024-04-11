# coding-stuff

This repository is for my own coding solutions .

## This Repository has some basic tools for basic utilities
- *epochToDatetime Converter in CPP*.
- *classPatterns* basic code for practicing Design Patterns.
- basic *elvatorSystemDesign*.
- *mostFrequentString in CPP*.

**Every Methods Used definitions**
- import subprocess (smart_ip_allocator.py) :<br>
<ins>*Popen(args)*</ins>  <br>
We can PIPE *stderr* and *stdout* and also make shell and cwd as **False** , we can use it for checking the output for an OS command. <br>
<ins>*communicate()*</ins> <br>
This method is used for checking the PIPE'd err , and output in **Popen** used method and can be modified using raised exception if command failed using try/except.

**In python-stuff**
- The smart_ip_allocator is a great upcoming tool for detecting in a Running **Kubernetes** cluster, that  how many IPs are vacant after the deployments are using and can be used in for newer/latest deployments.