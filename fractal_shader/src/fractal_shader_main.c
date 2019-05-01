/*
 ============================================================================
 Name        : fractal_shader.c
 Author      : cg
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "bmp.h"
#include "orbit.h"
#include "picture.h"
#include "prj_types.h"

Frame f;
OrbitConf conf;
int main(void)
{
    printf("!!!Hello World!!!"); /* prints !!!Hello World!!! */

//    f.pHeight = 1000uL;
//    f.pWidth = 1000uL;
    f.pHeight = 1000uL;
    f.pWidth = 1000uL;
    f.fWidth = 2.0f;
    f.fHeight = 2.0f;
    f.xStart =-2.0f;
    f.yStart = 1.0f;
    allocPicture(&f);

    doTestColoring(&f);
//
    generateBitmapImage("testData.bmp", &f);
    freePicture(&f);

    allocPicture(&f);
    conf.Nmax = 200uL;
    conf.M = 16.0f * 16.0f;
    f.orbitConf = &conf;
    fOrbit(&f);

    doSwColoring(&f);
    generateBitmapImage("Sw.bmp", &f);
    freePicture(&f);

    return EXIT_SUCCESS;
}
