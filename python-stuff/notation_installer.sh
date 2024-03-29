#!/usr/bin/bash
## for Linux AMD (Debian Specific)
#make a directory as workon
#dependency1: this script has to run always as a root 
PROC="$0"
PROCNAME="${PROC%%.*}"
echo "${PROCNAME}:Making a temporary DIRectory (./workon):..."
mkdir workon
cd workon
echo "${PROCNAME}:Installing notation..."
wget https://github.com/notaryproject/notation/releases/download/v1.0.1/notation_1.0.1_linux_amd64.tar.gz
tar -xvzf ./notation_1.0.1_linux_amd64.tar.gz
chmod u+x ./notation
mv ./notation /usr/bin/notation
echo "${PROCNAME}:Installed notation... Usage: notatation --help"
#- setting up the pass-credential-store for notation and docker
echo "${PROCNAME}:Installing docker-credential-pass..."
wget https://github.com/docker/docker-credential-helpers/releases/download/v0.8.1/docker-credential-pass-v0.8.1.linux-amd64
chmod u+x ./docker-credential-pass-v0.8.1.linux-amd64
mv ./docker-credential-pass-v0.8.1.linux-amd64 /usr/bin/
echo "${PROCNAME}:Installed docker-credential-pass!!!"
#- setting up the key for credential store
echo "${PROCNAME}:Setting UP GPG keys ... "
cat >foo <<EOF
     %echo Generating a basic OpenPGP key
     Key-Type: RSA
     Key-Length: 2048
     Subkey-Type: ELG-E
     Subkey-Length: 2048
     Name-Real: Joe Tester
     Name-Comment: with stupid passphrase
     Name-Email: joe@foo.bar
     Expire-Date: 0
     Passphrase: abc
     # Do a commit here, so that we can later print "done" :-)
     %commit
     %echo done
EOF

gpg --batch --generate-key foo 
#we can also check using --list-secret-key
hexID=$(gpg --list-secret-keys --fingerprint | head -4 | tail -1 | sed -e "s/ //g")
#we can take the hexadecimal string ref ID 
echo $hexID
echo "${PROCNAME}:GPG keyring has been set..."

#git clone the pass password store
echo "${PROCNAME}:Installing pass ..."
git clone https://git.zx2c4.com/password-store  
cd password-store ;make install ;cd ../

#TO DO from here 
echo "${PROCNAME}:Initialising the password-store (pass)..."
pass init $hexID

#Creating a config.json file in ~/.docker/config.json 
ls ~/.docker/ 2>1
if [[ "$?" -eq 0 ]];then 
     echo "${PROCNAME}:Creating ~/.docker/ folder"
     mkdir -p ~/.docker/
fi
echo "${PROCNAME}:Creating pass credsStore in config.json!"
echo "{credsStore: "pass"}" ~/.docker/config.json
systemctl restart docker

##Similarily one can set credStore for notation in notation directory 
#Structure (notation dir structure)
#TO DO here 