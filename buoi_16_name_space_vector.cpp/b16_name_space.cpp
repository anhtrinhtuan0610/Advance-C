#include <iostream>

namespace teamB{
    int A = 10;
}

namespace teamc{
    int A = 15;
}

using namespace teamB;

int main(int argc, char const *argv[])
{
    //teamB :: A = 20;
    printf("A: %d\n", teamB::A);
    printf("A: %d\n", teamc::A);

    //khi su dung using namespace teamB
    printf("A: %d", A);

    return 0;
}