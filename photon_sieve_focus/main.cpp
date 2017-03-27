/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/*
 * File:   main.cpp
 * Author: byrdie
 *
 * Created on December 1, 2016, 11:08 AM
 */

#include <math.h>
#include <QApplication>
#include <vector>

#include "main.h"

using namespace std;

/* The wavelength and focal length (in meters) is given by */
double lambda = 303.8e-10;
double fl = 2.0;

/* We will take the number of zones to be */
uint numZ = 21;

/* and we will pick the packing factor (greater than one) to be */
double alpha = 1.5;

int main(int argc, char *argv[]) {

    //    QApplication app(argc, argv);

    /* We will count the total number of holes for bragging rights */
    uint total_holes = 0;

    /* Space to store the locations of every hole */
    vector<vector<vector<double>>> holes;

    /* Find the position of each hole in the sieve */
    for (uint i = 1; i <= numZ; i += 2) {

        /* The two radii enclosing an active zone are */
        double zR1 = zRad(i);
        double zR2 = zRad(i + 1);

        /* The width of an active zone is then */
        double zW = zR2 - zR1;

        /* and the radius of a hole in this zone is */
        double hR = zW / 2;

        /* The radius where the center of the circle is located is then */
        double hC = zR1 + hR;

        /* The circumference of a circle of this radius is */
        double hCirc = 2 * M_PI * hC;

        /* The number of holes in each zone can then be determined by the packing factor */
        uint numH = floor(hCirc / (zW * alpha));

        /* Increment the total number of holes for bragging rights */
        total_holes += numH;

        /* Loop over every hole in each zone */
        vector<vector<double>> zone_holes;
        for (uint j = 0; j < numH; j++) {

            /* Calculate the angular position of each hole */
            double hPhi = 2.0 * M_PI * j / numH;
            
            
            
            
        }

    }



    //    return app.exec();
}

/* To get constructive interference at the focus, we need the expression */
double zRad(uint n) {
    return sqrt(n * lambda * fl + (n * n * lambda * lambda) / 4);
}