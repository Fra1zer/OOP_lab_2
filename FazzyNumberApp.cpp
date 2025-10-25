#include "FazzyNumber.h"

int main(){
    FazzyNumber num1, num2(5, 4, 6);

    FazzyNumber t1(3.5, 0.1, 0.1), t2;

    cout << t1 << endl;

    cin >> t2;

    cout << t2 << endl;
    
    cout << num2 << endl;
    cout << num1 + num2 << endl;
    cout << num2 - num1 << endl;

    bool check1 = num1 == num2, check2 = num1 != num2;

    cout << check1 << endl;
    cout << check2 << endl;
    return 0;
}
