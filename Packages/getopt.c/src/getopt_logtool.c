/*
 *   logtool - a logfile parsing/monitoring/manipulation utility
 *
 *   Copyright (C) Y2K (2000) A.L.Lambert
 *
 *   This program is free software; you can redistribute it and/or modify
 *   it under the terms of the GNU General Public License as published by
 *   the Free Software Foundation; either version 2, or (at your option)
 *   any later version.
 *
 *   This program is distributed in the hope that it will be useful,
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *   GNU General Public License for more details.
 *
 *   You should have received a copy of the GNU General Public License
 *   along with this program; if not, write to the Free Software
 *   Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.
 */

#include "includes.h"

/*
 * Yee ole show usage function.  Put it here because I didn't feel like
 * having a separate object for this one dinky little function, and it's
 * related to getopt, because it'll be called from the lt_getopts()
 * function if ever 
 */
void lt_sh_usage()
{

    /*
     * NOTE: we don't tell the user they can specify green/yellow/whatever 
     * else on the command line anymore, as we've got way too many
     * different files, and I get sick of trying to maintain too many
     * command line switches for them. :) HOWEVER: I have not removed
     * the existing cmdline switches from the getopt() stuff below, in the 
     * name of backwards compatability 
     */

    PRINT_VERSION;
    printf("\n");
    printf("Command line options:\n");
    printf
	(" -c [/path/config.file]  = specify a config file other than %s\n",
	 CONFIG_FILE);
    printf
	(" -i [/path/include.file] = a file containing regex's for inclusion\n");
    printf
	(" -e [/path/exclude.file] = a file containing regex's for exclusion\n");
    printf
	(" -o [ ANSI | ASCII | CSV | HTML | RAW ]\n  Output Format: ANSI (default), ASCII, CSV, HTML, RAW\n");
    printf
	(" -t [ long | short ]\n\tTime display Format: (Long [default]) Mon Dy HH:MM:SS or (Short) HH:MM\n");
    printf(" -m = specify a program name for multilog files\n");
    printf(" -n = do not resolve IP addresses (if applicable)\n");
    printf(" -b = beep on RED events (ANSI output only)\n");
    printf(" -S = disable mod_sound (if enabled by conffile) (ANSI output only)\n");
    printf(" -s = do not display the syslog \"source\" field\n");
    printf(" -p = do not display the \"program\" field\n");
    printf(" -v = verbose (print event processing info to stderr)\n");
    printf(" -d = do debugging output on stderr (for us developers)\n");
    printf(" -V = print version and exit \n");
    printf(" -h = this help message\n");
}


/*
 * Set the options to something sane before we accept any user defined
 * options 
 */
void lt_optsanity()
{
    /*
     * Set the defaults for what/how to parse to something sane by default.
     * The defaults set here can/will be overiden by user defined preferences 
     * in either command line or config file.
     */
    cf.outfmt = OUTPUT_ANSI;	/* ANSI is the default output type */
    cf.input = FALSE;		/* no, we ain't seen no input yet, eh? */
    cf.timefmt = DATE_LONG;	/* what date format shall we use? */
    cf.verbose = FALSE;		/* We are not verbose by default */
    cf.debug = FALSE;		/* do we do debugging output? */
    cf.redbeep = FALSE;		/* We do not beep on red events by default */
    cf.sound = FALSE;		/* nor do we do sounds by default 
				 */
    cf.showprog = TRUE;		/* set this to true by default */
    cf.showsrc = TRUE;		/* do we show the program field? */
    cf.supdupes = TRUE;		/* do we show duplicate entries? */
    cf.sys_ng_host = FALSE;	/* suppress syslog-ng *@'s in host field? */
    cf.hostfmt = HOST_DEFAULT;	/* do we parse syslog-ng host filed (and
				 * how) */
    cf.resolv = TRUE;		/* let config file enable host resolution */
    /*
     * a sane default for our config file 
     */
    strncpy(cf.configfile, CONFIG_FILE, 1023);
    strncpy(cf.multilog_program, "local prog", 255);
}

void lt_getopts(int argc, char **argv)
{

    int option;

    lt_optsanity();

    /*
     * Read the default config file for our user defined defaults (if any) 
     */
    lt_read_config();
    /*
     * Check out the command line options liberal use of strn*() here, as 
     * users can send who knows what to these calls B-g below is depreciated
     */
    while ((option = getopt(argc, argv, "B:M:C:I:y:g:c:i:m:e:o:t:nbsSpvdVh")) != -1) {
	switch (option) {
	case 0:		/* I dunno why this is here; was there in
				   * the example so I left it... */
	    break;
	case 'n':
	    cf.resolv = FALSE;
	    break;
	case 'd':
	    cf.debug = TRUE;
	    break;

	case 'h':
	    lt_sh_usage();
	    exit(0);
	    break;

	case 'c':
	    strncpy(cf.configfile, optarg, 1023);
	    lt_read_config();
	    break;

	case 'm':
	    strncpy(cf.multilog_program, optarg, 255);
	    break;
		
	case 't':
	    if (strncasecmp(optarg, "long", 32) == 0) {
		cf.timefmt = DATE_LONG;
	    } else if (strncasecmp(optarg, "short", 32) == 0) {
		cf.timefmt = DATE_SHORT;
	    } else {
		lt_sh_usage();
		exit(0);
	    }
	    break;


	case 's':
	    cf.showsrc = FALSE;
	    break;

	case 'p':
	    cf.showprog = FALSE;
	    break;
	case 'o':
	    if (strncasecmp(optarg, "ansi", 32) == 0) {
		cf.outfmt = OUTPUT_ANSI;
	    } else if (strncasecmp(optarg, "ascii", 32) == 0) {
		cf.outfmt = OUTPUT_ASCII;
	    } else if (strncasecmp(optarg, "csv", 32) == 0) {
		cf.outfmt = OUTPUT_CSV;
	    } else if (strncasecmp(optarg, "html", 32) == 0) {
		cf.outfmt = OUTPUT_HTML;
	    } else if (strncasecmp(optarg, "raw", 32) == 0) {
		cf.outfmt = OUTPUT_RAW;
	    } else if (strncasecmp(optarg, "curses", 32) == 0) {
		cf.outfmt = OUTPUT_CURSES;
	    } else {
		lt_sh_usage();
		exit(1);
	    }
	    break;

	case 'b':
	    cf.redbeep = TRUE;
	    break;
	case 'S':
	    /* this switch is just to switch off sound quickly in case of a rash of alerts or
	     * other reasons you might want to stop beeping and bonging via wav file. */
	    cf.sound = FALSE;
	    break;
	    
	case 'i':		/* we skip the strn*()'s here as we're
				 * dynamicly allocating the space for user 
				 * input */
	    reg.include_file = malloc(strlen(optarg) + 1);
	    strcpy(reg.include_file, optarg);
	    reg.include_check = TRUE;
	    break;

	case 'e':
	    reg.exclude_file = malloc(strlen(optarg) + 1);
	    strcpy(reg.exclude_file, optarg);
	    reg.exclude_check = TRUE;
	    break;

	case 'v':
	    cf.verbose = TRUE;
	    break;
	case 'V':
	    PRINT_VERSION;	/* put version stuff to screen */
	    exit(0);		/* exit with errlevel 0 */
	    break;		/* why is this here? I dunno... */

	    /*
	     * all of the below is depreciated: please don't use them
	     * anymore !!! 
	     */
	case 'y':
	    if(cf.verbose == TRUE) fprintf(stderr, "colorfile setting on command line is depreciated, please use a config file\n");
	    reg.yellow_file = malloc(strlen(optarg) + 1);
	    strncpy(reg.yellow_file, optarg, 254);
	    reg.yellow_check = TRUE;
	    break;

	case 'g':
	    if(cf.verbose == TRUE) fprintf(stderr, "colorfile setting on command line is depreciated, please use a config file\n");
	    reg.green_file = malloc(strlen(optarg) + 1);
	    strncpy(reg.green_file, optarg, 254);
	    reg.green_check = TRUE;
	    break;

	case 'B':
	    if(cf.verbose == TRUE) fprintf(stderr, "colorfile setting on command line is depreciated, please use a config file\n");
	    reg.blue_file = malloc(strlen(optarg) + 1);
	    strncpy(reg.blue_file, optarg, 254);
	    reg.blue_check = TRUE;
	    break;

	case 'M':
	    if(cf.verbose == TRUE) fprintf(stderr, "colorfile setting on command line is depreciated, please use a config file\n");
	    reg.magenta_file = malloc(strlen(optarg) + 1);
	    strncpy(reg.magenta_file, optarg, 254);
	    reg.magenta_check = TRUE;
	    break;

	case 'C':
	    if(cf.verbose == TRUE) fprintf(stderr, "colorfile setting on command line is depreciated, please use a config file\n");
	    reg.cyan_file = malloc(strlen(optarg) + 1);
	    strncpy(reg.cyan_file, optarg, 254);
	    reg.cyan_check = TRUE;
	    break;

	case 'I':
	    if(cf.verbose == TRUE) fprintf(stderr, "colorfile setting on command line is depreciated, please use a config file\n");
	    reg.brightcyan_file = malloc(strlen(optarg) + 1);
	    strncpy(reg.brightcyan_file, optarg, 254);
	    reg.brightcyan_check = TRUE;
	    break;

	    /*
	     * end dpreciated block 
	     */
	default:
	    lt_sh_usage();
	    exit(1);		/* some sucker done put in invalid cmdline 
				 * options ... grrr... */

	}
    }
}
