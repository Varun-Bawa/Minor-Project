#Migrating within Ubuntu System storing to Original System
#~~~
#~~~
#@author Varun Bawa
#~~~
#~~~
#Once we are done with taking the backup and manually moving the archive now we'll restore it
#This have only three steps rest the Linux Distribution will help us

#Step 1)
#Untar the archive to get the sources.list file and pkglist
sudo tar xv -C ~ -f migrate.tar 

#Step 2)
#Replacing the sources.list file
sudo cp ~/sources.list /etc/apt/sources.list

#Step 3)
#Installing all the packages to new system using apt
sudo apt update && cat pkglist | xargs sudo apt install 
#->apt update && cat pkglist 
# This command is used to update the ubuntu system with pkglist file links as argument
# xargs is used to build and execute the pkglist current line
# Then we install the packages using apt install

#Then you are all good to go
echo 'Thank-You For Using OSS Backup'
echo ''
echo 'Program Maintained by Varun Bawa'
echo ''
echo 'Feel free to contact at varunbawa62ak@gmail.com'
echo 'Read my blog'
echo 'innovativebit.blogspot.in'
