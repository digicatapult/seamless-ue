def GenerateYML(_outputYMLFileDir, bottom_left_lat, bottom_left_lon, top_right_lat, top_right_lon):
    lines = ['bounding_box:',
             '\n  bottom_left:',
             '\n    lat: ' + str(bottom_left_lat),
             '\n    lon: ' + str(bottom_left_lon),
             '\n  top_right:',
             '\n    lat: ' + str(top_right_lat),
             '\n    lon: ' + str(top_right_lon) 
             ]
    with open(_outputYMLFileDir, 'w') as f:
        f.writelines(lines)
    print("ymlFileGenerated!")

GenerateYML(sys.argv[1], sys.argv[2], sys.argv[3], sys.argv[4], sys.argv[5])
#GenerateYML("newFile.yml", 12.2, 13.3, 14.4, 15.5) 
