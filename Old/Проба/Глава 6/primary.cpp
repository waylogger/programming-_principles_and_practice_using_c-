
double primary ()
{

Token t = get_token ();
switch (t.kind)
	{
	case '(':
	{
	double d = exptession ();
	t = get_token ();
	if (t.kind != ')')
	{
	error ("Требуется ')');
	}
	return d;
	case '8':
	return t.value;
	default:
	error ("требуется первичное выражение)";
}
};