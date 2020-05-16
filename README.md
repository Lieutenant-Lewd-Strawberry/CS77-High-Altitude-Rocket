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


# Criticisms

From what I was able to gather, we had 3 major criticisms.

1. Lack of comments. All teams basically lacked in this area. When I had written the code, the team split into 2 subsections. The parser and the graphics. At the end we merge the 2. I didnt have any intention or understanding at first that other students or future students were ever going to read the code and therefore need comments.

2. Large blocky sections of code with too much going on. Hard to read. I agree with the other teams on this portion. The only issue I was having with this, was that all the information in those blocky sections of code was important and necessary. Seperate classes could have been made to combine the blocks and make more logical sections. However, I did not do this because I wanted the modularity to remain. The way it was set up was for explicitness. A person can define a new piece of the GUI, be it text, a graphic object, a new shader, a new texture, or anything and fit them together. Making classes for logical pieces beyond what I had already done would make the GUI less customizable. So base classes for types of objects were made ( mesh, texture, shader, materials ) and is left up to the developers to add what they want. That could include making their own classes to make more logical code sections.

3. The last thing people mentioned was a lack of testing for the 3D rocket section. The problem with this was that we didnt even have access to the hardware needed to make tests for this. We need at lest a few minutes of real flight data to test this section of the code. It is implemented minus the ability to move the rocket. We never had a successful test flight of the 2 test flights we did. The first one had the stages smash into eachother, and the second flight went up 10 feet and flopped. Because of this, we have not test data for pitch, yaw, and roll in respects to the telemetry data, for us to calculate and translate a 3D rocket properly. We just dont know what the numbers mean and it doesnt seem as simple as degrees from 0-360, which is what we need to translate the telemetry to equivalently, to make it work. 

Therefore the only thing we chose to add from the feedback was comments. Especially where the large blocky portions of the code are because since we choose to leave the GUI pieces more up to the developer instead of breaking it up into more classes, it would at least be helpful for someone else to know how to use the code, as it requires lots of numbers.
