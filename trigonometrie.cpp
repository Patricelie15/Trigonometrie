#include <iostream>
#include <cmath>

const double PI = 3.141592653589793 ;


/*fonction pour calculer la factorielle*/
double factorielle(int n) {
        double fact = 1;
        for (int  i= 1; i<= n; i++){
            fact *= i;
      }
        return fact;
}


//fonction pour calculer la puissance
double puissance(double x , int n) {
        double res = 1 ; 
        for (int i = 0; i < n; i++)
         {
           res = res * x;
        }
        return res;
}


//Fonction pour calculer le sinus :sin(x)= somme allant de i=0 a n de (-1)^i * x^ (2i+1)/(2i+1)!
double sinus (double x, int ordre){
            double sin = 0;
            for (int i = 0; i <= ordre; i++)
            {
                double terme = puissance(-1,i)* puissance(x , 2* i + 1) / factorielle(2 * i + 1);
                sin += terme;
            }
            return sin;
}

// fonction qui calcule le cosinus
double cosinus (double x, int ordre){
            double cos = 0;
            for (int i = 0; i <= ordre; i++)
            {
                double terme = puissance((-1),(i))* puissance(x , 2*i)/  factorielle(2 * i );
                cos += terme;
            }
            return cos;
}

// fonction pour convertir en radian
double convertirenradians(double degrees) {
return degrees * (M_PI / 180 );
}

int main() { 

    double angledegrees, resultat1, resultat2, resultat3;
    int ordre;

    std::cout << " entrer l angle en degre : "<< std::endl;
    std::cin >> angledegrees;

    double angleradians = convertirenradians(angledegrees);


/*entrer l ordre de developpement limite*/
    std::cout << "entrer l ordre de developpement limite :" << std::endl;
    std::cin >> ordre;

/*calcul du sinus,cosinus et tangente*/
    resultat1 = sinus(angleradians,ordre);
    resultat2 = cosinus(angleradians,ordre);
    double tan = resultat1 / resultat2;

std::cout <<"le cosinus de "<< angleradians << "  est : " << resultat2 <<" ,son sinus est: " << resultat1 << " ,sa tangente est " << tan << std::endl;

    return 0;
    
}