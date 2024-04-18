#include "typedefs.h"
#include "utils.h"
#include "init.h"
#include "reverse.h"

int main(int argc, char** argv) {
    if (argc >= 3 && CheckArgs(argv[1], argv[2]))
        RevArgs(argc, argv);
    else
        NoArgs();
    return 0;
}
