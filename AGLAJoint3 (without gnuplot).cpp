#include <iostream>
#include <iomanip>
#include <vector>
#include <cmath>

using namespace std;


int main() {
    cout << fixed << setprecision(2);
    
    double V0, K0;
    cin >> V0 >> K0;
    
    double alpha1, beta1, alpha2, beta2;
    cin >> alpha1 >> beta1 >> alpha2 >> beta2;
 
    double time;
    cin >> time;

    double points;
    cin >> points;

    double step = time / points;

	double _V0 = (alpha2 / beta2);
    double _K0 = (alpha1 / beta1);

    double v0 = V0 - _V0;
    double k0 = K0 - _K0;

    vector<double> Vs;
    vector<double> Ks;

    cout << "t:\n";

    for (double i = 0; i <= time; i += step){
        cout << i << " ";
        Vs.push_back(_V0 + v0 * cos(sqrt(alpha1 * alpha2) * i) - k0 * ((sqrt(alpha2) * beta1) / (beta2 * sqrt(alpha1))) * sin(sqrt(alpha1 * alpha2) * i));
        Ks.push_back(_K0 + v0 * ((sqrt(alpha1) * beta2) / (beta1 * sqrt(alpha2))) * sin(sqrt(alpha1 * alpha2) * i) + k0 * cos(sqrt(alpha1 * alpha2) * i));
    }

    cout << "\nv:\n";
    for (int i = 0; i < Vs.size(); i++){
        cout << Vs[i] << " ";
    }

    cout << "\nk:\n";
    for (int i = 0; i < Ks.size(); i++){
        cout << Ks[i] << " ";
    }
    

    return 0;
}
