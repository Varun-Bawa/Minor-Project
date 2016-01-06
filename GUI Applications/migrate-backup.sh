#Migrating within Ubuntu System storing to Original System
#~~~
#~~~
#@author Varun Bawa
#~~~
#~~~
#This program helps you to migrate your System saving the System Environment same
#**Contains 3 steps

#1)Getting all installed packages from original System
#2)Storing the system sources list of apt
#3)Creating archive of these files
#4)Migrate just this tar/archive
#5)Restore and update from this archive.

#Step 1)
sudo dpkg --get-selections | sed "s/.*deinstall//" | sed "s/install$//g" > ~/pkglist
#Step 1 Explained
# dpkg --get-selections
#This command is used to to get the list of package selections and write it to stdout.
#Without a pattern, non-installed packages won't be shown
# sed s/.*deinstall// && sed s/install$//g
#sed (stream editor) isn't an interactive text editor.
#Instead, it is used to filter text, i.e., it takes text input, performs some operation (or set of operations) on it, and outputs the modified text.
#sed is typically used for extracting part of a file using pattern matching or substituting multiple occurrences of a string within a file.
#So with these two PIPED sed it generates an output with deinstall and installed packages to a output

#Once the sed generaes the output then that selection is written to a new file named pkglist
#That pkglist file is stored in home directory of curretnt user ~

#Step 2)
#Storing the sources of apt
#apt sources list files is used to set HIT & IGN links
sudo cp /etc/apt/sources.list ~/sources.list

#Here we are just copying the sources list file of apt to home directory

#Step 3)
#Creating archive of these two files so it is easy to mirgrate a single tar
sudo tar -zcvf migrate.tar.gz ~/sources.list ~/pkglist ~/Desktop ~/Documents ~/Downloads ~/Music ~/Pictures ~/Videos
#In this step we are just creating the archive of sources.list and pkglist

#Step 4)
#It is to be performed manually

#Step 5) is done via restore.sh which is further divided into its sub steps
