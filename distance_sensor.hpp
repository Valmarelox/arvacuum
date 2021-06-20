
class DistanceSensor {
public:
    DistanceSensor(unsigned int ping_pin, unsigned int echo_pin) :
        _ping_pin(ping_pin), _echo_pin(echo_pin) {}

    unsigned long measure_distance();


private:
    unsigned int _ping_pin;
    unsigned int _echo_pin;
};
