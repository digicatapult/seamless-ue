// Copyright 2023 Digital Catapult


#include "CoordsConverter.h"

void UCoordsConverter::GPStoGlobalXY
(
    float lat, 
    float lon, 
    float tl_lat, 
    float br_lat, 
    float& x, 
    float& y
)
{    
    float radius = GetRadiusAtLat(lat);
    x = radius * lon * cos((tl_lat + br_lat) / 2);
    y = radius * lat; 
}

void UCoordsConverter::GPStoScreenXY
(
    float lat, 
    float lon, 
    float tl_lat, 
    float tl_lon, 
    float br_lat, 
    float br_lon, 
    float tl_scr_x,  
    float tl_scr_y, 
    float br_scr_x,  
    float br_scr_y, 
    float& x, 
    float& y
)
{
    float posX = 0, posY = 0;  
    GPStoGlobalXY(lat, lon, tl_lat, br_lat, posX, posY);
     
    float tlX = 0, tlY = 0; 
    GPStoGlobalXY(tl_lat, tl_lon, tl_lat, br_lat, tlX, tlY);
    float brX = 0, brY = 0; 
    GPStoGlobalXY(br_lat, br_lon, tl_lat, br_lat, brX, brY);
     
    float perX = ((posX - tlX) / (brX - tlX)); 
    float perY = ((posY - tlY) / (brY - tlY)); 
     
    x = tl_scr_x + (br_scr_x - tl_scr_x) * perX; 
    y = tl_scr_y + (br_scr_y - tl_scr_y) * perY; 
}

float UCoordsConverter::GetRadiusAtLat(float _lat)
{
    float lat_rad = _lat * (PI / 180);
    float f1 = pow((pow(kEarthRadiusEquator, 2) * cos(lat_rad)), 2);
    float f2 = pow((pow(kEarthRadiusPole, 2) * sin(lat_rad)), 2);
    float f3 = pow((kEarthRadiusEquator * cos(lat_rad)), 2);
    float f4 = pow((kEarthRadiusPole * sin(lat_rad)), 2);
     
    return sqrt((f1 + f2) / (f3 + f4));
}

