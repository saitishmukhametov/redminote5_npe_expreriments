# redminote5_npe_expreriments
OpenCL, NPE on Snapdragon 636



# Setting Up ADB and Code-Server with Termux on Android

## Install ADB on PC
1. Download and install ADB (Android Debug Bridge) on your PC.

## Install Termux on Android Phone
1. Download and install Termux from the Google Play Store or F-Droid.

## On the Phone:
### Give USB Debugging Permissions
1. Go to your phone's settings, navigate to 'Developer options', and enable 'USB debugging'.

### Set Up Termux
```bash
pkg update
pkg upgrade
pkg install openssh
sshd
```

### Get Username and Set Password
```bash
whoami # Get the username
passwd # Set the password
```

## On the PC:
### Check ADB Devices
1. Open a terminal or command prompt and run:
```bash
adb devices
```

### Forward Port for SSH
```bash
adb forward tcp:8022 tcp:8022
```

### Connect via SSH
```bash
ssh u0_aXXX@localhost -p 8022 # Replace 'u0_aXXX' with your username from Termux
```

## On the Phone:
### Install Additional Packages
```bash
pkg install tur-repo
pkg install code-server
```

### Run Code-Server on a Different Port
1. Start code-server on a different port (replace `diffport` with your desired port number).

### Forward Port for Code-Server
```bash
adb forward tcp:diffport tcp:diffport # Replace 'diffport' with your port number
```

## Access Code-Server from PC Browser
1. Open a web browser and navigate to `localhost:diffport` (replace `diffport` with your port number).
