#include "getopt.h"
/* vim:ts=4:sw=4:noet
 * (tabspace=4)
 * 
 * Copyright (C) 2004, 2005 Walter Doekes, <walter@djcvt.net>.
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.
 */

#ifdef _WIN32

#include <string.h>
#include <stdio.h>

int optind = 0;
static int optind2 = 1;

int getopt(int argc, char* const argv[], const char* optstring) {
	if(!optind) {
		int start = 1;
		while(1) {
			int first_non_opt = 0;
			int i;
			for(i = start; i < argc; ++i) {
				if(argv[i][0] == '-' && argv[i][1] == '-' &&
						argv[i][2] == '\0') {
					optind++;
					i = argc;
					break;
				} else if(argv[i][0] != '-' || (argv[i][0] == '-' &&
							argv[i][1] == '\0')) {
					if(!first_non_opt)
						first_non_opt = i;
				} else {
					size_t j;
					for(j = 1; j < strlen(argv[i]); ++j) {
						if(strchr(optstring, argv[i][j]) == NULL) {
							fprintf(stderr, "%s: invalid option -- %c\n",
									argv[0], argv[i][j]);
							return '?';
						}
					}
					if(first_non_opt) {
						int k;
						for(k = i; k > first_non_opt; --k) {
							char const* tmp = argv[k];
							*((char const**)argv + k) = argv[k - 1];
							*((char const**)argv + k - 1) = tmp;
						}
						start = first_non_opt + 1;
						break;
					}
				}
			}
			if(argc == i)
				break;
		}
		optind++;
	}

	while(1) {
		if(optind >= argc)
			return -1;
		if(argv[optind][0] != '-' || (argv[optind][0] == '-' &&
				argv[optind][1] == '\0'))
			return -1;
		if(argv[optind][0] == '-' && argv[optind][1] == '-' &&
				argv[optind][2] == '\0') {
			optind++;
			return -1;
		}
	    if(argv[optind][optind2] != '\0')
			return argv[optind][optind2++];
		optind++;
		optind2 = 1;
	}
	return -1;
}

#endif /* !_WIN32 */
