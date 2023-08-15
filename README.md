# seamless-ue

Unreal project for [SEAMless](https://gtr.ukri.org/projects?ref=10011940) - Subsea Enhanced Autonomous Mapping. An application that visualises 3D mapping to deliver the 'Google Maps' of subsea.

## Getting started

### Prerequisites

- [Unreal Engine 5.2](https://www.unrealengine.com/en-US/download)
- [Cloud Compare 2.12.4](https://www.danielgm.net/cc/) for `.ply` -> `.las` conversion, installed in the default folder (C:\Program Files\CloudCompare). 
 #### Warning: do not use any other version of Cloud Compare that is not 2.12.4 as this will BREAK your build :warning::warning:
  [Get the correct version here](https://www.danielgm.net/cc/release/CloudCompare_v2.12.4_setup_x64.exe)
- [Mapbox](https://www.mapbox.com/) api key


### Instructions
<details>
<summary>UI and UX 🐋</summary>
<br> 
Work-in-Progress
</details>

<details>
<summary>General Information ℹ️</summary>
<br> 
Work-in-Progress
</details>

<details>
<summary>Packaging 📦</summary>
<br>
- Package the project for Windows via Unreal Engine 5.2 (Platforms>Windows>Package Project)
- Copy the "Other" folder from this repository to the package folde, it has to be inside the SEAMless folder:
**[build folder]/SEAMless/**
- Make sure this folder includes the tokens.json file (Please follow the **Mapbox API** instructions)
</details>

<details>
<summary>Mapbox 🌍</summary>
<br>
To use the mapping features you need a mapbox api key. 
Please create a file name "tokens.json" inside the "Other" folder. The file should contain your api key and be structured like this: 

`{
"mapbox":"yourKeyHere"
}`

</details>


<details>
<summary>List of external tools 🧰️</summary>
<br>
In order to parse and generate files unsupported by Unreal Engine this project uses a few external python scripts (built to executables) and a bat file. 

All external tools and scripts can be found in the "Other" folder in this repository. 

This is a list of exe files/python files/bat files used:
- checkType.exe - used to check the .ply file pass type (pass 1 (mbes) and pass2 (subslam))
- convertCSVtoJSON.exe - converts the submarine .csv path file to a .json file (supported by Unreal Engine)
- createYMLfromBoundingBox.exe - used to generate bounding_box.yml files necessary for pass 2
- ymlToCoords.exe - parse ned_origin.yml files and outputs lat and lon
- ConvertPLYToLAS.bat - uses CloudCompare to convert .ply files to .las files (supported by Unreal Engine)

Executable sources: 
- checkType.exe source file: "Other/checkType_source/checkType.py"
- convertCSVtoJSON.exe source file:: "Other/convertCSVtoJSON_source/convertCSVtoJSON.py"
- createYMLfromBoundingBox.exe source file: "Other/createYMLfromBoundingBox_source/createYMLfromBoundingBox.py
- ymlToCoords.exe source file: "Other/ymlToCoords_source/ymlToCoords.py"
</details>

<details>
<summary>Building external tools from source 🛠</summary>
<br>
- install pyinstaller and all other prerequisites for the python file you're trying to build 
- Generate executables via command line with: `pyinstaller my_script.py --onefile`
</details>

### Walkthroughs

Work-in-Progress