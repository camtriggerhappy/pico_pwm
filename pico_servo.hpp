class Servo{
    const int frequency{200};
    uint gpio_pin{42069};

    public:
    Servo(int pin){
        gpio_pin = pin;
    }
        
int servo_disable();
int servo_enable();
int servo_set_position(const uint16_t degree);
void percentOutput(float percent_out);
};