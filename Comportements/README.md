# CPP_BE

Partie : Comportements des Bestioles

Ce dépôt contient une simulation de comportement de bestioles, où chaque bestiole est programmée pour adopter l'un des cinq comportements distincts. 

Les détails d'implémentation de chaque comportement sont décrits ci-dessous :
5.1 Grégaire

    Effet : Ajuste sa direction en fonction de la moyenne.
    Détails d’implémentation : Calcule le barycentre des bestioles présentent dans son champ de vision et se dirige vers celui-ci.

5.2 Peureuse

    Effet : Fuit à vive allure dans la direction opposée avant de reprendre sa vitesse de croisière.
    Détails d’implémentation : Inverse sa direction si elle détecte deux bestioles ou plus dans son entourage.

5.3 Kamikaze

    Effet : Attirée par la bestiole la plus proche, tente de l’attaquer en cherchant à provoquer une collision.
    Détails d’implémentation : Se dirige vers la bestiole la plus proche d’elle.

5.4 Prévoyante

    Effet : Estime les trajectoires des bestioles autour d’elle et ajuste sa trajectoire pour éviter d'éventuelles collisions.
    Détails d’implémentation : Estime que les bestioles se dirigent vers leur barycentre et s’en éloigne au maximum.

5.5 Personnalités Multiples

    Effet : Adopte successivement d’autres comportements choisis aléatoirement au cours du temps.
    Détails d’implémentation : Change de comportement toutes les 150 frames de la simulation.

Utilisation :

Dans un environnement linux lancez le Makefile grâce à la commande : 
"make" 
le programme compilera et créera un executable sous le nom de main. La commande "./main" permet l'execution.

Pour tester des comportement spécifique :

