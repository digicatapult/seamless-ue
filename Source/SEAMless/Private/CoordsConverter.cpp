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

void UCoordsConverter::GPStoTile
(
    float lat,
    float lon,
    float zoom,
    float& x,
    float& y
)
{
    float n = powf(2, zoom);
    float lat_rad = (lat * PI) / 180;
    x = n * ((lon + 180) / 360);
    y = n * (1 - (log(tan(lat_rad) + sec(lat_rad)) / PI)) / 2;
}

void UCoordsConverter::GPStoTile_Precise
(
    double lat,
    double lon,
    double zoom,
    double& x,
    double& y
)
{
    double n = powf(2, zoom);
    double lat_rad = (lat * PI) / 180;
    x = n * ((lon + 180) / 360);
    y = n * (1 - (log(tan(lat_rad) + sec_precise(lat_rad)) / PI)) / 2;
}

void UCoordsConverter::TileToGPS
(
    float x,
    float y,
    float zoom,
    float& lat,
    float& lon
)
{ 
    float n = powf(2, zoom);
    lon = x / n * 360 - 180;
    float lat_rad = atan(sinh(PI * (1 - 2 * y / n)));
    lat = lat_rad * 180 / PI;
}

void UCoordsConverter::TileToGPS_Precise
(
    double x,
    double y,
    double zoom,
    double& lat,
    double& lon
)
{
    double n = powf(2, zoom);
    lon = x / n * 360 - 180;
    double lat_rad = atan(sinh(PI * (1 - 2 * y / n)));
    lat = lat_rad * 180 / PI;
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

float UCoordsConverter::sec(float x)
{
    return 1 / cos(x);
}

double UCoordsConverter::sec_precise(double x)
{
    return 1.0 / cos(x);
}
