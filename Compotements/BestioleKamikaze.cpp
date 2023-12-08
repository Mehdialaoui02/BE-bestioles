#include "Milieu.h"
#include "BestioleKamikaze.h"
#include <iostream>
#include <cmath>

#ifndef M_PI
    #define M_PI 3.14159265358979323846
#endif

BestioleKamikaze::BestioleKamikaze() : Bestiole(), groupe(3) {
}

BestioleKamikaze::BestioleKamikaze(const BestioleKamikaze &bg) : Bestiole(bg), groupe(bg.groupe) {
}

BestioleKamikaze::~BestioleKamikaze(){
}


void BestioleKamikaze::rejoindreGroupe(int groupe) {
    this->groupe = groupe;
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
    // std::cout << "Distance min " << distanceMin << "\n" << std::endl;
    // std::cout << "Plusproche : x , y  " << *xproche << "," << *yproche << std::endl;
}


void BestioleKamikaze::Changedir(Milieu &milieu) {

    // Obtenir la bestiole la plus proche
    int xproche;
    int yproche;
    PlusProche(milieu,&xproche,&yproche);
    //std::cout << "Changedir : x , y  " << xproche << "," << yproche << std::endl;

    couleur[ 0 ] = static_cast<int>( 40 );
    couleur[ 1 ] = static_cast<int>( 163 );
    couleur[ 2 ] = static_cast<int>( 116 );

    double newOrient;
    if (xproche != -1 || yproche != -1) {
        if (xproche - getX() == 0) {
            newOrient = 0;
        } 
        else {
            newOrient = - std::atan2((yproche - getY()) , (xproche - getX()));
            setOrientation(newOrient);
            std::cout << "New Orient " << newOrient << "\n" << std::endl;
        }
        }     
}


    void BestioleKamikaze::action(Milieu &monMilieu) {
        Changedir(monMilieu);
        bouge(monMilieu.getWidth(),monMilieu.getHeight());
    }   






