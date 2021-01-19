#pragma once

int strcmp(const char* s0, const char* s1)
{
	while (*s0 == *s1++)
		if (*s0++ == 0)
			return 0;

	return -1;
}

int wcscmp(const short* s0, const short* s1)
{
	while (*s0 == *s1++)
		if (*s0++ == 0)
			return 0;
	
	return -1;
}
