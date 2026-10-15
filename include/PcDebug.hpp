#ifndef POKERANGER2_PCDEBUG_HPP
#define POKERANGER2_PCDEBUG_HPP

// PC port only: debugging switches read from the environment (src/pc/PcDebug.cpp)
#ifdef PC_PORT
int PcDebug_StartScene(int defaultScene);
#endif

#endif // POKERANGER2_PCDEBUG_HPP
