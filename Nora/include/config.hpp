#pragma once

#if defined(_WIN32) || defined(_WIN64)
	#define NORA_API_EXPORT __declspec(dllexport)
	#define NORA_API_IMPORT __declspec(dllimport)
#endif
