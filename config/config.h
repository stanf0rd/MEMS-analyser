/*  This is "a very default" config file.
 *  It is used when no .conf files in the program folder were found.
 */

#pragma once

#include "conder.h"


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

                        width  = 60;
            Defaults:   height = 30;
                        delta  = 10;

*/ const ConderSizes defaultConderSizes(60, 30, 10); /*
\*****************************************************/


/***************** DEFAULT MAP SIZES *****************\
*/
    const int defaultOffset = 5;        // in pixels
    const int defaultTopOffset = 20;    // in percent
/*
\*****************************************************/


/************** DEFAULT VECTOR SETTINGS **************\
*/
    const int defaultVectorY = 0;  // on top of the map
    // defaultVectorX = ConderMapSize/2
/*
\*****************************************************/