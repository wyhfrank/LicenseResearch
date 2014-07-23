/***************************************************************************
 *   copyright           : (C) 2003 by Hendrik Sattler                     *
 *   mail                : post@hendrik-sattler.de                         *
 *                                                                         *
 *   This program is free software; you can redistribute it and/or modify  *
 *   it under the terms of the GNU General Public License as published by  *
 *   the Free Software Foundation; either version 2 of the License, or     *
 *   (at your option) any later version.                                   *
 *                                                                         *
 ***************************************************************************/

#include <config.h>
#include <options.h>
#include <helper.h>
#include <w32compat.h>

#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#if PARSELIB == 1
#ifdef HAVE_GETOPT_H
# include <getopt.h>
#else
# include <gnugetopt/getopt.h>
#endif

char** args_parse (int argc, char** argv,
		   struct args_def* list,
		   void (*arg_fill) (int short_opt,
				     const char* long_opt,
				     char* argument))
{
  int arg = -1;
  int option_index = 0;
  char** retval;
  int i = 0;
  struct option* myoptions;
  struct option listEnd = { 0, 0, 0, 0 };
  char* myoptions_short;
  int short_count = 0;
  char* posixly_correct;
  int k = 0;

  while(list[i].long_name != NULL ||
	list[i].short_name != 0)
    ++i;
  myoptions = mem_alloc((i+1)*sizeof(*myoptions),0);
  myoptions_short = mem_alloc((3*i*sizeof(*myoptions_short))+1,1);
  memcpy(&myoptions[i--],&listEnd,sizeof(listEnd));
  for (; i >= 0; --i) {
    myoptions[i].name = list[i].long_name;
    myoptions[i].val = list[i].short_name;
    myoptions[i].flag = 0;
    switch (list[i].ptype) {
    case ARGS_PARAM_NONE:  myoptions[i].has_arg = 0; break;
    case ARGS_PARAM_OPT: myoptions[i].has_arg = 2; break;
    case ARGS_PARAM_REQ: myoptions[i].has_arg = 1; break;
    }
    if (isalnum((int)list[i].short_name)) {
      myoptions_short[short_count++] = list[i].short_name;
      for (k = 0; k < myoptions[i].has_arg; ++k) {
	myoptions_short[short_count++] = ':';
      }
    }
  }

  if ((posixly_correct=getenv("POSIXLY_CORRECT")) != NULL) {
    posixly_correct = str_dup(getenv("POSIXLY_CORRECT"));
  }
  setenv("POSIXLY_CORRECT","1",1);

  optind = 0;
  while ((arg = getopt_long(argc, argv,
			    myoptions_short,
			    myoptions,
			    &option_index)) != -1) {
    if (arg==0) {
      arg_fill(arg,myoptions[option_index].name,optarg);
    } else {
      arg_fill(arg,NULL,optarg);
    }
  }
  if (posixly_correct == NULL) {
    unsetenv("POSIXLY_CORRECT");
  } else {
    setenv("POSIXLY_CORRECT",posixly_correct,1);
  }
  if (optind >= argc) {
    retval = mem_alloc(sizeof(char*),0);    
    i=0;
  } else {
    retval = mem_alloc((argc-optind+1)*sizeof(char*),0);
    for (i=0;optind+i < argc;++i) {
      retval[i] = argv[optind+i];
    }
  }
  retval[i]=NULL;

  mem_realloc(myoptions,0);
  mem_realloc(myoptions_short,0);

  return retval;
}

#endif
