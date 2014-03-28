#include "Base.h"

int main(int argc, char** argv)
{
    Base base;
    base.Initialize();
    base.Update();
    base.Shutdown();

    return 0;
}