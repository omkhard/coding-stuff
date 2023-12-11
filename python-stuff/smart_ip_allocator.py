"""
This project is made for telling free IP's in a network-attachment for launch
any POD in a k8s cluster.

Solution: 
it will take the net-att name and find out the IP which are not in use
* Assuming that in a POD's deployment [Environment: -| HA_MGT_IP:]
Some thing like this has been described already
"""
import re
import os, sys
import json 
from subprocess import Popen , PIPE


class IPAllocator:
  def __init__(self,network_attachment):
    self.network_attachment = network_attachment

  def get_deploy(self):
    list_envs = []
    process_output = Popen(['kubectl', 'get','deploy', '-A', '-o', 'json'],stdout=PIPE,stderr=PIPE)
    stdout , stderr = process_output.communicate()
    deploy_data = json.loads(stdout.decode('utf-8'))
    #deploy_data['items'][0]['spec']['template']
    #
    # assuming that the (items.*.spec.template.spec.containers.*.env) always stays 
    # and have the :-  
    # HA_MGT_IP: 
    # PKT0_IP:
    # PKT1_IP: 
    # kinds of keys in it 

    ## {I have to do analysis part of IP later}
    try:
      for i in range(len(deploy_data['items'])):
        deploy_template_spec_containers = deploy_data['items'][i]['spec']['template']['spec']['containers']
        for j in range(len(deploy_template_spec_containers)):
          deploy_template_spec_containers_env = json.loads(json.dumps(deploy_template_spec_containers[j]))
          print(deploy_template_spec_containers_env['env']) # assuming HA_MGT: stays in env and env also stays 
    except:
      print("Some Deployment is GHOSTED!!")
      pass
      
   # ['template']['spec']['containers'][0]['env']



if __name__ ==  "__main__":
  new_obj = IPAllocator("ext-static-net-1")
  new_obj.get_deploy()
