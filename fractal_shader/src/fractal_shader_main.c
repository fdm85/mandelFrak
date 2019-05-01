/*
 ============================================================================
 Name        : fractal_shader.c
 Author      : cg
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdlib.h>
#include "bmp.h"
#include "orbit.h"
#include "picture.h"
#include "prj_types.h"
#include "config.h"


Frame f;
OrbitConf conf;
int main(int argc, char *argv[])
{
    allocPicture(&f);

    doTestColoring(&f);
//
    generateBitmapImage("testData.bmp", &f);
    freePicture(&f);


    f.orbitConf = &conf;

    if(!loadCfgSucceedes(&f, argc, argv))
    {
        return EXIT_FAILURE;
    }
    allocPicture(&f);

    fOrbit(&f);

    doSwColoring(&f);
    generateBitmapImage("Sw.bmp", &f);
    freePicture(&f);

    return EXIT_SUCCESS;
}
