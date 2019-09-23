# GEANT4 Projects and Tutorials

Collection of projects and tutorials using [GEANT4](https://geant4.web.cern.ch/) toolkit and [ROOT Data Analysis Framework](https://root.cern.ch/) from CERN.

The projects are based on the examples provided already together with GEANT4 toolkit, but adapted for the projects of the [Laserteilchenbeschleunigung (Laser Particle Acceleration - LPA) group](https://www.ioq.uni-jena.de/lpa.html) of the Institut für Optik und Quantenelektronik, Friedrich-Schiller-Universität Jena.

## Requirements and Installation
The projects and examples are based on the following versions of GEANT4 and ROOT Framework. The examples may work also on old versions.
* [GEANT4 10.05.p01](https://geant4.web.cern.ch/support/download)
* [ROOT Framework 6.18/04](https://root.cern.ch/content/release-61804)

The data analysis is performed using the output file `.root` given by each simulation and the combination of python + jupyter notebook + PyROOT. Therefore, it is required to have Python 2.7 installed and a working Jupyter Notebook capable of loading the Pyhton2 kernel.

Since here we use the binary file of ROOT distributed by CERN which is compiled for Python 2.7, we should use the same version of python for analyzing data using PyROOT. However, if one desires to use Python 3, it is necessary to download the ROOT source files and compile it for Python 3.

The installation guide can be found on [this file](./Ubuntu-Installation-Guide.md). All commands are based on Debian based Linux distributions, once most of the people in our group uses Ubuntu LTS 16.04 operational system.

## Projects descriptions
Example projects can be found in the folder `GEANT4 Examples/`. These projects are based on the GEANT4 examples provided with the toolkit installation, but they are modified according to the requirements of the projects of the LPA group as mentioned above.

A list of the projects is available below. All projects have basic post-processing notebooks in the directory `GEANT4 Examples/Post-Processing Notebooks/`.

* **Stopping Power**: Defines a F2 lead-glass material and calculates the stopping power of the material for a 2 GeV electron traveling trough the material. For the stopping power be compared with the stopping power value provided by the NIST E-Star database, the generation of secondary particles are disabled for this study.
* **Energy deposition**: Defines a 100 cm F2 lead-glass material and calculates the energy deposited by a single 2 GeV electron traveling through the glass block. This example shows how to get the longitudinal profile of energy distribution in the glass block. It is included the generation of secondaries particles.
