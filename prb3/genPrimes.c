
/*** includes ***/
#include <stdio.h>
#include <stdint.h> // Suplies types, e.g. uint64_t
#include <stdlib.h> // Suplies EXIT_FAILURE, EXIT_SUCCESS, exit()
#include <getopt.h> // For parsing command line options. getop() ect.
#include <libgen.h> // Supplies basename()
#include <errno.h>  // Defines the external errno variable and possible values

/* defines */
#define OPTSTR "vn:o:h"
#define USAGE_FMT  "%s [-v] [-n <number of primes to generate>] [-o <outputfile>] [-h]\n"
#define ERR_FOPEN_OUTPUT "fopen(output, w) failed"
#define ERR_NUM_PRIMES "Failed parsing argument \"n\". n must be an integer larger than 0.\n"
#define DEFAULT_PROGNAME "genPrimes"



/* external declarations */
extern int errno;
extern char *optarg;
extern int opterr, optind;

/* type declerations */
typedef struct
{
  int         verbose;
  int         numPrimes;
  FILE*       output;
} options_t;

/* function prototypes */
void usage(char *progname, int opt);


int main(int argc, char *argv[]) {
  int opt;
  opterr = 0;
  options_t options = {0, -1, stdout};


  // Handle command-line arguments
  while( (opt = getopt(argc, argv, OPTSTR)) != EOF) {
    switch(opt) {
      case 'n':
        if(!(options.numPrimes = atoi(optarg)) )
        {
          fprintf(stderr, ERR_NUM_PRIMES);
          exit(EXIT_FAILURE);
        }
        break;
      case 'o':
        if(!(options.output = fopen(optarg, "w")) ){
          perror(ERR_FOPEN_OUTPUT);
          exit(EXIT_FAILURE);
        }
        break;
      case 'v':
        options.verbose += 1;
        break;
      case 'h':
        /* Fallthrough */
      default:
        usage(basename(argv[0]), opt);
        /* NOTREACHED */
        break;
    }
  }

  if ( options.numPrimes < 1 )
  {
    fprintf(stderr, ERR_NUM_PRIMES);
    exit(EXIT_FAILURE);
  }

  uint64_t* pPrimes = malloc(sizeof(uint64_t)*options.numPrimes);
  if (pPrimes == NULL)
  {
    exit(EXIT_FAILURE);
  }

  pPrimes[0] = 2;
  uint16_t idxPrimes = 1;
  uint64_t ittCount = 1;

  for(uint64_t i = 3; idxPrimes < options.numPrimes; i += 2)
  {
    uint64_t n = i;
    ittCount++;
    for (uint16_t j = 0; j < idxPrimes; j++)
    {
      // TODO: Optimise this by breaking as soon as hit is found.
      while ( n%pPrimes[j] == 0)
      {
        n /= pPrimes[j];
      }
    }
    
    if ( n != 1)
    {
      pPrimes[idxPrimes++] = n;
    }

    // Inform user on progress statistics if verbosity is set
    if (options.verbose && (ittCount%1000 == 0) )
    {
      fprintf(stderr, "%ld values checked, %d primes out of %d found\n", (i+1)/2, idxPrimes, options.numPrimes);
    }
  }

  // Write result to file
  fprintf(options.output, "%ld", pPrimes[0]);
  for ( uint16_t i = 1; i < idxPrimes; i++ )
  {
    fprintf(options.output, ",%ld", pPrimes[i]);
  }
  free(pPrimes);
  fprintf(options.output, "\n");

}

/* usage: prints usage instructions to stderr */
void usage(char *progname, int opt) {
 fprintf(stderr, USAGE_FMT, progname?progname:DEFAULT_PROGNAME);
 exit(EXIT_FAILURE);
}
