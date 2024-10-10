#include <iostream>


// class is declared
class Time {

// member variables are created
    protected:
        int hour; //data representing the hour
        int minute; // data representing the minute
    
    public:
        Time (int h = 0, int m = 0); // constructor
    // Member function prototypes are declared
        void increment_minute(); // method to increment minute
        void decrement_minute(); // method to decrement minute
        void print_time(void) const; // method to print time
        void set_time (int h,int m);

};
//class inherited from time class called timezone is declared
class Timezone:public Time {
    private:
        int timezone; // additional member variable
    public:
        Timezone (int h = 0,int m = 0, int tz = 0); // constructor
        void change_timezone(int change_tz);
        void see_timezone(void) const;
        void print_time(void) const;






};