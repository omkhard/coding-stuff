#!/usr/bin/env python3 

import os 
import json 
from subprocess import Popen , PIPE , check_output , run 


class Signer:

    def __init__(self,image):
        self.image = image

    def run_cmd(self,args_list) -> tuple:
        try:
            output = Popen(args_list,stderr=PIPE,stdout=PIPE) # can give stdin here using PIPE
            out,err = output.communicate()
            return (output.returncode,out.decode(),err.decode())
        except Exception :
            pass
        return (1,None,None)
    
    def check_login(self,rtfact) -> bool: 
        output = os.system('docker login {}'.format(rtfact))
        if output == 0:
            return True
        else:
            return False 
        
    def sign_image(self):
        # TO DO     
        pass
    
if __name__ == "__main__":
    rtfact = 'artifact2.eng.sonusnet.com'
    registry = "/sbx-docker-prod-virtual/isbc/okhard/"
    image = "debian:latest"
    signer = Signer(rtfact+registry+image)
    if signer.check_login(rtfact):
        pass



