// squeeze : delete each char in s1 which is in s2
void squeeze(char s1[], char s2[])
{
	int i, j, k;
	for (i = k = 0; s1[i] != '\0'; i++) {
		for (j = 0; s2[j] != '\0' && s1[i] != s2[j] ; j++)
			;
			if (s2[j] == '\0')
				s1[k++] = s1[i];
	}
	s1[k] = '\0';
}

//expand shorthand notation in s1 into string s2
void expand(char s1[], char s2[])
{
	char c;
	int i = 0;
	int j = 0;
	while ((c = s1[i++]) != '\0') {
		if (s1[i] == '-' && c < s1[i + 1]) {
			i++;
			while (c < s1[i])
				s2[j++] = c++;
		}
		else
			s2[j++] = c;
	}
	s2[j] = '\0';
}

