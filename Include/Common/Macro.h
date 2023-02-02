/**
 * Created by root on 2023-02-02.
 */

#ifndef PWOL_MACRO_H
#define PWOL_MACRO_H

// Do check compile cpp version, default should to 17
#if __cplusplus > 201703L
	#define CPP_VERSION 20
#elif __cplusplus == 201703L
	#define CPP_VERSION 17
#elif __cplusplus == 201402L
	#define CPP_VERSION 14
#elif __cplusplus == 201103L
	#define CPP_VERSION 11
#else
	// version below c++11
	#define CPP_VERSION 0
#endif

#if CPP_VERSION > 17
	#define UString std::u8string
#else
	#define UString std::string
#endif

#endif //PWOL_MACRO_H
