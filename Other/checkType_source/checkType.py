import numpy
import sys
from plyfile import PlyData, PlyElement

def CheckPLYFileType(_path):
    plydata = PlyData.read(_path)
    elementCount = len(plydata.elements[0][0])

    if(elementCount == 3):
        print("Pass1")
    elif(elementCount == 6):
        print("Pass2")
    else: print("Unknown")

  
CheckPLYFileType(sys.argv[1])
