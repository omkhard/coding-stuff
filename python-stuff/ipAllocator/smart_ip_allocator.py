"""
This project is made for telling free IP's in a network-attachment for launch
any POD in a k8s cluster.

Solution: 
it will take the net-att name and find out the IP which are not in use
* Assuming that in a POD's deployment [Environment: -| HA_MGT_IP:]
Some thing like this has been described already

Problems faced:
Can't use self in @classmethod

Solved using ,:;

1. applied json and re module for ip_analyser

stored IP's under: deploy.items.[].spec.template.spec.containers.[].env

Future Updates:
* check the network-attachment being used make the decision dynamic
"""
import re
import os, sys
import json 
import logging 
from subprocess import Popen , PIPE
import datetime 

class IPAllocator:
  IPS = {}
  def __init__(self,network_attachment):
    self.network_attachment = network_attachment

  @classmethod # Used decorator here for accessing class attributes
  def get_deploy_info(cls):
    #get deploy info using 'kubectl'  
    process_output = Popen(['kubectl', 'get','deploy', '-A', '-o', 'json'],stdout=PIPE,stderr=PIPE)
    stdout = process_output.communicate()[0] #as its a tuple
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
    for i in range(len(deploy_data['items'])):
      try:
        deploy_template_spec_containers = deploy_data['items'][i]['spec']['template']['spec']['containers']
        for j in range(len(deploy_template_spec_containers)):
          deploy_template_spec_containers_env = json.loads(json.dumps(deploy_template_spec_containers[j]))
          # assuming HA_MGT: stays in env and env also stays 
          for k in range(len(deploy_template_spec_containers_env['env'])):
            cls.IPS[deploy_template_spec_containers_env['env'][k]['name']] = deploy_template_spec_containers_env['env'][k]['value']
      except:
        logger.error("Some Deployments are GHOSTED(Doesn't have 'env' IPs)!!")
        pass
    # log functionality for step checking    
    logger.info("Checked all the 'Deployments' for IP")

   #jq -r ".items[].spec.template[].container"
  @classmethod # Used decorator here for accessing class attributes 
  def ip_analyser(cls,network_attachment) -> list:
    cls.get_deploy_info() # calling deploy info in here
    ipies = cls.IPS
    ips = []
    pattern = r"(\w)+_IP$" # regex for detecting env variables
    for i in ipies:
      if re.match(pattern,i):
        ips.append(ipies[i])
    process_output = Popen(['kubectl','get','network-attachment-definitions',network_attachment,'-o','json'],stdout=PIPE,stderr=PIPE)
    stdout = process_output.communicate()[0] # as its a tuple 
    data = json.loads(stdout.decode('utf-8'))
    rangeStart = json.loads(data["spec"]["config"])["ipam"]["ranges"][0][0]["rangeStart"] #getting end and start out
    rangeEnd = json.loads(data["spec"]["config"])["ipam"]["ranges"][0][0]["rangeEnd"]
    return ips , rangeStart , rangeEnd

if __name__ ==  "__main__":
  # added logger functionality for appending the logs in a file 
  loglevel = logging.INFO
  # added  the initial loglevel as INFO and changing the loglevel during runtime 
  logformat = '%(asctime)s - %(levelname)s - %(message)s'
  logger = logging.getLogger(__name__)
  logger.setLevel(loglevel)
  ch = logging.FileHandler(filename="./allocator.log",mode='a',delay=False)
  ch.setLevel(loglevel)
  formatter = logging.Formatter(logformat)
  ch.setFormatter(formatter)
  logger.addHandler(ch)
  network_attachment_def = "ext-static-net-1"
  new_obj = IPAllocator(network_attachment_def)
  # get the list of ips ,and  detect 
  # how many from the IPrange can be used 
  ips = new_obj.ip_analyser(network_attachment_def)
  logger.info(ips)
