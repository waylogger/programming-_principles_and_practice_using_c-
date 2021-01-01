double term()
{
double left = primary();
Token t = get_token ();
while (true) {
	switch (t.kind) {
	case '*':
	left *= primary;
	break;
	case '/':
	{
	double d = primary ();
	if (d == 0) {error ("„деление на ноль");}
	left /= d;
	t= get_token ();
	break;
	}
	default:
		return left;
	}
}
}