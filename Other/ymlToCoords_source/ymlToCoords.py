import sys

def PrintLatLon(_filePath):
    with open(_filePath) as f:
        lines = f.readlines()
        print(lines[1].split("lat: ")[1].replace("\n", ""), ";", lines[2].split("lon: ")[1].replace("\n", ""))  

PrintLatLon(sys.argv[1])
