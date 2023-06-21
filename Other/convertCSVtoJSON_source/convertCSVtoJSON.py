import csv
import json

def make_json(csvFilePath, jsonFilePath):
    data = {}
    with open(csvFilePath, encoding='utf-8') as csvf:
        csvReader = csv.DictReader(csvf)
        index = 0
        for rows in csvReader:
            key = index #rows['timestamp']
            data[key] = rows
            index = index + 1
    with open(jsonFilePath, 'w', encoding='utf-8') as jsonf:
        jsonf.write(json.dumps(data, indent=4))
 
make_json(sys.argv[1], sys.argv[2])

print("DONE!")
