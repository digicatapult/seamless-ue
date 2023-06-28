import csv
import datetime as DT

onlyComputeEvery = 50
ignoreFirst = 10

def make_gpx(csvFilePath, gpxFilePath):
    data = {}
    data = '<gpx xmlns:xsi="http://www.w3.org/2001/XMLSchema-instance"> \n'
   
    with open(csvFilePath, encoding='utf-8') as csvf:
        csvReader = csv.DictReader(csvf)
        index = 0
        computedIndex = 0
        for rows in csvReader:
            if (index % onlyComputeEvery == 0):
                if(computedIndex > ignoreFirst):
                    timeISO = DT.datetime.utcfromtimestamp(float(rows['field.utc_time'])).isoformat()
                    #print(timeISO)
                    new_data = '<wpt lat="' + rows['field.latitude'] + '" lon="' + rows['field.longitude'] + '">\n' + '<ele>' + str(index) + '</ele>\n' + '<name>' + str(index) + '</name>\n'+ '<time>' + timeISO + '</time>\n' + '</wpt>\n'
                    data = data + new_data
                    #print(new_data)
                computedIndex = computedIndex + 1
            index = index + 1
        data = data + "</gpx>"
        with open(gpxFilePath, 'w') as f:
            f.write(data) 
 
make_gpx("C:/Users/GrigorTodorov/Desktop/hnav_msgs.csv", "doneFile.gpx")

print("DONE!")
