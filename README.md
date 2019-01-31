# InnoSetup5
InnoSetup5 for Linux 




Setting up the Inno Setup compiler on Debian
Posted on 01-02-2019 à 23h00 by Nadir Fouka

I’m currently setting up a nightly build system for Quasar on my Linux box which is running Debian. This system also cross-compiles Quasar for Windows.
The Windows version of Quasar is going to be available in two fashions: one self-contained, portable version and one version that can be installed.
I’m not a huge fan of installers. But when it comes to creating a setup program for a given Windows application I’m quite accustomed to Inno Setup having used it for years. Unfortunately there is no native Linux version of the Inno Setup compiler available for Linux. NSIS exists as package for Debian but I am not fond of using it, largely because I am a Delphi guy. :)
So, here is a small guide on how to get the Inno Setup compiler up and running on Debian:

First step is to install Wine either as super user or by using sudo:

    sudo apt-get install wine  

As normal user fire up your X server and your favourite terminal application and get the latest Inno Setup QuickStart pack:

    mkdir /tmp/innosetup  
    cd /tmp/innosetup  
    wget http://files.jrsoftware.org/ispack/ispack-5.2.3.exe  
    wine ./ispack-5.2.3.exe  

This will start the installer in Wine. Note, for the installation you will need a running X11 server since the installer obviously is graphical. If you have not set up Wine before, the default location C:\Program Files\Inno Setup 5 will install to ~/.wine/drive_c/Programme/Inno Setup 5.

Luckily the Inno Setup compiler offers a command line interface, ISCC.exe, which will run in Wine without the necessity of having a X server running. So it is ideally suited for automated runs.

Here is a simple wrapper shell script called iscc:

    #!/bin/sh  
    unset DISPLAY  
    scriptname=$1  
    [ -f "$scriptname" ] && scriptname=$(winepath -w "$scriptname")  
    wine "C:\Program Files\Inno Setup 5\ISCC.exe" "$scriptname" "$2" "$3" "$4" "$5" "$6" "$7" "$8" "$9"  

I installed this script in my local bin directory (~/bin) and added it to the PATH environment variable.
This will allow running the Inno Setup compiler from anywhere and it also makes it very easy to integrate into a build script. You can even feed a script via stdin, e.g. something like:

    iscc - < ./myscript.iss  
