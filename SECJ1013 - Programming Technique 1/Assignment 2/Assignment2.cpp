//MURSYIDAH BINTI JAHIDI (A25CS0286)
//BALQIS BATRISYA BINTI JALALUDDIN (A25CS0196)
//28 DECEMBER 2025
//SET 1
#include <iostream>
using namespace std;

double calcBMR(int a, double h, double w, char g){
    double b;
    if((g == 'M') || (g == 'm')){
        b = (10*w) + (6.25*h) - (5*a) + 5;
    }
    else{
        b = (10*w) + (6.25*h) - (5*a) - 161;
    }
    return b;
}

void dispCalActivity(double calories){
    cout << "Daily calorie needs based on activity level" << endl;
    cout << endl;
    cout << "Activity Level\t\t\t\t\t\tCalorie" << endl;

    int a1 = calories * 1.2;
    cout << "Sedentary: little or no exercise\t\t\t" << a1 << endl;

    int a2 = calories * 1.375;
    cout << "Exercise 1-3 times/week\t\t\t\t\t" << a2 << endl;

    int a3 = calories * 1.465;
    cout << "Exercise 4-5 times/week\t\t\t\t\t" << a3 << endl;

    int a4 = calories * 1.55;
    cout << "Daily exercise or intense exercise 3-4 times/week\t" << a4 << endl;

    int a5 = calories * 1.725;
    cout << "Intense exercise 6-7 times/week\t\t\t\t" << a5 << endl;

    int a6 = calories * 1.9;
    cout << "Very intense exercise daily, or physical job\t\t" << a6 << endl;
}

int main(){
    int age;
    char gen, repeat;
    double height, weight, bmr;
    
    do{
        cout << "Basal metabolic Rate (BMR) Calculator" << endl;
        cout << endl;
    do{

        cout << "Age [15-80]: ";
        cin >> age;

    }while((age < 15) || (age > 80));

    do{
        cout << "Gender [F @ M]: ";
        cin >> gen;

    }while((gen != 'F') && (gen != 'f') && (gen != 'M') && (gen != 'm'));

    cout << "Height (cm): ";
    cin >> height;
    cout << "Weight (kg): ";
    cin >> weight;
    cout << endl;

    bmr = calcBMR(age, height, weight, gen);

    cout << "BMR = " << bmr << " Calories/ day (using Mifflin-St Jeor Equation)" << endl;
    cout << endl;

    dispCalActivity(bmr);

    cout << endl;
    cout << "Exercise: 15-30 minutes of elevated heart rate activity." << endl;
    cout << "Intense exercise: 45-120 minutes of elevated heart rate activity." << endl;
    cout << "Very intense exercise: 2+ hours of elevated heart rate activity." << endl;
    cout << endl;

    cout << "Do you want to enter other data? [Y @ N]: ";
    cin >> repeat;
    cout << endl;
    
    }while((repeat == 'Y') || (repeat == 'y'));

    cout << "Thank You :)" << endl;
    

    return 0;

}

