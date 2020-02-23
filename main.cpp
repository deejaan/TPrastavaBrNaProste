#include <iostream>
#include <vector>
#include <cmath>
#include <stdexcept>
#include <complex>

std::vector<std::complex<int>> RastaviNaProste (int n) {
    // prosti faktor broja n smještam u realni dio kompleksnog broja a stepen u imaginarni
    std::vector<std::complex<int>> result; int pomocni=n, faktor, stepen;
    for (int i=2; i<=n; i++) {
        stepen=0;
        if (pomocni % i == 0) {
            while (pomocni % i == 0) {
                faktor = i; stepen++;
                pomocni /= i;
            }
        result.push_back({faktor, stepen}); 
        }
    }
    return result;
}

void RastavaBroja (int n, int &p, int &q) {
    if (n<1) throw std::domain_error("Broj koji se rastavlja mora biti prirodan");   
    std::vector<std::complex<int>> prostiFaktori=RastaviNaProste(n);
    p=1; q=1; 
    for(auto element : prostiFaktori) {
        if (element.imag()==1) p *= element.real();
        else if (element.imag()==2) q *= element.real();
        else if (element.imag() % 2 == 0) q *= pow(element.real(), element.imag()/2);
        else if (element.imag() % 2 != 0) {
            p *= element.real();
            element = {element.real(), element.imag()-1};
            if (element.imag()==2) q *= element.real();
            else if (element.imag() % 2 == 0) q *= pow(element.real(), element.imag()/2);
        }
    }
}

int main ()
{
  std::cout << "Unesite prirodan broj";
    int n, p, q; std::cin >> n;
    try {
        RastavaBroja(n, p, q);
        std::cout << std::endl << p << " " << q << std::endl;
    }
    catch (std::domain_error e) {
        std::cout << std::endl << "Izuzetak: " << e.what() <<"!" << std::endl;
    }
 	return 0;
}
