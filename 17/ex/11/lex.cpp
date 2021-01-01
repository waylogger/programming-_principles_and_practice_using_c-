const char min = '0';
const char max = '9';

int num_of_char (const char c)
{
	switch(c)
	{	case min: return -1;
		case max: return 999999;
		case 'A': case 'a': return 0;
		case 'B': case 'b': return 1;
		case 'C': case 'c': return 2;
		case 'D': case 'd': return 3;
		case 'E': case 'e': return 4;
		case 'F': case 'f': return 5;
		case 'G': case 'g': return 6;
		case 'H': case 'h': return 7;
		case 'I': case 'i': return 8;
		case 'J': case 'j': return 9;
		case 'K': case 'k': return 10;
		case 'L': case 'l': return 11;
		case 'M': case 'm': return 12;
		case 'N': case 'n': return 13;
		case 'O': case 'o': return 14;
		case 'P': case 'p': return 15;
		case 'Q': case 'q': return 16;
		case 'R': case 'r': return 17;
		case 'S': case 's': return 18;
		case 'T': case 't': return 19;
		case 'U': case 'u': return 20;
		case 'V': case 'v': return 21;
		case 'W': case 'w': return 22;
		case 'X': case 'x': return 23;
		case 'Y': case 'y': return 24;
		case 'Z': case 'z': return 25;
	}
	return 0;
}



bool lexigraph_last (const string& s1, const string& s2)
{
	for (int i =0, j =0; i < s1.size() || j < s2.size(); ++i, ++j)
	{
		if (s1[i]!=s2[j])
		{
			int f {num_of_char(s1[i])};
			int s {num_of_char(s2[j])};
			if (f>s) 		return true;
			else if (f<s) 	return false;
			else if (f==s) 	return false;
		}
	}
	return false; 
}

int lexigraph_dif (const string& s1, const string& s2)
{
	int a = 0;
	if (s1[0]==s2[0])
	for (int i =0, j =0; i < s1.size() || j < s2.size(); ++i, ++j)
	{
	if (s1[i]!=s2[j])
	{
		int f = {num_of_char(s1[i])};
		int s = {num_of_char(s2[j])};
		if (f>s) return 1;
		else return -1;
	}
	}
	
	
	for (int i =0, j =0; i < s1.size() || j < s2.size(); ++i, ++j)
	{
		if (s1[i]!=s2[j])
		{
			int f = {num_of_char(s1[i])};
			int s = {num_of_char(s2[j])};
			return f-s;
		}
	}
	return -11111111;
}



















