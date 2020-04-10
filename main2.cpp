#include <tuple>

std::tuple<int, int> divide(int dividend, int divisor) {
    return  std::make_tuple(dividend / divisor, dividend % divisor);
}

#include <iostream>

int main() {
    using namespace std;

    int quotient, remainder;

    tie(quotient, remainder) = divide(14, 3);

    cout << quotient << ',' << remainder << endl;
}
