// Windows only: the game's log goes to a pipe or file more often than to a console there, and the C runtime
// buffers those fully; unbuffered, the log survives the game being killed
#include <stdio.h>

namespace {

struct UnbufferedLog {
    UnbufferedLog()
    {
        setvbuf(stdout, NULL, _IONBF, 0);
        setvbuf(stderr, NULL, _IONBF, 0);
    }
} sUnbufferedLog;

} // namespace
