#include "Milieu.h"
#include "BestioleKamikaze.h"
#include <iostream>

#ifndef M_PI
    #define M_PI 3.14159265358979323846
#endif

BestioleKamikaze::BestioleKamikaze() : Bestiole(), groupe(1) {
}

BestioleKamikaze::BestioleKamikaze(const BestioleKamikaze &bg) : Bestiole(bg), groupe(bg.groupe) {
}

BestioleKamikaze::~BestioleKamikaze(){
}


void BestioleKamikaze::PlusProche(Milieu &monMilieu, int* xproche, int* yproche) {
    const std::vector<std::unique_ptr<Bestiole>> &bestioles = monMilieu.getBestioles();
    *xproche = -1;
    *yproche = -1;

    double distanceMin = 100000;

    for (const std::unique_ptr<Bestiole> &bPtr : bestioles) {
        // calculer la distance entre b et chaque autre bestiole
        const Bestiole &b = *bPtr; // Dereference the smart pointer
        double distance = std::sqrt(std::pow(getCoords().first - b.getCoords().first, 2) +
                                    std::pow(getCoords().second - b.getCoords().second, 2));
        if (distance < distanceMin && distance != 0) {
            distanceMin = distance;
            *xproche = b.getX(); 
            *yproche = b.getY();
             
        }
    }
}


void BestioleKamikaze::setDirection(Milieu &milieu) {

    // Obtenir la bestiole la plus proche
    int xproche;
    int yproche;
    PlusProche(milieu,&xproche,&yproche);

    couleur[ 0 ] = static_cast<int>( 40 );
    couleur[ 1 ] = static_cast<int>( 163 );
    couleur[ 2 ] = static_cast<int>( 116 );

    vitesse = 5;

    double newOrient;
    // cout << (xproche - getX()) << endl;
    // cout << (yproche - getY()) << endl;
    if (xproche != -1 || yproche != -1) {
        if (xproche - getX() < 10 ) {
            newOrient = M_PI;
            setOrientation(newOrient);
        } 
        else {
            
            newOrient = 2*M_PI - atan((yproche - getY())/(xproche - getX()));
            cout << (xproche - getX()) << endl;
            setOrientation(newOrient);
        }
        }     
}


    void BestioleKamikaze::action(Milieu &monMilieu) {
        setDirection(monMilieu);
        bouge(monMilieu.getWidth(),monMilieu.getHeight());
    }   






