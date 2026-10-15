// The SDK's WVR library (libwvr) sits between the game code and libcrypto in main,
// so it is built here as an object instead of being linked from libwvr.a
#ifndef PC_PORT // the PC build links libntr's WVR
extern "C" {
#include "../subprojects/NitroSDK-4.1.30001/libraries/wvr/src/wvr.c"
}
#endif
