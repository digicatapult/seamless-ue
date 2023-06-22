// Copyright 2023 Digital Catapult

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "CoordsConverter.generated.h"

/**
 * Geodetic (lon/lat) and Cartesian (x, y) converter blueprint nodes
 */
UCLASS()
class SEAMLESS_API UCoordsConverter : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()
public:
	UFUNCTION(BlueprintPure, meta = (DisplayName = "GPS to Global XY", Keywords = "GPS,XY, Global"), Category = "SEAMless | Converters")
	static void GPStoGlobalXY
	( 
		float lat,
		float lon,
		float top_left_lat, 
		float bottom_right_lat, 
		float& x, 
		float& y
	); 

	UFUNCTION(BlueprintPure, meta = (DisplayName = "GPS to Screen XY", Keywords = "GPS,XY,Screen"), Category = "SEAMless | Converters")
	static void GPStoScreenXY
	(
		float lat,
		float lon,
		float top_left_lat,
		float top_left_lon,
		float bottom_right_lat,
		float bottom_right_lon,
		float top_left_screen_x,
		float top_left_screen_y,
		float bottom_right_screen_x,
		float bottom_right_screen_y,
		float& x,
		float& y
	);

	UFUNCTION(BlueprintPure, meta = (DisplayName = "GPS to Tile", Keywords = "GPS,XY,Tile"), Category = "SEAMless | Converters")
	static void GPStoTile
	(
		float lat,
		float lon,
		float zoom, 
		float& x,
		float& y
	);

	UFUNCTION(BlueprintPure, meta = (DisplayName = "GPS to Tile - Precise", Keywords = "GPS,XY,Tile,Precise"), Category = "SEAMless | Converters")
	static void GPStoTile_Precise
	(
		double lat,
		double lon,
		double zoom,
		double& x,
		double& y
	);

	UFUNCTION(BlueprintPure, meta = (DisplayName = "Tile to GPS", Keywords = "GPS,XY,Tile"), Category = "SEAMless | Converters")
	static void TileToGPS
	(
		float x,
		float y,
		float zoom,
		float& lat,
		float& lon
	);

	UFUNCTION(BlueprintPure, meta = (DisplayName = "Tile to GPS - Precise", Keywords = "GPS,XY,Tile,Precise"), Category = "SEAMless | Converters")
	static void TileToGPS_Precise
	(
		double x,
		double y,
		double zoom,
		double& lat,
		double& lon
	);

	UFUNCTION(BlueprintPure, meta = (DisplayName = "Resolution - meters in pixel - Precise", Keywords = "Res,Meters,Pixel,Precise"), Category = "SEAMless | Converters")
	static void ResMetersInPixel_Precise
	(
		double lat,
		double tileSizeInPixels,
		double zoomLevel,
		double& metersInPixel 
	);

	UFUNCTION(BlueprintPure, meta = (DisplayName = "Get Offset Lat Lon - Precise", Keywords = "Km,Deg,Precise"), Category = "SEAMless | Converters")
	static void GetOffsetLatLon_Precise
	(
		double lat,
		double lon,
		double offset_meters_lat,
		double offset_meters_lon,
		double& new_lat,
		double& new_lon
	);

private:
	static float GetRadiusAtLat(float _lat);
	static double GetRadiusAtLat_Precise(double _lat);
	static float sec(float x);
	static double sec_precise(double x);
};

const float kEarthRadiusEquator = 6378137.0;
const float kEarthRadiusPole = 6356752.314; 