#include "time.hpp"

int main() {

std::cout << "Lets use the time class" << std::endl;

Time now(23,20);
now.print_time();
now.decrement_minute();
now.print_time();

Timezone timen(2,25,-15);
timen.print_time();
timen.change_timezone(2);
timen.print_time();

return 0;
};