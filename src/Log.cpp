#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <Log.h>

// global variables defined for log
double __log_stime__;
FILE *__log_file__;       
FILE *__error_file__;
int __log_level__;

#ifndef __PARALLEL__
struct timeval tval;
struct timezone tzval;
#endif  // __PARALLEL__

void log_init (const char *filename, const char *errorfile, int loglevel)
{
#ifndef __PARALLEL__
	gettimeofday(&tval, &tzval);
#endif
	__log_stime__ = STIME;
	__log_level__ = 0;
	if (!(loglevel < 0))
		__log_level__ = loglevel;

#ifdef __LOG_ENABLE__

	__log_file__ = fopen (filename, "a+");
	if (!__log_file__)
	{
		fprintf (stderr, "Unable to open __log_file__ for writing\n");
	}

	if (!errorfile)
	{
		errorfile = filename;
	}

	__error_file__ = fopen (errorfile, "a+");
	if (!__error_file__)
	{
		fprintf (stderr, "Unable to open __error_file__ for writing\n");
	}

#endif /* __LOG_ENABLE__ */
}


void log_close ()
{
#ifdef __LOG_ENABLE__
	GEN("############################################################\n");
	fclose (__log_file__);
	fclose (__error_file__);
#endif /* __LOG_ENABLE__ */
}
