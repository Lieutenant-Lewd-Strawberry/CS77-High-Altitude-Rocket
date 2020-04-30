## CS77-High-Altitude-Rocket

# Setup Instructions

All libraries are cross platform compatible with existing binaries for Windows, MacOS, and Linux. The repo only includes Windows libraries due to free user space limits. All libraries were compiled for Windows 10 using Visual Studio Enterprise 2019 in x64 mode. A PC with an OpenGL compatible graphics card is required. 

To test on a seperate platform, you must download, compile, and link the STB, GLFW, GLEW, and GLM C++ libraries for your specific OS. 

To test and run this software solely base on the contents of this repo, a PC running Windows 10 is required, and an installation of Visual Studio 2019 with the C++ development tools downloaded.  

* Run Visual Studio 2019. 
* Click "File" and then "Open".
* Navigate to the "Rocket GUI.sln" file within the repo's top level and open it.
* A visual studio solution will be loaded along with a visual studio project both named "Rocket GUI" and all its associated headers, sources, and resource files.
* Right click on the "Rocket GUI" project in the solution explorer, and click on properties.
* Make sure that Configuration is set to "All Configurations".
* Make sure Platorm is set to "x64"
* Under "Configuration Properties->General->C++ Language Standard", ensure that "ISO C++ Standard (std:c++17)" is checked.
* Under "Configuration Properties->General->Platform Toolkit", ensure that "Visual Studio 2019 v142" is checked.
* Under "Configuration Properties->General->Windows SDK Version", ensure that "10.0.xxxxx.x" is checked.
* Under "Configuration Properties->C/C++->General", click Additional Include Directories and a down arrow will appear on the right. Click it and click edit. Ensure there are 4 entries in the top list. "$(SolutionDir)\includeWIN\STB", "$(SolutionDir)\includeWIN\GLEW", "$(SolutionDir)\includeWIN\GLM", "$(SolutionDir)\includeWIN\GLFW". If not, add them by clicking the folder icon at the top right and typing it in exactly as above.
* Under "Configuration Properties->C/C++-->->Language->C++ Language Standard", ensure that "ISO C++ Standard (/std:c++17)" is checked.
* Under "Configuration Properties->Linker->General", click Additional Library Directories and a down arrow will appear on the right. Click it and click edit. Ensure there is 1 entry in the top list. "$(SolutionDir)\libWIN". If not, add it by clicking the folder icon at the top right and typing it in exactly as above.
* Under "Configuration Properties->Linker->Input", click Additional Dependencies and a down arrow will appear on the right. Click it and click edit. Ensure there is 3 entries in the top list. "opengl32.lib", "glfw3.lib", "glew32.lib". If not, add them by clicking in the box and typing them in on seperate lines.

After all ensuring all project properties are set as above, make sure the project is set to build in x64 mode. At the top to the left of the compile button, choose x64 from the dropdown. The compile button will be labled as "Start" or "Local Windows Debugger" depending on if you have it set to compile in debug or release mode. You can choose either option. 

Lastly, compile the code by pressing the "Start/Local Windows Debugger" button and it will build and run automatically.
