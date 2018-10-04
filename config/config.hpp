/*  This is "a very default" config file.
 *  It is used when no .conf files in the program folder were found.
 */

#pragma once

#include "conder.hpp"
#include "configuration.hpp"

/*************** DEFAULT CONDER SIZES ****************\

        |←-----------   WIDTH   -----------→|

         ___________________________________   _
        |                                   |   ↑
        |                                   |   |
        |___________________________________|   |
                          ↑                     |
                        Delta                     Height
         _________________↓_________________    |
        |                                   |   |
        |                                   |   |
        |___________________________________|  _↓

                        delta  = 10;  ----------.
            Defaults:   height = 30;  ------.   |
                        width  = 60;  --.   |   |
                                        |   |   |
*/ const ConderSizes defaultConderSizes(60, 30, 10); /*
\*****************************************************/


/**************** DEFAULT FIELD SIZES ****************\
*/
    const int defaultOffset = 5;        // in pixels
    const int defaultTopOffset = 30;    // in percent
    const FieldSizes defaultFieldSizes(
        0, 0, defaultOffset, defaultTopOffset
    );
/*
\*****************************************************/


/************** DEFAULT VECTOR SETTINGS **************\
*/
    const int defaultVectorY = 0;  // on top of the map
    // defaultVectorX = ConderMapSize/2
/*
\*****************************************************/


/************** DEFAULT COUNTS SETTINGS **************\
*/
    const int defaultConderCount = 20;
    const int defaultVectorCount = 20;
/*
\*****************************************************/


/*************** LEAKS COUNTER SETTINGS **************\
*/
    const int maxCrossingsCount = 3;
    const int angleCount = 89;
/*
\*****************************************************/


/********************** SUMMARY **********************\
*/
    const Configuration defaultConfig(
        defaultFieldSizes,
        defaultConderSizes,
        defaultConderCount,
        defaultVectorCount
    );
/*
\*****************************************************/
