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

private:
	static float GetRadiusAtLat(float _lat);

};

const float kEarthRadiusEquator = 6378137.0;
const float kEarthRadiusPole = 6356752.314; 