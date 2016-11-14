#ifndef _DLL_TUTORIAL_H_
#define DECLDIR __declspec(dllexport)

extern "C"
{
	DECLDIR int Compute(int a, int b);
	DECLDIR const char* GetName();
}

#endif