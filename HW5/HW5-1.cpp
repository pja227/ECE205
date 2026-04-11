/**
 * Perry Addey
 */
#include <iostream>
#include <iomanip>
#include <string>
#include <cmath>

using namespace std;

class BicycleSpeedometer {
    private:
        double distance;
        int time;

    public:
        BicycleSpeedometer() {
            distance = 0;
            time = 0;
        }

        void setDistance(double d) { distance = d; };
        double getDistance() { return distance; };

        void setTime(int t) { time = t; };
        int getTime() { return time; };

        double computeAverageSpeed();
};

double BicycleSpeedometer::computeAverageSpeed() {
    return (distance / time) * 60;
}

int main() {
	BicycleSpeedometer speedometer;
    double distance = 0;
    int time = 0;

    cout << "Enter distance traveled (in miles): ";
    cin >> distance;
    cout << "Enter time taken (in minutes): ";
    cin >> time;

    speedometer.setDistance(distance);
    speedometer.setTime(time);

    cout << "Average speed: " << speedometer.computeAverageSpeed() << " mph" << endl;

    return 0;
}