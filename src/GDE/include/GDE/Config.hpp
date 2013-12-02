#ifndef GDE_CONFIG_HPP
#define GDE_CONFIG_HPP

////////////////////////////////////////////////////////////
// Versión de GDE
////////////////////////////////////////////////////////////
#define GDE_VERSION_MAJOR 0
#define GDE_VERSION_MINOR 1


////////////////////////////////////////////////////////////
// Identificar Sistema Operativo
////////////////////////////////////////////////////////////
#if defined(_WIN32) || defined(__WIN32__)
	// Windows
	#define GDE_SYSTEM_WINDOWS
	#ifndef NOMINMAX
		#define NOMINMAX
	#endif
#elif defined(linux) || defined(__linux)
	// Linux
	#define GDE_SYSTEM_LINUX
#elif defined(__APPLE__) || defined(MACOSX) || defined(macintosh) || defined(Macintosh)
	// MacOS
	#define GDE_SYSTEM_MACOS

#elif defined(__FreeBSD__) || defined(__FreeBSD_kernel__)
	// FreeBSD
	#define GDE_SYSTEM_FREEBSD
#else
	// Otros sistenmas no son soportados
	#error Este sistema no soportado por la biblioteca GDE
#endif


////////////////////////////////////////////////////////////
// Macro de debug portable
////////////////////////////////////////////////////////////
#if !defined(NDEBUG)
	#define GDE_DEBUG
#endif


////////////////////////////////////////////////////////////
// Define helpers to create portable import / export macros for each module
////////////////////////////////////////////////////////////
#if !defined(GDE_STATIC)
	#if defined(GDE_SYSTEM_WINDOWS)
		// Windows compilers need specific (and different) keywords for export and import
		#if !defined(GDE_API_EXPORTS)
			#define GDE_API __declspec(dllexport)
		#else
			#define GDE_API __declspec(dllimport)
		#endif

		// For Visual C++ compilers, we also need to turn off this annoying C4251 warning
		#ifdef _MSC_VER
			#pragma warning(disable : 4251)
		#endif

	#else // Linux, FreeBSD, Mac OS X
		#if __GNUC__ >= 4
			// GCC 4 has special keywords for showing/hidding symbols,
			// the same keyword is used for both importing and exporting
			#if !defined(GDE_API_EXPORTS)
				#define GDE_API __attribute__ ((__visibility__ ("default")))
			#else
				#define GDE_API __attribute__ ((__visibility__ ("default")))
			#endif
		#else
			// GCC < 4 has no mechanism to explicitely hide symbols, everything's exported
			#define GDE_API
			#define GDE_API
		#endif
	#endif
#else
	// Static build doesn't need import/export macros
	#define GDE_API
	#define GDE_API
#endif

#endif // GDE_CONFIG_HPP