# Installation Guide

## Pre-Installation
The GEANT4 toolkit requires several packages to be in the system before it be installed. I strongly recommend to use only packages in the Ubuntu Repository. In case we cannot find the package in the repository or the version in there is too outdated, then I suggest to download the package from the distributor and install into the system.

### Ubuntu Packages
For this version of GEANT4 used on the examples, the requirements are installed using the following commands on the terminal:
```console
sudo apt-get update
sudo apt-get upgrade
sudo apt-get install synaptic
sudo apt-get install libfontconfig1 freetypes2-demos
sudo apt-get install libexpat1-dev libxmu-dev libxmu-headers libxmu6
sudo apt-get install qt5-creator qt5 qt5-default
sudo apt-get install build-essential
sudo apt-get install cmake cmake-qt-gui
sudo apt-get install libxerces-c-dev libxerces-c-doc
sudo apt-get install mesa-common-dev build-essential libglew1.5-dev libglm-dev
sudo apt-get install xorg openbox xauth
```

In case a problem occur when installing the Qt, you can download the open source Qt directly from the website (https://www.qt.io/download-qt-installer?hsCtaTracking=9f6a2170-a938-42df-a8e2-a9f0b1d6cdce%7C6cb0de4f-9bb5-4778-ab02-bfb62735f3e5) and run the following commands in the terminal to install the Qt:
```console
chmod +x qt-unified-linux-x64-3.1.1-online.run
./qt-unified-linux-x64-3.1.1-online.run
```
Don't forget that in the commands above, `qt-unified-linux-x64-3.1.1-online.run` is the name of the downloaded file for the Qt package.

The last step is to check if the versions of cmake>=3.5 and gcc>=5.5. To do so, just type the commands in the terminal:
```console
cmake --version
gcc --version
```

### Installing Python and Jupyter Notebook:
To install **Python 2.7** or Python 3 in Ubuntu, we can simply type the commands in the terminal:

```console
sudo apt-get update
sudo apt-get upgrade
sudo apt-get python2.7 python-pip
```

Similarly, we can install **Python 3**:
```console
sudo apt-get update
sudo apt-get upgrade
sudo apt-get python3 python-pip
```

Now, to install Jupyter Notebook, we follow the description given in the [website](https://jupyter.org/install.html):

If you have **Python 3** installed:
```console
python3 -m pip install --upgrade pip
python3 -m pip install --user jupyter
```

If you have **Python 2.7** installed:
```console
python -m pip install --upgrade pip
python -m pip install --user jupyter
```

Now Jupyter Notebook is installed. To run the notebook, type in the terminal the following command and an instance of jupyter notebook will open in your web browser:

```console
jupyter notebook
```

The last step is to make sure that your jupyter notebook recognizes the kernels correctly. To guarantee that the kernels are correctly recognized, run the following commands in your terminal to install the kernels accordingly to your python version:

**Python 2**:
```console
python -m ipykernel install --user
```
or
```console
python2 -m ipykernel install --user
```

**Python 3**:
```console
python3 -m ipykernel install --user
```


## Installing GEANT4
*Remark*: For a full guide on how to install GEANT4, please refer to the official installation guide at http://geant4-userdoc.web.cern.ch/geant4-userdoc/UsersGuides/InstallationGuide/html/

Here on this guide, I created a folder on `~/Documents/` called `GEANT4` and all the GEANT4 files (source code, build, installation) are performed inside this folder.

The easy installation steps are:

1. Download the latest GEANT4 source code `geant4.10.05.tar.gz` from the CERN website: https://geant4.web.cern.ch/support/download
2. Extract the files from the source package inside the folder `~/Documents/GEANT4/geant4.10.05.p01/`.
3. Now, create a directory at `~/Documents/GEANT4/` with the name `geant4.10.05.p01-build` such that we have `~/Documents/GEANT4/geant4.10.05.p01-build/`. You can use the command `mkdir geant4.10.05.p01-build` to create the directory.
4. Enter the `geant4.10.05.p01-build` folder: `cd geant4.10.05.p01-build` and type:

```console
cmake -DCMAKE_INSTALL_PREFIX=~/Documents/GEANT4/geant4.10.05.p01-install -DCMAKE_BUILD_TYPE=RelWithDebInfo -DGEANT4_BUILD_MULTITHREADED=ON -DGEANT4_INSTALL_DATA=ON -DGEANT4_USE_OPENGL_X11=ON -DGEANT4_USE_GDML=ON -DGEANT4_USE_QT=ON ~/Documents/GEANT4/geant4.10.05.p01/
```
This command configures cmake to use the source files of GEANT4, activates the viewers (e.g. X11, QT, GDML), sets GEANT4 to use multithreads and to download dependencies from the internet and points to the GEANT4 installation directory `~/Documents/GEANT4/geant4.10.05.p01-install`. No need to create such directory. It is created automatically when compiling and installing GEANT4.
5. Still inside the `geant4.10.05.p01-build` folder, we type in the terminal:

```console
make -j 4
make install
```
Note: you can substitute the number 4 with the amount of processors you would like to use to compile and install GEANT4. The more processors you use, faster is the compiling and installation.

Now GEANT4 should be installed successfully in the directory `~/Documents/GEANT4/geant4.10.05.p01-install`.


## Installing ROOT and PyROOT
To use the [ROOT Data Analysis Framework](https://root.cern.ch/downloading-root), we can install the ROOT framework binary distributions compiled for Ubuntu LTS 16.04.

1. Download the ROOT binary distribution for Ubuntu LTS 16.04: https://root.cern/download/root_v6.18.04.Linux-ubuntu16-x86_64-gcc5.4.tar.gz
2. Create the directory `root` inside the GENAT4 folder such that: `~/Documents/GEANT4/root/`
3. Extract all files from the downloaded file `root_v6.18.04.Linux-ubuntu16-x86_64-gcc5.4.tar.gz` into the directory: `~/Documents/GEANT4/root/`
4. Test if ROOT works in your system by running the file `thisroot.sh`:

```console
. ~/Documents/GEANT4/root/bin/thisroot.sh
```
and then type on the terminal `root`. This should open the ROOT shell. A new ROOT gui can be open by typing in the ROOT shell the command:

```console
new Tbrowser()
```

5. Finally, you need to include the necessary paths in the ~/.bashrc file (every time you open a terminal, it loads ~/.bashrc). Open the ~/.bashrc file using your favorite text editor, for example:

```console
nano ~/.bashrcsuccessfully
```

and include the following lines:

```console
export ROOTSYS=~/Documents/GEANT4/root/
export PATH=$ROOTSYS/bin:$PATH
export LD_LIBRARY_PATH=$ROOTSYS/lib:$LD_LIBRARY_PATH
export PYTHONPATH=$ROOTSYS/lib:$PYTHONPATH
```

Save and close the ~/.bashrc file. Then, source the file: `source ~/.bashrc`.

Note: you can also include the `export` commands in the ~/.bash_profile.

## Running the first example
To test if your GEANT4 installation was successful, let's build the first example.

1. In the terminal window, you always need first to run the `.sh` script in the GEANT4 folder:

```console
. ~/Documents/GEANT4/geant4.10.05.p01-install/bin/geant4.sh
```

2. Open the first example directory:

```console
cd ~/Documents/GEANT4/geant4-projects/GEANT4\ Examples/Energy\ Deposition/
```

3. Create a build directory:

```console
mkdir edep-build
```

4. Enter the build directory:

```console
cd edep-build/
```

5. Now, inside the build directory, we should configure the cmake. Change the folders according to your directory structure.

```console
cmake -DGEANT4_DIR=~/Documents/GEANT4/geant4.10.05.p01-ins
tall/lib/Geant4.10.05.p01/ ~/Documents/GEANT4/geant4-projects/GEANT4\ Examples/Energy\ Deposition/
```

After entering this command, a similar output as the following one should be seen. It is important to have no error.

```console
-- The C compiler identification is GNU 5.5.0
-- The CXX compiler identification is GNU 5.5.0
-- Check for working C compiler: /usr/bin/cc
-- Check for working C compiler: /usr/bin/cc -- works
-- Detecting C compiler ABI info
-- Detecting C compiler ABI info - done
-- Detecting C compile features
-- Detecting C compile features - done
-- Check for working CXX compiler: /usr/bin/c++
-- Check for working CXX compiler: /usr/bin/c++ -- works
-- Detecting CXX compiler ABI info
-- Detecting CXX compiler ABI info - done
-- Detecting CXX compile features
-- Detecting CXX compile features - done
-- Configuring done
-- Generating done
CMake Warning:
  Manually-specified variables were not used by the project:

    GEANT4_DIR


-- Build files have been written to: /home/fcsalgado/Documents/GEANT4/geant4-projects/GEANT4 Examples/Energy Deposition/edep-build
```

6. Still inside the build directory, we can `make`:

```console
make -j 4
```

If the make command is performed without error, it means that we have configured GEANT4 correctly. A similar output should be seen:

```console
Scanning dependencies of target TestEm3
[  5%] Building CXX object CMakeFiles/TestEm3.dir/TestEm3.cc.o
[ 10%] Building CXX object CMakeFiles/TestEm3.dir/src/RunAction.cc.o
[ 15%] Building CXX object CMakeFiles/TestEm3.dir/src/Run.cc.o
[ 20%] Building CXX object CMakeFiles/TestEm3.dir/src/StepMax.cc.o
[ 30%] Building CXX object CMakeFiles/TestEm3.dir/src/PhysicsListMessenger.cc.o
[ 30%] Building CXX object CMakeFiles/TestEm3.dir/src/DetectorConstruction.cc.o
[ 35%] Building CXX object CMakeFiles/TestEm3.dir/src/HistoManager.cc.o
[ 40%] Building CXX object CMakeFiles/TestEm3.dir/src/PrimaryGeneratorAction.cc.o
[ 45%] Building CXX object CMakeFiles/TestEm3.dir/src/RunActionMessenger.cc.o
[ 50%] Building CXX object CMakeFiles/TestEm3.dir/src/PhysListEmStandard.cc.o
[ 55%] Building CXX object CMakeFiles/TestEm3.dir/src/EventAction.cc.o
[ 60%] Building CXX object CMakeFiles/TestEm3.dir/src/EmAcceptance.cc.o
[ 65%] Building CXX object CMakeFiles/TestEm3.dir/src/PrimaryGeneratorMessenger.cc.o
[ 70%] Building CXX object CMakeFiles/TestEm3.dir/src/SteppingVerbose.cc.o
[ 75%] Building CXX object CMakeFiles/TestEm3.dir/src/PhysicsList.cc.o
[ 80%] Building CXX object CMakeFiles/TestEm3.dir/src/DetectorMessenger.cc.o
[ 85%] Building CXX object CMakeFiles/TestEm3.dir/src/ActionInitialization.cc.o
[ 90%] Building CXX object CMakeFiles/TestEm3.dir/src/SteppingAction.cc.o
[ 95%] Building CXX object CMakeFiles/TestEm3.dir/src/TrackingAction.cc.o
[100%] Linking CXX executable TestEm3
[100%] Built target TestEm3
```

7. The last step is to execute the compiled example. To run the application, execute the following command inside the build directory:

```console
./TestEm3
```
