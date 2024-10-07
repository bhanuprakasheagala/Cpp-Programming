#include <iostream>
#include <vector>
#include <ctime>

class Sensor {
    protected:
        std::string name;
        double value;
        time_t timestamp;

    public:
        Sensor(const std::string& n) : name(n), value(0), timestamp(0) {}

        virtual void read() = 0;

        virtual void display() const {
            std::cout << "Sensor: " << name << ", Value: " << value << ", Time: " << ctime(&timestamp) << '\n';
        }

        double getValue() const {
            return value;
        }

        time_t getTimeStamp() const {
            return timestamp;
        }
};

class TemparatureSensor : public Sensor {
    public:
        TemparatureSensor(const std::string& n) : Sensor(n) {}

        void read() override {
            // Simulating a temparature reading
            value = 20.0 + (rand() % 151) / 10.0; // Random temp b/w 20.0 and 35.0
            timestamp = std::time(nullptr);
        }

        void display() const override {
            std::cout << "Temparature in DegreesCelcius: \n";
            Sensor::display();
        }
};

class HumiditySensor : public Sensor {
    public:
        HumiditySensor(const std::string& n) : Sensor(n) {}

        void read() override {
            // Simulating a humidity reading
            value = 30.0 + (rand() % 171) / 10.0; // Random humidity b/w 30.0% and 100.0%
            timestamp = std::time(nullptr);
        }

        void display() const override {
            std::cout << "Humidity in %: \n";
            Sensor::display();
        }
};

class SensorNetwork {
    private:
        std::vector<Sensor*> sensors;

    public:
        void addSensor(Sensor* sensor) {
            sensors.push_back(sensor);
        }

        void readAllSensors() {
            for(auto sensor : sensors) {
                sensor->read();
            }
        }

        void displayAllReadings() const {
            for(const auto sensor : sensors) {
                sensor->display();
            }
        }

        double getAverageReading() const {
            if(sensors.empty()) {
                return 0.0;
            }

            double sum = 0.0;
            for(const auto sensor : sensors) {
                sum += sensor->getValue();
            }
            return sum / sensors.size();
        }

        Sensor* getLastReading() const {
            if(sensors.empty()) {
                return nullptr;
            }

            return *std::max_element(sensors.begin(), sensors.end(), [](const Sensor* a, const Sensor* b){
                return a->getTimeStamp() < b->getTimeStamp();
            });
        }
};

int main()
{
    SensorNetwork network;
    network.addSensor(new TemparatureSensor("Living Room"));
    network.addSensor(new TemparatureSensor("Bedroom"));
    network.addSensor(new HumiditySensor("Bathroom"));

    network.readAllSensors();

    std::cout << "All sensor readings:\n";
    network.displayAllReadings();

    std::cout << "\nAverage reading: " << network.getAverageReading() << '\n';

    Sensor* latestReading = network.getLastReading();
    if(latestReading) {
        std::cout << "\nLatest Reading: \n";
        latestReading->display();
    }
    
    return 0;
}

/*
Here's a brief explanation of the code:

1. Base Class: `Sensor`
   - Abstract base class for all sensors
   - Contains common properties: name, value, timestamp
   - Has a pure virtual `read()` function, making it an abstract class

2. Derived Classes: `TemperatureSensor` and `HumiditySensor`
   - Inherit from `Sensor`
   - Implement specific `read()` methods to simulate sensor readings
   - Override `display()` to show sensor-specific information

3. `SensorNetwork` Class:
   - Manages a collection of sensors using `std::vector<Sensor*>`
   - Provides methods to:
     - Add sensors
     - Read data from all sensors
     - Display all readings
     - Calculate average reading
     - Find the sensor with the latest reading

4. Main Function:
   - Creates a `SensorNetwork` instance
   - Adds different types of sensors
   - Demonstrates the use of the `SensorNetwork` methods

Key C++ Concepts Demonstrated:
- Inheritance and polymorphism
- Pure virtual functions
- STL containers (vector)
- STL algorithms (max_element)
- Lambda functions
- Range-based for loops
*/